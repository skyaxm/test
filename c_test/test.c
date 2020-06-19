#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char buf[32];
    strcpy(buf, "hello");
    char *str = "hello123";
    printf("strlen(buf): %d\n", strlen(buf));
    if(strncmp(buf, str, strlen(str)-3)==0) {
        printf("equal\n");
    }
    char* start = strstr(str, "1o");
    if(start == NULL) {
        printf("start == NULL\n");
    }else{
        printf("%s\n", start);
    }
    return 0;
}
#if 0
void print_buf(char** buf)
{
	printf("%s\n", buf[0]);
}
int main()
{
	char* buf[] = {"cpu", "fpga"};
	char buf1[32] = "123456";
	printf("cnt:%d\n", sizeof(buf)/sizeof(char*));
	print_buf(buf);
	char *tmp = buf1;
	printf("%s\n", tmp);
	return 0;
}
#endif

#if 0
int main()
{
	char *buf[] = {
		"critical",
		"major",
		"minor"
	};

	int i;
	for(i=0; i<3; ++i) {
		printf("%s\n", buf[i]);
	}
	int index;
	printf("%s\n", buf[index]);
	return 0;
}
#endif
