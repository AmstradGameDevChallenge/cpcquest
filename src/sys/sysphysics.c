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
void SysPhysicsInit()
{      
   ;   
}

////////////////////////////////////////////////////////////////////////////////
void SysPhysicsUpdate()
{      
   i8 mx = 0;
   i8 my = 0;   
   TTurn* turn = ManTurnGet();   
   TSprite *sprite = ManSpriteGet(turn->currentid);
      
   if (turn->action == ST_move)
   {            
      if (turn->dirmove == 4)
      {
         mx = 1;
      }
      else if (turn->dirmove == 3)
      {
         mx = -1;         
      }
      else if (turn->dirmove == 2)
      {
         my = 4;         
      }
      else if (turn->dirmove == 1)
      {
         my = -4;         
      }
      
      sprite->x += mx;
      sprite->y += my;
      
      if (mx != 0 || my != 0)
      {
         ManSpriteSetNextFrame(turn->currentid);         
         turn->stepmove++;
         
         if (turn->stepmove == 4)
         {
            turn->stepmove = 0;
            turn->dirmove = 0;
            turn->currentmove++;
            
            if (turn->currentmove == sprite->move)
            {               
               turn->action = ST_attack;               
            }
         }      
      }      
   } 
   else if (turn->action == ST_attack)
   {
      sprite->attack = cpct_rand() & 7;
      turn->action = ST_iddle;           
   }  
   else
   {
      ;
   }   
}
