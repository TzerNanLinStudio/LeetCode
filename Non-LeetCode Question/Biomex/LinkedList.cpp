#include "LinkedList.h"

LinkedList::LinkedList() {
    throw std::runtime_error("Default constructor not allowed.");
}

LinkedList::LinkedList(std::string dt, float s, float zp, float m, float sd) :  head(nullptr), tail(nullptr), dataType(dt), scale(s), zeroPoint(zp), mean(m), standardDeviation(sd) {}

void LinkedList::addNode(float value) {
    ListNode* newNode;
    
    // Create a new node based on the data type
    if (dataType == "Int8")
        newNode = new ListNode(quantize(value)); // For Int8, quantize the value
    else if (dataType == "Float32")
        newNode = new ListNode(normalize(value)); // For Float32, normalize the value
    else
        throw std::runtime_error("Error happened.");

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

int8_t LinkedList::quantize(float x) {
    int x_q = std::round(scale * x + zeroPoint);

    // Clamp the quantized value to the range of int8_t
    if (x_q < -128)
        x_q = -128;
    else if (x_q > 127)
        x_q = 127;

    return static_cast<int8_t>(x_q);
}

float LinkedList::normalize(float x) {
    return (x - mean) / standardDeviation;
}

ListNode* LinkedList::getHead() {
    return head;
}

std::string LinkedList::toString() const {
    std::stringstream ss;
    ListNode* current = head;
    while (current != nullptr) {
        ss << current->toString() << " -> ";
        current = current->next;
    }
    ss << "nullptr";
    return ss.str();
}
