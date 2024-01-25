// main.c
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "stuff.h"
#include "things.h"

char* hexstring_to_buffer(const char* hexstring) {
    size_t len = strlen(hexstring);
    size_t buffer_len = len / 2;
    char* buffer = malloc(buffer_len + 1);
    
    for (size_t i = 0; i < buffer_len; i++) {
        sscanf(hexstring + 2 * i, "%2hhx", &buffer[i]);
    }
    
    buffer[buffer_len] = '\0';
    return buffer;
}

// Used to test printig the the data passed into functions
void data_function(char *data, uint8_t len);

// Single line prototype for one-line function. Prototype should not be included itself as a function in 
// code_extraction.py.
float one_line_func(float x);

// Two line prototype for a two-line function. Prototype should not be included itself as a function in 
// code_extraction.py. 
float two_line_func(
    float x
);

int main() 
{
    public_stuff_func1();
    public_stuff_func2();
    public_things_func1();
    public_things_func2();
    float r1 = one_line_func(4.0);
    float r2 = two_line_func(5.0);
    printf("r1=%f, r2=%f\n", r1, r2);
    const char* hexstring = "DEADBEEF1234"; // Hex representation of "Hello World"
    char* buffer = hexstring_to_buffer(hexstring);
    uint8_t len = strlen(buffer);
    data_function(buffer, len);
    free(buffer);

    return 0;
}

// Single line function. This should be included as a function in code_extraction.py.
float one_line_func(float x) { return x; }

// Two line function. This should be included as a function in code_extraction.py.
float two_line_func(
    float x) { return one_line_func(x); };

void data_function(char *data, uint8_t len) {
    printf("data_function: %s\n", data);
    for (float i=0; i<10; i++) {
        one_line_func(i);
    }
    for (float i=0; i<10; i++) {
        two_line_func(i);
    }
}