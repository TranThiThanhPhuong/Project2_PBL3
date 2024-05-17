#include"Teacher.h"
Teacher::Teacher()
{
    this->IDclass = "";
}

Teacher::~Teacher()
{
    ListStudents.clear();
}

void Teacher::setIDclass(string id){
    IDclass = id;
}
string Teacher::getIDclass() const{
    return IDclass;
}

void Teacher::setIDTeacher(string id) {
    IDTeacher = id;
}
string Teacher::getIDTeacher(){
    return IDTeacher;
}
string Teacher::getNameTeacher()  {
    return this->Name;
}

void Teacher::setNameTeacher(string name) {
    this->Name = name;
}

void Teacher::setBirthdayT(Date birthday) {
    this->date = birthday;
}
Date Teacher::getBirthdayT()  {
    return this->date;
}

void Teacher::setGenderT(string gender){
    this->Gender = gender;
}
string Teacher::getGenderT() {
    return this->Gender;
}

Students* Teacher::findStudentByID(const string id){
    for (int i = 0; i < ListStudents.getSize(); i++){
        if (ListStudents[i].getIDStudent() == id){
            return &ListStudents[i];
        }
    }
    return nullptr;
}

istream& operator>>(istream& cin, Teacher& St){
	cout << "Nhap thong tin giao vien: " << endl;
    // getline(cin, St.IDclass);
    // cout << "Chu nhiem duoc them vao lop: " ; getline(cin, St.IDclass);
    std::cin.ignore();
    cout << "ID giao vien: "; getline(cin, St.IDTeacher);
    cout << "Ten giao vien: "; getline(cin, St.Name);
    cout << "Ngay sinh: "; cin >> St.date;
    cout << "Gioi tinh: "; cin >> St.Gender;
    return cin;
}