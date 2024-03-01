
struct recursive_struct; //forward declaration.

//function pointer type
typedef void (*function_pointer_type)(struct recursive_struct *, int);

//Struct type with a pointer to itself
struct recursive_struct
{
    char **data;
    int data_size;
    struct recursive_struct *next;
    // function pointer type
    function_pointer_type function_pointer;

};
typedef struct recursive_struct recursive_struct_type;

void test_struct_trace();
