#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool* prefixesDivBy5(int* A, int ASize, int* returnSize)
{
    bool* pAnswer = (bool*)malloc(ASize*sizeof(bool));
    *returnSize = ASize;
    int i;
    int res = 0;
    int val;
    for(i=0; i<ASize; ++i){
        val = (res<<1) + A[i];
        if(val>=5){
            res=val-5;
        }else{
            res = val;
        }
        if(res==0){
            pAnswer[i]=true;
        }else{
            pAnswer[i]=false;
        }
    }
    return pAnswer;
}

int main()
{
    int A[]={0, 1, 1};

    int size;
    bool* ret = prefixesDivBy5(A, 3, &size);
    int i;
    for(i=0; i<size; ++i){
        if(ret[i]){
            printf("true ");
        }else{
            printf("false ");
        }
    }
    return 0;
}
