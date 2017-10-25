//
// Created by Paweł Kocwa on 11.10.2017.
//

#include "Date.h"


const int daysInMonth [12] {31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31};



////////////////////////////////////    CONSTRUCTORS            /////////////////////////////////////////

Date::Date(int givenYear, int givenMonth, int givenDay) {

    if(givenYear >= 1970)
        year = givenYear;

    else{
        std::cout<<"You have given a bad year!"<<std::endl;
        std::cout<<"Try again if you wish :) "<<std::endl;

        while(givenYear < 1970){

            std::cin>>givenYear;

            if(givenYear < 1970){
                std::cout<<"Still wrong! :/ "<<std::endl;
                std::cout<<std::endl;
            }

        }
        std::cout<<"Good!"<<std::endl;
        year = givenYear;
    }

    if(givenMonth >= 1 && givenMonth <=12)
        month = givenMonth;

    else{
        std::cout<<"You have given a bad month! "<<std::endl;
        std::cout<<"Try again if you wish :) "<<std::endl;

        while(givenMonth < 1 || givenMonth > 12){

            std::cin>>givenMonth;

            if(givenMonth < 1 || givenMonth > 12)
                std::cout<<"Still wrong! :/ "<<std::endl;

            std::cout<<std::endl;

        }
        std::cout<<"Good!"<<std::endl;
        month = givenMonth;
    }

    if(givenDay >= 1 && givenDay <= daysInMonth[givenMonth - 1])
        day = givenDay;

    else{
        std::cout<<"You have given a bad numbers of days! "<<std::endl;
        std::cout<<"Try again if you wish :) "<<std::endl;

        while(givenDay < 1 || givenDay > daysInMonth[month-1]){

            std::cin>>givenDay;

            if(givenDay < 1 || givenDay > daysInMonth[month-1])
                std::cout<<"Still wrong! :/ "<<std::endl;

            std::cout<<std::endl;

        }

        day = givenDay;
        std::cout<<"Good!"<<std::endl;
    }
}               // tested and it's good

/*                                                                          // pointless xd
Date::Date(Date const &toCopy) {

    this->year = toCopy.year;
    this->month = toCopy.month;
    this->day = toCopy.day;
}
*/


////////////////////////////////////    OPERATOR OVERLOADING    /////////////////////////////////////////

int Date::operator-(const Date &t) const {

    int daysInFirst = this->day, daysInT = t.day, difference = 0;

    for(int i = 0; i <= this->month ;i++){
        daysInFirst += daysInMonth[i];
    }
    for(int i = 0; i <= t.month ;i++){
        daysInT += daysInMonth[i];
    }

    daysInFirst += this->year * 365;
    daysInT += t.year * 365;

    difference = daysInFirst - daysInT;

    return difference;
}                               // tested and it's good

Date Date::operator-(int howManyDays) const {

    int year, month, day, i = 0;

    // count how many days

    int daysInFirst = this->day, difference = 0;

    for(int i = 0; i <= this->month - 1 ;i++){
        daysInFirst += daysInMonth[i];
    }

    daysInFirst += this->year * 365;

    difference = daysInFirst - howManyDays;

    // creating new date

    year = difference / 365;

    difference = difference - year * 365;                                   //now in difference left just days without years

    while( difference <= daysInMonth[i] ){
        difference -= daysInMonth[i];
        i++;
    }

    month = i + 1;

    day = difference;





    return Date(year,month,day);
}                           // you've to check that!!!

Date Date::operator+(int howManyDays) const {

    Date newDate;
    int newMonth = month, newYear = year, newDay = day;

    newDay += howManyDays;

    if( newDay <= daysInMonth[this->month - 1] ){            //check if there is need to divide the days
        newDate.year = this->year;
        newDate.month = this->month;
        newDate.day = this->day;

    }
    else {
        newDay -= howManyDays;
        howManyDays += newDay;
        howManyDays += newYear * 365;

        for(int i = 0; i <= month - 2; i++) {
            howManyDays += daysInMonth[i];
        }



        /*
        while( newDay > daysInMonth[(newMonth-1) % 12] ){

            // check how many days in the month

            if( newDay > daysInMonth[(newMonth-1) % 12]) {

                newDay -= daysInMonth[ (newMonth-1) % 12 ];
                newMonth++;

                if(newMonth / 12 == 1){
                    newYear += newMonth / 12;
                    newMonth = 1;
                }

            }

            if(newMonth / 12 == 1){
                newYear += newMonth / 12;
                newMonth = 1;
            }

        */
        }
    }


    newDate.year = newYear;
    newDate.month = newMonth;
    newDate.day = newDay;

    return newDate;
}                           // probably it's okey, CHECK!!!

Date &Date::operator+=(int howManyDays) {


    int newMonth = month, newYear = year, newDay = day;

    newDay += howManyDays;

    if( newDay <= daysInMonth[this->month - 1] ){            //check if there is need to divide the days

        (this->day = newDay);
    }


    while( newDay <= daysInMonth[(newMonth-1) % 12] ){

        // check how many days in the month

        if( newDay > daysInMonth[(newMonth-1) % 12]) {

            newDay -= daysInMonth[ (newMonth-1) % 12 ];
            newMonth++;

            if(newMonth / 12 == 1){
                newYear += newMonth / 12;
                newMonth = 1;
            }

        }

        if(newMonth / 12 == 1){
            newYear += newMonth / 12;
            newMonth = 1;
        }
    }
    this->year = newYear;
    this->month = newMonth;
    this->day = newDay;

}

void Date::operator=(const Date &t) {

    this->year = t.year;
    this->month = t.month;
    this->day = t.day;
}



/*
Date &Date::operator-=(int howManyDays) {
    return ;
}

bool Date::operator!=(const Date &t) const {
    return false;
}

bool Date::operator==(const Date &t) const {
    return false;
}
*/


////////////////////////////////////        OTHERS      /////////////////////////////////////////

std::ostream &operator<<(std::ostream &osObject, const Date &dateObject) {
    osObject<<dateObject.year<<"-"<<dateObject.month<<"-"<<dateObject.day<<std::endl;
    return osObject;
}



