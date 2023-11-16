#pragma once

#include "ListNode.h"
#include <sstream>
#include <cstdint>
#include <cmath>

class LinkedList {
private:
    // Pointers to the head and tail of the linked list
    ListNode* head;
    ListNode* tail;

    // Indicates the type of data stored in the list (e.g., Int8 or Float32) and ensures all subsequent nodes of the linked list will hold data of the same type
    const std::string dataType;

    // Parameters used for data normalization and quantization
    float scale;
    float zeroPoint;
    float mean;
    float standardDeviation;

    // Private methods for quantization and normalization
    int8_t quantize(float x);
    float normalize(float x);

public:
    // Default constructor
    LinkedList();

    // Constructor with parameters for data type and normalization/quantization parameters
    LinkedList(std::string dt, float s, float zp, float m, float sd);

    // Method to add a new node with a given value
    void addNode(float value);

    // Method to get the head of the list
    ListNode* getHead();

    // Method to get a string representation of the list
    std::string toString() const;
};
