#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_0125a0.h"
#include "game/game_013540.h"
#include "game/game_113220.h"
#include "game/game_157db0.h"
#include "game/pad.h"
#include "gvars/gvars.h"
#include "library/library_121e0.h"
#include "library/library_159b0.h"
#include "library/library_1a500.h"
#include "library/library_233c0.h"
#include "types.h"

const u32 var7f1a8280[] = {0x3dccccce};
const u32 var7f1a8284[] = {0x4164924b};
const u32 var7f1a8288[] = {0x3f6e147b};
const u32 var7f1a828c[] = {0x00000000};

GLOBAL_ASM(
glabel func0f0125a0
/*  f0125a0:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0125a4:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f0125a8:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f0125ac:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0125b0:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0125b4:	00049c00 */ 	sll	$s3,$a0,0x10
/*  f0125b8:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0125bc:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f0125c0:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f0125c4:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0125c8:	00137403 */ 	sra	$t6,$s3,0x10
/*  f0125cc:	00a6082a */ 	slt	$at,$a1,$a2
/*  f0125d0:	01c09825 */ 	or	$s3,$t6,$zero
/*  f0125d4:	00e08025 */ 	or	$s0,$a3,$zero
/*  f0125d8:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0125dc:	00c09025 */ 	or	$s2,$a2,$zero
/*  f0125e0:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f0125e4:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f0125e8:	1020001d */ 	beqz	$at,.L0f012660
/*  f0125ec:	ace00008 */ 	sw	$zero,0x8($a3)
/*  f0125f0:	3c148008 */ 	lui	$s4,%hi(stagethinglist_22e60)
/*  f0125f4:	2694ce40 */ 	addiu	$s4,$s4,%lo(stagethinglist_22e60)
/*  f0125f8:	27b50048 */ 	addiu	$s5,$sp,0x48
.L0f0125fc:
/*  f0125fc:	00133c00 */ 	sll	$a3,$s3,0x10
/*  f012600:	00077c03 */ 	sra	$t7,$a3,0x10
/*  f012604:	01e03825 */ 	or	$a3,$t7,$zero
/*  f012608:	00002025 */ 	or	$a0,$zero,$zero
/*  f01260c:	00002825 */ 	or	$a1,$zero,$zero
/*  f012610:	02803025 */ 	or	$a2,$s4,$zero
/*  f012614:	afb10010 */ 	sw	$s1,0x10($sp)
/*  f012618:	afb50014 */ 	sw	$s5,0x14($sp)
/*  f01261c:	0c009217 */ 	jal	func0002485c
/*  f012620:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f012624:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f012628:	87b90048 */ 	lh	$t9,0x48($sp)
/*  f01262c:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f012630:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f012634:	03194021 */ 	addu	$t0,$t8,$t9
/*  f012638:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f01263c:	87aa004a */ 	lh	$t2,0x4a($sp)
/*  f012640:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f012644:	0232082a */ 	slt	$at,$s1,$s2
/*  f012648:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f01264c:	ae0b0004 */ 	sw	$t3,0x4($s0)
/*  f012650:	87ad004c */ 	lh	$t5,0x4c($sp)
/*  f012654:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f012658:	1420ffe8 */ 	bnez	$at,.L0f0125fc
/*  f01265c:	ae0e0008 */ 	sw	$t6,0x8($s0)
.L0f012660:
/*  f012660:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f012664:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f012668:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f01266c:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f012670:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f012674:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f012678:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f01267c:	03e00008 */ 	jr	$ra
/*  f012680:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func0f012684
/*  f012684:	27bdff28 */ 	addiu	$sp,$sp,-216
/*  f012688:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f01268c:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f012690:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f012694:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f012698:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f01269c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0126a0:	3c058008 */ 	lui	$a1,%hi(var8007c0c0)
/*  f0126a4:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f0126a8:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f0126ac:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f0126b0:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0126b4:	24a5c0c0 */ 	addiu	$a1,$a1,%lo(var8007c0c0)
/*  f0126b8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0126bc:	2604045c */ 	addiu	$a0,$s0,0x45c
/*  f0126c0:	0c008be9 */ 	jal	func00022fa4
/*  f0126c4:	26060494 */ 	addiu	$a2,$s0,0x494
/*  f0126c8:	8e2e0284 */ 	lw	$t6,0x284($s1)
/*  f0126cc:	0c008c28 */ 	jal	func000230a0
/*  f0126d0:	8dc4047c */ 	lw	$a0,0x47c($t6)
/*  f0126d4:	3c017f1b */ 	lui	$at,%hi(var7f1a8280)
/*  f0126d8:	c4368280 */ 	lwc1	$f22,%lo(var7f1a8280)($at)
/*  f0126dc:	8e240284 */ 	lw	$a0,0x284($s1)
/*  f0126e0:	4405b000 */ 	mfc1	$a1,$f22
/*  f0126e4:	0c006bd6 */ 	jal	func0001af58
/*  f0126e8:	2484045c */ 	addiu	$a0,$a0,0x45c
/*  f0126ec:	3c013f80 */ 	lui	$at,0x3f80
/*  f0126f0:	44810000 */ 	mtc1	$at,$f0
/*  f0126f4:	4480a000 */ 	mtc1	$zero,$f20
/*  f0126f8:	8e240284 */ 	lw	$a0,0x284($s1)
/*  f0126fc:	44050000 */ 	mfc1	$a1,$f0
/*  f012700:	4406a000 */ 	mfc1	$a2,$f20
/*  f012704:	0c0077eb */ 	jal	func0001dfac
/*  f012708:	2484045c */ 	addiu	$a0,$a0,0x45c
/*  f01270c:	3c013f80 */ 	lui	$at,0x3f80
/*  f012710:	44810000 */ 	mtc1	$at,$f0
/*  f012714:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f012718:	3c017f1b */ 	lui	$at,%hi(var7f1a8284)
/*  f01271c:	c4228284 */ 	lwc1	$f2,%lo(var7f1a8284)($at)
/*  f012720:	ade003ac */ 	sw	$zero,0x3ac($t7)
/*  f012724:	3c017f1b */ 	lui	$at,%hi(var7f1a8288)
/*  f012728:	c4248288 */ 	lwc1	$f4,%lo(var7f1a8288)($at)
/*  f01272c:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f012730:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f012734:	3c108007 */ 	lui	$s0,%hi(var80075c00)
/*  f012738:	e70403b0 */ 	swc1	$f4,0x3b0($t8)
/*  f01273c:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f012740:	3c138007 */ 	lui	$s3,%hi(var80075c30)
/*  f012744:	26735c30 */ 	addiu	$s3,$s3,%lo(var80075c30)
/*  f012748:	af2003b4 */ 	sw	$zero,0x3b4($t9)
/*  f01274c:	8e280284 */ 	lw	$t0,0x284($s1)
/*  f012750:	26105c00 */ 	addiu	$s0,$s0,%lo(var80075c00)
/*  f012754:	27b200c8 */ 	addiu	$s2,$sp,0xc8
/*  f012758:	e50003b8 */ 	swc1	$f0,0x3b8($t0)
/*  f01275c:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f012760:	e52003bc */ 	swc1	$f0,0x3bc($t1)
/*  f012764:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f012768:	e55403c0 */ 	swc1	$f20,0x3c0($t2)
/*  f01276c:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f012770:	e57403c4 */ 	swc1	$f20,0x3c4($t3)
/*  f012774:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f012778:	e59403c8 */ 	swc1	$f20,0x3c8($t4)
/*  f01277c:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f012780:	e5b403cc */ 	swc1	$f20,0x3cc($t5)
/*  f012784:	8e2e0284 */ 	lw	$t6,0x284($s1)
/*  f012788:	e5d403d0 */ 	swc1	$f20,0x3d0($t6)
/*  f01278c:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f012790:	e5f403d4 */ 	swc1	$f20,0x3d4($t7)
/*  f012794:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f012798:	e71403d8 */ 	swc1	$f20,0x3d8($t8)
/*  f01279c:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f0127a0:	e73403dc */ 	swc1	$f20,0x3dc($t9)
/*  f0127a4:	8e280284 */ 	lw	$t0,0x284($s1)
/*  f0127a8:	e51403e0 */ 	swc1	$f20,0x3e0($t0)
/*  f0127ac:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f0127b0:	e53403e4 */ 	swc1	$f20,0x3e4($t1)
/*  f0127b4:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f0127b8:	e55403e8 */ 	swc1	$f20,0x3e8($t2)
/*  f0127bc:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f0127c0:	e57403ec */ 	swc1	$f20,0x3ec($t3)
/*  f0127c4:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f0127c8:	e59403f0 */ 	swc1	$f20,0x3f0($t4)
/*  f0127cc:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f0127d0:	e5b403f4 */ 	swc1	$f20,0x3f4($t5)
/*  f0127d4:	8e2e0284 */ 	lw	$t6,0x284($s1)
/*  f0127d8:	e5c203f8 */ 	swc1	$f2,0x3f8($t6)
/*  f0127dc:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f0127e0:	e5f403fc */ 	swc1	$f20,0x3fc($t7)
/*  f0127e4:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f0127e8:	e7020400 */ 	swc1	$f2,0x400($t8)
/*  f0127ec:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f0127f0:	e7340404 */ 	swc1	$f20,0x404($t9)
/*  f0127f4:	8e280284 */ 	lw	$t0,0x284($s1)
/*  f0127f8:	ad0203a0 */ 	sw	$v0,0x3a0($t0)
/*  f0127fc:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f012800:	ad2203a4 */ 	sw	$v0,0x3a4($t1)
/*  f012804:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f012808:	ad4203a8 */ 	sw	$v0,0x3a8($t2)
/*  f01280c:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f012810:	e5740408 */ 	swc1	$f20,0x408($t3)
/*  f012814:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f012818:	e594040c */ 	swc1	$f20,0x40c($t4)
/*  f01281c:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f012820:	e5b40410 */ 	swc1	$f20,0x410($t5)
/*  f012824:	8e2e0284 */ 	lw	$t6,0x284($s1)
/*  f012828:	e5d40414 */ 	swc1	$f20,0x414($t6)
/*  f01282c:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f012830:	e5f40418 */ 	swc1	$f20,0x418($t7)
/*  f012834:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f012838:	e714041c */ 	swc1	$f20,0x41c($t8)
/*  f01283c:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f012840:	e7340420 */ 	swc1	$f20,0x420($t9)
/*  f012844:	8e280284 */ 	lw	$t0,0x284($s1)
/*  f012848:	e5140424 */ 	swc1	$f20,0x424($t0)
/*  f01284c:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f012850:	e5340428 */ 	swc1	$f20,0x428($t1)
/*  f012854:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f012858:	e554042c */ 	swc1	$f20,0x42c($t2)
/*  f01285c:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f012860:	e5600430 */ 	swc1	$f0,0x430($t3)
/*  f012864:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f012868:	e5940434 */ 	swc1	$f20,0x434($t4)
/*  f01286c:	8e2d0284 */ 	lw	$t5,0x284($s1)
/*  f012870:	e5b40438 */ 	swc1	$f20,0x438($t5)
/*  f012874:	8e2e0284 */ 	lw	$t6,0x284($s1)
/*  f012878:	e5c0043c */ 	swc1	$f0,0x43c($t6)
/*  f01287c:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f012880:	e5f40440 */ 	swc1	$f20,0x440($t7)
/*  f012884:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f012888:	e7000444 */ 	swc1	$f0,0x444($t8)
/*  f01288c:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f012890:	e7340448 */ 	swc1	$f20,0x448($t9)
/*  f012894:	8e280284 */ 	lw	$t0,0x284($s1)
/*  f012898:	e514044c */ 	swc1	$f20,0x44c($t0)
/*  f01289c:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f0128a0:	e5200450 */ 	swc1	$f0,0x450($t1)
/*  f0128a4:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f0128a8:	e5540454 */ 	swc1	$f20,0x454($t2)
/*  f0128ac:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f0128b0:	ad600458 */ 	sw	$zero,0x458($t3)
.L0f0128b4:
/*  f0128b4:	c6060004 */ 	lwc1	$f6,0x4($s0)
/*  f0128b8:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f0128bc:	86040000 */ 	lh	$a0,0x0($s0)
/*  f0128c0:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0128c4:	02403825 */ 	or	$a3,$s2,$zero
/*  f0128c8:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0128cc:	44054000 */ 	mfc1	$a1,$f8
/*  f0128d0:	44068000 */ 	mfc1	$a2,$f16
/*  f0128d4:	0fc04968 */ 	jal	func0f0125a0
/*  f0128d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0128dc:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*  f0128e0:	c6120008 */ 	lwc1	$f18,0x8($s0)
/*  f0128e4:	c6040004 */ 	lwc1	$f4,0x4($s0)
/*  f0128e8:	448e4000 */ 	mtc1	$t6,$f8
/*  f0128ec:	26100018 */ 	addiu	$s0,$s0,0x18
/*  f0128f0:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f0128f4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0128f8:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f0128fc:	46068483 */ 	div.s	$f18,$f16,$f6
/*  f012900:	1613ffec */ 	bne	$s0,$s3,.L0f0128b4
/*  f012904:	e612fff4 */ 	swc1	$f18,-0xc($s0)
/*  f012908:	3c013f00 */ 	lui	$at,0x3f00
/*  f01290c:	3c0f8006 */ 	lui	$t7,%hi(var800623b0)
/*  f012910:	27b20088 */ 	addiu	$s2,$sp,0x88
/*  f012914:	25ef23b0 */ 	addiu	$t7,$t7,%lo(var800623b0)
/*  f012918:	4481b000 */ 	mtc1	$at,$f22
/*  f01291c:	25f9003c */ 	addiu	$t9,$t7,0x3c
/*  f012920:	02404025 */ 	or	$t0,$s2,$zero
.L0f012924:
/*  f012924:	8de10000 */ 	lw	$at,0x0($t7)
/*  f012928:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f01292c:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f012930:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f012934:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f012938:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f01293c:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f012940:	15f9fff8 */ 	bne	$t7,$t9,.L0f012924
/*  f012944:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f012948:	8de10000 */ 	lw	$at,0x0($t7)
/*  f01294c:	4407a000 */ 	mfc1	$a3,$f20
/*  f012950:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f012954:	ad010000 */ 	sw	$at,0x0($t0)
/*  f012958:	8e240284 */ 	lw	$a0,0x284($s1)
/*  f01295c:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f012960:	e7b60010 */ 	swc1	$f22,0x10($sp)
/*  f012964:	00003025 */ 	or	$a2,$zero,$zero
/*  f012968:	0c007733 */ 	jal	func0001dccc
/*  f01296c:	2484045c */ 	addiu	$a0,$a0,0x45c
/*  f012970:	8e240284 */ 	lw	$a0,0x284($s1)
/*  f012974:	0c006cef */ 	jal	func0001b3bc
/*  f012978:	2484045c */ 	addiu	$a0,$a0,0x45c
/*  f01297c:	27b30048 */ 	addiu	$s3,$sp,0x48
/*  f012980:	0c00566c */ 	jal	func000159b0
/*  f012984:	02602025 */ 	or	$a0,$s3,$zero
/*  f012988:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f01298c:	afb30088 */ 	sw	$s3,0x88($sp)
/*  f012990:	02402025 */ 	or	$a0,$s2,$zero
/*  f012994:	26090510 */ 	addiu	$t1,$s0,0x510
/*  f012998:	afa90098 */ 	sw	$t1,0x98($sp)
/*  f01299c:	0c0073af */ 	jal	func0001cebc
/*  f0129a0:	2605045c */ 	addiu	$a1,$s0,0x45c
/*  f0129a4:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f0129a8:	24130018 */ 	addiu	$s3,$zero,0x18
/*  f0129ac:	3c128007 */ 	lui	$s2,%hi(var80075c00)
/*  f0129b0:	c6040544 */ 	lwc1	$f4,0x544($s0)
/*  f0129b4:	26525c00 */ 	addiu	$s2,$s2,%lo(var80075c00)
/*  f0129b8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0129bc:	e6040414 */ 	swc1	$f4,0x414($s0)
/*  f0129c0:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f0129c4:	e5540418 */ 	swc1	$f20,0x418($t2)
/*  f0129c8:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f0129cc:	c6080584 */ 	lwc1	$f8,0x584($s0)
/*  f0129d0:	c60a0544 */ 	lwc1	$f10,0x544($s0)
/*  f0129d4:	460a4401 */ 	sub.s	$f16,$f8,$f10
/*  f0129d8:	e610041c */ 	swc1	$f16,0x41c($s0)
/*  f0129dc:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f0129e0:	c6060588 */ 	lwc1	$f6,0x588($s0)
/*  f0129e4:	c6120548 */ 	lwc1	$f18,0x548($s0)
/*  f0129e8:	46123101 */ 	sub.s	$f4,$f6,$f18
/*  f0129ec:	e6040420 */ 	swc1	$f4,0x420($s0)
/*  f0129f0:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f0129f4:	8e0b03ac */ 	lw	$t3,0x3ac($s0)
/*  f0129f8:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0129fc:	e7b60010 */ 	swc1	$f22,0x10($sp)
/*  f012a00:	01730019 */ 	multu	$t3,$s3
/*  f012a04:	2604045c */ 	addiu	$a0,$s0,0x45c
/*  f012a08:	00006012 */ 	mflo	$t4
/*  f012a0c:	024c1021 */ 	addu	$v0,$s2,$t4
/*  f012a10:	84450000 */ 	lh	$a1,0x0($v0)
/*  f012a14:	0c007733 */ 	jal	func0001dccc
/*  f012a18:	8c470004 */ 	lw	$a3,0x4($v0)
/*  f012a1c:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f012a20:	4406a000 */ 	mfc1	$a2,$f20
/*  f012a24:	8e0d03ac */ 	lw	$t5,0x3ac($s0)
/*  f012a28:	2604045c */ 	addiu	$a0,$s0,0x45c
/*  f012a2c:	01b30019 */ 	multu	$t5,$s3
/*  f012a30:	00007012 */ 	mflo	$t6
/*  f012a34:	024ec021 */ 	addu	$t8,$s2,$t6
/*  f012a38:	0c00777b */ 	jal	func0001ddec
/*  f012a3c:	8f050004 */ 	lw	$a1,0x4($t8)
/*  f012a40:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f012a44:	8e1903ac */ 	lw	$t9,0x3ac($s0)
/*  f012a48:	2604045c */ 	addiu	$a0,$s0,0x45c
/*  f012a4c:	03330019 */ 	multu	$t9,$s3
/*  f012a50:	00007812 */ 	mflo	$t7
/*  f012a54:	024f4021 */ 	addu	$t0,$s2,$t7
/*  f012a58:	0c007787 */ 	jal	func0001de1c
/*  f012a5c:	8d050008 */ 	lw	$a1,0x8($t0)
/*  f012a60:	8e240284 */ 	lw	$a0,0x284($s1)
/*  f012a64:	3c057f11 */ 	lui	$a1,0x7f11
/*  f012a68:	24a53220 */ 	addiu	$a1,$a1,0x3220
/*  f012a6c:	0c0077a6 */ 	jal	func0001de98
/*  f012a70:	2484045c */ 	addiu	$a0,$a0,0x45c
/*  f012a74:	0fc44c8f */ 	jal	func0f11323c
/*  f012a78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f012a7c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f012a80:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f012a84:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f012a88:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f012a8c:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f012a90:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f012a94:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f012a98:	03e00008 */ 	jr	$ra
/*  f012a9c:	27bd00d8 */ 	addiu	$sp,$sp,0xd8
);

