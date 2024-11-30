
# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/insert-delete-getrandom-o1/).

# 2. Solution

## 2.1. C++

```cpp
class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(0)); // Seed the random number generator once
    }

    bool insert(int val) {
        if (valueIndexMap.find(val) != valueIndexMap.end()) {
            return false; // Value already exists
        }
        numbers.push_back(val);
        valueIndexMap[val] = numbers.size() - 1; // Store index in the map
        return true;
    }

    bool remove(int val) {
        if (valueIndexMap.find(val) == valueIndexMap.end()) {
            return false; // Value does not exist
        }
        int index = valueIndexMap[val]; // Get the index of the value
        int lastValue = numbers.back(); // Get the last value in the vector

        // Swap the value to remove with the last value
        numbers[index] = lastValue;
        valueIndexMap[lastValue] = index; // Update the index of the swapped value

        numbers.pop_back(); // Remove the last element
        valueIndexMap.erase(val); // Erase the value from the map

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % numbers.size(); // Get a random index
        return numbers[randomIndex];
    }

private:
    std::vector<int> numbers; // Stores the elements
    std::unordered_map<int, int> valueIndexMap; // Maps values to their indices
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```
