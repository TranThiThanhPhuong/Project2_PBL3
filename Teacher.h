#include"Personal.h"
#include"Students.h"
#include<string.h>
class Teacher : public Personal
{
    private:
        string IDTeacher;
        string IDclass;
    public:
        MyVector<Students> ListStudents;
        Teacher();
        ~Teacher();

        void setIDTeacher(string);
        void setNameTeacher(string);
        void setBirthdayT(Date);
        void setGenderT(string);
        void setIDclass(string);

        string getIDTeacher() ;
        string getNameTeacher() ;
        Date getBirthdayT() ;
        string getGenderT() ;
        string getIDclass() const;

        Students* findStudentByID(const string);
        // friend ostream& operator<<(ostream&, const Teacher& );
        friend istream& operator>>(istream&, Teacher&);
        // void DisplayStudents(int&) const;
};


