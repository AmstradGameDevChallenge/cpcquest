//-----------------------------LICENSE NOTICE-----------------------------------
//  This file is part of CPC Quest
//  Copyright (C) 2020 Antonio Corpas Cuenca
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

#include <cpctelera.h>
#include <stdio.h>
#include <string.h>
#include "draw/draw.h"
#include "video/video.h"
#include "man/manmap.h"
#include "man/mansprite.h"
#include "man/mancharacters.h"
#include "img/tiles.h"
#include "img/font.h"
#include "maps/map1.h"

cpctm_createTransparentMaskTable(tablatrans, 0x100, M0, 0);

const u8 blackpalette[16] = { 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54 };

////////////////////////////////////////////////////////////////////////////////
void SysRenderInit()
{      
   cpct_setVideoMode(0);
   cpct_setPalette(blackpalette, 16);
   cpct_setBorder(HW_YELLOW);
   VideoInitializeMemoryBuffers();    
}

////////////////////////////////////////////////////////////////////////////////
void SysRenderMap()
{      
   const u8* map = ManMapGet();   
   u8 a, b, k;
   
   for (b = 0; b < 12; b++)
   {      
      u8* backscreenptr = VideoGetBackBufferPtr(0, b * TILES_00_H * 2);
      k = b * 20;
      
      for (a = 0; a < 20; a++)
      {
         DrawTileDoubleHeight(tileset[map[a + k]], backscreenptr, TILES_00_W, TILES_00_H);
         backscreenptr = backscreenptr + TILES_00_W;
      }
   }
}

////////////////////////////////////////////////////////////////////////////////
void SysRenderText(u8 *string, u8 x, u8 y)
{
   u8 i;
   u8* backscreenptr;
   u8* data;
   u8 len = 40;
   u8 text[40 + 1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789   ";   

   if (strlen(string) > 0)
   {
      strcpy(text, string);
      len = strlen(text);
   }
   
   backscreenptr = VideoGetBackBufferPtr(x, y);

   for(i = 0; i < len; i++)
   {          
      data = ManCharactersGet(text[i]);      
               
      DrawTileDoubleHeight(data, backscreenptr, FONT_00_W, FONT_00_H);
      backscreenptr = backscreenptr + 2;
   }
}

////////////////////////////////////////////////////////////////////////////////
void SysRenderMenu()
{
   SysRenderText("HERO PHASE", 52, 16);
   SysRenderText("MOVE", 56, 32);
   SysRenderText("ATTACK", 56, 48);

   SysRenderText("EXPLORATION", 52, 64);
   SysRenderText("NEW ROOM", 56, 80);
   SysRenderText("NEW MONSTER", 56, 96);
   
   SysRenderText("ENEMY PHASE", 52, 112);
   SysRenderText("ENCOUNTER", 56, 128);
   SysRenderText("MONSTERS", 56, 144);   
   SysRenderText("TRAPS", 56, 160);   
}

////////////////////////////////////////////////////////////////////////////////
void SysRenderScreen()
{
   cpct_setPalette(blackpalette, 16);
      
   SysRenderMap();
   SysRenderMenu();   
   VideoFlipBuffers(); 

   SysRenderMap();
   SysRenderMenu();   
   VideoFlipBuffers(); 
   
   cpct_setPalette(palette, 16);   
}

////////////////////////////////////////////////////////////////////////////////
void SysRenderBackground(TSprite* sprite)
{
   u8 i, j;
   u8 k;
   u8 a, b;
   u8* backscreenptr;
   const u8* map = ManMapGet();

   i = sprite->px / TILES_00_W;
   sprite->px = i * TILES_00_W;
   j = sprite->py / (TILES_00_H * 2);

   for (b = 0; b < 2; b++)
   {
      k = i + (j * 20);
      sprite->py = j * TILES_00_H * 2;
      backscreenptr = VideoGetBackBufferPtr(sprite->px, sprite->py);

      for (a = 0; a < 2; a++)
      {
         DrawTileDoubleHeight(tileset[map[k + a]], backscreenptr, TILES_00_W, TILES_00_H);
         backscreenptr = backscreenptr + TILES_00_W;
      }

      j++;
   }
   sprite->px = sprite->x;
   sprite->py = sprite->y;  
}

////////////////////////////////////////////////////////////////////////////////
void SysRenderUpdate()
{
   char cadena[10] = "";
   u8 i;
   u8* backscreenptr;      
   TSprite *sprite;
   u8 num = ManSpriteGetNumSprites();
   
   // draw sprites
   
   for (i = 0; i < num; i++)
   {
      sprite = ManSpriteGet(i);
            
      backscreenptr = VideoGetBackBufferPtr(sprite->x, sprite->y);         
      DrawSpriteDoubleHeight(sprite->frame->img, backscreenptr, sprite->w, sprite->h, tablatrans);
   }
   
   sprite = ManSpriteGet(ID_PLAYER);
   
   sprintf(cadena, "%03hd", sprite->x);
   SysRenderText(cadena, 0, 0);     
   sprintf(cadena, "%03hd", sprite->y);
   SysRenderText(cadena, 0, 10);                
   sprintf(cadena, "%03hd", sprite->attack);
   SysRenderText(cadena, 0, 30);                
   
   VideoFlipBuffers();
   
   // delete sprites
         
   for(i = 0; i < num; i++)
   {
      sprite = ManSpriteGet(i);
      SysRenderBackground(sprite);      
   }  
}
