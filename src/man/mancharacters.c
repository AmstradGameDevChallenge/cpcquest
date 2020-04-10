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
#include "img/font.h"

#define MAX_CHARACTERS 37
u8* const characters[MAX_CHARACTERS] = {
   {font_00},
   {font_01},
   {font_02},
   {font_03},
   {font_04},
   {font_05},
   {font_06},
   {font_07},
   {font_08},
   {font_09},
   {font_10},
   {font_11},
   {font_12},
   {font_13},
   {font_14},
   {font_15},
   {font_16},
   {font_17},
   {font_18},
   {font_19},
   {font_20},
   {font_21},
   {font_22},
   {font_23},
   {font_24},
   {font_25},
   {font_26},
   {font_27},
   {font_28},
   {font_29},
   {font_30},
   {font_31},
   {font_32},
   {font_33},
   {font_34},
   {font_35},
   {font_36}
};

////////////////////////////////////////////////////////////////////////////////
u8* const ManCharactersGet(u8 character)
{   
   if (character > 64)
   {
      character -= 54;
   }
   else if (character > 47)
   {
      character -= 48;
   }
   else
   {
      character = 10;
   }     
   
   return characters[character];
}
