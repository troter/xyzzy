#include "ed.h"


ApplicationFrame::ApplicationFrame ()
     : mouse (kbdq)
{
  default_tab_columns = 8;
  auto_save_count = 0;
  toplevel_is_active = 0;
  ime_composition = 0;
  ime_open_mode = kbd_queue::IME_MODE_OFF;
  sleep_timer_exhausted = 0;
  last_vkeycode = -1;
  kbd_repeat_count = 0;
  wait_cursor_depth = 0;
  f_in_drop = 0;
  drop_window = 0;
  drag_window = 0;
  drag_buffer = 0;
  f_protect_quit = 0;
  hwnd_clipboard = 0;
  last_cmd_tick = GetTickCount ();
  f_auto_save_pending = 0;
  default_caret_blink_time = 0;
  last_blink_caret = 0;
  lquit_char = make_char ('G' - '@');
  quit_vkey = 'G';
  quit_mod = MOD_CONTROL;
  minibuffer_prompt_column = -1;

  memset((void*)&active_frame, 0, sizeof(active_frame));
  a_next = 0;
}


// ApplicationFrame g_appf;
ApplicationFrame *root = NULL;

static void inline ensure_root()
{
	if(root == NULL)
	{
		root = new ApplicationFrame();
	}
}

ApplicationFrame& active_app_frame()
{
	ensure_root();
	return *root;
}

ApplicationFrame *default_app_frame() { ensure_root(); return root; }


ApplicationFrame* retrieve_app_frame(HWND hwnd)
{
  return (ApplicationFrame *)GetWindowLong (hwnd, 0);
}

#include <vector>
static std::vector<ApplicationFrame*> g_floating_frames;

void app_frame_gc_mark(void (*f)(lisp))
{
  for(ApplicationFrame *app1 = root; app1; app1 = app1->a_next)
  {
	  (*f)(app1->lfp);
      app1->user_timer.gc_mark (f);
  }
}


void insert_app_frame(HWND hwnd, ApplicationFrame *app1)
{
  SetWindowLong (hwnd, 0, LONG (app1));
}

bool is_last_app_frame()
{
	if(root == NULL || root->a_next == NULL)
		return true;
	return false;
}

void notify_focus(ApplicationFrame *app1)
{
	if (root == app1) // do nothing.
		return;

	ApplicationFrame *cur = root;
	ApplicationFrame *prev = cur;
	while(cur != app1)
	{
		prev = cur;
		cur = cur->a_next;
	}
	assert(prev->a_next == app1);

	prev->a_next = app1->a_next;
	app1->a_next = root;
	root = app1;
	kbd_queue::change_application_window = true;
	for(Window* wp = root->active_frame.windows; wp; wp = wp->w_next)
		wp->update_window();
}

static void unchain_app_frame(ApplicationFrame* app1)
{
	if(root == app1){
		root = app1->a_next;
		app1->a_next = 0;
		return;
	}
	ApplicationFrame *app = root;
	while(app->a_next != app1)
	{
		app = app->a_next;
	}
	app->a_next = app1->a_next;
	app1->a_next = 0;
}


void delete_app_frame(ApplicationFrame *app1)
{
	unchain_app_frame(app1);
	// delete app1;
	g_floating_frames.push_back(app1);
	kbd_queue::change_application_window = true;
// 	notify_focus(root);
}


void delete_floating_app_frame()
{
	for(std::vector<ApplicationFrame*>::iterator it = g_floating_frames.begin(); it != g_floating_frames.end(); it++)
	{
		ApplicationFrame *app1 = *it;
		delete app1;
	}
	g_floating_frames.clear();
}

extern int init_app(HINSTANCE hinst, ApplicationFrame* app1);


lisp
Fmake_frame (lisp opt)
{
	HINSTANCE hinst = root->hinst;

	ApplicationFrame* new_app = new ApplicationFrame();
	new_app->a_next = root;
	root = new_app;

	init_app(hinst, new_app);
	return new_app->lfp;
}
