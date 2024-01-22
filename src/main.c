#include "compress.h"
#include "decompress.h"
#include <stdio.h>

void print_data(const unsigned char *data, int size) {
  for (int i = 0; i < size; i++) {
    printf("%02x ", data[i]);
  }
  printf("\n");
}

int main() {
  unsigned char data[] = {0x03, 0x74, 0x04, 0x04, 0x04, 0x35, 0x35, 0x64,
                          0x64, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00,
                          0x56, 0x45, 0x56, 0x56, 0x56, 0x09, 0x09, 0x09};
  int data_size = 24;

  printf("Original Data:\t\t");
  print_data(data, data_size);

  int new_size = byte_compress(data, data_size);
  printf("Compressed Data:\t");
  print_data(data, new_size);

  byte_decompress(data, new_size);
  printf("Decompressed Data:\t");
  print_data(data, data_size);

  return 0;
}
