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
        int number = 0;
        char[] charArray = s.ToCharArray();

        for (int i = charArray.Length - 1; i >= 0; i--)
        {
            switch (charArray[i])
            {
                case 'I':
                    number += 1;           
                    break;
                case 'V':
                    if (i > 0 && charArray[i - 1] == 'I')
                    {
                        number += 4;  
                        i--;                
                    }
                    else
                    {
                        number += 5;
                    }  
                    break;
                case 'X':
                    if (i > 0 && charArray[i - 1] == 'I')
                    {
                        number += 9;  
                        i--;                 
                    }
                    else
                    {
                        number += 10;
                    }  
                    break;
                case 'L':
                    if (i > 0 && charArray[i - 1] == 'X')
                    {
                        number += 40;      
                        i--;            
                    }
                    else
                    {
                        number += 50;
                    }  
                    break;
                case 'C':
                    if (i > 0 && charArray[i - 1] == 'X')
                    {
                        number += 90;    
                        i--;               
                    }
                    else
                    {
                        number += 100;
                    }  
                    break;
                case 'D':
                    if (i > 0 && charArray[i - 1] == 'C')
                    {
                        number += 400;  
                        i--;                
                    }
                    else
                    {
                        number += 500;
                    }  
                    break;   
                case 'M':
                    if (i > 0 && charArray[i - 1] == 'C')
                    {
                        number += 900;      
                        i--;            
                    }
                    else
                    {
                        number += 1000;
                    }  
                    break;
                default:
                    break;
            }
        }

        return number;
    }
}
```

### 2.3.2. Approach Two

```csharp

```

## 2.4. Python3

```python

```
