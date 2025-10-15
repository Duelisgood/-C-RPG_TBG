#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>  
#include <time.h>   

#include "combat.h" // Sertakan header diri sendiri
#include "utilities.h"
#include "player_manager.h"

#include "data/game_data.h"
#include "data/monster_data.h"
#include "data/item_data.h"
#include "data/skill_data.h"

#define MAX_INPUT 50
#define MAX_USERNAME 50

void monster_turn(struct Monster *musuh); // <--- TAMBAHKAN BARIS INI
void kembali_ke_main();

void kembali_ke_main() {
    printf("\nAnda berhasil kabur dari pertarungan!\n");
}


void lakukan_pertarungan(struct Monster musuh) {
    
    printf("[DEBUG] Nilai saat pertarungan dimulai -> Skill 1 Index: %d, Skill 2 Index: %d\n", 
           mainPlayer.active_skill_1_index, mainPlayer.active_skill_2_index);

    mainPlayer.skill_1_cd = 0; // <-- TAMBAHKAN BARIS INI
    mainPlayer.skill_2_cd = 0;

    char input[MAX_INPUT];
    struct Monster *musuh_ptr = &musuh; 
    
    int skill1_id = mainPlayer.owned_skill_ids[mainPlayer.active_skill_1_index];
    int skill2_id = mainPlayer.owned_skill_ids[mainPlayer.active_skill_2_index];

   
    struct Skill skill1_data = get_skill_by_id(skill1_id);
    struct Skill skill2_data = get_skill_by_id(skill2_id);

    
    printf("\n--> PERTARUNGAN DIMULAI dengan %s! (HP: %d)\n", musuh.nama, musuh.healthPoint);

    while (mainPlayer.HP > 0 && musuh_ptr->healthPoint > 0) {
        
        // --- 1. PENGURANGAN COOLDOWN ---
        if (mainPlayer.skill_1_cd > 0) mainPlayer.skill_1_cd--;
        if (mainPlayer.skill_2_cd > 0) mainPlayer.skill_2_cd--;

        // Tampilkan Status
        printf("\n== Status ==\n");
        printf("Player HP: %d | %s HP: %d\n", mainPlayer.HP, musuh_ptr->nama, musuh_ptr->healthPoint);

        printf("Pilih Aksi: [ATTACK] | [SKILL 1] (%s) (CD: %d) | [SKILL 2] (%s) (CD: %d) | [KABUR]\n",
            skill1_data.nama, mainPlayer.skill_1_cd, skill2_data.nama, mainPlayer.skill_2_cd);
        
        // --- 2. GILIRAN PLAYER ---
        if (fgets(input, MAX_INPUT, stdin) == NULL) continue; 
        bersihkanString(input);

          for (int i = 0; input[i]; i++) {
            input[i] = toupper(input[i]); 
        }

        int turn_taken = 0;

        if (strcmp(input, "ATTACK") == 0) {
            musuh_ptr->healthPoint -= mainPlayer.ATK;
            printf("Anda menyerang %s dan memberikan %d damage!\n", musuh_ptr->nama, mainPlayer.ATK);
            turn_taken = 1;
        } 
        else if (strcmp(input, "SKILL 1") == 0) {
            if (mainPlayer.skill_1_cd > 0) {
                printf("Skill 1 (%s) sedang cooldown (%d turn tersisa).\n", skill1_data.nama, mainPlayer.skill_1_cd);
                continue;
            }
            
            if (strcmp(skill1_data.effect_type, "HEAL") == 0) {
                int old_hp = mainPlayer.HP;
                mainPlayer.HP += skill1_data.effect_value;
                if (mainPlayer.HP > mainPlayer.MAX_HP) {
                    mainPlayer.HP = mainPlayer.MAX_HP;
                }
                int actual_healed = mainPlayer.HP - old_hp;
                printf("Anda menggunakan skill %s dan memulihkan %d HP!\n", skill1_data.nama, actual_healed);

            } else if (strcmp(skill1_data.effect_type, "ATTACK") == 0) {
                int total_damage = mainPlayer.ATK + skill1_data.effect_value;
                musuh_ptr->healthPoint -= total_damage;
                printf("Anda menggunakan skill %s dan memberikan %d damage!\n", skill1_data.nama, total_damage);
            }

            mainPlayer.skill_1_cd = skill1_data.cooldown_max; 
            turn_taken = 1;
        }

        else if (strcmp(input, "SKILL 2") == 0) {
            if (mainPlayer.skill_2_cd > 0) {
                printf("Skill 2 (%s) sedang cooldown (%d turn tersisa).\n", skill2_data.nama, mainPlayer.skill_2_cd);
                continue;
            }
            
            if (strcmp(skill2_data.effect_type, "HEAL") == 0) { 
                int old_hp = mainPlayer.HP;
                mainPlayer.HP += skill2_data.effect_value;
                if (mainPlayer.HP > mainPlayer.MAX_HP) {
                    mainPlayer.HP = mainPlayer.MAX_HP;
                }
                int actual_healed = mainPlayer.HP - old_hp;
                printf("Anda menggunakan skill %s dan memulihkan %d HP!\n", skill2_data.nama, actual_healed);

            } else if (strcmp(skill2_data.effect_type, "ATTACK") == 0) { 
                int total_damage = mainPlayer.ATK + skill2_data.effect_value;
                musuh_ptr->healthPoint -= total_damage;
                printf("Anda menggunakan skill %s dan memberikan %d damage!\n", skill2_data.nama, total_damage);
            }

            mainPlayer.skill_2_cd = skill2_data.cooldown_max; 
            turn_taken = 1;
        }

         else if (strcmp(input, "KABUR") == 0) {
            
            // Logika Kabur (50% Berhasil)
            if (rand() % 100 < 50) { 
                printf("Anda berhasil kabur dari %s dan kembali ke menu utama!\n", musuh_ptr->nama);
                return; // Keluar dari pertarungan
            } else {
                printf("Gagal kabur! %s menyerang Anda saat mencoba lari!\n", musuh_ptr->nama);
                turn_taken = 1; // Dianggap mengambil giliran yang gagal, monster harus menyerang
            }
        }

        else {
            printf("Perintah tidak dikenal. Coba lagi.\n");
            continue; // Ulangi giliran Player
        }

        // --- 3. Cek Kemenangan dan Giliran Musuh ---
        
      // --- 3. Cek Kemenangan dan Giliran Musuh ---
        
        if (musuh_ptr->healthPoint <= 0) {
            printf("\n!!! %s Tumbang! Anda menang!\n", musuh_ptr->nama);
            
            // Hadiah (GOLD dan XP)
            mainPlayer.GOLD += musuh_ptr->goldDrop;
            mainPlayer.XP += musuh_ptr->expDrop;
            printf("Anda mendapatkan %d Gold dan %d XP.\n", musuh_ptr->goldDrop, musuh_ptr->expDrop);

            handle_monster_loot_drop(musuh_ptr->rarity); 

            heal_to_max_hp();
            check_for_level_up();
            save_game_data(); 

            return; // KELUAR dari lakukan_pertarungan()
        } 

        // Hanya jika Player mengambil aksi yang valid (turn_taken == 1)
        if (turn_taken) {
            monster_turn(musuh_ptr);
        }

        if (mainPlayer.HP <= 0) {
            printf("\n!!! Anda dikalahkan oleh %s! ---\n", musuh_ptr->nama);

            // Penalti: Kehilangan 10% Gold
            int gold_loss = mainPlayer.GOLD * 0.10;
            if (gold_loss < 1 && mainPlayer.GOLD > 0) {
                gold_loss = 1; // Kehilangan minimal 1 gold jika punya
            }
            mainPlayer.GOLD -= gold_loss;
            if (mainPlayer.GOLD < 0) {
                mainPlayer.GOLD = 0;
            }
            printf("Anda kehilangan %d Gold.\n", gold_loss);

            // Pulihkan HP pemain agar bisa melanjutkan permainan
            heal_to_max_hp();
            
            // Simpan status setelah kekalahan (HP penuh, Gold berkurang)
            save_game_data();

            printf("Anda kembali ke kota untuk memulihkan diri...\n");
            return; // Keluar dari pertarungan
        }
    } // Akhir dari while loop pertarungan
} // Akhir dari fungsi l

