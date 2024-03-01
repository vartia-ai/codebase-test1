
#include <stdio.h>
#include "complex_types.h"

//function that takes a pointer to a struct as an argument
void print_struct(recursive_struct_type *s, int depth);
void init_struct(recursive_struct_type *s, recursive_struct_type *next, char **data, int data_size);

void print_struct(recursive_struct_type *s, int depth)
{
    if (s == NULL || s->data == NULL || depth >= 10)
    {
        printf("Done\n");
        return;
    }

    for (int i = 0; i < s->data_size; i++){
        if (s->data[i] != NULL){
            printf("%s ", s->data[i]);
        }  
    } 

    if (s->next != NULL && s->next->function_pointer != NULL)
    {
        s->next->function_pointer(s->next, depth + 1);
    }
}

void init_struct(recursive_struct_type *s, recursive_struct_type *next, char **data, int data_size)
{
    s->data = data;
    s->data_size = data_size;
    s->next = next;
    //call the print_struct function
    s->function_pointer = print_struct;
}

void test_struct_trace()
{   
    char *child_data[] = {"Hello", "Child!", NULL};
    recursive_struct_type child;
    init_struct(&child, NULL, child_data, 2);

    recursive_struct_type parent;
    char *parent_data[] = {"Hello", "Parent!", NULL};
    init_struct(&parent, &child, parent_data, 2);
    parent.function_pointer(&parent, 0);
}
