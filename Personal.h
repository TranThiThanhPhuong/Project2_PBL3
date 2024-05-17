#include"Date.h"
#ifndef PERSONAL_H
#define PERSONAL_H
#include<iostream>
using namespace std;
class Personal : public Date
{
protected:
    string Name;
    string Gender;
    Date date;
public:
    Personal();
    Personal(string, Date, string);
    ~Personal();
};
#endif