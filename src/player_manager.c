#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>  
#include <time.h>   

#include "player_manager.h" // Selalu sertakan header diri sendiri
#include "utilities.h"

#include "data/game_data.h"
#include "data/item_data.h"
#include "data/skill_data.h"
#include "data/treasure_data.h"
#define MAX_INPUT 50
#define MAX_USERNAME 50

struct Item get_item_by_id(int id); 

struct Player mainPlayer = {
    .username = "",
    .HP = 10,
    .MAX_HP = 10, 
    .ATK = 2,
    .DEF = 0,
    .LEVEL = 1,
    .XP = 0,
    .GOLD = 0,
    .equipped_weapon_id = 0,
    .bonus_atk = 0,
    .equipped_armor_id = 0, 
    .bonus_def = 0,   
    .skill_1_cd = 0,
    .skill_2_cd = 0,
    .active_skill_1_index = 0,
    .active_skill_2_index = 1,
    .inventory_count = 0,
    .owned_skill_ids = {101, 102, 0, 0, 0, 0, 0, 0, 0, 0}, 
    .owned_skill_count = 2    
};

void save_game_data() {
    if (strcmp(mainPlayer.username, "") == 0) {
        // Hanya simpan jika ada pemain yang login
        return; 
    }

    FILE *file = fopen(mainPlayer.username, "w");
    if (file == NULL) {
        printf("ERROR: Gagal menyimpan data ke file %s. Periksa izin folder.\n", mainPlayer.username);
        return;
    }

    // Tulis semua stat Player ke file
    fprintf(file, "HP=%d\n", mainPlayer.HP);
    fprintf(file, "MAX_HP=%d\n", mainPlayer.MAX_HP);
    fprintf(file, "ATK=%d\n", mainPlayer.ATK);
    fprintf(file, "DEF=%d\n", mainPlayer.DEF);
    fprintf(file, "LEVEL=%d\n", mainPlayer.LEVEL);
    fprintf(file, "XP=%d\n", mainPlayer.XP);
    fprintf(file, "GOLD=%d\n", mainPlayer.GOLD);
    fprintf(file, "equipped_armor_id=%d\n", mainPlayer.equipped_armor_id); 
    fprintf(file, "equipped_weapon_id=%d\n", mainPlayer.equipped_weapon_id);
    fprintf(file, "bonus_def=%d\n", mainPlayer.bonus_def);  

    fprintf(file, "active_skill_1_index=%d\n", mainPlayer.active_skill_1_index);
    fprintf(file, "active_skill_2_index=%d\n", mainPlayer.active_skill_2_index);
    fprintf(file, "skill_1_cd=%d\n", mainPlayer.skill_1_cd);
    fprintf(file, "skill_2_cd=%d\n", mainPlayer.skill_2_cd);
    
    // Simpan daftar Skill yang dimiliki (Owned Skills)
    fprintf(file, "OWNED_SKILL_COUNT=%d\n", mainPlayer.owned_skill_count);
    for (int i = 0; i < mainPlayer.owned_skill_count; i++) {
        fprintf(file, "SKILL_OWNED_ID=%d\n", mainPlayer.owned_skill_ids[i]);
    }

    // Tambahkan stat lain di sini jika ada (misal: EQUIPPED_WEAPON_ID)
    fprintf(file, "BAG_SIZE=%d\n", mainPlayer.inventory_count);
    for (int i = 0; i < mainPlayer.inventory_count; i++) {
        // Tulis ITEM=ID,Quantity
        fprintf(file, "ITEM=%d,%d\n", 
                mainPlayer.inventory[i].itemID, 
                mainPlayer.inventory[i].quantity);
    }

    fclose(file);
    printf("[Data berhasil disimpan ke %s]\n", mainPlayer.username);
}

