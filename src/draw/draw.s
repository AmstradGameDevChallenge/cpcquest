;;-----------------------------LICENSE NOTICE-----------------------------------
;;  This file is part of CPC Quest
;;  Copyright (C) 2020 Antonio Corpas Cuenca
;;  This routines were inspired in CPCtelera drawing routines
;;
;;  This program is free software: you can redistribute it and/or modify
;;  it under the terms of the GNU Lesser General Public License as published by
;;  the Free Software Foundation, either version 3 of the License, or
;;  (at your option) any later version.
;;
;;  This program is distributed in the hope that it will be useful,
;;  but WITHOUT ANY WARRANTY; without even the implied warranty of
;;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;;  GNU Lesser General Public License for more details.
;;
;;  You should have received a copy of the GNU Lesser General Public License
;;  along with this program.  If not, see <http://www.gnu.org/licenses/>.
;;------------------------------------------------------------------------------

.macro jr__0
   .DW #0x0018  ;; JR #00 (Normally used as a modifiable jump, as jr 0 is an infinite loop)
.endm
.macro ld__a_ixl
   .dw #0x7DDD  ;; Opcode for ld a, ixl
.endm   
.macro ld__c_ixl
   .dw #0x4DDD  ;; Opcode for ld c, ixl
.endm
.macro dec__ixl
   .dw #0x2DDD  ;; Opcode for dec ixl
.endm     
.macro dec__ixh
   .dw #0x25DD  ;; Opcode for dec ixh
.endm 
.macro ld__ixl    Value 
   .db #0xDD, #0x2E, Value  ;; Opcode for ld ixl, Value
.endm

_DrawTileDoubleHeight::
   pop  af
   pop  hl
   pop  de
   pop  bc

   push af

   ld    a, #126
   sub   c
   sub   c
   ld (ds_DrawTileDoubleHeightWidth+#4), a
   ld (ds_DrawTileDoubleHeightWidth2+#4), a
   ld    a, b
   ex   de, hl

ds_DrawTileDoubleHeightWidth_next:
   ex   de, hl
   push hl

ds_DrawTileDoubleHeightWidth:
   ld   bc, #0x800
   jr__0
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi

   pop hl

   ex   de, hl
   add  hl, bc
   ld    b, a
   ld    a, h
   and   #0x38
   ld    a, b
   jp   nz, ds_DrawTileDoubleHeightWidth_next2

   ld   bc, #0xC050
   add  hl, bc
   jp ds_DrawTileDoubleHeightWidth_next2

ds_DrawTileDoubleHeightWidth_next2:
   ex   de, hl

ds_DrawTileDoubleHeightWidth2:
   ld   bc, #0x800
   jr__0
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi
   ldi

   dec   a
   ret   z

   ex   de, hl
   add  hl, bc
   ld    b, a
   ld    a, h
   and   #0x38
   ld    a, b
   jp   nz, ds_DrawTileDoubleHeightWidth_next

   ld   bc, #0xC050
   add  hl, bc
   jp ds_DrawTileDoubleHeightWidth_next 
   
_DrawSpriteDoubleHeight::
   ld (dms_restore_ix + 2), ix
   pop   hl
   pop   bc
   pop   de
   pop   ix
   ex   (sp), hl

ld__a_ixl
   ld (restore_ixl1 + 2), a
   ld (restore_ixl2 + 2), a

dms_sprite_height_loop1:
   push de

dms_sprite_width_loop1:
   ld    a, (bc)
   ld    l, a
   ld    a, (de)
   and (hl)
   or    l
   ld  (de), a
   inc  de
   inc  bc

   dec__ixl
   jr   nz,dms_sprite_width_loop1

   pop  de
   push hl
   push de

restore_ixl1:
   ld__ixl #00

   ld    a, d
   add   #0x08
   ld    d, a
   and   #0x38
   jr   nz, dms_sprite_height2

dms_sprite_8bit_boundary_crossed1:
   ld    a, e
   add   #0x50
   ld    e, a
   ld    a, d
   adc   #0xC0
   ld    d, a

dms_sprite_height2:

   pop hl
   push de
   push bc
   ld b,#0x00
   ld__c_ixl
   ldir
   pop bc
   pop de
   pop hl

   dec__ixh
   jr    z,dms_sprite_copy_ended

restore_ixl2:
   ld__ixl #00

   ld    a, d
   add   #0x08
   ld    d, a
   and   #0x38
   jr   nz, dms_sprite_height_loop1

dms_sprite_8bit_boundary_crossed2:
   ld    a, e
   add   #0x50
   ld    e, a
   ld    a, d
   adc   #0xC0
   ld    d, a

   jr  dms_sprite_height_loop1

dms_sprite_copy_ended:

dms_restore_ix:
   ld   ix, #0000
   ret   

