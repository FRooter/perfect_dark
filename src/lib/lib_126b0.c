#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_126b0.h"
#include "lib/debughud.h"
#include "lib/memory.h"
#include "data.h"
#include "types.h"

struct memaspace {
	s32 addr;
	u32 size;
};

struct memaheap {
	u32 unk000;
	struct memaspace spaces[127];
};

s32 g_MemaHeapStart;
s32 g_MemaHeapSize;
struct memaheap g_MemaHeap;

void memaSwap(struct memaspace *a, struct memaspace *b)
{
	u32 tempaddr = a->addr;
	u32 tempsize = a->size;
	a->addr = b->addr;
	a->size = b->size;
	b->addr = tempaddr;
	b->size = tempsize;
}

void memaMerge(struct memaspace *a, struct memaspace *b)
{
	a->size += b->size;
	b->addr = 0;
	b->size = 0;
}

bool memaDefragPass(struct memaheap *heap)
{
	bool merged = false;
	struct memaspace *prev = &heap->spaces[0];
	struct memaspace *curr = &heap->spaces[1];
	struct memaspace *last = &heap->spaces[124];
	u32 addr = 0;

	while (curr <= last) {
		if (curr->size != 0) {
			if (curr->addr < addr) {
				memaSwap(curr, prev);
			}

			if (prev->size + addr == curr->addr) {
				memaMerge(prev, curr);
				curr = prev;
				merged = true;
			}

			prev = curr;
			addr = curr->addr;
		}

		curr++;
	}

	return merged;
}

void memaDefrag(void)
{
	while (memaDefragPass(&g_MemaHeap));
}

/**
 * Defrag the spaces list in an attempt to free up any slot.
 *
 * If none can be found, return the smallest run of free space so it can be
 * overwritten by the caller.
 */
struct memaspace *memaMakeSlot(struct memaheap *heap)
{
	struct memaspace *curr = &heap->spaces[1];
	struct memaspace *best;
	u32 min;
	s32 i;

	// Do 124 passes over the list. This ensures the list is in order by the
	// end. Though in most cases it's roughly in order anyway, and the excessive
	// looping is just wasting CPU cycles. In reality this situation probably
	// never occurs.
	for (i = 0; i < 124; i++) {
		while (curr <= &heap->spaces[124]) {
			if (curr->size == 0) {
				return curr;
			}

			if ((u32)curr[1].addr < (u32)curr[0].addr) {
				memaSwap(&curr[0], &curr[1]);
			}

			if (curr[1].addr == curr[0].size + curr[0].addr) {
				// Found two that can be merged
				curr[0].size += curr[1].size;
				curr[1].addr = 0;
				curr[1].size = 0;

				return &curr[1];
			}

			curr++;
		}

		curr = &heap->spaces[1];
	}

	// If this code is reached then the spaces list is so badly and unrepairably
	// fragmented that we can't find any slot to record the free space in.
	// Find the smallest run of free space and use that instead.
	// The caller will overwrite it with its own free allocation, causing the
	// original run of free space to be unusable until the mema heap is reset.
	min = 0xffffffff;
	best = curr;

	while (curr <= &heap->spaces[124]) {
		if (curr->size < min) {
			best = curr;
			min = curr->size;
		}

		curr++;
	}

	return best;
}

void _memaFree(s32 addr, s32 size)
{
	// Choose an index in the spaces array which we'll mark a space as free,
	// based on how far into the heap the allocation is. This is a rough
	// estimate and doesn't need to be any particular index, but the defrag
	// function tries to order the spaces by address so the closer we get to it
	// the less work the defrag function will have to do should it be called.
	s32 index = (addr - g_MemaHeapStart) * 124 / g_MemaHeapSize;
	struct memaspace *curr = &g_MemaHeap.spaces[index + 1];

	// If the entry is taken, keep moving forward until a zero is found.
	while (curr->size != 0) {
		curr++;
	}

	// If we reached the end of the spaces list, go backwards instead
	if (curr->addr == -1) {
		curr = &g_MemaHeap.spaces[index + 1];

		while (curr->size != 0) {
			curr--;
		}

		if (curr->addr == 0) {
			curr = memaMakeSlot(&g_MemaHeap);
		}
	}

	// Mark this space as free
	curr->addr = addr;
	curr->size = size;
}

