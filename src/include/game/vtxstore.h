#ifndef _IN_GAME_GAME_129210_H
#define _IN_GAME_GAME_129210_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void vtxstore_reset(void);

void vtxstore_fix_refs(void *find, void *replacement);
void vtxstore_tick(void);
void *vtxstore_allocate(s32 count, s32 index, struct modelnode *node, s32 level);
void vtxstore_free(s32 type, void *arg1);

#endif
