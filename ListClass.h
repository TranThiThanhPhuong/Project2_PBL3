#include"Teacher.h"
class ListClass
{
    private:
        string IDclass;
    public:
        MyVector<Teacher> ListTeacher;
        ListClass();
        ~ListClass();

        void setIDclass(string);
        string getIDclass() const;

        Teacher* fineStudentByIDclass(const string);

};
