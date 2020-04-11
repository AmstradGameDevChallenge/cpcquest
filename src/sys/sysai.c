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
#include "cmp/tsprite.h"
#include "man/mansprite.h"

////////////////////////////////////////////////////////////////////////////////
void SysAIInit()
{      
   ;   
}

////////////////////////////////////////////////////////////////////////////////
void SysAIUpdate()
{   
   u8 i;
   u8 r;
   TSprite *sprite;
   u8 num = ManSpriteGetNumSprites();

   for (i = ID_ENEMY01; i < num; i++)
   {                 
      sprite = ManSpriteGet(i);   
      
      if (sprite->move == 0)
      {
         r = cpct_rand() & 7;
         
         switch(r)
         {
            case 0:
            case 1:
               sprite->move = -4;
            break;      
            case 2:
            case 3:
               sprite->move = 4;
            break;
            case 4:
            case 5:
               sprite->move = -14;
            break;
            case 6:
            case 7:
               sprite->move = 14;
            break;
            default:
            break;     
         }           
      }
   }              
}
