#ifndef _IN_DATA_H
#define _IN_DATA_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern u8 *g_StackStartAddrs[7];
extern u8 *g_StackEndAddrs[7];
extern u8 *g_StackAllocatedPos;
extern u32 var8005ce60;
extern u32 var8005ce64;
extern u32 var8005ce68;
extern u32 var8005ce6c;
extern u32 var8005ce70;
extern s32 var8005ce74;
extern f32 var8005ce78[2];
extern f32 var8005ce80[2];
extern u32 var8005ce88[2];
extern s32 var8005ce90;
extern u32 var8005ce94;
extern u32 var8005ce98;
extern u32 var8005ce9c;
extern OSMesg var8005cea8;
extern u32 var8005cec8;
extern s8 var8005ced0;
extern u32 __osViDevMgr;
extern u32 var8005cefc;
extern OSDevMgr __osPiDevMgr;
extern u32 __osCurrentHandle;
extern u32 var8005cf30;
extern OSTime osClockRate;
extern s32 osViClock;
extern u32 var8005cf6c;
extern u32 __osGlobalIntMask;
extern u32 var8005cf84;
extern u8 g_LoadState;
extern s32 var8005d9d0;
extern s32 var8005dd18;
extern u32 var8005dd58;
extern bool g_Silent;
extern u16 g_SfxVolume;
extern u32 g_SoundMode;
extern s32 var8005ddd4;
extern struct audiorussmapping g_AudioRussMappings[];
extern struct audioconfig g_AudioConfigs[];
extern u32 var8005eedc;
extern u32 var8005ef10;
extern u32 var8005ef20;
extern s32 g_NumGlobalAilists;
extern s32 g_NumLvAilists;
extern u32 var8005ef40;
extern u32 var8005ef5c;
extern u32 var8005ef7c;
extern u32 var8005ef90;
extern u32 var8005efb4;
extern u32 var8005efb8;
extern bool var8005efbc;
extern u32 var8005efc0;
extern void *var8005efc4;
extern void *var8005efc8;
extern u32 var8005efcc;
extern u32 var8005efd0;
extern u32 var8005efdc;
extern u32 var8005efe0;
extern u32 var8005efec;
extern u32 var8005eff8;
extern u32 var8005f000;
extern u32 var8005f004;
extern s16 g_NumAnimations;
extern struct animheader *g_Anims;
extern u32 var8005f010;
extern u32 var8005f014;
extern u32 var8005f018;
extern u32 var8005f01c;
extern u32 var8005f020;
extern u32 var8005f024;
extern u32 var8005f030;
extern u32 var8005f034;
extern u32 var8005f038;
extern u16 *var8005f040;
extern u16 *var8005f044;
extern u32 var8005f048;
extern u32 var8005f0a8;
extern u32 var8005f108;
extern u32 var8005f110;
extern u32 var8005f114;
extern u32 var8005f120;
extern u32 var8005f124;
extern u32 var8005f128;
extern u32 var8005f12c;
extern u32 var8005f130;
extern u32 var8005f134;
extern u32 var8005f138;
extern u32 var8005f13c;
extern u32 var8005f140;
extern u32 var8005f150;
extern u32 var8005f34c;
extern u32 var8005f4dc;
extern u32 var8005f548;
extern u32 var8005f570;
extern u32 var8005f66c;
extern u32 var8005f670;
extern u32 var8005f6f8;
extern u32 var8005f6fc;
extern u32 var8005f704;
extern OSViMode osViModeTable[42];
extern u32 var80060890;
extern OSTimer *__osTimerList;
extern __OSViContext var800608b0[2];
extern __OSViContext *__osViCurr;
extern __OSViContext *__osViNext;
extern u32 __osPiAccessQueueEnabled;
extern u32 __osThreadTail;
extern OSThread *__osRunQueue;
extern OSThread *__osActiveQueue;
extern OSThread *__osRunningThread;
extern OSThread *__osFaultedThread;
extern u32 __osSiAccessQueueEnabled;
extern u32 __osContInitialized;
extern u32 var80060970;
extern u32 var80060980;
extern u8 var80060984;
extern u32 var80060990;
extern u32 var800609a0;
extern u32 var800609c4;
extern u32 var800609f0;
extern u32 var800611ec;
extern u32 var800611f0;
extern u32 var80061220;
extern OSViMode osViModePalLan1;
extern OSViMode osViModeMpalLan1;
extern OSViMode osViModeNtscLan1;
extern char ldigs[];
extern char udigs[];
extern u32 var80061360;
extern u32 var80061380;
extern u32 var800613a0;
extern f32 var80061630;
extern u32 var80061634;
extern bool g_NbombsActive;
extern s32 g_WeatherActive;
extern u32 var80062410;
extern s32 var800624a4;
extern u32 var800624b0;
extern s32 g_TitleMode;
extern s32 g_TitleNextMode;
extern u32 g_TitleDelayedTimer;
extern s32 g_TitleDelayedMode;
extern s32 g_TitleTimer;
extern u32 var800624d4;
extern u32 var800624d8;
extern u32 var800624dc;
extern u32 var800624e0;
extern s32 g_TitleNextStage;
extern u32 var800624e8;
extern u32 var800624ec;
extern u32 var800624f0;
extern u32 var800624f4;
extern u8 g_FileState;
extern u8 var80062944;
extern u8 var80062948;
extern u8 var8006294c;
extern u32 var80062950;
extern bool g_WeatherTickEnabled;
extern void *var80062960;
extern f32 var80062968;
extern bool var8006296c;
extern s32 g_SelectedAnimNum;
extern u32 var80062974;
extern u32 var80062978;
extern u32 var8006297c;
extern s32 g_NextChrnum;
extern struct chrdata *g_ChrSlots;
extern s32 g_NumChrSlots;
extern struct var80062a8c *var80062a8c;
extern s32 var80062a90;
extern s32 g_NumBondBodies;
extern s32 g_NumMaleGuardHeads;
extern s32 g_NumFemaleGuardHeads;
extern s32 g_NumMaleGuardTeamHeads;
extern s32 g_NumFemaleGuardTeamHeads;
extern s32 var80062b14;
extern s32 var80062b18;
extern s32 g_BondBodies[];
extern s32 g_MaleGuardHeads[];
extern s32 g_MaleGuardTeamHeads[];
extern s32 g_FemaleGuardHeads[];
extern s32 g_FemaleGuardTeamHeads[];
extern s32 var80062c80;
extern s32 g_ActiveMaleHeadsIndex;
extern s32 g_ActiveFemaleHeadsIndex;
extern f32 var80062ca0;
extern f32 var80062ca4;
extern f32 var80062ca8;
extern f32 var80062cac;
extern s32 var80062cbc;
extern struct somedruggedracethingdeep var800637cc[];
extern struct somedruggedracething *var800652b8[NUM_RACES];
extern struct animfloats var800656c0[];
extern struct var80065750 *var80065ae0[][32];
extern struct animfloats var80065be0[];
extern struct var80065750 *var800662d8[][32];
extern struct animfloats var800663d8[];
extern u32 var800666c8;
extern struct var80065750 *var80066a70[][32];
extern struct var80065750 *var80066ef0[][32];
extern struct var80065750 *var80067328[][32];
extern struct animfloats var80067428;
extern struct animfloats var80067a10;
extern struct animfloats var80067a58;
extern struct animfloats var80067aa0;
extern struct animfloats var80067ae8;
extern struct animfloats var80067b30;
extern struct animfloats var80067b78;
extern u32 g_StageFlags;
extern struct chrdata *g_BgChrs;
extern s16 *g_BgChrnums;
extern s32 g_NumBgChrs;
extern s16 *g_TeamList;
extern s16 *g_SquadronList;
extern struct var80067e6c *var80067fdc[];
extern s16 var80067ff0[];
extern f32 var80069880;
extern u32 g_TintedGlassEnabled;
extern s32 g_AlarmTimer;
extern struct audiohandle *g_AlarmAudioHandle;
extern f32 g_AlarmSpeakerWeight;
extern f32 var800698e4;
extern s32 var800698e8;
extern f32 var800698ec[3];
extern u32 var800698f8;
extern f32 var800698fc;
extern struct audiohandle *var80069900;
extern u32 g_CountdownTimerVisible;
extern bool g_CountdownTimerRunning;
extern f32 g_CountdownTimerValue;
extern u32 var80069910;
extern u32 var80069914;
extern u32 var80069918;
extern struct linkliftdoorobj *g_LiftDoors;
extern struct padlockeddoorobj *g_PadlockedDoors;
extern struct safeitemobj *g_SafeItems;
extern struct linksceneryobj *g_LinkedScenery;
extern struct blockedpathobj *g_BlockedPaths;
extern u32 var80069930;
extern s32 var80069934;
extern f32 g_CameraWaitMultiplier;
extern f32 var8006994c;
extern f32 var80069950;
extern f32 var80069954;
extern f32 var80069958;
extern f32 g_AmmoMultiplier;
extern struct padeffectobj *var80069960;
extern s32 var80069964;
extern struct autogunobj *g_ThrownLaptops;
extern struct var8006996c *var8006996c;
extern s32 g_MaxThrownLaptops;
extern struct prop *g_Lifts[MAX_LIFTS];
extern u32 var80069d90;
extern u32 var8006aaa0;
extern u32 var8006aae4;
extern struct audiochannel *g_AudioChannels;
extern s8 var8006ae18;
extern s8 var8006ae1c;
extern s8 var8006ae20;
extern s8 var8006ae24;
extern s8 var8006ae28;
extern s32 g_ObjectiveLastIndex;
extern bool g_ObjectiveChecksDisabled;
extern u16 var8006ae90[];
extern u16 var8006af0c[];
extern u16 var8006af8c[];
extern struct inventory_menupos invmenupos_00010fd0;
extern struct inventory_typee inve_000110c0;
extern struct weapon *g_Weapons[];
extern u32 var800700ac;
extern s32 g_CasingsActive;
extern u32 var800705a0;
extern u32 var800705a4;
extern bool var800705a8;
extern u32 var800705ac;
extern u32 var800705b0;
extern u32 var800705b4;
extern u32 var800705b8;
extern u32 var800705bc;
extern s32 g_ViMode;
extern bool g_HiResEnabled;
extern s32 var8007072c;
extern u32 var80070738;
extern u32 var8007073c;
extern struct gecreditsdata *g_CurrentGeCreditsData;
extern u32 var80070744;
extern u32 var80070748;
extern u32 var8007074c;
extern bool g_PlayersWithControl[];
extern bool g_PlayerInvincible;
extern s32 g_InCutscene;
extern s16 g_DeathAnimations[];
extern u32 g_NumDeathAnimations;
extern u32 var80071180;
extern u32 var80071184;
extern s32 g_ScissorX1;
extern s32 g_ScissorX2;
extern s32 g_ScissorY1;
extern s32 g_ScissorY2;
extern u32 var800711f0;
extern char *g_StringPointer;
extern char *g_StringPointer2;
extern s32 g_MpPlayerNum;
extern u32 var800714d8;
extern u16 g_ControlStyleOptions[];
extern struct menudialog g_PreAndPostMissionBriefingMenuDialog;
extern struct stageoverviewentry g_StageNames[NUM_SOLOSTAGES];
extern struct mission missions[];
extern struct menudialog g_SoloMissionControlStyleMenuDialog;
extern struct menudialog g_CiControlStyleMenuDialog;
extern struct menudialog g_CiControlStylePlayer2MenuDialog;
extern struct menudialog g_ChangeAgentMenuDialog;
extern struct menudialog g_2PMissionOptionsHMenuDialog;
extern struct menudialog g_2PMissionOptionsVMenuDialog;
extern struct menudialog g_FrWeaponsAvailableMenuDialog;
extern struct menudialog g_SoloMissionPauseMenuDialog;
extern struct menudialog g_2PMissionPauseHMenuDialog;
extern struct menudialog g_2PMissionPauseVMenuDialog;
extern struct cutscene g_Cutscenes[];
extern struct menudialog g_CiMenuViaPcMenuDialog;
extern struct menudialog g_CiMenuViaPauseMenuDialog;
extern struct menudialog g_CheatsMenuDialog;
extern struct menudialog g_PakChoosePakMenuDialog;
extern struct menudialog g_FilemgrFileSelect4MbMenuDialog;
extern struct menudialog g_MpQuickGo4MbMenuDialog;
extern struct menudialog g_MpConfirmChallenge4MbMenuDialog;
extern struct menudialog g_MainMenu4MbMenuDialog;
extern struct menudialog g_MpEditSimulant4MbMenuDialog;
extern struct menudialog g_AdvancedSetup4MbMenuDialog;
extern struct filelist *g_FileLists[];
extern bool var80075bd0[];
extern struct var80075c00 var80075c00[];
extern s32 var80075d60;
extern u32 var80075d64;
extern u32 var80075d68;
extern s32 var80075d78;
extern u8 unregistered_function1[];
extern u8 unregistered_function2[];
extern u8 unregistered_function3[];
extern struct ailist g_GlobalAilists[];
extern struct stagethinglist stagethinglist_20e10;
extern struct stagethinglist stagethinglist_20e3c;
extern struct stagethinglist stagethinglist_20e48;
extern struct stagethinglist stagethinglist_20e54;
extern struct stagethinglist stagethinglist_20e60;
extern struct stagethinglist stagethinglist_20e6c;
extern struct stagethinglist stagethinglist_20e80;
extern struct stagethinglist stagethinglist_20e94;
extern struct stagethinglist stagethinglist_20ea4;
extern struct stagethinglist stagethinglist_20ec8;
extern struct stagethinglist stagethinglist_20edc;
extern struct stagethinglist stagethinglist_20eec;
extern struct stagethinglist stagethinglist_20ef8;
extern struct stagethinglist stagethinglist_20f0c;
extern struct stagethinglist stagethinglist_20f18;
extern struct stagethinglist stagethinglist_20f24;
extern struct stagethinglist stagethinglist_20f50;
extern struct stagethinglist stagethinglist_20f5c;
extern struct stagethinglist stagethinglist_20f74;
extern struct stagethinglist stagethinglist_20f84;
extern struct stagethinglist stagethinglist_20fb8;
extern struct stagethinglist stagethinglist_20fd8;
extern struct stagethinglist stagethinglist_20fe8;
extern struct stagethinglist stagethinglist_20ff8;
extern struct stagethinglist stagethinglist_2100c;
extern struct stagethinglist stagethinglist_21018;
extern struct stagethinglist stagethinglist_21024;
extern struct stagethinglist stagethinglist_21034;
extern struct stagethinglist stagethinglist_21084;
extern struct modelstate g_ModelStates[441];
extern u8 propexplosiontypes[];
extern struct stagethinglist stagethinglist_2208c;
extern struct stagethinglist stagethinglist_220a4;
extern struct stagethinglist stagethinglist_220d0;
extern u32 var8007c0c0;
extern struct stagethinglist stagethinglist_221a4;
extern struct stagethinglist stagethinglist_221b4;
extern struct stagethinglist stagethinglist_221cc;
extern struct stagethinglist stagethinglist_221e4;
extern struct stagethinglist stagethinglist_22200;
extern struct stagethinglist stagethinglist_22220;
extern struct stagethinglist stagethinglist_2224c;
extern struct stagethinglist stagethinglist_222b4;
extern struct stagethinglist stagethinglist_22318;
extern struct stagethinglist stagethinglist_22374;
extern struct stagethinglist stagethinglist_223d4;
extern struct stagethinglist stagethinglist_22424;
extern struct stagethinglist stagethinglist_2247c;
extern struct stagethinglist stagethinglist_224d8;
extern struct stagethinglist stagethinglist_22538;
extern struct stagethinglist stagethinglist_2258c;
extern struct stagethinglist stagethinglist_225d8;
extern struct stagethinglist stagethinglist_22630;
extern struct stagethinglist stagethinglist_22698;
extern struct stagethinglist stagethinglist_226e8;
extern struct stagethinglist stagethinglist_22754;
extern struct stagethinglist stagethinglist_227ac;
extern struct stagethinglist stagethinglist_22804;
extern struct stagethinglist stagethinglist_2285c;
extern struct stagethinglist stagethinglist_228b4;
extern struct stagethinglist stagethinglist_2291c;
extern struct stagethinglist stagethinglist_22970;
extern struct stagethinglist stagethinglist_229c4;
extern struct stagethinglist stagethinglist_22a20;
extern struct stagethinglist stagethinglist_22a78;
extern struct stagethinglist stagethinglist_22adc;
extern struct stagethinglist stagethinglist_22b28;
extern struct stagethinglist stagethinglist_22b80;
extern struct stagethinglist stagethinglist_22be0;
extern struct stagethinglist stagethinglist_22c3c;
extern struct stagethinglist stagethinglist_22c54;
extern struct stagethinglist stagethinglist_22ca0;
extern struct stagethinglist stagethinglist_22cf0;
extern struct stagethinglist stagethinglist_22d40;
extern struct stagethinglist stagethinglist_22d90;
extern struct stagethinglist stagethinglist_22de0;
extern struct stagethinglist stagethinglist_22e34;
extern struct stagethinglist stagethinglist_22e60;
extern struct stagethinglist stagethinglist_22eb8;
extern struct stagethinglist stagethinglist_22ec8;
extern struct stagethinglist stagethinglist_22f0c;
extern struct stagethinglist stagethinglist_22f1c;
extern struct body g_Bodies[];
extern u32 var8007dae4;
extern f32 var8007db80;
extern f32 var8007db84;
extern u32 var8007db88;
extern u32 var8007db94;
extern u32 var8007dba0;
extern u32 var8007dbb8;
extern u32 var8007dbd0;
extern u32 var8007dbe8;
extern u32 var8007dbf4;
extern u32 var8007dc00;
extern struct var8007e3d0 var8007e3d0[];
extern u32 var8007e4a0;
extern u32 var8007e4a4;
extern f32 var8007e4a8;
extern struct sparktype g_SparkTypes[];
extern s32 g_SparksAreActive;
extern struct weatherdata *g_WeatherData;
extern u32 var8007fa80;
extern bool g_ShardsActive;
extern s32 g_ScaleX;
extern struct font *g_FontNumeric2;
extern struct font2a4 *g_FontNumeric1;
extern struct font *g_FontHandelGothicXs2;
extern struct font2a4 *g_FontHandelGothicXs1;
extern struct font *g_FontHandelGothicSm2;
extern struct font2a4 *g_FontHandelGothicSm1;
extern struct font *g_FontHandelGothicMd2;
extern struct font2a4 *g_FontHandelGothicMd1;
extern struct font *g_FontHandelGothicLg2;
extern struct font2a4 *g_FontHandelGothicLg1;
extern u32 var8007fb9c;
extern s32 g_StageIndex;
extern s16 var8007fc0c;
extern u32 var8007fc24;
extern u16 var8007fc3c;
extern s32 g_NumPortalThings;
extern f32 var8007fcb4;
extern struct stagetableentry g_Stages[61];
extern s32 var80082050;
extern u32 g_GfxNumSwaps;
extern s32 g_NumReasonsToEndMpMatch;
extern u32 var800840c4;
extern u32 var800840d8;
extern u32 var800840e0;
extern u32 var800840e4;
extern u32 var800840f0;
extern u32 var800840f4;
extern u32 var800840f8;
extern u32 var800840fc;
extern u32 g_LanguageId;
extern struct something *somethings[];
extern void *var800844f0;
extern f32 var800845d4;
extern u32 var800845dc;
extern struct menudialog g_2PMissionInventoryHMenuDialog;
extern struct menudialog g_2PMissionInventoryVMenuDialog;
extern struct menudialog g_MpEndscreenChallengeCheatedMenuDialog;
extern struct menudialog g_MpEndscreenChallengeFailedMenuDialog;
extern struct menudialog g_MpDropOutMenuDialog;
extern struct mparena g_MpArenas[];
extern struct menudialog g_MpWeaponsMenuDialog;
extern struct menudialog g_MpPlayerOptionsMenuDialog;
extern struct menudialog g_MpControlMenuDialog;
extern struct menudialog g_MpPlayerStatsMenuDialog;
extern struct menudialog g_MpPlayerNameMenuDialog;
extern struct menudialog g_MpLoadSettingsMenuDialog;
extern struct menudialog g_MpLoadPresetMenuDialog;
extern struct menudialog g_MpLoadPlayerMenuDialog;
extern struct menudialog g_MpArenaMenuDialog;
extern struct menudialog g_MpLimitsMenuDialog;
extern struct menudialog g_MpHandicapsMenuDialog;
extern struct menudialog g_MpReadyMenuDialog;
extern struct menudialog g_MpSimulantsMenuDialog;
extern struct menudialog g_MpTeamsMenuDialog;
extern struct menudialog g_MpChallengeListOrDetailsMenuDialog;
extern struct menudialog g_MpChallengeListOrDetailsViaAdvChallengeMenuDialog;
extern struct menudialog g_MpAdvancedSetupMenuDialog;
extern struct menudialog g_MpQuickGoMenuDialog;
extern struct menudialog g_MpQuickTeamGameSetupMenuDialog;
extern struct menudialog g_MpQuickTeamMenuDialog;
extern struct menudialog g_CombatSimulatorMenuDialog;
extern struct menudialog g_MpCombatOptionsMenuDialog;
extern struct menudialog g_MpBriefcaseOptionsMenuDialog;
extern struct menudialog g_MpCaptureOptionsMenuDialog;
extern struct menudialog g_MpHillOptionsMenuDialog;
extern struct menudialog g_MpHackerOptionsMenuDialog;
extern struct menudialog g_MpPopacapOptionsMenuDialog;
extern struct mpscenariooverview g_MpScenarioOverviews[];
extern struct menudialog g_MpScenarioMenuDialog;
extern struct menudialog g_MpQuickTeamScenarioMenuDialog;
extern s32 var80087260;
extern u32 var80087264;
extern struct mpweapon g_MpWeapons[0x27];
extern struct mphead g_MpHeads[75];
extern struct mpsimulanttype g_MpSimulantTypes[];
extern struct mpbody g_MpBodies[NUM_MPBODIES];
extern struct mppreset g_MpPresets[NUM_MPPRESETS];
extern u32 g_TeamColours[];
extern u16 var80087ce4[];
extern u8 g_NumMpSimulantChrs;
extern u32 var80087eb0;
extern u32 var80087eb4;
extern struct challenge g_MpChallenges[NUM_CHALLENGES];
extern u8 g_FrIsValidWeapon;
extern s32 g_FrWeaponNum;
extern u8 g_ChrBioSlot;
extern u8 g_HangarBioSlot;
extern u8 g_DtSlot;
extern u8 var80088bb4;
extern struct menudialog g_FrWeaponListMenuDialog;
extern struct menudialog g_FrTrainingInfoInGameMenuDialog;
extern struct menudialog g_FrTrainingInfoPreGameMenuDialog;
extern struct menudialog g_FrCompletedMenuDialog;
extern struct menudialog g_FrFailedMenuDialog;
extern struct menudialog g_BioListMenuDialog;
extern struct menudialog g_DtListMenuDialog;
extern struct menudialog g_DtDetailsMenuDialog;
extern struct menudialog g_DtFailedMenuDialog;
extern struct menudialog g_DtCompletedMenuDialog;
extern struct menudialog g_HtListMenuDialog;
extern struct menudialog g_HtDetailsMenuDialog;
extern struct menudialog g_HtFailedMenuDialog;
extern struct menudialog g_HtCompletedMenuDialog;
extern struct menudialog g_HangarListMenuDialog;

#endif