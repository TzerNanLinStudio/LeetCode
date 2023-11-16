#pragma once

#include <iostream>
#include <sstream>
#include <cstdint>

class ListNode {
public:
    // Union to store either an int8_t or a float value
    union {
        int8_t int8Value;
        float floatValue;
    } data;

    // String to store the data type (Int8 or Float32)
    std::string dataType;

    // Pointer to the next node in the linked list
    ListNode* next;

    // Default constructor
    ListNode();

    // Constructor for int8_t values
    ListNode(int8_t value);

    // Constructor for float values
    ListNode(float value);

    // Method to get a string representation of the node
    std::string toString() const;
};
