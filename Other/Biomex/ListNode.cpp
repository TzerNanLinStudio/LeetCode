#include "ListNode.h"

ListNode::ListNode() {
    throw std::runtime_error("Default constructor not allowed.");
}

ListNode::ListNode(int8_t value) : dataType("Int8"), next(nullptr) {
    data.int8Value = value;
}

ListNode::ListNode(float value) : dataType("Float32"), next(nullptr) {
    data.floatValue = value;
}

std::string ListNode::toString() const {
    std::stringstream ss;
    if (dataType == "Int8") 
        ss << static_cast<int>(data.int8Value);
    else if (dataType == "Float32")
        ss << data.floatValue;
    else
        throw std::runtime_error("Error happened.");
    return ss.str();
}
