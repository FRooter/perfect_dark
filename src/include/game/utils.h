#ifndef IN_GAME_UTILS_H
#define IN_GAME_UTILS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 align4(u32 arg0);
u32 align16(u32 arg0);
u32 align32(u32 arg0);
void utils_init(void);
void func0f1770ac(struct coord *a, struct coord *b, struct coord *out);
bool func0f177164(struct coord *arg0, struct coord *arg1, u32 line, char *file);
bool func0f1773c8(struct coord *a, struct coord *b);
f32 coords_get_distance(struct coord *a, struct coord *b);
void utils_reset(void);
s32 func0f177a54(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3);
s32 func0f177c8c(u8 *arg0, s32 *arg1, s32 *roomnum);

#endif