void load_game_data(const char *username) {
    FILE *file = fopen(username, "r");
    if (file == NULL) {
        printf("ERROR: Gagal memuat data dari file %s.\n", username);
        return;
    }

    int owned_skill_counter = 0;
    char key[20];
    int value;
    char line[100];
    int load_index = 0; // Indeks untuk inventory item
    
    // Reset inventory sebelum memuat
    mainPlayer.inventory_count = 0; 
    
    // Pastikan array owned_skill_ids juga di-reset (hanya untuk keamanan)
    // Walaupun owned_skill_counter=0 sudah cukup
    
    // LOOP TUNGGAL: Membaca file BARIS DEMI BARIS
    while (fgets(line, sizeof(line), file) != NULL) {
        
        bersihkanString(line);

        // 1. COBA MUAT DATA BACKPACK ITEM (Paling spesifik)
        if (strncmp(line, "ITEM=", 5) == 0) {
            int id, qty;
            if (sscanf(line, "ITEM=%d,%d", &id, &qty) == 2) {
                if (load_index < MAX_INVENTORY_SLOTS) {
                    mainPlayer.inventory[load_index].itemID = id;
                    mainPlayer.inventory[load_index].quantity = qty;
                    load_index++;
                }
            }
        }
        
        // 2. COBA MUAT DATA SKILL YANG DIMILIKI (SKILL_OWNED_ID=ID)
        else if (strncmp(line, "SKILL_OWNED_ID=", 15) == 0) {
            int skill_id;
            if (sscanf(line, "SKILL_OWNED_ID=%d", &skill_id) == 1) {
                if (owned_skill_counter < MAX_SKILLS_OWNED) {
                    mainPlayer.owned_skill_ids[owned_skill_counter] = skill_id;
                    owned_skill_counter++;
                }
            }
        } 
        
        // 3. COBA MUAT STAT DASAR (Sisanya, format KEY=VALUE)
        else if (sscanf(line, "%19[^=]=%d", key, &value) == 2) {
            
            if (strcmp(key, "HP") == 0) mainPlayer.HP = value;
            else if (strcmp(key, "MAX_HP") == 0) mainPlayer.MAX_HP = value;
            else if (strcmp(key, "ATK") == 0) mainPlayer.ATK = value;
            else if (strcmp(key, "DEF") == 0) mainPlayer.DEF = value;
            else if (strcmp(key, "LEVEL") == 0) mainPlayer.LEVEL = value;
            else if (strcmp(key, "XP") == 0) mainPlayer.XP = value;
            else if (strcmp(key, "GOLD") == 0) mainPlayer.GOLD = value;
            else if (strcmp(key, "equipped_armor_id") == 0) mainPlayer.equipped_armor_id = value; 
            else if (strcmp(key, "bonus_def") == 0) mainPlayer.bonus_def = value; 
            else if (strcmp(key, "active_skill_1_index") == 0) mainPlayer.active_skill_1_index = value;
            else if (strcmp(key, "active_skill_2_index") == 0) mainPlayer.active_skill_2_index = value;
            else if (strcmp(key, "skill_1_cd") == 0) mainPlayer.skill_1_cd = value;
            else if (strcmp(key, "skill_2_cd") == 0) mainPlayer.skill_2_cd = value;
            else if (strcmp(key, "OWNED_SKILL_COUNT") == 0) mainPlayer.owned_skill_count = value;
        }
        
        // Baris yang tidak cocok dengan format apapun (misalnya baris kosong atau komentar) diabaikan.
    } // Tutup loop utama while (fgets)

    // Tetapkan inventory_count global dari jumlah item yang berhasil dimuat
    mainPlayer.inventory_count = load_index; 
    
    // Jumlah skill yang dimiliki harus berdasarkan counter, bukan dari file (jika file rusak)
    mainPlayer.owned_skill_count = owned_skill_counter; 
    
    fclose(file);
    apply_stat_boosts(); 

    printf("Data %s dimuat. Level %d | HP %d | ATK %d | Item di tas: %d\n", 
           username, mainPlayer.LEVEL, mainPlayer.HP, mainPlayer.ATK, mainPlayer.inventory_count);
}

