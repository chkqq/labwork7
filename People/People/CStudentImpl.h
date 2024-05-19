#pragma once
#include "CPersonImpl.h"

template <typename Base>
class CStudentImpl : public CPersonImpl<Base> 
{
public:
    std::string GetUniversity() const override { return m_university; }
    void SetUniversity(const std::string& university) override { m_university = university; }

    std::string GetStudentID() const override { return m_studentID; }
    void SetStudentID(const std::string& studentID) override { m_studentID = studentID; }

private:
    std::string m_university;
    std::string m_studentID;
};
