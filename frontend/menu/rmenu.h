/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2013 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2013 - Daniel De Matteis
 * 
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _RMENU_H_
#define _RMENU_H_

#include "menu_common.h"

#ifdef _XBOX1
#define HAVE_MENU_PANEL
#endif

#if defined(HAVE_OPENGL)
#define DEVICE_CAST gl_t*
#elif defined(_XBOX1)
#define DEVICE_CAST xdk_d3d_video_t*
#endif

enum
{
   CONFIG_FILE = 0,
#ifdef HAVE_SHADER_MANAGER
   SHADER_PRESET_FILE,
#endif
};

enum
{
   FILE_BROWSER_MENU = 0,
#ifdef HAVE_SHADER_MANAGER
   SHADER_CHOICE,
   CGP_CHOICE,
#endif
   BORDER_CHOICE,
   LIBRETRO_CHOICE,
   PATH_SAVESTATES_DIR_CHOICE,
   PATH_DEFAULT_ROM_DIR_CHOICE,
#ifdef HAVE_XML
   PATH_CHEATS_DIR_CHOICE,
#endif
   PATH_SRAM_DIR_CHOICE,
   PATH_SYSTEM_DIR_CHOICE,
   CONFIG_CHOICE,
   INGAME_MENU,
   INGAME_MENU_SETTINGS,
   INGAME_MENU_CUSTOM_RATIO,
   INGAME_MENU_CORE_OPTIONS,
   INGAME_MENU_LOAD_GAME_HISTORY,
   INGAME_MENU_VIDEO_OPTIONS,
   INGAME_MENU_AUDIO_OPTIONS,
   INGAME_MENU_INPUT_OPTIONS,
   INGAME_MENU_PATH_OPTIONS,
   INGAME_MENU_SHADER_OPTIONS,
   INGAME_MENU_SCREENSHOT,
};


