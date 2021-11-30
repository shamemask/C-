#ifndef _OBFUSCATOR_H
#define _OBFUSCATOR_H

#ifdef X
#pragma message("MACRO X IS ALREADY DEFINED, EXPECT SERIOUS ERRORS")
#endif

#ifdef DO_OBFUSCATE_STRINGS

__forceinline char *obDecodeStr(char *inst);

#define X(s)obDecodeStr(OBPREPROCESSENCODEDSTR(s))
#else
#define X(s)s
#endif

#endif