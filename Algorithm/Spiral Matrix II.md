# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/spiral-matrix-ii/).

# 2. Solution

## 2.1. C++

This is my initial idea, though it may not be the best approach.

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int index = 1;
        int x = 0; 
        int y = 0;
        int side = 1;
        int topEdge = 1;
        int rightEdge = n - 1;
        int bottomEdge = n - 1;
        int leftEdge = 0;

        while (index <= n * n) {
            matrix[y][x] = index;
            
            switch (side) {
                case 1:              
                    if (x == rightEdge) {
                        y++;
                        rightEdge--;
                        side = 2;    
                    }
                    else {
                        x++;
                    }
                    break;

                case 2:                
                    if (y == bottomEdge) {
                        x--;
                        bottomEdge--;
                        side = 3;
                    }
                    else {
                        y++;
                    }
                    break;
                
                case 3:
                    if (x == leftEdge) {
                        y--;
                        leftEdge++;
                        side = 4;
                    }
                    else {
                        x--;
                    }
                    break;
                
                case 4:
                    if (y == topEdge) {
                        x++;
                        topEdge++;
                        side = 1;
                    }
                    else {
                        y--;
                    }
                    break;
            } 

            index++;
        }

        // for (int i = 0; i < matrix.size(); i++) {
        //     for (int j = 0; j < matrix[i].size(); j++)
        //         cout << matrix[i][j] << " " ;
        //     cout << endl;
        // }

        return  matrix;
    }
}
```
