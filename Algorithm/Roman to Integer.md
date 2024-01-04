# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/roman-to-integer/).

# 2. Solution

## 2.1. C

The time complexity of this approach is $O(n)$. 

```c

```

## 2.2. C++

```cpp
class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int answer = 0;
        int previous = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            int current = roman[s[i]];

            if (current < previous)
                answer -= current;
            else
                answer += current;

            previous = current;
        }

        return answer;
    }
};
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
public class Solution 
{
    public int RomanToInt(string s) 
    {
        int answer = 0, number = 0;

        for (int i = s.Length - 1; i >= 0; i--)
        {
            switch (s[i]) 
            {
                case 'I': number = 1; break;
                case 'V': number = 5; break;
                case 'X': number = 10; break;
                case 'L': number = 50; break;
                case 'C': number = 100; break;
                case 'D': number = 500; break;
                case 'M': number = 1000; break;
            }

            if (4 * number < answer) answer -= number;
            else answer += number;
        }

        return answer;
    }
}
```

## 2.4. Python3

```python

```
