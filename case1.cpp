#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = 0, currentSum = 0;
        unordered_map<int, int> countMap;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                currentSum -= nums[i - k];
                if (--countMap[nums[i - k]] == 0) {
                    countMap.erase(nums[i - k]);
                }
            }
            currentSum += nums[i];
            countMap[nums[i]]++;
            if (i >= k - 1 && countMap.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
        }
        return maxSum;
    }
};


int main(int argc, char const *argv[])
{
    vector <int> tes = {1,2,3,4,5,6,7,8,9};
    Solution solusi;
    long long a =   solusi.maximumSubarraySum(tes,3);  
    return 0;
}
