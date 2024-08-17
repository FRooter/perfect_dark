#include <ultra64.h>
#include "constants.h"
#include "game/lang.h"
#include "game/room.h"
#include "lib/main.h"
#include "bss.h"
#include "data.h"
#include "types.h"

#if VERSION == VERSION_JPN_FINAL
s32 var8009d370jf;
#endif

extern s32 g_JpnMaxCacheItems;

void lang_tick(void)
{
	s32 i;

#if VERSION == VERSION_JPN_FINAL
	static u32 language = 99;

	var8009d370jf = 0;

	main_override_variable("jap", &language);

	if (language < 2) {
		lang_set_jpn_enabled(language);
		language = 99;
	}

	for (i = 0; i < MAX_JPN_CACHE_ITEMS(); i++) {
		if (g_JpnCacheCacheItems[i].ttl) {
			g_JpnCacheCacheItems[i].ttl--;
		}
	}
#elif VERSION >= VERSION_PAL_BETA
	static u32 language = 99;

	main_override_variable("language", &language);

	if (language < 5) {
		lang_set_european(language);
		language = 99;
	}

	if (g_Jpn) {
		for (i = 0; i != MAX_JPN_CACHE_ITEMS(); i++) {
			if (g_JpnCacheCacheItems[i].ttl) {
				g_JpnCacheCacheItems[i].ttl--;
			}
		}
	}
#else
	if (g_Jpn) {
		for (i = 0; i != MAX_JPN_CACHE_ITEMS(); i++) {
			if (g_JpnCacheCacheItems[i].ttl) {
				g_JpnCacheCacheItems[i].ttl--;
			}
		}
	}
#endif
}
