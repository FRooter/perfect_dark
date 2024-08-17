#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

void explosions_reset(void)
{
	s32 i;
	s32 j;

	g_ExplosionShakeTotalTimer = 0;
	g_ExplosionShakeIntensityTimer = 0;
	g_ExplosionDamageTxScale = 1;

	g_MaxExplosions = MAX_EXPLOSIONS;

	if (g_Vars.stagenum >= STAGE_TITLE) {
		g_MaxExplosions = 0;
	}

	if (g_MaxExplosions == 0) {
		g_Explosions = NULL;
	} else {
		g_Explosions = memp_alloc((g_MaxExplosions * sizeof(struct explosion) + 0xf) & ~0xf, MEMPOOL_STAGE);

		for (i = 0; i < g_MaxExplosions; i++) {
			g_Explosions[i].prop = NULL;

			for (j = 0; j < ARRAYCOUNT(g_Explosions[i].parts); j++) {
				g_Explosions[i].parts[j].frame = 0;
			}
		}
	}
}