void check_for_level_up() {
    int exp_needed = 100 * mainPlayer.LEVEL;
    
    // Perulangan untuk menangani multi-level up
    while (mainPlayer.XP >= exp_needed) {
        mainPlayer.LEVEL++;
        // Kurangi EXP yang dibutuhkan
        mainPlayer.XP -= exp_needed; 
        
        // Peningkatan Stat (Anda bisa atur sesuai keinginan)
        mainPlayer.MAX_HP += 10; // +10 Max HP
        mainPlayer.HP += 10;     // Pulihkan Current HP sebesar kenaikannya
        mainPlayer.ATK += 2; 
        mainPlayer.DEF += 1; 

        printf("\n***********************************\n");
        printf("!!! SELAMAT! Anda naik ke LEVEL %d !!!\n", mainPlayer.LEVEL);
        printf("Stat bertambah: MAX HP +10, ATK +2, DEF +1.\n");
        printf("***********************************\n");
        
        // Hitung ulang EXP yang dibutuhkan untuk level berikutnya
        exp_needed = 100 * mainPlayer.LEVEL;
    }
}

void login_system() {
    char username[MAX_USERNAME];
    char choice[MAX_INPUT];
    FILE *file = NULL;
    int valid_choice = 0;

    printf("--- SISTEM LOGIN ---\n");

    // --- LOOP UNTUK MEMASTIKAN COMMAND VALID ---
    while (!valid_choice) {
        printf("Pilih: [LOGIN] atau [REGISTER] (atau QUIT): ");

        if (fgets(choice, MAX_INPUT, stdin) == NULL) continue;
        bersihkanString(choice);

        // Ubah input menjadi huruf kapital untuk perbandingan yang lebih mudah
        for (int i = 0; choice[i]; i++) {
            choice[i] = toupper(choice[i]); // toupper memerlukan <ctype.h>
        }
        
        if (strcmp(choice, "QUIT") == 0) {
            printf("Terima kasih, sampai jumpa!\n");
            exit(0); // Keluar dari program
        } 
        else if (strcmp(choice, "LOGIN") == 0 || strcmp(choice, "REGISTER") == 0) {
            valid_choice = 1; // Input valid, keluar dari loop command
        } else {
            printf("!!! Perintah tidak valid. Harap masukkan LOGIN, REGISTER, atau QUIT. !!!\n");
            // Kembali ke awal loop command
        }
    }

    // --- INPUT USERNAME (Hanya diproses setelah command valid) ---
    printf("Masukkan Username: ");
    if (fgets(username, MAX_USERNAME, stdin) == NULL) {
        printf("Input gagal.\n");
        login_system(); // Kembali ke awal fungsi jika input username gagal
        return;
    }
    bersihkanString(username);

    // 1. OPSI REGISTER
    if (strcmp(choice, "REGISTER") == 0) {
        
        file = fopen(username, "r");
        if (file != NULL) {
            printf("--- AKUN SUDAH ADA. Silakan LOGIN. ---\n");
            fclose(file);
            login_system(); // Coba lagi
            return;
        }
        
        // Buat file baru
        file = fopen(username, "w");
        // ... (Cek error file) ...
        fclose(file);

        // Set stat awal dan simpan ke file
        mainPlayer.HP = 10; 
        mainPlayer.MAX_HP = 10; // <-- FIX: Set Max HP awal
        mainPlayer.ATK = 2; 
        mainPlayer.DEF = 0; // <-- FIX: Set DEF awal
        // ... (Set stat dasar lainnya) ...
        
        // --- INISIALISASI INVENTORY ---
        tambahkan_item_ke_bag(101, 1);  
        // -----------------------------

        mainPlayer.owned_skill_count = 0; 

        // 2. Tambahkan Skill ID 101 dan 102 ke daftar yang dimiliki
        // (Anda dapat membuat fungsi 'learn_skill' terpisah, tapi kita lakukan inline di sini)
        mainPlayer.owned_skill_ids[0] = 101;
        mainPlayer.owned_skill_ids[1] = 102;
        mainPlayer.owned_skill_count = 2; // Pemain memiliki 2 skill

        // 3. Atur sebagai Skill Aktif
        // active_skill_1_index dan 2 menyimpan index dalam array owned_skill_ids
        mainPlayer.active_skill_1_index = 0; // Skill 1: Index 0 (ID 101)
        mainPlayer.active_skill_2_index = 1; // Skill 2: Index 1 (ID 102)

        strcpy(mainPlayer.username, username);
        save_game_data(); 
        cls();

        printf("--- Registrasi Sukses! Akun %s dibuat. Silakan LOGIN untuk bermain. ---\n", username);
        login_system();
        return;
    } 
    
    // 2. OPSI LOGIN
    else if (strcmp(choice, "LOGIN") == 0) {
        
        file = fopen(username, "r");
        if (file == NULL) {
            printf("--- ERROR: Username tidak ditemukan. Silakan REGISTER. ---\n");
            login_system();
            return;
        }
        
        printf("\n");
        printf("--- Login Sukses! Selamat datang, %s. ---\n", username);
        fclose(file);
        
        // Set username aktif dan muat data dari file
        strcpy(mainPlayer.username, username);
        load_game_data(mainPlayer.username); 
        
        return; // Keluar dari login_system, lanjut ke main game
    } 
}

