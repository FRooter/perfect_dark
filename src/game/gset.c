#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/inv.h"
#include "game/bondgun.h"
#include "game/gset.h"
#include "game/player.h"
#include "game/hudmsg.h"
#include "game/playermgr.h"
#include "game/mplayer/setup.h"
#include "game/botcmd.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "data.h"
#include "types.h"

struct weapondef *gset_get_weapondef(s32 itemid)
{
	if (itemid < 0) {
		return NULL;
	}

	if (itemid >= ARRAYCOUNT(g_Weapons)) {
		return NULL;
	}

	return g_Weapons[itemid];
}

struct funcdef *gset_get_funcdef_by_weaponnum_funcnum(u32 weaponnum, u32 which)
{
	struct weapondef *weapon = gset_get_weapondef(weaponnum);

	if (weapon) {
		return weapon->functions[which];
	}

	return NULL;
}

struct funcdef *gset_get_funcdef_by_gset2(struct gset *gset)
{
	struct weapondef *weapon = gset_get_weapondef(gset->weaponnum);

	if (weapon) {
		return weapon->functions[gset->weaponfunc];
	}

	return NULL;
}

struct funcdef *gset_get_funcdef_by_gset(struct gset *gset)
{
	struct weapondef *weapon = g_Weapons[gset->weaponnum];

	if (weapon) {
		return weapon->functions[gset->weaponfunc];
	}

	return NULL;
}

struct funcdef *gset_get_funcdef_by_gset_funcnum(struct gset *gset, s32 which)
{
	struct weapondef *weapon = g_Weapons[gset->weaponnum];

	if (weapon) {
		return weapon->functions[which];
	}

	return NULL;
}

struct funcdef *gset_get_current_funcdef(u32 hand)
{
	struct weapondef *weapon = gset_get_weapondef(g_Vars.currentplayer->hands[hand].gset.weaponnum);

	if (weapon) {
		return weapon->functions[g_Vars.currentplayer->hands[hand].gset.weaponfunc];
	}

	return NULL;
}

u32 gset_get_num_functions(u32 weaponnum)
{
	struct weapondef *weapon = gset_get_weapondef(weaponnum);
	s32 i;

	if (!weapon) {
		return 0;
	}

	for (i = 0; i < 2; i++) {
		if (weapon->functions[i] == NULL) {
			return i;
		}
	}

	return 2;
}

struct invaimsettings *gset_get_aim_settings(struct gset *gset)
{
	struct weapondef *weapon = gset_get_weapondef(gset->weaponnum);

	if (weapon) {
		return weapon->aimsettings;
	}

	return &invaimsettings_default;
}

struct ammodef *gset_get_ammodef(u32 weaponnum, u32 funcnum)
{
	struct weapondef *weapon = gset_get_weapondef(weaponnum);
	struct funcdef *func = gset_get_funcdef_by_weaponnum_funcnum(weaponnum, funcnum);

	if (func && weapon && func->ammoindex >= 0) {
		return weapon->ammos[func->ammoindex];
	}

	return NULL;
}

void gset_get_weapon_pos(struct coord *pos)
{
	struct weapondef *weapon = gset_get_weapondef(bgun_get_weapon_num(HAND_RIGHT));

	if (weapon) {
		pos->x = weapon->posx;
		pos->y = weapon->posy;
		pos->z = weapon->posz;
	}
}

void gset_set_weapon_pos(struct coord *pos)
{
	struct weapondef *weapon = gset_get_weapondef(bgun_get_weapon_num(HAND_RIGHT));

	if (weapon) {
		weapon->posx = pos->x;
		weapon->posy = pos->y;
		weapon->posz = pos->z;
	}
}

f32 gset_get_xshift(s32 handnum)
{
	return g_Vars.currentplayer->hands[handnum].xshift;
}