void memaInit(void)
{
	// empty
}

void memaHeapInit(void *heapaddr, u32 heapsize)
{
	struct memaspace *space;

#if VERSION >= VERSION_NTSC_1_0
	heapsize += 0x8e0; // ?!
#endif

	g_MemaHeap.unk000 = 0;

	g_MemaHeap.spaces[0].addr = 0;
	g_MemaHeap.spaces[0].size = 0;

	g_MemaHeap.spaces[125].addr = 0xffffffff;
	g_MemaHeap.spaces[125].size = 0;
	g_MemaHeap.spaces[126].addr = 0xffffffff;
	g_MemaHeap.spaces[126].size = 0xffffffff;

	for (space = &g_MemaHeap.spaces[1]; space <= &g_MemaHeap.spaces[124]; space++) {
		space->addr = 0;
		space->size = 0;
	}

	g_MemaHeap.spaces[1].addr = g_MemaHeapStart = (u32)heapaddr;
	g_MemaHeap.spaces[1].size = g_MemaHeapSize = heapsize;
}

/**
 * Example printout of figures:
 *
 *     Mem Info
 *     memp: MP_LF_LEV
 *      F: 0 722352
 *      S: 972080 3668704
 *      Over: 2946352
 *     memp: MP_LF_ETER
 *      F: 0 0
 *      S: 601728 0
 *     mema:
 *      LF: 391728
 *     Audio Free: 13184
 *
 * Where two figures are shown in one line, the left refers to onboard memory
 * and the right refers to expansion pak memory.
 *
 * F means free.
 * S means size.
 *
 * "Over" shows how much it's over 4MB, if they were to try to fit the game into
 * onboard memory only. This shows "Free" if under 4MB.
 *
 * The ETER (permanent) pool has 0 free space because it's shrunk to fit once
 * the permanent allocations are done during startup. This pool fits entirely
 * in onboard memory, so the expansion size is 0.
 */
