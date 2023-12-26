# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/first-missing-positive/).

# 2. Solution

## 2.1. C

The time complexity of this approach is $O(n)$. 

```c
int firstMissingPositive(int* nums, int size) {
    int* rank = (int*)calloc(size, 4); // Allocate memory for an array 'rank' of size 'size' using calloc, initializing all elements to 0. Each element is of size 4 bytes (size of an int).
    for (int i = 0; i < size; i++)
        if (nums[i] <= size && nums[i] > 0)
            rank[nums[i] - 1] = nums[i];
    for (int i = 0; i < size; i++)
        if (rank[i] == 0)
            return i + 1;
    return size + 1;
}
```

## 2.2. C++

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> hashArray(n, false);
        for (int num : nums)
            if (1 <= num && num <= n)
                hashArray[num - 1] = true;
        for (int i = 0; i < n; i++)
            if (!hashArray[i])
                return i + 1;
        return n + 1;
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
