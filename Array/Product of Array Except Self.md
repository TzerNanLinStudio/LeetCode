# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/product-of-array-except-self/).

# 2. Solution

## 2.1. C++

The time complexity is **O(n)**. The space complexity is **O(n)**.

```cpp
std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    // Result vector to hold the product of elements except itself
    std::vector<int> result(nums.size(), 0);

    // Variables to track the index of a single zero (if any) and the total product
    int zeroIndex = -1; // -1 indicates no zero found
    int totalProduct = 1;

    // Iterate through the array to calculate the total product and identify zeros
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            // If a zero is found, check if it's the first or second zero
            if (zeroIndex == -1) {
                zeroIndex = i; // Mark the first zero's index
            } else {
                zeroIndex = -2; // Mark as invalid if there are multiple zeros
                break; // No need to continue as result will be all zeros
            }
        } else {
            // Multiply non-zero elements to calculate the total product
            totalProduct *= nums[i];
        }
    }

    // Populate the result vector based on the zeroIndex
    if (zeroIndex == -1) {
        // No zero in the input, compute result normally
        for (int i = 0; i < nums.size(); i++) {
            result[i] = totalProduct / nums[i];
        }
    } else if (zeroIndex >= 0) {
        // Single zero in the input, only one non-zero product exists
        result[zeroIndex] = totalProduct;
    }

    // If there are multiple zeros, the result vector remains all zeros
    return result;
}
```
