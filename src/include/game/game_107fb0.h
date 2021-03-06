#ifndef IN_GAME_GAME_107FB0_H
#define IN_GAME_GAME_107FB0_H
#include <ultra64.h>
#include "types.h"

char *getSaveLocationName(s32 index);
char *pakMenuTextLocationName(struct menu_item *item);
void func0f1080d0(char *dst, u32 ar1, u32 arg2);
char *func0f1082b0(struct menu_item *item);
void func0f108324(s32 arg0);
u32 func0f1083b0(void);
void func0f1083d0(s32 arg0, s32 arg1);
char *pakMenuTextFailReason(struct menu_item *item);
u32 func0f108550(void);
u32 func0f10865c(void);
u32 func0f1086b8(void);
u32 func0f10876c(void);
u32 func0f1088a0(void);
u32 func0f10898c(void);
u32 func0f108a80(void);
u32 func0f108d8c(void);
u32 func0f108f90(void);
void func0f109038(s32 arg0);
u32 func0f1091e0(void);
bool func0f1094e4(bool *saved, s32 arg1, s32 arg2);
u32 pakDeleteFile(void);
u32 func0f1097d0(void);
u32 func0f109954(void);
u32 func0f1099a8(void);
void func0f109a68(char *name);
void func0f109bb4(char *name);
u32 func0f109c8c(void);
void func0f109ec4(void);
u32 func0f10a19c(void);
u32 func0f10a1ec(void);
u32 func0f10a22c(void);
u32 func0f10a2ec(void);
void func0f10a51c(s32 arg0, s32 arg1);
u32 func0f10a5e8(void);
u32 func0f10a630(void);
u32 func0f10a97c(void);
u32 func0f10aad8(void);
void func0f10b0c4(s32 arg0);
u32 func0f10b75c(void);
u32 func0f10b7cc(void);
u32 func0f10b83c(void);
u32 func0f10b924(void);
u32 func0f10c900(void);
void func0f10c970(void);
void menucustomChooseAgent(void);
void menucustomDeleteGameNote(void);
void menucustomFileToCopy(void);
void menucustomFileToDelete(void);
bool menudialog00108e58(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem);
s32 menudialog0010b014(u32, u32, u32 *);
s32 menudialog0010b674(u32, u32, u32 *);
s32 menudialog0010ba10(u32, u32, u32 *);
s32 menudialog0010c804(u32, u32, u32 *);
s32 menuhandler00108014(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler00108254(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler001084b8(u32, u32, u32 *);
s32 menuhandlerPakErrorTryAgain(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerPakCancelSave2(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerAcknowledgePakFileLost(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler00108ecc(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler00108f08(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerPakRenameDuplicateSave(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerPakCancelDuplicateSave(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerPakCancelSave(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerDeleteFiles(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerPakConfirmDelete(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandler0010b14c(u32, u32, u32 *);
s32 menuhandlerPakSelection(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerAgentName(u32 operation, struct menu_item *item, char **value);
s32 menuhandlerOpenCopyFile(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerOpenDeleteFile(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerRenameFile(u32 operation, struct menu_item *item, char **value);
s32 menuhandlerSaveElsewhere(u32, u32, u32 *);
s32 menuhandlerSaveLocation(u32 operation, struct menu_item *item, s32 *value);

extern const char var7f1b3214[];
extern const char var7f1b3218[];
extern const char var7f1b321c[];
extern const char var7f1b3220[];

#endif
