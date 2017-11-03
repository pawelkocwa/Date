
#ifndef DATE_DATE_H
#define DATE_DATE_H

#include <ostream>
#include <iostream>

class Date {

private:

    int year;
    int month;
    int day;


public:

    Date(int givenYear = 1970, int givenMonth = 1, int givenDay = 1);   // while we are checking if the numbers are good, we should do sth if they are bad
    //Date(Date const &toCopy);

    ~Date() = default;


    int operator-(const Date &t) const;

    Date operator-(int howManyDays) const;
    Date operator+(int howManyDays) const;
    Date &operator+=(int howManyDays);
    Date &operator-=(int howManyDays);
    void operator=(const Date& t);

    bool operator!=(const Date &t) const;
    bool operator==(const Date &t) const;

    friend std::ostream & operator<<(std::ostream & osObject, const Date & dateObject);




};


#endif //DATE_DATE_H