void memaPrint(void)
{
	s32 onboard;
	s32 expansion;
	s32 line = 1;
	s32 over;
	char buffer[124];

	memaDefragPass(&g_MemaHeap);

#if VERSION < VERSION_NTSC_1_0
	if (debugIsMemInfoEnabled()) {
		dhudSetFgColour(0xff, 0xff, 0xff, 0xff);
		dhudSetBgColour(0, 0, 0, 0xff);

		dhudSetPos(30, line);
		dhudPrintString("Mem Info");
		line++;

		dhudSetPos(30, line);
		dhudPrintString("memp: MP_LF_LEV");
		line++;

		onboard = memGetFree(MEMPOOL_STAGE, MEMBANK_ONBOARD);
		expansion = memGetFree(MEMPOOL_STAGE, MEMBANK_EXPANSION);
		sprintf(buffer, "F: %d %d", onboard, expansion);
		dhudSetPos(31, line);
		dhudPrintString(buffer);
		line++;

		onboard = memGetSize(MEMPOOL_STAGE, MEMBANK_ONBOARD);
		expansion = memGetSize(MEMPOOL_STAGE, MEMBANK_EXPANSION);
		sprintf(buffer, "S: %d %d", onboard, expansion);
		dhudSetPos(31, line);
		dhudPrintString(buffer);
		line++;

		over = memGetSize(MEMPOOL_STAGE, MEMBANK_EXPANSION)
			- memGetFree(MEMPOOL_STAGE, MEMBANK_EXPANSION)
			- memGetFree(MEMPOOL_STAGE, MEMBANK_ONBOARD);

		if (over >= 0) {
			sprintf(buffer, "Over: %d", over);
		} else {
			sprintf(buffer, "Free: %d", -over);
		}

		dhudSetPos(31, line);
		dhudPrintString(buffer);
		line++;

		dhudSetPos(30, line);
		dhudPrintString("memp: MP_LF_ETER");
		line++;

		onboard = memGetFree(MEMPOOL_PERMANENT, MEMBANK_ONBOARD);
		expansion = memGetFree(MEMPOOL_PERMANENT, MEMBANK_EXPANSION);
		sprintf(buffer, "F: %d %d", onboard, expansion);
		dhudSetPos(31, line);
		dhudPrintString(buffer);
		line++;

		onboard = memGetSize(MEMPOOL_PERMANENT, MEMBANK_ONBOARD);
		expansion = memGetSize(MEMPOOL_PERMANENT, MEMBANK_EXPANSION);
		sprintf(buffer, "S: %d %d", onboard, expansion);
		dhudSetPos(31, line);
		dhudPrintString(buffer);
		line++;

		dhudSetPos(30, line);
		dhudPrintString("mema:");
		line++;

		sprintf(buffer, "LF: %d", memaGetLongestFree());
		dhudSetPos(31, line);
		dhudPrintString(buffer);
		line++;

		sprintf(buffer, "Audio Free: %d", g_SndHeap.base + (g_SndHeap.len - (u32)g_SndHeap.cur));
		dhudSetPos(30, line);
		dhudPrintString(buffer);
		line++;
	}
#endif
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel memaAlloc
/*    12ab0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    12ab4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    12ab8:	afb10018 */ 	sw	$s1,0x18($sp)
/*    12abc:	00809025 */ 	or	$s2,$a0,$zero
/*    12ac0:	afb50028 */ 	sw	$s5,0x28($sp)
/*    12ac4:	afb00014 */ 	sw	$s0,0x14($sp)
/*    12ac8:	3c11800a */ 	lui	$s1,%hi(g_MemaHeap+0xc)
/*    12acc:	3c078009 */ 	lui	$a3,%hi(g_Is4Mb)
/*    12ad0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    12ad4:	afb40024 */ 	sw	$s4,0x24($sp)
/*    12ad8:	afb30020 */ 	sw	$s3,0x20($sp)
/*    12adc:	26319484 */ 	addiu	$s1,$s1,%lo(g_MemaHeap+0xc)
/*    12ae0:	2404ffff */ 	addiu	$a0,$zero,-1
/*    12ae4:	00004025 */ 	or	$t0,$zero,$zero
/*    12ae8:	24e70af0 */ 	addiu	$a3,$a3,%lo(g_Is4Mb)
/*    12aec:	00008025 */ 	or	$s0,$zero,$zero
/*    12af0:	2415ffff */ 	addiu	$s5,$zero,-1
/*    12af4:	24060001 */ 	addiu	$a2,$zero,0x1
/*    12af8:	24050010 */ 	addiu	$a1,$zero,0x10
.L00012afc:
/*    12afc:	8e230004 */ 	lw	$v1,0x4($s1)
/*    12b00:	26100001 */ 	addiu	$s0,$s0,0x1
/*    12b04:	0072082b */ 	sltu	$at,$v1,$s2
/*    12b08:	14200011 */ 	bnez	$at,.L00012b50
/*    12b0c:	00721023 */ 	subu	$v0,$v1,$s2
/*    12b10:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*    12b14:	0044082b */ 	sltu	$at,$v0,$a0
/*    12b18:	12ae000f */ 	beq	$s5,$t6,.L00012b58
/*    12b1c:	00000000 */ 	nop
/*    12b20:	1020000b */ 	beqz	$at,.L00012b50
/*    12b24:	2c410040 */ 	sltiu	$at,$v0,0x40
/*    12b28:	00402025 */ 	or	$a0,$v0,$zero
/*    12b2c:	1420000a */ 	bnez	$at,.L00012b58
/*    12b30:	02204025 */ 	or	$t0,$s1,$zero
/*    12b34:	90ef0000 */ 	lbu	$t7,0x0($a3)
/*    12b38:	0012c082 */ 	srl	$t8,$s2,0x2
/*    12b3c:	0058082b */ 	sltu	$at,$v0,$t8
/*    12b40:	10cf0003 */ 	beq	$a2,$t7,.L00012b50
/*    12b44:	00000000 */ 	nop
/*    12b48:	14200003 */ 	bnez	$at,.L00012b58
/*    12b4c:	00000000 */ 	nop
.L00012b50:
/*    12b50:	1605ffea */ 	bne	$s0,$a1,.L00012afc
/*    12b54:	26310008 */ 	addiu	$s1,$s1,0x8
.L00012b58:
/*    12b58:	55000027 */ 	bnezl	$t0,.L00012bf8
/*    12b5c:	8d030000 */ 	lw	$v1,0x0($t0)
/*    12b60:	8e390004 */ 	lw	$t9,0x4($s1)
/*    12b64:	00008025 */ 	or	$s0,$zero,$zero
/*    12b68:	24140008 */ 	addiu	$s4,$zero,0x8
/*    12b6c:	0332082b */ 	sltu	$at,$t9,$s2
/*    12b70:	10200006 */ 	beqz	$at,.L00012b8c
/*    12b74:	3c13800a */ 	lui	$s3,%hi(g_MemaHeap)
/*    12b78:	8e29000c */ 	lw	$t1,0xc($s1)
.L00012b7c:
/*    12b7c:	26310008 */ 	addiu	$s1,$s1,0x8
/*    12b80:	0132082b */ 	sltu	$at,$t1,$s2
/*    12b84:	5420fffd */ 	bnezl	$at,.L00012b7c
/*    12b88:	8e29000c */ 	lw	$t1,0xc($s1)
.L00012b8c:
/*    12b8c:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*    12b90:	26739478 */ 	addiu	$s3,$s3,%lo(g_MemaHeap)
/*    12b94:	56aa0017 */ 	bnel	$s5,$t2,.L00012bf4
/*    12b98:	02204025 */ 	or	$t0,$s1,$zero
/*    12b9c:	3c11800a */ 	lui	$s1,%hi(g_MemaHeap+0xc)
/*    12ba0:	26319484 */ 	addiu	$s1,$s1,%lo(g_MemaHeap+0xc)
.L00012ba4:
/*    12ba4:	0c0049bc */ 	jal	memaDefragPass
/*    12ba8:	02602025 */ 	or	$a0,$s3,$zero
/*    12bac:	26100001 */ 	addiu	$s0,$s0,0x1
/*    12bb0:	1614fffc */ 	bne	$s0,$s4,.L00012ba4
/*    12bb4:	00000000 */ 	nop
/*    12bb8:	8e6b0010 */ 	lw	$t3,0x10($s3)
/*    12bbc:	0172082b */ 	sltu	$at,$t3,$s2
/*    12bc0:	50200007 */ 	beqzl	$at,.L00012be0
/*    12bc4:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*    12bc8:	8e2c000c */ 	lw	$t4,0xc($s1)
.L00012bcc:
/*    12bcc:	26310008 */ 	addiu	$s1,$s1,0x8
/*    12bd0:	0192082b */ 	sltu	$at,$t4,$s2
/*    12bd4:	5420fffd */ 	bnezl	$at,.L00012bcc
/*    12bd8:	8e2c000c */ 	lw	$t4,0xc($s1)
/*    12bdc:	8e2d0000 */ 	lw	$t5,0x0($s1)
.L00012be0:
/*    12be0:	56ad0004 */ 	bnel	$s5,$t5,.L00012bf4
/*    12be4:	02204025 */ 	or	$t0,$s1,$zero
/*    12be8:	1000000b */ 	b	.L00012c18
/*    12bec:	00001025 */ 	or	$v0,$zero,$zero
/*    12bf0:	02204025 */ 	or	$t0,$s1,$zero
.L00012bf4:
/*    12bf4:	8d030000 */ 	lw	$v1,0x0($t0)
.L00012bf8:
/*    12bf8:	8d0f0004 */ 	lw	$t7,0x4($t0)
/*    12bfc:	00727021 */ 	addu	$t6,$v1,$s2
/*    12c00:	01f2c023 */ 	subu	$t8,$t7,$s2
/*    12c04:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*    12c08:	17000002 */ 	bnez	$t8,.L00012c14
/*    12c0c:	ad180004 */ 	sw	$t8,0x4($t0)
/*    12c10:	ad000000 */ 	sw	$zero,0x0($t0)
.L00012c14:
/*    12c14:	00601025 */ 	or	$v0,$v1,$zero
.L00012c18:
/*    12c18:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    12c1c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    12c20:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    12c24:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    12c28:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    12c2c:	8fb40024 */ 	lw	$s4,0x24($sp)
/*    12c30:	8fb50028 */ 	lw	$s5,0x28($sp)
/*    12c34:	03e00008 */ 	jr	$ra
/*    12c38:	27bd0030 */ 	addiu	$sp,$sp,0x30
);
#else
GLOBAL_ASM(
glabel memaAlloc
/*    13324:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    13328:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    1332c:	afb10018 */ 	sw	$s1,0x18($sp)
/*    13330:	00809025 */ 	or	$s2,$a0,$zero
/*    13334:	afb50028 */ 	sw	$s5,0x28($sp)
/*    13338:	afb00014 */ 	sw	$s0,0x14($sp)
/*    1333c:	3c11800a */ 	lui	$s1,0x800a
/*    13340:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    13344:	afb40024 */ 	sw	$s4,0x24($sp)
/*    13348:	afb30020 */ 	sw	$s3,0x20($sp)
/*    1334c:	2631c404 */ 	addiu	$s1,$s1,-15356
/*    13350:	2404ffff */ 	addiu	$a0,$zero,-1
/*    13354:	00002825 */ 	or	$a1,$zero,$zero
/*    13358:	00008025 */ 	or	$s0,$zero,$zero
/*    1335c:	2415ffff */ 	addiu	$s5,$zero,-1
/*    13360:	24060010 */ 	addiu	$a2,$zero,0x10
.NB00013364:
/*    13364:	8e230004 */ 	lw	$v1,0x4($s1)
/*    13368:	26100001 */ 	addiu	$s0,$s0,0x1
/*    1336c:	0072082b */ 	sltu	$at,$v1,$s2
/*    13370:	1420000e */ 	bnez	$at,.NB000133ac
/*    13374:	00721023 */ 	subu	$v0,$v1,$s2
/*    13378:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*    1337c:	0044082b */ 	sltu	$at,$v0,$a0
/*    13380:	00127882 */ 	srl	$t7,$s2,0x2
/*    13384:	12ae000b */ 	beq	$s5,$t6,.NB000133b4
/*    13388:	00000000 */ 	sll	$zero,$zero,0x0
/*    1338c:	10200007 */ 	beqz	$at,.NB000133ac
/*    13390:	2c410040 */ 	sltiu	$at,$v0,0x40
/*    13394:	00402025 */ 	or	$a0,$v0,$zero
/*    13398:	14200006 */ 	bnez	$at,.NB000133b4
/*    1339c:	02202825 */ 	or	$a1,$s1,$zero
/*    133a0:	004f082b */ 	sltu	$at,$v0,$t7
/*    133a4:	14200003 */ 	bnez	$at,.NB000133b4
/*    133a8:	00000000 */ 	sll	$zero,$zero,0x0
.NB000133ac:
/*    133ac:	1606ffed */ 	bne	$s0,$a2,.NB00013364
/*    133b0:	26310008 */ 	addiu	$s1,$s1,0x8
.NB000133b4:
/*    133b4:	54a00027 */ 	bnezl	$a1,.NB00013454
/*    133b8:	8ca30000 */ 	lw	$v1,0x0($a1)
/*    133bc:	8e380004 */ 	lw	$t8,0x4($s1)
/*    133c0:	00008025 */ 	or	$s0,$zero,$zero
/*    133c4:	24140008 */ 	addiu	$s4,$zero,0x8
/*    133c8:	0312082b */ 	sltu	$at,$t8,$s2
/*    133cc:	10200006 */ 	beqz	$at,.NB000133e8
/*    133d0:	3c13800a */ 	lui	$s3,0x800a
/*    133d4:	8e39000c */ 	lw	$t9,0xc($s1)
.NB000133d8:
/*    133d8:	26310008 */ 	addiu	$s1,$s1,0x8
/*    133dc:	0332082b */ 	sltu	$at,$t9,$s2
/*    133e0:	5420fffd */ 	bnezl	$at,.NB000133d8
/*    133e4:	8e39000c */ 	lw	$t9,0xc($s1)
.NB000133e8:
/*    133e8:	8e280000 */ 	lw	$t0,0x0($s1)
/*    133ec:	2673c3f8 */ 	addiu	$s3,$s3,-15368
/*    133f0:	56a80017 */ 	bnel	$s5,$t0,.NB00013450
/*    133f4:	02202825 */ 	or	$a1,$s1,$zero
/*    133f8:	3c11800a */ 	lui	$s1,0x800a
/*    133fc:	2631c404 */ 	addiu	$s1,$s1,-15356
.NB00013400:
/*    13400:	0c004b24 */ 	jal	memaDefragPass
/*    13404:	02602025 */ 	or	$a0,$s3,$zero
/*    13408:	26100001 */ 	addiu	$s0,$s0,0x1
/*    1340c:	1614fffc */ 	bne	$s0,$s4,.NB00013400
/*    13410:	00000000 */ 	sll	$zero,$zero,0x0
/*    13414:	8e690010 */ 	lw	$t1,0x10($s3)
/*    13418:	0132082b */ 	sltu	$at,$t1,$s2
/*    1341c:	50200007 */ 	beqzl	$at,.NB0001343c
/*    13420:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*    13424:	8e2a000c */ 	lw	$t2,0xc($s1)
.NB00013428:
/*    13428:	26310008 */ 	addiu	$s1,$s1,0x8
/*    1342c:	0152082b */ 	sltu	$at,$t2,$s2
/*    13430:	5420fffd */ 	bnezl	$at,.NB00013428
/*    13434:	8e2a000c */ 	lw	$t2,0xc($s1)
/*    13438:	8e2b0000 */ 	lw	$t3,0x0($s1)
.NB0001343c:
/*    1343c:	56ab0004 */ 	bnel	$s5,$t3,.NB00013450
/*    13440:	02202825 */ 	or	$a1,$s1,$zero
/*    13444:	1000000b */ 	beqz	$zero,.NB00013474
/*    13448:	00001025 */ 	or	$v0,$zero,$zero
/*    1344c:	02202825 */ 	or	$a1,$s1,$zero
.NB00013450:
/*    13450:	8ca30000 */ 	lw	$v1,0x0($a1)
.NB00013454:
/*    13454:	8cad0004 */ 	lw	$t5,0x4($a1)
/*    13458:	00726021 */ 	addu	$t4,$v1,$s2
/*    1345c:	01b27023 */ 	subu	$t6,$t5,$s2
/*    13460:	acac0000 */ 	sw	$t4,0x0($a1)
/*    13464:	15c00002 */ 	bnez	$t6,.NB00013470
/*    13468:	acae0004 */ 	sw	$t6,0x4($a1)
/*    1346c:	aca00000 */ 	sw	$zero,0x0($a1)
.NB00013470:
/*    13470:	00601025 */ 	or	$v0,$v1,$zero
.NB00013474:
/*    13474:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    13478:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    1347c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    13480:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    13484:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    13488:	8fb40024 */ 	lw	$s4,0x24($sp)
/*    1348c:	8fb50028 */ 	lw	$s5,0x28($sp)
/*    13490:	03e00008 */ 	jr	$ra
/*    13494:	27bd0030 */ 	addiu	$sp,$sp,0x30
);
#endif

