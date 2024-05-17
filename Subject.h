#include<iostream>
#ifndef SUBJECT_H
#define SUBJECT_H
using namespace std;
class Subject {
private:
    string IDSubject;
    float Score;
public:
    Subject();
    // Subject(string);
    // Subject(string, float);
    // Subject(Subject&);
    ~Subject();

    void setSubject(string);
    string getSubject() const ;
    
    void setScore(float);
    float getScore() const;

    bool addScore(float);
    // friend ostream& operator<<(ostream&, const Subject&);
    // friend istream& operator>>(istream&, Subject&);
    // bool operator==(const Subject& );
};
#endif