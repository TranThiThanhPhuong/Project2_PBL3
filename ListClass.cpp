#include"ListClass.h"
ListClass::ListClass()
{}

ListClass::~ListClass(){
    ListTeacher.clear();
}

void ListClass::setIDclass(string id){
    this->IDclass = id;
}
string ListClass::getIDclass() const{
    return IDclass;
}

Teacher* ListClass::fineStudentByIDclass(const string idlop){
    for (int i = 0; i < ListTeacher.isEmpty(); i++){
        if (ListTeacher[i].getIDclass() == idlop){
            return &ListTeacher[i];
        }
    }
    return nullptr;
}