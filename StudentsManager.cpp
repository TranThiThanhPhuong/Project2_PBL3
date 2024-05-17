#include"StudentsManager.h"
#include<string>
StudentsManager::StudentsManager()
{}

StudentsManager::~StudentsManager(){
    dsClass.clear();
}

void StudentsManager::WriteDataFromFile(){
    ifstream Fileclass("lop.txt");
    string line;
    while (std::getline(Fileclass, line)) {
        istringstream iss(line);
        string idclass;
        if (std::getline(iss, idclass, ';')) {
            ListClass listcl;
            listcl.setIDclass(idclass);
            ifstream Fileteacher("teacher.txt");
            string teacherLine;
            while (std::getline(Fileteacher, teacherLine)) {
                istringstream teacherIss(teacherLine);
                string idteacher1, namet, gent, idclass1;
                Date datet;
                if (std::getline(teacherIss, idteacher1, ';') && std::getline(teacherIss, namet, ';') && teacherIss >> datet  && std::getline(teacherIss, gent, ';') && std::getline(teacherIss, idclass1, ';')) {
                    if (idclass == idclass1 ) {
                        Teacher listtea;
                        listtea.setIDTeacher(idteacher1);
                        listtea.setNameTeacher(namet);
                        listtea.setBirthdayT(datet);
                        listtea.setGenderT(gent);
                        ifstream Filestudents("students.txt");
                        string svLine;
                        while (std::getline(Filestudents, svLine)) {
                            istringstream svIss(svLine);
                            string idstudent, namest, genst, idclass_st;
                            Date datest;
                            if (std::getline(svIss, idstudent, ';') && std::getline(svIss, namest, ';') &&
                                svIss >> datest  && std::getline(svIss, genst, ';') && std::getline(svIss, idclass_st, ';')) {
                                if (idclass_st == idclass ) {
                                    Students st;
                                    st.setIDClass(idclass_st);
                                    st.setIDStudent(idstudent);
                                    st.setNameStudent(namest);
                                    st.setBirthdayS(datest);
                                    st.setGenderS(genst);
                                    ifstream FileScore("subject.txt");
                                    // ifstream FileScore("diem.txt");
                                    string scoreLine;
                                    while (std::getline(FileScore, scoreLine)) {
                                        stringstream ss(scoreLine);
                                        string idst, idsub_score;
                                        float sco;
                                        if (std::getline(ss, idst, ';')) {
                                            while (std::getline(ss, idsub_score, ',') && ss >> sco) {
                                            // while (ss >> sco) {
                                                        if (idst == idstudent && sco >= 0.0 && sco <= 10.0){
                                                            Subject sub;
                                                            sub.setSubject(idsub_score);
                                                            sub.setScore(sco);
                                                            st.ListSubject.pushBack(sub);


                                                }
                                            }
                                        }
                                    }
                                    FileScore.close();
                                    listtea.ListStudents.pushBack(st);
                                }
                            }
                        }
                        Filestudents.close();
                        listcl.ListTeacher.pushBack(listtea);
                    }
                }
            }
            Fileteacher.close();
            dsClass.pushBack(listcl);
        }
    }
    Fileclass.close();
}
void StudentsManager::Display() {
    for (int i = 0; i < dsClass.getSize(); i++) {
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "================================================================" << endl;
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "ID lop hoc: "<< dsClass[i].getIDclass() << endl;
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Giao vien chu nhiem: " << dsClass[i].ListTeacher[i].getIDTeacher() << "--"
        << dsClass[i].ListTeacher[i].getNameTeacher() << endl;
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Danh sach hoc sinh cua lop: " << endl;
        std::cout << "\t\t\t\t" << setfill(' ') << setw(5) << left << "ID     " << "|Ten hoc sinh         " << "|Ngay sinh " << "|Gioi tinh" << endl;
            for (int j = 0; j < dsClass[i].ListTeacher[i].ListStudents.getSize(); ++j) {
            std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << left << setw(7) << dsClass[i].ListTeacher[i].ListStudents[j].getIDStudent() 
            << "|"  << left <<  setw(21)<< dsClass[i].ListTeacher[i].ListStudents[j].getNameStudent() 
            << "|"<< dsClass[i].ListTeacher[i].ListStudents[j].getBirthdayS() 
            << "|" << left << setw(6) << dsClass[i].ListTeacher[i].ListStudents[j].getGenderS() << endl;
        }
        std::cout << endl;
    }
    std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "================================================================" << endl;

}
void StudentsManager::ShowSTandSub() {
    for (int i = 0; i < dsClass.getSize(); i++) {
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "================================================================" << endl;
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left  << "ID Teacher: "<< dsClass[i].getIDclass() << endl;
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left  << "Giao vien chu nhiem: " << dsClass[i].ListTeacher[i].getIDTeacher() << "--"
        << dsClass[i].ListTeacher[i].getNameTeacher() << endl;
        // std::std::cout << "Danh sach hoc sinh kem diem cua Teacher: " << endl;
        for (int j = 0; j < dsClass[i].ListTeacher[i].ListStudents.getSize(); ++j) {
            std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Hoc sinh: " << dsClass[i].ListTeacher[i].ListStudents[j].getIDStudent();
            std::cout << "--" << dsClass[i].ListTeacher[i].ListStudents[j].getNameStudent()  << endl;
            std::cout << "\t\t\t\t" << setfill(' ') << setw(6) << left  << "|Mon   " << "|Diem" << endl;
            for (int k = 0; k < dsClass[i].ListTeacher[i].ListStudents[j].ListSubject.getSize(); k++){
                std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left  << left << setw(7) <<  dsClass[i].ListTeacher[i].ListStudents[j].ListSubject[k].getSubject() ;
                std::cout << "|" << left << setw(4) <<  dsClass[i].ListTeacher[i].ListStudents[j].ListSubject[k].getScore() << endl;
            }
            std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left  << "----------------------------------------------------------------" << endl;
        }
        std::cout << endl;
    }
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left  <<"================================================================" << endl;

}
void StudentsManager::ReadDataFromFile() {
    ofstream Fileclass("class1.txt", ios::trunc);
    Fileclass.close();

    ofstream Fileteacher("teacher1.txt", ios::trunc);
    Fileteacher.close();

    ofstream Filestudent("students1.txt", ios::trunc);
    Filestudent.close();

    for (int i = 0; i < dsClass.getSize(); ++i) {
        ofstream Fileclass("class1.txt", ios::app);
        ofstream Fileteacher("teacher1.txt", ios::app);
        Fileclass << dsClass[i].getIDclass() << endl;
        Fileteacher << dsClass[i].ListTeacher[i].getIDTeacher() << ";"
                    << dsClass[i].ListTeacher[i].getNameTeacher() << ";"
                    << dsClass[i].ListTeacher[i].getBirthdayT() << ";"
                    << dsClass[i].ListTeacher[i].getGenderT() << ";"
                    << dsClass[i].ListTeacher[i].getIDclass() << endl;
        Fileclass.close();
        Fileteacher.close();
            for (int j = 0; j < dsClass[i].ListTeacher[i].ListStudents.getSize(); j++) {
                ofstream Filestudent("students1.txt", ios::app);
                Filestudent << dsClass[i].ListTeacher[i].ListStudents[j].getIDStudent() << ";"
                        << dsClass[i].ListTeacher[i].ListStudents[j].getNameStudent() << ";"
                        << dsClass[i].ListTeacher[i].ListStudents[j].getBirthdayS() << ";"
                        << dsClass[i].ListTeacher[i].ListStudents[j].getGenderS() << ";"
                        << dsClass[i].ListTeacher[i].ListStudents[j].getIDClass() << endl;
                Filestudent.close();
            }
        }
    // std::cout << "Du lieu da duoc cap nhat thong tin cho hoc sinh. " << endl;
}

