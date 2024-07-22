#include "stdio.h"
#include "string.h"

  char namaP[3][50] = {"Minyak Goreng 1L", "Beras Karungan", "Okky Jelly drink 2L"};
  int hargaP[3] = {320000, 75000, 20000};
  int stokP[3] = {10, 5, 8};
  int balance = 478000;

  void StocKurang() {
    printf("\nSTOCK PRODUK KURANG\n");
  }

  void IdSalah () {
    
    printf("\nID ERROR!!\n");
  }

  void ProsesBarang (int pilihanP, int jumlahB) {
      int totalHarga = hargaP[pilihanP - 1] * jumlahB;

  printf("\nReceipt\n");
  printf("Product: %s\n", namaP[pilihanP - 1]);
  printf("Price: Rp%d\n", hargaP[pilihanP - 1]);
  printf("Amount: %d\n", jumlahB);
  printf("Total: Rp%d\n", totalHarga);

  stokP[pilihanP - 1] -= jumlahB;

  printf("\nStok left %d.\n", stokP[pilihanP - 1]);
  }


  int main () {

int pilihanP;
int jumlahB;

    do {

    printf ("\nBalance = Rp%d", balance);
    printf("\nProduct List:\n");
  for (int i = 0; i < 3; i++) {
    printf("%d. %s - Rp%d (Stok: %d)\n", i + 1, namaP[i], hargaP[i], stokP[i]);
  }

  printf("\nInput Product ID: ");
  scanf("%d", &pilihanP);

  if (pilihanP == 4)
  
  {
    printf("~EXIT");
    return 0;
  }

  printf("\nInput amount: ");
  scanf("%d", &jumlahB);
  
 if (pilihanP <= 0 || pilihanP > 3) {
    IdSalah();
    return 0;
  }

  if (jumlahB > stokP[pilihanP - 1]) {
    StocKurang();
    return 0;
  }

  ProsesBarang(pilihanP, jumlahB);

  int Ppilihan;
  printf("Balance: %d\nBayar(1) Atau Batalkan Transaksi(Other) ?\n: ", balance);
  scanf("%d", &Ppilihan);

    int totalBayar = hargaP[pilihanP - 1] * jumlahB;

    if (Ppilihan == 1) {
      if (balance < totalBayar)
      {
        printf("TRANSAKSI DIBATALKAN\n -Uang anda Kurang\n");
      }
      else if (balance > totalBayar)
      {
      balance -= totalBayar;
      printf("Terima Kasih Sudah Membayar\n");
      } 
    }

    else
    {
      printf("TRANSAKSI DI BATALKAN");
    }

    } while (pilihanP != 4);
    
    return 0;
  }