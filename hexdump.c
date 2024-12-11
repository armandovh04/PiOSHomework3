#include <stdio.h>
void hexdump(char *buffer, unsigned int length) {
  unsigned int i, j;

  for (i = 0; i < length; i += 16) {
     printf("%08lx  ", (unsigned long)(buffer + i));

    for (j = 0; j < 16; ++j) {
         if (i + j < length) {
             printf("%02x ", (unsigned char)buffer[i + j]);
         } else {
             printf("   "); // Padding for incomplete lines
        }
    }

    printf("  |");
    for (j = 0; j < 16; ++j) {
        if (i + j < length) {
            char c = buffer[i + j];
            printf("%c", (c >= 32 && c <= 126) ? c : '.');
        } else {
            printf(" ");
          }
      }
    printf("|\n");
  }
}

int main() {
  char dummy_buffer[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20
  };

  printf("Hexdump of dummy_buffer:\n");
  hexdump(dummy_buffer, sizeof(dummy_buffer));

  return 0;
}
