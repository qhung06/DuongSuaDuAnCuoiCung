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
		cout << "======================================================\n";
		cout << "       HE THONG QUAN LY BAI DO XE THONG MINH\n";
		cout << "======================================================\n";
		cout << " Ngay lam viec: " << ngaylamviec << endl;
		cout << " Tong so cho: " << MAXSLOT <<"	  	   So cho trong: "<<MAXSLOT - bdx.getsoxemay() - bdx.getsoxeoto() << endl;
		cout << "-------------------------------------------------------\n";
		cout << " 1. Tiep nhan xe vao bai\n";
		cout << " 2. Tra xe - tinh tien tu dong\n";
		cout << " 3. Danh sach xe dang gui\n";
		cout << " 4. Kiem tra so cho trong\n";
		cout << " 5. Tim kiem thong tin ve\n";
		cout << " 6. Thong ke doanh thu theo ngay bat ky\n";
		cout << " 7. Bao cao tong hop ngay\n";
		cout << " 8. Xem lich su xe ra vao\n";
		cout << " 9. Thay doi ngay lam viec\n";
		cout << " 0. Thoat chuong trinh\n";
		cout << "======================================================\n";
		cout << " Vui long chon chuc nang: ";
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
