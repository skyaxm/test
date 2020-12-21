#include"main.h"

int global = 20;

str_t var;

static void func()
{
    printf("this is func!\n");
}

int display(str_t *var)
{
    (*var).a = 5;
    strcpy((*var).b, "hello");
    printf("this is display\n");
    func();
    return 0;
}

int main()
{
    test();
    printf("main: %d\n", global);
    return 0;
}
