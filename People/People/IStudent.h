#pragma once
#include "IPerson.h"

class IStudent : public IPerson 
{
public:
    virtual std::string GetUniversity() const = 0;
    virtual void SetUniversity(const std::string& university) = 0;

    virtual std::string GetStudentID() const = 0;
    virtual void SetStudentID(const std::string& studentID) = 0;
};
