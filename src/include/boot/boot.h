#ifndef _IN_BOOT_H
#define _IN_BOOT_H
#include <ultra64.h>

s32 func000010a4(void);
s32 func0000113c(void);
s32 func00001180(void);
s32 osGetMemSize(void);
void *func000018ac(s32 arg0, s32 arg1);
void func00001b28(u32 arg0);
s32 func00001e30(void);
s32 func00001fa8(void);
s32 func00002078(void);
s32 func00002148(void);
s32 func00002148(void);
s32 func000022e0(void);
void resetThreadInit(void *data);
void osMapTLBRdb(void);

#endif
