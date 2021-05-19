#include <iostream>
#include <conio.h>
#include "function.hpp"
#include "main_function.hpp"

int main(){
  elmPtr newElement;
  createQueue(Q);
  createQueue(Q2);
  createStack(Top);
  createStack(Top2);
  menuUtama(Q, Q2, Top, Top2, newElement);
  return 0;
}

void header(){
  int i;
  for (i = 0;i < 39; i++){std::cout << "=";}
  std::cout << "\n PROGRAM PENERIMAAN DAN ANTARAN BARANG \n";
  for (i = 0;i < 39; i++){std::cout << "=";}
  std::cout << "\n";
}

void inputPilihan(int &pilih){
  std::cout << "\nMasukkan angka = "; std::cin >> pilih; 
}

void menuUtama(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry){
  int pilih;
  header();
  std::cout << "1. Opsi Pekerja\n"
            << "2. Opsi Kurir\n"
            << "3. Exit Program\n";
  inputPilihan(pilih);

  switch (pilih)
  {
  case 1:
    menuPkjUtama(Q, Q2, Top, Top2, newEntry);
    break;
  
  case 2:
    menuKurirUtama(Q, Q2, Top, Top2, newEntry);
    break;

  case 3:

    break;

  default:
    break;
  }
}

void menuPkjUtama(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry){
  int pilih;

  header();
  std::cout << "1. Entry Penerimaan Barang\n"
            << "2. List Barang yang sudah disortir\n"
            << "3. Kembali\n"
            << "4. Exit Program\n";
  inputPilihan(pilih);

  switch (pilih)
  {
  case 1:
    entryPkj(Q, Q2, Top, Top2, newEntry);
    break;
  
  case 2:
    showListPkj(Q, Q2, Top, Top2, newEntry);
    break;

  case 3:
    menuUtama(Q, Q2, Top, Top2, newEntry);
    break;
  
  case 4:
    break;

  default:
    break;
  }
}

void entryPkj(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry){
  elmPtr newEntryy = new Element;
  char id[3];
  std::string nama, pengirim, penerima, alamat;
  int pengiriman;

  std:: cout << "ID Barang : "; std::cin >> id;
  std:: cout << "Nama Barang : "; std::cin >> nama;
  std:: cout << "Nama Pengirim : "; std::cin >> pengirim;
  std:: cout << "Nama Penerima : "; std::cin >> penerima;
  std:: cout << "Alamat Penerima : "; std::cin >> alamat;
  std:: cout << "0 = Kilat, 1 = cepat, 2 = reguler\n" 
             << "Jenis Pengiriman : "; std::cin >> pengiriman;
  createElement(newEntryy, id, nama, pengirim, penerima, alamat, pengiriman);
  enqueue(Q, newEntryy);

  std::cout << "\nBarang dimasukkan ke dalam list!\n";
  menuPkjUtama(Q, Q2, Top, Top2, newEntry);
}

void showListPkj(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry){
  header();
  int pilihan;
  elmPtr pHelp = Q.Head;
  if (!isQueueEmpty(Q)){
    std::cout << "List barang masuk :\n";
    do
    {
      std::cout << pHelp->id << " -- ";
      pHelp = pHelp->next;
    } while (pHelp != nullptr);

    std::cout << "\n1. Lihat Info Barang"
              << "\n2. Kembali";

    inputPilihan(pilihan);
    switch (pilihan)
    {
    case 1:
      infoBarangIn(Q, Q2, Top, Top2, newEntry);
      break;
    
    case 2:
      menuPkjUtama(Q, Q2, Top, Top2, newEntry);
      break;
    
    default:
      break;
    }
    } else {
      std::cout << "Belum ada Entry barang masuk!\n";
      menuPkjUtama(Q, Q2, Top, Top2, newEntry);
    }

  
}

void infoBarangIn(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry){
  char id[3];
  int pause;
  elmPtr pCari = Q.Head;

  std::cout << "Masukkan ID Barang = "; std::cin >> id[3];
  while (pCari != nullptr)
  {
    if (pCari->id == id)
    {
      std::cout << "\nID Barang : " << pCari->id
                << "\nNama Barang : " << pCari->namaBarang
                << "\nNama Pengirim : " << pCari->namaPengirim
                << "\nNama Penerima : " << pCari->namaPenerima
                << "\nAlamat Penerima : " << pCari->alamatPenerima
                << "\nJenis Pengiriman : ";
      if (pCari->jenisPengiriman == 2)
      {
        std::cout << "Reguler";
      } else if (pCari->jenisPengiriman == 1){
        std::cout << "Cepat";
      } else {
        std::cout << "Kilat";
      }
      
      break;
    }
    pCari = pCari->next;
  }
  std::cout << "\nTekan Enter Untuk Kembali ke Menu Sebelumnya"; std::cin >> pause;
  menuPkjUtama(Q, Q2, Top, Top2, newEntry);
}
 
