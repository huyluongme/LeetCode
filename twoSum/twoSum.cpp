#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(hashTable.find(complement) != hashTable.end()) {
                return {hashTable[complement], i};
            }
            hashTable[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    Solution solution;

    vector<int> nums = {3, 3};
    int target = 6;

    vector<int> res = solution.twoSum(nums, target);

    if(!res.empty())
        cout << "[" << res[0] << ", " << res[1] << "]\n";
    else
        cout << "No solution found\n";
    return 0;
}