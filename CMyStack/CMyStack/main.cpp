#include "CMyStack.hpp"
#include <iostream>

int main() {
    CMyStack<int> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    std::cout << "Top element: " << intStack.top() << std::endl;

    intStack.pop();

    std::cout << "Top element after pop: " << intStack.top() << std::endl;

    if (intStack.is_empty()) {
        std::cout << "Stack is empty." << std::endl;
    }
    else {
        std::cout << "Stack is not empty." << std::endl;
    }

    return 0;
}
