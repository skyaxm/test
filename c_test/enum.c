#include<stdio.h>

enum fault_severity
{
	"CRITICAL",
	"MAJOR",
	"MINOR,
	"WARNING
};

char* buf[] = {
	"CRITICAL",
	"MAJOR",
	"MINOR",
	"WARNING"
};

#define ENUM_PRINT(V) buf[V]

int main()
{
	enum fault_severity level;
	level = CRITICAL;
	printf("%d\n", level);
//	printf("%s\n", ENUM_PRINT(level));

	return 0;
}
