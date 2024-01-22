# RLE Compression Algorithm

This is a simple, lightweight project for compressing and decompressing data.

## Algorithm Explanation

### Compression (Run-Length Encoding - RLE)
RLE works by scanning the data for sequences of repeated bytes and compressing these sequences into two-byte pairs:

- The first byte represents the count of repetitions.
- The second byte is the value being repeated.

For example, a sequence like 0x00 0x00 0x00 would be compressed to 0x03 0x00 (three repetitions of the byte 0x03).

### Decompression

The decompression process reverses the RLE compression and ensures that the compression algorithm was lossless:

- It reads the compressed data in two-byte pairs.
- It then replicates the second byte of each pair according to the count specified in the first byte.

This process reconstructs the original uncompressed data from its compressed form.

## Algorithm Analysis

### Design Choices

- Run-Length Encoding (RLE): Chosen for its simplicity and effectiveness in compressing data with repeated values.
- In-Place Compression and Decompression: The original data buffer is modified directly to store the compressed/decompressed data, optimizing memory usage.
- Dynamic Memory Allocation: Ensures that memory usage scales with the size of the data being processed.

### Tradeoffs

- Efficiency with Repeated Data: While RLE excels at compressing data with many repeated elements, it can perform poorly or even increase the size of datasets with high variability (many unique elements).
- Memory Overhead: The algorithm initially allocates memory double the size of the input data as a worst-case scenario buffer. This might be more than necessary, especially for highly compressible data.