//void *memaAlloc(u32 size)
//{
//	u32 addr;
//	u32 diff;
//	s32 i;
//
//	struct memaspace *curr = &g_MemaHeap.spaces[0];
//	u32 bestdiff = 0xffffffff;
//	struct memaspace *best = NULL;
//
//	// Iterate up to the first 16 spaces, looking for the
//	// smallest space that will accommodate the requested size.
//	for (i = 0; i < 16; i++) {
//		if (curr->size >= size) {
//			if (curr->addr == 0xffffffff) {
//				// Reached the end
//				break;
//			}
//
//			diff = curr->size - size;
//
//			if (diff < bestdiff) {
//				bestdiff = diff;
//				best = curr;
//
//				// Stop looking if the space is small enough
//#if VERSION >= VERSION_NTSC_1_0
//				if (diff < 64 || (IS8MB() && diff < size / 4))
//#else
//				if (diff < 64 || diff < size / 4)
//#endif
//				{
//					break;
//				}
//			}
//		}
//
//		curr++;
//	}
//
//	if (best == NULL) {
//		// Keep iterating until we find a space that is big enough to fit.
//		// The last space is marked as size 0xffffffff which prevents this loop
//		// from iterating past the end of the spaces array.
//		while (curr->size < size) {
//			curr++;
//		}
//
//		if (curr->addr == 0xffffffff) {
//			// There was no space, so attempt to free up some space
//			// by doing several defrag passes
//			for (i = 0; i < 8; i++) {
//				memaDefragPass(&g_MemaHeap);
//			}
//
//			curr = &g_MemaHeap.spaces[0];
//
//			while (curr->size < size) {
//				curr++;
//			}
//
//			if (curr->addr == 0xffffffff) {
//				return NULL;
//			}
//		}
//
//		best = curr;
//	}
//
//	addr = best->addr;
//	best->addr += size;
//	best->size -= size;
//
//	if (best->size == 0) {
//		best->addr = 0;
//	}
//
//	return (void *)addr;
//}

