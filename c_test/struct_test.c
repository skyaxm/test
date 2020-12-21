#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct TAG_affect_objects{
    int num;
    char val[255];
}affected_objects_t;

affected_objects_t affected_obj[] = {
    {0, ""},
    {2, "rhub board"},
    {1, "rru"},
    {3, "ad9544 pa ad9528"},
    {0, ""}
};

char *objects[10];

void init_objects(affected_objects_t *obj)
{
    char *tmp = obj->val;
    char buf[255];
    for(int i = 0; i<obj->num; ++i){
        sscanf(tmp, "%s", buf);
        tmp += strlen(buf);
        //printf("%s\n", buf);
        char *ptr = (char*)malloc(32);
        strcpy(ptr, buf);
        objects[i] = ptr;
    }
}

void print(char **obj)
{
    printf("%s %s\n", obj[0], obj[1]);
}
int main()
{
    //printf("affect objects: %d %s\n", obj[1].num, "hello");
    int i;

    init_objects(&affected_obj[1]);
    print(objects);
    //char *buf[] ={"buf" ,"hello"};
    //printf("%s %s\n", (char**)buf[0], (char**)buf[1]);
    return 0;
}
