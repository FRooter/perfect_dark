#ifndef _IN_GAME_GAME_0D7070_H
#define _IN_GAME_GAME_0D7070_H
#include <ultra64.h>
#include "types.h"

bool func0f0d7070(struct prop *prop);
bool func0f0d716c(struct prop *prop, s32 arg1);
bool func0f0d7240(struct prop *prop);
s32 func0f0d7328(s32 arg0);
void func0f0d7364(void);
void func0f0d7390(s32 arg0);
s32 func0f0d789c(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
u32 func0f0d78f4(void);
u32 func0f0d7f54(void);
u32 func0f0d87a8(void);
Gfx *sightRenderDefault(Gfx *gdl, bool arg1);
Gfx *sightRenderClassic(Gfx *gdl, bool arg1);
Gfx *sightRenderType2(Gfx *gdl, bool arg1);
u32 func0f0d9948(void);
Gfx *sightRenderSkedar(Gfx *gdl, bool arg1);
Gfx *sightRenderZoom(Gfx *gdl, bool arg1);
Gfx *sightRenderMaian(Gfx *gdl, bool arg1);
Gfx *sightRenderTarget(Gfx *gdl);
bool func0f0dca28(s32 sight);
Gfx *sightRender(Gfx *gdl, bool arg1, s32 sight);

#endif
