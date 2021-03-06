#ifndef _ed_h_
# define _ed_h_

# include "version.h"
# include "sysdep.h"
# include "xcolor.h"
# include "lisp.h"
# include "vfs.h"
# include "wm.h"
# include "mousemsg.h"

struct Window;
struct Buffer;
class ApplicationFrame;

class lwindow: public lisp_object
{
public:
  Window *wp;
};

# define windowp(X) typep ((X), Twindow)

inline void
check_window (lisp x)
{
  check_type (x, Twindow, Qwindow);
}

inline Window *&
xwindow_wp (lisp x)
{
  assert (windowp (x));
  return ((lwindow *)x)->wp;
}

class lappframe: public lisp_object
{
public:
  ApplicationFrame *fp;
};

#define appframep(X) typep((X), Tappframe)

inline void
check_appframe(lisp x)
{
  check_type (x, Tappframe, Qappframe);
}

inline ApplicationFrame *&
xappframe_fp (lisp x)
{
  assert (appframep (x));
  return ((lappframe *)x)->fp;
}

class lbuffer: public lisp_object
{
public:
  Buffer *bp;
};

# define bufferp(X) typep ((X), Tbuffer)

inline void
check_buffer (lisp x)
{
  check_type (x, Tbuffer, Qbuffer);
}

inline Buffer *&
xbuffer_bp (lisp x)
{
  assert (bufferp (x));
  return ((lbuffer *)x)->bp;
}

class lmarker: public lisp_object
{
public:
  Buffer *buffer;
  point_t point;
  ~lmarker ();
};

# define markerp(X) typep ((X), Tmarker)

inline void
check_marker (lisp x)
{
  check_type (x, Tmarker, Qmarker);
}

inline Buffer *&
xmarker_buffer (lisp x)
{
  assert (markerp (x));
  return ((lmarker *)x)->buffer;
}

inline point_t &
xmarker_point (lisp x)
{
  assert (markerp (x));
  return ((lmarker *)x)->point;
}

class lregexp: public lisp_object
{
public:
  Char *pattern;
  int length;
  enum
    {
      MATCH_VOID = 1,
      MATCH_BOL = 2,
      TRANSLATE = 4,
      HAS_BACKREF = 8
    };
  int flags;
  lisp source;

  ~lregexp () {xfree (pattern);}
};

# define regexpp(X) typep ((X), Tregexp)

inline Char *&
xregexp_pattern (lisp x)
{
  assert (regexpp (x));
  return ((lregexp *)x)->pattern;
}

inline int &
xregexp_length (lisp x)
{
  assert (regexpp (x));
  return ((lregexp *)x)->length;
}

inline int &
xregexp_flags (lisp x)
{
  assert (regexpp (x));
  return ((lregexp *)x)->flags;
}

inline lisp &
xregexp_source (lisp x)
{
  assert (regexpp (x));
  return ((lregexp *)x)->source;
}

inline void
check_regexp (lisp x)
{
  check_type (x, Tregexp, Qregexp);
}

#define MENU_ID_RANGE_MIN 0
#define MENU_ID_RANGE_MAX 1024
#define TOOL_ID_RANGE_MIN 1024
#define TOOL_ID_RANGE_MAX 2048

class lwin32_menu: public lisp_object
{
public:
  HMENU handle;
  int id;
  lisp init;
  lisp command;
  lisp tag;

  ~lwin32_menu ();
};

# define win32_menu_p(X) typep ((X), Twin32_menu)

inline void
check_win32_menu (lisp x)
{
  check_type (x, Twin32_menu, Qmenu);
}

inline HMENU &
xwin32_menu_handle (lisp x)
{
  assert (win32_menu_p (x));
  return ((lwin32_menu *)x)->handle;
}

inline int &
xwin32_menu_id (lisp x)
{
  assert (win32_menu_p (x));
  return ((lwin32_menu *)x)->id;
}

inline lisp &
xwin32_menu_init (lisp x)
{
  assert (win32_menu_p (x));
  return ((lwin32_menu *)x)->init;
}

inline lisp &
xwin32_menu_tag (lisp x)
{
  assert (win32_menu_p (x));
  return ((lwin32_menu *)x)->tag;
}

inline lisp &
xwin32_menu_command (lisp x)
{
  assert (win32_menu_p (x));
  return ((lwin32_menu *)x)->command;
}

void check_popup_menu (lisp lmenu);

class lwin32_dde_handle: public lisp_object
{
public:
  HCONV hconv;
  ~lwin32_dde_handle ();
};

# define win32_dde_handle_p(X) typep ((X), Twin32_dde_handle)

inline
lwin32_dde_handle::~lwin32_dde_handle ()
{
  if (hconv)
    DdeDisconnect (hconv);
}

inline void
check_win32_dde_handle (lisp x)
{
  check_type (x, Twin32_dde_handle, Qdde_handle);
}

