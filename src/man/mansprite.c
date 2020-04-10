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
#include "mansprite.h"
#include "cmp/tsprite.h"
#include "img/elf.h"
#include "img/dwarf.h"
#include "img/skaven.h"
#include "img/serpent.h"

#define MAX_SPRITES 10

#define ELF_FRAMES 2
const TFrame frameself[ELF_FRAMES] = {
   { 0, elf }, 
   { 0, elf } 
};

#define DWARF_FRAMES 2
const TFrame framesdwarf[DWARF_FRAMES] = {
   { 0, dwarf_0 }, 
   { 0, dwarf_1 } 
};

#define SKAVEN_FRAMES 2
const TFrame framesskaven[SKAVEN_FRAMES] = {
   { 0, skaven_0 }, 
   { 0, skaven_1 } 
};

#define SERPENT_FRAMES 2
const TFrame framesserpent[SERPENT_FRAMES] = {
   { 0, serpent }, 
   { 0, serpent } 
};

u8 numsprites;

TSprite sprites[MAX_SPRITES];

////////////////////////////////////////////////////////////////////////////////
void ManSpriteInit()
{
   numsprites = 0;
}

////////////////////////////////////////////////////////////////////////////////
void ManSpriteCreate(u8 num)
{
   TSprite *s = &sprites[num];
   
   s->w = 4;
   s->h = 8;   
   s->move = 0;      
   s->nframe = 0;   
   
   if (num == PLAYER_SPRITE)
   {      
      s->x = s->px = 16;
      s->y = s->py = 64;      
         
      s->frame = &framesdwarf[0];
   }
   else
   {      
      s->x = s->px = 32;
      s->y = s->py = 64;      
         
      s->frame = &framesskaven[0];      
   }
      
   /*         
   u8 energy;
   u8 attack;
   u8 deffense;
   u8 force;   
   TFrame* frame; 
   */    
   
   numsprites++;
}

////////////////////////////////////////////////////////////////////////////////
TSprite* ManSpriteGet(u8 num)
{
   return &(sprites[num]);
}  

////////////////////////////////////////////////////////////////////////////////   
void ManSpriteSetNextFrame(u8 num)
{
   TSprite *s = ManSpriteGet(num);     
   
   s->nframe++;  
   if (num == PLAYER_SPRITE) 
   {
      if (s->nframe == DWARF_FRAMES) 
      {
         s->nframe = 0;
      }
      s->frame = &framesdwarf[s->nframe];   
   }
   else
   {
      if (s->nframe == SKAVEN_FRAMES) 
      {
         s->nframe = 0;
      }      
      s->frame = &framesskaven[s->nframe];   
   }   
}

////////////////////////////////////////////////////////////////////////////////   
u8 ManSpriteGetNumSprites()
{
   return numsprites;
}
