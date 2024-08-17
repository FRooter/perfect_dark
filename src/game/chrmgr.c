#include <ultra64.h>
#include "constants.h"
#include "game/game_00b820.h"
#include "game/title.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

void chrmgr_reset(void)
{
	s32 i;

	var80062968 = 1;
	var8006296c = 0;
	g_SelectedAnimNum = 0;
	var80062974 = 0;
	var80062978 = 0;
	var8006297c = 0;
	g_NextChrnum = 5000;
	g_ChrSlots = NULL;
	g_NumChrSlots = 0;

	g_ShieldHits = memp_alloc(sizeof(struct shieldhit) * 20, MEMPOOL_STAGE);

	for (i = 0; i < 20; i++) {
		g_ShieldHits[i].prop = NULL;
	}

	g_ShieldHitActive = 0;
	g_NumChrs = 0;
	g_Chrnums = NULL;
	g_ChrIndexes = NULL;
	var80062960 = memp_alloc(ALIGN16(15 * sizeof(struct var80062960)), MEMPOOL_STAGE);

	for (i = 0; i < ARRAYCOUNT(var8009ccc0); i++) {
		var8009ccc0[i] = (void *)ALIGN64(memp_alloc(16 * 16 * sizeof(u16) + 0x40, MEMPOOL_STAGE));
	}

	reset_some_stage_things();
}

void chrmgr_configure(s32 numchrs)
{
	s32 i;

	g_NumChrSlots = PLAYERCOUNT() + numchrs + 10;
	g_ChrSlots = memp_alloc(ALIGN16(g_NumChrSlots * sizeof(struct chrdata)), MEMPOOL_STAGE);

	for (i = 0; i < g_NumChrSlots; i++) {
		g_ChrSlots[i].chrnum = -1;
		g_ChrSlots[i].model = NULL;
		g_ChrSlots[i].prop = NULL;
	}

	g_NumChrs = 0;
	g_Chrnums = memp_alloc(ALIGN16(g_NumChrSlots * sizeof(g_Chrnums[0])), MEMPOOL_STAGE);
	g_ChrIndexes = memp_alloc(ALIGN16(g_NumChrSlots * sizeof(g_ChrIndexes[0])), MEMPOOL_STAGE);

	for (i = 0; i < g_NumChrSlots; i++) {
		g_Chrnums[i] = -1;
		g_ChrIndexes[i] = -1;
	}
}
