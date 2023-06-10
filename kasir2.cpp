#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

//Bagian Deklarasi Class
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
  string jabatan;

public:
  Pegawai(string _nama, string _jabatan) : nama(_nama), jabatan(_jabatan) {}

  string getNama()
  {
    return nama;
  }

  string getJabatan()
  {
    return jabatan;
  }
};

class Transaksi
{
private:
  Item *item;
  int jumlah;
  int totalprice; // Menambahkan atribut totalprice untuk menyimpan total pembayaran

public:
  Transaksi(Item *_item, int _jumlah) : item(_item), jumlah(_jumlah)
  {
    totalprice = item->getprice() * jumlah; // Menghitung totalprice saat membuat objek Transaksi
  }

  int getTotalprice()
  {
    return totalprice;
  }

  void cetakTransaksi()
  {
    cout << "Transaksi: " << item->getNama() << " x " << jumlah << endl;
    cout << "Total price: Rp" << getTotalprice() << endl;
  }
};

class Kasir
{
public:
  void prosesTransaksi(Item *item, int jumlah)
  {
    if (item->getStok() >= jumlah)
    {
      item->setStok(item->getStok() - jumlah);
      Transaksi transaksi(item, jumlah);
      transaksi.cetakTransaksi();
    }
    else
    {
      cout << "Stok tidak cukup!" << endl;
    }
  }
};

class Admin
{
private:
  string password;               // atribut password
  vector<Pegawai> daftarPegawai; // add vector pegawai

public:
  Admin(string _password) : password(_password) {} // add constructor dengan parameter password

  void tambahBarang(vector<Item *> &daftarItem) //bagian implementasi fungi / method
  {
  	system ("cls");
    string nama;
    int price, stok;
    cout << "Masukkan nama barang: ";
    cin >> nama;
    cout << "Masukkan price barang: ";
    cin >> price;
    cout << "Masukkan jumlah stok barang: ";
    cin >> stok;

    Item *itemBaru = new Item(nama, price, stok);
    daftarItem.push_back(itemBaru);

    cout << "Barang berhasil ditambahkan." << endl;
  }

  void hapusBarang(vector<Item *> &daftarItem) //method
  {
  	system ("cls");
    int pilihan;
    cout << "Pilih barang yang ingin dihapus: " << endl;
    for (int i = 0; i < daftarItem.size(); i++)
    {
      cout << i + 1 << ". " << daftarItem[i]->getNama() << endl;
    }
    cout << "Pilih: ";
    cin >> pilihan;

    if (pilihan >= 1 && pilihan <= daftarItem.size())
    {
      delete daftarItem[pilihan - 1];
      daftarItem.erase(daftarItem.begin() + pilihan - 1);
      cout << "Barang berhasil dihapus." << endl;
    }
    else
    {
      cout << "Pilihan tidak valid!" << endl;
    }
  }

  void tambahStok(vector<Item *> &daftarItem) //method
  {
  	system ("cls");
    int pilihan;
    cout << "Pilih barang yang ingin ditambah stoknya: " << endl;
    for (int i = 0; i < daftarItem.size(); i++)
    {
      cout << i + 1 << ". " << daftarItem[i]->getNama() << " - Stok: " << daftarItem[i]->getStok() << endl;
    }
    cout << "Pilih: ";
    cin >> pilihan;

    if (pilihan >= 1 && pilihan <= daftarItem.size())
    {
      int stokBaru;
      cout << "Masukkan jumlah stok baru: ";
      cin >> stokBaru;
      daftarItem[pilihan - 1]->setStok(daftarItem[pilihan - 1]->getStok() + stokBaru);
      cout << "Stok barang berhasil ditambah." << endl;
    }
    else
    {
      cout << "Pilihan tidak valid!" << endl;
    }
  }

