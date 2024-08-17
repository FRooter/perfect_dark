#ifndef IN_GAME_BONDMOVE_H
#define IN_GAME_BONDMOVE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bmove_set_control_def(u32 controldef);
void bmove_set_auto_move_centre_enabled(bool enabled);
void bmove_set_auto_aim_y(bool enabled);
bool bmove_is_auto_aim_y_enabled(void);
bool bmove_is_auto_aim_y_enabled_for_current_weapon(void);
bool bmove_is_in_sight_aim_mode(void);
void bmove_update_auto_aim_y_prop(struct prop *prop, f32 autoaimy);
void bmove_set_auto_aim_x(bool enabled);
bool bmove_is_auto_aim_x_enabled(void);
bool bmove_is_auto_aim_x_enabled_for_current_weapon(void);
void bmove_update_auto_aim_x_prop(struct prop *prop, f32 autoaimx);
struct prop *bmove_get_hoverbike(void);
struct prop *bmove_get_grabbed_prop(void);
void bmove_grab_prop(struct prop *prop);
void bmove_set_mode(u32 movemode);
void bmove_set_mode_for_all_players(u32 movemode);
void bmove_handle_activate(void);
void bmove_apply_move_data(struct movedata *data);
void bmove_update_speed_theta(void);
f32 bmove_get_speed_verta_limit(f32 value);
void bmove_update_speed_verta(f32 value);
f32 bmove_get_speed_theta_control_limit(f32 value);
void bmove_update_speed_theta_control(f32 value);
f32 bmove_calculate_lookahead(void);
void bmove_reset_move_data(struct movedata *data);
void bmove_process_input(bool allowc1x, bool allowc1y, bool allowc1buttons, bool ignorec2);
void bmove_find_entered_rooms_by_pos(struct player *player, struct coord *arg1, RoomNum *rooms);
void bmove_find_entered_rooms(struct player *player, RoomNum *rooms);
void bmove_update_rooms(struct player *player);
void bmove0f0cb904(struct coord *coord);
void bmove0f0cba88(f32 *a, f32 *b, struct coord *c, f32 mult1, f32 mult2);
void bmove_update_move_init_speed(struct coord *newpos);
void bmove_tick(bool allowc1x, bool allowc1y, bool allowc1buttons, bool ignorec2);
void bmove_update_verta(void);
void bmove0f0cc19c(struct coord *arg);
void bmove_update_head(f32 arg0, f32 arg1, f32 arg2, Mtxf *arg3, f32 arg4);
void bmove0f0cc654(f32 arg0, f32 arg1, f32 arg2);
s32 bmove_get_crouch_pos(void);
s32 bmove_get_crouch_pos_by_player(s32 playernum);

#endif