GLOBAL_ASM(
glabel func0f012aa0
/*  f012aa0:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f012aa4:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f012aa8:	3c15800a */ 	lui	$s5,%hi(g_StageSetup)
/*  f012aac:	26b5d030 */ 	addiu	$s5,$s5,%lo(g_StageSetup)
/*  f012ab0:	8ea2001c */ 	lw	$v0,0x1c($s5)
/*  f012ab4:	3c04800a */ 	lui	$a0,%hi(g_PadsFile)
/*  f012ab8:	3c07800a */ 	lui	$a3,%hi(g_PadOffsets)
/*  f012abc:	24e72354 */ 	addiu	$a3,$a3,%lo(g_PadOffsets)
/*  f012ac0:	24842350 */ 	addiu	$a0,$a0,%lo(g_PadsFile)
/*  f012ac4:	244e0014 */ 	addiu	$t6,$v0,0x14
/*  f012ac8:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f012acc:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f012ad0:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f012ad4:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f012ad8:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f012adc:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f012ae0:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f012ae4:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f012ae8:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f012aec:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f012af0:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f012af4:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f012af8:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f012afc:	00009025 */ 	or	$s2,$zero,$zero
/*  f012b00:	0000a025 */ 	or	$s4,$zero,$zero
/*  f012b04:	1900005e */ 	blez	$t0,.L0f012c80
/*  f012b08:	00401825 */ 	or	$v1,$v0,$zero
/*  f012b0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f012b10:	4481a000 */ 	mtc1	$at,$f20
/*  f012b14:	afa80120 */ 	sw	$t0,0x120($sp)
/*  f012b18:	241effff */ 	addiu	$s8,$zero,-1
/*  f012b1c:	27b70064 */ 	addiu	$s7,$sp,0x64
/*  f012b20:	27b60090 */ 	addiu	$s6,$sp,0x90
/*  f012b24:	27b300c8 */ 	addiu	$s3,$sp,0xc8
.L0f012b28:
/*  f012b28:	3c07800a */ 	lui	$a3,%hi(g_PadOffsets)
/*  f012b2c:	24e72354 */ 	addiu	$a3,$a3,%lo(g_PadOffsets)
/*  f012b30:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f012b34:	8eb9001c */ 	lw	$t9,0x1c($s5)
/*  f012b38:	02402025 */ 	or	$a0,$s2,$zero
/*  f012b3c:	01f4c021 */ 	addu	$t8,$t7,$s4
/*  f012b40:	97020000 */ 	lhu	$v0,0x0($t8)
/*  f012b44:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f012b48:	02603025 */ 	or	$a2,$s3,$zero
/*  f012b4c:	0fc456ac */ 	jal	padUnpack
/*  f012b50:	03228821 */ 	addu	$s1,$t9,$v0
/*  f012b54:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f012b58:	00008025 */ 	or	$s0,$zero,$zero
/*  f012b5c:	02602025 */ 	or	$a0,$s3,$zero
/*  f012b60:	00095480 */ 	sll	$t2,$t1,0x12
/*  f012b64:	000a5d83 */ 	sra	$t3,$t2,0x16
/*  f012b68:	05610023 */ 	bgez	$t3,.L0f012bf8
/*  f012b6c:	02c02825 */ 	or	$a1,$s6,$zero
/*  f012b70:	02e03025 */ 	or	$a2,$s7,$zero
/*  f012b74:	24070014 */ 	addiu	$a3,$zero,0x14
/*  f012b78:	0fc58865 */ 	jal	func0f162194
/*  f012b7c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f012b80:	87ac0090 */ 	lh	$t4,0x90($sp)
/*  f012b84:	87ad0064 */ 	lh	$t5,0x64($sp)
/*  f012b88:	02602025 */ 	or	$a0,$s3,$zero
/*  f012b8c:	13cc0003 */ 	beq	$s8,$t4,.L0f012b9c
/*  f012b90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f012b94:	10000004 */ 	beqz	$zero,.L0f012ba8
/*  f012b98:	02c08025 */ 	or	$s0,$s6,$zero
.L0f012b9c:
/*  f012b9c:	13cd0002 */ 	beq	$s8,$t5,.L0f012ba8
/*  f012ba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f012ba4:	02e08025 */ 	or	$s0,$s7,$zero
.L0f012ba8:
/*  f012ba8:	52000014 */ 	beqzl	$s0,.L0f012bfc
/*  f012bac:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f012bb0:	0c00a900 */ 	jal	func0002a400
/*  f012bb4:	02002825 */ 	or	$a1,$s0,$zero
/*  f012bb8:	58400009 */ 	blezl	$v0,.L0f012be0
/*  f012bbc:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f012bc0:	86290002 */ 	lh	$t1,0x2($s1)
/*  f012bc4:	0002c100 */ 	sll	$t8,$v0,0x4
/*  f012bc8:	33193ff0 */ 	andi	$t9,$t8,0x3ff0
/*  f012bcc:	312ac00f */ 	andi	$t2,$t1,0xc00f
/*  f012bd0:	032a5825 */ 	or	$t3,$t9,$t2
/*  f012bd4:	10000008 */ 	beqz	$zero,.L0f012bf8
/*  f012bd8:	a62b0002 */ 	sh	$t3,0x2($s1)
/*  f012bdc:	860e0000 */ 	lh	$t6,0x0($s0)
.L0f012be0:
/*  f012be0:	86290002 */ 	lh	$t1,0x2($s1)
/*  f012be4:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f012be8:	31f83ff0 */ 	andi	$t8,$t7,0x3ff0
/*  f012bec:	3139c00f */ 	andi	$t9,$t1,0xc00f
/*  f012bf0:	03195025 */ 	or	$t2,$t8,$t9
/*  f012bf4:	a62a0002 */ 	sh	$t2,0x2($s1)
.L0f012bf8:
/*  f012bf8:	8e2b0000 */ 	lw	$t3,0x0($s1)
.L0f012bfc:
/*  f012bfc:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
/*  f012c00:	000b6382 */ 	srl	$t4,$t3,0xe
/*  f012c04:	318d0200 */ 	andi	$t5,$t4,0x200
/*  f012c08:	51a00016 */ 	beqzl	$t5,.L0f012c64
/*  f012c0c:	8fae0120 */ 	lw	$t6,0x120($sp)
/*  f012c10:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f012c14:	c7a800fc */ 	lwc1	$f8,0xfc($sp)
/*  f012c18:	c7b00100 */ 	lwc1	$f16,0x100($sp)
/*  f012c1c:	c7a40104 */ 	lwc1	$f4,0x104($sp)
/*  f012c20:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f012c24:	c7a80108 */ 	lwc1	$f8,0x108($sp)
/*  f012c28:	02402025 */ 	or	$a0,$s2,$zero
/*  f012c2c:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f012c30:	e7a600f8 */ 	swc1	$f6,0xf8($sp)
/*  f012c34:	c7b0010c */ 	lwc1	$f16,0x10c($sp)
/*  f012c38:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f012c3c:	e7aa00fc */ 	swc1	$f10,0xfc($sp)
/*  f012c40:	02602825 */ 	or	$a1,$s3,$zero
/*  f012c44:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f012c48:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*  f012c4c:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f012c50:	e7a60104 */ 	swc1	$f6,0x104($sp)
/*  f012c54:	e7aa0108 */ 	swc1	$f10,0x108($sp)
/*  f012c58:	0fc45864 */ 	jal	padCopyBboxFromPad
/*  f012c5c:	e7b2010c */ 	swc1	$f18,0x10c($sp)
/*  f012c60:	8fae0120 */ 	lw	$t6,0x120($sp)
.L0f012c64:
/*  f012c64:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f012c68:	26940002 */ 	addiu	$s4,$s4,0x2
/*  f012c6c:	164effae */ 	bne	$s2,$t6,.L0f012b28
/*  f012c70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f012c74:	3c03800a */ 	lui	$v1,0x800a
/*  f012c78:	8c632350 */ 	lw	$v1,0x2350($v1)
/*  f012c7c:	8ea2001c */ 	lw	$v0,0x1c($s5)
.L0f012c80:
/*  f012c80:	8c6f0008 */ 	lw	$t7,0x8($v1)
/*  f012c84:	004f4821 */ 	addu	$t1,$v0,$t7
/*  f012c88:	aea90000 */ 	sw	$t1,0x0($s5)
/*  f012c8c:	8c78000c */ 	lw	$t8,0xc($v1)
/*  f012c90:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f012c94:	aeb90004 */ 	sw	$t9,0x4($s5)
/*  f012c98:	8c6a0010 */ 	lw	$t2,0x10($v1)
/*  f012c9c:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f012ca0:	11600003 */ 	beqz	$t3,.L0f012cb0
/*  f012ca4:	aeab0008 */ 	sw	$t3,0x8($s5)
/*  f012ca8:	0fc050ba */ 	jal	func0f0142e8
/*  f012cac:	00000000 */ 	sll	$zero,$zero,0x0
.L0f012cb0:
/*  f012cb0:	8ea20000 */ 	lw	$v0,0x0($s5)
/*  f012cb4:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f012cb8:	05a20009 */ 	bltzl	$t5,.L0f012ce0
/*  f012cbc:	8ea20004 */ 	lw	$v0,0x4($s5)
.L0f012cc0:
/*  f012cc0:	8eae001c */ 	lw	$t6,0x1c($s5)
/*  f012cc4:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f012cc8:	8c580010 */ 	lw	$t8,0x10($v0)
/*  f012ccc:	24420010 */ 	addiu	$v0,$v0,0x10
/*  f012cd0:	01cf4821 */ 	addu	$t1,$t6,$t7
/*  f012cd4:	0701fffa */ 	bgez	$t8,.L0f012cc0
/*  f012cd8:	ac49fff4 */ 	sw	$t1,-0xc($v0)
/*  f012cdc:	8ea20004 */ 	lw	$v0,0x4($s5)
.L0f012ce0:
/*  f012ce0:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f012ce4:	5060000c */ 	beqzl	$v1,.L0f012d18
/*  f012ce8:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f012cec:
/*  f012cec:	8eb9001c */ 	lw	$t9,0x1c($s5)
/*  f012cf0:	8c4c0004 */ 	lw	$t4,0x4($v0)
/*  f012cf4:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f012cf8:	03235021 */ 	addu	$t2,$t9,$v1
/*  f012cfc:	ac4afff4 */ 	sw	$t2,-0xc($v0)
/*  f012d00:	8eab001c */ 	lw	$t3,0x1c($s5)
/*  f012d04:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f012d08:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f012d0c:	1460fff7 */ 	bnez	$v1,.L0f012cec
/*  f012d10:	ac4dfff8 */ 	sw	$t5,-0x8($v0)
/*  f012d14:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f012d18:
/*  f012d18:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f012d1c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f012d20:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f012d24:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f012d28:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f012d2c:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f012d30:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f012d34:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f012d38:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f012d3c:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f012d40:	03e00008 */ 	jr	$ra
/*  f012d44:	27bd0130 */ 	addiu	$sp,$sp,0x130
/*  f012d48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f012d4c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f012d50
/*  f012d50:	27bdfee0 */ 	addiu	$sp,$sp,-288
/*  f012d54:	3c03800a */ 	lui	$v1,0x800a
/*  f012d58:	8c63d030 */ 	lw	$v1,-0x2fd0($v1)
/*  f012d5c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f012d60:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f012d64:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f012d68:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f012d6c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f012d70:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f012d74:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f012d78:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f012d7c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f012d80:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f012d84:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f012d88:	00001025 */ 	or	$v0,$zero,$zero
/*  f012d8c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f012d90:	05c00007 */ 	bltz	$t6,.L0f012db0
/*  f012d94:	0060b025 */ 	or	$s6,$v1,$zero
/*  f012d98:	8ecf0010 */ 	lw	$t7,0x10($s6)
.L0f012d9c:
/*  f012d9c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f012da0:	26d60010 */ 	addiu	$s6,$s6,0x10
/*  f012da4:	05e3fffd */ 	bgezl	$t7,.L0f012d9c
/*  f012da8:	8ecf0010 */ 	lw	$t7,0x10($s6)
/*  f012dac:	0060b025 */ 	or	$s6,$v1,$zero
.L0f012db0:
/*  f012db0:	00022040 */ 	sll	$a0,$v0,0x1
/*  f012db4:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f012db8:	3498000f */ 	ori	$t8,$a0,0xf
/*  f012dbc:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f012dc0:	0c0048f2 */ 	jal	malloc
/*  f012dc4:	afa20118 */ 	sw	$v0,0x118($sp)
/*  f012dc8:	8fa80118 */ 	lw	$t0,0x118($sp)
/*  f012dcc:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f012dd0:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f012dd4:	aea20060 */ 	sw	$v0,0x60($s5)
/*  f012dd8:	0000a025 */ 	or	$s4,$zero,$zero
/*  f012ddc:	1900003c */ 	blez	$t0,.L0f012ed0
/*  f012de0:	0000f025 */ 	or	$s8,$zero,$zero
/*  f012de4:	27b7005c */ 	addiu	$s7,$sp,0x5c
/*  f012de8:	001e4900 */ 	sll	$t1,$s8,0x4
.L0f012dec:
/*  f012dec:	01369821 */ 	addu	$s3,$t1,$s6
/*  f012df0:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f012df4:	240500c0 */ 	addiu	$a1,$zero,0xc0
/*  f012df8:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f012dfc:	0fc456ac */ 	jal	padUnpack
/*  f012e00:	00009025 */ 	or	$s2,$zero,$zero
/*  f012e04:	1a80001c */ 	blez	$s4,.L0f012e78
/*  f012e08:	00008825 */ 	or	$s1,$zero,$zero
.L0f012e0c:
/*  f012e0c:	8eaa0060 */ 	lw	$t2,0x60($s5)
/*  f012e10:	240500c0 */ 	addiu	$a1,$zero,0xc0
/*  f012e14:	02e03025 */ 	or	$a2,$s7,$zero
/*  f012e18:	01515821 */ 	addu	$t3,$t2,$s1
/*  f012e1c:	856c0000 */ 	lh	$t4,0x0($t3)
/*  f012e20:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f012e24:	01b68021 */ 	addu	$s0,$t5,$s6
/*  f012e28:	0fc456ac */ 	jal	padUnpack
/*  f012e2c:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f012e30:	8fa200f8 */ 	lw	$v0,0xf8($sp)
/*  f012e34:	8fa300a4 */ 	lw	$v1,0xa4($sp)
/*  f012e38:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f012e3c:	0043082a */ 	slt	$at,$v0,$v1
/*  f012e40:	1420000d */ 	bnez	$at,.L0f012e78
/*  f012e44:	31cf2000 */ 	andi	$t7,$t6,0x2000
/*  f012e48:	54430009 */ 	bnel	$v0,$v1,.L0f012e70
/*  f012e4c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f012e50:	55e0000a */ 	bnezl	$t7,.L0f012e7c
/*  f012e54:	2682ffff */ 	addiu	$v0,$s4,-1
/*  f012e58:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f012e5c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f012e60:	0319082a */ 	slt	$at,$t8,$t9
/*  f012e64:	54200005 */ 	bnezl	$at,.L0f012e7c
/*  f012e68:	2682ffff */ 	addiu	$v0,$s4,-1
/*  f012e6c:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f012e70:
/*  f012e70:	1654ffe6 */ 	bne	$s2,$s4,.L0f012e0c
/*  f012e74:	26310002 */ 	addiu	$s1,$s1,0x2
.L0f012e78:
/*  f012e78:	2682ffff */ 	addiu	$v0,$s4,-1
.L0f012e7c:
/*  f012e7c:	0052082a */ 	slt	$at,$v0,$s2
/*  f012e80:	1420000a */ 	bnez	$at,.L0f012eac
/*  f012e84:	00128840 */ 	sll	$s1,$s2,0x1
/*  f012e88:	00021840 */ 	sll	$v1,$v0,0x1
/*  f012e8c:	2642ffff */ 	addiu	$v0,$s2,-1
/*  f012e90:	00022040 */ 	sll	$a0,$v0,0x1
.L0f012e94:
/*  f012e94:	8ea80060 */ 	lw	$t0,0x60($s5)
/*  f012e98:	01031021 */ 	addu	$v0,$t0,$v1
/*  f012e9c:	84490000 */ 	lh	$t1,0x0($v0)
/*  f012ea0:	2463fffe */ 	addiu	$v1,$v1,-2
/*  f012ea4:	1464fffb */ 	bne	$v1,$a0,.L0f012e94
/*  f012ea8:	a4490002 */ 	sh	$t1,0x2($v0)
.L0f012eac:
/*  f012eac:	8eaa0060 */ 	lw	$t2,0x60($s5)
/*  f012eb0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f012eb4:	01515821 */ 	addu	$t3,$t2,$s1
/*  f012eb8:	a57e0000 */ 	sh	$s8,0x0($t3)
/*  f012ebc:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f012ec0:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f012ec4:	57ccffc9 */ 	bnel	$s8,$t4,.L0f012dec
/*  f012ec8:	001e4900 */ 	sll	$t1,$s8,0x4
/*  f012ecc:	0000f025 */ 	or	$s8,$zero,$zero
.L0f012ed0:
/*  f012ed0:	8ead02bc */ 	lw	$t5,0x2bc($s5)
/*  f012ed4:	3c12800a */ 	lui	$s2,%hi(g_RoomPtrs)
/*  f012ed8:	26524928 */ 	addiu	$s2,$s2,%lo(g_RoomPtrs)
/*  f012edc:	19a0000e */ 	blez	$t5,.L0f012f18
/*  f012ee0:	00001025 */ 	or	$v0,$zero,$zero
/*  f012ee4:	8e4e0000 */ 	lw	$t6,0x0($s2)
.L0f012ee8:
/*  f012ee8:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f012eec:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f012ef0:	a1e00009 */ 	sb	$zero,0x9($t7)
/*  f012ef4:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f012ef8:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f012efc:	a720000c */ 	sh	$zero,0xc($t9)
/*  f012f00:	8ea802bc */ 	lw	$t0,0x2bc($s5)
/*  f012f04:	2442008c */ 	addiu	$v0,$v0,0x8c
/*  f012f08:	03c8082a */ 	slt	$at,$s8,$t0
/*  f012f0c:	5420fff6 */ 	bnezl	$at,.L0f012ee8
/*  f012f10:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f012f14:	0000f025 */ 	or	$s8,$zero,$zero
.L0f012f18:
/*  f012f18:	8fa90118 */ 	lw	$t1,0x118($sp)
/*  f012f1c:	3c12800a */ 	lui	$s2,%hi(g_RoomPtrs)
/*  f012f20:	26524928 */ 	addiu	$s2,$s2,%lo(g_RoomPtrs)
/*  f012f24:	1920002a */ 	blez	$t1,.L0f012fd0
/*  f012f28:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f012f2c:	00008825 */ 	or	$s1,$zero,$zero
/*  f012f30:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f012f34:	2413008c */ 	addiu	$s3,$zero,0x8c
/*  f012f38:	8eaa0060 */ 	lw	$t2,0x60($s5)
.L0f012f3c:
/*  f012f3c:	3c0e800a */ 	lui	$t6,0x800a
/*  f012f40:	8dced030 */ 	lw	$t6,-0x2fd0($t6)
/*  f012f44:	01515821 */ 	addu	$t3,$t2,$s1
/*  f012f48:	856c0000 */ 	lh	$t4,0x0($t3)
/*  f012f4c:	240500c0 */ 	addiu	$a1,$zero,0xc0
/*  f012f50:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f012f54:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f012f58:	01ae1021 */ 	addu	$v0,$t5,$t6
/*  f012f5c:	0fc456ac */ 	jal	padUnpack
/*  f012f60:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f012f64:	8faf00f8 */ 	lw	$t7,0xf8($sp)
/*  f012f68:	51f00008 */ 	beql	$t7,$s0,.L0f012f8c
/*  f012f6c:	8fa900fc */ 	lw	$t1,0xfc($sp)
/*  f012f70:	01f30019 */ 	multu	$t7,$s3
/*  f012f74:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f012f78:	01e08025 */ 	or	$s0,$t7,$zero
/*  f012f7c:	0000c812 */ 	mflo	$t9
/*  f012f80:	03194021 */ 	addu	$t0,$t8,$t9
/*  f012f84:	a51e000c */ 	sh	$s8,0xc($t0)
/*  f012f88:	8fa900fc */ 	lw	$t1,0xfc($sp)
.L0f012f8c:
/*  f012f8c:	312a2000 */ 	andi	$t2,$t1,0x2000
/*  f012f90:	5540000b */ 	bnezl	$t2,.L0f012fc0
/*  f012f94:	8faf0118 */ 	lw	$t7,0x118($sp)
/*  f012f98:	52140009 */ 	beql	$s0,$s4,.L0f012fc0
/*  f012f9c:	8faf0118 */ 	lw	$t7,0x118($sp)
/*  f012fa0:	02130019 */ 	multu	$s0,$s3
/*  f012fa4:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f012fa8:	00006012 */ 	mflo	$t4
/*  f012fac:	016c1021 */ 	addu	$v0,$t3,$t4
/*  f012fb0:	904d0009 */ 	lbu	$t5,0x9($v0)
/*  f012fb4:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f012fb8:	a04e0009 */ 	sb	$t6,0x9($v0)
/*  f012fbc:	8faf0118 */ 	lw	$t7,0x118($sp)
.L0f012fc0:
/*  f012fc0:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f012fc4:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f012fc8:	57cfffdc */ 	bnel	$s8,$t7,.L0f012f3c
/*  f012fcc:	8eaa0060 */ 	lw	$t2,0x60($s5)
.L0f012fd0:
/*  f012fd0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f012fd4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f012fd8:	aeb80330 */ 	sw	$t8,0x330($s5)
/*  f012fdc:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f012fe0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f012fe4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f012fe8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f012fec:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f012ff0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f012ff4:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f012ff8:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f012ffc:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f013000:	03e00008 */ 	jr	$ra
/*  f013004:	27bd0120 */ 	addiu	$sp,$sp,0x120
/*  f013008:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01300c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f013010
/*  f013010:	3c018008 */ 	lui	$at,0x8008
/*  f013014:	ac20e4a0 */ 	sw	$zero,-0x1b60($at)
/*  f013018:	3c018008 */ 	lui	$at,0x8008
/*  f01301c:	ac20e4a4 */ 	sw	$zero,-0x1b5c($at)
/*  f013020:	3c013f80 */ 	lui	$at,0x3f80
/*  f013024:	44812000 */ 	mtc1	$at,$f4
/*  f013028:	3c08800a */ 	lui	$t0,%hi(var800a3434)
/*  f01302c:	3c018008 */ 	lui	$at,0x8008
/*  f013030:	25083434 */ 	addiu	$t0,$t0,%lo(var800a3434)
/*  f013034:	240e0006 */ 	addiu	$t6,$zero,0x6
/*  f013038:	e424e4a8 */ 	swc1	$f4,-0x1b58($at)
/*  f01303c:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*  f013040:	3c0f800a */ 	lui	$t7,0x800a
/*  f013044:	8defa474 */ 	lw	$t7,-0x5b8c($t7)
/*  f013048:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01304c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013050:	29e1005a */ 	slti	$at,$t7,0x5a
/*  f013054:	14200002 */ 	bnez	$at,.L0f013060
/*  f013058:	3c05800a */ 	lui	$a1,%hi(var800a3430)
/*  f01305c:	ad000000 */ 	sw	$zero,0x0($t0)
.L0f013060:
/*  f013060:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f013064:	24a53430 */ 	addiu	$a1,$a1,%lo(var800a3430)
/*  f013068:	54400004 */ 	bnezl	$v0,.L0f01307c
/*  f01306c:	000220c0 */ 	sll	$a0,$v0,0x3
/*  f013070:	1000002b */ 	beqz	$zero,.L0f013120
/*  f013074:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f013078:	000220c0 */ 	sll	$a0,$v0,0x3
.L0f01307c:
/*  f01307c:	00822021 */ 	addu	$a0,$a0,$v0
/*  f013080:	00042100 */ 	sll	$a0,$a0,0x4
/*  f013084:	00822023 */ 	subu	$a0,$a0,$v0
/*  f013088:	000420c0 */ 	sll	$a0,$a0,0x3
/*  f01308c:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f013090:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f013094:	0081c024 */ 	and	$t8,$a0,$at
/*  f013098:	03002025 */ 	or	$a0,$t8,$zero
/*  f01309c:	0c0048f2 */ 	jal	malloc
/*  f0130a0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0130a4:	3c08800a */ 	lui	$t0,%hi(var800a3434)
/*  f0130a8:	25083434 */ 	addiu	$t0,$t0,%lo(var800a3434)
/*  f0130ac:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0130b0:	3c05800a */ 	lui	$a1,%hi(var800a3430)
/*  f0130b4:	24a53430 */ 	addiu	$a1,$a1,%lo(var800a3430)
/*  f0130b8:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f0130bc:	1b200018 */ 	blez	$t9,.L0f013120
/*  f0130c0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0130c4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0130c8:	240303c0 */ 	addiu	$v1,$zero,0x3c0
/*  f0130cc:	8ca90000 */ 	lw	$t1,0x0($a1)
.L0f0130d0:
/*  f0130d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0130d4:	01265021 */ 	addu	$t2,$t1,$a2
/*  f0130d8:	ad400000 */ 	sw	$zero,0x0($t2)
.L0f0130dc:
/*  f0130dc:	000460c0 */ 	sll	$t4,$a0,0x3
/*  f0130e0:	01846021 */ 	addu	$t4,$t4,$a0
/*  f0130e4:	8cab0000 */ 	lw	$t3,0x0($a1)
/*  f0130e8:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f0130ec:	01846023 */ 	subu	$t4,$t4,$a0
/*  f0130f0:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0130f4:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f0130f8:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f0130fc:	24420018 */ 	addiu	$v0,$v0,0x18
/*  f013100:	1443fff6 */ 	bne	$v0,$v1,.L0f0130dc
/*  f013104:	a5c0001c */ 	sh	$zero,0x1c($t6)
/*  f013108:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f01310c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f013110:	24c60478 */ 	addiu	$a2,$a2,0x478
/*  f013114:	008f082a */ 	slt	$at,$a0,$t7
/*  f013118:	5420ffed */ 	bnezl	$at,.L0f0130d0
/*  f01311c:	8ca90000 */ 	lw	$t1,0x0($a1)
.L0f013120:
/*  f013120:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f013124:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f013128:	03e00008 */ 	jr	$ra
/*  f01312c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f013130
/*  f013130:	3c0e8009 */ 	lui	$t6,0x8009
/*  f013134:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*  f013138:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01313c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f013140:	15c10006 */ 	bne	$t6,$at,.L0f01315c
/*  f013144:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013148:	3c08800a */ 	lui	$t0,%hi(var800a3444)
/*  f01314c:	25083444 */ 	addiu	$t0,$t0,%lo(var800a3444)
/*  f013150:	240f000a */ 	addiu	$t7,$zero,0xa
/*  f013154:	10000005 */ 	beqz	$zero,.L0f01316c
/*  f013158:	ad0f0000 */ 	sw	$t7,0x0($t0)
.L0f01315c:
/*  f01315c:	3c08800a */ 	lui	$t0,%hi(var800a3444)
/*  f013160:	25083444 */ 	addiu	$t0,$t0,%lo(var800a3444)
/*  f013164:	24180014 */ 	addiu	$t8,$zero,0x14
/*  f013168:	ad180000 */ 	sw	$t8,0x0($t0)
.L0f01316c:
/*  f01316c:	3c19800a */ 	lui	$t9,0x800a
/*  f013170:	8f39a474 */ 	lw	$t9,-0x5b8c($t9)
/*  f013174:	3c05800a */ 	lui	$a1,%hi(var800a3440)
/*  f013178:	24a53440 */ 	addiu	$a1,$a1,%lo(var800a3440)
/*  f01317c:	2b21005a */ 	slti	$at,$t9,0x5a
/*  f013180:	54200003 */ 	bnezl	$at,.L0f013190
/*  f013184:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f013188:	ad000000 */ 	sw	$zero,0x0($t0)
/*  f01318c:	8d020000 */ 	lw	$v0,0x0($t0)
.L0f013190:
/*  f013190:	54400004 */ 	bnezl	$v0,.L0f0131a4
/*  f013194:	00022080 */ 	sll	$a0,$v0,0x2
/*  f013198:	1000002c */ 	beqz	$zero,.L0f01324c
/*  f01319c:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f0131a0:	00022080 */ 	sll	$a0,$v0,0x2
.L0f0131a4:
/*  f0131a4:	00822023 */ 	subu	$a0,$a0,$v0
/*  f0131a8:	00042080 */ 	sll	$a0,$a0,0x2
/*  f0131ac:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0131b0:	000420c0 */ 	sll	$a0,$a0,0x3
/*  f0131b4:	00822023 */ 	subu	$a0,$a0,$v0
/*  f0131b8:	00042080 */ 	sll	$a0,$a0,0x2
/*  f0131bc:	0c0048f2 */ 	jal	malloc
/*  f0131c0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0131c4:	3c08800a */ 	lui	$t0,%hi(var800a3444)
/*  f0131c8:	25083444 */ 	addiu	$t0,$t0,%lo(var800a3444)
/*  f0131cc:	8d090000 */ 	lw	$t1,0x0($t0)
/*  f0131d0:	3c05800a */ 	lui	$a1,%hi(var800a3440)
/*  f0131d4:	24a53440 */ 	addiu	$a1,$a1,%lo(var800a3440)
/*  f0131d8:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f0131dc:	1920001b */ 	blez	$t1,.L0f01324c
/*  f0131e0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0131e4:	44800000 */ 	mtc1	$zero,$f0
/*  f0131e8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0131ec:	24030190 */ 	addiu	$v1,$zero,0x190
/*  f0131f0:	8caa0000 */ 	lw	$t2,0x0($a1)
.L0f0131f4:
/*  f0131f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0131f8:	01465821 */ 	addu	$t3,$t2,$a2
/*  f0131fc:	ad600000 */ 	sw	$zero,0x0($t3)
.L0f013200:
/*  f013200:	00046880 */ 	sll	$t5,$a0,0x2
/*  f013204:	01a46823 */ 	subu	$t5,$t5,$a0
/*  f013208:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f01320c:	01a46821 */ 	addu	$t5,$t5,$a0
/*  f013210:	8cac0000 */ 	lw	$t4,0x0($a1)
/*  f013214:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f013218:	01a46823 */ 	subu	$t5,$t5,$a0
/*  f01321c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f013220:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f013224:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f013228:	24420028 */ 	addiu	$v0,$v0,0x28
/*  f01322c:	1443fff4 */ 	bne	$v0,$v1,.L0f013200
/*  f013230:	e5e00014 */ 	swc1	$f0,0x14($t7)
/*  f013234:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f013238:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f01323c:	24c6019c */ 	addiu	$a2,$a2,0x19c
/*  f013240:	0098082a */ 	slt	$at,$a0,$t8
/*  f013244:	5420ffeb */ 	bnezl	$at,.L0f0131f4
/*  f013248:	8caa0000 */ 	lw	$t2,0x0($a1)
.L0f01324c:
/*  f01324c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f013250:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f013254:	03e00008 */ 	jr	$ra
/*  f013258:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01325c:	00000000 */ 	sll	$zero,$zero,0x0
);
