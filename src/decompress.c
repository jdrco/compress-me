#include "decompress.h"
#include <string.h>

void byte_decompress(unsigned char *data_ptr, int compressed_size) {
  unsigned char *decompressed = (unsigned char *)malloc(2 * compressed_size);
  int decompressed_size = 0;

  for (int i = 0; i < compressed_size; i += 2) {
    for (int j = 0; j < data_ptr[i]; j++) {
      decompressed[decompressed_size++] = data_ptr[i + 1];
    }
  }

  memcpy(data_ptr, decompressed, decompressed_size);
  free(decompressed);
}
