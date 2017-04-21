
#include "menu.h"
#include <stdio.h>

  
u8g2_t u8g2;

uint8_t a, b;

me_t melist_nums[] = 
{
  { me_cb_0_9, &a, 2,20 },
  { me_cb_0_9, &b, 16,20 },
  { me_cb_null, NULL, 0, 0 },
};

me_t melist_menu[] = 
{
  { me_cb_text_line, "Zurück", 3,10 },
  { me_cb_text_line, "Alarm", 3,20 },
  { me_cb_text_line, "Einstellungen", 3,30 },
  { me_cb_null, NULL, 0, 0 },
};



menu_t menu;


int main(void)
{
  int x, y;
  int k;
  int i;
  
  u8g2_SetupBuffer_SDL_128x64_4(&u8g2, &u8g2_cb_r0);
  u8x8_InitDisplay(u8g2_GetU8x8(&u8g2));
  u8x8_SetPowerSave(u8g2_GetU8x8(&u8g2), 0);  
  
  //u8g2_SetFont(&u8g2, u8g2_font_helvB18_tf);
  u8g2_SetFont(&u8g2, u8g2_font_ncenR08_tf);
  
  menu_Init(&menu, &u8g2);
  menu_SetMEList(&menu, melist_menu, 0);
  
  x = 50;
  y = 30;

  
  for(;;)
  {
    u8g2_FirstPage(&u8g2);
    i = 0;
    do
    {
      u8g2_SetFontDirection(&u8g2, 0);
      u8g2_DrawStr(&u8g2, x, y, "123");
      menu_Draw(&menu);
      i++;
      
    } while( u8g2_NextPage(&u8g2) );
   
    do
    {
      k = u8g_sdl_get_key();
    } while( k < 0 );
    
    if ( k == 'n' )
      menu_NextFocus(&menu);

    if ( k == 's' )
      menu_Select(&menu);
    
    if ( k == 273 ) y -= 7;
    if ( k == 274 ) y += 7;
    if ( k == 276 ) x -= 7;
    if ( k == 275 ) x += 7;
    
    if ( k == 'q' ) break;
    
  }
  
  //u8x8_Set8x8Font(u8g2_GetU8x8(&u8g2), bdf_font);
  //u8x8_Draw8x8String(u8g2_GetU8x8(&u8g2), 0, 0, "Hello World!");
  
  
  
  
  
  
  return 0;
}

