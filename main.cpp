
#include <iostream>
#include "Date.h"


int main() {

    Date data1(2000,10,5);
    Date data2(2007,9,10);

    Date data3 = (data2 + 100);
    std::cout<<data3;


    return 0;
}