#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

void print_welcome(void) {
    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "<<<           Guess the number game                 >>>" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
}

std::string get_user_name(void) {
    std::cout << "Please, enter your name: ";
    std::string name;
    std::cin >> name;
    if(name == "") {
        std::cout << "Error. String is empty. ";    // todo - fix (doesn't show error)
        name = get_user_name();
    }
    
    return name;
}

void exit(void) {
    // TODO print goodbuy and exit from programm
}

void get_table(void) {

}

void safe_table(void) {

}

void show_table(void) {

}



int main(int argc, char const *argv[])
{
    print_welcome();
    std::srand(std::time(nullptr));
    const int max_value = 100;
    const int random_value = std::rand() % max_value;

    const std::string user_name = get_user_name();
    std::cout << user_name << std::endl;


    return 0;
}
