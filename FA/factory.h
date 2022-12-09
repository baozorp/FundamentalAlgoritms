#pragma once
#include <memory>
#include <ctime>
#include "lotterytickets.h"

class Factory {
public:
    virtual  std::shared_ptr<Ticket> generateTickets() const = 0;
    virtual ~Factory() {};
};

class Factory_5_36 :Factory {
private:
    mutable int serialNumber = 0;
public:
    Factory_5_36() {
        srand(time(0));
    }
    std::shared_ptr<Ticket> generateTickets() const override {
        int numbers[5];
        //генерация чисел для билетов

        for (size_t i = 0; i < 5; )
        {
            int value = 1 + rand() % 36;
            bool flag = true;
            //проверка на повторение
            for (size_t k = 0; k < i; k++)
            {
                if (numbers[k] == value) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                numbers[i] = value;
                i++;
            }
        }
        serialNumber += 1;
        return  std::shared_ptr<Ticket>{(Ticket*)(new Ticket_5_36(serialNumber, numbers))};
    }
};

class Factory_6_49 : Factory {
private:
    mutable int serialNumber = 0;
public:
    Factory_6_49() {
        srand(time(0));
    }
    std::shared_ptr<Ticket> generateTickets() const override {
        int numbers[6];
        //генерация чисел для билетов
        for (size_t i = 0; i < 6; )
        {
            int value = 1 + rand() % 45;
            bool flag = true;
            //проверка на повторение
            for (size_t k = 0; k < i; k++)
            {
                if (numbers[k] == value) {
                    break;
                }
            }
            if (flag) {
                numbers[i] = value;
                i++;
            }
        }
        serialNumber += 1;
        return  std::shared_ptr<Ticket>{(Ticket*)(new Ticket_6_49(serialNumber, numbers))};
    }
};
