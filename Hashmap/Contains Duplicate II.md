# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link]https://leetcode.com/problems/contains-duplicate-ii/).

# 2. Solution

## 2.1. C++

The time complexity is **O(n)** because each element is inserted and looked up in the unordered map at most once, and both insertion and lookup operations have an average time complexity of **O(1)**.

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;  // Map to store the element and its last seen index
      
        for(int i = 0; i < nums.size(); i++){ 
            if(mp.count(nums[i])) // Check if the current element exists in the map
                if (i - mp[nums[i]] <= k) // If found, check if the difference between indices is <= k
                    return true;

            mp[nums[i]] = i; // Update the index of the current element in the map
        }

        return false; // Return false if no valid pair was found
    }
};
```
