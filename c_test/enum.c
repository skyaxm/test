#include<stdio.h>

typedef enum fault_severity
{
	CRITICAL,
	MAJOR,
	MINOR,
	WARNING
}fault_severity_t;

char* buf[] = {
	"CRITICAL",
	"MAJOR",
	"MINOR",
	"WARNING"
};

#define ENUM_PRINT(V) buf[V]

void display(fault_severity_t arg)
{
    fault_severity_t a = arg;
	printf("%s\n", ENUM_PRINT(a));

    return;
}

int main()
{
	fault_severity_t level;
	level = 3;
	printf("%d\n", level);
	//printf("%s\n", ENUM_PRINT(level));
    display(3);
	return 0;
}
