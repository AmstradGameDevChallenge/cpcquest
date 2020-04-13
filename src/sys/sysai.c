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
#include "man/manturn.h"

////////////////////////////////////////////////////////////////////////////////
void SysAIInit()
{      
   ;   
}

////////////////////////////////////////////////////////////////////////////////
void SysAIUpdate()
{         
   TTurn* turn = ManTurnGet();
   
   if (turn->currentid != ID_PLAYER)
   {
      TSprite *enemy = ManSpriteGet(turn->currentid);    
      TSprite *player = ManSpriteGet(ID_PLAYER);    
      
      if (turn->action == ST_move)
      {                                           
         if (turn->currentmove < enemy->move)
         {                             
            if (turn->stepmove == 0)
            {  
               u8 movement[4] = { 0, 0, 0, 0 };               
               u8 num = 0;
               u8 i;
               
               if (player->y < enemy->y) movement[0] = 1;
               if (player->y > enemy->y) movement[1] = 1;
               if (player->x < enemy->x) movement[2] = 1;
               if (player->x > enemy->x) movement[3] = 1;
               
               for (i = 0; i < 4; i++)
               {
                  if (movement[i] == 1)
                  {
                     if (num == turn->trymove)
                     {
                        break;
                     } 
                     num++;
                  }                  
               }
               
               switch (i)
               {
                  case 0:
                     turn->dirmove = 1;
                  break;
                  case 1:
                     turn->dirmove = 2;
                  break;
                  case 2:
                     turn->dirmove = 3;
                  break;
                  case 3:
                     turn->dirmove = 4;
                  break;                                    
                  default:
                     turn->action = ST_attack;
                  break;                  
               }
            }
         }    
         else
         {
            turn->action = ST_attack;
         }                   
      }  
      else
      {
         turn->action = ST_iddle;
      }             
   }     
}