GLOBAL_ASM(
glabel func00012c3c
/*    12c3c:	3c0f800a */ 	lui	$t7,%hi(g_MemaHeap+0xc)
/*    12c40:	8def9484 */ 	lw	$t7,%lo(g_MemaHeap+0xc)($t7)
/*    12c44:	3c0e800a */ 	lui	$t6,%hi(g_MemaHeap+0xc)
/*    12c48:	2407ffff */ 	addiu	$a3,$zero,-1
/*    12c4c:	25ce9484 */ 	addiu	$t6,$t6,%lo(g_MemaHeap+0xc)
/*    12c50:	00a03025 */ 	or	$a2,$a1,$zero
/*    12c54:	10ef000c */ 	beq	$a3,$t7,.L00012c88
/*    12c58:	01c01025 */ 	or	$v0,$t6,$zero
/*    12c5c:	8dc30000 */ 	lw	$v1,0x0($t6)
.L00012c60:
/*    12c60:	54830006 */ 	bnel	$a0,$v1,.L00012c7c
/*    12c64:	8c430008 */ 	lw	$v1,0x8($v0)
/*    12c68:	8c450004 */ 	lw	$a1,0x4($v0)
/*    12c6c:	00a6082b */ 	sltu	$at,$a1,$a2
/*    12c70:	50200008 */ 	beqzl	$at,.L00012c94
/*    12c74:	0066c021 */ 	addu	$t8,$v1,$a2
/*    12c78:	8c430008 */ 	lw	$v1,0x8($v0)
.L00012c7c:
/*    12c7c:	24420008 */ 	addiu	$v0,$v0,0x8
/*    12c80:	14e3fff7 */ 	bne	$a3,$v1,.L00012c60
/*    12c84:	00000000 */ 	nop
.L00012c88:
/*    12c88:	03e00008 */ 	jr	$ra
/*    12c8c:	00001025 */ 	or	$v0,$zero,$zero
/*    12c90:	0066c021 */ 	addu	$t8,$v1,$a2
.L00012c94:
/*    12c94:	00a6c823 */ 	subu	$t9,$a1,$a2
/*    12c98:	ac580000 */ 	sw	$t8,0x0($v0)
/*    12c9c:	17200002 */ 	bnez	$t9,.L00012ca8
/*    12ca0:	ac590004 */ 	sw	$t9,0x4($v0)
/*    12ca4:	ac400000 */ 	sw	$zero,0x0($v0)
.L00012ca8:
/*    12ca8:	00801025 */ 	or	$v0,$a0,$zero
/*    12cac:	03e00008 */ 	jr	$ra
/*    12cb0:	00000000 */ 	nop
);

