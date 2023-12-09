#include <stdio.h>

// THIS PROGRAM DOES 3X8-BIT TO 4X6-BIT CONVERSION
int main() {
    // Manually specify a few bytes to encode
    unsigned char source[9] = {0xd8, 0xff, 0xe0, 0xff, 0x10, 0x00, 0x46, 0x4a, 0x46};
    char buffer[4] = {0,0,0,0};

    // sizeof(char) == 1 byte, so the array's size in bytes is also its length
    int source_length = sizeof(source);
    for (int i = 0; i< source_length; i++) {
        printf("0x%02x ", source[i]);
    }
    printf("==> ");
    for (int i = 0; i < source_length; i+=3) {
        unsigned char byte1 = source[i];
        unsigned char byte2 = source[i+1];
        unsigned char byte3 = source[i+2];

        // Move the appropriate bits into the buffer
        buffer[0] = byte1 >> 2;
        buffer[1] = (byte1 & 0x03) << 4;
        buffer[1] |= (byte2 & 0xf0) >> 4;
        buffer[2] = (byte2 & 0x0f) << 2;
        buffer[2] |= (byte3 & 0xc0) >> 6;
        buffer[3] = byte3 & 0x3f;

        for (int b = 0; b < 4; b++) {
            if (buffer[b] < 26) {
                // Uppercase letter
                printf("%c", 'A' + buffer[b]);
            } else if (buffer[b] < 52) {
                // Lowercase letter
                printf("%c", 'a' + (buffer[b] - 26));
            } else if (buffer[b] < 62) {
                // A digit
                printf("%c", '0' + (buffer[b] - 52));
            } else if (buffer[b] == 62) {
                // "+"
                printf("+");
            } else if (buffer[b] == 63) {
                // "/"
                printf("/");
            } else {
                printf("Invalid 6-bit value: %c\n", buffer[b]);
            }
        }
    }
    return 0;
}