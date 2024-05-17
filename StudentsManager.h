#include"ListClass.h"
#include<fstream>
#include<sstream>
// #include<iostream>
// using namespace std;
class StudentsManager
{
protected:
    MyVector<ListClass> dsClass;
public:
    Subject subjects;
    Students students;
    Teacher teacher;
    StudentsManager();
    ~StudentsManager();

    // bool addSubject(const string& );
    // bool addScore(const string& , string&, float) ;
    // float getAverageScore() ;
    // bool addStudents(const Students&);
    // bool checkSubject(const string& );
    // Subject findIDSubject(const string& );
    // Students findIDStudent(const string&) ;
    // Students findNameStudent(const string&);
    // void removeStudents(const string&);
    // void printSortedStudents(bool);
    // void Display();
    // void ShowSTandSub();
    // void sortStudents();

    void WriteDataFromFile(); // lay du lieu
    void Display(); // in hoc sinh
    void ShowSTandSub(); // in diem
    void ReadDataFromFile(); // luu dl
    void ReadDataScoreFromFile(); // luu dl co diem
    void addStudent(); // // them hs
    void removeStudents(); // // xoa hs
    void searchStudentByID(); // tim 
    void searchStudentByName(); // tim
    void changeStudentToOtherClass(); // doi hoc sinh sang lop khac
    void changeTeacherForClass(); // doi gvcn
    void addSubjectandScoreforStudent(); // them mon va diem
    void CCAverageScore() ; // tinh diem trung binh
    void ShowAllScoreandDTB(); // xem diem tb va nhieu mon
    void ShowOnlyDTB(); // chi xem dtb
    void sortStudentsByAverageScoreTD(); // sap xep hoc sinh theo dtb
    void sortStudentsByAverageScoreGD(); // sap xep hoc sinh theo dtb
    void DisplaySortedStudentsTD(); // in ra danh sach sau khi xep
    void DisplaySortedStudentsGD(); // in ra danh sach sau khi xep
    void sortAllStudentsByAverageScoreTD();
    void sortAllStudentsByAverageScoreGD();
    // bool compareByNameLength();

    
};

