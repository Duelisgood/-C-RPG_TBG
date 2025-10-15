#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>  
#include <time.h>   

#include "utilities.h" // Sertakan header diri sendiri
#include "player_manager.h" // Untuk tambahkan_item_ke_bag

#include "data/game_data.h"
#include "data/item_data.h"
#include "data/skill_data.h"
#include "data/monster_data.h"

#define MAX_INPUT 50
#define MAX_USERNAME 50

void cls() {
    
    #ifdef _WIN32
        system("cls");
    #else
        printf("\033[H\033[J"); 
    #endif
}

void bersihkanString(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

struct Item get_item_by_id(int id) {
    for (int i = 0; i < JUMLAH_ITEM; i++) {
        if (daftarItem[i].itemID == id) {
            return daftarItem[i]; // Item ditemukan
        }
    }
    // Kembalikan item kosong jika tidak ditemukan
    struct Item empty_item = {0, "None", 0, 0, "NONE", 0}; 
    return empty_item;
}

int get_random_rarity() {
    // Menghasilkan angka acak antara 1 hingga 100
    int rarity_roll = (rand() % 100) + 1; 

    if (rarity_roll <= 50) {
        return 1; // 1-50: Umum (50%)
    } else if (rarity_roll <= 75) {
        return 2; // 51-75: Tidak Biasa (25%)
    } else if (rarity_roll <= 90) {
        return 3; // 76-90: Langka (15%)
    } else if (rarity_roll <= 97) {
        return 4; // 91-97: Epik (7%)
    } else { // 98-100
        return 5; // 98-100: Legendaris (3%)
    }
}

struct Monster get_random_monster_by_rarity(int required_rarity) {
    
    // Array sementara untuk menampung ID monster yang cocok
    int available_monster_indices[JUMLAH_MONSTER];
    int count = 0;

    // 1. Cari monster yang cocok dengan Rarity
    for (int i = 0; i < JUMLAH_MONSTER; i++) {
        if (daftarMonster[i].rarity == required_rarity) {
            available_monster_indices[count] = i; // Simpan indeks yang cocok
            count++;
        }
    }

    if (count == 0) {
        printf("Peringatan: Tidak ada monster Rarity %d yang ditemukan. Kembali ke Rarity 1.\n", required_rarity);
        // Fallback ke monster Rarity 1 jika Rarity yang diminta tidak ada
        return get_random_monster_by_rarity(1);
    }
    
    // 2. Pilih indeks acak dari daftar monster yang cocok
    int random_list_index = rand() % count;
    int final_monster_index = available_monster_indices[random_list_index];
    
    // 3. Kembalikan monster yang dipilih
    return daftarMonster[final_monster_index];
}

void heal_to_max_hp() {
    if (mainPlayer.HP < mainPlayer.MAX_HP) {
        printf("\n[Sistem]: Memulihkan HP ke %d.\n", mainPlayer.MAX_HP);
        mainPlayer.HP = mainPlayer.MAX_HP;
    }
}

int is_item_in_inventory(int itemID) {
    for (int i = 0; i < mainPlayer.inventory_count; i++) {
        if (mainPlayer.inventory[i].itemID == itemID) {
            return mainPlayer.inventory[i].quantity; // Mengembalikan jumlah item
        }
    }
    return 0; // Item tidak ditemukan
}

void bacaInput(char *input) {
    // Membaca string dari input
    if (fgets(input, MAX_INPUT, stdin) != NULL) {
        bersihkanString(input);
        
        // Konversi ke huruf kapital (standar untuk command di main_loop)
        for (int i = 0; input[i]; i++) {
            input[i] = toupper(input[i]); 
        }
    }
}

void help(){
    printf("\n--- DAFTAR PERINTAH ---\n");
    printf("EXPLORE       - Mulai menjelajahi area untuk bertemu monster atau menemukan hadiah.\n");
    printf("BAG           - Menampilkan status karakter, equipment yang dipakai, dan isi tas.\n");
    printf("USE_EQUIPMENT - Membuka menu untuk memakai atau mengganti Weapon, Armor, dan Helmet.\n");
    printf("CHANGE_SKILL  - Membuka menu untuk mengganti skill aktif yang bisa digunakan dalam pertarungan.\n");
    printf("OPEN_CHEST    - Membuka menu untuk menggunakan Kunci dan membuka Peti Harta Karun.\n");
    printf("LEARN_BOOk    - Membuka menu untuk mempelajari skill baru dari buku yang dimiliki.\n");
    printf("QUIT          - Menyimpan permainan dan keluar dari program.\n");
    printf("SHOP          - Membuka toko untuk membeli dan menjual item.\n");
    printf("HELP          - Menampilkan daftar perintah ini.\n");
    printf("CLS           - Membersihkan layar konsol.\n");
    printf("------------------------\n");
}

struct Skill get_skill_by_id(int id) {
    for (int i = 0; i < JUMLAH_SKILL; i++) {
        if (daftarSkill[i].skillID == id) {
            return daftarSkill[i];
        }
    }
    // Mengembalikan skill kosong jika tidak ditemukan
    struct Skill empty = {0}; 
    return empty;
}

void apply_stat_boosts() {
    // 1. Hitung Base HP (Asumsi 10 HP di awal + 10 per level)
    int base_hp_from_level = 10 + (mainPlayer.LEVEL - 1) * 10;
    
    // 2. Terapkan Bonus HP dari Helmet
    mainPlayer.MAX_HP = base_hp_from_level + mainPlayer.bonus_hp;

    // Jaga agar HP saat ini tidak melebihi MAX HP baru
    if (mainPlayer.HP > mainPlayer.MAX_HP) {
        mainPlayer.HP = mainPlayer.MAX_HP;
    }

    // 3. Hitung Base ATK (Asumsi ATK dasar 2 + 2 per level)
    int base_atk_from_level = 2 + (mainPlayer.LEVEL - 1) * 2; 

    // 4. Terapkan Bonus ATK dari Weapon
    mainPlayer.ATK = base_atk_from_level + mainPlayer.bonus_atk;
    
    // 5. Terapkan Bonus DEF dari Armor
    mainPlayer.DEF = mainPlayer.bonus_def; 
}

struct Skill get_random_skill_by_rarity(int required_rarity) {
    int available_skill_indices[JUMLAH_SKILL];
    int count = 0;

    // 1. Cari skill yang cocok dengan Rarity
    for (int i = 0; i < JUMLAH_SKILL; i++) {
        if (daftarSkill[i].rarity == required_rarity) {
            available_skill_indices[count] = i; // Simpan indeks yang cocok
            count++;
        }
    }

    if (count == 0) {
        // Fallback: Jika Rarity yang diminta tidak ada, coba Rarity 1
        printf("Peringatan: Tidak ada skill Rarity %d yang ditemukan. Mencoba Rarity 1.\n", required_rarity);
        return get_random_skill_by_rarity(1);
    }
    
    // 2. Pilih indeks acak dari daftar skill yang cocok
    int random_list_index = rand() % count;
    int final_skill_index = available_skill_indices[random_list_index];
    
    // 3. Kembalikan skill yang dipilih
    return daftarSkill[final_skill_index];
}

struct Item get_random_item_by_rarity(int required_rarity) {
    
    // Array sementara untuk menampung indeks item yang cocok
    int available_item_indices[JUMLAH_ITEM];
    int count = 0;

    // 1. Cari item yang cocok dengan Rarity
    for (int i = 0; i < JUMLAH_ITEM; i++) {
        // Hanya pertimbangkan item yang dapat ditemukan (misalnya BUKAN Consumable)
        // Kita asumsikan semua item non-Consumable dapat ditemukan.
        if (daftarItem[i].rarity == required_rarity && 
            strcmp(daftarItem[i].type, "CONSUMABLE") != 0) { 
            available_item_indices[count] = i; // Simpan indeks yang cocok
            count++;
        }
    }

    if (count == 0) {
        printf("Peringatan: Tidak ada item Rarity %d yang ditemukan. Mencari Rarity 1.\n", required_rarity);
        // Fallback: Jika Rarity yang diminta tidak ada, ambil item Rarity 1
        return get_random_item_by_rarity(1);
    }
    
    // 2. Pilih indeks acak dari daftar item yang cocok
    int random_list_index = rand() % count;
    int final_item_index = available_item_indices[random_list_index];
    
    // 3. Kembalikan item yang dipilih
    return daftarItem[final_item_index];
}

// File: utilities.c (Tambahkan di bagian paling bawah)

void drop_chest_key_by_rarity(int monster_rarity) {
    // Array sementara untuk menampung ID kunci yang cocok dengan rarity monster
    int available_key_ids[JUMLAH_ITEM];
    int count = 0;

    // 1. Cari semua item dengan tipe "CHEST" dan rarity yang sesuai
    for (int i = 0; i < JUMLAH_ITEM; i++) {
        if (strcmp(daftarItem[i].type, "CHEST") == 0 && daftarItem[i].rarity == monster_rarity) {
            available_key_ids[count] = daftarItem[i].itemID;
            count++;
        }
    }

    // 2. Jika ada kunci yang ditemukan, pilih satu secara acak
    if (count > 0) {
        int random_index = rand() % count;
        int dropped_key_id = available_key_ids[random_index];
        
        // Dapatkan detail item kunci untuk menampilkan namanya
        struct Item dropped_key = get_item_by_id(dropped_key_id);

        // 3. Tambahkan kunci yang dipilih ke tas pemain
        printf("\n[Loot Drop]: Monster menjatuhkan sebuah kunci: %s (Rarity: %d)!\n", dropped_key.nama, dropped_key.rarity);
        tambahkan_item_ke_bag(dropped_key_id, 1);
    }
    // Jika tidak ada kunci dengan rarity tersebut (count == 0), tidak terjadi apa-apa.
}

// File: utilities.c (Tambahkan di bagian bawah)

void drop_skill_book_by_rarity(int monster_rarity) {
    // Array sementara untuk menampung ID buku yang cocok
    int available_book_ids[JUMLAH_ITEM];
    int count = 0;

    // 1. Cari semua item dengan tipe "BOOK" dan rarity yang sesuai
    for (int i = 0; i < JUMLAH_ITEM; i++) {
        if (strcmp(daftarItem[i].type, "BOOK") == 0 && daftarItem[i].rarity == monster_rarity) {
            available_book_ids[count] = daftarItem[i].itemID;
            count++;
        }
    }

    // 2. Jika ada buku yang ditemukan, pilih satu secara acak
    if (count > 0) {
        int random_index = rand() % count;
        int dropped_book_id = available_book_ids[random_index];
        
        struct Item dropped_book = get_item_by_id(dropped_book_id);

        printf("\n[Loot Drop]: Monster menjatuhkan sebuah buku: %s (Rarity: %d)!\n", dropped_book.nama, dropped_book.rarity);
        tambahkan_item_ke_bag(dropped_book_id, 1);
    }
    // Jika tidak ada buku dengan rarity tersebut, tidak terjadi apa-apa
}

void handle_monster_loot_drop(int monster_rarity) {
    int roll = rand() % 100; // Menghasilkan angka acak dari 0 hingga 99

    if (roll < 50) {
        // 50% kemungkinan (0-49): Drop Kunci Peti (Loot Box)
        drop_chest_key_by_rarity(monster_rarity);
    } else {
        // 50% kemungkinan (50-99): Drop Buku Skill
        drop_skill_book_by_rarity(monster_rarity);
    }
}

