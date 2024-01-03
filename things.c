// things.c

#include "things.h"

struct private_things_struct
{
    char things[10];
};

void private_things_func(struct private_things_struct unused)
{
    return;
}

global_things_type public_things_func1()
{
    typedef int local_things_type;
    local_things_type ret_val = 5;
    return (global_things_type)ret_val;
}

void public_things_func2()
{
    struct private_things_struct s;
    private_things_func(s);
    return;
}
