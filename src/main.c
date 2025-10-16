#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>  
#include <time.h>   

#include "data/game_data.h" 
#include "utilities.h"
#include "player_manager.h"
#include "combat.h"    
#include "shop.h"  
#include "trainer.h"
#include "enchanter.h"
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
        else if (strcmp(aksiPengguna, "CHANGE_SKILL") == 0) {
            change_skill(); 
        }  
        else if (strcmp(aksiPengguna, "OPEN_CHEST") == 0) { // <-- COMMAND BARU
            open_chest_menu(); // <-- Panggil fungsi menu chest baru
        }
        else if (strcmp(aksiPengguna, "LEARN_BOOK") == 0) { // <-- TAMBAHKAN BLOK INI
            learn_skill_menu();
        }
        else if (strcmp(aksiPengguna, "EXPLORE") == 0) {
            explore(); 
        } 
        else if (strcmp(aksiPengguna, "ENCHANTER") == 0) { // <-- TAMBAHKAN
            open_enchanter_menu();
        }       
        else if (strcmp(aksiPengguna, "TRAINER") == 0) { // <-- TAMBAHKAN BLOK INI
            open_trainer_menu();
        }
        else if (strcmp(aksiPengguna, "SHOP") == 0) { // <-- TAMBAHKAN BLOK INI
            open_shop_menu();
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