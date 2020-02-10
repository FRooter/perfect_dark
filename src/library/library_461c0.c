#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_461c0.h"
#include "types.h"

GLOBAL_ASM(
glabel func000461c0
/*    461c0:	310c0007 */ 	andi	$t4,$t0,0x7
/*    461c4:	240b0008 */ 	addiu	$t3,$zero,0x8
/*    461c8:	908d0000 */ 	lbu	$t5,0x0($a0)
/*    461cc:	908a0001 */ 	lbu	$t2,0x1($a0)
/*    461d0:	000d4a00 */ 	sll	$t1,$t5,0x8
/*    461d4:	012a4825 */ 	or	$t1,$t1,$t2
/*    461d8:	016c5822 */ 	sub	$t3,$t3,$t4
/*    461dc:	01694806 */ 	srlv	$t1,$t1,$t3
/*    461e0:	312900ff */ 	andi	$t1,$t1,0xff
/*    461e4:	00065a00 */ 	sll	$t3,$a2,0x8
/*    461e8:	01695820 */ 	add	$t3,$t3,$t1
/*    461ec:	3c0a8006 */ 	lui	$t2,%hi(var8005f6fc)
/*    461f0:	254af6fc */ 	addiu	$t2,$t2,%lo(var8005f6fc)
/*    461f4:	8d4a0000 */ 	lw	$t2,0x0($t2)
/*    461f8:	016a5020 */ 	add	$t2,$t3,$t2
/*    461fc:	914a0000 */ 	lbu	$t2,0x0($t2)
/*    46200:	1140000d */ 	beqz	$t2,.L00046238
/*    46204:	00000000 */ 	sll	$zero,$zero,0x0
/*    46208:	010a4020 */ 	add	$t0,$t0,$t2
/*    4620c:	018a6020 */ 	add	$t4,$t4,$t2
/*    46210:	000c60c2 */ 	srl	$t4,$t4,0x3
/*    46214:	008c2020 */ 	add	$a0,$a0,$t4
/*    46218:	3c0a8006 */ 	lui	$t2,%hi(var8005f6f8)
/*    4621c:	254af6f8 */ 	addiu	$t2,$t2,%lo(var8005f6f8)
/*    46220:	8d4a0000 */ 	lw	$t2,0x0($t2)
/*    46224:	016a5020 */ 	add	$t2,$t3,$t2
/*    46228:	914a0000 */ 	lbu	$t2,0x0($t2)
/*    4622c:	000a4902 */ 	srl	$t1,$t2,0x4
/*    46230:	03e00008 */ 	jr	$ra
/*    46234:	3142000f */ 	andi	$v0,$t2,0xf
.L00046238:
/*    46238:	00107820 */ 	add	$t7,$zero,$s0
/*    4623c:	31090007 */ 	andi	$t1,$t0,0x7
/*    46240:	240a0080 */ 	addiu	$t2,$zero,0x80
/*    46244:	012a5006 */ 	srlv	$t2,$t2,$t1
/*    46248:	240effff */ 	addiu	$t6,$zero,-1
.L0004624c:
/*    4624c:	01aa6024 */ 	and	$t4,$t5,$t2
/*    46250:	51800002 */ 	beqzl	$t4,.L0004625c
/*    46254:	91ec0000 */ 	lbu	$t4,0x0($t7)
/*    46258:	91ec0001 */ 	lbu	$t4,0x1($t7)
.L0004625c:
/*    4625c:	000a5042 */ 	srl	$t2,$t2,0x1
/*    46260:	000c6080 */ 	sll	$t4,$t4,0x2
/*    46264:	15400004 */ 	bnez	$t2,.L00046278
/*    46268:	01ec7820 */ 	add	$t7,$t7,$t4
/*    4626c:	240a0080 */ 	addiu	$t2,$zero,0x80
/*    46270:	20840001 */ 	addi	$a0,$a0,0x1
/*    46274:	908d0000 */ 	lbu	$t5,0x0($a0)
.L00046278:
/*    46278:	81e90002 */ 	lb	$t1,0x2($t7)
/*    4627c:	112efff3 */ 	beq	$t1,$t6,.L0004624c
/*    46280:	21080001 */ 	addi	$t0,$t0,0x1
/*    46284:	00091020 */ 	add	$v0,$zero,$t1
/*    46288:	03e00008 */ 	jr	$ra
/*    4628c:	81e90003 */ 	lb	$t1,0x3($t7)
);