#ifndef HAVE_RMENU_XUI
enum
{
   SETTING_REWIND_ENABLED,
   SETTING_REWIND_GRANULARITY,
   SETTING_EMU_SHOW_DEBUG_INFO_MSG,
   SETTING_EMU_SHOW_INFO_MSG,
   SETTING_EMU_SKIN,
   SETTING_EMU_END,
   SETTING_SOUND_MODE,
#ifdef HAVE_RSOUND
   SETTING_RSOUND_SERVER_IP_ADDRESS,
#endif
   SETTING_ENABLE_CUSTOM_BGM,
#ifdef _XBOX1
   SETTING_EMU_AUDIO_SOUND_VOLUME_LEVEL,
#endif
   SETTING_EMU_AUDIO_MUTE,
   SETTING_AUDIO_CONTROL_RATE_DELTA,
   SETTING_EMU_AUDIO_END,
   SETTING_PATH_DEFAULT_ROM_DIRECTORY,
   SETTING_PATH_SAVESTATES_DIRECTORY,
   SETTING_PATH_SRAM_DIRECTORY,
#ifdef HAVE_XML
   SETTING_PATH_CHEATS,
#endif
   SETTING_PATH_SYSTEM,
   SETTING_PATH_END,
   SETTING_CONTROLS_NUMBER,
   SETTING_CONTROLS_BIND_DEVICE_TYPE,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_B,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_Y,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_SELECT,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_START,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_UP,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_DOWN,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_LEFT,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_RIGHT,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_A,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_X,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_L,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_R,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_L2,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_R2,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_L3,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_R3,
   SETTING_CONTROLS_DEFAULT_ALL,
   SETTING_CONTROLS_END,
   SETTING_END,
   INGAME_MENU_CHANGE_LIBRETRO_CORE,
   INGAME_MENU_LOAD_GAME_HISTORY_MODE,
   INGAME_MENU_CHANGE_GAME,
   INGAME_MENU_CORE_OPTIONS_MODE,
   INGAME_MENU_VIDEO_OPTIONS_MODE,
   INGAME_MENU_AUDIO_OPTIONS_MODE,
   INGAME_MENU_INPUT_OPTIONS_MODE,
   INGAME_MENU_PATH_OPTIONS_MODE,
   INGAME_MENU_SETTINGS_MODE,
   INGAME_MENU_LOAD_STATE,
   INGAME_MENU_SAVE_STATE,
   INGAME_MENU_SCREENSHOT_MODE,
   INGAME_MENU_RETURN_TO_GAME,
   INGAME_MENU_RESET,
#ifdef HAVE_MULTIMAN
   INGAME_MENU_RETURN_TO_MULTIMAN,
#endif
   INGAME_MENU_CONFIG,
   INGAME_MENU_SAVE_CONFIG,
   INGAME_MENU_QUIT_RETROARCH,
   INGAME_MENU_END,
#ifdef HAVE_SHADER_MANAGER
   INGAME_MENU_SHADER_OPTIONS_MODE,
#endif
#ifdef __CELLOS_LV2__
   SETTING_CHANGE_RESOLUTION,
   SETTING_PAL60_MODE,
#endif
   SETTING_HW_TEXTURE_FILTER,
#ifdef _XBOX1
   SETTING_FLICKER_FILTER,
   SETTING_SOFT_DISPLAY_FILTER,
#endif
   SETTING_TRIPLE_BUFFERING,
   SETTING_ASPECT_RATIO,
   SETTING_CUSTOM_VIEWPORT,
   SETTING_ROTATION,
   SETTING_VIDEO_VSYNC,
   SETTING_VIDEO_CROP_OVERSCAN,
   SETTING_REFRESH_RATE,
   SETTING_VIDEO_END,
#ifdef HAVE_SHADER_MANAGER
   SHADERMAN_APPLY_CHANGES,
   SHADERMAN_LOAD_CGP,
   SHADERMAN_SAVE_CGP,
   SHADERMAN_SHADER_PASSES,
   SHADERMAN_SHADER_0,
   SHADERMAN_SHADER_0_FILTER,
   SHADERMAN_SHADER_0_SCALE,
   SHADERMAN_SHADER_1,
   SHADERMAN_SHADER_1_FILTER,
   SHADERMAN_SHADER_1_SCALE,
   SHADERMAN_SHADER_2,
   SHADERMAN_SHADER_2_FILTER,
   SHADERMAN_SHADER_2_SCALE,
   SHADERMAN_SHADER_3,
   SHADERMAN_SHADER_3_FILTER,
   SHADERMAN_SHADER_3_SCALE,
   SHADERMAN_SHADER_4,
   SHADERMAN_SHADER_4_FILTER,
   SHADERMAN_SHADER_4_SCALE,
   SHADERMAN_SHADER_5,
   SHADERMAN_SHADER_5_FILTER,
   SHADERMAN_SHADER_5_SCALE,
   SHADERMAN_SHADER_6,
   SHADERMAN_SHADER_6_FILTER,
   SHADERMAN_SHADER_6_SCALE,
   SHADERMAN_SHADER_7,
   SHADERMAN_SHADER_7_FILTER,
   SHADERMAN_SHADER_7_SCALE,
#endif
   SETTING_LAST_LAST,
};
#endif

#define FIRST_SETTING				      0
#define FIRST_VIDEO_SETTING            INGAME_MENU_END+1
#define FIRST_AUDIO_SETTING            SETTING_EMU_END+1
#define FIRST_PATH_SETTING				   SETTING_EMU_AUDIO_END+1
#define FIRST_CONTROLS_SETTING_PAGE_1	SETTING_PATH_END+1
#define FIRST_CONTROL_BIND				   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_B
#define FIRST_INGAME_MENU_SETTING      SETTING_END+1

#define MAX_NO_OF_SETTINGS			      SETTING_EMU_END
#define MAX_NO_OF_VIDEO_SETTINGS			SETTING_VIDEO_END
#define MAX_NO_OF_AUDIO_SETTINGS			SETTING_EMU_AUDIO_END
#define MAX_NO_OF_PATH_SETTINGS			SETTING_PATH_END
#define MAX_NO_OF_CONTROLS_SETTINGS		SETTING_CONTROLS_END
#define MAX_NO_OF_INGAME_MENU_SETTINGS INGAME_MENU_END

#ifdef HAVE_SHADER_MANAGER
#define FIRST_SHADERMAN_SETTING        SETTING_VIDEO_END+1
#define MAX_NO_OF_SHADERMAN_SETTINGS   SHADERMAN_SHADER_PASSES+1
#endif

#endif /* MENU_H_ */
