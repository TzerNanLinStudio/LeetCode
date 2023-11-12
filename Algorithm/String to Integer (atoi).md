# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/string-to-integer-atoi/description/).

# 2. Solution

## 2.1. C++

```cpp
class Solution {
public:
    int myAtoi(string s) {
        /*
        (1) In C++, when accessing elements beyond the end of a standard string (std::string), it typically does not throw an exception (unlike C#)
        (2) INT_MAX = 2,147,483,647 and INT_MIN = -2,147,483,648
        */

        int index = 0;
        while (index < s.size() && s[index] == ' ') 
            index++;

        int sign = 1;
        if (s[index] == '-' || s[index] == '+') { 
            if (s[index] == '-')
                sign = -1;
            index++;
        }

        int number = 0;
        while (index < s.size() && isdigit(s[index])) {
            if (number > INT_MAX / 10 || (number == INT_MAX / 10 && s[index] - '0' > 7))
                return (sign == -1) ? INT_MIN : INT_MAX; 
            number = number * 10 + (s[index] - '0');
            index++;
        }

        std::cout << "The answer is " << number * sign;
        return number * sign;
    }
};
```

## 2.2. C#

```csharp
public class Solution {
    public int MyAtoi(string s) {
        int index = 0;
        while (index < s.Length && s[index] == ' ')
            index++;

        int sign = 1;
        if (index < s.Length && (s[index] == '-' || s[index] == '+')) {
            if (s[index] == '-')
                sign = -1;
            index++;
        }

        int number = 0;
        while (index < s.Length && Char.IsDigit(s[index])) {
            if (number > Int32.MaxValue / 10 || (number == Int32.MaxValue / 10 && s[index] - '0' > 7))
                return (sign == -1) ? Int32.MinValue : Int32.MaxValue;
            number = number * 10 + (s[index] - '0');
            index++;
        }

        Console.WriteLine("The answer is " + sign * number);
        return sign * number;
    }
}
```

## 2.3. Python3

```python
class Solution:
    def myAtoi(self, s: str) -> int:
        index = 0
        while index < len(s) and s[index] == ' ':
            index += 1

        sign = 1
        if index < len(s) and (s[index] == '-' or s[index] == '+'):
            if s[index] == '-':
                sign = -1
            index += 1

        number = 0
        while index < len(s) and s[index].isdigit():
            if number > (2**31 - 1) // 10 or (number == (2**31 - 1) // 10 and int(s[index]) > 7):
                return -2**31 if sign == -1 else 2**31 - 1
            number = number * 10 + int(s[index])
            index += 1

        print("The answer is ", number * sign)
        return number * sign
```