void memaFree(void *addr, s32 size)
{
	_memaFree((u32)addr, size);
}

void mema00012cd4(void)
{
	// empty
}

/**
 * Find and return the largest amount of contiguous free space in the pool.
 * ie. the biggest allocation that mema can currently make.
 */
s32 memaGetLongestFree(void)
{
	struct memaspace *curr;
	s32 biggest = 0;

	memaDefrag();

	curr = &g_MemaHeap.spaces[1];

	while (curr->addr != -1) {
		if (curr->size > biggest) {
			biggest = curr->size;
		}

		curr++;
	}

	if (biggest) {
		return biggest;
	}

	return 0;
}

GLOBAL_ASM(
glabel func00012d48
/*    12d48:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    12d4c:	00a6082b */ 	sltu	$at,$a1,$a2
/*    12d50:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    12d54:	afa40018 */ 	sw	$a0,0x18($sp)
/*    12d58:	10200008 */ 	beqz	$at,.L00012d7c
/*    12d5c:	00a03825 */ 	or	$a3,$a1,$zero
/*    12d60:	00852021 */ 	addu	$a0,$a0,$a1
/*    12d64:	0c004b0f */ 	jal	func00012c3c
/*    12d68:	00c52823 */ 	subu	$a1,$a2,$a1
/*    12d6c:	5440000a */ 	bnezl	$v0,.L00012d98
/*    12d70:	24020001 */ 	addiu	$v0,$zero,0x1
/*    12d74:	10000008 */ 	b	.L00012d98
/*    12d78:	00001025 */ 	or	$v0,$zero,$zero
.L00012d7c:
/*    12d7c:	00c7082b */ 	sltu	$at,$a2,$a3
/*    12d80:	10200004 */ 	beqz	$at,.L00012d94
/*    12d84:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    12d88:	01e62021 */ 	addu	$a0,$t7,$a2
/*    12d8c:	0c004b2d */ 	jal	memaFree
/*    12d90:	00e62823 */ 	subu	$a1,$a3,$a2
.L00012d94:
/*    12d94:	24020001 */ 	addiu	$v0,$zero,0x1
.L00012d98:
/*    12d98:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    12d9c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    12da0:	03e00008 */ 	jr	$ra
/*    12da4:	00000000 */ 	nop
/*    12da8:	3c02800a */ 	lui	$v0,%hi(g_MemaHeapSize)
/*    12dac:	03e00008 */ 	jr	$ra
/*    12db0:	8c429474 */ 	lw	$v0,%lo(g_MemaHeapSize)($v0)
);
