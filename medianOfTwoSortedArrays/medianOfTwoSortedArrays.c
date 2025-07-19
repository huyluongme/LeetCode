#include <stdio.h>
#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int total = nums1Size + nums2Size;
    int leftCount = (total + 1) / 2;
    int low = 0, high = nums1Size;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = leftCount - i;

        int leftA  = (i > 0) ? nums1[i - 1] : INT_MIN;
        int rightA = (i < nums1Size) ? nums1[i] : INT_MAX;
        int leftB  = (j > 0) ? nums2[j - 1] : INT_MIN;
        int rightB = (j < nums2Size) ? nums2[j] : INT_MAX;

        if (leftA <= rightB && leftB <= rightA) {
            if (total % 2 == 1) {
                return (double)(leftA > leftB ? leftA : leftB);
            } else {
                int maxLeft = (leftA > leftB ? leftA : leftB);
                int minRight = (rightA < rightB ? rightA : rightB);
                return (maxLeft + minRight) / 2.0;
            }
        } else if (leftA > rightB) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }

    return 0.0;
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    double res = findMedianSortedArrays(nums1, 2, nums2, 1);
    printf("Median = %.5f\n", res);

    int nums3[] = {1, 2};
    int nums4[] = {3, 4};
    printf("Median = %.5f\n", findMedianSortedArrays(nums3, 2, nums4, 2));

    return 0;
}