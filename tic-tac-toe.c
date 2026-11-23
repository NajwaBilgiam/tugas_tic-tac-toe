#include <stdio.h>
#include <stdlib.h>

/* Array 2D Papan Tic-Tac-Toe */
char C[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Fungsi untuk menampilkan papan ke layar
void tampilkanPapan() {
    printf("\n");
    for (int baris = 0; baris < 3; baris++) {
        for (int kolom = 0; kolom < 3; kolom++) {
            printf(" %c ", C[baris][kolom]);
            if (kolom < 2) printf("|");
        }
        printf("\n");
        if (baris < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Fungsi untuk mengecek apakah sudah ada yang menang (3 simbol sejajar)
int cekKemenangan() {
    // Cek 3 Baris Horizontal
    for (int i = 0; i < 3; i++) {
        if (C[i][0] == C[i][1] && C[i][1] == C[i][2]) return 1;
    }
    // Cek 3 Kolom Vertikal
    for (int i = 0; i < 3; i++) {
        if (C[0][i] == C[1][i] && C[1][i] == C[2][i]) return 1;
    }
    // Cek Diagonal (Miring)
    if (C[0][0] == C[1][1] && C[1][1] == C[2][2]) return 1;
    if (C[0][2] == C[1][1] && C[1][1] == C[2][0]) return 1;

    return 0; // Belum ada yang menang
}

int main(int argc, char *argv[]) {
    int pilihan;
    char pemain = 'x'; // Pemain pertama memakai 'x'
    int totalLangkah = 0;
    int adaPemenang = 0;

    printf("=== GAME TIC TAC TOE ===\n");

    while (totalLangkah < 9 && !adaPemenang) {
        tampilkanPapan();

        printf("Pemain '%c', pilih nomor kotak (1-9): ", pemain);
        scanf("%d", &pilihan);

        // Mengubah nomor kotak (1-9) menjadi indeks baris dan kolom Array 2D
        int baris = (pilihan - 1) / 3;
        int kolom = (pilihan - 1) % 3;

        // Validasi agar tidak mengisi kotak yang sudah terisi
        if (pilihan >= 1 && pilihan <= 9 && C[baris][kolom] != 'x' && C[baris][kolom] != 'o') {
            C[baris][kolom] = pemain;
            totalLangkah++;

            // Cek kemenangan (Minimal pada langkah ke-5 total / 3 kali percobaan pemain pertama)
            if (totalLangkah >= 5) {
                adaPemenang = cekKemenangan();
            }

            if (adaPemenang) {
                tampilkanPapan();
                printf("Selamat! Pemain '%c' MENANG!\n", pemain);
                return 0;
            }

            // Berganti giliran antara 'x' dan 'o'
            pemain = (pemain == 'x') ? 'o' : 'x';
        } else {
            printf("Pilihan tidak valid atau kotak sudah terisi! Coba lagi.\n");
        }
    }

    tampilkanPapan();
    printf("Permainan Seri (Draw)!\n");

    return 0;
}