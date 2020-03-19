#include <X11/Xlib.h>
#include <unistd.h>

int main()
{
   Display *disp = NULL;
   Window ventana;
   XColor color;
   
   disp = XOpenDisplay(NULL);
   ventana = XCreateSimpleWindow (disp, XDefaultRootWindow (disp), 100, 100, 500, 500, 1, 1,BlackPixel (disp, DefaultScreen(disp)));
   XMapWindow (disp, ventana);
   XFlush (disp);
   color.flags = DoRed | DoGreen | DoBlue;
   color.red = 65535;
   color.blue = 0;
   color.green = 0;
   XAllocColor (disp, DefaultColormap (disp, DefaultScreen(disp)), &color);
   XSetForeground (disp, XDefaultGC (disp, DefaultScreen(disp)), color.pixel);
   XDrawLine (disp,ventana,XDefaultGC (disp, DefaultScreen(disp)),10, 10,100, 100);
   XFlush (disp);
   sleep (100);
}

