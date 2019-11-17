#include <ultra64.h>
#include "types.h"
#include "library/library_491b0.h"

GLOBAL_ASM(
glabel func00048ef0
/*    48ef0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    48ef4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    48ef8:	e7ac0028 */ 	swc1	$f12,0x28($sp)
/*    48efc:	0c01256c */ 	jal	func000495b0
/*    48f00:	afb00018 */ 	sw	$s0,0x18($sp)
/*    48f04:	3c0e8006 */ 	lui	$t6,0x8006
/*    48f08:	8dce0914 */ 	lw	$t6,0x914($t6)
/*    48f0c:	c7a40028 */ 	lwc1	$f4,0x28($sp)
/*    48f10:	3c0f8006 */ 	lui	$t7,0x8006
/*    48f14:	00408025 */ 	or	$s0,$v0,$zero
/*    48f18:	e5c40024 */ 	swc1	$f4,0x24($t6)
/*    48f1c:	8def0914 */ 	lw	$t7,0x914($t7)
/*    48f20:	02002025 */ 	or	$a0,$s0,$zero
/*    48f24:	95f80000 */ 	lhu	$t8,0x0($t7)
/*    48f28:	37190004 */ 	ori	$t9,$t8,0x4
/*    48f2c:	0c012588 */ 	jal	func00049620
/*    48f30:	a5f90000 */ 	sh	$t9,0x0($t7)
/*    48f34:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    48f38:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    48f3c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    48f40:	03e00008 */ 	jr	$ra
/*    48f44:	00000000 */ 	sll	$zero,$zero,0x0
/*    48f48:	00000000 */ 	sll	$zero,$zero,0x0
/*    48f4c:	00000000 */ 	sll	$zero,$zero,0x0
);