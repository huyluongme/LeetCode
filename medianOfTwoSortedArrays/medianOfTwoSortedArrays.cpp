#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return this->findMedianSortedArrays(nums2, nums1);
        
        int nums1Size = nums1.size(), nums2Size = nums2.size();
        int total = nums1Size + nums2Size;
        int leftCount = (total + 1) / 2;
        int low = 0, high = nums1Size;

        while(low <= high) {
            int i = (low + high) / 2;
            int j = leftCount - i;

            int leftA = (i > 0) ? nums1[i - 1] : numeric_limits<int>::min();
            int rightA = (i < nums1Size) ? nums1[i] : numeric_limits<int>::max();
            int leftB = (j > 0) ? nums2[j - 1] : numeric_limits<int>::min();
            int rightB = (j < nums2Size) ? nums2[j] : numeric_limits<int>::max();

            if(leftA <= rightB && leftB <= rightA) {
                if(total % 2 == 1) {
                    return double(max(leftA, leftB));
                }
                else {
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                }
            }
            else if(leftA > rightB) {
                high = i - 1;
            }
            else {
                low = i + 1;
            }
        }

        return 0.0;
    }
};

int main() {
    vector<int> nums1{1, 2}, nums2{3, 4};
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2) << "\n";
    return 0;
}