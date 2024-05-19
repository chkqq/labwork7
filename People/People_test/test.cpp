#include "pch.h"
#include "../../People/People/CAdvancedStudent.h"
#include "../../People/People/CPersonImpl.h"
#include "../../People/People/CStudent.h"
#include "../../People/People/CStudentImpl.h"
#include "../../People/People/CWorker.h"

class TestPerson : public ::testing::Test 
{
protected:
    CPersonImpl<IPerson> person;
};

TEST_F(TestPerson, FirstName)
{
    person.SetFirstName("John");
    EXPECT_EQ(person.GetFirstName(), "John");
}

TEST_F(TestPerson, LastName)
{
    person.SetLastName("Doe");
    EXPECT_EQ(person.GetLastName(), "Doe");
}

TEST_F(TestPerson, MiddleName) 
{
    person.SetMiddleName("A.");
    EXPECT_EQ(person.GetMiddleName(), "A.");
}

TEST_F(TestPerson, Address) 
{
    person.SetAddress("1234 Elm Street");
    EXPECT_EQ(person.GetAddress(), "1234 Elm Street");
}

class TestStudent : public ::testing::Test
{
protected:
    CStudentImpl<IStudent> student;
};

TEST_F(TestStudent, FirstName) 
{
    student.SetFirstName("Jane");
    EXPECT_EQ(student.GetFirstName(), "Jane");
}

TEST_F(TestStudent, LastName)
{
    student.SetLastName("Smith");
    EXPECT_EQ(student.GetLastName(), "Smith");
}

TEST_F(TestStudent, MiddleName) 
{
    student.SetMiddleName("B.");
    EXPECT_EQ(student.GetMiddleName(), "B.");
}

TEST_F(TestStudent, Address)
{
    student.SetAddress("5678 Oak Street");
    EXPECT_EQ(student.GetAddress(), "5678 Oak Street");
}

TEST_F(TestStudent, University) 
{
    student.SetUniversity("MIT");
    EXPECT_EQ(student.GetUniversity(), "MIT");
}

TEST_F(TestStudent, StudentID)
{
    student.SetStudentID("123456");
    EXPECT_EQ(student.GetStudentID(), "123456");
}

class TestAdvancedStudent : public ::testing::Test
{
protected:
    CAdvancedStudent advancedStudent;
};

TEST_F(TestAdvancedStudent, FirstName)
{
    advancedStudent.SetFirstName("Alice");
    EXPECT_EQ(advancedStudent.GetFirstName(), "Alice");
}

TEST_F(TestAdvancedStudent, LastName) 
{
    advancedStudent.SetLastName("Johnson");
    EXPECT_EQ(advancedStudent.GetLastName(), "Johnson");
}

TEST_F(TestAdvancedStudent, MiddleName)
{
    advancedStudent.SetMiddleName("C.");
    EXPECT_EQ(advancedStudent.GetMiddleName(), "C.");
}

TEST_F(TestAdvancedStudent, Address)
{
    advancedStudent.SetAddress("9101 Pine Street");
    EXPECT_EQ(advancedStudent.GetAddress(), "9101 Pine Street");
}

TEST_F(TestAdvancedStudent, University)
{
    advancedStudent.SetUniversity("Harvard");
    EXPECT_EQ(advancedStudent.GetUniversity(), "Harvard");
}

TEST_F(TestAdvancedStudent, StudentID)
{
    advancedStudent.SetStudentID("789012");
    EXPECT_EQ(advancedStudent.GetStudentID(), "789012");
}

TEST_F(TestAdvancedStudent, DissertationTopic)
{
    advancedStudent.SetDissertationTopic("Quantum Computing");
    EXPECT_EQ(advancedStudent.GetDissertationTopic(), "Quantum Computing");
}

class TestWorker : public ::testing::Test 
{
protected:
    CWorker worker;
};

TEST_F(TestWorker, FirstName) 
{
    worker.SetFirstName("John");
    EXPECT_EQ(worker.GetFirstName(), "John");
}

TEST_F(TestWorker, LastName) 
{
    worker.SetLastName("Doe");
    EXPECT_EQ(worker.GetLastName(), "Doe");
}

TEST_F(TestWorker, MiddleName) 
{
    worker.SetMiddleName("A.");
    EXPECT_EQ(worker.GetMiddleName(), "A.");
}

TEST_F(TestWorker, Address) 
{
    worker.SetAddress("1234 Elm Street");
    EXPECT_EQ(worker.GetAddress(), "1234 Elm Street");
}

TEST_F(TestWorker, Specialty) 
{
    worker.SetSpecialty("Carpenter");
    EXPECT_EQ(worker.GetSpecialty(), "Carpenter");
}