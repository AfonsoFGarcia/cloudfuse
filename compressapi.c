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

void update_level(int diff) {
  int size = fifo_size();

  if (size < 10) {
    if (diff <= 0) {
      compression_level = compression_level / 2;
    }
  } else if (size < 20) {
    if (diff > 0) {
      compression_level++;
    } else if (diff < 0) {
      compression_level--;
    }
  } else if (size < 30) {
    if (diff > 0) {
      compression_level += 2;
    } else if (diff < 0) {
      compression_level--;
    }
  } else if (diff > 0) {
    compression_level += 2;
  }

  if(compression_level > 9) {
    compression_level = 9;
  } else if (compression_level < 0) {
    compression_level = 0;
  }
}