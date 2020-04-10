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

#ifndef _VIDEO_H_
#define _VIDEO_H_

#define SCREEN_BUFF           0x8000
#define MASK_TABLE_SIZE       0x100
#define NEW_STACK_LOCATION    (SCREEN_BUFF - MASK_TABLE_SIZE)

#define SCREEN_H              200

#define VIDEO_MEM             0
#define BUFFER_MEM            1

void VideoInitializeMemoryBuffers();
u8*  VideoGetBackBufferPtr(u8 xpos, u8 ypos);
void VideoFlipBuffers();

#endif
