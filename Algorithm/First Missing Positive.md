# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/first-missing-positive/).

# 2. Solution

## 2.1. C++

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<int>> dp(row + 1, std::vector<int>(col + 1, 0));
        
        int max = 0;
        for(int r = 0; r < row; ++r)
            for(int c = 0; c < col; ++c) {
                // The value of dp[r + 1][c + 1] represents the side length of the largest square whose bottom-right corner is at (r, c) in the original matrix.
                if(matrix[r][c] == '1') {
                    dp[r + 1][c + 1] = std::min({dp[r][c], dp[r + 1][c], dp[r][c + 1]}) + 1;
                    max = std::max(max, dp[r + 1][c + 1]);
                }
            }

        return max * max;
    }
};
```

## 2.2. C#

### 2.2.1. Approach One

The worst-case time complexity of this approach be is $O(n^2)$.

```csharp
public class Solution {
    public int FirstMissingPositive(int[] nums) {
        int number = 1;
        HashSet<int> set = new();

        for (int i = 0; i < nums.Length; i++) {
            set.Add(nums[i]);

            if (number == nums[i])
                do 
                    number++;
                while (set.Contains(number));
        }

        return number;
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
    def firstMissingPositive(self, nums: List[int]) -> int:
        count = 1 
        nums = set(nums)
        while count in nums:
            count +=1
        return count
```