void menuKurirUtama(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry){
  int pilih;
  header();
  std::cout << "1. Entry Pengantaran Barang\n"
            << "2. List Barang yang akan diantar\n"
            << "3. Info Barang yang sedang diantar\n"
            << "4. Keluarkan Barang\n"
            << "5. Kembali\n"
            << "6. Exit Program\n";
  inputPilihan(pilih);

  switch (pilih)
  {
  case 1:
    entryKurir(Q, Q2, Top, Top2, newEntry);
    break;
  
  case 2:
    showListKurir(Q, Q2, Top, Top2, newEntry);
    break;

  case 3:
    infoBarangTop(Q, Q2, Top, Top2, newEntry);
    break;
  
  case 4:
    keluarBarang(Q, Q2, Top, Top2, newEntry);
    break;
  
  case 5:
    menuUtama(Q, Q2, Top, Top2, newEntry);
    break;

  case 6:
    break;

  default:
    break;
  }

}

void entryKurir(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry){
  header();
  char id[3];
  std::string nama, pengirim, penerima, alamat;
  int pengiriman;

  std:: cout << "ID Barang : "; std::cin >> id;
  std:: cout << "Nama Barang : "; std::getline(std::cin, nama);
  std:: cout << "Nama Pengirim : "; std::getline(std::cin, pengirim);
  std:: cout << "Nama Penerima : "; std::getline(std::cin, penerima);
  std:: cout << "Alamat Penerima : "; std::getline(std::cin, alamat);
  
  std:: cout << "0 = Kilat, 1 = cepat, 2 = reguler\n" 
             << "Jenis Pengiriman : "; std::cin >> pengiriman;
  createElement(newEntry, id, nama, pengirim, penerima, alamat, pengiriman);

  push(Top, newEntry);
  push(Top2, newEntry);
  menuKurirUtama(Q, Q2, Top, Top2, newEntry);
}

void showListKurir(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry){
  header();
  int pilihan;
  elmPtr pCari;

  elmPtr pHelp = Top;
  if (isStackEmpty(Top)){
    std::cout << "Kendaraan Kosong!\n";
    menuKurirUtama(Q, Q2, Top, Top2, newEntry);
  } else {
    std::cout << "List barang keluar :\n";
    do {
      std::cout << pHelp->id << " -- ";
      pHelp = pHelp->next;
    } while (pHelp != nullptr);

    std::cout << "\n1. Lihat Info Barang"
              << "\n2. Kembali";

    inputPilihan(pilihan);
    switch (pilihan)
    {
    case 1:
      infoBarangOut(Q, Q2, Top, Top2, newEntry);
      break;
    
    case 2:
      menuKurirUtama(Q, Q2, Top, Top2, newEntry);
      break;
    
    default:
      break;
    }
  }

  
}

void infoBarangOut(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry){
  char id[3];
  int pause;
  elmPtr pCari = Q.Head;
  
  std::cout << "Masukkan ID Barang = "; std::cin >> id[3];
  while (pCari != nullptr)
  {
    if (pCari->id == id)
    {
      std::cout << "\nID Barang : " << pCari->id
                << "\nNama Barang : " << pCari->namaBarang
                << "\nNama Pengirim : " << pCari->namaPengirim
                << "\nNama Penerima : " << pCari->namaPenerima
                << "\nAlamat Penerima : " << pCari->alamatPenerima
                << "\nJenis Pengiriman : ";
      if (pCari->jenisPengiriman == 2)
      {
        std::cout << "Reguler";
      } else if (pCari->jenisPengiriman == 1){
        std::cout << "Cepat";
      } else {
        std::cout << "Kilat";
      }
      
      break;
    }
    pCari = pCari->next;
  }
  std::cout << "\nTekan Enter Untuk Kembali ke Menu Sebelumnya"; std::cin >> pause;
  menuKurirUtama(Q, Q2, Top, Top2, newEntry);
}

void infoBarangTop(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry){
  std::cout << "\nBarang" << Top->id;
  std::cout << "\nNama Barang" << Top->namaBarang;
  std::cout << "\nNama Pengirim" << Top->namaPengirim;
  std::cout << "\nNama Penerima" << Top->namaPenerima;
  std::cout << "\nAlamat Penerima" << Top->alamatPenerima;
  std::cout << "\nJenis Pengiriman" << Top->jenisPengiriman;
  menuKurirUtama(Q, Q2, Top, Top2, newEntry);
}

void keluarBarang(Queue &Q, Queue &Q2, S &Top, S &Top2, elmPtr newEntry){
  elmPtr pDel;
  int pause;
  pop(Top, pDel);
  std::cout << "Barang dikeluarkan dari kendaraan!";
  std::cout << "\nTekan Enter Untuk Kembali ke Menu Sebelumnya"; std::cin >> pause;
  menuKurirUtama(Q, Q2, Top, Top2, newEntry);
};
