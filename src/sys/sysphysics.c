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
void SysPhysicsInit()
{      
   ;   
}

////////////////////////////////////////////////////////////////////////////////
void SysPhysicsUpdate()
{   
   u8 i;
   i8 mx, my;
   TSprite *sprite;
   u8 num = ManSpriteGetNumSprites();

   for (i = 0; i < num; i++)
   {     
      mx = my = 0;       
      sprite = ManSpriteGet(i);   
      
      if (sprite->move > 10)
      {
         sprite->move--;
         mx = 1;
      }
      else if (sprite->move < -10)
      {
         sprite->move++;
         mx = -1;         
      }
      else if (sprite->move > 0)
      {
         sprite->move--;
         my = 4;         
      }
      else if (sprite->move < 0)
      {
         sprite->move++;
         my = -4;         
      }
      
      sprite->x += mx;
      sprite->y += my;
      
      if (mx != 0 || my != 0)
      {
         ManSpriteSetNextFrame(i);
      }
      
      if (sprite->move == 10 || sprite->move == -10)
      {
         sprite->move = 0;
      }
   }              
}
