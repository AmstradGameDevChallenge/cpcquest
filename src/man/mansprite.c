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
#include "img/warrior.h"
#include "img/elf.h"
#include "img/wizard.h"
#include "img/dwarf.h"
#include "img/skaven.h"
#include "img/serpent.h"
#include "img/spider.h"

#define MAX_SPRITES 10

#define WARRIOR_FRAMES 2
const TFrame frameswarrior[WARRIOR_FRAMES] = {
   { 0, warrior_0 }, 
   { 0, warrior_1 } 
};

#define ELF_FRAMES 2
const TFrame frameself[ELF_FRAMES] = {
   { 0, elf_0 }, 
   { 0, elf_1 } 
};

#define WIZARD_FRAMES 2
const TFrame frameswizard[WIZARD_FRAMES] = {
   { 0, wizard_0 }, 
   { 0, wizard_1 } 
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

#define SPIDER_FRAMES 2
const TFrame framesspider[SPIDER_FRAMES] = {
   { 0, spider_0 }, 
   { 0, spider_1 } 
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
   s->attack = 0;  
   s->nframe = 0;      
   
   switch (num)
   {
      case ID_PLAYER:
         s->x = s->px = 16;
         s->y = s->py = 32;                  
         s->frame = &framesdwarf[0];
      break;      
      case ID_ENEMY01:
         s->x = s->px = 32;
         s->y = s->py = 32;               
         s->frame = &framesskaven[0];        
      break;      
      case ID_ENEMY02:
         s->x = s->px = 28;
         s->y = s->py = 144;               
         s->frame = &framesserpent[0];              
      break;      
      case ID_ENEMY03:
         s->x = s->px = 8;
         s->y = s->py = 128;               
         s->frame = &framesspider[0];         
      break;      
      case ID_ENEMY04:
         s->x = s->px = 36;
         s->y = s->py = 80;               
         s->frame = &frameswarrior[0];         
      break; 
      case ID_ENEMY05:
         s->x = s->px = 8;
         s->y = s->py = 96;               
         s->frame = &frameself[0];         
      break; 
      case ID_ENEMY06:
         s->x = s->px = 16;
         s->y = s->py = 160;               
         s->frame = &frameswizard[0];         
      break;                   
      default:
         s->x = s->px = 28;
         s->y = s->py = 144;               
         s->frame = &framesserpent[0];         
      break;
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

   switch (num)
   {
      case ID_PLAYER:
         if (s->nframe == DWARF_FRAMES) s->nframe = 0;      
         s->frame = &framesdwarf[s->nframe];  
      break;      
      case ID_ENEMY01:
         if (s->nframe == SKAVEN_FRAMES) s->nframe = 0;
         s->frame = &framesskaven[s->nframe];        
      break;      
      case ID_ENEMY02:
         if (s->nframe == SERPENT_FRAMES) s->nframe = 0;      
         s->frame = &framesserpent[s->nframe];            
      break;      
      case ID_ENEMY03:
         if (s->nframe == SPIDER_FRAMES) s->nframe = 0;      
         s->frame = &framesspider[s->nframe];         
      break;      
      case ID_ENEMY04:
         if (s->nframe == WARRIOR_FRAMES) s->nframe = 0;      
         s->frame = &frameswarrior[s->nframe];         
      break; 
      case ID_ENEMY05:
         if (s->nframe == ELF_FRAMES) s->nframe = 0;      
         s->frame = &frameself[s->nframe];         
      break; 
      case ID_ENEMY06:
         if (s->nframe == WIZARD_FRAMES) s->nframe = 0;      
         s->frame = &frameswizard[s->nframe];         
      break;             
      default:
         if (s->nframe == SERPENT_FRAMES) s->nframe = 0;      
         s->frame = &framesserpent[s->nframe];        
      break;
   }  
}

////////////////////////////////////////////////////////////////////////////////   
u8 ManSpriteGetNumSprites()
{
   return numsprites;
}
