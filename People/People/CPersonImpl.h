#pragma once
#include <string>

template <typename Base>
class CPersonImpl : public Base 
{
public:
    std::string GetFirstName() const override { return m_firstName; }
    void SetFirstName(const std::string& firstName) override { m_firstName = firstName; }

    std::string GetLastName() const override { return m_lastName; }
    void SetLastName(const std::string& lastName) override { m_lastName = lastName; }

    std::string GetMiddleName() const override { return m_middleName; }
    void SetMiddleName(const std::string& middleName) override { m_middleName = middleName; }

    std::string GetAddress() const override { return m_address; }
    void SetAddress(const std::string& address) override { m_address = address; }

private:
    std::string m_firstName;
    std::string m_lastName;
    std::string m_middleName;
    std::string m_address;
};