GLOBAL_ASM(
glabel func00046290
/*    46290:	88890000 */ 	lwl	$t1,0x0($a0)
/*    46294:	98890003 */ 	lwr	$t1,0x3($a0)
/*    46298:	310a0007 */ 	andi	$t2,$t0,0x7
/*    4629c:	01515020 */ 	add	$t2,$t2,$s1
/*    462a0:	000a50c2 */ 	srl	$t2,$t2,0x3
/*    462a4:	008a2020 */ 	add	$a0,$a0,$t2
/*    462a8:	310a0007 */ 	andi	$t2,$t0,0x7
/*    462ac:	01494804 */ 	sllv	$t1,$t1,$t2
/*    462b0:	240a0020 */ 	addiu	$t2,$zero,0x20
/*    462b4:	01515022 */ 	sub	$t2,$t2,$s1
/*    462b8:	01491006 */ 	srlv	$v0,$t1,$t2
/*    462bc:	03e00008 */ 	jr	$ra
/*    462c0:	01114020 */ 	add	$t0,$t0,$s1
);

GLOBAL_ASM(
glabel func000462c4
/*    462c4:	8ca80000 */ 	lw	$t0,0x0($a1)
/*    462c8:	000848c2 */ 	srl	$t1,$t0,0x3
/*    462cc:	00892020 */ 	add	$a0,$a0,$t1
/*    462d0:	88890000 */ 	lwl	$t1,0x0($a0)
/*    462d4:	98890003 */ 	lwr	$t1,0x3($a0)
/*    462d8:	310a0007 */ 	andi	$t2,$t0,0x7
/*    462dc:	01494804 */ 	sllv	$t1,$t1,$t2
/*    462e0:	240a0020 */ 	addiu	$t2,$zero,0x20
/*    462e4:	01465022 */ 	sub	$t2,$t2,$a2
/*    462e8:	01491006 */ 	srlv	$v0,$t1,$t2
/*    462ec:	01064020 */ 	add	$t0,$t0,$a2
/*    462f0:	03e00008 */ 	jr	$ra
/*    462f4:	aca80000 */ 	sw	$t0,0x0($a1)
);

