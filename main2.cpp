#include"StudentsManager.h"
#include<conio.h>
void Start();
void Choose();
StudentsManager m;
int main(){
    m.WriteDataFromFile();
    Start();
    Choose();
    system("pause");
    return 0;
}
void Start()
{
	system("cls");
    cout << setfill('_') << right;
    cout << "" << setw(72) <<"TRUONG DAI HOC BACH KHOA - DAI HOC DA NANG" << setw(30) << "" ;
    cout << "\n*" << setfill(' ') <<setw(65) << "== KHOA CONG NGHE THONG TIN =="  << setw(36) << "*" << endl;
    cout << "*" << setw(101) << "*";
    cout << "\n*" << setw(64) << "PBL2:  DO AN CO SO LAP TRINH" << setw(37) << "*"  << endl;
    cout << "*" <<  setw(60)<< "CHU DE: QUAN LI HOC SINH" << setw(41) << "*" << endl;
    cout << "*" << setw(101) << "*" << endl;
    cout << "*" << setw(45) << "GV HUONG DAN:" << setw(50) << left << "    Ths DO THI TUYET HOA" << right << setw(6) << "*" <<endl;
    cout << "*" <<setw(45) << "SINH VIEN THUC HIEN:" << setw(56) << "*" << endl;
    cout << "*" << setw(49) << left << "" << setw(51) << "TRAN THI THANH PHUONG"  << "*" << endl;
    cout << "*" << setw(49) << left << "" << setw(51) << "HOANG HUONG BINH"  << "*" << endl;
    cout << "*" << setfill('_') <<right << setw(101) << "*" << endl;
}
void Choose()
{
    // m.WriteDataFromFile();
	while(true)
	{
		Start();
		cout << setfill(' ') << setw(31) << left << "" << "==============WELCOME==============" << endl << endl;
        cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "1. In danh sach hoc sinh cua cac lop\n";
        cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "2. Them hoc sinh vao danh sach\n";
        cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "3. Tim kiem hoc sinh trong tat ca cac lop\n";
        cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "4. Chuyen hoc sinh qua lop khac\n";
        cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "5. Xoa hoc sinh ra khoi lop\n";
        // cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "6. Doi giao vien chu nhiem\n";
		// cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "7. In danh sach mon cua tat ca hoc sinh\n";
		// cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "8. Them mon hoc va diem cho hoc sinh bat ki\n";
        // cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "9. Xem diem trung binh tat ca cac mon hoc cua hoc sinh\n";
        // cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "10. In ra danh sach da sap xep hoc sinh theo so diem trung binh cac mon\n";
        cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "0. Thoat\n";
        cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Lua chon cua ban: ";
		int yeucau;
		cin >> yeucau;
		switch(yeucau)
		{
			case 1: 
			{
				m.Display();
                system("pause");
				break;
			}
			case 2: 
			{
				m.addStudent();
                system("pause");
				break;
			}
			case 3:
			{
                m.searchStudentByID();
                system("pause");
				break;
			}
			case 4:
			{
                m.changeStudentToOtherClass();
                system("pause");
				break;
			}
			case 5:
			{
				m.removeStudents();
                system("pause");
				break;
			}
            // case 6:
			// {
			// 	m.changeTeacherForClass();
            //     system("pause");
			// 	break;
			// }
			// case 7:
			// {
			// 	m.ShowSTandSub();
            //     system("pause");
			// 	break;;
			// }
			// case 8:
			// {
            //     m.addSubjectandScoreforStudent();
            //     system("pause");
            //     break;
			// }
            // case 9:
            // {
            //     cout << "a. Chi xem diem trung binh cua hoc sinh." << endl;
            //     cout << "b. Xem ca diem trung binh va tat ca cac mon." << endl;
            //     cout << "Xem theo cach: " ;
            //     char cach;
            //     cin >> cach;
            //     switch(cach){
            //         case 'a':
            //         {
            //             m.ShowOnlyDTB();
            //             system("pause");
            //             break;
            //         }
            //         case 'b':
            //         {
            //             m.ShowAllScoreandDTB();
            //             system("pause");
            //             break;
            //         }
            //         default:
			//         {
			// 	    cout << "Khong co lenh nay! Moi nhap lai. " << endl;
            //         }
            //     break;
            //     }
            //     break;
            // }
            // case 10:
            // {
            //     // cout << "c. Sap xep theo cac lop\n";
            //     // cout << "d. Sap xep theo tat ca cac lop\n";
            //     // cout << "Sap xep theo cach: ";
            //     // char a;
            //     // cin >> a;
            //     // switch(a)
            //     // {
            //     //     case 'c':
            //     //     {
            //     //         cout << "                   6. Sap xep theo thu tu tang dan DTB cac mon\n";
            //     //         cout << "                   7. Sap xep theo thu tu giam dan DTB cac mon\n";
            //     //         cout << "                   Sap xep theo cach: ";
            //     //         int b; cin >> b;
            //     //         switch(b)
            //     //         {
            //     //             case 6:
            //     //             {
            //     //                 m.sortStudentsByAverageScoreTD();
            //     //                 system("pause");
            //     //                 break;
            //     //             }
            //     //             case 7:
            //     //             {
            //     //                 m.sortStudentsByAverageScoreGD();
            //     //                 system("pause");
            //     //                 break;
            //     //             }
            //     //             default :
            //     //             {
            //     //                 cout << "Nhap lai\n";
            //     //                 break;
            //     //             }
            //     //             break;
            //     //         }
            //     //         break;
            //     //     }
            //     //     case 'd':
            //     //     {
            //     //         cout << "                   4. Sap xep theo thu tu tang dan DTB cac mon\n";
            //     //         cout << "                   5. Sap xep theo thu tu giam dan DTB cac mon\n";
            //     //         cout << "                   Sap xep theo cach: ";
            //     //         int c; cin >> c;
            //     //         switch(c)
            //     //         {
            //     //             case 4:
            //     //             {
            //     //                 m.sortAllStudentsByAverageScoreTD();
            //     //                 system("pause");
            //     //                 break;
            //     //             }
            //     //             case 5:
            //     //             {
            //     //                 m.sortAllStudentsByAverageScoreGD();
            //     //                 system("pause");
            //     //                 break;
            //     //             }
            //     //             default :
            //     //             {
            //     //                 cout << "Nhap lai\n";
            //     //                 break;
            //     //             }
            //     //             break;
            //     //         }
            //     //         break;
            //     //     }
            //     // }
            //     cout << "4. Sap xep theo thu tu tang dan DTB cac mon\n";
            //     cout << "5. Sap xep theo thu tu giam dan DTB cac mon\n";
            //     cout << "Sap xep theo cach: ";
            //     int c; cin >> c;
            //     switch(c)
            //     {
            //         case 4:{
            //              m.sortAllStudentsByAverageScoreTD();
            //             system("pause");
            //             break;
            //         }
            //         case 5:
            //         {
            //             m.sortAllStudentsByAverageScoreGD();
            //             system("pause");
            //             break;
            //         }
            //         default :
            //             {
            //             cout << "Nhap lai\n";
            //             break;
            //        }
            //     break;
            //     }
            // break;
            // }
            case 0:
            {
                return;
            }
			default:
			{
				cout << "\t\t\t\t" << setfill(' ') << setw(10) << left << "Khong co lenh nay! Moi nhap lai!";
				getch();
				Choose();
                // break;
			}
		}
	}
}