#include"Students.h"
Students::Students()
{}

Students::~Students()
{
   ListSubject.clear();
}

string Students::getIDClass() const{
    return IDclass;
}
void Students::setIDClass(string id){
    IDclass = id;
}
string Students::getIDStudent() const  {
    return this->IDStudent;
}

void Students::setIDStudent(string id) {
    this->IDStudent = id;
}

string Students::getNameStudent() const {
    return this->Name;
}

void Students::setNameStudent(string name) {
    this->Name = name;
}

Date Students::getBirthdayS() const {
    return this->date;
}

void Students::setBirthdayS(Date birthday) {
    this->date = birthday;
}

void Students::setGenderS(string gender){
    this->Gender = gender;
}

string Students::getGenderS() const {
    return this->Gender;
}

MyVector<Subject> Students::getScore()  {
    return ListSubject;
}

void Students::setScore( MyVector<Subject>& score) {
        this->ListSubject = score;
}

// bool Students::operator==(const Students& other)  {
//     return IDStudent == other.IDStudent;
// }

// float Students::getAverageScore()  {
//     float result = 0;
//     Subject sub;
//     for (int i = 0; i < ListSubject.getSize(); i++){
//         result += sub.getScore();
//     }
//     return ListSubject.getSize() > 0 ? result / ListSubject.getSize() : 0;
// }

// bool Students::addScore(string& IDsub, float score) {
//     for (int i = 0; i < ListSubject.getSize(); ++i) {
//         Subject& sb = ListSubject.at(i);
//         if (sb.getSubject() == IDsub) {
//             return sb.addScore(score);
//         }
//     }
//     return false;
// }
void Students::setDTB(float s){
    DTB = s;
}
float Students::getDTB(){
    return DTB;
}
// Subject* Students::findIDSubject(const string IDsub)  {
//     for (int i = 0; i < ListSubject.getSize(); i++){
//         if (ListSubject[i].getSubject() == IDsub){
//             return &ListSubject[i];
//         }
//     }
//     return nullptr;
// }
// void Students::writeStudent() {
//     cout << "Nhap thong tin hoc sinh: " << endl;
//     cout << "Ten ma ID hoc sinh: "; getline(cin, IDStudent);
//     cout << "Ten hoc sinh: "; getline(cin, Name);
//     cout << "Ngay sinh: "; cin >> date;
//     cout << "Gioi tinh: "; cin >> Gender;
// }

ostream& operator<<(ostream& cout, const Students& St){
    // cout << "ID     " << "|Ho va ten      " << "|Ngay sinh  " << "|Gioi tinh" << endl;
    cout << left << setw(7) << St.IDStudent << "|"  << left <<  setw(15) << St.Name << "|" 
    << left << setw(11) << St.date << "|" << left << setw(9) << St.Gender << endl;
    return cout;
}

istream& operator>>(istream& cin, Students& St){
	cout << "Nhap thong tin hoc sinh moi: " << endl;
    // getline(cin, St.IDclass);
    std::cin.ignore();
    // cout << "Lop duoc them vao: " ; getline(cin, St.IDclass);
    cout << "ID hoc sinh: "; getline(cin, St.IDStudent);
    cout << "Ten hoc sinh: "; getline(cin, St.Name);
    cout << "Ngay sinh: "; cin >> St.date;
    cout << "Gioi tinh: "; cin >> St.Gender;
    cout << endl;
    cout << "===============================================" << endl;
    return cin;
}

