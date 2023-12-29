# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/roman-to-integer/).

# 2. Solution

## 2.1. C

The time complexity of this approach is $O(n)$. 

```c

```

## 2.2. C++

```cpp

```

## 2.3. C#

### 2.3.1. Approach One

```csharp
public class Solution 
{
    public int RomanToInt(string s) 
    {
        int answer = 0;
        char[] char_array = s.ToCharArray();

        for (int i = char_array.Length - 1; i >= 0; i--)
            switch (char_array[i])
            {
                case 'I':
                    answer += 1;           
                    break;
                case 'V':
                    if (i > 0 && char_array[i - 1] == 'I')
                    {
                        answer += 4;  
                        i--;                
                    }
                    else
                        answer += 5;
                    break;
                case 'X':
                    if (i > 0 && char_array[i - 1] == 'I')
                    {
                        answer += 9;  
                        i--;                 
                    }
                    else
                        answer += 10;
                    break;
                case 'L':
                    if (i > 0 && char_array[i - 1] == 'X')
                    {
                        answer += 40;      
                        i--;            
                    }
                    else
                        answer += 50;
                    break;
                case 'C':
                    if (i > 0 && char_array[i - 1] == 'X')
                    {
                        answer += 90;    
                        i--;               
                    }
                    else
                        answer += 100;
                    break;
                case 'D':
                    if (i > 0 && char_array[i - 1] == 'C')
                    {
                        answer += 400;  
                        i--;                
                    }
                    else
                        answer += 500;
                    break;   
                case 'M':
                    if (i > 0 && char_array[i - 1] == 'C')
                    {
                        answer += 900;      
                        i--;            
                    }
                    else
                        answer += 1000;
                    break;
                default:
                    break;
            }

        return answer;
    }
}
```

### 2.3.2. Approach Two

```csharp

```

## 2.4. Python3

```python

```
