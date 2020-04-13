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
#include "man/mansprite.h"
#include "man/manmap.h"
#include "man/manturn.h"
#include "img/tiles.h"

////////////////////////////////////////////////////////////////////////////////
void SysCollisionInit()
{      
   ;   
}

////////////////////////////////////////////////////////////////////////////////
void SysCollisionUpdate()
{
   u8 x, y;      
   TTurn* turn = ManTurnGet();   
   TSprite* sprite = ManSpriteGet(turn->currentid);
  
   if (turn->action == ST_move && turn->stepmove == 1)
   {  
      x = sprite->x;
      y = sprite->y;
   
      if (turn->dirmove == 4)
      {
         x = sprite->x + 3;
      }     
      else if (turn->dirmove == 3)
      {
         x = sprite->x - 3;
      }         
      else if (turn->dirmove == 2)
      {
         y = sprite->y + 12;
      }    
      else if (turn->dirmove == 1)
      {
         y = sprite->y - 12;
      }    
      
      if (x != sprite->x || y != sprite->y)
      {   
         // check collision
         
         u8 col = 0;       
         TSprite* enemy;
         u8 j;
         u8 num = ManSpriteGetNumSprites();               
           
         for (j = 0; j < num; j++)
         {   
            // enemy collision
                     
            if (turn->currentid != j)
            {
               enemy = ManSpriteGet(j);
               
               if (x == enemy->x && y == enemy->y)
               {
                  col = 1;
                  break;
               }
            }                  
         }  
         
         if (!col)
         {    
            // map collision
            
            const u8* map = ManMapGet();            
            if (map[x / TILES_00_W + (y / (TILES_00_H * 2)) * 20] >= 10)
            {
               col = 1;
            }            
            else
            {
               if ((sprite->py == 0 && turn->dirmove == 1) 
                  || (sprite->py == 160 && turn->dirmove == 2))
               {
                  col = 1;
               }
            }       
         }
         
         if (col)  
         {
            sprite->x = sprite->px;
            sprite->y = sprite->py;
            if (turn->stepmove == 0)
            {
               turn->stepmove = 3;        
               turn->currentmove--;                              
            }
            else
            {
               turn->stepmove--;            
            }            
            turn->action = ST_move;
            turn->dirmove = 0;                        
            turn->trymove++;
            ManSpriteSetNextFrame(turn->currentid);
         }
      }     
   }         
}