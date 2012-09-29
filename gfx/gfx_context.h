/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2012 - Hans-Kristian Arntzen
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

#ifndef __GFX_CONTEXT_H
#define __GFX_CONTEXT_H

#include "../boolean.h"
#include "../driver.h"

#ifdef HAVE_CONFIG_H
#include "../config.h"
#endif

#if defined(HAVE_SDL) && !defined(__APPLE__)
#include "SDL_syswm.h"
#endif

enum gfx_ctx_api
{
   GFX_CTX_OPENGL_API,
   GFX_CTX_OPENGL_ES_API,
   GFX_CTX_OPENVG_API
};

typedef void (*gfx_ctx_proc_t)(void);

// Avoid breakage on XBox. TODO: Migrate to new context abstraction if it makes sense.
#if !defined(HAVE_D3D9) && !defined(HAVE_D3D8)
typedef struct gfx_ctx_driver
{
   bool (*init)(void);
   void (*destroy)(void);

   bool (*bind_api)(enum gfx_ctx_api); // Which API to bind to.

   // Sets the swap interval.
   void (*swap_interval)(unsigned);

   // Sets video mode. Creates a window, etc.
   bool (*set_video_mode)(unsigned, unsigned, unsigned, bool);

   // Gets current window size.
   // If not initialized yet, it returns current screen size.
   void (*get_video_size)(unsigned*, unsigned*);

   // Translates a window size to an aspect ratio.
   // In most cases this will be just width / height, but
   // some contexts will better know which actual aspect ratio is used.
   // This can be NULL to assume the default behavior.
   float (*translate_aspect)(unsigned, unsigned);

   // Asks driver to update window title (FPS, etc).
   void (*update_window_title)(bool);

   // Queries for resize and quit events.
   // Also processes events.
   void (*check_window)(bool*, bool*, unsigned*, unsigned*, unsigned);

   // Acknowledge a resize event. This is needed for some APIs. Most backends will ignore this.
   void (*set_resize)(unsigned, unsigned);

   // Checks if window has input focus.
   bool (*has_focus)(void);

   // Swaps buffers. VBlank sync depends on earlier calls to swap_interval.
   void (*swap_buffers)(void);

   // Most video backends will want to use a certain input driver.
   // Checks for it here.
   void (*input_driver)(const input_driver_t**, void**);

   // Wraps whatever gl_proc_address() there is.
   gfx_ctx_proc_t (*get_proc_address)(const char*);

   // Human readable string.
   const char *ident;

#ifdef RARCH_CONSOLE
   void (*set_filtering)(unsigned index, bool set_smooth);
   void (*get_available_resolutions)(void);
   int  (*check_resolution)(unsigned resolution_id);
   bool (*menu_init)(void);
   void (*set_fbo)(bool);
   void (*apply_fbo_state_changes)(unsigned);
#endif
} gfx_ctx_driver_t;

extern const gfx_ctx_driver_t gfx_ctx_sdl_gl;
extern const gfx_ctx_driver_t gfx_ctx_x_egl;
extern const gfx_ctx_driver_t gfx_ctx_glx;
extern const gfx_ctx_driver_t gfx_ctx_drm_egl;
extern const gfx_ctx_driver_t gfx_ctx_ps3;
extern const gfx_ctx_driver_t gfx_ctx_videocore;

const gfx_ctx_driver_t *gfx_ctx_find_driver(const char *ident); // Finds driver with ident. Does not initialize.
const gfx_ctx_driver_t *gfx_ctx_init_first(enum gfx_ctx_api api); // Finds first suitable driver and initializes.

#else
void gfx_ctx_set_swap_interval(unsigned interval, bool inited);

bool gfx_ctx_set_video_mode(
      unsigned width, unsigned height,
      unsigned bits, bool fullscreen);

bool gfx_ctx_init(void);
void gfx_ctx_destroy(void);

void gfx_ctx_get_video_size(unsigned *width, unsigned *height);
void gfx_ctx_update_window_title(bool reset);

void gfx_ctx_check_window(bool *quit,
      bool *resize, unsigned *width, unsigned *height, unsigned frame_count);

void gfx_ctx_set_resize(unsigned width, unsigned height);

#ifndef HAVE_GRIFFIN
bool gfx_ctx_window_has_focus(void);
#endif
void gfx_ctx_swap_buffers(void);

void gfx_ctx_input_driver(const input_driver_t **input, void **input_data);

#ifdef HAVE_CG_MENU
bool gfx_ctx_menu_init(void);
#endif

void gfx_ctx_set_filtering(unsigned index, bool set_smooth);
void gfx_ctx_get_available_resolutions(void);
int gfx_ctx_check_resolution(unsigned resolution_id);

void gfx_ctx_set_projection(xdk_d3d_video_t *vid, const struct gl_ortho *ortho, bool allow_rotate);
#endif

#endif

