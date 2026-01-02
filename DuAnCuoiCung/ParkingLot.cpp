#include "ParkingLot.h"
#include <fstream>
using namespace std;

ParkingLot::ParkingLot()
{
	for (int i = 0; i < 1000; i++)
	{
		ve[i] = new Ticket(i+1);
	}

	ifstream fin("in.txt");
	string type, plate;
	Xe* xe=nullptr;
	int id;
	Time timein;
	Date datein;
	while (fin >> id >> type >> plate >> timein >> datein)
	{
		if (type == "XeMay")
		{
			xe = new XeMay();
			xe->settype(type);
			xe->setplate(plate);
		}
		if (type == "Oto")
		{
			xe = new Oto();
			xe->settype(type);
			xe->setplate(plate);
		}
		themxe(timein, datein, *xe);
		n = id;
		
	}
}

void ParkingLot::themxe(Time timein, Date datein, Xe& xe)
{
	if (soluongxehienco < max)
	{
		ve[n]->taove(timein, datein, xe);
		soluongxehienco++;
		
	}
	else
	{
		cout << "Bai do xe da day!" << endl;
	}
}

void ParkingLot::xuatxe(int id, Time timeout, Date dateout)
{
	for (int i = 0; i < n; i++)
	{
		if (ve[i]->getid() == id)
		{
			ve[i]->xuatve(timeout, dateout);
			soluongxehienco--;
			return;
		}
	}
}

void ParkingLot::themxe(Date datein)
{
	Xe* xe;
	string type, plate;
	Time timein;
	cout << "1.Xe may" << endl;
	cout << "2.O to" << endl;
	cout << "0.Quay lai" << endl;
	char choice;
	cin >> choice;
	switch (choice)
	{
	case '1':
		xe = new XeMay();
		xe->settype("XeMay");
		cout << "Nhap bien so: ";
		cin >> plate;
		xe->setplate(plate);
		cout << "Nhap thoi gian vao: " << endl;
		cin >> timein;
		themxe(timein, datein, *xe);
		n++;
		break;
	case '2':
		xe = new Oto();
		xe->settype("Oto");
		cout << "Nhap bien so: ";
		cin >> plate;
		xe->setplate(plate);
		cout << "Nhap thoi gian vao: " << endl;
		cin >> timein;
		themxe(timein, datein, *xe);
		n++;
		break;
	case '0':
		break;
	default:
		cout << "Lua chon khong hop le!" << endl;
		break;
	}

	
}

	void ParkingLot::xuatxe(Date dateout)
	{
		int id;
		Time timeout;
		cout << "Nhap ID ve xe: ";
		cin >> id;
		cout << "Nhap thoi gian ra: " << endl;
		cin >> timeout;
		xuatxe(id, timeout, dateout);
		ofstream fout("in.txt");
		for (int i = 0; i < n; i++)
		{
			if (ve[i]->gettimeout().getphut() == 0 && ve[i]->gettimeout().getgio() == 0)
				fout << ve[i]->getid() << " " << ve[i]->getxe()->gettype() << " " << ve[i]->getxe()->getplate() << " " << ve[i]->gettimein().getgio() << " " << ve[i]->gettimein().getphut() << " " << ve[i]->getdatein().getngay() << " " << ve[i]->getdatein().getthang() << " " << ve[i]->getdatein().getnam() << endl;
		}
	}

	void ParkingLot::danhsachxe()
	{
		int dem=0;
		cout << "=====================DANH SACH XE DANG DO TAI BAI====================" << endl;
		for (int i = 0; i < n; i++)
		{
			if (ve[i]->gettimeout().getphut()==0 && ve[i]->gettimeout().getgio() == 0)
			{
				cout << "ID ve: " << ve[i]->getid()<<"   Loai: "<< ve[i]->getxe()->gettype() << "   Bien so: " << ve[i]->getxe()->getplate() << "   Thoi gian vao: " << ve[i]->gettimein() << " " << ve[i]->getdatein() << endl;
				dem++;
			}
		}
		if (dem == 0)
			cout << "Khong co xe nao dang do tai bai!" << endl;
	}