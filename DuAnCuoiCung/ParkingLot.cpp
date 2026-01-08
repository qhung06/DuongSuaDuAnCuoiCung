#include "ParkingLot.h"
#include <iostream>
#include <fstream>
#define MAXXEMAY 20
#define MAXOTO 30

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

    if (soxemay >= MAXXEMAY)
    {
        cout << "Xe may da day!\n";
        cout << "1. O to\n0. Quay lai\n";
        cin >> ch;
        if (ch == '0') return;
        if (ch == '1')
        {
            xe = new Oto();
            soxeoto++;
        }
        else
        {
            cout << "Lua chon khong hop le!\n";
            return;
        }
    }
        if (soxeoto >= MAXOTO)
        {
            cout << "O to da day!\n";
            cout << "1. Xe may\n0. Quay lai\n";
            cin >> ch;
            if (ch == '0') return;
            if (ch == '1')
            {
                xe = new XeMay();
                soxemay++;
            }
            else
            {
                cout << "Lua chon khong hop le!\n";
                return;
            }
        }

        if (soxemay >= MAXXEMAY && soxeoto >= MAXOTO)
        {
            cout << "Bai do xe da day!\n";
            return;
        }

        if (soxemay < MAXXEMAY && soxeoto < MAXOTO)
        {
            cout << "1. Xe may\n2. O to\n0. Quay lai\n";
            cin >> ch;

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
                    return;
                }
        }
        cout << "Nhap bien so: ";
        cin >> plate;
        cout << "Nhap thoi gian vao: ";
        cin >> timein;

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

// ================= XU?T XE =================
void ParkingLot::xuatxe(const Date& dateout)
{
    int id;
    Time timeout;
	bool found = false;

    cout << "Nhap ID ve: ";
    cin >> id;
    for (int i = 0; i < n; i++)
    {
        if (ve[i]->getid() == id)
            {
            found = true;
            break;
		    }
    }
    if (!found)
    {
        cout << "Khong tim thay ve voi ID da nhap!\n";
        return;
	}
    cout << "Nhap thoi gian ra: ";
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
    cout << "===== DANH SACH XE DANG DO =====\n";
    int dem = 0;

    for (int i = 0; i < n; i++)
    {
        if (ve[i]->gettimeout().getgio() == 0 &&
            ve[i]->gettimeout().getphut() == 0)
        {
            cout << "ID: " << ve[i]->getid()
                << " | Loai: " << ve[i]->getxe()->gettype()
                << " | Bien so: " << ve[i]->getxe()->getplate()
                << " | Vao: " << ve[i]->gettimein()
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
    cout << "Xe may: " << MAXXEMAY - soxemay << "\n";
    cout << "O to: " << MAXOTO - soxeoto << "\n";
}
