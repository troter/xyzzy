#include "cdecl.h"
#include "version.h"

#if !PROGRAM_PATCH_LEVEL
# if !PROGRAM_MINOR_REVISION
#  if !PROGRAM_MAJOR_REVISION
#   define PROGRAM_VERSION \
  _TOSTR (PROGRAM_MAJOR_VERSION) "." _TOSTR (PROGRAM_MINOR_VERSION)
#  else /* PROGRAM_MAJOR_REVISION */
#   define PROGRAM_VERSION \
  _TOSTR (PROGRAM_MAJOR_VERSION) "." _TOSTR (PROGRAM_MINOR_VERSION) \
    "." _TOSTR (PROGRAM_MAJOR_REVISION)
#  endif /* PROGRAM_MAJOR_REVISION */
# else /* PROGRAM_MINOR_REVISION */
#  define PROGRAM_VERSION \
  _TOSTR (PROGRAM_MAJOR_VERSION) "." _TOSTR (PROGRAM_MINOR_VERSION) \
    "." _TOSTR (PROGRAM_MAJOR_REVISION) "." _TOSTR (PROGRAM_MINOR_REVISION)
# endif /* PROGRAM_MINOR_REVISION */
#else /* PROGRAM_PATCH_LEVEL */
#  define PROGRAM_VERSION \
  _TOSTR (PROGRAM_MAJOR_VERSION) "." _TOSTR (PROGRAM_MINOR_VERSION) \
    "." _TOSTR (PROGRAM_MAJOR_REVISION) "." _TOSTR (PROGRAM_MINOR_REVISION) \
      "." _TOSTR (PROGRAM_PATCH_LEVEL)
#endif /* PROGRAM_PATCH_LEVEL */

#if (PROGRAM_MAJOR_VERSION == 0 && PROGRAM_MINOR_VERSION == 2 \
     && PROGRAM_MAJOR_REVISION == 1 && PROGRAM_MINOR_REVISION == 176)
# define DISPLAY_VERSION_STRING "0.2.1.0xB0" // ���炵��
#else
# define DISPLAY_VERSION_STRING PROGRAM_VERSION
#endif

#define TITLEBAR_STRING PROGRAM_NAME " " DISPLAY_VERSION_STRING

char TitleBarString[TITLE_BAR_STRING_SIZE] = TITLEBAR_STRING;
const char VersionString[] = PROGRAM_VERSION;
const char DisplayVersionString[] = DISPLAY_VERSION_STRING;
const char ProgramName[] = PROGRAM_NAME;
const char ProgramNameWithVersion[] = PROGRAM_NAME " version " PROGRAM_VERSION;
