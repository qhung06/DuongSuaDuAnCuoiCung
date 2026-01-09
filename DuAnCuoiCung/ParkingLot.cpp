#include "ParkingLot.h"
#include <iostream>
#include <fstream>


using namespace std;

// ================= CONSTRUCTOR =================
ParkingLot::ParkingLot()
{
    n = 0;
    max = 1000;
	soxemay = 0;
	soxeoto = 0;

    for (int i = 0; i < max; i++)
        ve[i] = nullptr;

    ifstream finIn("in.txt");
    ifstream finOut("out.txt");

    int id;
    string type, plate;
    Time timein, timeout;
    Date datein, dateout;
    Xe* xe = nullptr;

    // ----- ??c danh sách xe ?ang trong bãi -----
    while (finIn >> id >> type >> plate >> timein >> datein)
    {
        ve[n] = new Ticket(id);

        if (type == "XeMay")
        {
            xe = new XeMay();
			soxemay++;

        }
        else 
            if (type == "Oto")
            {
                xe = new Oto();
                soxeoto++;
            }

        xe->settype(type);
        xe->setplate(plate);

        ve[n]->taove(timein, datein, *xe);

        delete xe;
        xe = nullptr;

        n++;
    }

    // ----- ??c danh sách xe ?ã xu?t -----
    while (finOut >> id >> type >> plate >> timein >> datein >> timeout >> dateout)
    {
        ve[n] = new Ticket(id);

        if (type == "XeMay") xe = new XeMay();
        else if (type == "Oto") xe = new Oto();

        xe->settype(type);
        xe->setplate(plate);

        ve[n]->taove(timein, datein, *xe);
        ve[n]->settimeout(timeout);
        ve[n]->setdateout(dateout);

        delete xe;
        xe = nullptr;

        n++;
    }
}

// ================= THÊM XE =================
void ParkingLot::themxe(const Date& datein)
{
    Xe* xe = nullptr;
    string plate;
    Time timein;
    char ch;
    if (soxemay >= MAXXEMAY && soxeoto >= MAXOTO)
    {
        cout << "Bai do xe da day!\n";
        system("pause");
        return;
    }
    else
    if (soxemay >= MAXXEMAY)
    {
        cout << "Xe may da day!\n";
        cout << "1. O to\n0. Quay lai\n";
        cin >> ch;
        system("cls");
        if (ch == '0') return;
        if (ch == '1')
        {
            xe = new Oto();
            soxeoto++;
        }
        else
        {
            cout << "Lua chon khong hop le!\n";
            system("pause");
            return;
        }
    }
    else
        if (soxeoto >= MAXOTO)
        {
            cout << "O to da day!\n";
            cout << "1. Xe may\n0. Quay lai\n";
            cin >> ch;
            system("cls");
            if (ch == '0') return;
            if (ch == '1')
            {
                xe = new XeMay();
                soxemay++;
            }
            else
            {
                cout << "Lua chon khong hop le!\n";
                system("pause");
                return;
            }
        }
        
        if (soxemay < MAXXEMAY && soxeoto < MAXOTO)
        {
            cout << "1. Xe may\n2. O to\n0. Quay lai\n";
            cin >> ch;
            system("cls");
            if (ch == '0') return;

            if (ch == '1')
            {
                xe = new XeMay();
                soxemay++;
            }
            else
                if (ch == '2')
                {
                    xe = new Oto();
                    soxeoto++;
                }
                else
                {
                    cout << "Lua chon khong hop le!\n";
                    system("pause");
                    return;
                }
        }
        cout << "Nhap bien so: ";
        cin >> plate;
        cout << "Nhap thoi gian vao (gio/phut): ";
        cin >> timein;
		system("cls");
		cout << "Them xe thanh cong!\n";
        system("pause");
        xe->setplate(plate);
        ve[n] = new Ticket(n + 1);
        ve[n]->taove(timein, datein, *xe);

        delete xe;
        n++;

        // ----- Ghi l?i file in.txt -----
        ofstream fout("in.txt");
        for (int i = 0; i < n; i++)
        {
            if (ve[i]->gettimeout().getgio() == 0 &&
                ve[i]->gettimeout().getphut() == 0)
            {
                fout << ve[i]->getid() << " "
                    << ve[i]->getxe()->gettype() << " "
                    << ve[i]->getxe()->getplate() << " "
                    << ve[i]->gettimein().getgio() << " "
                    << ve[i]->gettimein().getphut() << " "
                    << ve[i]->getdatein().getngay() << " "
                    << ve[i]->getdatein().getthang() << " "
                    << ve[i]->getdatein().getnam() << endl;
            }
        }

}

