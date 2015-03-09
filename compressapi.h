#include <stdlib.h>
#include "fifo_ts.h"

#ifndef COMPRESS_GUARD
#define COMPRESS_GUARD

  int inflate(FILE* input, FILE* output, int level);
  int deflate(FILE* input, FILE* output);

#endif