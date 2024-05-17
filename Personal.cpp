#include"Personal.h"
Personal::Personal()
    : Name(""), Gender(""), Date(0,0,0)
{}

Personal::Personal(string Name, Date date, string Gender)
    :Name(Name), date(date) , Gender(Gender)
{}

Personal::~Personal()
{}