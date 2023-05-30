#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

struct Barang
{
    char Nama_Barang[20];
    int stock;
    int Price;
};

struct Pegawai
{
    char Nama[20];
    char Asal_Kota[20];
    int Umur;
    int Id;
    int Present;
    int Absent;
};

struct Token_Listrik
{
    int Kode;
    int Tprice;
};

void AddDataPegawai(struct Pegawai *p)
{
    strcpy(p[0].Nama, "Budy");
    strcpy(p[0].Asal_Kota, "Bojonegoro");
    p[0].Umur = 25;
    p[0].Id = 1;
}

int main()
{
    Pegawai p[15];
    AddDataPegawai(p);

    int a, n, x, y, ip;
    // a = untuk perulangan, n = untuk pilihan menu utama, x = untuk case 1

    cout << "Menu Kasir" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Beli Barang" << endl;
    cout << "3. Beli Token Listrik" << endl;
    cout << "4. Exit" << endl;
    cout << "Pilih : ";
    cin >> n;

    switch (n)
    {
    case 1:
        cout << "Menu Admin" << endl;
        cout << "1. Lihat Stock Barang" << endl;
        cout << "2. Data Pegawai" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih : ";
        cin >> x;

        if (x == 1)
        {
            /* code */
        }
        else if (x == 2)
        {
            // Edit Data Pegawai
            cout << "|  ID Pegawai   |  Nama Pegawai    |   Umur    |   Asal Kota   |" << endl;
            for (a = 0; a < 5; a++)
            {
                cout << p[a].Id << p[a].Nama << p[a].Umur << p[a].Asal_Kota << endl;
            }

            cout << "1. Masukan Data Pegawai Baru" << endl;
            cout << "2. Edit Data Pegwai" << endl;
            cout << "3. Hitung Gaji Pegawai" << endl;
            cin >> ip;

            if (ip == 1)
            {
                cout << "Masukan Data Pegawai Baru" << endl;
                cout << "===========================" << endl;
                cout << "Masukan Jumlah Data Pegwawai Baru (MAX 10)" << endl;
                cin >> ip;

                for (a = 0; a < ip; a++)
                {
                    cout << "ID Pegawai Baru :" << p[a].Id << endl;
                    cout << "Nama Pegawai Baru :" << p[a].Nama << endl;
                    cout << "Umur Pegawai Baru :" << p[a].Umur << endl;
                    cout << "Asal Kota Pegwai Baru :" << p[a].Asal_Kota << endl;
                }
            }

            else if (ip == 2)
            {
                cout << "Wahyu" << endl;
            }

            else if (ip == 3)
            {
                cout << "Wahyu02" << endl;
            }

            else
            {
                cout << "Tidak Diketahui" << endl;
            }
        }
        else if (x == 3)
        {
            cout << "Wahyu03" << endl;
        }
        break;

    case 2:
        cout << "Menu Beli Barang" << endl;
        cout << "| No | Nama Barang | Harga |" << endl;
        cout << "|----|--------------|-------|" << endl;
        for (a = 0; a < 10; a++)
        {
        }
        cout << "Pilih : ";
        cin >> y;

        break;

        return 0;
    }
    while (n != 4)
        ;
}