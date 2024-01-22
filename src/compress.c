#include "compress.h"
#include <string.h>

int byte_compress(unsigned char *data_ptr, int data_size) {
  unsigned char *compressed = (unsigned char *)malloc(2 * data_size);
  int compressed_size = 0, count;

  for (int i = 0; i < data_size; i++) {
    count = 1;
    while (i < data_size - 1 && data_ptr[i] == data_ptr[i + 1] && count < 127) {
      count++;
      i++;
    }
    compressed[compressed_size++] = count;
    compressed[compressed_size++] = data_ptr[i];
  }

  memcpy(data_ptr, compressed, compressed_size);
  free(compressed);
  return compressed_size;
}
