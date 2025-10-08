#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>  
#include <time.h>   
#include "game_data.h"
#include "game_data.h"     // Structs global
#include "utilities.h"     // Fungsi dasar
#include "player_manager.h" // Login, Save, Bag
#include "combat.h"        // Explore, Fight
#define MAX_INPUT 50

void start_game(){
    //pesan awalan game
   
    
    printf("\n        Selamat datang di D U N G E O N  C L I\n");
    printf("---------------------------------------------------\n");
    printf("Ketik 'help' untuk melihat semua perintah yang tersedia.\n");
    printf("---------------------------------------------------\n");
}

void main_loop(){
    int game_running = 1;
    char aksiPengguna[MAX_INPUT];

    while (game_running)
    {
        bacaInput(aksiPengguna);
        if (strcmp(aksiPengguna, "HELP") == 0) {
            help();
        } 
        else if (strcmp(aksiPengguna, "BAG") == 0) {
            bag();
        }  
        else if (strcmp(aksiPengguna, "USE_EQUIPMENT") == 0) {
            use_equipment(); 
        }
        else if (strcmp(aksiPengguna, "change_SKILL") == 0) {
            change_skill(); 
            while (getchar() != '\n' && getchar() != EOF); 
        }  
        else if (strcmp(aksiPengguna, "OPEN_CHEST") == 0) { // <-- COMMAND BARU
            open_chest_menu(); // <-- Panggil fungsi menu chest baru
        }
        else if (strcmp(aksiPengguna, "LEARN") == 0) { // <-- TAMBAHKAN BLOK INI
        learn_skill_menu();
        }
        else if (strcmp(aksiPengguna, "EXPLORE") == 0) {
            explore(); 
        } 
        else if (strcmp(aksiPengguna, "QUIT") == 0) { // Hapus || strcmp(aksiPengguna, "quit") == 0
            save_game_data(); // Simpan data sebelum keluar
            printf("Menyimpan dan keluar. Sampai jumpa!\n");
            return; // Keluar dari main_loop
        }
        else if (strcmp(aksiPengguna, "CLS") == 0)
        {
            cls();
        }
        else {
            printf("\n!!! Pilihan aksi tidak valid: %s\n", aksiPengguna);
        }

    }
    
}

int main()
{
    // INITIALISASI RANDOM SEED
    srand(time(NULL)); 
    
    // PANGGIL SISTEM LOGIN SEBELUM START GAME
    login_system();

    start_game();
    
    // Panggil loop utama game
    main_loop(); 

    return 0;
}