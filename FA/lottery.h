#include "factory.h"
#include <map>
#include <vector>


class Lottery
{
private:
    std::map<int, std::vector<int>> realization;
    std::map<int, std::vector<int>> winners_100;
    std::map<int, std::vector<int>> winners_1000;
    std::map<int, std::vector<int>> winners_10000;
    std::map<int, std::vector<int>> winners_100000;
    std::map<int, std::vector<int>> winners_1000000;
    std::shared_ptr<Ticket> win;
    bool flag = false;
    int counter = 0;
    int winners_1 = 0;
    int winners_2 = 0;
    int winners_3 = 0;
    int winners_4 = 0;
    int winners_5 = 0;
public:
    Lottery(){
    }

    void start(int release, int lotType) {


        Factory_5_36 factor;

        std::map<int, std::vector<int>> tickets;

        //Generate all tickets
        for (size_t i = 1; i < release; i++)
        {
            std::shared_ptr<Ticket> current_Ticket;
            current_Ticket = factor.generateTickets();
            tickets.insert(std::pair <int, std::vector<int>>(current_Ticket->getSerialNumber(), current_Ticket->getNumbers()));
        }

        //Create winner ticket
        std::shared_ptr<Ticket> win = factor.generateTickets();

        //Exclude some
        std::map<int, std::vector<int>>::iterator it = tickets.begin();
        int counter = 0;
        for (size_t i = 1; i < release; i++)
        {
            int random = 1 + rand() % 100;
            if (random < 60) {
                realization.insert(std::pair <int, std::vector<int>>(it->first, it->second));
                it++;
                counter++;
            }
            else {
                it++;
            }
        }

        it = realization.begin();
        int coutWinNumbers;
        std::cout << "The lottery has been played" << std::endl;
        for (size_t i = 1; i < counter; i++) {
            coutWinNumbers = 0;
            for (int k = 0; k < lotType; k++) {
                for (int j = 0; j < lotType; j++) {
                    if (win->getNumbers()[k] == it->second[j]) {
                        coutWinNumbers++;
                    }
                }
            }
            switch (coutWinNumbers)
            {
            case 1:
                winners_100.insert(std::pair <int, std::vector<int>>(it->first, it->second));
                winners_1++;
                break;
            case 2:
                winners_1000.insert(std::pair <int, std::vector<int>>(it->first, it->second));
                winners_2++;
                break;
            case 3:
                winners_10000.insert(std::pair <int, std::vector<int>>(it->first, it->second));
                winners_3++;
                break;
            case 4:
                winners_100000.insert(std::pair <int, std::vector<int>>(it->first, it->second));
                winners_4++;
                break;
            case 5:
                winners_1000000.insert(std::pair <int, std::vector<int>>(it->first, it->second));
                winners_5++;
                break;
            default:
                break;
            }
            it++;
        }
        std::cout << "Number of people who won 100: " << winners_1 << std::endl;
        std::cout << "Number of people who won 1000: " << winners_2 << std::endl;
        std::cout << "Number of people who won 10000: " << winners_3 << std::endl;
        std::cout << "Number of people who won 100000: " << winners_4 << std::endl;
        std::cout << "Number of people who won 1000000: " << winners_5 << std::endl;
        std::cout << "Winner is: ";
        for (int j = 0; j < 5; j++) {
            std::cout << win->getNumbers()[j] << "|";
        }
        std::cout << std::endl;

    }

    int find_by_sum(int sum, int type_lot) {
        int checker = 0;
        std::map<int, std::vector<int>>::iterator it = winners_100.begin();
        if (sum == 100) {
            std::map<int, std::vector<int>>::iterator it = winners_100.begin();
            checker = winners_1;
        }
        else if (sum == 1000) {
            std::map<int, std::vector<int>>::iterator it = winners_1000.begin();
            checker = winners_2;
        }
        else if (sum == 10000) {
            std::map<int, std::vector<int>>::iterator it = winners_10000.begin();
            checker = winners_3;
        }
        else if (sum == 100000) {
            std::map<int, std::vector<int>>::iterator it = winners_100000.begin();
            checker = winners_4;
        }
        else if (sum == 1000000) {
            std::map<int, std::vector<int>>::iterator it = winners_1000000.begin();
            checker = winners_5;
        }
        else {
            std::cout << "Not found" << std::endl;
        }
        if(checker==0){
            std::cout << "Not found" << std::endl;
            return 0;
        }
        else {
            for (int i = 0; i < checker; i++) {
                std::cout << "ID: " << it->first << "Numbers: ";
                for (int j = 0; j < type_lot; j++) {
                    std::cout << it->second[j] << "|";
                }
                std::cout << std::endl;
                it++;
            }
            return 1;
        }
    }
    
    void finder(std::map<int, std::vector<int>>::iterator it, int serial)
    {
        for (int i = 0; i < counter; i++) {
            if (serial == it->first){
                flag = true;
                std::cout << "This id is win" << std::endl;
                break;
            }
        }
    }
    void find_by_serial(int serial){
        flag = false;
        std::map<int, std::vector<int>>::iterator it = winners_100.begin();
        finder(it, serial);
        it = winners_1000.begin();
        finder(it, serial);
        it = winners_10000.begin();
        finder(it, serial);
        it = winners_10000.begin();
        finder(it, serial);
        it = winners_100000.begin();
        finder(it, serial);
        if (flag){
            std::cout << "Was not found" << std::endl;
        }
    }
};
