// main.c

#include <stdio.h>

#include "stuff.h"
#include "things.h"

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
    return 0;
}

// Single line function. This should be included as a function in code_extraction.py.
float one_line_func(float x) { return x; }

// Two line function. This should be included as a function in code_extraction.py.
float two_line_func(
    float x) { return x; };
