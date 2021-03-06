# - Try to find XKBCommon
# Once done, this will define
#
#   XKBCOMMON_FOUND - System has XKBCommon
#   XKBCOMMON_INCLUDE_DIRS - The XKBCommon include directories
#   XKBCOMMON_LIBRARIES - The libraries needed to use XKBCommon
#   XKBCOMMON_DEFINITIONS - Compiler switches required for using XKBCommon

find_package(PkgConfig)
pkg_check_modules(PC_XKBCOMMON_X11 QUIET xkbcommon-x11)
set(XKBCOMMON_X11_DEFINITIONS ${PC_XKBCOMMON_X11_CFLAGS_OTHER})

find_path(XKBCOMMON_X11_INCLUDE_DIR
    NAMES xkbcommon/xkbcommon-x11.h
    HINTS ${PC_XKBCOMMON_X11_INCLUDE_DIR} ${PC_XKBCOMMON_X11_INCLUDE_DIRS}
)

find_library(XKBCOMMON_X11_LIBRARY
    NAMES xkbcommon-x11
    HINTS ${PC_XKBCOMMON_X11_LIBRARY} ${PC_XKBCOMMON_X11_LIBRARY_DIRS}
)

set(XKBCOMMON_X11_LIBRARIES ${XKBCOMMON_X11_LIBRARY})
set(XKBCOMMON_X11_LIBRARY_DIRS ${XKBCOMMON_X11_LIBRARY_DIRS})
set(XKBCOMMON_X11_INCLUDE_DIRS ${XKBCOMMON_X11_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(XKBCommon-X11 DEFAULT_MSG
    XKBCOMMON_X11_LIBRARY
    XKBCOMMON_X11_INCLUDE_DIR
)

mark_as_advanced(XKBCOMMON_X11_LIBRARY XKBCOMMON_X11_INCLUDE_DIR)

