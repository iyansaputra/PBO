#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <math.h>
#include <string.h>

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
    strcpy(p[0].Nama, "Budy Enri");
    strcpy(p[0].Asal_Kota, "Bojonegoro");
    p[0].Umur = 25;
    p[0].Id = 1;

    strcpy(p[1].Nama, "Naswa Sabila");
    strcpy(p[1].Asal_Kota, "Dahanrejo");
    p[1].Umur = 20;
    p[1].Id = 167;

    strcpy(p[2].Nama, "Apri Supri");
    strcpy(p[2].Asal_Kota, "Dinari");
    p[2].Umur = 30;
    p[2].Id = 198;

    strcpy(p[3].Nama, "Saputro Ahmad");
    strcpy(p[3].Asal_Kota, "PPS Suci");
    p[3].Umur = 28;
    p[3].Id = 123;

    strcpy(p[4].Nama, "Aldi Taher");
    strcpy(p[4].Asal_Kota, "Planet Mars");
    p[4].Umur = 17;
    p[4].Id = 169;
}

int main()
{
    Pegawai p[5];
    AddDataPegawai(p);

    int a, b = 0, n, x, y, ip, lanjut;
    // a = untuk perulangan, n = untuk pilihan menu utama, x = untuk case 1

    cout << "================================================================" << endl;
    cout << "\t\t|   Menu Kasir   |" << endl;
    cout << "================================================================" << endl;
    cout << "\t\t|1. |\tAdmin" << endl;
    cout << "\t\t|2. |\tBeli Barang" << endl;
    cout << "\t\t|3. |\tBeli Token Listrik" << endl;
    cout << "\t\t|4. |\tExit" << endl;
    cout << "================================================================" << endl;
    cout << "Pilih : ";
    cin >> n;
    system("cls");

    switch (n)
    {
    case 1:
        cout << "================================================================" << endl;
        cout << "\t\t|   Menu Admin   |" << endl;
        cout << "================================================================" << endl;
        cout << "\t\t|1. |\tLihat Stock Barang" << endl;
        cout << "\t\t|2. |\tData Pegawai" << endl;
        cout << "\t\t|3. |\tKeluar" << endl;
        cout << "================================================================" << endl;
        cout << "Pilih : ";
        cin >> x;
        system("cls");

        if (x == 1)
        {
            /* code */
        }
        else if (x == 2)
        {
            // Edit Data Pegawai
            cout << "================================================================" << endl;
            cout << "\t\t|   Pegawai   |" << endl;
            cout << "================================================================" << endl;
            cout << "\t\t|1. |\tLihat Data Pegawai" << endl;
            cout << "\t\t|2. |\tMasukan Data Pegawai Baru" << endl;
            cout << "\t\t|3. |\tEdit Data Pegwai" << endl;
            cout << "\t\t|4. |\tHitung Gaji Pegawai" << endl;
            cout << "================================================================" << endl;
            cout << "Pilih : " << endl;
            cin >> ip;
            system("cls");

            if (ip == 1)
            {
                cout << "|  ID Pegawai   |  Nama Pegawai    |   Umur    |   Asal Kota   |" << endl;
                cout << "================================================================" << endl;
                for (a = 0; a <= 4; a++)
                {
                    cout << p[a].Id << p[a].Nama << p[a].Umur << p[a].Asal_Kota << endl;
                }

                for (a = 0; a < b; a++)
                {
                    cout << p[a].Id << p[a].Nama << p[a].Umur << p[a].Asal_Kota << endl;
                }

                // cout << "Masukan Data Pegawai Baru" << endl;
                // cout << "===========================" << endl;
                // cout << "Masukan Jumlah Data Pegwawai Baru (MAX 10) : ";
                // cin >> b;

                // for (a = 0; a < b; a++)
                // {
                //     cout << "ID Pegawai Baru : ";
                //     cin >> p[a].Id;
                //     cout << "Nama Pegawai Baru : ";
                //     cin >> p[a].Nama;
                //     cout << "Umur Pegawai Baru : ";
                //     cin >> p[a].Umur;
                //     cout << "Asal Kota Pegwai Baru : ";
                //     cin >> p[a].Asal_Kota;

                //     system("cls");
                //     cout << "Data Berhasil Ditambahkan" << endl;
                // }
                // balekno nk menu awal pal, gaero carane aku
            }

            else if (ip == 2)
            {
                do
                {
                    cout << "Masukan Data Pegawai Baru" << endl;
                    cout << "===========================" << endl;
                    cout << "Masukan Jumlah Data Pegwawai Baru (MAX 10) : ";
                    cin >> b;

                    for (a = 0; a < b; a++)
                    {
                        cout << "ID Pegawai Baru : ";
                        cin >> p[a].Id;
                        cout << "Nama Pegawai Baru : ";
                        cin >> p[a].Nama;
                        cout << "Umur Pegawai Baru : ";
                        cin >> p[a].Umur;
                        cout << "Asal Kota Pegwai Baru : ";
                        cin >> p[a].Asal_Kota;

                        system("cls");
                        cout << "Data Berhasil Ditambahkan" << endl;
                    }

                    cout << "Input 1 untuk lanjut\ninput 0 untuk berhenti";
                    cin >> lanjut;
                    system("cls");
                } while (lanjut != 0);
                break;
            }

            else if (ip == 3)
            {
                cout << "Wahyu02" << endl;
            }

            else if (ip == 4)
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

//look at the star