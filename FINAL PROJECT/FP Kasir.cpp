class Toko
{
private:
  vector<Item *> daftarItem;

public:
  ~Toko()
  {
    for (Item *item : daftarItem){
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
      for (int i = 0; i < daftarItem.size(); i++){
        cout << i + 1 << "\t" << daftarItem[i]->getNama() << "\t\tRp" << daftarItem[i]->getprice() << endl;
      }
      cout << "-----------------------------------------------------" << endl;
      cout << " 0. Keluar" << endl;
      cout << " Silakan pilih item yang ingin Anda beli:" << endl;
      cout << " Pilih: ";
      cin >> pilihan;

      if (pilihan >= 1 && pilihan <= daftarItem.size()){
        cout << " Jumlah: ";
        cin >> jumlah;

        if (jumlah > 0){
          Item *selectedItem = daftarItem[pilihan - 1];
          kasir.prosesTransaksi(selectedItem, jumlah);
          totalPembayaran += selectedItem->getprice() * jumlah;
          cout << " Transaksi berhasil!" << endl;
        }
        else{
          cout << " Jumlah tidak valid!" << endl;
        }
      }

      else if (pilihan != 0){
        cout << " Pilihan tidak valid!" << endl;
      }

    } 
    while (pilihan != 0);

    cout << " Total pembayaran: Rp" << totalPembayaran << endl;
    cout << " Terima kasih telah berbelanja di Mandiri Store!" << endl;
  }

  void menuAdmin() 
  {
    Admin admin("1234");

    if (!admin.login()){
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

      switch (pilihan){
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

      switch (pilihan){
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

    switch (menu){
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