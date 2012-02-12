#ifndef _buffer_bar_h_
#define _buffer_bar_h_

#include "dockbar.h"
#include "DnD.h"
#include <map>

typedef std::map<Buffer*, bool> buf_bool_map;

class buffer_bar: public tab_bar
{
private:
  Buffer *b_last_buffer;
  buffer_bar_drop_target b_drop_target;
  int b_last_checked_version; // modified flag version.
  buf_bool_map b_buf_map;
  bool b_item_deleted;
  int b_drop_index;
  enum {DROP_TIMER_ID = 10};

  buffer_bar (ApplicationFrame*, dock_frame &);
  virtual ~buffer_bar () {}
  virtual int notify (NMHDR *, LRESULT &);
  int create (HWND);
  Buffer *nth (int i) const {return (Buffer *)tab_bar::nth (i);}
  Buffer *current () const;
  int insert (const Buffer *, int);
  int modify (const Buffer *, int);
  static char *set_buffer_name (const Buffer *, char *, int);
  virtual int need_text (TOOLTIPTEXT &);
  virtual void draw_item (const draw_item_struct &);
  void insert_buffers ();
  void delete_buffer (Buffer *);
  virtual void post_nc_destroy () {}
  Buffer *next_buffer (Buffer *, int) const;
  Buffer *top_buffer () const;
  Buffer *bottom_buffer () const;
  void tab_color (const Buffer *, COLORREF &, COLORREF &);
  lisp buffer_list () const;
protected:
  virtual lisp context_menu (int);
  virtual LRESULT wndproc (UINT, WPARAM, LPARAM);
public:
  static buffer_bar* make_instance (ApplicationFrame* app);
  static void buffer_deleted (Buffer *bp);
  virtual void update_ui ();
  static Buffer *next_buffer (Buffer *bp);
  static Buffer *prev_buffer (Buffer *bp);
  static Buffer *get_top_buffer ();
  static Buffer *get_bottom_buffer ();
  void drag_enter (int, int);
  void drag_over (int, int);
  void drag_leave ();
  static lisp list_buffers ();
};

#endif /* _buffer_bar_h_ */
