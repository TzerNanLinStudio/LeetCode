# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/two-sum/?envType=list&envId=ol6q4f5j).

# 2. Solution

There are three versions in different programming language.

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

### 2.2.1. Method One

O(m×n)

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

### 2.2.2. Method Two

This method is not good enough. It can pass some testcase but will exceed Time Limit if input is too complex. Between \( O(n^4) \) to \( O(n^5) \)


$$
O(n^2m^2)
$$

```csharp
public class Solution {
    public int MaximalSquare(char[][] matrix) {
        int max_length = matrix.Length > matrix[0].Length ? matrix[0].Length : matrix.Length;
        for (int i = max_length; i > 0; i--) 
            for (int j = 0; j + i <= matrix.Length; j++)
                for (int k = 0; k + i <= matrix[0].Length; k++)
                    if (CheckValue(matrix, j, k, i))
                        return i * i;
        return 0;
    }

    public bool CheckValue(char[][] matrix, int x, int y, int length) {
        for (int i = 0; i < length; i++)
            for (int j = 0; j < length; j++)
                if (matrix[x + i][y + j] == '0')
                    return false;
        return true;
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
