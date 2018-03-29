//========================================================================
// GLFW 3.3 XKB - www.glfw.org
//------------------------------------------------------------------------
// Copyright (c) 2018 Kovid Goyal <kovid@kovidgoyal.net>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#pragma once

#include <xkbcommon/xkbcommon.h>
#include <xkbcommon/xkbcommon-compose.h>
#ifdef _GLFW_X11
#include <xkbcommon/xkbcommon-x11.h>
#endif

typedef struct {
    struct xkb_context*     context;
    struct xkb_keymap*      keymap;
    struct xkb_state*       state;
    struct xkb_compose_state* composeState;
    short int               keycodes[256];
    short int               scancodes[GLFW_KEY_LAST + 1];

    xkb_mod_mask_t          controlMask;
    xkb_mod_mask_t          altMask;
    xkb_mod_mask_t          shiftMask;
    xkb_mod_mask_t          superMask;
    xkb_mod_mask_t          capsLockMask;
    xkb_mod_mask_t          numLockMask;
    unsigned int            modifiers;

#ifdef _GLFW_X11
    int32_t                 keyboard_device_id;
    GLFWbool                available;
    GLFWbool                detectable;
    int                     majorOpcode;
    int                     eventBase;
    int                     errorBase;
    int                     major;
    int                     minor;
#endif

} _GLFWXKBData;

#ifdef _GLFW_X11
GLFWbool glfw_xkb_set_x11_events_mask(void);
GLFWbool glfw_xkb_update_x11_keyboard_id(_GLFWXKBData *xkb);
#endif

void glfw_xkb_release(_GLFWXKBData *xkb);
GLFWbool glfw_xkb_create_context(_GLFWXKBData *xkb);
GLFWbool glfw_xkb_compile_keymap(_GLFWXKBData *xkb, const char *map_str);
void glfw_xkb_update_modifiers(_GLFWXKBData *xkb, unsigned int depressed, unsigned int latched, unsigned int locked, unsigned int group);
int glfw_xkb_to_glfw_key_code(_GLFWXKBData *xkb, unsigned int key);
