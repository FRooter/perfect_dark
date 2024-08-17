#ifndef IN_GAME_MPLAYER_MPLAYER_H
#define IN_GAME_MPLAYER_MPLAYER_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

f32 mp_handicap_to_damage_scale(u8 value);
void func0f187838(struct mpchrconfig *mpchr);
void mp_start_match(void);
void mp_reset(void);
void mp_calculate_team_is_only_ai(void);
void func0f187fbc(s32 playernum);
void func0f187fec(void);
void mp_player_set_defaults(s32 playernum, bool autonames);
void func0f1881d4(s32 index);
void mp_init(void);
void mp_get_teams_with_default_name(u8 *mask);
void mp_set_team_names_to_default(u8 mask);
void mp_set_default_names_if_empty(void);
s32 mp_calculate_team_score_limit(void);
void mp_apply_limits(void);
s32 mp_get_player_rankings(struct ranking *rankings);
s32 mp_calculate_team_score(s32 arg0, s32 *arg1);
s32 mp_get_team_rankings(struct ranking *rankings);
s32 func0f188bcc(void);
s32 mp_get_num_weapon_options(void);
char *mp_get_weapon_label(s32 weaponnum);
void mp_set_weapon_slot(s32 slot, s32 mpweaponnum);
s32 mp_get_weapon_slot(s32 slot);
struct mpweapon *mp_get_mp_weapon_by_location(s32 locationindex);
s32 mp_count_weapon_set_thing(s32 weaponsetindex);
s32 func0f188f9c(s32 arg0);
s32 func0f189058(bool full);
s32 func0f189088(void);
char *mp_get_weapon_set_name(s32 arg0);
void func0f18913c(void);
void mp_apply_weapon_set(void);
void mp_set_weapon_set(s32 weaponsetnum);
void func0f1895e8(void);
s32 mp_get_weapon_set(void);
bool mp_is_paused(void);
void mp_set_paused(u8 mode);
Gfx *mp_render_modal_text(Gfx *gdl);
s32 mp_find_max_int(s32 playercount, s32 val0, s32 val1, s32 val2, s32 val3);
s32 mp_find_min_int(s32 playercount, s32 val0, s32 val1, s32 val2, s32 val3);
s32 mp_find_max_float(s32 playercount, f32 val0, f32 val1, f32 val2, f32 val3);
s32 mp_find_min_float(s32 playercount, f32 val0, f32 val1, f32 val2, f32 val3);
void mp_calculate_player_title(struct mpplayerconfig *mpplayer);
void mp_calculate_awards(void);
void mp_end_match(void);
s32 mp_get_num_heads2(void);
s32 mp_get_num_heads(void);
s32 mp_get_head_id(u8 headnum);
s32 mp_get_head_required_feature(u8 headnum);
s32 mp_get_beau_head_id(u8 headnum);
u32 mp_get_num_bodies(void);
s32 mp_get_body_id(u8 bodynum);
s32 mp_get_mpbodynum_by_bodynum(u16 bodynum);
char *mp_get_body_name(u8 mpbodynum);
u8 mp_get_body_required_feature(u8 bodynum);
s32 mp_get_mpheadnum_by_mpbodynum(s32 bodynum);
s32 mp_choose_random_lock_player(void);
bool mp_set_lock(s32 locktype, s32 playernum);
s32 mp_get_lock_type(void);
u32 mp_get_lock_player_num(void);
bool mp_is_player_locked_out(s32 playernum);
void mp_calculate_lock_if_last_winner_or_loser(void);
bool mp_is_track_unlocked(s32 tracknum);
s32 mp_get_track_slot_index(s32 tracknum);
s32 mp_get_track_num_at_slot_index(s32 slotindex);
s32 mp_get_num_unlocked_tracks(void);
s32 mp_get_track_music_num(s32 slotindex);
char *mp_get_track_name(s32 slotindex);
void mp_set_using_multiple_tunes(bool enable);
bool mp_get_using_multiple_tunes(void);
bool mp_is_multi_track_slot_enabled(s32 slot);
void mp_set_multi_track_slot_enabled(s32 slot, bool enable);
void mp_set_track_slot_enabled(s32 slot);
void mp_enable_all_multi_tracks(void);
void mp_disable_all_multi_tracks(void);
void mp_randomise_multi_tracks(void);
void mp_set_track_to_random(void);
s32 mp_get_current_track_slot_num(void);
s32 mp_choose_track(void);
struct mpchrconfig *mp_get_chr_config_by_slot_num(s32 slot);
s32 mp_get_chr_index_by_slot_num(s32 slot);
s32 mp_get_num_chrs(void);
u8 mp_find_unused_team_num(void);
void mp_create_bot_from_profile(s32 botnum, u8 difficulty);
void mp_set_bot_difficulty(s32 botnum, s32 difficulty);
s32 mp_get_slot_for_new_bot(void);
void mp_remove_simulant(s32 index);
bool mp_has_simulants(void);
bool mp_has_unused_bot_slots(void);
bool mp_is_sim_slot_enabled(s32 slot);
s32 mp_find_bot_profile(s32 type, s32 difficulty);
void mp_generate_bot_names(void);
s32 mp_player_get_index(struct chrdata *chr);
struct chrdata *mp_get_chr_from_player_index(s32 index);
s32 func0f18d074(s32 index);
s32 func0f18d0e8(s32 arg0);
void mpplayerfile_load_gun_funcs(struct savebuffer *buffer, s32 playernum);
void mpplayerfile_save_gun_funcs(struct savebuffer *buffer, s32 playernum);
void mpplayerfile_load_wad(s32 playernum, struct savebuffer *buffer, s32 arg2);
void mpplayerfile_save_wad(s32 playernum, struct savebuffer *buffer);
void mpplayerfile_get_overview(char *arg0, char *name, u32 *playtime);
s32 mpplayerfile_save(s32 playernum, s32 device, s32 fileid, u16 deviceserial);
s32 mpplayerfile_load(s32 playernum, s32 device, s32 arg2, u16 deviceserial);
s32 mp_get_num_presets(void);
bool mp_is_preset_unlocked(s32 presetnum);
s32 mp_get_num_unlocked_presets(void);
char *mp_get_preset_name_by_slot(s32 slot);
void mp_apply_config(struct mpconfigfull *mpconfig);
void mp0f18dec4(s32 arg0);
void mpsetupfile_load_wad(struct savebuffer *buffer);
void mpsetupfile_save_wad(struct savebuffer *buffer);
void mpsetupfile_get_overview(char *arg0, char *filename, u16 *numsims, u16 *stagenum, u16 *scenarionum);
s32 mpsetupfile_save(s32 device, s32 filenum, u16 deviceserial);
s32 mpsetupfile_load(s32 device, s32 filenum, u16 deviceserial);
void func0f18e558(void);
struct modeldef *func0f18e57c(s32 index, s32 *headnum);

#endif
