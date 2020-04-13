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
void SysInputInit()
{      
   ;   
}

////////////////////////////////////////////////////////////////////////////////
void SysInputUpdate()
{   
   TTurn* turn = ManTurnGet();      
      
   if (turn->currentid == ID_PLAYER)
   {      
      TSprite *sprite = ManSpriteGet(turn->currentid);
   
      if (turn->action == ST_move && turn->stepmove == 0)
      {
         static const cpct_keyID keys[10] = 
         {
            Key_CursorUp, Joy0_Up,
            Key_CursorDown, Joy0_Down,
            Key_CursorLeft, Joy0_Left,
            Key_CursorRight, Joy0_Right,
            Key_Z, Joy0_Fire1 
         };
         i8 k = -1;              
         u8 i;         
         
         //while (k == -1)
         {     
            if (cpct_isAnyKeyPressed())
            {
               for(i = 0; i < 10; i++)
               {
                  if (cpct_isKeyPressed(keys[i]))
                  {
                     k = i;
                     break;
                  }
               }
                                                                          
               switch(k)
               {
                  case 0:
                  case 1:
                     turn->dirmove = 1;
                  break;      
                  case 2:
                  case 3:
                     turn->dirmove = 2;
                  break;
                  case 4:
                  case 5:
                     turn->dirmove = 3;
                  break;
                  case 6:
                  case 7:
                     turn->dirmove = 4;
                  break;
                  case 8:
                  case 9:                                             
                     turn->action = ST_attack;
                  break; 
                  default:
                  break;     
               }    
            }   
         }         
      }       
   }        
}
