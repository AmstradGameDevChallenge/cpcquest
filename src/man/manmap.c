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
#include "maps/map1.h"
#include "maps/map2.h"

#define MAX_MAPS 2
u8* const maps[MAX_MAPS] = {
   {map1_end},
   {map2_end}
}; 

u8 map[20*12];

u8 currentmap;

////////////////////////////////////////////////////////////////////////////////
void ManMapCreate()
{   
   cpct_zx7b_decrunch_s(map + map1_size - 1, maps[currentmap]);
}

////////////////////////////////////////////////////////////////////////////////
void ManMapInit()
{
   currentmap = 0;
}

////////////////////////////////////////////////////////////////////////////////
const u8* ManMapGet()
{
   return map;
}

////////////////////////////////////////////////////////////////////////////////
u8 ManMapGetNumMaps()
{
   return MAX_MAPS;
}
