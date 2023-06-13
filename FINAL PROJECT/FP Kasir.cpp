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

public:
Admin(string _password) : password(_password) {}

void tambahBarang(vector<Item *> &daftarItem)
{
  system("cls");
  string nama;
  int price, stok;
  cout << " Masukkan nama barang: ";
  cin >> nama;
  cout << " Masukkan harga barang: ";
  cin >> price;
  cout << " Masukkan jumlah stok barang: ";
  cin >> stok;

  Item *itemBaru = new Item(nama, price, stok);
  daftarItem.push_back(itemBaru);

  cout << " Barang berhasil ditambahkan." << endl;
}

void hapusBarang(vector<Item *> &daftarItem)
{
  system("cls");
  int pilihan;
  cout << " Pilih barang yang ingin dihapus: " << endl;
  for (int i = 0; i < daftarItem.size(); i++)
  {
    cout << i + 1 << ". " << daftarItem[i]->getNama() << endl;
  }
  cout << " Pilih: ";
  cin >> pilihan;

  if (pilihan >= 1 && pilihan <= daftarItem.size())
  {
    delete daftarItem[pilihan - 1];
    daftarItem.erase(daftarItem.begin() + pilihan - 1);
    cout << " Barang berhasil dihapus." << endl;
  }
  else
  {
    cout << " Pilihan tidak valid!" << endl;
  }
}

void tambahStok(vector<Item *> &daftarItem)
{
  system("cls");
  int pilihan;
  cout << " Pilih barang yang ingin ditambah stoknya: " << endl;
  for (int i = 0; i < daftarItem.size(); i++)
  {
    cout << i + 1 << ". " << daftarItem[i]->getNama() << " - Stok: " << daftarItem[i]->getStok() << endl;
  }
  cout << " Pilih: ";
  cin >> pilihan;

  if (pilihan >= 1 && pilihan <= daftarItem.size())
  {
    int stokBaru;
    cout << " Masukkan jumlah stok baru: ";
    cin >> stokBaru;
    daftarItem[pilihan - 1]->setStok(daftarItem[pilihan - 1]->getStok() + stokBaru);
    cout << " Stok barang berhasil ditambah." << endl;
  }
  else
  {
    cout << " Pilihan tidak valid!" << endl;
  }
}

void kurangiStok(vector<Item *> &daftarItem)
{
  system("cls");
  int pilihan;
  cout << " Pilih barang yang ingin dikurangi stoknya: " << endl;
  for (int i = 0; i < daftarItem.size(); i++)
  {
    cout << i + 1 << ". " << daftarItem[i]->getNama() << " - Stok: " << daftarItem[i]->getStok() << endl;
  }
  cout << " Pilih: ";
  cin >> pilihan;

  if (pilihan >= 1 && pilihan <= daftarItem.size())
  {
    int stokKurang;
    cout << " Dikurangi berapa stok?: ";
    cin >> stokKurang;
    if (daftarItem[pilihan - 1]->getStok() >= stokKurang)
    {
      daftarItem[pilihan - 1]->setStok(daftarItem[pilihan - 1]->getStok() - stokKurang);
      cout << " Stok barang berhasil dikurangi." << endl;
    }
    else
    {
      cout << " Stok tidak cukup!" << endl;
    }
  }
  else
  {
    cout << " Pilihan tidak valid!" << endl;
  }
}

void lihatStock(vector<Item *> &daftarItem)
{
  system("cls");
  cout << " ===== Stock Barang =====" << endl;
  for (int i = 0; i < daftarItem.size(); i++)
  {
    cout << " Nama Barang: " << daftarItem[i]->getNama() << endl;
    cout << " Stok: " << daftarItem[i]->getStok() << endl;
  }
}

void tambahPegawai()
{
  system("cls");
  string nama, umur, kota;
  cout << " Masukkan nama pegawai: ";
  cin >> nama;
  cout << " Masukkan Umur Pegawai: ";
  cin >> umur;
  cout << " Masukkan Asal Kota Pegawai: ";
  cin >> kota;

  Pegawai pegawai(nama, umur, kota);
  daftarPegawai.push_back(pegawai);

  cout << " Berhasil ditambahkan." << endl;
}

void hapusPegawai()
{
  system("cls");
  int pilihan;
  cout << " Pilih pegawai yang ingin dihapus: " << endl;
  for (int i = 0; i < daftarPegawai.size(); i++)
  {
    cout << i + 1 << ". " << daftarPegawai[i].getNama() << " - " << endl;
  }
  cout << " Pilih: ";
  cin >> pilihan;

  if (pilihan >= 1 && pilihan <= daftarPegawai.size())
  {
    daftarPegawai.erase(daftarPegawai.begin() + pilihan - 1);
    cout << " Pegawai berhasil dihapus." << endl;
  }
  else
  {
    cout << " Pilihan tidak valid!" << endl;
  }
}

void lihatDataPegawai()
{
  system("cls");
  cout << " ===== Data Pegawai =====" << endl;
  cout << "-----------------------------------------------------" << endl;
  cout << "\t|   Nama    |    Umur    |     Asal Kota     |" << endl;
  for (int i = 0; i < daftarPegawai.size(); i++)
  {
    cout << "\t" << daftarPegawai[i].getNama() << "\t\t" << daftarPegawai[i].getumur() << "\t" << daftarPegawai[i].getkota() << endl;
  }
}

bool login()
{
  string inputPassword;
  cout << " Masukkan password: ";
  cin >> inputPassword;

  if (inputPassword == password)
  {
    cout << " Login berhasil." << endl;
    return true;
  }
  else
  {
    cout << " Akses ditolak." << endl;
    return false;
  }
}
}
;

