#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>   

#include "game_data.h"
#define MAX_INPUT 50

    int HP = 10;
    int ATK = 2;
    int DEF = 0;
    int LEVEL = 1;
    int XP = 0;
    int GOLD = 0;

//=====================================================
void bersihkanString(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
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


void bacaInput(char *input) {
  
    // Membaca string dari input, maksimal 50 karakter
    if (fgets(input, MAX_INPUT, stdin) != NULL) {
        // Membersihkan karakter newline dari string input
        bersihkanString(input);
    }
}


  //===================================Fight and Explore>>>>>  
struct Monster get_random_monster() {
    if (JUMLAH_MONSTER == 0) {
        struct Monster default_m = {999, "Error Monster", 1, 1};
        return default_m;
    }
    
    int random_index = rand() % JUMLAH_MONSTER;
    
    return daftarMonster[random_index];
}

void monster_turn(struct Monster *musuh) {
    int aksi_monster = rand() % 100; // 0-99

    printf("\n--- Giliran %s ---\n", musuh->nama);

    if (aksi_monster < 70) { // 70% peluang Attack
        int damage = musuh->attackPower - DEF;
        if (damage < 0) damage = 0;

        HP -= damage;
        printf("%s menyerang! Anda menerima %d damage.\n", musuh->nama, damage);
    } else { // 30% peluang Heal
        int heal_amount = musuh->healthPoint * 0.10; // Heal 10% dari HP
        if (heal_amount < 1) heal_amount = 1;

        musuh->healthPoint += heal_amount;
        printf("%s melakukan penyembuhan dan memulihkan %d HP.\n", musuh->nama, heal_amount);
    }
}

void lakukan_pertarungan(struct Monster musuh) {
    char input[MAX_INPUT];

    printf("\n--> PERTARUNGAN DIMULAI dengan %s! (HP: %d)\n", musuh.nama, musuh.healthPoint);

    // Gunakan pointer untuk Monster agar perubahan HP-nya bisa disimpan
    struct Monster *musuh_ptr = &musuh; 
    
    // Loop Pertarungan Utama
    while (HP > 0 && musuh_ptr->healthPoint > 0) {
        
        // Tampilkan Status
        printf("\n== Status ==\n");
        printf("Player HP: %d | %s HP: %d\n", HP, musuh_ptr->nama, musuh_ptr->healthPoint);
        printf("Pilih Aksi: [ATTACK] | [SKILL 1] (Heal +1) | [KABUR]\n");
        
        // --- GILIRAN PLAYER ---
        
        if (fgets(input, MAX_INPUT, stdin) == NULL) continue;
        bersihkanString(input);

        if (strcmp(input, "ATTACK") == 0 || strcmp(input, "attack") == 0) {
            musuh_ptr->healthPoint -= ATK;
            printf("Anda menyerang %s dan memberikan %d damage!\n", musuh_ptr->nama, ATK);
        } 
        else if (strcmp(input, "SKILL 1") == 0 || strcmp(input, "skill 1") == 0) {
            HP += 1;
            printf("Anda menggunakan Skill 1 dan memulihkan 1 HP.\n");
        } 
        else if (strcmp(input, "KABUR") == 0 || strcmp(input, "kabur") == 0) {
            printf("Anda mencoba kabur...\n");
            // Implementasikan logika kabur (misalnya 50% berhasil)
            if (rand() % 100 < 50) {
                 printf("Berhasil kabur!\n");
                 return; // Keluar dari fungsi dan kembali ke main loop
            } else {
                 printf("Gagal kabur! Monster menyerang...\n");
                 // Monster tetap menyerang jika gagal kabur
                 monster_turn(musuh_ptr); 
            }
        }
        else {
            printf("Perintah tidak dikenal. Coba lagi.\n");
            continue; // Ulangi giliran Player
        }

        // Cek kondisi setelah aksi Player
        if (musuh_ptr->healthPoint <= 0) {
            printf("\n!!! %s Tumbang! Anda menang!\n", musuh_ptr->nama);
            printf("\n Silahkan Menjelajah lagi\n");
            // Tambahkan logika XP dan GOLD di sini
            return; 
        }

        // --- GILIRAN MUSUH ---
        monster_turn(musuh_ptr);

        // Cek kondisi setelah aksi Musuh
        if (HP <= 0) {
            printf("\n!!! Anda dikalahkan oleh %s. GAME OVER.\n", musuh_ptr->nama);
            // Tambahkan logika Game Over di sini
            return;
        }
    }
}

void kembali_ke_main() {
    printf("\nAnda berhasil kabur dari pertarungan!\n");
}




void tambahkan_item_ke_bag() {
    printf("Item Koin Emas ditambahkan ke tas.\n");
}

void start_fight(struct Monster musuh) {
    char aksi[MAX_INPUT];
    int valid_input = 0;

    printf("\n--- PERTEMUAN MONSTER ---\n");
    printf("Seekor %s (HP: %d) menghadang Anda!\n", musuh.nama, musuh.healthPoint);

    while (!valid_input) {
        printf("Pilih Aksi: [FIGHT] atau [KABUR]: ");
        
        // Membaca input (gunakan fungsi bacaInput yang sudah Anda definisikan)
        if (fgets(aksi, MAX_INPUT, stdin) != NULL) {
            bersihkanString(aksi); // Hapus karakter newline

            // Mencocokkan input
            if (strcmp(aksi, "FIGHT") == 0 || strcmp(aksi, "fight") == 0) {
                valid_input = 1;
                // Masuk ke logika pertarungan
                lakukan_pertarungan(musuh); 
                // Di akhir pertarungan, Anda akan kembali ke main_loop()
            } 
            else if (strcmp(aksi, "KABUR") == 0 || strcmp(aksi, "kabur") == 0) {
                valid_input = 1;
                // Keluar dari pertarungan dan kembali ke loop utama
                kembali_ke_main();
            } 
            else {
                printf("Perintah tidak valid. Coba lagi.\n");
            }
        }
    }
}

void explore(){
    int Nomor_Acak = rand () %100;

    printf("Anda mulai menjelajahi area...\n");

    if (Nomor_Acak >= 0 && Nomor_Acak <= 60) {
        // Monster: 0-60 (61%)
        struct Monster monster_saat_ini = get_random_monster();
        printf("Seekor monster muncul: %s (HP: %d)!\n", 
               monster_saat_ini.nama, 
               monster_saat_ini.healthPoint);
               start_fight(monster_saat_ini);
    } 
    else if (Nomor_Acak >= 61 && Nomor_Acak <= 85) {
        // Item: 61-85 (25%)
        printf("Anda menemukan sebuah item tersembunyi!\n");
        tambahkan_item_ke_bag();
    } 
    else { 
        // Kosong: 86-99 (14%)
        printf("Anda menjelajah, tetapi tidak terjadi apa-apa.\n");
    }
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


//==========================================Game Start>>>
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

void start_game(){
    //pesan awalan game
    printf("Welcome To RPG Game \n");
    printf("-------------------\n");
    printf("command 'help' to get any command\n");
}

void main_loop(){
    int game_running = 1;

    char aksiPengguna[MAX_INPUT];


    while (game_running)
    {
        bacaInput(aksiPengguna);

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
    
}

int main()
{
    start_game();
    main_loop();
    
   

    return 0;
}
