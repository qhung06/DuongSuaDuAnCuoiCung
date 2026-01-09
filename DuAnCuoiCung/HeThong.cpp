#include "HeThong.h"
#include <cstdlib>

HeThong::HeThong()
{
}

void HeThong::menu()
{
	cout << "Nhap ngay lam viec(d/m/y) "<<endl;
	cin >> ngaylamviec;
	system("cls");
	int choice;
	do
	{
		
		cout << "=====MENU HE THONG QUAN LY BAI DO XE=====" << endl;
		cout << "1. Them xe vao bai" << endl;
		cout << "2. Xuat xe khoi bai" << endl;
		cout << "3. Danh sach xe dang do tai bai" << endl;
		cout << "4. Kiem tra cho trong" << endl;
		cout << "5. Tim kiem thong tin" << endl;
		cout << "6. Tinh doanh thu trong ngay bat ky" << endl;
		cout << "7. Thong tin bai do trong ngay lam viec" << endl;
		cout << "8. Hien thi xe da ra khoi bai" << endl;
		cout << "9. Thay doi ngay lam viec" << endl;
		cout << "0. Thoat" << endl;
		cout << "---------Ngay " <<ngaylamviec.getngay()<<" Thang "<< ngaylamviec.getthang()<<" Nam "<< ngaylamviec.getnam() << "---------" << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			bdx.themxe(ngaylamviec);
			system("cls");
			break;
		case 2:
			bdx.xuatxe(ngaylamviec);
			system("pause");
			system("cls");
			break;
		case 3:
			bdx.danhsachxe();
			system("pause");
			system("cls");
			break;
		case 4:
			bdx.kiemtrachotrong();
			system("pause");
			system("cls");
			break;
		case 5:
			bdx.timkiem();
			system("pause");
			system("cls");
			break;
		case 6:	
			bdx.tinhdoanhthu();
			system("pause");
			system("cls");
			break;
		case 7:
			bdx.thongtinravao(ngaylamviec);
			system("pause");
			system("cls");
			break;
		case 8:
			bdx.hienthixe();
			system("pause");
			system("cls");
			break;
		case 9:
			cout << "Nhap ngay lam viec moi (d/m/y): " << endl;
			cin >> ngaylamviec;
			system("cls");
			break;
		case 0:
			return;
		default:
			cout << "Lua chon khong hop le!" << endl;
			system("pause");
			system("cls");
			continue;
		}

	} while (true);

}
