#include "CMyStack.h"
#include "CMyStack.cpp"
#include <iostream>

int main() {
    // Создаем стек для хранения целых чисел
    CMyStack<int> intStack;

    // Добавляем несколько элементов в стек
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    // Выводим верхний элемент стека
    std::cout << "Top element: " << intStack.top() << std::endl;

    // Удаляем верхний элемент стека
    intStack.pop();

    // Выводим верхний элемент после удаления
    std::cout << "Top element after pop: " << intStack.top() << std::endl;

    // Проверяем, пуст ли стек
    if (intStack.is_empty()) {
        std::cout << "Stack is empty." << std::endl;
    }
    else {
        std::cout << "Stack is not empty." << std::endl;
    }

    return 0;
}