void start_fight(struct Monster musuh) {
    char aksi[MAX_INPUT];
    int valid_input = 0;

    printf("\n--- PERTEMUAN MONSTER ---\n");
    printf("Seekor %s (HP: %d) menghadang Anda!\n", musuh.nama, musuh.healthPoint);

    while (!valid_input) {
        printf("Pilih Aksi: [FIGHT] atau [KABUR]: ");
        
        if (fgets(aksi, MAX_INPUT, stdin) != NULL) {
            bersihkanString(aksi); 
            for (int i = 0; aksi[i]; i++) {
                aksi[i] = toupper(aksi[i]); 
            }

            if (strcmp(aksi, "FIGHT") == 0) {
                lakukan_pertarungan(musuh); 
                return; // <-- HARUS KELUAR DARI start_fight setelah pertarungan selesai
            } 
            else if (strcmp(aksi, "KABUR") == 0) {
                kembali_ke_main();
                return; // <-- HARUS KELUAR DARI start_fight setelah kabur
            } 
            else {
                printf("Perintah tidak valid. Coba lagi.\n");
            }
        }
    }
}

void monster_turn(struct Monster *musuh) {
    int aksi_monster = rand() % 100; // 0-99

    printf("\n--- Giliran %s ---\n", musuh->nama);

    if (aksi_monster < 50) { // 50% peluang Attack (0 - 49)
        int damage = musuh->attackPower - mainPlayer.DEF;
        if (damage < 0) damage = 0;

        mainPlayer.HP -= damage;
        printf("%s menyerang dengan serangan dasar! Anda menerima %d damage.\n", musuh->nama, damage);
    } 
    else if (aksi_monster < 75) { // 25% peluang Heal (50 - 74)
        int heal_amount = musuh->healthPoint * 0.10; 
        if (heal_amount < 1) heal_amount = 1;

        musuh->healthPoint += heal_amount;
        printf("%s melakukan penyembuhan dan memulihkan %d HP.\n", musuh->nama, heal_amount);
    }
    else { // 25% peluang Skill (75 - 99)
        int skill_damage = musuh->attackPower + musuh->skillPower;
        int damage = skill_damage - mainPlayer.DEF;
        if (damage < 0) damage = 0;
        
        mainPlayer.HP -= damage;
        printf("%s menggunakan **SKILL KHUSUS** dan menyerang Anda! Anda menerima %d damage.\n", musuh->nama, damage);
    }
    
    // Pastikan HP Player tidak negatif
    if (mainPlayer.HP < 0) {
        mainPlayer.HP = 0;
    }
}

