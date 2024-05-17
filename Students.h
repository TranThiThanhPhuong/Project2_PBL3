#include<iomanip>
#pragma once
#include"Subject.h"
#include"MyVector.cpp"
#include"Personal.h"
#ifndef STUDENTS_H
#define STUDENTS_H
class Students  : public Personal
{
private:
    string IDStudent;
    string IDclass;
    float DTB;
public:
    MyVector<Subject> ListSubject;
    Students();
    ~Students();

    void setIDClass(string);
    void setIDStudent(string);
    void setNameStudent(string);
    void setBirthdayS(Date);
    void setGenderS(string);
    void setScore(MyVector<Subject>& );
    void setDTB(float);


    string getIDClass() const;
    string getIDStudent() const;
    string getNameStudent() const;
    Date getBirthdayS() const;
    string getGenderS() const;
    MyVector<Subject> getScore() ;
    float getDTB();

    // bool operator==(const Students&) ;
    // float getAverageScore() ;
    // bool addScore( string&, float ) ;
    // Subject* findIDSubject(const string) ;
    // void writeStudent();

    friend ostream& operator<<(ostream&, const Students& );
    friend istream& operator>>(istream&, Students&);
};
#endif