void use_equipment() {
    int input_id;
    printf("\n--- EQUIP ITEM (Weapon/Armor) ---\n");
    printf("Masukkan ID Item untuk dilengkapi: ");
    
    // Membaca input ID
    if (scanf("%d", &input_id) != 1) {
        printf("Input tidak valid. Harap masukkan angka.\n");
        while (getchar() != '\n'); 
        return;
    }
    while (getchar() != '\n'); // Membersihkan buffer

    struct Item item_pilihan = get_item_by_id(input_id);

    if (item_pilihan.itemID == 0) {
        printf("Item dengan ID %d tidak ditemukan.\n", input_id);
        return;
    }

     int qty_in_bag = is_item_in_inventory(input_id);

    if (qty_in_bag <= 0) {
        printf("ERROR: Anda tidak memiliki item %s (ID %d) di tas Anda.\n", 
               item_pilihan.nama, input_id);
        return;
    }

    // LOGIKA KHUSUS UNTUK WEAPON
    if (strcmp(item_pilihan.type, "WEAPON") == 0) {
        
        // Cek Weapon lama dan lepaskan stat-nya
        if (mainPlayer.equipped_weapon_id != 0) {
            struct Item old_weapon = get_item_by_id(mainPlayer.equipped_weapon_id);
            mainPlayer.bonus_atk -= old_weapon.stat_boost;
            printf("Weapon lama (%s) dilepas.\n", old_weapon.nama);
        }

        // Equip Weapon baru
        mainPlayer.equipped_weapon_id = item_pilihan.itemID;
        mainPlayer.bonus_atk += item_pilihan.stat_boost;
        apply_stat_boosts(); 

        printf("Berhasil melengkapi %s! Bonus ATK: +%d.\n", 
               item_pilihan.nama, item_pilihan.stat_boost);
        printf("ATK total Anda sekarang: %d.\n", mainPlayer.ATK);

    } 
    // LOGIKA LAIN (ARMOR, dll.)
    else if (strcmp(item_pilihan.type, "ARMOR") == 0) {
        
        // 1. Lepaskan Armor lama
        if (mainPlayer.equipped_armor_id != 0) {
            struct Item old_armor = get_item_by_id(mainPlayer.equipped_armor_id);
            mainPlayer.bonus_def -= old_armor.stat_boost;
            printf("Armor lama (%s) dilepas. DEF -%d.\n", old_armor.nama, old_armor.stat_boost);
        }

        // 2. Equip Armor baru
        mainPlayer.equipped_armor_id = item_pilihan.itemID;
        mainPlayer.bonus_def += item_pilihan.stat_boost;
        
        // 3. Perbarui stat DEF total Player (Asumsi DEF Dasar = 0)
        mainPlayer.DEF = mainPlayer.bonus_def; // DEF = Bonus dari Armor

        printf("Berhasil melengkapi %s! Bonus DEF: +%d.\n", 
               item_pilihan.nama, item_pilihan.stat_boost);
        printf("DEF total Anda sekarang: %d.\n", mainPlayer.DEF);

    } 

    else if (strcmp(item_pilihan.type, "CONSUMABLE") == 0) {
         printf("Gunakan item Consumable di Inventory (Belum diimplementasikan).\n");
    }
    else {
        printf("%s tidak dapat dilengkapi.\n", item_pilihan.nama);
    }
}

