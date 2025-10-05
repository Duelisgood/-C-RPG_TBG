#include <stdio.h>
#include <string.h>

#include "game_data.h"
#define MAX_INPUT 50

    int HP = 10;
    int ATK = 2;
    int DEF = 0;
    int LEVEL = 1;
    int XP = 0;
    int GOLD = 0;

void start_game(){
    //pesan awalan game
    printf("Welcome To RPG Game \n");
    printf("-------------------\n");
    printf("command 'help' to get any command\n");

}


void test_data(){
        // Akses data Item dari file game_data.c
    printf("Item Pertama (Total %d): ID %d, Nama: %s, Harga: %d\n",
           JUMLAH_ITEM,
           daftarItem[0].itemID,
           daftarItem[0].nama,
           daftarItem[0].harga);

    // Akses data Monster dari file game_data.c
    printf("Monster Kedua (Total %d): ID %d, Nama: %s, HP: %d\n",
           JUMLAH_MONSTER,
           daftarMonster[1].monsterID,
           daftarMonster[1].nama,
           daftarMonster[1].healthPoint);
}

void help(){
    printf("\n--- DAFTAR PERINTAH ---\n");
    printf("explore\n");
    printf("bag\n");
    printf("upgrade\n");
    printf("use\n");
    printf("quit\n");
    printf("help\n"); // Jangan lupa tambahkan 'help' itu sendiri!
    printf("------------------------\n");
}


void bersihkanString(char *str) {
    // Cari dan hapus karakter newline ('\n')
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void bacaInput(char *input) {
  
    // Membaca string dari input, maksimal 50 karakter
    if (fgets(input, MAX_INPUT, stdin) != NULL) {
        // Membersihkan karakter newline dari string input
        bersihkanString(input);
    }
}


void explore(){
    printf("explore\n");
}

void bag(){
    printf("bag\n");
}

void upgrade(){
    printf("upgrade\n");
}

void use_item(){
    printf("use_(item)\n");
}



int main()
{
    start_game();
    int game_running = 1;

    char aksiPengguna[MAX_INPUT];


    while (game_running)
    {
        bacaInput(aksiPengguna);

    // Membandingkan input string menggunakan if-else if-else

        if (strcmp(aksiPengguna, "help") == 0) {
            help();
        } 
        else if (strcmp(aksiPengguna, "bag") == 0) {
            bag();
        } 
        else if (strcmp(aksiPengguna, "upgrade_(item)") == 0) {
            upgrade();
        }  
        else if (strcmp(aksiPengguna, "use_(item)") == 0) {
            use_item();
        }   
        else if (strcmp(aksiPengguna, "explore") == 0) {
            explore(); 
        } 
        else if (strcmp(aksiPengguna, "quit") == 0) {
              printf("Selamat Tinggal!\n");
                game_running = 0; 
        } 
        else {
            printf("\n!!! Pilihan aksi tidak valid: %s\n", aksiPengguna);
        }

    }
    
    
   

    return 0;
}
