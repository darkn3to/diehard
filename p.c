#include <stdio.h>
void removeDuplicates(int* nums, int numsSize) {
    int k=0;
    for (int i=1; i<numsSize; i++) if (nums[k]!=nums[i]) nums[++k]=nums[i];
    printf("%d", k);
}
void main() {
    int arr[]={0, 0, 1, 2, 2, 2, 3, 4};
    removeDuplicates(arr, sizeof(arr));
}