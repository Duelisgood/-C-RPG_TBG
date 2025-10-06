#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>   

#include "game_data.h"
#define MAX_INPUT 50

//=====================================player stats>>>
    int HP = 10;
    int ATK = 2;
    int DEF = 0;
    int LEVEL = 1;
    int XP = 0;
    int GOLD = 0;

//=================================Skill CD>>
int SKILL_1_CD = 0; 
int SKILL_2_CD = 0; 

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
    struct Monster *musuh_ptr = &musuh; 

    struct Skill skill1_data = daftarSkill[2];
    struct Skill skill2_data = daftarSkill[4];
    
    printf("\n--> PERTARUNGAN DIMULAI dengan %s! (HP: %d)\n", musuh.nama, musuh.healthPoint);

    while (HP > 0 && musuh_ptr->healthPoint > 0) {
        
        // --- 1. PENGURANGAN COOLDOWN ---
        if (SKILL_1_CD > 0) SKILL_1_CD--;
        if (SKILL_2_CD > 0) SKILL_2_CD--;

        // Tampilkan Status
        printf("\n== Status ==\n");
        printf("Player HP: %d | %s HP: %d\n", HP, musuh_ptr->nama, musuh_ptr->healthPoint);

        printf("Pilih Aksi: [ATTACK] | [SKILL 1] (%s) (CD: %d) | [SKILL 2] (%s) (CD: %d) | [KABUR]\n",
            skill1_data.nama, SKILL_1_CD, skill2_data.nama, SKILL_2_CD);
        
        // --- 2. GILIRAN PLAYER ---
        if (fgets(input, MAX_INPUT, stdin) == NULL) continue;
        bersihkanString(input);

        int turn_taken = 0;

        if (strcmp(input, "ATTACK") == 0) {
            musuh_ptr->healthPoint -= ATK;
            printf("Anda menyerang %s dan memberikan %d damage!\n", musuh_ptr->nama, ATK);
            turn_taken = 1;
        } 
        else if (strcmp(input, "SKILL 1") == 0) {
            if (SKILL_1_CD > 0) {
                printf("Skill 1 (%s) sedang cooldown (%d turn tersisa).\n", skill1_data.nama, SKILL_1_CD);
                continue; // Ulangi giliran Player
            }
            
                if (strcmp(skill1_data.effect_type, "HEAL") == 0) {
                    HP += skill1_data.effect_value;
                } else if (strcmp(skill1_data.effect_type, "ATTACK") == 0) {
                    musuh_ptr->healthPoint -= (ATK + skill1_data.effect_value);
                }

                printf("Anda menggunakan %s!\n", skill1_data.nama);
                SKILL_1_CD = skill1_data.cooldown_max; 
                turn_taken = 1;
            } 

        else if (strcmp(input, "SKILL 2") == 0) {
            if (SKILL_2_CD > 0) {
                printf("Skill 2 (%s) sedang cooldown (%d turn tersisa).\n", skill2_data.nama, SKILL_2_CD);
                continue; // Ulangi giliran Player
            }
                if (strcmp(skill1_data.effect_type, "HEAL") == 0) {
                    HP += skill1_data.effect_value;
                } else if (strcmp(skill1_data.effect_type, "ATTACK") == 0) {
                    musuh_ptr->healthPoint -= (ATK + skill1_data.effect_value);
                }
            }

        else if (strcmp(input, "KABUR") == 0) {

            return; 
        }
        else {
            printf("Perintah tidak dikenal. Coba lagi.\n");
            continue; // Ulangi giliran Player
        }

        // --- 3. Cek Kemenangan dan Giliran Musuh ---
        
        if (musuh_ptr->healthPoint <= 0) {
            printf("\n!!! %s Tumbang! Anda menang!\n", musuh_ptr->nama);
            return; 
        }
        
        // Hanya jika Player mengambil aksi yang valid (turn_taken == 1)
        if (turn_taken) {
            monster_turn(musuh_ptr);
        }

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
