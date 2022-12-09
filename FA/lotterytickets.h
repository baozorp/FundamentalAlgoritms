#pragma once
#include <map>
#include <vector>
#include <algorithm>

class Ticket
{
public:
    virtual ~Ticket() {};
    virtual std::vector<int> getNumbers() = 0;
    virtual int getSerialNumber() = 0;
private:
};

class Ticket_5_36 :public Ticket
{
public:

    int getSerialNumber() override {
        return m_id;
    }

    Ticket_5_36(int serialNumber, int* numbers) :m_id(serialNumber)
    {
        for (size_t i = 0; i < 5; i++)
        {
            m_numbers[i] = numbers[i];
        }
    }

    std::vector<int> getNumbers() override {
        std::vector<int> numbers;
        for (size_t i = 0; i < 5; i++)
        {
            numbers.push_back(m_numbers[i]);
            std::sort(numbers.begin(), numbers.end());
        }

        return numbers;
    }

private:

    int m_numbers[5];
    int m_id;
};

class Ticket_6_49 :public Ticket
{
public:

    int getSerialNumber() override {
        return m_id;
    }

    Ticket_6_49(int serialNumber, int* numbers) :m_id(serialNumber)
    {
        for (size_t i = 0; i < 6; i++)
        {
            m_numbers[i] = numbers[i];
        }
    }

    std::vector<int> getNumbers() override {
        std::vector<int> numbers;
        for (size_t i = 0; i < 6; i++)
        {
            numbers.push_back(m_numbers[i]);
        }

        return numbers;
    }

private:
    int m_numbers[6];
    int m_id;
};

