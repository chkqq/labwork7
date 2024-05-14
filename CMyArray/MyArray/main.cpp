#include <iostream>
#include <string>
#include "CMyArray.h"
#include "CMyArray.cpp"

int main() 
{
    CMyArray<std::string> stringArray;

    stringArray.Add("Hello");
    stringArray.Add("World");
    stringArray.Add("!");

    std::cout << "String array:" << std::endl;
    for (const auto& str : stringArray) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    // Демонстрация работы с массивом чисел с плавающей запятой (double)
    CMyArray<double> doubleArray;

    doubleArray.Add(3.14);
    doubleArray.Add(2.71);
    doubleArray.Add(1.62);

    std::cout << "Double array:" << std::endl;
    for (const auto& num : doubleArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Демонстрация изменения размера массива
    doubleArray.Resize(5);
    doubleArray[3] = 4.0;
    doubleArray[4] = 5.0;

    std::cout << "Resized double array:" << std::endl;
    for (const auto& num : doubleArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Демонстрация очистки массива
    stringArray.Clear();
    std::cout << "String array size after clear: " << stringArray.Size() << std::endl;

    return 0;
}
