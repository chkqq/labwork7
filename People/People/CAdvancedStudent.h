#pragma once
#include "CStudentImpl.h"
#include "IAdvancedStudent.h"

class CAdvancedStudent : public CStudentImpl<IAdvancedStudent>
{
public:
    std::string GetDissertationTopic() const override { return m_dissertationTopic; }
    void SetDissertationTopic(const std::string& topic) override { m_dissertationTopic = topic; }

private:
    std::string m_dissertationTopic;
};
