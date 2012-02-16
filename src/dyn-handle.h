#ifndef _DYN_HANDLE_H_
# define _DYN_HANDLE_H_

class dyn_handle
{
private:
  void operator = (const dyn_handle &);
  dyn_handle (const dyn_handle &, int = 0);
protected:
  HANDLE h;
public:
  dyn_handle ();
  dyn_handle (HANDLE);
  ~dyn_handle ();
  int valid () const;
  operator HANDLE () const;
  // sometime, cast cause un-intented copy constructor call.
  inline HANDLE get_handle() const { return h; }
  inline void explicit_copy(dyn_handle &to) {
	  int inherit = 0;
	  HANDLE hproc = GetCurrentProcess ();
	 if (!DuplicateHandle (hproc, h, hproc, &to.h, 0, inherit,
		                    DUPLICATE_SAME_ACCESS))
		to.h = INVALID_HANDLE_VALUE;
  }
  void fix (HANDLE);
  HANDLE unfix ();
  void close ();

  friend int pipe (dyn_handle &, dyn_handle &, SECURITY_ATTRIBUTES *, DWORD = 0);
};

inline
dyn_handle::dyn_handle ()
     : h (INVALID_HANDLE_VALUE)
{
}

inline
dyn_handle::dyn_handle (HANDLE h_)
     : h (h_)
{
}


inline int
dyn_handle::valid () const
{
  return h != INVALID_HANDLE_VALUE;
}

inline
dyn_handle::~dyn_handle ()
{
  if (valid ())
    CloseHandle (h);
}

inline
dyn_handle::operator HANDLE () const
{
  assert (valid ());
  return h;
}

inline void
dyn_handle::fix (HANDLE h_)
{
  assert (!valid ());
  h = h_;
}

inline HANDLE
dyn_handle::unfix ()
{
  HANDLE h_ = h;
  h = INVALID_HANDLE_VALUE;
  return h_;
}

inline void
dyn_handle::close ()
{
  if (valid ())
    {
      CloseHandle (h);
      h = INVALID_HANDLE_VALUE;
    }
}

inline int
pipe (dyn_handle &r, dyn_handle &w, SECURITY_ATTRIBUTES *sa, DWORD size)
{
  assert (!r.valid ());
  assert (!w.valid ());
  return CreatePipe (&r.h, &w.h, sa, size);
}

#endif
