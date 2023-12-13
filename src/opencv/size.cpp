#include "size.hpp"

#if WIN32
#include <windows.h>
#else
// i have no idea if you can check for X11 or Wayland with the preprocessor so
// i'm assuming you can't and that non-windows = x11
#include <X11/Xlib.h>
#endif

Size::Size() {
#if WIN32
  width = (int)GetSystemMetrics(SM_CXSCREEN);
  height = (int)GetSystemMetrics(SM_CYSCREEN);
#else
  Display *d = XOpenDisplay(NULL);
  Screen *s = DefaultScreenOfDisplay(d);

  width = s->width;
  height = s->height;
#endif
}
