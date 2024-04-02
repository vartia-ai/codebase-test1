 struct i3p
    {
        int i[3];
        char *p;
        long l;
    };

    void fn_taking_array_of_struct_i3p(struct i3p array_of_i3p[])
    {
        char *p = "spacer";
        return;
    }

    int main(void)
    {
        struct i3p i3p_inst;
        i3p_inst.i[0] = 1;
        i3p_inst.i[1] = 2;
        i3p_inst.i[2] = 3;
        char *i3p_p = "shazbot";
        i3p_inst.p = i3p_p;
        i3p_inst.l = 0xdeadbeef;

        struct i3p i3p_inst2;
        i3p_inst2.i[0] = 4;
        i3p_inst2.i[1] = 5;
        i3p_inst2.i[2] = 6;
        char *i3p_p2 = "bezurb";
        i3p_inst2.p = i3p_p2;
        i3p_inst2.l = 0xfeedface;

        struct i3p array_of_i3p[2];
        array_of_i3p[0] = i3p_inst;
        array_of_i3p[1] = i3p_inst2;

        fn_taking_array_of_struct_i3p(array_of_i3p);
    }