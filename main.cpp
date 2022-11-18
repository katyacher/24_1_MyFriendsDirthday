#include <iostream>
#include <ctime>
#include <iomanip>
#include <map>

int main() {
    std::cout << "24.1. My Friends BirthDay" << std::endl;
    std::time_t current_t = std::time(nullptr);
    std::tm* current_tm = std::localtime(&current_t);
    std::map <std::string, std::tm> birthdays;
    std::string name;
    std::tm birthday{};

    while(true){
        std::cout << "Enter the name of your friend:"<< std::endl;
        std::cin >> name;
        if(name == "end") {
            break;
        } else{
            std::cout << "Enter birthday YYYY/MM/DD:" << std::endl;
            std::cin >> std::get_time(&birthday, "%Y/%m/%d");
            birthdays.emplace(name, birthday);
        }
    }

    std::map<double,std::string> nearest;

    for(auto my_friend: birthdays) {
        my_friend.second.tm_year = current_tm->tm_year;
        double diff = difftime(current_t, mktime(&my_friend.second));
        nearest.emplace(std::abs(diff), my_friend.first);

        if(my_friend.second.tm_mon == current_tm->tm_mon
            && my_friend.second.tm_mday == current_tm->tm_mday){
            std::cout << "Today is "<< my_friend.first << "'s birthday. " ;
        }
    }
    std::cout << nearest.begin()->first << " - " << nearest.begin()->second;
    return 0;
}
