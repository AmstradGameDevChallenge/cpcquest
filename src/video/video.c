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
#include "video.h" 

u8 gvmem;                                          

////////////////////////////////////////////////////////////////////////////////
void VideoInitializeMemoryBuffers() 
{
   cpct_memset((u8*)SCREEN_BUFF, 0, 0x4000);   
   gvmem = VIDEO_MEM;   
}

////////////////////////////////////////////////////////////////////////////////
u8* VideoGetBackBufferPtr(u8 xpos, u8 ypos) 
{
   u8* backbufferstart;

   if (gvmem == VIDEO_MEM) backbufferstart = (u8*)SCREEN_BUFF;
   else backbufferstart = (u8*)CPCT_VMEM_START;

   return cpct_getScreenPtr(backbufferstart, xpos, ypos);
}

////////////////////////////////////////////////////////////////////////////////
void VideoFlipBuffers() 
{
   cpct_waitVSYNC(); 

   if (gvmem == BUFFER_MEM) 
   {            
      cpct_setVideoMemoryPage(cpct_pageC0);
      gvmem = VIDEO_MEM;
   } 
   else 
   {
      cpct_setVideoMemoryPage(cpct_page80);
      gvmem = BUFFER_MEM;
   }
}
