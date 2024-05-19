#include <iostream>
#include "CWorker.h"
#include "CStudent.h"
#include "CAdvancedStudent.h"

int main() 
{
    CWorker worker;
    worker.SetFirstName("John");
    worker.SetLastName("Doe");
    worker.SetMiddleName("A.");
    worker.SetAddress("1234 Elm Street");
    worker.SetSpecialty("Carpenter");

    std::cout << "Worker: " << worker.GetFirstName() << " " << worker.GetLastName() << ", Specialty: " << worker.GetSpecialty() << std::endl;

    CStudent student;
    student.SetFirstName("Jane");
    student.SetLastName("Smith");
    student.SetMiddleName("B.");
    student.SetAddress("5678 Oak Street");
    student.SetUniversity("MIT");
    student.SetStudentID("123456");

    std::cout << "Student: " << student.GetFirstName() << " " << student.GetLastName() << ", University: " << student.GetUniversity() << ", Student ID: " << student.GetStudentID() << std::endl;

    CAdvancedStudent advancedStudent;
    advancedStudent.SetFirstName("Alice");
    advancedStudent.SetLastName("Johnson");
    advancedStudent.SetMiddleName("C.");
    advancedStudent.SetAddress("9101 Pine Street");
    advancedStudent.SetUniversity("Harvard");
    advancedStudent.SetStudentID("789012");
    advancedStudent.SetDissertationTopic("Quantum Computing");

    std::cout << "Advanced Student: " << advancedStudent.GetFirstName() << " " << advancedStudent.GetLastName() << ", University: " << advancedStudent.GetUniversity() << ", Student ID: " << advancedStudent.GetStudentID() << ", Dissertation Topic: " << advancedStudent.GetDissertationTopic() << std::endl;

    return 0;
}