GLOBAL_ASM(
glabel func000462f8
/*    462f8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    462fc:	afbf0000 */ 	sw	$ra,0x0($sp)
/*    46300:	afb00004 */ 	sw	$s0,0x4($sp)
/*    46304:	afb10008 */ 	sw	$s1,0x8($sp)
/*    46308:	afb2000c */ 	sw	$s2,0xc($sp)
/*    4630c:	afb30010 */ 	sw	$s3,0x10($sp)
/*    46310:	afb40014 */ 	sw	$s4,0x14($sp)
/*    46314:	afb50018 */ 	sw	$s5,0x18($sp)
/*    46318:	afb6001c */ 	sw	$s6,0x1c($sp)
/*    4631c:	afb70020 */ 	sw	$s7,0x20($sp)
/*    46320:	afbe0024 */ 	sw	$s8,0x24($sp)
/*    46324:	afbc0028 */ 	sw	$gp,0x28($sp)
/*    46328:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    4632c:	8ca80000 */ 	lw	$t0,0x0($a1)
/*    46330:	00068080 */ 	sll	$s0,$a2,0x2
/*    46334:	3c09800a */ 	lui	$t1,%hi(var8009c650)
/*    46338:	2529c650 */ 	addiu	$t1,$t1,%lo(var8009c650)
/*    4633c:	02098020 */ 	add	$s0,$s0,$t1
/*    46340:	8e100000 */ 	lw	$s0,0x0($s0)
/*    46344:	8fb10040 */ 	lw	$s1,0x40($sp)
/*    46348:	8fb20044 */ 	lw	$s2,0x44($sp)
/*    4634c:	8fb30048 */ 	lw	$s3,0x48($sp)
/*    46350:	8fb4004c */ 	lw	$s4,0x4c($sp)
/*    46354:	8e730000 */ 	lw	$s3,0x0($s3)
/*    46358:	8e940000 */ 	lw	$s4,0x0($s4)
/*    4635c:	000848c2 */ 	srl	$t1,$t0,0x3
/*    46360:	00892020 */ 	add	$a0,$a0,$t1
/*    46364:	02474822 */ 	sub	$t1,$s2,$a3
/*    46368:	1920003b */ 	blez	$t1,.L00046458
/*    4636c:	00000000 */ 	sll	$zero,$zero,0x0
.L00046370:
/*    46370:	0c011870 */ 	jal	func000461c0
/*    46374:	00000000 */ 	sll	$zero,$zero,0x0
/*    46378:	12200007 */ 	beqz	$s1,.L00046398
/*    4637c:	0009b020 */ 	add	$s6,$zero,$t1
/*    46380:	240a000f */ 	addiu	$t2,$zero,0xf
/*    46384:	144a0004 */ 	bne	$v0,$t2,.L00046398
/*    46388:	00000000 */ 	sll	$zero,$zero,0x0
/*    4638c:	0c0118a4 */ 	jal	func00046290
/*    46390:	00000000 */ 	sll	$zero,$zero,0x0
/*    46394:	2042000f */ 	addi	$v0,$v0,0xf
.L00046398:
/*    46398:	5040000f */ 	beqzl	$v0,.L000463d8
/*    4639c:	a2800000 */ 	sb	$zero,0x0($s4)
/*    463a0:	80890000 */ 	lb	$t1,0x0($a0)
/*    463a4:	240b0007 */ 	addiu	$t3,$zero,0x7
/*    463a8:	310a0007 */ 	andi	$t2,$t0,0x7
/*    463ac:	214c0001 */ 	addi	$t4,$t2,0x1
/*    463b0:	000c60c2 */ 	srl	$t4,$t4,0x3
/*    463b4:	008c2020 */ 	add	$a0,$a0,$t4
/*    463b8:	016a5022 */ 	sub	$t2,$t3,$t2
/*    463bc:	01494806 */ 	srlv	$t1,$t1,$t2
/*    463c0:	31290001 */ 	andi	$t1,$t1,0x1
/*    463c4:	21080001 */ 	addi	$t0,$t0,0x1
/*    463c8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    463cc:	51200002 */ 	beqzl	$t1,.L000463d8
/*    463d0:	a2800000 */ 	sb	$zero,0x0($s4)
/*    463d4:	a28a0000 */ 	sb	$t2,0x0($s4)
.L000463d8:
/*    463d8:	12200008 */ 	beqz	$s1,.L000463fc
/*    463dc:	0002b820 */ 	add	$s7,$zero,$v0
/*    463e0:	240a000f */ 	addiu	$t2,$zero,0xf
/*    463e4:	16ca0005 */ 	bne	$s6,$t2,.L000463fc
/*    463e8:	00000000 */ 	sll	$zero,$zero,0x0
/*    463ec:	0c0118a4 */ 	jal	func00046290
/*    463f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    463f4:	2056000f */ 	addi	$s6,$v0,0xf
/*    463f8:	00171020 */ 	add	$v0,$zero,$s7
.L000463fc:
/*    463fc:	a6620000 */ 	sh	$v0,0x0($s3)
/*    46400:	a6760002 */ 	sh	$s6,0x2($s3)
/*    46404:	22730004 */ 	addi	$s3,$s3,0x4
/*    46408:	52c0000f */ 	beqzl	$s6,.L00046448
/*    4640c:	a2800001 */ 	sb	$zero,0x1($s4)
/*    46410:	80890000 */ 	lb	$t1,0x0($a0)
/*    46414:	240b0007 */ 	addiu	$t3,$zero,0x7
/*    46418:	310a0007 */ 	andi	$t2,$t0,0x7
/*    4641c:	214c0001 */ 	addi	$t4,$t2,0x1
/*    46420:	000c60c2 */ 	srl	$t4,$t4,0x3
/*    46424:	008c2020 */ 	add	$a0,$a0,$t4
/*    46428:	016a5022 */ 	sub	$t2,$t3,$t2
/*    4642c:	01494806 */ 	srlv	$t1,$t1,$t2
/*    46430:	31290001 */ 	andi	$t1,$t1,0x1
/*    46434:	21080001 */ 	addi	$t0,$t0,0x1
/*    46438:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    4643c:	51200002 */ 	beqzl	$t1,.L00046448
/*    46440:	a2800001 */ 	sb	$zero,0x1($s4)
/*    46444:	a28a0001 */ 	sb	$t2,0x1($s4)
.L00046448:
/*    46448:	20e70002 */ 	addi	$a3,$a3,0x2
/*    4644c:	02474822 */ 	sub	$t1,$s2,$a3
/*    46450:	1d20ffc7 */ 	bgtz	$t1,.L00046370
/*    46454:	22940002 */ 	addi	$s4,$s4,0x2
.L00046458:
/*    46458:	aca80000 */ 	sw	$t0,0x0($a1)
/*    4645c:	8fa80048 */ 	lw	$t0,0x48($sp)
/*    46460:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*    46464:	ad130000 */ 	sw	$s3,0x0($t0)
/*    46468:	ad340000 */ 	sw	$s4,0x0($t1)
/*    4646c:	8fbf0000 */ 	lw	$ra,0x0($sp)
/*    46470:	8fb00004 */ 	lw	$s0,0x4($sp)
/*    46474:	8fb10008 */ 	lw	$s1,0x8($sp)
/*    46478:	8fb2000c */ 	lw	$s2,0xc($sp)
/*    4647c:	8fb30010 */ 	lw	$s3,0x10($sp)
/*    46480:	8fb40014 */ 	lw	$s4,0x14($sp)
/*    46484:	8fb50018 */ 	lw	$s5,0x18($sp)
/*    46488:	8fb6001c */ 	lw	$s6,0x1c($sp)
/*    4648c:	8fb70020 */ 	lw	$s7,0x20($sp)
/*    46490:	8fbe0024 */ 	lw	$s8,0x24($sp)
/*    46494:	8fbc0028 */ 	lw	$gp,0x28($sp)
/*    46498:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    4649c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    464a0:	03e00008 */ 	jr	$ra
/*    464a4:	00071020 */ 	add	$v0,$zero,$a3
);