struct Skill get_skill_by_id(int id);

void change_skill() {
    int active_slot; 
    int skill_id_baru;

    printf("\n--- GANTI SKILL AKTIF ---\n");
    printf("Skill Aktif Saat Ini:\n");

    // Tampilkan skill aktif saat ini (menggunakan index dari array owned_skill_ids)
    struct Skill skill_1 = get_skill_by_id(mainPlayer.owned_skill_ids[mainPlayer.active_skill_1_index]);
    struct Skill skill_2 = get_skill_by_id(mainPlayer.owned_skill_ids[mainPlayer.active_skill_2_index]);
    
    printf("1. Slot 1: %s (CD: %d)\n", skill_1.nama, skill_1.cooldown_max);
    printf("2. Slot 2: %s (CD: %d)\n", skill_2.nama, skill_2.cooldown_max);
    printf("--------------------------------\n");
    
    printf("Skill yang Anda Miliki:\n");
    for (int i = 0; i < mainPlayer.owned_skill_count; i++) {
        struct Skill s = get_skill_by_id(mainPlayer.owned_skill_ids[i]);
        printf("ID: %d | %s (Rarity: %d, Efek: %d, CD: %d)\n", 
               s.skillID, s.nama, s.rarity, s.effect_value, s.cooldown_max);
    }
    printf("--------------------------------\n");

    printf("Pilih Slot Aktif yang ingin diganti (1 atau 2): ");
    if (scanf("%d", &active_slot) != 1) {
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    if (active_slot != 1 && active_slot != 2) {
        printf("ERROR: Slot aktif harus 1 atau 2.\n");
        return;
    }

    printf("Masukkan ID Skill BARU dari daftar skill yang dimiliki: ");
    if (scanf("%d", &skill_id_baru) != 1) {
        // ... (pembersihan input)
        return;
    }
    
    // ==========================================================
    // VALIDASI: Cek apakah skillID baru dimiliki pemain
    // ==========================================================
    int skill_index_in_owned = -1;
    for (int i = 0; i < mainPlayer.owned_skill_count; i++) {
        if (mainPlayer.owned_skill_ids[i] == skill_id_baru) {
            skill_index_in_owned = i;
            break;
        }
    }
    
    if (skill_index_in_owned == -1) {
        printf("ERROR: Skill ID %d tidak ditemukan di skill yang Anda miliki.\n", skill_id_baru);
        return;
    }
    
    // ==========================================================
    // VALIDASI: Cek apakah skillID sudah aktif di slot lain
    // ==========================================================
    if ((active_slot == 1 && skill_id_baru == mainPlayer.owned_skill_ids[mainPlayer.active_skill_2_index]) ||
        (active_slot == 2 && skill_id_baru == mainPlayer.owned_skill_ids[mainPlayer.active_skill_1_index])) {
        printf("ERROR: Skill %s sudah aktif di slot lain.\n", get_skill_by_id(skill_id_baru).nama);
        return;
    }

    // Lakukan penggantian skill
    struct Skill skill_baru = get_skill_by_id(skill_id_baru);
    
    if (active_slot == 1) {
        mainPlayer.active_skill_1_index = skill_index_in_owned;
        mainPlayer.skill_1_cd = 0; // Reset CD saat diganti
    } else {
        mainPlayer.active_skill_2_index = skill_index_in_owned;
        mainPlayer.skill_2_cd = 0; // Reset CD saat diganti
    }

    printf("\nSUKSES: Slot %d berhasil diganti menjadi %s.\n", active_slot, skill_baru.nama);
}

void bag(){
    printf("\n--- BAG & STATS ---\n");
    printf("Username: %s\n", mainPlayer.username);
    printf("Level: %d | XP: %d\n", mainPlayer.LEVEL, mainPlayer.XP);
    printf("HP: %d | ATK: %d | DEF: %d | GOLD: %d\n", mainPlayer.HP, mainPlayer.ATK, mainPlayer.DEF, mainPlayer.GOLD);
    
    // Tampilkan Equipment
    struct Item weapon = get_item_by_id(mainPlayer.equipped_weapon_id);
    printf("Weapon: %s (Bonus ATK: %d)\n", weapon.nama, mainPlayer.bonus_atk);
    
    printf("\n--- INVENTORY ---\n");
    if (mainPlayer.inventory_count == 0) {
        printf("Tas kosong.\n");
        return;
    }

    for (int i = 0; i < mainPlayer.inventory_count; i++) {
        int item_id = mainPlayer.inventory[i].itemID;
        int qty = mainPlayer.inventory[i].quantity;
        
        // Dapatkan detail Item dari daftarItem global
        struct Item item_detail = get_item_by_id(item_id); 
        
        printf("[%d] ID %d | Nama: %s (x%d) | Tipe: %s\n", 
               i + 1, item_id, item_detail.nama, qty, item_detail.type);
    }
}

void tambahkan_item_ke_bag(int item_id_baru, int jumlah) {
    // 1. Cek apakah item sudah ada di Inventory
    struct Item item = get_item_by_id(item_id_baru);
    for (int i = 0; i < mainPlayer.inventory_count; i++) {
        // PERBAIKAN: Menggunakan mainPlayer.inventory
        if (mainPlayer.inventory[i].itemID == item_id_baru) {
            mainPlayer.inventory[i].quantity += jumlah;
            printf("\n%s bertambah menjadi %d.\n", item.nama, mainPlayer.inventory[i].quantity);
            return;
        }
    }

    // 2. Jika item belum ada, cari slot kosong
    if (mainPlayer.inventory_count < MAX_INVENTORY_SLOTS) {
        int new_index = mainPlayer.inventory_count;
        // PERBAIKAN: Menggunakan mainPlayer.inventory
        mainPlayer.inventory[new_index].itemID = item_id_baru;
        mainPlayer.inventory[new_index].quantity = jumlah;
        mainPlayer.inventory_count++; // Tingkatkan jumlah slot terisi
        
        struct Item item = get_item_by_id(item_id_baru);
        printf("\nItem baru ditemukan: %s x%d!\n", item.nama, jumlah);
    } else {
        printf("\nTas penuh! Item tidak bisa diambil.\n");
    }
}

void learn_new_skill(int skill_id) {
    // 1. Cek apakah skill sudah dimiliki
    for (int i = 0; i < mainPlayer.owned_skill_count; i++) {
        if (mainPlayer.owned_skill_ids[i] == skill_id) {
            printf("\nAnda sudah memiliki skill %s.\n", get_skill_by_id(skill_id).nama);
            return;
        }
    }

    // 2. Tambahkan skill ke slot yang tersedia
    if (mainPlayer.owned_skill_count < MAX_SKILLS_OWNED) {
        mainPlayer.owned_skill_ids[mainPlayer.owned_skill_count] = skill_id;
        mainPlayer.owned_skill_count++;
        
        struct Skill s = get_skill_by_id(skill_id);
        printf("\n*** Selamat! Anda mempelajari skill baru: %s (Rarity %d) ***\n", s.nama, s.rarity);
    } else {
        printf("\nSkill pouch penuh! Skill baru tidak dapat dipelajari.\n");
    }
}

struct Chest get_chest_by_id(int id);
void remove_item_from_bag(int itemID, int quantity) {
    // 1. Cari Item dalam Inventory
    for (int i = 0; i < mainPlayer.inventory_count; i++) {
        if (mainPlayer.inventory[i].itemID == itemID) {
            
            // 2. Cek apakah kuantitas cukup
            if (mainPlayer.inventory[i].quantity >= quantity) {
                mainPlayer.inventory[i].quantity -= quantity;
                printf("[Sistem]: Mengurangi %s sebanyak %d.\n", 
                       get_item_by_id(itemID).nama, quantity);
                
                // 3. Logika Penghapusan Slot jika kuantitas menjadi nol
                if (mainPlayer.inventory[i].quantity == 0) {
                    printf("[Sistem]: Item %s habis dan dihapus dari tas.\n", get_item_by_id(itemID).nama);
                    
                    for (int j = i; j < mainPlayer.inventory_count - 1; j++) {
                        mainPlayer.inventory[j] = mainPlayer.inventory[j + 1];
                    }
                    mainPlayer.inventory_count--;
                }
                return;
            } else {
                printf("ERROR: Kuantitas %s tidak cukup.\n", get_item_by_id(itemID).nama);
                return;
            }
        }
    }
    printf("ERROR: Item ID %d tidak ditemukan di tas.\n", itemID);
}

// Fungsi pembantu untuk mencari data Chest

struct Chest get_chest_by_id(int id) {
    // Akses global
    for (int i = 0; i < JUMLAH_CHEST; i++) { 
        if (daftarChest[i].chestID == id) {  
            return daftarChest[i];
        }
    }
    struct Chest empty = {0}; 
    return empty;
}

void open_chest(int chest_item_id) {
    
    struct Item chest_item = get_item_by_id(chest_item_id);
    if (strcmp(chest_item.type, "CHEST") != 0) return;

    struct Chest chest_data = get_chest_by_id(chest_item.stat_boost); // Dapatkan data Chest
    
    if (chest_data.chestID == 0) {
        printf("ERROR: Data peti tidak valid.\n");
        return;
    }

    // 1. Kurangi Chest dari Inventory (Asumsi Player punya item Chest/Kunci ini)
    remove_item_from_bag(chest_item_id, 1);
    
    printf("\n--- MEMBUKA %s ---\n", chest_data.nama);
    
    // 2. Tentukan Item Drop Acak
    if (chest_data.drop_count > 0) {
        
        // Pilih indeks acak dalam batas drop_count (0 hingga drop_count - 1)
        int random_drop_index = rand() % chest_data.drop_count;
        
        // Ambil Item ID yang dipilih dari array Chest
        int dropped_item_id = chest_data.drop_item_ids[random_drop_index];
        
        // Dapatkan struct Item yang dijatuhkan
        struct Item dropped_item_data = get_item_by_id(dropped_item_id);
        
        // 3. Tambahkan item yang dijatuhkan ke Inventory Player
        tambahkan_item_ke_bag(dropped_item_id, 1);
        
        printf("  [Drop]: Anda mendapatkan %s (Rarity %d)!\n", 
               dropped_item_data.nama, dropped_item_data.rarity);
    } else {
        printf("Peti ini kosong!\n");
    }

    save_game_data(); 
}

// Tambahkan kode ini di dalam file: src/player_manager.c

void open_chest_menu() {
    printf("\n--- BUKA PETI ---\n");
    printf("Pilih peti dari inventory Anda untuk dibuka.\n");

    // 1. Cek dan tampilkan item tipe CHEST yang dimiliki pemain
    int chest_count = 0;
    printf("Peti yang Anda miliki:\n");
    for (int i = 0; i < mainPlayer.inventory_count; i++) {
        // Dapatkan detail item dari ID yang ada di tas
        struct Item item_di_tas = get_item_by_id(mainPlayer.inventory[i].itemID);
        // Cek apakah tipenya "CHEST"
        if (strcmp(item_di_tas.type, "CHEST") == 0) {
            printf("  ID: %d | %s (Jumlah: %d)\n",
                   item_di_tas.itemID, item_di_tas.nama, mainPlayer.inventory[i].quantity);
            chest_count++;
        }
    }

    // 2. Jika tidak ada peti sama sekali, keluar dari fungsi
    if (chest_count == 0) {
        printf("Anda tidak memiliki kunci atau peti untuk dibuka.\n");
        return;
    }

    // 3. Minta input dari pemain
    int input_id;
    printf("\nMasukkan ID Peti/Kunci yang ingin digunakan (atau 0 untuk batal): ");
    if (scanf("%d", &input_id) != 1) {
        printf("Input tidak valid. Harap masukkan angka.\n");
        while (getchar() != '\n'); // Bersihkan buffer input jika input bukan angka
        return;
    }
    while (getchar() != '\n'); // Selalu bersihkan sisa buffer setelah scanf

    if (input_id == 0) {
        printf("Membatalkan membuka peti.\n");
        return;
    }

    // 4. Validasi input dan panggil fungsi open_chest
    if (is_item_in_inventory(input_id) > 0) {
        struct Item item_pilihan = get_item_by_id(input_id);
        if (strcmp(item_pilihan.type, "CHEST") == 0) {
            // Panggil fungsi open_chest yang sudah ada dengan ID pilihan pemain
            open_chest(input_id);
        } else {
            printf("ERROR: Item dengan ID %d bukan merupakan peti atau kunci.\n", input_id);
        }
    } else {
        printf("ERROR: Anda tidak memiliki item dengan ID %d di tas Anda.\n", input_id);
    }
}

// File: player_manager.c (Tambahkan di bagian bawah)

// Fungsi pembantu untuk mencari data SkillBook berdasarkan ID-nya
struct SkillBook get_skillbook_by_id(int id) {
    for (int i = 0; i < JUMLAH_SKILLBOOK; i++) {
        if (daftarSkillBook[i].bookID == id) {
            return daftarSkillBook[i];
        }
    }
    struct SkillBook empty = {0};
    return empty;
}

// Fungsi inti untuk memproses pembelajaran skill dari buku
void learn_from_book(int book_item_id) {
    struct Item book_item = get_item_by_id(book_item_id);
    if (strcmp(book_item.type, "BOOK") != 0) return; // Keamanan

    // Ambil data buku dari stat_boost item
    struct SkillBook book_data = get_skillbook_by_id(book_item.stat_boost);

    if (book_data.bookID == 0) {
        printf("ERROR: Data buku tidak valid.\n");
        return;
    }

    // 1. Kurangi buku dari inventory
    remove_item_from_bag(book_item_id, 1);

    printf("\n--- Membaca %s ---\n", book_data.nama);

    // 2. Tentukan Skill Drop secara acak
    if (book_data.drop_count > 0) {
        int random_drop_index = rand() % book_data.drop_count;
        int dropped_skill_id = book_data.drop_skill_ids[random_drop_index];

        // 3. Panggil fungsi learn_new_skill yang sudah ada
        learn_new_skill(dropped_skill_id);

    } else {
        printf("Buku ini ternyata kosong dan tidak berisi apa-apa!\n");
    }

    save_game_data();
}

// Fungsi menu interaktif untuk pemain
void learn_skill_menu() {
    printf("\n--- BELAJAR DARI BUKU ---\n");
    printf("Pilih buku dari inventory Anda untuk dipelajari.\n");

    int book_count = 0;
    printf("Buku yang Anda miliki:\n");
    for (int i = 0; i < mainPlayer.inventory_count; i++) {
        struct Item item_di_tas = get_item_by_id(mainPlayer.inventory[i].itemID);
        if (strcmp(item_di_tas.type, "BOOK") == 0) {
            printf("  ID: %d | %s (Jumlah: %d)\n",
                   item_di_tas.itemID, item_di_tas.nama, mainPlayer.inventory[i].quantity);
            book_count++;
        }
    }

    if (book_count == 0) {
        printf("Anda tidak memiliki buku untuk dipelajari.\n");
        return;
    }

    int input_id;
    printf("\nMasukkan ID Buku yang ingin digunakan (atau 0 untuk batal): ");
    if (scanf("%d", &input_id) != 1) {
        printf("Input tidak valid.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    if (input_id == 0) {
        printf("Batal mempelajari buku.\n");
        return;
    }

    if (is_item_in_inventory(input_id) > 0) {
        struct Item item_pilihan = get_item_by_id(input_id);
        if (strcmp(item_pilihan.type, "BOOK") == 0) {
            learn_from_book(input_id);
        } else {
            printf("ERROR: Item dengan ID %d bukan sebuah buku.\n", input_id);
        }
    } else {
        printf("ERROR: Anda tidak memiliki item dengan ID %d di tas Anda.\n", input_id);
    }
}