void StudentsManager::ReadDataScoreFromFile(){
    ofstream Filescore("score.txt", ios::trunc);
    Filescore.close();
    for (int i = 0; i < dsClass.getSize(); ++i) {
        for (int j = 0; j < dsClass[i].ListTeacher[i].ListStudents.getSize(); j++) {
            ofstream Filescore("score.txt", ios::app);
            Filescore << dsClass[i].ListTeacher[i].ListStudents[j].getIDStudent() << ";";
            for (int k =0; k < dsClass[i].ListTeacher[i].ListStudents[j].ListSubject.getSize(); k++){
                Filescore << dsClass[i].ListTeacher[i].ListStudents[j].ListSubject[k].getSubject() << ",";
                Filescore << dsClass[i].ListTeacher[i].ListStudents[j].ListSubject[k].getScore() ;
            }
            Filescore << endl;
            Filescore.close();
        }
    }
    std::cout << "Du lieu da duoc cap nhat diem cho hoc sinh. " << endl;
}

void StudentsManager::removeStudents() {
    //string maLop, maHS;
    // std::cout << "Nhap ID lop: ";
    // std::cin >> maLop;
    std::cout << "Nhap ID hoc sinh can xoa: ";
    string maHS;
    std::cin >> maHS;
    std::cout << endl;
    std::cout << "================================================================" << endl;
    // ListClass* lop = nullptr;
    // for (int i = 0; i < dsClass.getSize(); ++i) {
    //     if (dsClass[i].getIDclass() == maLop) {
    //         lop = &dsClass[i];
    //         break;
    //     }
    // }
    // if (!lop) {
    //     std::cout << "Khong tim thay lop co ma " << maLop << endl;
    //     return;
    // }
    // Teacher& GV = lop->ListTeacher[0];
    bool found = false;
    for (int i = 0; i < dsClass.getSize(); ++i) {
        for (int j = 0; j < dsClass[i].ListTeacher.getSize(); ++j) {
            for (int k = 0; k < dsClass[i].ListTeacher[j].ListStudents.getSize();k++) {
                if (dsClass[i].ListTeacher[j].ListStudents[k].getIDStudent() == maHS) {
                    dsClass[i].ListTeacher[j].ListStudents.remove(k);
                    found = true;
                    std::cout << "================================================================" << endl;
                    std::cout << "Xoa hoc sinh thanh cong!" << endl;
                    ReadDataFromFile();
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            break;
        }
    }
    // if (!found){

    // }
    if (found) {
        for (int i = 0; i < dsClass.getSize(); i++) {
        std::cout << "================================================================" << endl;
        std::cout << "ID lop hoc: "<< dsClass[i].getIDclass() << endl;
        std::cout << "Giao vien chu nhiem: " << dsClass[i].ListTeacher[i].getIDTeacher() << "--"
        << dsClass[i].ListTeacher[i].getNameTeacher() << endl;
        std::cout << "Danh sach hoc sinh cua lop: " << endl;
        std::cout << "ID     " << "|Ten hoc sinh         " << "|Ngay sinh " << "|Gioi tinh" << endl;
            for (int j = 0; j < dsClass[i].ListTeacher[i].ListStudents.getSize(); ++j) {
            std::cout << left << setw(7) << dsClass[i].ListTeacher[i].ListStudents[j].getIDStudent() << "|"  << left <<  setw(21) << dsClass[i].ListTeacher[i].ListStudents[j].getNameStudent() << "|"
            << dsClass[i].ListTeacher[i].ListStudents[j].getBirthdayS() << "|" << left << setw(6) << dsClass[i].ListTeacher[i].ListStudents[j].getGenderS() << endl;
        }
        std::cout << endl;
        }
    } 
    else {
        std::cout << "Khong tim thay hoc sinh co ID " << maHS << " trong lop " << "tat ca cac lop" << endl;
    }
}

void StudentsManager::searchStudentByID() {
    std::string maHS;
    std::cout << "Nhap ID hoc sinh can tim kiem: ";
    std::cin >> maHS;
    std::cout << "----------------------------------------------------------------" << endl;
    bool found = false;
    for (int i = 0; i < dsClass.getSize(); ++i) {
        ListClass& lop = dsClass[i];
        for (int j = 0; j < lop.ListTeacher.getSize(); ++j) {
            Teacher& GV = lop.ListTeacher[j];
            for (int k = 0; k < GV.ListStudents.getSize(); ++k) {
                Students& HS = GV.ListStudents[k];
                if (HS.getIDStudent() == maHS) {
                    std::cout << "Tim thay hoc sinh trong lop " << lop.getIDclass() << std::endl;
                    std::cout << "ID: " << HS.getIDStudent() << std::endl;
                    std::cout << "Ten: " << HS.getNameStudent() << std::endl;
                    std::cout << "Ngay sinh: " << HS.getBirthdayS() << std::endl;
                    std::cout << "Gioi tinh: " << HS.getGenderS() << std::endl;
                    std::cout << "----------------------------------------------------------------" << endl;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
    }
    if (!found) {
        std::cout << "Khong tim thay hoc sinh co ID " << maHS << " trong tat ca cac lop." << std::endl;
        std::cout << "----------------------------------------------------------------" << endl;
    }
}
void StudentsManager::searchStudentByName(){
    std::string namehs;
    std::cout << "Nhap ID hoc sinh can tim kiem: ";
    std::getline(std::cin, namehs);
    std::cout << "----------------------------------------------------------------" << endl;
    bool found = false;
    for (int i = 0; i < dsClass.getSize(); ++i) {
        ListClass& lop = dsClass[i];
        for (int j = 0; j < lop.ListTeacher.getSize(); ++j) {
            Teacher& GV = lop.ListTeacher[j];
            for (int k = 0; k < GV.ListStudents.getSize(); ++k) {
                Students& HS = GV.ListStudents[k];
                if (HS.getNameStudent() == namehs) {
                    std::cout << "Tim thay hoc sinh trong lop " << lop.getIDclass() << std::endl;
                    std::cout << "ID: " << HS.getIDStudent() << std::endl;
                    std::cout << "Ten: " << HS.getNameStudent() << std::endl;
                    std::cout << "Ngay sinh: " << HS.getBirthdayS() << std::endl;
                    std::cout << "Gioi tinh: " << HS.getGenderS() << std::endl;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
    }
    if (!found) {
        std::cout << "Khong tim thay hoc sinh co ID " << namehs << " trong tat ca cac lop." << std::endl;
        std::cout << "----------------------------------------------------------------" << endl;
    }
}

void StudentsManager::changeStudentToOtherClass() {
    std::string maHS, maLopMoi;
    std::cout << "Nhap ID hoc sinh can chuyen lop: ";
    std::cin >> maHS;
    Students* studentToMove = nullptr;
    Teacher* teachera = nullptr;
    for (int i = 0; i < dsClass.getSize(); ++i) {
        ListClass& lop = dsClass[i];
        for (int j = 0; j < lop.ListTeacher.getSize(); ++j) {
            Teacher& GV = lop.ListTeacher[j];
            for (int k = 0; k < GV.ListStudents.getSize(); ++k) {
                Students& HS = GV.ListStudents[k];
                if (HS.getIDStudent() == maHS) {
                    studentToMove = &HS;
                    teachera = &GV;
                    break;
                }
            }
            if (studentToMove) {
                break;
            }
        }
        if (studentToMove) {
            break;
        }
    }
    if (!studentToMove) {
        std::cout << "Khong tim thay hoc sinh co ID " << maHS << " trong tat ca cac lop." << std::endl;
        return; // dung lai xong quay ve menu
    }
    std::cout << "Nhap ID lop hoc de hoc sinh chuyen vao: ";
    std::cin >> maLopMoi;
    bool dung = true;
    while (dung)
    {
        if (maLopMoi == studentToMove->getIDClass()){
            std::cout << "Hoc sinh nay da ton tai trong lop nay roi!" << endl;
            std::cout << "Ban co muon chuyen hoc sinh qua lop khac nua khong " << endl;
            std::cout << "1. Co " << endl;
            std::cout << "2. Khong " << endl;
            std::cout << "Chon: " ;
            int chon;
            std::cin >> chon;
            if (chon == 1){
                string maLopMoi2;
                std::cout << "Nhap lai ID lop hoc khac de hoc sinh chuyen vao: " ;
                std::cin >> maLopMoi2;
                maLopMoi = maLopMoi2;
                if (maLopMoi != studentToMove->getIDClass()) {
                    dung = false;
                    break;
                }
            }
            else {
                return;
            }
        }
        else{
            break;
        }
    }
    std::cout << "-----------------------------------------------" << endl;
    ListClass* newClass = nullptr;
    for (int i = 0; i < dsClass.getSize(); ++i) {
        if (dsClass[i].getIDclass() == maLopMoi) {
            newClass = &dsClass[i];
            std::cout << "Chuyen hoc sinh qua lop "<< maLopMoi << " thanh cong" << endl;
            break;
        }
    }
    if (!newClass) {
        std::cout << "Khong tim thay lop moi co ID " << maLopMoi << std::endl;
        return;
    }
    studentToMove->setIDClass(maLopMoi);
    newClass->ListTeacher[0].ListStudents.pushBack(*studentToMove);
    for (int i = 0; i < teachera->ListStudents.getSize(); ++i) {
        if (teachera->ListStudents[i].getIDStudent() == maHS) {
            teachera->ListStudents.remove(i);
            break;
        }
    }
    ReadDataFromFile();
    std::cout << "================================================================" << endl;

}
void StudentsManager::addStudent() {
    std::string maHS, maLopMoi;
    std::string Name, Gender;
    Date date;
    bool dung = true;
    ListClass* targetClass = nullptr; // Khai báo targetClass ở đầu hàm
    while (dung) {
        std::cout << "Nhap ID hoc sinh can them vao lop: ";
        std::cin >> maHS;
        bool studentExists = false;
        for (int i = 0; i < dsClass.getSize(); ++i) {
            ListClass& lop = dsClass[i];
            for (int j = 0; j < lop.ListTeacher.getSize(); ++j) {
                Teacher& GV = lop.ListTeacher[j];
                for (int k = 0; k < GV.ListStudents.getSize(); ++k) {
                    Students& HS = GV.ListStudents[k];
                    if (HS.getIDStudent() == maHS) {
                        studentExists = true;
                        break;
                    }
                }
                if (studentExists) {
                    break;
                }
            }
            if (studentExists) {
                break;
            }
        }

        if (studentExists) {
            std::cout << "ID Hoc sinh da ton tai trong mot lop." << std::endl;
            std::cout << "Ban co muon nhap lai ID hoc sinh khac khong?" << std::endl;
            std::cout << "1. Co" << std::endl;
            std::cout << "2. Khong" << std::endl;
            std::cout << "Chon: ";
            int chon;
            std::cin >> chon;
            if (chon == 1) {
                continue; 
            } else {
                return;
            }
        }
        cout << "Nhap thong tin cua hoc sinh moi " << endl;
        // string IDclass;
        // std::getline(cin,IDclass);
        std::cout << "Ten hoc sinh: ";std::cin.ignore(); std::getline(std::cin, Name);
        std::cout << "Ngay sinh: "; std::cin >> date;
        std::cout << "Gioi tinh: "; std::cin >> Gender;
        std::cout << "Nhap ID lop hoc de them hoc sinh vao: ";
        std::cin >> maLopMoi;
        targetClass = nullptr; // Đặt lại targetClass
        for (int i = 0; i < dsClass.getSize(); ++i) {
            if (dsClass[i].getIDclass() == maLopMoi) {
                targetClass = &dsClass[i];
                break;
            }
        }

        if (!targetClass) {
            std::cout << "Khong tim thay lop co ID " << maLopMoi << std::endl;
            return;
        }

        dung = false;
    }
    Students newStudent;
    newStudent.setIDStudent(maHS);
    newStudent.setIDClass(maLopMoi);
    newStudent.setNameStudent(Name);
    newStudent.setGenderS(Gender);
    newStudent.setBirthdayS(date);
    targetClass->ListTeacher[0].ListStudents.pushBack(newStudent);
    std::cout << "Them hoc sinh vao lop " << maLopMoi << " thanh cong." << std::endl;
    ReadDataFromFile();
    std::cout << "================================================================" << std::endl;
}
// void StudentsManager::changeTeacherForClass() {
//     string maLop;
//     std::cout << "Nhap ID lop hoc can doi GVCN: ";
//     std::cin >> maLop;

//     ListClass* targetClass = nullptr;
//     for (int i = 0; i < dsClass.getSize(); ++i) {
//         if (dsClass[i].getIDclass() == maLop) {
//             targetClass = &dsClass[i];
//             break;
//         }
//     }

//     if (!targetClass) {
//         std::cout << "Khong co ID " << maLop << " trong tat ca cac lop." << std::endl;
//         return;
//     }
//     string IDTeacher, Name, Gender;
//     Date date;
//     bool dung = true;
//     Teacher GVmoi;
//     while (dung) {
//         std::cout << "Nhap ID giao vien moi cho lop: ";
//         std::cin >> IDTeacher;
//         // Kiểm tra xem ID giao vien mới đã tồn tại trong danh sách lớp hay chưa
//         bool gvMoiTonTai = false;
//         for (int i = 0; i < dsClass.getSize(); ++i) {
//             for (int j = 0; j < dsClass[i].ListTeacher.getSize(); ++j) {
//                 if (dsClass[i].ListTeacher[j].getIDTeacher() == IDTeacher) {
//                     gvMoiTonTai = true;
//                     break;
//                 }
//             }
//             if (gvMoiTonTai) {
//                 break;
//             }
//         }

//         if (gvMoiTonTai) {
//             std::cout << "ID giao vien moi da ton tai trong mot lop nao do." << std::endl;
//             std::cout << "Ban co muon nhap lai ID giao vien khac khong?" << std::endl;
//             std::cout << "1. Co" << std::endl;
//             std::cout << "2. Khong" << std::endl;
//             std::cout << "Chon: ";
//             int chon;
//             std::cin >> chon;
//             if (chon == 1) {
//                 continue; // Nhập lại ID nếu chọn 1
//             } else {
//                 return;
//                 //dung = false; // Thoát nếu chọn 2
//             }
//         } else {
//             dung = false; // Nếu không trùng, thoát khỏi vòng lặp
//         }
//     }
//     // Đặt các thông tin mới cho giáo viên 
//     MyVector<Students> lopdubi = targetClass->ListTeacher[0].ListStudents;
//     std::cout << "Nhap thong tin cho giao vien moi." << std::endl;
//     std::cout << "Ten giao vien: ";std::cin.ignore(); std::cin >> Name;
//     std::cout << "Ngay sinh: "; std::cin >> date;
//     std::cout << "Gioi tinh: "; std::cin >> Gender;std::cin.ignore();
//     GVmoi.setIDTeacher(IDTeacher);
//     GVmoi.setNameTeacher(Name);
//     GVmoi.setGenderT(Gender);
//     GVmoi.setBirthdayT(date);
//     GVmoi.setIDclass(maLop);
//     // targetClass->ListTeacher.clear();
//     // Thêm giáo viên mới vào danh sách giáo viên của lớp
//     targetClass->ListTeacher.pushBack(GVmoi);
//     targetClass->ListTeacher[0].ListStudents = lopdubi;
//     std::cout << "Doi giao vien chu nhiem cho lop " << maLop << " thanh cong." << std::endl;
//     //ReadDataFromFile();  // Đọc dữ liệu từ file (giả sử hàm này đã được triển khai)
//     std::cout << "================================================================" << std::endl;
// }
// void StudentsManager::changeTeacherForClass() {
//     string maLop;
//     std::cout << "Nhap ID lop hoc can doi GVCN: ";
//     std::cin >> maLop;
//     ListClass* targetClass = nullptr;
//     for (int i = 0; i < dsClass.getSize(); ++i) {
//         if (dsClass[i].getIDclass() == maLop) {
//             targetClass = &dsClass[i];
//             break;
//         }
//     }

//     if (!targetClass) {
//         std::cout << "Khong co ID " << maLop << " trong tat ca cac lop." << std::endl;
//         return;
//     }
//     string IDTeacher, Name, Gender;
//     Date date;
//     bool dung = true;
//     while (dung) {
//         std::cout << "Nhap ID giao vien moi cho lop: ";
//         std::cin >> IDTeacher;
//         // Kiểm tra xem ID giao vien mới đã tồn tại trong tất cả các lớp hay chưa
//         bool gvMoiTonTai = false;
//         for (int i = 0; i < dsClass.getSize(); ++i) {
//             for (int j = 0; j < dsClass[i].ListTeacher.getSize(); ++j) {
//                 if (dsClass[i].ListTeacher[j].getIDTeacher() == IDTeacher) {
//                     gvMoiTonTai = true;
//                     break;
//                 }
//             }
//             if (gvMoiTonTai) {
//                 break;
//             }
//         }
//         // Nếu ID giáo viên mới đã tồn tại
//         if (gvMoiTonTai) {
//             std::cout << "ID giao vien moi da ton tai trong mot lop nao do." << std::endl;
//             std::cout << "Ban co muon nhap lai ID giao vien khac khong?" << std::endl;
//             std::cout << "1. Co" << std::endl;
//             std::cout << "2. Khong" << std::endl;
//             std::cout << "Chon: ";
//             int chon;
//             std::cin >> chon;

//             if (chon == 1) {
//                 continue; // Nhập lại ID nếu chọn 1
//             } else {
//                 return; // Thoát nếu chọn 2
//             }
//         } 
//         else {
//             dung = false; // Nếu không trùng, thoát khỏi vòng lặp
//         }
//     }
//     // Lưu trữ danh sách học sinh của giáo viên cũ
//     MyVector<Students> lopdubi = targetClass->ListTeacher[0].ListStudents;

//     // Tạo giáo viên mới
//     Teacher GVmoi;
//     GVmoi.setIDTeacher(IDTeacher);
//     std::cout << "Ten giao vien: "; std::cin >> Name;
//     std::cout << "Ngay sinh: "; std::cin >> date;
//     std::cout << "Gioi tinh: "; std::cin >> Gender;
//     GVmoi.setNameTeacher(Name);
//     GVmoi.setGenderT(Gender);
//     GVmoi.setBirthdayT(date);
//     GVmoi.setIDclass(maLop);
//     // Thêm giáo viên mới vào danh sách giáo viên của lớp
//     targetClass->ListTeacher.clear(); // Xóa danh sách giáo viên cũ
//     targetClass->ListTeacher.pushBack(GVmoi);

//     // Giữ nguyên học sinh trong lớp
//     targetClass->ListTeacher[0].ListStudents = lopdubi;
//     cout << GVmoi.getIDTeacher();
//     std::cout << "Doi giao vien chu nhiem cho lop " << maLop << " thanh cong." << std::endl;
//     ReadDataFromFile();  // Đọc dữ liệu từ file (giả sử hàm này đã được triển khai)
//     std::cout << "================================================================" << std::endl;
// }
void StudentsManager::changeTeacherForClass(){
    string malop;
    std::cout << "Nhap ID lop hoc can doi GVCN: " ;
    std::cin >> malop;
    ListClass* lop = nullptr;
    MyVector<Students> lopdubi;
    for (int i = 0; i < dsClass.getSize(); i++){
        if (dsClass[i].getIDclass() == malop){
            lop = &dsClass[i];
            lopdubi = lop->ListTeacher[i].ListStudents;
            lop->ListTeacher.remove(i);
            // cout << lop->ListTeacher[i].getNameTeacher();
            break;
        }
    }
    if (!lop){
        std::cout << "Khong co ID " << malop << " trong tat ca cac lop. " << endl;
        return;
    }
    // std::cout << "Nhap ID GVCN can chuyen ra: ";
    // std::std::cin >> magv;
    // // std::cout << "-----------------------------------------------" << endl;
    // Teacher *teacherold = nullptr;
    // for (int i = 0; i < lop->ListTeacher.getSize(); i++){
    //     if (lop->ListTeacher[i].getIDTeacher() == magv){
    //         teacherold = &lop->ListTeacher[i];
    //         break;
    //     }
    // }
    // if (!teacherold){
    //     std::cout << "Khong tim thay GVCN co ID " << magv << " de doi. " << endl;
    //     return;
    // }
    // MyVector<Students> lopdubi;
    // for (int i = 0; i < lop->ListTe;acher.getSize(); ++i) {
    //     if (lop->ListTeacher[i].getIDTeacher() == magv) {
    //         lopdubi = lop->ListTeacher[i].ListStudents;
    //         lop->ListTeacher.remove(i);
    //         break;
    //     }
    // }
    string IDclass, IDTeacher, Name, Gender;
    Date date;
    std::cout << "Nhap thong tin giao vien chu nhiem moi: " << endl;
    std::getline(std::cin, IDclass);
    std::cout << "ID giao vien: "; std::getline(std::cin, IDTeacher);
    std::cout << "Ten giao vien: "; std::getline(std::cin, Name);
    std::cout << "Ngay sinh: "; std::cin >> date;
    std::cout << "Gioi tinh: "; std::cin >> Gender;
    Teacher GVmoi;
    GVmoi.setIDTeacher(IDTeacher);
    GVmoi.setNameTeacher(Name);
    GVmoi.setGenderT(Gender);
    GVmoi.setBirthdayT(date);
    bool GVdaco = false;
    for (int k = 0; k < lop->ListTeacher.getSize(); k++) {
        if (lop->ListTeacher[k].getIDTeacher() == GVmoi.getIDTeacher()) {
            GVdaco = true;
            string newIDGV;
            std::cout << "ID giao vien da ton tai, nhap ID giao vien moi: ";
            std::cin >> newIDGV;
            GVmoi.setIDTeacher(newIDGV);
            if (newIDGV == lop->ListTeacher[k].getIDTeacher()){
                std::cout << "ID giao vien da ton tai, thoat. ";
                return;
            }
            else {
                GVmoi.setIDTeacher(newIDGV);
                GVmoi.ListStudents = lopdubi;
                lop->ListTeacher.pushBack(GVmoi);
                std::cout << "Doi giao vien chu nhiem thanh cong." << endl;
                ReadDataFromFile();
                std::cout << "================================================================" << endl;
                return;
            }
        }
        // break;
        // return;
        // else{
            // GVmoi.ListStudents = lopdubi;
        // }
    }
    GVmoi.ListStudents = lopdubi;
    lop->ListTeacher.pushBack(GVmoi);
    std::cout << "Doi giao vien chu nhiem thanh cong." << endl;
    ReadDataFromFile();
    std::cout << "================================================================" << endl;
    // for (int i = 0; i < dsClass.getSize(); i++) {
    //     std::cout << "================================================================" << endl;
    //     std::cout << "ID lop hoc: "<< dsClass[i].getIDclass() << endl;
    //     std::cout << "Giao vien chu nhiem: " << dsClass[i].ListTeacher[i].getIDTeacher() << "--"
    //     << dsClass[i].ListTeacher[i].getNameTeacher() << endl;
    //     std::cout << "Danh sach hoc sinh cua lop: " << endl;
    //     std::cout << "ID     " << "|Ten hoc sinh         " << "|Ngay sinh " << "|Gioi tinh" << endl;
    //         for (int j = 0; j < dsClass[i].ListTeacher[i].ListStudents.getSize(); ++j) {
    //         std::cout << left << setw(7) << dsClass[i].ListTeacher[i].ListStudents[j].getIDStudent() << "|"  << left <<  setw(21) << dsClass[i].ListTeacher[i].ListStudents[j].getNameStudent() << "|"
    //         << dsClass[i].ListTeacher[i].ListStudents[j].getBirthdayS() << "|" << left << setw(6) << dsClass[i].ListTeacher[i].ListStudents[j].getGenderS() << endl;
    //     }
    //     std::cout << endl;
    //     }
    // std::cout << "Doi giao vien chu nhiem thanh cong." << endl;
    // ReadDataFromFile();
    // std::cout << "================================================================" << endl;
}

void StudentsManager::addSubjectandScoreforStudent() {
    string mahs;
    std::cout << "Nhap ID hoc sinh can them mon hoc: ";
    std::cin >> mahs;
    Students *HS = nullptr;
    for (int i = 0; i < dsClass.getSize(); i++) {
        for (int j = 0; j < dsClass[i].ListTeacher.getSize(); j++) {
            for (int k = 0; k < dsClass[i].ListTeacher[j].ListStudents.getSize();k++) {
                if (dsClass[i].ListTeacher[j].ListStudents[k].getIDStudent() == mahs) {
                    HS = &dsClass[i].ListTeacher[j].ListStudents[k];
                    string idSubject;
                    float score;
                    std::cout << "Nhap ID mon hoc: ";
                    std::cin >> idSubject;
                    Subject* sub = nullptr;
                    bool subjectExists = false;
                    for (int t = 0; t < HS->ListSubject.getSize(); t++) {
                        if (HS->ListSubject[t].getSubject() == idSubject) {
                        sub = &HS->ListSubject[t];
                        subjectExists = true;
                        break;
                        }
                    }
                    if (subjectExists) {
                        std::cout << "Mon hoc nay da ton tai cho hoc sinh." << endl;
                        return;
                    }
                    std::cout << "Nhap diem cho mon hoc " << idSubject << ": ";
                    std::cin >> score;
                    if (score < 0.0 || score > 10.0) {
                        std::cout << "Diem khong hop le. Nhap lai diem trong khoang tu 0.0 den 10.0." << endl;
                        return;
                    }
                    Subject newSubject;
                    newSubject.setSubject(idSubject);
                    newSubject.setScore(score);
                    HS->ListSubject.pushBack(newSubject);
                    // std::std::cout << "Tim thay hoc sinh trong lop " << lop.getIDclass() << std::endl;
                    // std::std::cout << "ID: " << HS.getIDStudent() << std::endl;
                    std::cout << "Ten: " << HS->getNameStudent() << std::endl;
                    std::cout << "|Mon  " << "|Diem" << endl;
                    for (int l = 0; l < HS->ListSubject.getSize(); l++ ){
                        std::cout << left << setw(6) << HS->ListSubject[l].getSubject() 
                        << "|" << left << setw(4) << HS->ListSubject[l].getScore() << endl;
                    }
                }
            }
        }
    }
    std::cout << "Them mon hoc thanh cong." << endl;
    std::cout << "================================================================" << endl;
    ReadDataScoreFromFile();
    if (!HS){
        std::cout << "Khong co ID " << mahs << " nay trong lop." << endl;
    }
    // std::cout << "Them mon hoc thanh cong." << endl;
    // // ShowSTandSub();
    // ReadDataScoreFromFile();
}
// void StudentsManager::addSubjectandScoreforStudent() {
//     string mahs;
//     std::cout << "Nhap ID hoc sinh moi can them mon hoc: ";
//     std::cin >> mahs;
//     Students *HS = nullptr;
//     for (int i = 0; i < dsClass.getSize(); i++) {
//         for (int j = 0; j < dsClass[i].ListTeacher.getSize(); j++) {
//             for (int k = 0; k < dsClass[i].ListTeacher[j].ListStudents.getSize();k++) {
//                 if (dsClass[i].ListTeacher[j].ListStudents[k].getIDStudent() == mahs) {
//                     HS = &dsClass[i].ListTeacher[j].ListStudents[k];
//                     // string idSubject;
//                     float score;
//                     // std::cout << "Nhap ID mon hoc: ";
//                     // std::std::cin >> idSubject;
//                     // Subject* sub = nullptr;
//                     // bool subjectExists = false;
//                     // for (int t = 0; t < HS->ListSubject.getSize(); t++) {
//                     //     if (HS->ListSubject[t].getSubject() == idSubject) {
//                     //     sub = &HS->ListSubject[t];
//                     //     subjectExists = true;
//                     //     break;
//                     //     }
//                     // }
//                     // if (subjectExists) {
//                     //     std::cout << "Mon hoc nay da ton tai cho hoc sinh." << endl;
//                     //     return;
//                     // }
//                     if ( int r = 0; r < 3; r++){
//                         std::cout << "Nhap diem cho mon hoc " << "toan " << ": ";
//                         std::cin >> score;
//                         if (score < 0.0 || score > 10.0) {
//                             std::cout << "Diem khong hop le. Nhap lai diem trong khoang tu 0.0 den 10.0." << endl;
//                             return;
//                         }
//                     }
//                     // std::cout << "Nhap diem cho mon hoc " << idSubject << ": ";
//                     // std::std::cin >> score;
//                     // if (score < 0.0 || score > 10.0) {
//                     //     std::cout << "Diem khong hop le. Nhap lai diem trong khoang tu 0.0 den 10.0." << endl;
//                     //     return;
//                     // }
//                     Subject newSubject;
//                     // newSubject.setSubject(idSubject);
//                     newSubject.setScore(score);
//                     HS->ListSubject.pushBack(newSubject);
//                     // std::std::cout << "Tim thay hoc sinh trong lop " << lop.getIDclass() << std::endl;
//                     // std::std::cout << "ID: " << HS.getIDStudent() << std::endl;
//                     std::cout << "Ten: " << HS->getNameStudent() << std::endl;
//                     std::cout << "|Mon  " << "|Diem" << endl;
//                     for (int l = 0; l < HS->ListSubject.getSize(); l++ ){
//                         // std::cout << left << setw(6) << HS->ListSubject[l].getSubject() 
//                         cout << "|" << left << setw(4) << HS->ListSubject[l].getScore() << endl;
//                     }
//                 }
//             }
//         }
//     }
//     std::cout << "Them mon hoc thanh cong." << endl;
//     std::cout << "================================================================" << endl;
//     ReadDataScoreFromFile();
//     if (!HS){
//         std::cout << "Khong co ID " << mahs << " nay trong lop." << endl;
//     }
//     // std::cout << "Them mon hoc thanh cong." << endl;
//     // // ShowSTandSub();
//     // ReadDataScoreFromFile();
// }
// void StudentsManager::addSubjectandScoreforStudent() {
// std::string maHS;
//     double diem;
//     bool dung = true;
//     Students* targetStudent = nullptr;

//     while (dung) {
//         std::cout << "Nhap ID hoc sinh can them mon hoc va diem: ";
//         std::cin >> maHS;

//         // Tìm học sinh trong danh sách lớp
//         for (int i = 0; i < dsClass.getSize(); ++i) {
//             ListClass& lop = dsClass[i];
//             for (int j = 0; j < lop.ListTeacher.getSize(); ++j) {
//                 Teacher& GV = lop.ListTeacher[j];
//                 for (int k = 0; k < GV.ListStudents.getSize(); ++k) {
//                     Students& HS = GV.ListStudents[k];
//                     if (HS.getIDStudent() == maHS) {
//                         targetStudent = &HS;
//                         break;
//                     }
//                 }
//                 if (targetStudent) {
//                     break;
//                 }
//             }
//             if (targetStudent) {
//                 break;
//             }
//         }

//         // Nếu không tìm thấy học sinh
//         if (!targetStudent) {
//             std::cout << "Khong tim thay hoc sinh co ID " << maHS << "." << std::endl;
//             return;
//         }

//         // Kiểm tra xem học sinh đã có môn và điểm hay chưa
//         if (!targetStudent->ListSubject.isEmpty()) {
//             std::cout << "Hoc sinh da co mon hoc va diem." << std::endl;
//             return;
//         }

//         // Chọn một học sinh bất kỳ có mã môn và sử dụng mã môn đó
//         if (dsClass.getSize() > 0) {
//             const Students& sampleStudent = dsClass[0].ListTeacher[0].ListStudents[0];
//             if (!sampleStudent.ListSubject.isEmpty()) {
//                 // Sử dụng một biến không const để truy cập phần tử
//                 Subject& sampleSubject = targetStudent->ListSubject[0];
//                 std::string maMon = sampleSubject.getSubject();
        
//                 // Nhập điểm cho môn học
//                 std::cout << "Nhap diem cho mon hoc " << maMon << ": ";
//                 std::cin >> diem;

//                 // Tạo môn học và điểm cho học sinh
//                 Subject monHoc;
//                 monHoc.setSubject(maMon);
//                 monHoc.setScore(diem);

//                 // Thêm môn học vào danh sách môn của học sinh
//                 targetStudent->ListSubject.pushBack(monHoc);

//                 std::cout << "Them mon hoc va diem cho hoc sinh " << maHS << " thanh cong." << std::endl;
//                 // Đọc dữ liệu từ file (giả sử hàm này đã được triển khai)
//                 ReadDataFromFile();
//                 std::cout << "================================================================" << std::endl;

//                 dung = false; // thoát khỏi vòng lặp sau khi thêm thành công
//             } else {
//                 std::cout << "Khong co mon hoc nao de lay ma." << std::endl;
//                 return;
//             }
//         } else {
//             std::cout << "Khong co lop hoc." << std::endl;
//             return;
//         }
//     }
// }
void StudentsManager::CCAverageScore() {
    Students* student = nullptr;
    for (int i = 0; i < dsClass.getSize(); i++) {
        for (int j = 0; j < dsClass[i].ListTeacher.getSize(); j++) {
            for (int k = 0; k < dsClass[i].ListTeacher[j].ListStudents.getSize(); k++) {
                student = &dsClass[i].ListTeacher[j].ListStudents[k];
                if (student->ListSubject.getSize() > 0) {
                    float totalScore = 0.0;
                    for (int m = 0; m < student->ListSubject.getSize(); m++) {
                        totalScore += student->ListSubject[m].getScore();
                    }
                    float averageScore = totalScore / student->ListSubject.getSize();
                    // std::std::cout << "ID hoc sinh: " << student->getIDStudent()
                    //           << ", Diem trung binh: " << std::fixed << std::setprecision(2) << student->DTB(averageScore)
                    //           << std::endl;
                    student->setDTB(averageScore);
                } 
                else {
                    std::cout << "ID hoc sinh: " << student->getIDStudent()
                              << ", Khong co diem trung binh vi khong co mon hoc" << std::endl;
                }
            }
        }
    }
}
void StudentsManager::sortStudentsByAverageScoreTD() {
    CCAverageScore(); // Tính điểm trung bình trước khi sắp xếp

    for (int i = 0; i < dsClass.getSize(); i++) {
        ListClass* lop = nullptr; 
        lop = &dsClass[i];
        if (lop) {
            for (int j = 0; j < lop->ListTeacher.getSize(); j++) {
                Teacher* teacher = nullptr;
                teacher  = &lop->ListTeacher[j];
                if (teacher) {
                    // Sắp xếp học sinh trong lớp theo điểm trung bình tăng dần
                    for (int m = 0; m < teacher->ListStudents.getSize() - 1; m++) {
                        for (int n = 0; n < teacher->ListStudents.getSize() - m - 1; n++) {
                            if (teacher->ListStudents[n].getDTB() > teacher->ListStudents[n + 1].getDTB()) {
                                // Swap students[n] và students[n + 1]
                                Students temp;
                                temp = teacher->ListStudents[n];
                                teacher->ListStudents[n] = teacher->ListStudents[n + 1];
                                teacher->ListStudents[n + 1] = temp;
                            }
                        }
                    }
                } 
                else if (!teacher){
                    std::cout << "Khong co giao vien trong lop." << std::endl;
                    // break;
                }
            }
        } 
        else if(!lop){
            std::cout << "Khong co lop hoc." << std::endl;
            // break;
        }
    }
}

void StudentsManager::sortStudentsByAverageScoreGD() {
    CCAverageScore(); // Tính điểm trung bình trước khi sắp xếp

    for (int i = 0; i < dsClass.getSize(); i++) {
        ListClass* lop = nullptr; 
        lop = &dsClass[i];
        if (lop) {
            for (int j = 0; j < lop->ListTeacher.getSize(); j++) {
                Teacher* teacher = nullptr;
                teacher  = &lop->ListTeacher[j];
                if (teacher) {
                    // Sắp xếp học sinh trong lớp theo điểm trung bình tăng dần
                    for (int m = 0; m < teacher->ListStudents.getSize() - 1; m++) {
                        for (int n = 0; n < teacher->ListStudents.getSize() - m - 1; n++) {
                            if (teacher->ListStudents[n].getDTB() < teacher->ListStudents[n + 1].getDTB()) {
                                // Swap students[n] và students[n + 1]
                                Students temp;
                                temp = teacher->ListStudents[n];
                                teacher->ListStudents[n] = teacher->ListStudents[n + 1];
                                teacher->ListStudents[n + 1] = temp;
                            }
                        }
                    }
                } 
                else if (!teacher){
                    std::cout << "Khong co giao vien trong lop." << std::endl;
                    break;
                }
            }
        } 
        else if(!lop){
            std::cout << "Khong co lop hoc." << std::endl;
            break;
        }
    }
}
void StudentsManager::ShowAllScoreandDTB(){
    CCAverageScore();
    for (int i = 0; i < dsClass.getSize(); i++) {
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "================================================================" << endl;
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left  << "ID Teacher: "<< dsClass[i].getIDclass() << endl;
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left  << "Giao vien chu nhiem: " << dsClass[i].ListTeacher[i].getIDTeacher() << "--"
        << dsClass[i].ListTeacher[i].getNameTeacher() << endl;
        // std::std::cout << "Danh sach hoc sinh kem diem cua Teacher: " << endl;
        for (int j = 0; j < dsClass[i].ListTeacher[i].ListStudents.getSize(); ++j) {
            std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Hoc sinh: " << dsClass[i].ListTeacher[i].ListStudents[j].getIDStudent();
            std::cout << "--" << dsClass[i].ListTeacher[i].ListStudents[j].getNameStudent()  << endl;
            std::cout << "\t\t\t\t" << setfill(' ') << setw(6) << left  << "|Mon   " << "|Diem" << endl;
            for (int k = 0; k < dsClass[i].ListTeacher[i].ListStudents[j].ListSubject.getSize(); k++){
                //std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left  << left << setw(7) <<  dsClass[i].ListTeacher[i].ListStudents[j].ListSubject[k].getSubject() ;
                std::cout << "|" << left << setw(4) <<  dsClass[i].ListTeacher[i].ListStudents[j].ListSubject[k].getScore() << endl;
            }
            std::cout << "\t\t\t\t" << setfill(' ') << setw(6) << left << "|DTB   " 
            << "|" << left << setw(4) << std::fixed << std::setprecision(2) << dsClass[i].ListTeacher[i].ListStudents[j].getDTB() << endl;  
            std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left  << "----------------------------------------------------------------" << endl;
        }
        std::cout << endl;
    }
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left  <<"================================================================" << endl;
}
void StudentsManager::ShowOnlyDTB(){
    CCAverageScore();
    for (int i = 0; i < dsClass.getSize(); i++) {
    std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "================================================================" << endl;
    std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "ID Teacher: " << dsClass[i].getIDclass() << endl;

        for (int j = 0; j < dsClass[i].ListTeacher.getSize(); j++) { // Dùng dsClass[i].ListTeacher.getSize() thay vì dsClass[i].ListTeacher[i]
            std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Giao vien chu nhiem: " << dsClass[i].ListTeacher[j].getIDTeacher() << "--"
            << dsClass[i].ListTeacher[j].getNameTeacher() << endl;

            for (int k = 0; k < dsClass[i].ListTeacher[j].ListStudents.getSize(); k++) {
                Students& student = dsClass[i].ListTeacher[j].ListStudents[k];
                std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Hoc sinh: " << student.getIDStudent();
                std::cout << "--" << student.getNameStudent() << endl;
                std::cout << "\t\t\t\t" << setfill(' ') << setw(6) << left << "|DTB   " 
                << "|" << left << setw(4) << std::fixed << std::setprecision(2) << student.getDTB() << endl;  
                std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "----------------------------------------------------------------" << endl;
            }
        }
    }
    std::cout << endl;
}
void StudentsManager::DisplaySortedStudentsTD() {
    sortStudentsByAverageScoreTD(); // Sắp xếp học sinh trước khi hiển thị
    std::cout << "Danh sach hoc sinh sau khi sap xep theo cac lop voi thu tu tang dan DTB" << endl;
    for (int i = 0; i < dsClass.getSize(); i++) {
    std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "================================================================" << endl;
    std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "ID Teacher: " << dsClass[i].getIDclass() << endl;

    for (int j = 0; j < dsClass[i].ListTeacher.getSize(); j++) { // Dùng dsClass[i].ListTeacher.getSize() thay vì dsClass[i].ListTeacher[i]
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Giao vien chu nhiem: " << dsClass[i].ListTeacher[j].getIDTeacher() << "--"
            << dsClass[i].ListTeacher[j].getNameTeacher() << endl;

        for (int k = 0; k < dsClass[i].ListTeacher[j].ListStudents.getSize(); k++) {
            Students& student = dsClass[i].ListTeacher[j].ListStudents[k];
            std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Hoc sinh: " << student.getIDStudent();
            std::cout << "--" << student.getNameStudent() << endl;

            std::cout << "\t\t\t\t" << setfill(' ') << setw(6) << left << "|DTB   " 
                << "|" << left << setw(4) << std::fixed << std::setprecision(2) << student.getDTB() << endl;  
            std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "----------------------------------------------------------------" << endl;
        }
    }
    std::cout << endl;
    }
}
void StudentsManager::DisplaySortedStudentsGD() {
    sortStudentsByAverageScoreGD(); // Sắp xếp học sinh trước khi hiển thị
    std::cout << "Danh sach hoc sinh sau khi sap xep theo cac lop voi thu tu giam dan DTB" << endl;
    for (int i = 0; i < dsClass.getSize(); i++) {
    std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "================================================================" << endl;
    std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "ID Teacher: " << dsClass[i].getIDclass() << endl;

    for (int j = 0; j < dsClass[i].ListTeacher.getSize(); j++) { // Dùng dsClass[i].ListTeacher.getSize() thay vì dsClass[i].ListTeacher[i]
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Giao vien chu nhiem: " << dsClass[i].ListTeacher[j].getIDTeacher() << "--"
            << dsClass[i].ListTeacher[j].getNameTeacher() << endl;

        for (int k = 0; k < dsClass[i].ListTeacher[j].ListStudents.getSize(); k++) {
            Students& student = dsClass[i].ListTeacher[j].ListStudents[k];
            std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Hoc sinh: " << student.getIDStudent();
            std::cout << "--" << student.getNameStudent() << endl;

            std::cout << "\t\t\t\t" << setfill(' ') << setw(6) << left << "|DTB   " 
                << "|" << left << setw(4) << std::fixed << std::setprecision(2) << student.getDTB() << endl;  
            std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "----------------------------------------------------------------" << endl;
        }
    }
    std::cout << endl;
    }
}
void StudentsManager::sortAllStudentsByAverageScoreTD() {
    CCAverageScore();
    MyVector<Students> allStudents;
    for (int i = 0; i < dsClass.getSize(); i++) {
        for (int j = 0; j < dsClass[i].ListTeacher.getSize(); j++) {
            ListClass *lop = nullptr;
            lop = &dsClass[i];
            Teacher *teacher = nullptr;
            teacher = &lop->ListTeacher[j];
            for (int k = 0; k < teacher->ListStudents.getSize(); k++) {
                allStudents.pushBack(teacher->ListStudents[k]);
            }
        }
    }
    for (int m = 0; m < allStudents.getSize() - 1; m++) {
        for (int n = 0; n < allStudents.getSize() - m - 1; n++) {
            if (allStudents[n].getDTB() > allStudents[n + 1].getDTB()) {
                // Swap allStudents[n] và allStudents[n + 1]
                Students temp;
                temp = allStudents[n];
                allStudents[n] = allStudents[n + 1];
                allStudents[n + 1] = temp;
            }
        }
    }
    std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Danh sach hoc sinh sau khi sap xep tat ca cac lop theo thu tu tang dan DTB:" << endl;
    std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "----------------------------------------------------------------" << endl;
    for (int e = 0; e < allStudents.getSize(); e++) {
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Hoc sinh: " << allStudents[e].getIDStudent();
            std::cout << "--" << allStudents[e].getNameStudent() << endl;

            std::cout << "\t\t\t\t" << setfill(' ') << setw(6) << left << "|DTB   " 
                << "|" << left << setw(4) << std::fixed << std::setprecision(2) << allStudents[e].getDTB() << endl;  
            std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "----------------------------------------------------------------" << endl;
    }
    
}
void StudentsManager::sortAllStudentsByAverageScoreGD() {
    CCAverageScore();
    MyVector<Students> allStudents;
    for (int i = 0; i < dsClass.getSize(); i++) {
        for (int j = 0; j < dsClass[i].ListTeacher.getSize(); j++) {
            ListClass *lop = nullptr;
            lop = &dsClass[i];
            Teacher *teacher = nullptr;
            teacher = &lop->ListTeacher[j];
            for (int k = 0; k < teacher->ListStudents.getSize(); k++) {
                allStudents.pushBack(teacher->ListStudents[k]);
            }
        }
    }
    for (int m = 0; m < allStudents.getSize() - 1; m++) {
        for (int n = 0; n < allStudents.getSize() - m - 1; n++) {
            if (allStudents[n].getDTB() < allStudents[n + 1].getDTB()) {
                // Swap allStudents[n] và allStudents[n + 1]
                Students temp;
                temp = allStudents[n];
                allStudents[n] = allStudents[n + 1];
                allStudents[n + 1] = temp;
            }
        }
    }
    std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Danh sach hoc sinh sau khi sap xep tat ca cac lop theo thu tu giam dan DTB:" << endl;
    std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "----------------------------------------------------------------" << endl;
    for (int e = 0; e < allStudents.getSize(); e++) {
        std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Hoc sinh: " << allStudents[e].getIDStudent();
            std::cout << "--" << allStudents[e].getNameStudent() << endl;

            std::cout << "\t\t\t\t" << setfill(' ') << setw(6) << left << "|DTB   " 
                << "|" << left << setw(4) << std::fixed << std::setprecision(2) << allStudents[e].getDTB() << endl;  
            std::cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "----------------------------------------------------------------" << endl;
    }
    
}