class Toko
{
private:
  vector<Item *> daftarItem;

public:
  ~Toko()
  {
    for (Item *item : daftarItem)
    {
      delete item;
    }
  }

  void tambahBarang(Item *item)
  {
    daftarItem.push_back(item);
  }

  void mulaiBelanja()
  {
    Kasir kasir;
    int pilihan;
    int jumlah;
    int totalPembayaran = 0;

    cout << " " << endl;
    cout << " ===== Mandiri Store =====" << endl;
    cout << " Selamat datang di Toko Serba Ada!" << endl;

    do
    {
      cout << " " << endl;
      cout << " ===== Menu Belanja =====" << endl;
      cout << "No  |     Nama Barang     |     Harga Barang    |" << endl;
      cout << "-----------------------------------------------------" << endl;
      for (int i = 0; i < daftarItem.size(); i++)
      {
        cout << i + 1 << "\t" << daftarItem[i]->getNama() << "\t\tRp" << daftarItem[i]->getprice() << endl;
      }
      cout << "-----------------------------------------------------" << endl;
      cout << " 0. Keluar" << endl;
      cout << " Silakan pilih item yang ingin Anda beli:" << endl;
      cout << " Pilih: ";
      cin >> pilihan;

      if (pilihan >= 1 && pilihan <= daftarItem.size())
      {
        cout << " Jumlah: ";
        cin >> jumlah;

        if (jumlah > 0)
        {
          Item *selectedItem = daftarItem[pilihan - 1];
          kasir.prosesTransaksi(selectedItem, jumlah);
          totalPembayaran += selectedItem->getprice() * jumlah;
          cout << " Transaksi berhasil!" << endl;
        }
        else
        {
          cout << " Jumlah tidak valid!" << endl;
        }
      }

      else if (pilihan != 0)
      {
        cout << " Pilihan tidak valid!" << endl;
      }

    } while (pilihan != 0);

    cout << " Total pembayaran: Rp" << totalPembayaran << endl;
    cout << " Terima kasih telah berbelanja di Mandiri Store!" << endl;
  }

  void menuAdmin()
  {
    Admin admin("1234");

    if (!admin.login())
    {
      return;
    }

    int pilihan;

    do
    {
      cout << " " << endl;
      cout << " ===== Menu Admin =====" << endl;
      cout << " 1. Tambah Barang" << endl;
      cout << " 2. Hapus Barang" << endl;
      cout << " 3. Tambah Stok" << endl;
      cout << " 4. Kurangi Stok" << endl;
      cout << " 5. Lihat Stock Barang" << endl;
      cout << " 6. Data Pegawai" << endl;
      cout << " 0. Keluar" << endl;
      cout << " ==============================" << endl;
      cout << " Pilih: ";
      cin >> pilihan;

      switch (pilihan)
      {
      case 1:
        system("cls");
        admin.tambahBarang(daftarItem);
        break;
      case 2:
        system("cls");
        admin.hapusBarang(daftarItem);
        break;
      case 3:
        system("cls");
        admin.tambahStok(daftarItem);
        break;
      case 4:
        system("cls");
        admin.kurangiStok(daftarItem);
        break;
      case 5:
        system("cls");
        admin.lihatStock(daftarItem);
        break;
      case 6:
        system("cls");
        menuDataPegawai(admin);
        break;
      case 0:
        break;
      default:
        cout << " Pilihan tidak valid!" << endl;
        break;
      }

    } while (pilihan != 0);
  }

  void menuDataPegawai(Admin &admin)
  {
    int pilihan;

    do
    {
      cout << " " << endl;
      cout << " ===== Menu Data Pegawai =====" << endl;
      cout << " 1. Lihat Data" << endl;
      cout << " 2. Tambah Data" << endl;
      cout << " 3. Hapus Data" << endl;
      cout << " 0. Kembali" << endl;
      cout << " ==============================" << endl;
      cout << " Pilih: ";
      cin >> pilihan;

      switch (pilihan)
      {
      case 1:
        admin.lihatDataPegawai();
        break;
      case 2:
        admin.tambahPegawai();
        break;
      case 3:
        admin.hapusPegawai();
        break;
      case 0:
        break;
      default:
        cout << " Pilihan tidak valid!" << endl;
        break;
      }
    } while (pilihan != 0);
  }
};

int main()
{
  Toko toko;

  Item item1(" Beras Tawon", 65700, 30);
  Item item2(" Aqua Galon", 19000, 30);
  Item item3(" Deterjen", 3000, 30);
  Item item4(" Susu UHT", 5500, 50);

  toko.tambahBarang(&item1);
  toko.tambahBarang(&item2);
  toko.tambahBarang(&item3);
  toko.tambahBarang(&item4);

  int menu;

  do
  {
    cout << " " << endl;
    cout << " ==============================" << endl;
    cout << "          Mandiri Store        " << endl;
    cout << " ==============================" << endl;
    cout << " 1. Belanja" << endl;
    cout << " 2. Menu Admin" << endl;
    cout << " 0. Keluar" << endl;
    cout << " ==============================" << endl;
    cout << " Pilih: ";
    cin >> menu;

    switch (menu)
    {
    case 1:
      system("cls");
      cout << " " << endl;
      cout << " ==============================" << endl;
      cout << "          Menu Belanja        " << endl;
      cout << " ==============================" << endl;
      toko.mulaiBelanja();
      break;
    case 2:
      cout << " ==============================" << endl;
      cout << "          Menu Admin          " << endl;
      cout << " ==============================" << endl;
      toko.menuAdmin();
      break;
    case 0:
      cout << " Terima kasih telah mengunjungi Mandiri Store!" << endl;
      break;
    default:
      cout << " Pilihan tidak valid!" << endl;
      break;
    }
  } while (menu != 0);

  return 0;
}
