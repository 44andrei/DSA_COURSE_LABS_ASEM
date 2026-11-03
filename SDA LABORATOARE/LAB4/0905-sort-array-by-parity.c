int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            int temp = nums[k];
            nums[k] = nums[i];
            nums[i] = temp;
            k++;
        }
    }
    return nums;
}