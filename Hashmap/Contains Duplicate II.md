# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link]https://leetcode.com/problems/contains-duplicate-ii/).

# 2. Solution

## 2.1. C++

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
      
        for(int i = 0; i < nums.size(); i++){
            // mp.count() will tell whatever ith index that I want, have I seen it before?
            if(mp.count(nums[i])) 
                // if I have already seen this number, then check for condition abs(i - j) <= k
                if (i - mp[nums[i]] <= k)
                    return true;

            // if I have not seen this number before, insert the number with its position in the map and if the number is already present in the map, then update the position of that number
            mp[nums[i]] = i;
        }

        // after the complete traversal, if we don't find a pair to satisfy the condition, return false
        return false;
    }
};
```
