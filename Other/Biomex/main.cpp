#include "LinkedList.h"
#include <iostream>

int main() {
    // Create a LinkedList object with Int8 data type and arbitrary normalization parameters
    LinkedList list("Int8", 11.0, 22.0, 0.0, 0.0);

    // Add several arbitrary float values to the list. These will be quantized based on the list's parameters.
    list.addNode(-150.0f);
    list.addNode(-10.0f);
    list.addNode(150.0f);
    list.addNode(1000.0f);
    list.addNode(150000.0f);

    // Print the string representation of the entire list to the console
    std::cout << list.toString() << std::endl;

    return 0;
}
