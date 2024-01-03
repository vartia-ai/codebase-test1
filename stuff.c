// stuff.c

#include "stuff.h"

struct private_stuff_struct
{
    char stuff[10];
};

void private_stuff_func(struct private_stuff_struct unused)
{
    return;
}

global_stuff_type public_stuff_func1()
{
    typedef int local_stuff_type;
    local_stuff_type ret_val = 5;
    return (global_stuff_type)ret_val;
}

void public_stuff_func2()
{
    struct private_stuff_struct s;
    private_stuff_func(s);
    return;
}
