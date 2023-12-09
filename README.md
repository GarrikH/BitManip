# 3x8 to 4x6 Bit Conversion Program

This C program performs a conversion from a 3x8-bit representation to a 4x6-bit representation. It takes a set of bytes as input and outputs the corresponding base64 encoding.

## Table of Contents

- [Usage](#usage)
- [Algorithm](#algorithm)
- [How to Compile](#how-to-compile)
- [Example](#example)
- [License](#license)

## Usage

To use the program, follow these steps:

1. Compile the program (see [How to Compile](#how-to-compile)).
2. Run the compiled executable.
3. Input bytes for conversion when prompted.
4. The program will output the base64 representation.

## Algorithm

The program follows a specific algorithm for the conversion:

1. For each set of 3 bytes, the program extracts 4 groups of 6 bits.
2. The 6-bit values are then mapped to base64 characters.
3. The resulting base64 characters are printed as the output.

## How to Compile

Compile the program using a C compiler. For example, using `gcc`:

```bash
gcc -o bitmanip BitManip.c
