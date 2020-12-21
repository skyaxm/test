#include<stdio.h>

int main()
{
    FILE *fp = fopen("/media/BOOT/boot_flag.txt", "r+");
    char boot_flag = 0x42; //B
    fwrite(&boot_flag, sizeof(boot_flag), 1, fp);
    fclose(fp);

    return 0;
}