GLOBAL_ASM(
glabel func000464a8
/*    464a8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    464ac:	afbf0000 */ 	sw	$ra,0x0($sp)
/*    464b0:	afb00004 */ 	sw	$s0,0x4($sp)
/*    464b4:	afb10008 */ 	sw	$s1,0x8($sp)
/*    464b8:	afb2000c */ 	sw	$s2,0xc($sp)
/*    464bc:	afb30010 */ 	sw	$s3,0x10($sp)
/*    464c0:	afb40014 */ 	sw	$s4,0x14($sp)
/*    464c4:	afb50018 */ 	sw	$s5,0x18($sp)
/*    464c8:	afb6001c */ 	sw	$s6,0x1c($sp)
/*    464cc:	afb70020 */ 	sw	$s7,0x20($sp)
/*    464d0:	afbe0024 */ 	sw	$s8,0x24($sp)
/*    464d4:	afbc0028 */ 	sw	$gp,0x28($sp)
/*    464d8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    464dc:	8ca80000 */ 	lw	$t0,0x0($a1)
/*    464e0:	00068080 */ 	sll	$s0,$a2,0x2
/*    464e4:	3c09800a */ 	lui	$t1,%hi(var8009c650)
/*    464e8:	2529c650 */ 	addiu	$t1,$t1,%lo(var8009c650)
/*    464ec:	02098020 */ 	add	$s0,$s0,$t1
/*    464f0:	8e100000 */ 	lw	$s0,0x0($s0)
/*    464f4:	8fb20040 */ 	lw	$s2,0x40($sp)
/*    464f8:	8fb30044 */ 	lw	$s3,0x44($sp)
/*    464fc:	8fb40048 */ 	lw	$s4,0x48($sp)
/*    46500:	8e730000 */ 	lw	$s3,0x0($s3)
/*    46504:	8e940000 */ 	lw	$s4,0x0($s4)
/*    46508:	000848c2 */ 	srl	$t1,$t0,0x3
/*    4650c:	00892020 */ 	add	$a0,$a0,$t1
/*    46510:	02484822 */ 	sub	$t1,$s2,$t0
/*    46514:	19200037 */ 	blez	$t1,.L000465f4
/*    46518:	00000000 */ 	sll	$zero,$zero,0x0
/*    4651c:	20e9fdc0 */ 	addi	$t1,$a3,-576
/*    46520:	05210034 */ 	bgez	$t1,.L000465f4
/*    46524:	00000000 */ 	sll	$zero,$zero,0x0
.L00046528:
/*    46528:	0c011870 */ 	jal	func000461c0
/*    4652c:	00000000 */ 	sll	$zero,$zero,0x0
/*    46530:	000258c2 */ 	srl	$t3,$v0,0x3
/*    46534:	316b0001 */ 	andi	$t3,$t3,0x1
/*    46538:	00026082 */ 	srl	$t4,$v0,0x2
/*    4653c:	318c0001 */ 	andi	$t4,$t4,0x1
/*    46540:	00026842 */ 	srl	$t5,$v0,0x1
/*    46544:	31ad0001 */ 	andi	$t5,$t5,0x1
/*    46548:	304e0001 */ 	andi	$t6,$v0,0x1
/*    4654c:	a66b0000 */ 	sh	$t3,0x0($s3)
/*    46550:	a66c0002 */ 	sh	$t4,0x2($s3)
/*    46554:	a66d0004 */ 	sh	$t5,0x4($s3)
/*    46558:	a66e0006 */ 	sh	$t6,0x6($s3)
/*    4655c:	0c0118a4 */ 	jal	func00046290
/*    46560:	24110004 */ 	addiu	$s1,$zero,0x4
/*    46564:	24110003 */ 	addiu	$s1,$zero,0x3
/*    46568:	a2820000 */ 	sb	$v0,0x0($s4)
/*    4656c:	11600003 */ 	beqz	$t3,.L0004657c
/*    46570:	02224806 */ 	srlv	$t1,$v0,$s1
/*    46574:	01695824 */ 	and	$t3,$t3,$t1
/*    46578:	2231ffff */ 	addi	$s1,$s1,-1
.L0004657c:
/*    4657c:	11800004 */ 	beqz	$t4,.L00046590
/*    46580:	a28b0000 */ 	sb	$t3,0x0($s4)
/*    46584:	02224806 */ 	srlv	$t1,$v0,$s1
/*    46588:	01896024 */ 	and	$t4,$t4,$t1
/*    4658c:	2231ffff */ 	addi	$s1,$s1,-1
.L00046590:
/*    46590:	11a00004 */ 	beqz	$t5,.L000465a4
/*    46594:	a28c0001 */ 	sb	$t4,0x1($s4)
/*    46598:	02224806 */ 	srlv	$t1,$v0,$s1
/*    4659c:	01a96824 */ 	and	$t5,$t5,$t1
/*    465a0:	2231ffff */ 	addi	$s1,$s1,-1
.L000465a4:
/*    465a4:	11c00004 */ 	beqz	$t6,.L000465b8
/*    465a8:	a28d0002 */ 	sb	$t5,0x2($s4)
/*    465ac:	02224806 */ 	srlv	$t1,$v0,$s1
/*    465b0:	01c97024 */ 	and	$t6,$t6,$t1
/*    465b4:	2231ffff */ 	addi	$s1,$s1,-1
.L000465b8:
/*    465b8:	a28e0003 */ 	sb	$t6,0x3($s4)
/*    465bc:	22310001 */ 	addi	$s1,$s1,0x1
/*    465c0:	31090007 */ 	andi	$t1,$t0,0x7
/*    465c4:	01314822 */ 	sub	$t1,$t1,$s1
/*    465c8:	05210002 */ 	bgez	$t1,.L000465d4
/*    465cc:	01114022 */ 	sub	$t0,$t0,$s1
/*    465d0:	2084ffff */ 	addi	$a0,$a0,-1
.L000465d4:
/*    465d4:	22730008 */ 	addi	$s3,$s3,0x8
/*    465d8:	22940004 */ 	addi	$s4,$s4,0x4
/*    465dc:	20e70004 */ 	addi	$a3,$a3,0x4
/*    465e0:	20e9fdc0 */ 	addi	$t1,$a3,-576
/*    465e4:	05210003 */ 	bgez	$t1,.L000465f4
/*    465e8:	02484822 */ 	sub	$t1,$s2,$t0
/*    465ec:	1d20ffce */ 	bgtz	$t1,.L00046528
/*    465f0:	00000000 */ 	sll	$zero,$zero,0x0
.L000465f4:
/*    465f4:	aca80000 */ 	sw	$t0,0x0($a1)
/*    465f8:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    465fc:	8fa90048 */ 	lw	$t1,0x48($sp)
/*    46600:	ad130000 */ 	sw	$s3,0x0($t0)
/*    46604:	ad340000 */ 	sw	$s4,0x0($t1)
/*    46608:	8fbf0000 */ 	lw	$ra,0x0($sp)
/*    4660c:	8fb00004 */ 	lw	$s0,0x4($sp)
/*    46610:	8fb10008 */ 	lw	$s1,0x8($sp)
/*    46614:	8fb2000c */ 	lw	$s2,0xc($sp)
/*    46618:	8fb30010 */ 	lw	$s3,0x10($sp)
/*    4661c:	8fb40014 */ 	lw	$s4,0x14($sp)
/*    46620:	8fb50018 */ 	lw	$s5,0x18($sp)
/*    46624:	8fb6001c */ 	lw	$s6,0x1c($sp)
/*    46628:	8fb70020 */ 	lw	$s7,0x20($sp)
/*    4662c:	8fbe0024 */ 	lw	$s8,0x24($sp)
/*    46630:	8fbc0028 */ 	lw	$gp,0x28($sp)
/*    46634:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    46638:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    4663c:	03e00008 */ 	jr	$ra
/*    46640:	00071020 */ 	add	$v0,$zero,$a3
/*    46644:	00000000 */ 	sll	$zero,$zero,0x0
/*    46648:	00000000 */ 	sll	$zero,$zero,0x0
/*    4664c:	00000000 */ 	sll	$zero,$zero,0x0
);