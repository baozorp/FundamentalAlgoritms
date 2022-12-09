#include <iostream>
#include "lottery.h"


int main()
{
    Lottery lottery ;

    std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;
    int flag = 5;
    lottery.start(20000, flag);
    std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;

    while (true) {
        int sum;
        int id_number;
        std::cout << "Enter 1 to find by id" << std::endl;
        std::cout << "Enter 2 to new lottery" << std::endl;
        std::cout << "Enter 100/1000/10000/100000 to find winers by that sum" << std::endl;
        std::cout << "Enter 5 or 6 for change type lottery. Now type is: " << flag << std::endl;
        std::cin >> sum;
        switch(sum){
            case 1:{
                std::cout << "Enter id" << std::endl;
                std::cin >> id_number;
                lottery.find_by_serial(id_number);
                break;
            }
            case 2:{
                Lottery lottery;
                lottery.start(100, flag);
                break;
            }
            case 5:{
                flag = 5;
                break;
            }
            case 6:{
                flag = 6;
                break;

            }
            default:{
                lottery.find_by_sum(sum, flag);
                break;
            }
        }

    }
    return 0;
};
