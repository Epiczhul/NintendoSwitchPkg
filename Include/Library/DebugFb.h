/** @file
  DebugFb.h: Write a solid color to the Switch framebuffer for bring-up debugging.

  The display controller is initialized by coreboot and continuously scans out the
  framebuffer at 0xdfb80000 (720x1280, 32bpp, pitch 2880 bytes). Filling it with a
  distinct color at a given boot stage lets us see how far the firmware gets.
**/

#ifndef _DEBUG_FB_H_
#define _DEBUG_FB_H_

#include <Base.h>

#define DEBUG_FB_BASE   0xdfb80000
#define DEBUG_FB_WIDTH  720
#define DEBUG_FB_HEIGHT 1280

#define DEBUG_FB_RED      0xFFFF0000
#define DEBUG_FB_GREEN    0xFF00FF00
#define DEBUG_FB_BLUE     0xFF0000FF
#define DEBUG_FB_WHITE    0xFFFFFFFF
#define DEBUG_FB_YELLOW   0xFFFFFF00
#define DEBUG_FB_PINK     0xFFFF69B4
#define DEBUG_FB_PURPLE   0xFF800080
#define DEBUG_FB_LIME     0xFF80FF00
#define DEBUG_FB_CYAN     0xFF00FFFF
#define DEBUG_FB_MAGENTA  0xFFFF00FF
#define DEBUG_FB_ORANGE   0xFFFF8000
#define DEBUG_FB_GRAY     0xFF808080
#define DEBUG_FB_TEAL     0xFF008080
#define DEBUG_FB_NAVY     0xFF000080
#define DEBUG_FB_OLIVE    0xFF808000
#define DEBUG_FB_MAROON   0xFF800000
#define DEBUG_FB_BROWN    0xFFA52A2A
#define DEBUG_FB_SILVER   0xFFC0C0C0
#define DEBUG_FB_LIGHTBLUE   0xFFADD8E6
#define DEBUG_FB_DARKGRAY    0xFF555555
#define DEBUG_FB_INDIGO      0xFF4B0082
#define DEBUG_FB_GOLD        0xFFFFD700
#define DEBUG_FB_SKYBLUE     0xFF87CEEB
#define DEBUG_FB_LIGHTGREEN  0xFF90EE90
#define DEBUG_FB_VIOLET      0xFFEE82EE
#define DEBUG_FB_LIGHTSALMON 0xFFFFA07A
#define DEBUG_FB_DEEPPINK    0xFFFF1493
#define DEBUG_FB_DODGERBLUE  0xFF1E90FF

STATIC
VOID
DebugFbFill (
  IN UINT32  Color
  )
{
  volatile UINT32 *Fb = (volatile UINT32 *)DEBUG_FB_BASE;
  UINTN           Index;

  for (Index = 0; Index < (UINTN)DEBUG_FB_WIDTH * DEBUG_FB_HEIGHT; Index++) {
    Fb[Index] = Color;
  }
}

#endif
