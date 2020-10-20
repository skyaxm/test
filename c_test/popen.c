#include<stdio.h>

int main()
{
    char *cmd = "/root/rru-option-8/dpd-mstream.arm -t 0xf -f IQTime_NRFDD_ETM3p1a_CellID1_Payload0_122p88.bin -s IQTime_NRFDD_ETM3p1a_CellID1_Payload0_122p88.bin -x 1 -c &";
    FILE *fp = popen(cmd, "r");
    char buf[128];
    while(fgets(buf, sizeof(buf), fp)){
        printf("%s\n", buf);
    }
    pclose(fp);
    return 0;
}
