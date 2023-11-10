# 1. Problem

The name of the problem is Two Sum on LeetCode. Please refer to [the link](https://leetcode.com/problems/two-sum/?envType=list&envId=ol6q4f5j).

# 2. Solution

## 2.1. C++

```cpp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var pairs = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++)
            if (pairs.ContainsKey(target - nums[i]))
                return new int [] {pairs[target - nums[i]], i};
            else
                pairs.TryAdd(nums[i], i);
        
        return default;
    }
}
```

## 2.2. C#

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var pairs = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++)
            if (pairs.ContainsKey(target - nums[i]))
                return new int [] {pairs[target - nums[i]], i};
            else
                pairs.TryAdd(nums[i], i);
        
        return default;
    }
}
```

## 2.3. Python3

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i in range(len(nums)):
            hashmap[nums[i]] = i
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashmap and hashmap[complement] != i:
                return [i, hashmap[complement]]
```

