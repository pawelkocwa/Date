
#include <iostream>
#include "Date.h"


int main() {

    Date data1(2000,1,1);
    Date data2(2000,1,1);
    Date data3(2001,1,1);


    for (int i = 0; i < 1000 ; ++i) {
        data1 += i;
        data2 = data2 + i;

        std::cout<<"+=  "<<data1;
        std::cout<<"= + "<<data2<<std::endl;

        data1 -= i;
        data2 = data2 - i;

        std::cout<<data1;
        std::cout<<data2<<std::endl;
        std::cout<<"------------------------------"<<std::endl;
    }
    std::cout<< "check the bug :P "<<std::endl;
    data1 -= 366;
    data2 = data2 - 366;
    std::cout<< data1<<std::endl;
    std::cout<< data2<<std::endl;


    std::cout<<"próba bool"<<std::endl;

    bool z = data3 != data2;
    std::cout<<"3 i 2 ->"<< z<<std::endl;

    z = data2 == data2;
    std::cout<<"2 i 2 -> "<< z<<std::endl;

    z = data1 != data2;
    std::cout<<"1 i 2 -> "<< z<<std::endl;

    z = data3 == data1;
    std::cout<<"3 i 1-> "<< z<<std::endl;


    return 0;
}