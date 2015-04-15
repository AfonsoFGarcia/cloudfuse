#include <stdlib.h>
#include "fifo_ts.h"

#ifndef COMPRESS_GUARD
#define COMPRESS_GUARD

  int adaptive_inflate(FILE* input, FILE* output);
  int adaptive_deflate(FILE* input, FILE* output);

#endif