f32 gset_get_xpos(s32 hand)
{
	f32 x;
	struct weapondef *weapon;

	if (hand == 0) {
		weapon = gset_get_weapondef(bgun_get_weapon_num2(0));
		x = weapon->posx;

		if (PLAYERCOUNT() == 2 && options_get_screen_split() == SCREENSPLIT_VERTICAL) {
			x -= 3.5f;

			if (g_Vars.currentplayernum == 0) {
				x += 2.0f;
			}
		}
	} else {
		weapon = gset_get_weapondef(bgun_get_weapon_num2(1));
		x = -weapon->posx;

		if (PLAYERCOUNT() == 2 && options_get_screen_split() == SCREENSPLIT_VERTICAL) {
			x += 3.5f;

			if (g_Vars.currentplayernum == 0) {
				x += 2.0f;
			}
		}
	}

	return x;
}

f32 gset_get_gun_zoom_fov(void)
{
	s32 index = -1;
	struct weapondef *weapon;

	switch (bgun_get_weapon_num2(0)) {
	case WEAPON_SNIPERRIFLE:
		index = 0;
		break;
	case WEAPON_FARSIGHT:
		index = 1;
		break;
	case WEAPON_HORIZONSCANNER:
		index = 2;
		break;
	}

	if (index >= 0) {
		return g_Vars.currentplayer->gunzoomfovs[index];
	}

	weapon = gset_get_weapondef(bgun_get_weapon_num2(0));

	if (weapon) {
		f32 fov = weapon->aimsettings->zoomfov;
		return fov;
	}

	return 0;
}

void gset_zoom_out(f32 fovpersec)
{
	s32 index = -1;

	switch (bgun_get_weapon_num2(0)) {
	case WEAPON_SNIPERRIFLE:
		index = 0;
		break;
	case WEAPON_FARSIGHT:
		index = 1;
		break;
	case WEAPON_HORIZONSCANNER:
		index = 2;
		break;
	}

	if (index >= 0) {
		f32 amount = fovpersec * 0.25f * LVUPDATE60FREAL();

		if (bgun_get_weapon_num2(0) == WEAPON_FARSIGHT) {
			amount *= 0.5f;
		}

		g_Vars.currentplayer->gunzoomfovs[index] *= 1.0f + amount * 0.1f;

		if (g_Vars.currentplayer->gunzoomfovs[index] > 60) {
			g_Vars.currentplayer->gunzoomfovs[index] = 60;
		}
	}
}

void gset_zoom_in(f32 fovpersec)
{
	s32 index = -1;

	switch (bgun_get_weapon_num2(0)) {
	case WEAPON_SNIPERRIFLE:
		index = 0;
		break;
	case WEAPON_FARSIGHT:
		index = 1;
		break;
	case WEAPON_HORIZONSCANNER:
		index = 2;
		break;
	}

	if (index >= 0) {
		f32 amount = fovpersec * 0.25f * LVUPDATE60FREAL();

		if (bgun_get_weapon_num2(0) == WEAPON_FARSIGHT) {
			amount *= 0.5f;
		}

		g_Vars.currentplayer->gunzoomfovs[index] /= 1 + amount * 0.1f;

		if (g_Vars.currentplayer->gunzoomfovs[index] < 2) {
			g_Vars.currentplayer->gunzoomfovs[index] = 2;
		}
	}
}

bool gset_has_weapon_flag(s32 itemid, u32 flag)
{
	struct weapondef *weapon = gset_get_weapondef(itemid);

	if (!weapon) {
		return false;
	}

	return (weapon->flags & flag) != 0;
}

bool gset_has_aim_flag(s32 weaponnum, u32 flag)
{
	struct weapondef *weapon = gset_get_weapondef(weaponnum);

	if (!weapon) {
		return false;
	}

	return (weapon->aimsettings->flags & flag) != 0;
}

bool gset_has_ammo_flag(s32 weaponnum, s32 funcnum, u32 flag)
{
	struct weapondef *weapon = gset_get_weapondef(weaponnum);
	struct ammodef *ammo;

	if (weapon == NULL) {
		return false;
	}

	ammo = weapon->ammos[funcnum];

	if (ammo) {
		return (ammo->flags & flag) != 0;
	}

	return false;
}

