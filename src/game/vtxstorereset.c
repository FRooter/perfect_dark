#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

void vtxstore_reset(void)
{
	s32 i;
	s32 j;
	s32 num;
	s32 val;

	for (i = 0; i < ARRAYCOUNT(g_VtxstoreTypes); i++) {
		if (PLAYERCOUNT() >= 2) {
			val = g_VtxstoreTypes[i].valifmp;
			num = g_VtxstoreTypes[i].numifmp;
		} else if (g_Vars.stagenum >= STAGE_TITLE) {
			val = g_VtxstoreTypes[i].valifspecial;
			num = g_VtxstoreTypes[i].numifspecial;
		} else {
			val = g_VtxstoreTypes[i].valifsp;
			num = g_VtxstoreTypes[i].numifsp;
		}

		if (num > 0) {
			g_VtxstoreTypes[i].unk24 = memp_alloc(num * sizeof(struct var8007e3d0_data), MEMPOOL_STAGE);
		}

		for (j = 0; j < num; j++) {
			g_VtxstoreTypes[i].unk24[j].unk0e = 0;
		}

		g_VtxstoreTypes[i].numallocated = num;
		g_VtxstoreTypes[i].val1 = val;
		g_VtxstoreTypes[i].val2 = val;
	}
}
