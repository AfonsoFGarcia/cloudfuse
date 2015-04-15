#include "compressapi.h"

int compression_level = 0;

int adaptive_inflate(FILE* input, FILE* output) {
  return inf(input, output);
}

int adaptive_deflate(FILE* input, FILE* output) {
  return def(input, output, compression_level);
}

void reset_level() {
  compression_level = 0;
}