void gset_stub1(s32 arg0)
{
	// empty
}

void gset_stub2(s32 arg0)
{
	// empty
}

s32 gset_get_device_state(s32 weaponnum)
{
	struct weapondef *weapon = gset_get_weapondef(weaponnum);
	s32 i;

	if (!weapon) {
		return DEVICESTATE_UNEQUIPPED;
	}

	for (i = 0; i < ARRAYCOUNT(weapon->functions); i++) {
		if (weapon->functions[i]) {
			struct funcdef_device *devicefunc = weapon->functions[i];

			if ((devicefunc->base.type & 0xff) == INVENTORYFUNCTYPE_DEVICE) {
				if ((g_Vars.currentplayer->devicesactive & devicefunc->device) == 0) {
					return DEVICESTATE_INACTIVE;
				}

				return DEVICESTATE_ACTIVE;
			}
		}
	}

	return DEVICESTATE_UNEQUIPPED;
}

void gset_set_device_active(s32 weaponnum, bool active)
{
	struct weapondef *weapon = gset_get_weapondef(weaponnum);
	s32 i;

	if (!weapon) {
		return;
	}

	for (i = 0; i < ARRAYCOUNT(weapon->functions); i++) {
		if (weapon->functions[i]) {
			struct funcdef_device *devicefunc = weapon->functions[i];

			if ((devicefunc->base.type & 0xff) == INVENTORYFUNCTYPE_DEVICE) {
				if (active) {
					if (devicefunc->device & (DEVICE_NIGHTVISION | DEVICE_XRAYSCANNER | DEVICE_EYESPY | DEVICE_IRSCANNER)) {
						g_Vars.currentplayer->devicesactive &= ~(DEVICE_NIGHTVISION | DEVICE_XRAYSCANNER | DEVICE_EYESPY | DEVICE_IRSCANNER);
					}

					g_Vars.currentplayer->devicesactive |= devicefunc->device;
				} else {
					g_Vars.currentplayer->devicesactive &= ~devicefunc->device;
				}

				return;
			}
		}
	}
}

u16 gset_get_filenum(s32 weaponnum)
{
	struct weapondef *weapon = NULL;

	if (weaponnum != -1) {
		weapon = g_Weapons[weaponnum];
	}

	if (weapon) {
		if (PLAYERCOUNT() >= 2) {
			return weapon->lo_model;
		}

		return weapon->hi_model;
	}

	return 0;
}

u16 gset_get_filenum2(s32 weaponnum)
{
	return gset_get_filenum(weaponnum);
}

void gset_populate(s32 handnum, struct gset *gset)
{
	gset->weaponnum = g_Vars.currentplayer->gunctrl.weaponnum;
	gset->weaponfunc = g_Vars.currentplayer->hands[handnum].gset.weaponfunc;
	gset->miscbyte = g_Vars.currentplayer->hands[handnum].gset.miscbyte;
	gset->upgradewant = g_Vars.currentplayer->hands[handnum].gset.upgradewant;

	if (gset->weaponnum == WEAPON_MAULER) {
		gset->maulercharge = g_Vars.currentplayer->hands[handnum].mm_maulercharge * 10.0f;
	}

	if (gset->weaponnum == WEAPON_LASER) {
		gset->lasershots = g_Vars.currentplayer->hands[handnum].burstbullets & 0xff;
	}
}

struct ammodef *gset_get_current_ammodef(struct gset *gset)
{
	struct funcdef *func = gset_get_funcdef_by_gset(gset);
	struct weapondef *weapon = gset_get_weapondef(gset->weaponnum);

	if (func && func->ammoindex >= 0) {
		return weapon->ammos[func->ammoindex];
	}

	return NULL;
}