  void kurangiStok(vector<Item *> &daftarItem) //method
  {
  	system ("cls");
    int pilihan;
    cout << "Pilih barang yang ingin dikurangi stoknya: " << endl;
    for (int i = 0; i < daftarItem.size(); i++)
    {
      cout << i + 1 << ". " << daftarItem[i]->getNama() << " - Stok: " << daftarItem[i]->getStok() << endl;
    }
    cout << "Pilih: ";
    cin >> pilihan;

    if (pilihan >= 1 && pilihan <= daftarItem.size())
    {
      int stokKurang;
      cout << "Dikurangi berapa stok?: ";
      cin >> stokKurang;
      if (daftarItem[pilihan - 1]->getStok() >= stokKurang)
      {
        daftarItem[pilihan - 1]->setStok(daftarItem[pilihan - 1]->getStok() - stokKurang);
        cout << "Stok barang berhasil dikurangi." << endl;
      }
      else
      {
        cout << "Stok tidak cukup!" << endl;
      }
    }
    else
    {
      cout << "Pilihan tidak valid!" << endl;
    }
  }

  void lihatStock(vector<Item *> &daftarItem) //method
  {
  	system ("cls");
    cout << "===== Stock Barang =====" << endl;
    for (int i = 0; i < daftarItem.size(); i++)
    {
      cout << "Nama Barang: " << daftarItem[i]->getNama() << endl;
      cout << "Stok: " << daftarItem[i]->getStok() << endl;
    }
  }

  void tambahPegawai() //method
  {
  	system ("cls");
    string nama, jabatan;
    cout << "Masukkan nama pegawai: ";
    cin >> nama;
    cout << "Masukkkan jabatan pegawai: ";
    cin >> jabatan;

    Pegawai pegawai(nama, jabatan);
    daftarPegawai.push_back(pegawai);

    cout << "Berhasil ditambahkan." << endl;
  }

  void hapusPegawai() //method
  {
  	system ("cls");
    int pilihan;
    cout << "Pilih pegawai yang ingin dihapus: " << endl;
    for (int i = 0; i < daftarPegawai.size(); i++)
    {
      cout << i + 1 << ". " << daftarPegawai[i].getNama() << " - " << daftarPegawai[i].getJabatan() << endl;
    }
    cout << "Pilih: ";
    cin >> pilihan;

    if (pilihan >= 1 && pilihan <= daftarPegawai.size())
    {
      daftarPegawai.erase(daftarPegawai.begin() + pilihan - 1);
      cout << "Pegawai berhasil dihapus." << endl;
    }
    else
    {
      cout << "Pilihan tidak valid!" << endl;
    }
  }

  void lihatDataPegawai() //method
  {
  	system ("cls");
    cout << "===== Data Pegawai =====" << endl;
    for (int i = 0; i < daftarPegawai.size(); i++)
    {
      cout << "Nama: " << daftarPegawai[i].getNama() << endl;
      cout << "Jabatan: " << daftarPegawai[i].getJabatan() << endl;
    }
  }

