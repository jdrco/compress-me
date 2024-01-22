#include "compress.h"
#include <string.h>

/**
 * Compresses a buffer of bytes using basic Run-Length Encoding (RLE).
 *
 * This function implements a simple RLE compression algorithm, which is
 * effective for data with common repeated consecutive values. It compresses
 * each sequence of repeated bytes into a pair: [count, byte], where 'count' is
 * the number of repetitions of the current 'byte'. The function modifies the
 * original data buffer with the compressed data and returns the size of this
 * compressed data.
 *
 * Note: If the data contains many unique bytes (no repetitions), the
 * "compressed" data may end up being larger than the original (negative
 * compression).
 *
 * @param data_ptr Pointer to the data buffer to be compressed.
 * @param data_size Size of the data buffer in bytes.
 * @return The size of the compressed data.
 */
int byte_compress(unsigned char *data_ptr, int data_size) {
  // In the worst case this will be twice the original data size.
  unsigned char *compressed = (unsigned char *)malloc(2 * data_size);
  int compressed_size = 0, byte_count;

  if (compressed == NULL) {
    return -1;
  }

  for (int i = 0; i < data_size; i++) {
    byte_count = 1;
    while (i < data_size - 1 && data_ptr[i] == data_ptr[i + 1] &&
           byte_count < 127) {
      byte_count++;
      i++;
    }
    // Store count and byte as a consecutive pair
    compressed[compressed_size++] = byte_count;
    compressed[compressed_size++] = data_ptr[i];
  }

  // Copy the compressed data back into the original data buffer
  memcpy(data_ptr, compressed, compressed_size);

  free(compressed);
  return compressed_size;
}
