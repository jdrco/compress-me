#include "decompress.h"
#include <string.h>

/**
 * Decompresses a buffer of bytes that was compressed using Run-Length Encoding
 * (RLE).
 *
 * This function reverses the compression performed by the RLE compression
 * algorithm. It reads pairs of bytes from the compressed data, where the first
 * byte in each pair represents the count and the second byte is the value that
 * was repeated. It then reconstructs the original uncompressed data by
 * replicating each value the specified number of times.
 *
 * @param data_ptr Pointer to the compressed data buffer to be decompressed.
 * @param compressed_size Size of the compressed data buffer in bytes.
 * @return The size of the decompressed data, or -1 if memory allocation fails.
 */
int byte_decompress(unsigned char *data_ptr, int compressed_size) {
  unsigned char *decompressed = (unsigned char *)malloc(2 * compressed_size);
  int decompressed_size = 0;

  if (decompressed == NULL) {
    return -1;
  }

  for (int i = 0; i < compressed_size; i += 2) {
    for (int j = 0; j < data_ptr[i]; j++) {
      decompressed[decompressed_size++] = data_ptr[i + 1];
    }
  }

  memcpy(data_ptr, decompressed, decompressed_size);
  free(decompressed);
  return decompressed_size;
}