inline HCONV &
xwin32_dde_handle_hconv (lisp x)
{
  assert (win32_dde_handle_p (x));
  return ((lwin32_dde_handle *)x)->hconv;
}

inline lwindow *
make_window ()
{
  lwindow *p = ldata <lwindow, Twindow>::lalloc ();
  p->wp = 0;
  return p;
}

inline lappframe *
make_appframe()
{
  lappframe *p = ldata <lappframe, Tappframe>::lalloc ();
  p->fp = 0;
  return p;
}

inline lbuffer *
make_buffer ()
{
  lbuffer *p = ldata <lbuffer, Tbuffer>::lalloc ();
  p->bp = 0;
  return p;
}

inline lmarker *
make_marker ()
{
  lmarker *p = ldata <lmarker, Tmarker>::lalloc ();
  p->buffer = 0;
  return p;
}

inline lregexp *
make_regexp ()
{
  lregexp *p = ldata <lregexp, Tregexp>::lalloc ();
  p->pattern = 0;
  p->source = Qnil;
  return p;
}

inline lwin32_dde_handle *
make_win32_dde_handle ()
{
  lwin32_dde_handle *p = ldata <lwin32_dde_handle, Twin32_dde_handle>::lalloc ();
  p->hconv = 0;
  return p;
}

struct Window;
struct Buffer;
class main_frame;

# include "process.h"
# include "dll.h"
# include "chunk.h"
# include "oledata.h"
# include "waitobj.h"
# include "ces.h"
# include "kbd.h"
# include "mouse.h"
# include "statarea.h"
# include "timer.h"
# include "font.h"
# include "utimer.h"

class StatusWindow
{
public:
  enum {TEXT_MAX = 1024};
  HWND sw_hwnd;
protected:
  struct swbuf
    {
      int l;
      int textf;
      ucs2_t buf[TEXT_MAX];
    } sw_last;
  ucs2_t sw_buf[TEXT_MAX];
  ucs2_t *sw_b;
  ucs2_t *sw_tail;
public:
  void restore ();
  int text (const char *);
  void puts (const Char *, int);
  int putc (Char);
  void newline ();
  void puts (const char *, int);
  void puts (int, int);
  void flush ();
  void clear (int = 0);
  StatusWindow ();
  void set (HWND);
  int paint (const DRAWITEMSTRUCT *);
};

class FKWin;


struct Frame
{
  Window *windows;
  Window *selected;
  Window *reserved;
  Window *deleted;
  int windows_moved;

  HWND hwnd;
  SIZE size;

  int has_focus;
  HWND has_caret;
  HWND has_caret_last;
  int caret_on;
  int gray_caret;
  SIZE caret_size;
  POINT caret_pos;
  COLORREF last_caret_color;

  FKWin *fnkey;
  Frame *f_next;
};


struct ModelineParam
{
  HFONT m_hfont;
  int m_height;
  int m_exlead;
  int m_exts[22];

  ModelineParam ();
  ~ModelineParam ();
  void init (HFONT);
};

struct Region
{
  point_t p1;
  point_t p2;
};

/*
This class is Frame in emacs meaning.
But Frame is already used in xyzzy and it does not contain status bar, menu, etc.
In xyzzy, similar concept was Application, so I create ApplicationFrame and separate from Application.
This name should be renamed.
*/
class ApplicationFrame
{
public:
  ApplicationFrame ();
  ~ApplicationFrame();

  HINSTANCE hinst;
  HWND toplev;
  HWND hwnd_sw;

  HWND hwnd_clipboard;

  kbd_queue kbdq;
  mouse_state mouse;
  ime_comp_queue ime_compq;

  Frame active_frame;

  FontSet text_font;
  ModelineParam modeline_param;
  StatusWindow status_window;
  key_sequence keyseq;
  itimer as_itimer;

  status_area stat_area;

  int default_tab_columns;
  int auto_save_count;

  int ime_composition;
  int ime_open_mode;

  int last_vkeycode;
  int kbd_repeat_count;
  int wait_cursor_depth;

  int sleep_timer_exhausted;
  int f_protect_quit;

  int f_in_drop;
  Window *drop_window;
  Window *drag_window;
  Buffer *drag_buffer;
  Region drag_region;

  DWORD last_cmd_tick;
  int f_auto_save_pending;

  UINT default_caret_blink_time;
  int last_blink_caret;

  lisp lquit_char;
  int quit_vkey;
  int quit_mod;

  ATOM atom_toplev;
  int minibuffer_prompt_column;

  utimer user_timer;
  main_frame* mframe;

  ApplicationFrame *a_next;
  lisp lfp;
};


class Application
{
public:
  Application ();
  ~Application ();

  static const char ToplevelClassName[];
  static const char FrameClassName[];
  static const char ClientClassName[];
  static const char ModelineClassName[];

  HINSTANCE hinst;

  itimer gc_itimer;

  char dump_image[PATH_MAX + 8];
  char *ini_file_path;
  int toplevel_is_active;
  u_int quit_thread_id;

