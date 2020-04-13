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

#ifndef _MANTURN_H_
#define _MANTURN_H_

#include "cmp/tturn.h"

typedef enum {
      ST_move = 0
   ,  ST_attack
   ,  ST_iddle
} EStatus;

void ManTurnInit();
void ManTurnCreate();
TTurn* ManTurnGet();
void ManTurnSetNext();

#endif
