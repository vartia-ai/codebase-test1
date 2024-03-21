// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header_func.h"
#include "stuff.h"
#include "things.h"
#include "complex_types.h"

#include <sanitizer/asan_interface.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

size_t vasan_buffer_size(void* buffer);
char* vasan_buffer_hex_string(void* buffer);
void vasan_free_saved_buffer(void* saved_buffer);
void* vasan_save_buffer_copy(void *buffer);

size_t vasan_buffer_size(void* buffer) {
    char* name = NULL;
    size_t name_size = 0;
    void* region_address = NULL;
    size_t region_size = 0;

    const void* alloc_info = __asan_locate_address(buffer, name, name_size, &region_address, &region_size);
    if (alloc_info) {
        
        // Check if a region is poisoned
        void* poisoned_byte = __asan_region_is_poisoned(buffer, region_size);
        
        if (poisoned_byte) {
            return poisoned_byte - buffer;
        } else {
            return region_size;
        }
    }

    assert(0 && "Failed to locate buffer");
    return 0;
}

char* vasan_buffer_hex_string(void* buffer) {
    size_t size = vasan_buffer_size(buffer);
    if (size == -1) {
        return NULL;
    }

    const unsigned char* bytes = (const unsigned char*)buffer;
    char* hex_string = (char*)malloc((size * 2) + 1);
    if (hex_string == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < size; i++) {
        snprintf(hex_string + (i * 2), 3, "%02x", bytes[i]);
    }
    hex_string[size * 2] = 0;

    return hex_string;
}

void vasan_free_saved_buffer(void* saved_buffer) {
    free(saved_buffer);
}

void* vasan_save_buffer_copy(void *buffer) {
    size_t size = vasan_buffer_size(buffer);
    if (size == -1) {
        return NULL;
    }

    void* copy = malloc(size);
    if (copy == NULL) {
        return NULL;
    }

    memcpy(copy, buffer, size);
    return copy;
}


typedef unsigned int uint_t;

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
void data_function(char *data, uint_t len);

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
    const char* hexstring = "8048656C6C6F20576F726C64"; // Hex representation of "Hello World" but with an invalid starting byte
    char* buffer = hexstring_to_buffer(hexstring);
    uint_t len = strlen(buffer);
    data_function(buffer, len);
    free(buffer);
    test_struct_trace();
    return 0;
}

// Single line function. This should be included as a function in code_extraction.py.
float one_line_func(float x) { return x; }

// Two line function. This should be included as a function in code_extraction.py.
float two_line_func(
    float x) { return one_line_func(x); };

void data_function(char *data, uint_t len) {
    printf("data_function: %s\n", data);
    for (float i=0; i<10; i++) {
        one_line_func(i);
    }
    for (float i=0; i<10; i++) {
        two_line_func(i);
    }
}
