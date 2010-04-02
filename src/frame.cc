#include "ed.h"


/*
Currently, I use Application as frame because they contain something we need like statusbar.
But this name is quite confusing. We should change these area in the future.
*/

Application *root = NULL;

static void inline ensure_root()
{
	if(root == NULL)
	{
		root = new Application();
	}
}

Application& active_app()
{
	ensure_root();
	return *root;
}
Application *default_app() { ensure_root(); return root; }


Application* retrieve_app(HWND hwnd)
{
  return (Application *)GetWindowLong (hwnd, 0);
}

void insert_app(HWND hwnd, Application *app1)
{
  SetWindowLong (hwnd, 0, LONG (app1));
}

bool is_last_app()
{
	if(root == NULL || root->a_next == NULL)
		return true;
	return false;
}

void notify_focus(Application *app1)
{
	if (root == app1) // do nothing.
		return;

	Application *cur = root;
	Application *prev = cur;
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
}

static void unchain_app(Application* app1)
{
	if(root == app1){
		root = app1->a_next;
		app1->a_next = 0;
		return;
	}
	Application *app = root;
	while(app->a_next != app1)
	{
		app = app->a_next;
	}
	app->a_next = app1->a_next;
	app1->a_next = 0;
}

void delete_app(Application *app1)
{
	unchain_app(app1);
	delete app1;
	kbd_queue::change_application_window = true;
// 	notify_focus(root);
}

extern int init_app(HINSTANCE hinst, Application* app1);


lisp
Fmake_frame (lisp opt)
{
	HINSTANCE hinst = root->hinst;

	Application* new_app = new Application();
	new_app->a_next = root;
	root = new_app;

	init_app(hinst, new_app);
	return Qnil;
}
