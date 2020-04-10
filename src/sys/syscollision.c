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
#include "man/manmap.h"
#include "img/tiles.h"

////////////////////////////////////////////////////////////////////////////////
void SysCollisionInit()
{      
   ;   
}

////////////////////////////////////////////////////////////////////////////////
void SysCollisionUpdate()
{
   TSprite* sprite = ManSpriteGet(PLAYER_SPRITE);
   u8 x = sprite->x;
   u8 y = sprite->y;
   
   if (sprite->move == 13)
   {
      x = sprite->x + 3;
   }     
   else if (sprite->move == -13)
   {
      x = sprite->x - 3;
   }         
   else if (sprite->move == 3)
   {
      y = sprite->y + 12;
   }    
   else if (sprite->move == -3)
   {
      y = sprite->y - 12;
   }    
   
   if (x != sprite->x || y != sprite->y)
   {   
      TSprite* enemy;
      u8 i;
      u8 num = ManSpriteGetNumSprites();
      u8 col = 0;      
        
      for (i = PLAYER_SPRITE + 1; i < num; i++)
      {            
         enemy = ManSpriteGet(i);
         
         if (x == enemy->x && y == enemy->y)
         {
            col = 1;
            break;
         }                  
      }    
      
      if (!col)
      {    
         const u8* map = ManMapGet();            
         if (map[x / TILES_00_W + (y / (TILES_00_H * 2)) * 20] >= 10)
         {
            col = 1;
         }                   
      }
      
      if (col)  
      {
         sprite->x = sprite->px;
         sprite->y = sprite->py;
         sprite->move = 0;            
         ManSpriteSetNextFrame(PLAYER_SPRITE);
      }
   }            
}