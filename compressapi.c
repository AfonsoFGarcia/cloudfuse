#include "compressapi.h"

int inflate(FILE* input, FILE* output, int level) {
  output = dup(input);
  return 0;
}

int deflate(FILE* input, FILE* output) {
  output = dup(input);
  return 0;
}