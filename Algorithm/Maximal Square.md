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

### 2.2.1. Approach One

This approach is less efficient because it repeatedly checks each potential square without leveraging any prior computations, leading to a large number of redundant operations, especially on larger matrices. The time complexity is $O(n^2m^2)$.

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

### 2.2.2. Approach Two

This approach chooses _Dynamic Programming_. The time complexity is $O(nm)$.

```csharp
public class Solution {
    int[,] dp;

    public int MaximalSquare(char[][] matrix) {
        int row = matrix.Length;
        int col = matrix[0].Length;
        dp = new int[row + 1, col + 1];
        return MaxArea(matrix, row, col);
    }

    public int MaxArea(char[][] matrix, int row, int col) {
        int max = 0;
        for(int r = 0; r < row; r++)
            for(int c = 0; c < col; c++){
                // The value of dp[r + 1, c + 1] represents the side length of the largest square whose bottom-right corner is at (r, c) in the original matrix.
                if(matrix[r][c] =='1') 
                    dp[r + 1, c + 1] = Math.Min(dp[r, c], Math.Min(dp[r + 1, c], dp[r , c + 1])) + 1;
                else 
                    dp[r + 1, c + 1] = 0;
                max = Math.Max(max, dp[r + 1, c + 1]);
            }
        return max * max;
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
