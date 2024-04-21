#include <iostream>
#include "../include/algebra/PrecisionDouble.h"

int main()
{
    std::cout << "Hello World!\n" << std::endl;
    PrecisionDouble test(1, 5);
    std::cout << test.ToString() << std::endl;
}
