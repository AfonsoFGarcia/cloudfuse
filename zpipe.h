#ifndef ZPIPE_GUARD
#define ZPIPE_GUARD

	#include <stdio.h>
	#include <string.h>
	#include <assert.h>
	#include "zlib.h"

	#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__)
	#  include <fcntl.h>
	#  include <io.h>
	#  define SET_BINARY_MODE(file) setmode(fileno(file), O_BINARY)
	#else
	#  define SET_BINARY_MODE(file)
	#endif

	int CHUNK;

	int def(FILE *source, FILE *dest, int level);
	int inf(FILE *source, FILE *dest);

#endif