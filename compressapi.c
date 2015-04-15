#include "compressapi.h"
#include "zpipe.h"

int adaptive_inflate(FILE* input, FILE* output) {
  return inf(input, output);
}

int adaptive_deflate(FILE* input, FILE* output) {
  return def(input, output, Z_DEFAULT_COMPRESSION);
}