#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

struct Barang{
    char Nama_Barang[20];
    int stock;
    int Price;
};

struct Pegawai{
    char Nama[20];
    char Asal_Kota[20];
    int Umur;
    int Id;
    int Present;
    int Absent;
};

struct Token_Listrik{
    int Kode;
    int Tprice;
};

void AddDataPegawai(struct Pegawai *p){
    strcpy (p[0].Nama, "Budy");
    strcpy (p[0].Asal_Kota, "Bojonegoro");
    p[0].Umur = 25;
    p[0].Id = 1;
}

int main()
{
    Pegawai p[10];
    AddDataPegawai(p);

    int a, n, x, y;
    //

    cout <<"Menu Kasir" << endl;
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

            if (x==1)
            {
                /* code */
            }
            else if (x==2)
            {

            }
            else if (x==3)
            {
                /* code */
            }
        break;
            
    case 2:
        cout << "Menu Beli Barang" << endl;
        cout << "| No | Nama Barang | Harga |" << endl;
        cout << "|----|--------------|-------|" << endl;
                for (a=0; a<10; a++){
                
                }
        cout << "Pilih : ";
        cin >> y;


        break;
    
    default:
        break;
    }
    // for (a=0; a<1; a++){
    //     cout << p[a].Nama << endl;
    //     cout << p[a].Asal_Kota << endl;
    //     cout << p[a].Umur << endl;
    //     cout << p[a].Id << endl;
    // }

    return 0;
}