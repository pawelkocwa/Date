//
// Created by Paweł Kocwa on 11.10.2017.
//

#include "Date.h"


const int daysInMonth [12] {31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31};



////////////////////////////////////    CONSTRUCTORS            /////////////////////////////////////////

Date::Date(int givenYear, int givenMounth, int givenDay) {

    if(givenYear >= 1970){
        year = givenYear;
    }
    else{
        std::cout<<"You have given a bad year"<<std::endl;            // nie wiem czy spoko xd
    }

    if(givenMounth >= 0 && givenMounth <=12){
        month = givenMounth;
    }
    else
        std::cout<<"You have given a bad month "<<std::endl;

    if(givenDay >= 0 && givenDay <= daysInMonth[givenMounth - 1]){
        day = givenDay;
    }
    else{
        std::cout<<"You have given a bad numbers of days "<<std::endl;
    }



}

Date::Date(Date const &toCopy) {

    this->year = toCopy.year;
    this->month = toCopy.month;
    this->day = toCopy.day;
}


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
}                               // probably it's okey, CHECK!!!

Date Date::operator-(int howManyDays) const {

    int year, month, day;

    int daysInFirst = this->day, difference = 0;

    for(int i = 0; i <= this->month ;i++){
        daysInFirst += daysInMonth[i];
    }

    daysInFirst += this->year * 365;

    difference = daysInFirst - howManyDays;

    year = difference / 365;

    difference = difference - year * 365;                                   //now in difference left just 




    return ;
}

Date Date::operator+(int howManyDays) const {

    Date newDate;
    short newMonth = month, newYear = year, newDay = day;

    newDay += howManyDays;

    if( newDay <= daysInMonth[this->month - 1] ){            //check if there is need to divide the days
        newDate.year = this->year;
        newDate.month = this->month;
        newDate.day = this->day;

        return newDate;
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

    newDate.year = newYear;
    newDate.month = newMonth;
    newDate.day = newDay;

    return newDate;
}                           // probably it's okey, CHECK!!!

Date &Date::operator+=(int howManyDays) {


    int newMonth = month, newYear = year, newDay = day;

    newDay += howManyDays;

    if( newDay <= daysInMonth[this->month - 1] ){            //check if there is need to divide the days

        return;
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

    newDate.year = newYear;
    newDate.month = newMonth;
    newDate.day = newDay;

    return newDate;
}

Date &Date::operator-=(int howManyDays) {
    return ;
}

bool Date::operator!=(const Date &t) const {
    return false;
}

bool Date::operator==(const Date &t) const {
    return false;
}

std::ostream &operator<<(std::ostream &osObject, const Date &dateObject) {
    osObject<<dateObject.year<<"-"<<dateObject.month<<"-"<<dateObject.day<<std::endl;
    return osObject;
}