u8 gset_get_single_penetration(struct gset *gset)
{
	struct funcdef *func = gset_get_funcdef_by_gset(gset);

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		struct funcdef_shoot *funcshoot = (struct funcdef_shoot *)func;
		return funcshoot->penetration;
	}

	return 0;
}

s32 gset_get_casing_type(struct gset *gset)
{
	s32 result = 0;
	struct ammodef *ammo = gset_get_current_ammodef(gset);

	if (ammo) {
		result = ammo->casingeject;
	}

	return result;
}

f32 gset_get_impact_force(struct gset *gset)
{
	struct funcdef *func = gset_get_funcdef_by_gset(gset);
	f32 result = 0;

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		struct funcdef_shoot *funcshoot = (struct funcdef_shoot *)func;
		result = funcshoot->impactforce;
	}

	return result;
}

f32 gset_get_damage(struct gset *gset)
{
	struct funcdef *func = gset_get_funcdef_by_gset(gset);
	f32 damage = 0;

	if (func) {
		if ((func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
			struct funcdef_shoot *shootfunc = (struct funcdef_shoot *)func;
			damage = shootfunc->damage;
		}

		if ((func->type & 0xff) == INVENTORYFUNCTYPE_MELEE) {
			struct funcdef_melee *meleefunc = (struct funcdef_melee *)func;
			damage = meleefunc->damage;

			if (gset->weaponnum == WEAPON_REAPER) {
				damage *= LVUPDATE60FREAL();
			}
		}

		if ((func->type & 0xff) == INVENTORYFUNCTYPE_THROW) {
			struct funcdef_throw *throwfunc = (struct funcdef_throw *)func;
			damage = throwfunc->damage;
		}
	}

	if (gset->weaponnum == WEAPON_MAULER) {
		damage = (gset->maulercharge / 3.0f + 1.0f) * damage;
	}

	if (bgun_is_firing(HAND_LEFT) && bgun_is_firing(HAND_RIGHT)) {
		damage += damage;
	}

	return damage;
}

u8 gset_get_fireslot_duration(struct gset *gset)
{
#if VERSION >= VERSION_PAL_FINAL
	struct funcdef *func = gset_get_funcdef_by_gset(gset);
	u8 result = 0;

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		struct funcdef_shoot *funcshoot = (struct funcdef_shoot *)func;
		result = funcshoot->duration60;
	}

	if (result >= 4) {
		result = TICKS(result);
	}

	return result;
#else
	struct funcdef *func = gset_get_funcdef_by_gset(gset);

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		struct funcdef_shoot *funcshoot = (struct funcdef_shoot *)func;
		return funcshoot->duration60;
	}

	return 0;
#endif
}

u16 gset_get_single_shoot_sound(struct gset *gset)
{
	struct funcdef *func = gset_get_funcdef_by_gset(gset);

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		struct funcdef_shoot *funcshoot = (struct funcdef_shoot *)func;
		return funcshoot->shootsound;
	}

	return 0;
}

bool gset_has_function_flags(struct gset *gset, u32 flags)
{
	struct funcdef *func = gset_get_funcdef_by_gset(gset);

	if (func) {
		return (func->flags & flags) == flags;
	}

	return false;
}

s8 weapon_get_num_ticks_per_shot(u32 weaponnum, u32 funcindex)
{
	u32 stack[2];
	s32 result = 0;
	struct weapondef *weapon = gset_get_weapondef(weaponnum);
	struct funcdef *func = weapon->functions[funcindex];

	if (func && func->type == INVENTORYFUNCTYPE_SHOOT_AUTOMATIC) {
		struct funcdef_shootauto *autofunc = (struct funcdef_shootauto *)func;

		result = 3600.0f / autofunc->maxrpm;
	}

#if VERSION != VERSION_PAL_BETA
	// PAL beta removes this check, only for it to be added back in PAL final
	if (result > 3) {
		result = TICKS(result);
	}
#endif

	return result;
}

