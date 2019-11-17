#include <ultra64.h>
#include "types.h"
#include "library/library_37650.h"
#include "library/library_3c4d0.h"

GLOBAL_ASM(
glabel func00037650
/*    37650:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    37654:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    37658:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3765c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    37660:	240e000e */ 	addiu	$t6,$zero,0xe
/*    37664:	a7ae0018 */ 	sh	$t6,0x18($sp)
/*    37668:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    3766c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    37670:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    37674:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    37678:	00003025 */ 	or	$a2,$zero,$zero
/*    3767c:	00003825 */ 	or	$a3,$zero,$zero
/*    37680:	0c00f184 */ 	jal	func0003c610
/*    37684:	24840048 */ 	addiu	$a0,$a0,0x48
/*    37688:	10000001 */ 	beqz	$zero,.L00037690
/*    3768c:	00000000 */ 	sll	$zero,$zero,0x0
.L00037690:
/*    37690:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    37694:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    37698:	03e00008 */ 	jr	$ra
/*    3769c:	00000000 */ 	sll	$zero,$zero,0x0
/*    376a0:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    376a4:	afa50004 */ 	sw	$a1,0x4($sp)
/*    376a8:	afa00000 */ 	sw	$zero,0x0($sp)
/*    376ac:	848e0002 */ 	lh	$t6,0x2($a0)
/*    376b0:	19c00010 */ 	blez	$t6,.L000376f4
/*    376b4:	00000000 */ 	sll	$zero,$zero,0x0
.L000376b8:
/*    376b8:	8faf0000 */ 	lw	$t7,0x0($sp)
/*    376bc:	8fa90004 */ 	lw	$t1,0x4($sp)
/*    376c0:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*    376c4:	0098c821 */ 	addu	$t9,$a0,$t8
/*    376c8:	8f280004 */ 	lw	$t0,0x4($t9)
/*    376cc:	00985821 */ 	addu	$t3,$a0,$t8
/*    376d0:	01095021 */ 	addu	$t2,$t0,$t1
/*    376d4:	ad6a0004 */ 	sw	$t2,0x4($t3)
/*    376d8:	8fac0000 */ 	lw	$t4,0x0($sp)
/*    376dc:	258d0001 */ 	addiu	$t5,$t4,0x1
/*    376e0:	afad0000 */ 	sw	$t5,0x0($sp)
/*    376e4:	848e0002 */ 	lh	$t6,0x2($a0)
/*    376e8:	01ae082a */ 	slt	$at,$t5,$t6
/*    376ec:	1420fff2 */ 	bnez	$at,.L000376b8
/*    376f0:	00000000 */ 	sll	$zero,$zero,0x0
.L000376f4:
/*    376f4:	10000001 */ 	beqz	$zero,.L000376fc
/*    376f8:	00000000 */ 	sll	$zero,$zero,0x0
.L000376fc:
/*    376fc:	03e00008 */ 	jr	$ra
/*    37700:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func00037704
/*    37704:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    37708:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3770c:	afa40028 */ 	sw	$a0,0x28($sp)
/*    37710:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    37714:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    37718:	afae0024 */ 	sw	$t6,0x24($sp)
/*    3771c:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    37720:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    37724:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    37728:	24014231 */ 	addiu	$at,$zero,0x4231
/*    3772c:	87190000 */ 	lh	$t9,0x0($t8)
/*    37730:	13210003 */ 	beq	$t9,$at,.L00037740
/*    37734:	00000000 */ 	sll	$zero,$zero,0x0
/*    37738:	10000027 */ 	beqz	$zero,.L000377d8
/*    3773c:	00000000 */ 	sll	$zero,$zero,0x0
.L00037740:
/*    37740:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    37744:	afa0001c */ 	sw	$zero,0x1c($sp)
/*    37748:	85090002 */ 	lh	$t1,0x2($t0)
/*    3774c:	19200020 */ 	blez	$t1,.L000377d0
/*    37750:	00000000 */ 	sll	$zero,$zero,0x0
.L00037754:
/*    37754:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    37758:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    3775c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    37760:	000b6080 */ 	sll	$t4,$t3,0x2
/*    37764:	014c6821 */ 	addu	$t5,$t2,$t4
/*    37768:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    3776c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    37770:	adb80004 */ 	sw	$t8,0x4($t5)
/*    37774:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    37778:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3777c:	00084880 */ 	sll	$t1,$t0,0x2
/*    37780:	03295821 */ 	addu	$t3,$t9,$t1
/*    37784:	8d6a0004 */ 	lw	$t2,0x4($t3)
/*    37788:	11400009 */ 	beqz	$t2,.L000377b0
/*    3778c:	00000000 */ 	sll	$zero,$zero,0x0
/*    37790:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    37794:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    37798:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    3779c:	000e7880 */ 	sll	$t7,$t6,0x2
/*    377a0:	018fc021 */ 	addu	$t8,$t4,$t7
/*    377a4:	8f040004 */ 	lw	$a0,0x4($t8)
/*    377a8:	0c00ddfa */ 	jal	func000377e8
/*    377ac:	8fa60020 */ 	lw	$a2,0x20($sp)
.L000377b0:
/*    377b0:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    377b4:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    377b8:	25a80001 */ 	addiu	$t0,$t5,0x1
/*    377bc:	afa8001c */ 	sw	$t0,0x1c($sp)
/*    377c0:	87290002 */ 	lh	$t1,0x2($t9)
/*    377c4:	0109082a */ 	slt	$at,$t0,$t1
/*    377c8:	1420ffe2 */ 	bnez	$at,.L00037754
/*    377cc:	00000000 */ 	sll	$zero,$zero,0x0
.L000377d0:
/*    377d0:	10000001 */ 	beqz	$zero,.L000377d8
/*    377d4:	00000000 */ 	sll	$zero,$zero,0x0
.L000377d8:
/*    377d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    377dc:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    377e0:	03e00008 */ 	jr	$ra
/*    377e4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000377e8
/*    377e8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    377ec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    377f0:	afa40020 */ 	sw	$a0,0x20($sp)
/*    377f4:	afa50024 */ 	sw	$a1,0x24($sp)
/*    377f8:	afa60028 */ 	sw	$a2,0x28($sp)
/*    377fc:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    37800:	91cf0002 */ 	lbu	$t7,0x2($t6)
/*    37804:	11e00003 */ 	beqz	$t7,.L00037814
/*    37808:	00000000 */ 	sll	$zero,$zero,0x0
/*    3780c:	10000038 */ 	beqz	$zero,.L000378f0
/*    37810:	00000000 */ 	sll	$zero,$zero,0x0
.L00037814:
/*    37814:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    37818:	24180001 */ 	addiu	$t8,$zero,0x1
/*    3781c:	a3380002 */ 	sb	$t8,0x2($t9)
/*    37820:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    37824:	8d090008 */ 	lw	$t1,0x8($t0)
/*    37828:	1120000b */ 	beqz	$t1,.L00037858
/*    3782c:	00000000 */ 	sll	$zero,$zero,0x0
/*    37830:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    37834:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    37838:	8d4b0008 */ 	lw	$t3,0x8($t2)
/*    3783c:	016c6821 */ 	addu	$t5,$t3,$t4
/*    37840:	ad4d0008 */ 	sw	$t5,0x8($t2)
/*    37844:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    37848:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    3784c:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    37850:	0c00de40 */ 	jal	func00037900
/*    37854:	8dc40008 */ 	lw	$a0,0x8($t6)
.L00037858:
/*    37858:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3785c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*    37860:	85f80000 */ 	lh	$t8,0x0($t7)
/*    37864:	1b000020 */ 	blez	$t8,.L000378e8
/*    37868:	00000000 */ 	sll	$zero,$zero,0x0
.L0003786c:
/*    3786c:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    37870:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    37874:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    37878:	00084880 */ 	sll	$t1,$t0,0x2
/*    3787c:	03295821 */ 	addu	$t3,$t9,$t1
/*    37880:	8d6c000c */ 	lw	$t4,0xc($t3)
/*    37884:	018d5021 */ 	addu	$t2,$t4,$t5
/*    37888:	ad6a000c */ 	sw	$t2,0xc($t3)
/*    3788c:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    37890:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    37894:	000fc080 */ 	sll	$t8,$t7,0x2
/*    37898:	01d84021 */ 	addu	$t0,$t6,$t8
/*    3789c:	8d19000c */ 	lw	$t9,0xc($t0)
/*    378a0:	13200009 */ 	beqz	$t9,.L000378c8
/*    378a4:	00000000 */ 	sll	$zero,$zero,0x0
/*    378a8:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    378ac:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    378b0:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    378b4:	000c6880 */ 	sll	$t5,$t4,0x2
/*    378b8:	012d5021 */ 	addu	$t2,$t1,$t5
/*    378bc:	8d44000c */ 	lw	$a0,0xc($t2)
/*    378c0:	0c00de40 */ 	jal	func00037900
/*    378c4:	8fa60028 */ 	lw	$a2,0x28($sp)
.L000378c8:
/*    378c8:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    378cc:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    378d0:	256f0001 */ 	addiu	$t7,$t3,0x1
/*    378d4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    378d8:	85d80000 */ 	lh	$t8,0x0($t6)
/*    378dc:	01f8082a */ 	slt	$at,$t7,$t8
/*    378e0:	1420ffe2 */ 	bnez	$at,.L0003786c
/*    378e4:	00000000 */ 	sll	$zero,$zero,0x0
.L000378e8:
/*    378e8:	10000001 */ 	beqz	$zero,.L000378f0
/*    378ec:	00000000 */ 	sll	$zero,$zero,0x0
.L000378f0:
/*    378f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    378f4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    378f8:	03e00008 */ 	jr	$ra
/*    378fc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00037900
/*    37900:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    37904:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    37908:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3790c:	afa50024 */ 	sw	$a1,0x24($sp)
/*    37910:	afa60028 */ 	sw	$a2,0x28($sp)
/*    37914:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    37918:	91cf0003 */ 	lbu	$t7,0x3($t6)
/*    3791c:	11e00003 */ 	beqz	$t7,.L0003792c
/*    37920:	00000000 */ 	sll	$zero,$zero,0x0
/*    37924:	10000023 */ 	beqz	$zero,.L000379b4
/*    37928:	00000000 */ 	sll	$zero,$zero,0x0
.L0003792c:
/*    3792c:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    37930:	24180001 */ 	addiu	$t8,$zero,0x1
/*    37934:	a3380003 */ 	sb	$t8,0x3($t9)
/*    37938:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3793c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*    37940:	8509000e */ 	lh	$t1,0xe($t0)
/*    37944:	19200019 */ 	blez	$t1,.L000379ac
/*    37948:	00000000 */ 	sll	$zero,$zero,0x0
.L0003794c:
/*    3794c:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    37950:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    37954:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    37958:	000b6080 */ 	sll	$t4,$t3,0x2
/*    3795c:	014c6821 */ 	addu	$t5,$t2,$t4
/*    37960:	8dae0010 */ 	lw	$t6,0x10($t5)
/*    37964:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    37968:	adb80010 */ 	sw	$t8,0x10($t5)
/*    3796c:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    37970:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    37974:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    37978:	00084880 */ 	sll	$t1,$t0,0x2
/*    3797c:	03295821 */ 	addu	$t3,$t9,$t1
/*    37980:	8d640010 */ 	lw	$a0,0x10($t3)
/*    37984:	0c00de71 */ 	jal	func000379c4
/*    37988:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    3798c:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    37990:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    37994:	254c0001 */ 	addiu	$t4,$t2,0x1
/*    37998:	afac001c */ 	sw	$t4,0x1c($sp)
/*    3799c:	85cf000e */ 	lh	$t7,0xe($t6)
/*    379a0:	018f082a */ 	slt	$at,$t4,$t7
/*    379a4:	1420ffe9 */ 	bnez	$at,.L0003794c
/*    379a8:	00000000 */ 	sll	$zero,$zero,0x0
.L000379ac:
/*    379ac:	10000001 */ 	beqz	$zero,.L000379b4
/*    379b0:	00000000 */ 	sll	$zero,$zero,0x0
.L000379b4:
/*    379b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    379b8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    379bc:	03e00008 */ 	jr	$ra
/*    379c0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000379c4
/*    379c4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    379c8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    379cc:	afa40018 */ 	sw	$a0,0x18($sp)
/*    379d0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    379d4:	afa60020 */ 	sw	$a2,0x20($sp)
/*    379d8:	8fae0018 */ 	lw	$t6,0x18($sp)
/*    379dc:	91cf000e */ 	lbu	$t7,0xe($t6)
/*    379e0:	11e00003 */ 	beqz	$t7,.L000379f0
/*    379e4:	00000000 */ 	sll	$zero,$zero,0x0
/*    379e8:	1000001a */ 	beqz	$zero,.L00037a54
/*    379ec:	00000000 */ 	sll	$zero,$zero,0x0
.L000379f0:
/*    379f0:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    379f4:	24180001 */ 	addiu	$t8,$zero,0x1
/*    379f8:	a338000e */ 	sb	$t8,0xe($t9)
/*    379fc:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    37a00:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    37a04:	8d090000 */ 	lw	$t1,0x0($t0)
/*    37a08:	012a5821 */ 	addu	$t3,$t1,$t2
/*    37a0c:	ad0b0000 */ 	sw	$t3,0x0($t0)
/*    37a10:	8fac0018 */ 	lw	$t4,0x18($sp)
/*    37a14:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    37a18:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    37a1c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*    37a20:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*    37a24:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    37a28:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    37a2c:	8f190008 */ 	lw	$t9,0x8($t8)
/*    37a30:	03295021 */ 	addu	$t2,$t9,$t1
/*    37a34:	af0a0008 */ 	sw	$t2,0x8($t8)
/*    37a38:	8fab0018 */ 	lw	$t3,0x18($sp)
/*    37a3c:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    37a40:	8fa60020 */ 	lw	$a2,0x20($sp)
/*    37a44:	0c00de99 */ 	jal	func00037a64
/*    37a48:	8d640008 */ 	lw	$a0,0x8($t3)
/*    37a4c:	10000001 */ 	beqz	$zero,.L00037a54
/*    37a50:	00000000 */ 	sll	$zero,$zero,0x0
.L00037a54:
/*    37a54:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    37a58:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    37a5c:	03e00008 */ 	jr	$ra
/*    37a60:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00037a64
/*    37a64:	908e0009 */ 	lbu	$t6,0x9($a0)
/*    37a68:	11c00003 */ 	beqz	$t6,.L00037a78
/*    37a6c:	00000000 */ 	sll	$zero,$zero,0x0
/*    37a70:	03e00008 */ 	jr	$ra
/*    37a74:	00000000 */ 	sll	$zero,$zero,0x0
.L00037a78:
/*    37a78:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    37a7c:	a08f0009 */ 	sb	$t7,0x9($a0)
/*    37a80:	8c980000 */ 	lw	$t8,0x0($a0)
/*    37a84:	0306c821 */ 	addu	$t9,$t8,$a2
/*    37a88:	ac990000 */ 	sw	$t9,0x0($a0)
/*    37a8c:	90880008 */ 	lbu	$t0,0x8($a0)
/*    37a90:	1500000c */ 	bnez	$t0,.L00037ac4
/*    37a94:	00000000 */ 	sll	$zero,$zero,0x0
/*    37a98:	8c890010 */ 	lw	$t1,0x10($a0)
/*    37a9c:	01255021 */ 	addu	$t2,$t1,$a1
/*    37aa0:	ac8a0010 */ 	sw	$t2,0x10($a0)
/*    37aa4:	8c8b000c */ 	lw	$t3,0xc($a0)
/*    37aa8:	11600004 */ 	beqz	$t3,.L00037abc
/*    37aac:	00000000 */ 	sll	$zero,$zero,0x0
/*    37ab0:	8c8c000c */ 	lw	$t4,0xc($a0)
/*    37ab4:	01856821 */ 	addu	$t5,$t4,$a1
/*    37ab8:	ac8d000c */ 	sw	$t5,0xc($a0)
.L00037abc:
/*    37abc:	1000000b */ 	beqz	$zero,.L00037aec
/*    37ac0:	00000000 */ 	sll	$zero,$zero,0x0
.L00037ac4:
/*    37ac4:	908e0008 */ 	lbu	$t6,0x8($a0)
/*    37ac8:	24010001 */ 	addiu	$at,$zero,0x1
/*    37acc:	15c10007 */ 	bne	$t6,$at,.L00037aec
/*    37ad0:	00000000 */ 	sll	$zero,$zero,0x0
/*    37ad4:	8c8f000c */ 	lw	$t7,0xc($a0)
/*    37ad8:	11e00004 */ 	beqz	$t7,.L00037aec
/*    37adc:	00000000 */ 	sll	$zero,$zero,0x0
/*    37ae0:	8c98000c */ 	lw	$t8,0xc($a0)
/*    37ae4:	0305c821 */ 	addu	$t9,$t8,$a1
/*    37ae8:	ac99000c */ 	sw	$t9,0xc($a0)
.L00037aec:
/*    37aec:	03e00008 */ 	jr	$ra
/*    37af0:	00000000 */ 	sll	$zero,$zero,0x0
/*    37af4:	03e00008 */ 	jr	$ra
/*    37af8:	00000000 */ 	sll	$zero,$zero,0x0
/*    37afc:	00000000 */ 	sll	$zero,$zero,0x0
);