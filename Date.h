#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<sstream>
using namespace std;
class Date
{
        int Day, Month, Year;
    public:
        Date(int, int, int);
        Date();
        Date(const Date&);
        ~Date();

        void SetDay(int);
        int  GetDay();
        void SetMonth(int);
        int GetMonth();
        void SetYear(int);
        int GetYear();
        // void parseDate(const string& );
        friend ostream& operator<<(ostream&, const Date&);
        friend istream& operator>>(istream&, Date&);
};
#endif
