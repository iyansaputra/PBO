#include <iostream>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
private:
  string nama;
  int harga;
  int stok;

public:
  Item(string _nama, int _harga, int _stok) : nama(_nama), harga(_harga), stok(_stok) {}

  string getNama() {
    return nama;
  }

  int getHarga() {
    return harga;
  }

  int getStok() {
    return stok;
  }

  void setStok(int _stok) {
    stok = _stok;
  }
};

class Transaksi {
private:
  Item* item;
  int jumlah;

public:
  Transaksi(Item* _item, int _jumlah) : item(_item), jumlah(_jumlah) {}

  int getTotalHarga() {
    return item->getHarga() * jumlah;
  }

  void cetakTransaksi() {
    cout << "Transaksi: " << item->getNama() << " x " << jumlah << endl;
    cout << "Total harga: " << getTotalHarga() << endl;
  }
};

class Kasir {
public:
  void prosesTransaksi(Item* item, int jumlah) {
    if (item->getStok() >= jumlah) {
      item->setStok(item->getStok() - jumlah);
      Transaksi transaksi(item, jumlah);
      transaksi.cetakTransaksi();
    } else {
      cout << "Stok tidak cukup!" << endl;
    }
  }
};

class Admin {
public:
  void kelolaStok(Item* item) {
    int tambahStok;
    cout << "Tambah stok " << item->getNama() << " sebanyak: ";
    cin >> tambahStok;
    item->setStok(item->getStok() + tambahStok);
    cout << "Stok " << item->getNama() << " berhasil ditambah." << endl;
  }

  void hapusStok(Item* item) {
    int kurangiStok;
    cout << "Kurangi stok " << item->getNama() << " sebanyak: ";
    cin >> kurangiStok;
    if (item->getStok() >= kurangiStok) {
      item->setStok(item->getStok() - kurangiStok);
      cout << "Stok " << item->getNama() << " berhasil dikurangi." << endl;
    } else {
      cout << "Stok tidak mencukupi!" << endl;
    }
  }
};

class Toko {
private:
  vector<Item*> daftarItem;

public:
  void tambahItem(Item* item) {
    daftarItem.push_back(item);
  }

  void mulaiBelanja() {
    Kasir kasir;
    int pilihan;
    int jumlah;

    do {
      cout << "===== Menu Belanja =====" << endl;
      for (int i = 0; i < daftarItem.size(); i++) {
        cout << i+1 << ". " << daftarItem[i]->getNama() << " - Rp" << daftarItem[i]->getHarga() << " (Stok: " << daftarItem[i]->getStok() << ")" << endl;
      }
      cout << "0. Keluar" << endl;
      cout << "Pilih: ";
      cin >> pilihan;

      if (pilihan >= 1 && pilihan <= daftarItem.size()) {
        cout << "Jumlah: ";
        cin >> jumlah;

        if (jumlah > 0) {
          kasir.prosesTransaksi(daftarItem[pilihan-1], jumlah);
        } else {
          cout << "Jumlah tidak valid!" << endl;
        }
      } else if (pilihan != 0) {
        cout << "Pilihan tidak valid!" << endl;
      }

    } while (pilihan != 0);
  }

  void menuAdmin() {
    Admin admin;
    int pilihan;

    do {
      cout << "===== Menu Admin =====" << endl;
      for (int i = 0; i < daftarItem.size(); i++) {
        cout << i+1 << ". " << daftarItem[i]->getNama() << " - Stok: " << daftarItem[i]->getStok() << endl;
      }
      cout << "0. Keluar" << endl;
      cout << "Pilih: ";
      cin >> pilihan;

      if (pilihan >= 1 && pilihan <= daftarItem.size()) {
        int subPilihan;
        cout << "===== Menu Kelola Stok =====" << endl;
        cout << "1. Tambah Stok" << endl;
        cout << "2. Hapus Stok" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilih: ";
        cin >> subPilihan;

        switch (subPilihan) {
          case 1:
            admin.kelolaStok(daftarItem[pilihan-1]);
            break;
          case 2:
            admin.hapusStok(daftarItem[pilihan-1]);
            break;
          case 0:
            break;
          default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
      } else if (pilihan != 0) {
        cout << "Pilihan tidak valid!" << endl;
      }

    } while (pilihan != 0);
  }
};

int main() {
  Toko toko;

  // Inisialisasi Item
  Item item1("Produk A", 10000, 5);
  Item item2("Produk B", 15000, 10);
  Item item3("Produk C", 20000, 3);

  // Tambahkan Item ke Toko
  toko.tambahItem(&item1);
  toko.tambahItem(&item2);
  toko.tambahItem(&item3);

  int menu;
  do {
    cout << "===== Menu =====" << endl;
    cout << "1. Belanja" << endl;
    cout << "2. Menu Admin" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih: ";
    cin >> menu;

    switch (menu) {
      case 1:
        toko.mulaiBelanja();
        break;
      case 2:
        toko.menuAdmin();
        break;
      case 0:
        break;
      default:
        cout << "Pilihan tidak valid!" << endl;
        break;
    }
  } while (menu != 0);

  return 0;
}