void explore(){
    int Nomor_Acak = rand () %100;

    printf("Anda mulai menjelajahi area...\n");

    if (Nomor_Acak >= 0 && Nomor_Acak <= 60) {
        // Monster: 0-60 (61%)

        // BARU: 1. Tentukan Rarity monster
        int monster_rarity = get_random_rarity(); 
        
        // BARU: 2. Dapatkan monster yang sesuai Rarity
        struct Monster monster_saat_ini = get_random_monster_by_rarity(monster_rarity);
        
        printf("Seekor monster muncul: %s (Rarity %d, HP: %d)!\n", 
               monster_saat_ini.nama, 
               monster_rarity, // Tampilkan rarity-nya
               monster_saat_ini.healthPoint);
               
        start_fight(monster_saat_ini);
    } 
    else if (Nomor_Acak >= 61 && Nomor_Acak <= 85) {
        // Item/Skill Encounter: 61-85 (25%)
        printf("Anda menemukan sebuah hadiah tersembunyi!\n");

        // Tentukan Rarity hadiah
        int prize_rarity = get_random_rarity(); 
        
        // Tentukan Tipe Hadiah: 50% Skill (0-49), 50% Equipment (50-99)
        int prize_type_roll = rand() % 100;

        if (prize_type_roll < 50) {
            struct Skill skill_ditemukan = get_random_skill_by_rarity(prize_rarity);

            if (skill_ditemukan.skillID != 0) {
                learn_new_skill(skill_ditemukan.skillID);
            } else {
                 printf("Hadiah skill gagal ditemukan.\n");
            }

        } else {
        
            struct Item item_ditemukan = get_random_item_by_rarity(prize_rarity);
            
            // Tambahkan item ke bag (misal: selalu 1 buah)
            tambahkan_item_ke_bag(item_ditemukan.itemID, 1);
            
            printf("Anda menemukan Equipment: ID %d - %s (Rarity %d).\n", item_ditemukan.itemID, item_ditemukan.nama, item_ditemukan.rarity);
        }
    }  
    else { 
        // Kosong: 86-99 (14%)
        printf("Anda menjelajah, tetapi tidak terjadi apa-apa.\n");
    }
}