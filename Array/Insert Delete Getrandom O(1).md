
# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/insert-delete-getrandom-o1/).

# 2. Solution

## 2.1. C++

```cpp
class RandomizedSet {
public:
    RandomizedSet() {

    }

    /**
     * Inserts a value into the set.
     * @param val The value to insert.
     * @return True if the value was successfully inserted, false if it already exists.
     */
    bool insert(int val) {
        if (valueToIndex.find(val) != valueToIndex.end()) {
            return false; // Value already exists in the set
        }
        
        values.push_back(val); // Add value to the end of the vector
        valueToIndex[val] = values.size() - 1; // Store the value's index in the map
        return true;
    }

    /**
     * Removes a value from the set.
     * @param val The value to remove.
     * @return True if the value was successfully removed, false if it does not exist.
     */
    bool remove(int val) {
        if (valueToIndex.find(val) == valueToIndex.end()) {
            return false; // Value does not exist in the set
        }

        // Overwrite the value to remove with the last value in the vector
        values[valueToIndex[val]] = values[values.size() - 1];
        
        // Update the map to reflect the new index of the last value
        valueToIndex[values[values.size() - 1]] = valueToIndex[val];
        
        // Remove the last value from the vector and erase the value from the map
        values.pop_back();
        valueToIndex.erase(val);
        return true;
    }

    /**
     * Returns a random value from the set.
     * @return A random value from the set.
     */
    int getRandom() {
        return values[rand() % values.size()]; // Return the value at the random index
    }

private:
    std::vector<int> values; // Stores the values in the set
    std::unordered_map<int, int> valueToIndex; // Maps each value to its index in the vector
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```
