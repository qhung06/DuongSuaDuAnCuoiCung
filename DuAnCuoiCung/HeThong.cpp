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
	char choice;
	do
	{
		
		cout << "=====MENU HE THONG QUAN LY BAI DO XE=====" << endl;
		cout << "1. Them xe vao bai" << endl;
		cout << "2. Xuat xe khoi bai" << endl;
		cout << "3. Danh sach xe dang do tai bai" << endl;
		cout << "4. Kiem tra cho trong" << endl;
		cout << "0. Thoat" << endl;
		cout << "---------Ngay " <<ngaylamviec.getngay()<<" Thang "<< ngaylamviec.getthang()<<" Nam "<< ngaylamviec.getnam() << "---------" << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case '1':
			bdx.themxe(ngaylamviec);
			system("cls");
			break;
		case '2':
			bdx.xuatxe(ngaylamviec);
			system("cls");
			break;
		case '3':
			bdx.danhsachxe();
			system("pause");
			system("cls");
			break;
		case '4':
			bdx.kiemtrachotrong();
			system("pause");
			system("cls");
			break;
		case '0':
			return;
		default:
			cout << "Lua chon khong hop le!" << endl;
			system("cls");
			continue;
		}

	} while (true);

}
