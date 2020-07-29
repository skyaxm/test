#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buf[32];
    strcpy(buf, "array copy");
    const char *str = buf;
    puts(buf);
    puts(str);
    return 0;
}
#if 0
char *str[] = {"call_home.log", "netconfd_debug.log", "netconfd.log", ""};

int main()
{
    int i=0;
    while(strcmp(str[i], "")){
        printf("%s\n", str[i++]);
    }

    return 0;
}
#endif
