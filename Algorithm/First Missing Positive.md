# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/first-missing-positive/).

# 2. Solution

## 2.1. C

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool checkTree(struct TreeNode* L, struct TreeNode* R);

bool isSymmetric(struct TreeNode* root){
    return checkTree(root->left, root->right);
}

bool checkTree(struct TreeNode* L, struct TreeNode* R){
    if (L == NULL && R == NULL)
        return true;
    if (L == NULL || R == NULL)
        return false;
    if (L->val == R->val)
        return true && checkTree(L->right, R->left) && checkTree(L->left, R->right);
    else
        return false;    
}
```

## 2.2. C++

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

## 2.3. C#

### 2.3.1. Approach One

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

### 2.3.2. Approach Two

Sorting the array is $O(n * log(n))$. Iterating through the sorted array is $O(n)$. The dominant factor for time complexity is indeed the sorting step, which is $O(n * log(n))$.

```csharp
public class Solution {
    public int FirstMissingPositive(int[] nums) {
        int smallest = 1;
        Array.Sort(nums);

        foreach (int num in nums) {
            if (smallest == num)
                smallest++;
        }

        return smallest;
    }
}
```

## 2.4. Python3

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums = set(nums)
        smallest = 1
        while smallest in nums:
            smallest+=1
        return smallest
```