// ================= XUAT XE =================
void ParkingLot::xuatxe(const Date& dateout)
{
    int id;
    Time timeout;
	bool found = false;

    cout << "Nhap ID ve: ";
    cin >> id;
    for (int i = 0; i < n; i++)
    {
        if (ve[i]->getid() == id && 
            ve[i]->gettimeout().getgio() == 0 &&
            ve[i]->gettimeout().getphut() == 0)
            {
            found = true;
            break;
		    }
    }
    if (!found)
    {
        cout << "Khong tim thay xe dang do voi ID da nhap!\n";
        return;
	}
    cout << "Nhap thoi gian ra (gio/phut): ";
    cin >> timeout;

    for (int i = 0; i < n; i++)
    {
        if (ve[i]->getid() == id)
        {
            ve[i]->xuatve(timeout, dateout);
            if (ve[i]->getxe()->gettype() == "XeMay")
                soxemay--;
            else if (ve[i]->getxe()->gettype() == "Oto")
                soxeoto--;
            break;
        }
    }

    // ----- Ghi file in.txt -----
    ofstream fout("in.txt");
    for (int i = 0; i < n; i++)
    {
        if (ve[i]->gettimeout().getgio() == 0 &&
            ve[i]->gettimeout().getphut() == 0)
        {
            fout << ve[i]->getid() << " "
                << ve[i]->getxe()->gettype() << " "
                << ve[i]->getxe()->getplate() << " "
                << ve[i]->gettimein().getgio() << " "
                << ve[i]->gettimein().getphut() << " "
                << ve[i]->getdatein().getngay() << " "
                << ve[i]->getdatein().getthang() << " "
                << ve[i]->getdatein().getnam() << endl;
        }
    }


    // ----- Ghi file out.txt -----
    ofstream foutOut("out.txt");
    for (int i = 0; i < n; i++)
    {
        if (ve[i]->gettimeout().getgio() != 0 ||
            ve[i]->gettimeout().getphut() != 0)
        {
            foutOut << ve[i]->getid() << " "
                << ve[i]->getxe()->gettype() << " "
                << ve[i]->getxe()->getplate() << " "
                << ve[i]->gettimein().getgio() << " "
                << ve[i]->gettimein().getphut() << " "
                << ve[i]->getdatein().getngay() << " "
                << ve[i]->getdatein().getthang() << " "
                << ve[i]->getdatein().getnam() << " "
                << ve[i]->gettimeout().getgio() << " "
                << ve[i]->gettimeout().getphut() << " "
                << ve[i]->getdateout().getngay() << " "
                << ve[i]->getdateout().getthang() << " "
                << ve[i]->getdateout().getnam() << endl;
        }
    }

}

// ================= DANH SÁCH XE =================
void ParkingLot::danhsachxe()
{
    cout << "========================= DANH SACH XE DANG DO ==========================\n";
    int dem = 0;

    for (int i = 0; i < n; i++)
    {
        if (ve[i]->gettimeout().getgio() == 0 &&
            ve[i]->gettimeout().getphut() == 0)
        {
            cout << "ID: " << setw(4) << setfill('0') << ve[i]->getid()
                << " | Loai: " << setw(6) << setfill(' ') << ve[i]->getxe()->gettype()
                << " | Bien so: " << setw(12) << setfill(' ') << ve[i]->getxe()->getplate()
                << " | Vao: " << setw(4) << setfill(' ') << ve[i]->gettimein()
                << " " << ve[i]->getdatein() << endl;
            dem++;
        }
    }

    if (dem == 0)
        cout << "Khong co xe nao dang do!\n";
}

void ParkingLot::kiemtrachotrong()
{
    cout << "Cho trong con lai: \n";
    cout << "Xe may: " << MAXXEMAY - soxemay <<"/" <<MAXXEMAY<<endl;
    cout << "O to: " << MAXOTO - soxeoto <<"/" << MAXOTO << endl;
}

