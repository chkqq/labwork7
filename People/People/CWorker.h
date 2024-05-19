#pragma once
#include "CPersonImpl.h"
#include "IPerson.h"

class CWorker : public CPersonImpl<IPerson>
{
public:
    std::string GetSpecialty() const { return m_specialty; }
    void SetSpecialty(const std::string& specialty) { m_specialty = specialty; }

private:
    std::string m_specialty;
};
