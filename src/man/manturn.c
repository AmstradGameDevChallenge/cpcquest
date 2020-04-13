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
#include "cmp/tturn.h"
#include "man/manturn.h"
#include "man/mansprite.h"

TTurn turn;

////////////////////////////////////////////////////////////////////////////////
void ManTurnInit()
{
   ;         
}

////////////////////////////////////////////////////////////////////////////////
void ManTurnCreate()
{
   TTurn *t = &turn;
   
   t->currentid = 0;
   t->action = ST_move;
   t->currentmove = 0;
   t->dirmove = 0;
   t->stepmove = 0;
   t->trymove = 0;
}

////////////////////////////////////////////////////////////////////////////////
TTurn* ManTurnGet()
{
   return &turn;
}  

////////////////////////////////////////////////////////////////////////////////
void ManTurnSetNext()
{
   TTurn *t = &turn;
    
   t->currentid++;   
   if (t->currentid >= ManSpriteGetNumSprites())
   {
      t->currentid = 0;        
   }   
   t->action = ST_move;
   t->currentmove = 0;
   t->dirmove = 0;
   t->stepmove = 0;   
   t->trymove = 0; 
} 