u32 gset_get_sight(void)
{
	struct funcdef *func = gset_get_funcdef_by_weaponnum_funcnum(
			g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponnum,
			g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponfunc);

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_MELEE) {
		return SIGHT_NONE;
	}

	if (cheat_is_active(CHEAT_CLASSICSIGHT)) {
		return SIGHT_CLASSIC;
	}

	switch (g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponnum) {
	case WEAPON_HORIZONSCANNER:
		return SIGHT_NONE;
	case WEAPON_NONE:
	case WEAPON_UNARMED:
	case WEAPON_FALCON2:
	case WEAPON_FALCON2_SILENCER:
	case WEAPON_DY357MAGNUM:
	case WEAPON_DY357LX:
	case WEAPON_CMP150:
	case WEAPON_CYCLONE:
	case WEAPON_RCP120:
	case WEAPON_SHOTGUN:
	case WEAPON_DEVASTATOR:
	case WEAPON_ROCKETLAUNCHER:
	case WEAPON_SLAYER:
	case WEAPON_COMBATKNIFE:
	case WEAPON_CROSSBOW:
	case WEAPON_TRANQUILIZER:
	case WEAPON_LASER:
	case WEAPON_GRENADE:
	case WEAPON_NBOMB:
	case WEAPON_TIMEDMINE:
	case WEAPON_PROXIMITYMINE:
	case WEAPON_REMOTEMINE:
	case WEAPON_ECMMINE:
		return SIGHT_DEFAULT;
	case WEAPON_FALCON2_SCOPE:
	case WEAPON_MAGSEC4:
	case WEAPON_SNIPERRIFLE:
	case WEAPON_LAPTOPGUN:
	case WEAPON_DRAGON:
	case WEAPON_K7AVENGER:
	case WEAPON_AR34:
	case WEAPON_SUPERDRAGON:
		return SIGHT_ZOOM;
	case WEAPON_MAULER:
	case WEAPON_REAPER:
		return SIGHT_SKEDAR;
	case WEAPON_PHOENIX:
	case WEAPON_CALLISTO:
	case WEAPON_FARSIGHT:
		return SIGHT_MAIAN;
	case WEAPON_PP9I:
	case WEAPON_CC13:
	case WEAPON_KL01313:
	case WEAPON_KF7SPECIAL:
	case WEAPON_ZZT:
	case WEAPON_DMC:
	case WEAPON_AR53:
	case WEAPON_RCP45:
		return SIGHT_CLASSIC;
	}

	return SIGHT_DEFAULT;
}

void gset_get_noise_settings(struct gset *gset, struct noisesettings *dst)
{
	struct noisesettings *settings = NULL;
	struct funcdef *func = gset_get_funcdef_by_gset(gset);

	if (func != NULL) {
		settings = func->noisesettings;
	}

	if (settings == NULL) {
		settings = &invnoisesettings_silent;
	}

	dst->minradius = settings->minradius;
	dst->maxradius = settings->maxradius;
	dst->incradius = settings->incradius;
	dst->decbasespeed = settings->decbasespeed;
	dst->decremspeed = settings->decremspeed;
}

struct guncmd *gset_get_equip_anim(struct gset *gset)
{
	struct weapondef *weapon = g_Weapons[gset->weaponnum];

	if (weapon) {
		return weapon->equip_animation;
	}

	return NULL;
}

struct guncmd *gset_get_unequip_anim(struct gset *gset)
{
	struct weapondef *weapon = g_Weapons[gset->weaponnum];

	if (weapon) {
		return weapon->unequip_animation;
	}

	return NULL;
}

struct guncmd *gset_get_pritosec_anim(struct gset *gset)
{
	struct weapondef *weapon = g_Weapons[gset->weaponnum];

	if (weapon) {
		return weapon->pritosec_animation;
	}

	return NULL;
}

struct guncmd *gset_get_sectopri_anim(struct gset *gset)
{
	struct weapondef *weapon = g_Weapons[gset->weaponnum];

	if (weapon) {
		return weapon->sectopri_animation;
	}

	return NULL;
}
