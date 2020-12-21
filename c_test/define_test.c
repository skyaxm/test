#include<stdio.h>
#include<stdlib.h>

#define YUMA_INSTALL "/root/netconf"
//#define YUMA_CONF "/etc/yuma/netconfd.conf"
#define YUMA_CONF YUMA_INSTALL "/yuma/netconfd.conf"


int main()
{
    printf("%s\n", YUMA_CONF);
    return 0;
}
