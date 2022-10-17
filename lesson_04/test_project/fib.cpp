#include <iostream>
#include <cstdlib>

void get_fib_num(const int& integer);

// recursion without branching
void get_fib_num(const int& integer) {
    
}

int main(int argc, char const *argv[])
{
    int n = 0;
    if(argc == 2) {
        int tmp = std::atol(argv[1]);
        if (tmp < 0) {
            std::cerr << "Only non-negative number allowd\n";
            return -1;
        }
        n = tmp;
    } else {
        std::cout << "Enter a number to calculate the Fibonacci number" << std::endl;
        std::cin >> n;
    }

    

    return 0;
}