  void *initial_stack;
  int in_gc;

};

extern ApplicationFrame& active_app_frame();
extern ApplicationFrame* first_app_frame();
extern ApplicationFrame* retrieve_app_frame(HWND hwnd);
extern void insert_app_frame(HWND hwnd, ApplicationFrame *app);
extern Application g_app;

class enable_quit
{
  static char q_enable;
  char q_save;
public:
  enable_quit () : q_save (q_enable)
    {
      if (!q_save)
        {
          q_enable = 1;
          PostThreadMessage (g_app.quit_thread_id, WM_PRIVATE_REGISTER_HOTKEY, 0, 0);
        }
    }
  ~enable_quit () {if (!q_save) disable ();}
  static void disable ()
    {
      if (q_enable)
        {
          PostThreadMessage (g_app.quit_thread_id, WM_PRIVATE_UNREGISTER_HOTKEY, 0, 0);
          q_enable = 0;
        }
    }
};

void change_focus_to_frame(ApplicationFrame *app);

class defer_change_focus
{
	static int s_count;
	static ApplicationFrame* s_focus_candidate;
public :
	static void request_change_focus(ApplicationFrame *app)
	{
		// should use semaphore, but inconsistency is not so serious in this case (just re-activate is enough).
		if(s_count == 0)
		{
			change_focus_to_frame(app);
		}
		else
		{
			// may be killed and refocus during evalling lisp.
			change_focus_to_frame(&active_app_frame());
			if(app == &active_app_frame())
				s_focus_candidate = 0;
			else
				s_focus_candidate = app;
		}
	}
	defer_change_focus() {
		s_count++;
	}
	~defer_change_focus() {
		s_count--;
		if(s_count == 0)
		{
			if(s_focus_candidate)
			{
				change_focus_to_frame(s_focus_candidate);
			}
			s_focus_candidate = 0;
		}
	}

};


# include "Buffer.h"
# include "Window.h"
# include "syntax.h"
# include "msgbox.h"
# include "resource.h"

inline Window *
selected_window (ApplicationFrame *owner = &active_app_frame())
{
//  ApplicationFrame *frame = owner != 0? owner : &active_app_frame();
  return owner->active_frame.selected;
}

inline Buffer *
selected_buffer (ApplicationFrame *app1 = &active_app_frame())
{
  assert (selected_window (app1));
  return selected_window (app1)->w_bufp;
}

inline HWND
get_active_window ()
{
  HWND hwnd = GetActiveWindow ();
  return hwnd ? hwnd : active_app_frame().toplev;
}

inline
lmarker::~lmarker ()
{
  if (buffer)
    delq (this, &buffer->lmarkers);
}

class save_excursion
{
  Buffer *se_bufp;
  save_excursion *se_prev;
public:
  point_t se_point;
private:
  void cleanup (int);
public:
  save_excursion ();
  ~save_excursion ();
  void cleanup ();
  save_excursion *prev () {return se_prev;}
  void invalid () {se_bufp = 0;}
};

inline
save_excursion::save_excursion ()
{
  Window *wp = selected_window ();
  se_bufp = wp->w_bufp;
  se_prev = se_bufp->b_excursion;
  se_bufp->b_excursion = this;
  se_point = wp->w_point.p_point;
}

inline
save_excursion::~save_excursion ()
{
  cleanup (0);
}

inline void
save_excursion::cleanup ()
{
  cleanup (1);
}

class save_restriction
{
  Buffer *sr_bufp;
  save_restriction *sr_prev;
  int sr_depth;
public:
  Region sr_contents;

  save_restriction ();
  ~save_restriction ();
  save_restriction *prev () {return sr_prev;}
  void invalid () {sr_bufp = 0;}
};

inline
save_restriction::save_restriction ()
{
  sr_bufp = selected_buffer ();
  sr_prev = sr_bufp->b_restriction;
  sr_bufp->b_restriction = this;
  sr_contents = sr_bufp->b_contents;
  sr_depth = sr_bufp->b_narrow_depth;
}

class save_cursor_depth
{
  int odepth;
public:
  save_cursor_depth () : odepth (active_app_frame().wait_cursor_depth) {}
  ~save_cursor_depth ()
    {
      if (!odepth)
        end_wait_cursor (1);
      else
        active_app_frame().wait_cursor_depth = odepth;
    }
};

class all_window_iterator
{
	ApplicationFrame *curApp;
	Window *curWin;
public:
	all_window_iterator()
	{
		curApp = 0;
		curWin = 0;
	}
	Window* begin()
	{
		curApp = first_app_frame();
		if(curApp != 0)
			curWin = curApp->active_frame.windows;
		return curWin;
	}
	Window* next()
	{
		if(curWin->w_next)
		{
			curWin = curWin->w_next;
			return curWin;
		}
		curApp = curApp->a_next;
		if(curApp == 0)
			return 0;
		curWin = curApp->active_frame.windows;
		return curWin;
	}

};


#endif
