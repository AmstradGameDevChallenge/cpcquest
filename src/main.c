// 30 horas 

//-----------------------------LICENSE NOTICE------------------------------------
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
#include "video/video.h"
#include "man/mansprite.h"
#include "man/manmap.h"
#include "sys/sysinput.h"
#include "sys/sysrender.h"
#include "sys/syscollision.h"
#include "sys/sysphysics.h"

__at(0x200) const unsigned char music[1147];

////////////////////////////////////////////////////////////////////////////////
void PlayMusic()
{
   __asm
      exx
      .db #0x08
      push af
      push bc
      push de
      push hl
      call _cpct_akp_musicPlay
      pop hl
      pop de
      pop bc
      pop af
      .db #0x08
      exx
   __endasm;
}

////////////////////////////////////////////////////////////////////////////////
void Interrupcion()
{
   static u8 i;
   
   i++;

   if (i == 6)
   {
      PlayMusic();
      cpct_scanKeyboard_if();
      i = 0;
   }      
}

////////////////////////////////////////////////////////////////////////////////
void Retardo(u8 val)
{
   u8 a, b;
   u8 resul = 0;

   for(a = 0; a < val; a++)
   {
      for(b = 0; b < val; b++)
      {      
         resul++;
      }
   }
}

////////////////////////////////////////////////////////////////////////////////
void main(void) 
{
   cpct_setStackLocation((u8*)NEW_STACK_LOCATION);
   cpct_disableFirmware();      
   SysRenderInit();
   //SysInputInit();
   //SysPhysicsInit();
   //SysCollisionInit();
   ManSpriteInit();
   ManMapInit();

   cpct_akp_musicInit(music);
   cpct_setInterruptHandler(Interrupcion);  

   ManSpriteCreate(PLAYER_SPRITE);
   ManSpriteCreate(ENEMY01_SPRITE);
   ManMapCreate();   
         
   SysRenderMap();      
   
   while(1)
   {    
      SysInputUpdate();             
      SysPhysicsUpdate();      
      SysCollisionUpdate();     
      SysRenderUpdate();
      
      //Retardo(200);
   }
}