void ParkingLot::timkiem()
{
    int index;
	bool found = false;
    cout << "Nhap vao id ve: " << endl;
    cin >> index;
    system("cls");
    for (int i = 0; i < n; i++)
    {
        if (ve[i]->getid() == index)
        {
			found = true;
            cout << "---------THONG TIN VE---------"<<endl;
            cout << "ID:        " << setw(4) << setfill('0') << ve[i]->getid() << endl
                 << "Loai:      " << ve[i]->getxe()->gettype() << endl
                 << "Bien so:   " << ve[i]->getxe()->getplate() << endl
                 << "Vao:       " << ve[i]->gettimein()
                 << " " << ve[i]->getdatein() << endl;
                if( ve[i]->gettimeout().getgio() == 0 &&
                    ve[i]->gettimeout().getphut() == 0)
                {
                   cout << "Ra: Xe chua ra khoi bai." << endl;
                }
                else
                {
                  cout << "Ra:         " << ve[i]->gettimeout()
                        << " " << ve[i]->getdateout() << endl;
                  cout << "Thanh tien: "<<ve[i]->getfee()<<" VND"<<endl;
                }
            return;
        }
   }
   if (!found)
   {
       cout << "Khong tim thay ve voi ID da nhap!\n";
   }
}

void ParkingLot::tinhdoanhthu()
{
	cout << "Nhap ngay can tinh doanh thu (d/m/y): ";
	Date date;
	cin >> date;
	system("cls");
    long long doanhthu = 0;
    for (int i = 0; i < n; i++)
    {
        if (ve[i]->getdateout().getngay() == date.getngay() &&
            ve[i]->getdateout().getthang() == date.getthang() &&
            ve[i]->getdateout().getnam() == date.getnam())
        {
            doanhthu += ve[i]->getfee();
        }
    }
    cout << "Doanh thu trong ngay " << date.getngay() << "/"
        << date.getthang() << "/" << date.getnam() << " la: "
        << doanhthu << " VND" << endl;
}

void ParkingLot::hienthixe()
{
    cout << "========================================= DANH SACH XE DA RA KHOI BAI =========================================\n";
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (ve[i]->gettimeout().getgio() != 0 ||
            ve[i]->gettimeout().getphut() != 0)
        {
            cout << "ID: " << setw(4) << setfill('0') << ve[i]->getid()
                << " | Loai: "<<setw(6) << setfill(' ') << ve[i]->getxe()->gettype()
                << " | Bien so: " << setw(12) << setfill(' ') << ve[i]->getxe()->getplate()
                << " | Thoi gian vao: " << ve[i]->gettimein()
                << " " << ve[i]->getdatein()
                << " | Thoi gian ra: " << ve[i]->gettimeout()
                << " " << ve[i]->getdateout() << endl;
            dem++;
        }
    }
    if (dem == 0)
        cout << "Khong co xe nao da ra khoi bai!\n";
}

void ParkingLot::thongtinravao(const Date& today)
{
    int xera = 0;
	int otora = 0;
	int xemayra = 0;
    int xevao = 0;
	int otovao = 0;
	int xemayvao = 0;
	long long doanhthu = 0;
    for (int i = 0; i < n; i++)
    {
        if (ve[i]->getdateout().getngay() == today.getngay() &&
            ve[i]->getdateout().getthang() == today.getthang() &&
            ve[i]->getdateout().getnam() == today.getnam())
        {
            xera++;
			if (ve[i]->getxe()->gettype() == "Oto")
                otora++;
            else if (ve[i]->getxe()->gettype() == "XeMay")
                xemayra++;
			doanhthu += ve[i]->getfee();
        }
        if (ve[i]->getdatein().getngay() == today.getngay() &&
            ve[i]->getdatein().getthang() == today.getthang() &&
            ve[i]->getdatein().getnam() == today.getnam())
        {
            xevao++;
            if (ve[i]->getxe()->gettype() == "Oto")
                otovao++;
            else if (ve[i]->getxe()->gettype() == "XeMay")
				xemayvao++;
        }

    }
    cout << "===== THONG BAI DO TRONG NGAY " << today << " =====" << endl
        << "Tong xe ra vao bai: " << xera + xevao << endl
        << "Xe ra bai:   " << xera << endl
		<< "  - O to:   " << otora << endl
		<< "  - Xe may: " << xemayra << endl
        << "Xe vao bai:  " << xevao << endl
	    << "  - O to:   " << otovao << endl
		<< "  - Xe may: " << xemayvao << endl
		<< "Doanh thu trong ngay: " << doanhthu << " VND" << endl;
}



