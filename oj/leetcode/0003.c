#include<stdio.h>
#include<stdlib.h>

//solution 1
double func(int* nums1, int left1, int right1, int* nums2, int left2, int right2, int k)
{
    int len1=right1-left1+1;
    int len2=right2-left2+1;
    if(len1>len2){
        return func(nums2, left2, right2, nums1, left1, right1, k);
    }
    if(len1 == 0){
        return nums2[left2+k-1];
    }
    if(k==1){
        return nums1[left1+k-1]>nums2[left2+k-1]?nums2[left2+k-1]:nums1[left1+k-1];
    }
    int i = len1>k/2?(left1+k/2-1):right1;
    int j = len2>k/2?(left2+k/2-1):right2;
    if(nums1[i]<nums2[j]){
        return func(nums1, i+1, right1, nums2, left2, right2, k-(i-left1+1));
    }else{
        return func(nums1, left1, right1, nums2, j+1, right2, k-(j-left2+1));
    }
}

double findMedianSortedArrays1(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int len = nums1Size + nums2Size;
    int k1 = (nums1Size+nums2Size+1)/2;
    int k2 = (nums1Size+nums2Size+2)/2;
    return (func(nums1, 0, nums1Size-1, nums2, 0, nums2Size-1, k1)+
            func(nums1, 0, nums1Size-1, nums2, 0, nums2Size-1, k2))*0.5;
}

//solution 2
double findMedianSortedArrays2(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
     int m = nums1Size;
     int n = nums2Size;
     if(m>n){
         return findMedianSortedArrays2(nums2, n, nums1, m);
     }
     int iMin=0, iMax=m;
     while(iMin<=iMax){
         int i = (iMin+iMax)/2;
         int j = (m+n+1)/2-i;
         if(i!=m && j!=0 && nums1[i]<nums2[j-1]){
             iMin=i+1;
         }else if(i!=0 && j!=n && nums1[i-1]>nums2[j]){
             iMax=i-1;
         }else{
             int maxLeft = 0;
             if(i==0){
                 maxLeft = nums2[j-1];
             }else if(j==0){
                maxLeft = nums1[i-1];
             }else{
                 maxLeft = nums1[i-1]>nums2[j-1]?nums1[i-1]:nums2[j-1];
             }
             if((m+n)%2 == 1){
                 return maxLeft;
             }

             int minRight = 0;
             if(i==m){
                minRight = nums2[j];
             }else if(j==n){
                minRight = nums1[i];
             }else{
                 minRight = nums1[i]<nums2[j]?nums1[i]:nums2[j];
             }
             return (maxLeft+minRight)*0.5;
         }
     }
     return 0.0;
}

int main()
{
    //case 1
    //int nums1[]={};
    //int nums2[]={1,2,3,4,5};

    int nums1[]={1,3};
    int nums2[]={2};
    double ret = findMedianSortedArrays2(nums1, 2, nums2, 1);
    printf("ret:%lf\n", ret);
    return 0;
}