  bool login() //method
  {
    string inputPassword;
    cout << "Masukkan password: ";
    cin >> inputPassword;

    if (inputPassword == password)
    {
      cout << "Login berhasil." << endl;
      return true;
    }
    else
    {
      cout << "Akses ditolak." << endl;
      return false;
    }
  }
};

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

  void tambahBarang(Item *item) //method
  {
    daftarItem.push_back(item);
  }

  void mulaiBelanja() //method
  {
    Kasir kasir;
    int pilihan;
    int jumlah;
    int totalPembayaran = 0;

    cout << " " << endl;
    cout << "===== Toko Serba Ada =====" << endl;
    cout << "Selamat datang di Toko Serba Ada!" << endl;
    cout << "Silakan pilih item yang ingin Anda beli:" << endl;

    do
    {
      cout << " " << endl;
      cout << "===== Menu Belanja =====" << endl;
      for (int i = 0; i < daftarItem.size(); i++)
      {
        cout << i + 1 << ". " << daftarItem[i]->getNama() << " - Rp" << daftarItem[i]->getprice() << " (Stok: " << daftarItem[i]->getStok() << ")" << endl;
      }
      cout << "0. Keluar" << endl;
      cout << "Pilih: ";
      cin >> pilihan;

      if (pilihan >= 1 && pilihan <= daftarItem.size())
      {
        cout << "Jumlah: ";
        cin >> jumlah;

        if (jumlah > 0)
        {
          Item *selectedItem = daftarItem[pilihan - 1];
          kasir.prosesTransaksi(selectedItem, jumlah);
          totalPembayaran += selectedItem->getprice() * jumlah;
          cout << "Transaksi berhasil!" << endl;
        }
        else
        {
          cout << "Jumlah tidak valid!" << endl;
        }
      }
      else if (pilihan != 0)
      {
        cout << "Pilihan tidak valid!" << endl;
      }
    } while (pilihan != 0);

    cout << "Terima kasih telah berbelanja di Toko Serba Ada!" << endl;
    cout << "Total pembayaran: Rp" << totalPembayaran << endl;
  }

  void menuAdmin() //method
  {
    Admin admin("1234"); // passwordnya
    if (!admin.login())
    {
      return; // jika salah, akses ditolak
    }

    int pilihan;

    do
    {
      cout << " " << endl;
      cout << "===== Menu Admin =====" << endl;
      cout << "1. Tambah Barang" << endl;
      cout << "2. Hapus Barang" << endl;
      cout << "3. Tambah Stok" << endl;
      cout << "4. Kurangi Stok" << endl;
      cout << "5. Lihat Stock Barang" << endl;
      cout << "6. Data Pegawai" << endl;
      cout << "0. Keluar" << endl;
      cout << "Pilih: ";
      cin >> pilihan;

      switch (pilihan)
      {
      case 1:
      	system ("cls");
        admin.tambahBarang(daftarItem);
        break;
      case 2:
      	system ("cls");
        admin.hapusBarang(daftarItem);
        break;
      case 3:
      	system ("cls");
        admin.tambahStok(daftarItem);
        break;
      case 4:
      	system ("cls");
        admin.kurangiStok(daftarItem);
        break;
      case 5:
      	system ("cls");
        admin.lihatStock(daftarItem);
        break;
      case 6:
      	system ("cls");
        menuDataPegawai(admin);
        break;
      case 0:
        break;
      default:
        cout << "Pilihan tidak valid!" << endl;
        break;
      }
    } while (pilihan != 0);
  }

  void menuDataPegawai(Admin &admin) //method
  {
    int pilihan;

    do
    {
      cout << " " << endl;
      cout << "===== Menu Data Pegawai =====" << endl;
      cout << "1. Lihat Data" << endl;
      cout << "2. Tambah Data" << endl;
      cout << "3. Hapus Data" << endl;
      cout << "0. Kembali" << endl;
      cout << "Pilih: ";
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
        cout << "Pilihan tidak valid!" << endl;
        break;
      }
    } while (pilihan != 0);
  }
};

//Bagian main (fungsi utama)
int main()
{
  Toko toko;

  // Inisialisasi Item
  Item item1("Beras Tawon", 65700, 30);
  Item item2("Aqua Galon", 19000, 30);
  Item item3("Deterjen", 3000, 30);
  Item item4("Susu UHT", 5500, 50);

  // Tambahkan Item ke Toko
  toko.tambahBarang(&item1);
  toko.tambahBarang(&item2);
  toko.tambahBarang(&item3);

  int menu;
  do
  {
  	system ("cls");
    cout << " " << endl;
    cout << "==============================" << endl;
    cout << "         Toko Serba Ada       " << endl;
    cout << "==============================" << endl;
    cout << "1. Belanja" << endl;
    cout << "2. Menu Admin" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih: ";
    cin >> menu;

    switch (menu)
    {
    case 1:
      system ("cls");
      cout << " " << endl;
      cout << "==============================" << endl;
      cout << "          Menu Belanja        " << endl;
      cout << "==============================" << endl;
      toko.mulaiBelanja();
      break;
    case 2:
      cout << "==============================" << endl;
      cout << "          Menu Admin          " << endl;
      cout << "==============================" << endl;
      toko.menuAdmin();
      break;
    case 0:
      cout << "Terima kasih telah mengunjungi Toko Serba Ada!" << endl;
      break;
    default:
      cout << "Pilihan tidak valid!" << endl;
      break;
    }
  } while (menu != 0);

  return 0;
}
