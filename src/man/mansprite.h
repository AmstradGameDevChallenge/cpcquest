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

#ifndef _MANSPRITE_H_
#define _MANSPRITE_H_

#include "cmp/tsprite.h"

#define ID_PLAYER 0
#define ID_ENEMY01 1
#define ID_ENEMY02 2
#define ID_ENEMY03 3
#define ID_ENEMY04 4
#define ID_ENEMY05 5
#define ID_ENEMY06 6

void ManSpriteInit();
void ManSpriteCreate(u8 num);
TSprite* ManSpriteGet(u8 num);
void ManSpriteSetNextFrame(u8 num);
u8 ManSpriteGetNumSprites();

#endif
