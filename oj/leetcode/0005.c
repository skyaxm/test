#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#if 1 //暴力解法
int isPalindrome(char *s, int start, int end)
{
    int i, j;
    for(i=start, j=end; i<j; ++i, --j){
        if(s[i]!=s[j]){
            return 0;
        }
    }
    return 1;
}

char * longestPalindrome0(char * s)
{
    int len = strlen(s);
    int left=0, right=0;
    int i;
    int max = 0;
    for(i=0; i<len; ++i){
        int j = len-1;
        while(j>=i){
            if(s[j]==s[i]){
                if(isPalindrome(s, i, j)){
                    if(max<(j-i+1)){
                        max=j-i+1;
                        left = i;
                        right = j;
                    }
                }
            }
            j--;
        }
    }
    char *str = (char*)malloc(right-left+2);
    strncpy(str, s+left, right-left+1);
    str[right-left+1]='\0';
    return str;
}
#endif

//动态规划
char * longestPalindrome1(char * s)
{
    int len = strlen(s);
    int dp[len][len];
    memset(dp, 0, sizeof(len*len));
    int i;
    for(i=0; i<len; ++i){
        dp[i][i] = 1;
    }
    int j;
    int max = 1;
    int begin = 0;
    for(j=1; j<len; ++j){
        for(i=0; i<j; ++i){
            if(s[i]==s[j]){
                if(j-i>=3){
                    dp[i][j] = dp[i+1][j-1];
                }else{
                    dp[i][j] = 1;
                }
            }else{
                dp[i][j] = 0;
            }
            if(dp[i][j]&&(j-i+1)>max){
                max = j-i+1;
                begin = i;
            }
        }
    }
    char *ans = (char*)malloc(max+1);
    strncpy(ans, s+begin, max);
    ans[max+1]='\0';
    return ans;
}

//中心扩散法
int centerSpread(char *s, int start, int end)
{
    int len = strlen(s);
    int i = start;
    int j = end;
    while (i>=0 && j<len) {
        if (s[i] ==s [j]) {
            i--;
            j++;
        } else {
            break;
        }
    }
    return j-(i+1);//(j-1)-(i+1)+1
}

char * longestPalindrome2(char * s)
{
    int len = strlen(s);
    if(len<2){
        return s;
    }
    int i;
    int max = 0;
    int start = 0;
    for (i=0; i<len-1; ++i) {
        int odd = centerSpread(s, i, i);
        int even = centerSpread(s, i, i+1);
        int tmp = odd>even?odd:even;
        if (tmp > max) {
            max = tmp;
            start = i-(max-1)/2;
        }
    }
    char *ans = (char*)malloc(max+1);
    strncpy(ans, s + start, max);
    ans[max] = '\0';
    return ans;
}

int main()
{
    //char *s = "babad";
    //char *s = "cbbd";
    //char *s = "a";
    char *s = "aacabdkacaa";
    char *ans=longestPalindrome2(s);
    printf("%s\n", ans);

    return 0;
}
