#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

class Item
{
private:
  string nama;
  int price;
  int stok;

public:
  Item(string _nama, int _price, int _stok) : nama(_nama), price(_price), stok(_stok) {}

  string getNama()
  {
    return nama;
  }

  int getprice()
  {
    return price;
  }

  int getStok() 
  {
    return stok;
  }

  void setStok(int _stok)
  {
    stok = _stok;
  }
};

class Pegawai
{
private:
  string nama;
  string umur;
  string kota;

public:
  Pegawai(string _nama, string _umur, string _kota) : nama(_nama), umur(_umur), kota(_kota) {}

  string getNama()
  {
    return nama;
  }

  string getumur()
  {
    return umur;
  }

  string getkota()
  {
    return kota;
  }
};

class Transaksi
{
private:
  Item *item;
  int jumlah;
  int totalprice;

public:
  Transaksi(Item *_item, int _jumlah) : item(_item), jumlah(_jumlah)
  {
    totalprice = item->getprice() * jumlah;
  }

  int getTotalprice() 
  {
    return totalprice;
  }

  void cetakTransaksi() 
  {
    cout << " Transaksi: " << item->getNama() << " x " << jumlah << endl;
    cout << " Total price: Rp" << getTotalprice() << endl;
  }
};

class Kasir
{
public:
  void prosesTransaksi(Item *item, int jumlah)
  {
    if (item->getStok() >= jumlah){
      item->setStok(item->getStok() - jumlah);
      Transaksi transaksi(item, jumlah);
      transaksi.cetakTransaksi();
    }
    else{
      cout << " Stok tidak cukup!" << endl;
    }
  }
};
