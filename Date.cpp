#include"Date.h"
#include<iomanip>
Date::Date(){
    this->Day = 0;
    this->Month = 0;
    this->Year = 0;
}
Date::Date(int Day, int Month, int Year){
    this->Day = Day;
    this->Month = Month;
    this->Year = Year;
}
Date::Date(const Date& D){
    this->Day = D.Day;
    this->Month = D.Month;
    this->Year = D.Year;
}
Date::~Date(){
}
void Date::SetDay(int D){
    this->Day = D;
}
int Date::GetDay(){
    return this->Day;
}
void Date::SetMonth(int M){
    this->Month = M;
}
int Date::GetMonth(){
    return this->Month;
}
void Date::SetYear(int Y){
    this->Year = Y;
}
int Date::GetYear(){
    return this->Year;
}

istream& operator>>(istream& i, Date& D){
    i >> D.Day ;
    i.ignore(1, '/');
    i >> D.Month ;
    i.ignore(1, '/');
    i >> D.Year;
    i.ignore(1, ';');
    return i;
}
ostream& operator<<(ostream& o, const Date& D){
    o << right << setw(2) <<  D.Day << "/" << right << setw(2)<< D.Month << "/" << right << setw(2) << D.Year;
    return o;
}
