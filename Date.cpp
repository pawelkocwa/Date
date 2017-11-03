//
// Created by Paweł Kocwa on 11.10.2017.
//

#include "Date.h"


const int daysInMonth [12] {31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31};
int sumDaysInDate(int year, int month, int day);

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
}                                  // tested and it's good

Date Date::operator-(int howManyDays) const {

    int year, month, day, i = 0;

    int difference = sumDaysInDate(this->year,this->month,this->day) - howManyDays;

    // creating new date

    year = difference / 365;

    difference = difference - year * 365;                                   //now in difference left just days without years


    while( difference > daysInMonth[i] ){
        difference -= daysInMonth[i];
        i++;
    }

    month = i + 1;

    day = difference;


    if( 0 == difference )
    {
        year --;
        month = 12;
        day = daysInMonth[month - 1];
    }

    //std::cout<<year<<" "<<month<<" "<<day<<std::endl;

    return Date(year,month,day);
}                               // tested and it's good

Date Date::operator+(int howManyDays) const {

    int dayAfterSum = this->day, newMonth = this->month - 1, newYear = this-> year;

    dayAfterSum += howManyDays;

    while (dayAfterSum > daysInMonth[newMonth])
    {
        dayAfterSum -= daysInMonth[newMonth];
        newMonth++;

        if( newMonth == 12 )
        {
            newYear ++;
            newMonth = 0;
        }
    }

    return Date(newYear, newMonth + 1, dayAfterSum);
}                               // tested and it's good

Date &Date::operator+=(int howManyDays) {

    int dayAfterSum = this->day;
    int newMonth = this->month;
    int newYear = this->year;


    dayAfterSum += howManyDays;

    while (dayAfterSum > daysInMonth[newMonth-1])
    {
        dayAfterSum -= daysInMonth[newMonth-1];
        newMonth++;

        if( newMonth == 13 )
        {
            newYear ++;
            newMonth = 1;
        }
    }

        this->year = newYear;
        this->month = newMonth;
        this->day = dayAfterSum;

    return *this;
}                                   // tested and it's good

Date &Date::operator-=(int howManyDays) {
/*
    int difference, z, newYear, newMonth;
    difference = z = 0;

    for (int i = 0; i < this->month - 1 ; i++) {
        difference += daysInMonth[i];
    }

    difference += this->year * 365;

    difference += this->day;

    difference -= howManyDays;

    newYear = difference / 365;                                          //year

    difference -= newYear * 356;

    while ( difference > daysInMonth[z] ){

        difference -= daysInMonth[z];
        z++;
    }


    //if(0 == difference){
    //    this->year --;
    //    this->month = 11;
    //    this->day = daysInMonth[month];
    //}


    newMonth = z + 1;

    this->day = difference;
    this->month = newMonth;
    this->year = newYear;

    return *this;
*/
    int year, month, day, i = 0;

    int difference = sumDaysInDate(this->year,this->month,this->day) - howManyDays;

    // creating new date

    year = difference / 365;

    difference = difference - year * 365;                                   //now in difference left just days without years


    while( difference > daysInMonth[i] ){
        difference -= daysInMonth[i];
        i++;
    }

    month = i + 1;

    day = difference;


    if( 0 == difference )
    {
        year --;
        month = 12;
        day = daysInMonth[month - 1];
    }

    //std::cout<<year<<" "<<month<<" "<<day<<std::endl;

    this->day = day;
    this->month = month;
    this->year = year;

    return *this;


}                                   // tested and it's good

void Date::operator=(const Date &t) {

    this->year = t.year;
    this->month = t.month;
    this->day = t.day;
}

bool Date::operator!=(const Date &t) const {
    return (this->day != t.day) || (this->month != t.month) || (this->year != t.year);
}                                // tested and it's good

bool Date::operator==(const Date &t) const {
    return (this->day == t.day) && (this->month == t.month) && (this->year == t.year);
}                                // tested and it's good



////////////////////////////////////        OTHERS      /////////////////////////////////////////

std::ostream &operator<<(std::ostream &osObject, const Date &dateObject) {
        osObject<<dateObject.year<<"-"<<dateObject.month<<"-"<<dateObject.day<<std::endl;
        return osObject;
    }  // tested and it's good


int sumDaysInDate(int year, int month, int days) {

    int sum=0;

    sum = (year * 365);

    sum += days;

    for (int i = 0; i < month - 1 ; ++i) {
        sum += daysInMonth[i];
    }

    return sum;
}
