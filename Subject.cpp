#include"Subject.h"
#include<iomanip>
Subject::Subject(){
    this->IDSubject = "";
    this->Score = 0.0;
}

// Subject::Subject(string sub){
//     this->IDSubject = sub;
// }

// Subject::Subject(string idSubject, float score) 
//     : IDSubject(idSubject), Score(score)
// {}

// Subject::Subject( Subject& S){
//     //this->IDSubject = S.IDSubject;
//     this->Score = S.Score;
// }

Subject::~Subject()
{
    
}

void Subject::setSubject(string SJ){
    this->IDSubject = SJ;
}

string Subject::getSubject() const {
    return IDSubject;
}

void Subject::setScore(float score){
    this->Score = score;
}

float Subject::getScore() const {
    return Score;
}

bool Subject::addScore(float score) {
    if (score >= 0.0 && score <= 10.0) {
        this->Score = score;
        return true;
    } else {
        cout << "Diem khong hop le!" << endl;
        return false;
    }
}

// ostream& operator<<(ostream& o, const Subject& s){
//     o << "ID mon" << "|Diem" << endl; 
//     o << "|" << setw(5) << s.IDSubject << "|" << setw(4) << s.Score << endl;
//     return o;
// }
// istream& operator>>(istream& cin, Subject& S ){
//     cin >> S.IDSubject;
//     cout << "Nhap diem cua mon: " ;
//     cin >> S.Score;
//     return cin; 
//     getline(cin, S.IDSubject, ';');
//     cin >> S.Score;
//     cin.ignore(0.0, ' ');
//     return cin;
// }

// bool Subject::operator==(const Subject& other)  {
//     return IDSubject == other.IDSubject; //&& Score == other.Score;
// }

// float Subject::getAverageScore(const MyVector<Subject>& subject)  {
//     float result = 0;
//     for (int i = 0; i < subject.getSize(); ++i) {
//         result += subject[i].getScore();
//     }
//     return subject.isEmpty() ? 0 : result / subject.getSize();
// }

// void Subject::printSubjects(const MyVector<Subject>& subjects)  {
//     cout << "IDSubject" << "|Score" << endl; 
//     for (int i = 0; i < subjects.getSize(); i++) {
//         cout << subjects[i].IDSubject << subjects[i].Score << endl;
//     }
// }
// void Subject::ShowSubjects()  {
//     cout << "ID mon" << "|Diem" << endl; 
//     cout << "|" << setw(7) << IDSubject << "|" << setw(4) << Score << endl;
// }

