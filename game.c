#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>  
#include <time.h>   
#include "game_data.h"
#define MAX_INPUT 50
#define MAX_USERNAME 50

// game.c (Definisi instance Player global)
struct Player mainPlayer = {
    .username = "",
    .HP = 10,
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
    .inventory_count = 0 

};

struct Item get_item_by_id(int id);


//======================================================================================================================================================Game Save

void bersihkanString(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

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
    fprintf(file, "ATK=%d\n", mainPlayer.ATK);
    fprintf(file, "DEF=%d\n", mainPlayer.DEF);
    fprintf(file, "LEVEL=%d\n", mainPlayer.LEVEL);
    fprintf(file, "XP=%d\n", mainPlayer.XP);
    fprintf(file, "GOLD=%d\n", mainPlayer.GOLD);
    fprintf(file, "equipped_armor_id=%d\n", mainPlayer.equipped_armor_id); 
    fprintf(file, "bonus_def=%d\n", mainPlayer.bonus_def);  
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

   char key[20];
    int value;
    char line[100];
    int load_index = 0; // BARU: Indeks untuk mengisi inventory
    
    // Reset inventory sebelum memuat
    mainPlayer.inventory_count = 0; 

    // LOOP TUNGGAL: Membaca file BARIS DEMI BARIS
    while (fgets(line, sizeof(line), file) != NULL) {
        
        bersihkanString(line); // Hapus newline

        // 1. MUAT STAT DASAR (Contoh: HP=10)
        if (strncmp(line, "ITEM=", 5) != 0) { // <--- TAMBAHKAN CHECK INI
    
            if (sscanf(line, "%19[^=]=%d", key, &value) == 2) {
                // ... (Kode muat stat HP, ATK, DEF, LEVEL, XP, GOLD ke mainPlayer.STAT) ...
                
                // TIDAK PERLU else if
                if (strcmp(key, "HP") == 0) mainPlayer.HP = value;
                else if (strcmp(key, "ATK") == 0) mainPlayer.ATK = value;
                else if (strcmp(key, "DEF") == 0) mainPlayer.DEF = value;
                else if (strcmp(key, "LEVEL") == 0) mainPlayer.LEVEL = value;
                else if (strcmp(key, "XP") == 0) mainPlayer.XP = value;
                else if (strcmp(key, "GOLD") == 0) mainPlayer.GOLD = value;
                else if (strcmp(key, "equipped_armor_id") == 0) mainPlayer.equipped_armor_id = value; 
                else if (strcmp(key, "bonus_def") == 0) mainPlayer.bonus_def = value; 
            }
        }
        
        // 2. MUAT DATA BACKPACK (Contoh: ITEM=101,2)
        else if (strncmp(line, "ITEM=", 5) == 0) {
            int id, qty;
            if (sscanf(line, "ITEM=%d,%d", &id, &qty) == 2) {
                if (load_index < MAX_INVENTORY_SLOTS) {
                    // Item dimuat ke array inventory milik struct Player
                    mainPlayer.inventory[load_index].itemID = id;
                    mainPlayer.inventory[load_index].quantity = qty;
                    load_index++; // PENTING: Tingkatkan indeks untuk item berikutnya
                }
            }
        }
    } // Tutup loop utama while (fgets)

    // Tetapkan inventory_count global dari jumlah item yang berhasil dimuat
    mainPlayer.inventory_count = load_index; 
    
    fclose(file);
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
        mainPlayer.HP += 10; // +10 HP
        mainPlayer.ATK += 2; // +2 ATK
        mainPlayer.DEF += 1; // +1 DEF

        printf("\n***********************************\n");
        printf("!!! SELAMAT! Anda naik ke LEVEL %d !!!\n", mainPlayer.LEVEL);
        printf("Stat bertambah: HP +10, ATK +2, DEF +1.\n");
        printf("***********************************\n");
        
        // Hitung ulang EXP yang dibutuhkan untuk level berikutnya
        exp_needed = 100 * mainPlayer.LEVEL;
    }
}

//====================================================================================================================


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



void bacaInput(char *input) {
  
    // Membaca string dari input, maksimal 50 karakter
    if (fgets(input, MAX_INPUT, stdin) != NULL) {
        // Membersihkan karakter newline dari string input
        bersihkanString(input);
    }
}

  //==========================================================================================================================================Fight and Explore>>>>> 
  
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

// Fungsi yang dimodifikasi untuk memilih monster berdasarkan Rarity
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

void lakukan_pertarungan(struct Monster musuh) {

    char input[MAX_INPUT];
    struct Monster *musuh_ptr = &musuh; 

    struct Skill skill1_data = daftarSkill[mainPlayer.active_skill_1_index]; 
    struct Skill skill2_data = daftarSkill[mainPlayer.active_skill_2_index];

    
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

        int turn_taken = 0;

        if (strcmp(input, "ATTACK") == 0) {
            musuh_ptr->healthPoint -= mainPlayer.ATK;
            printf("Anda menyerang %s dan memberikan %d damage!\n", musuh_ptr->nama, mainPlayer.ATK);
            turn_taken = 1;
        } 
        else if (strcmp(input, "SKILL 1") == 0) {
            if (mainPlayer.skill_1_cd > 0) {
                printf("Skill 1 (%s) sedang cooldown (%d turn tersisa).\n", skill1_data.nama, mainPlayer.skill_1_cd);
                continue; // Ulangi giliran Player
            }
            
                if (strcmp(skill1_data.effect_type, "HEAL") == 0) {
                mainPlayer.HP += skill1_data.effect_value;
                } else if (strcmp(skill1_data.effect_type, "ATTACK") == 0) {
                    musuh_ptr->healthPoint -= (mainPlayer.ATK + skill1_data.effect_value);
                }

                printf("Anda menggunakan %s!\n", skill1_data.nama);
                mainPlayer.skill_1_cd = skill1_data.cooldown_max; 
                turn_taken = 1;
            } 

        else if (strcmp(input, "SKILL 2") == 0) {
            if (mainPlayer.skill_2_cd > 0) {
                printf("Skill 2 (%s) sedang cooldown (%d turn tersisa).\n", skill2_data.nama, mainPlayer.skill_2_cd);
                continue; // Ulangi giliran Player
            }
            
             
                if (strcmp(skill2_data.effect_type, "HEAL") == 0) { 
                    mainPlayer.HP += skill2_data.effect_value;
                } else if (strcmp(skill2_data.effect_type, "ATTACK") == 0) { 
                    musuh_ptr->healthPoint -= (mainPlayer.ATK + skill2_data.effect_value);
                }
            
                printf("Anda menggunakan %s!\n", skill2_data.nama);
                mainPlayer.skill_2_cd = skill2_data.cooldown_max; 
                turn_taken = 1; // 
            // -------------------------
        }

         else if (strcmp(input, "KABUR") == 0) {
                printf("Anda berhasil kabur dari %s dan kembali ke menu utama.\n", musuh_ptr->nama);
                return; 
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
            
            check_for_level_up();
            save_game_data(); 

            return; // KELUAR dari lakukan_pertarungan()
        } // <--- PASTIKAN BRACE INI ADA

        // Hanya jika Player mengambil aksi yang valid (turn_taken == 1)
        if (turn_taken) {
            monster_turn(musuh_ptr);
        }

        if (mainPlayer.HP <= 0) {
            printf("\n!!! Anda dikalahkan oleh %s. GAME OVER.\n", musuh_ptr->nama);
            // Tambahkan logika Game Over di sini
            // Sebaiknya panggil save_game_data() di sini jika Anda ingin menyimpan status (HP=0)
            return;
        }
    } // Akhir dari while loop pertarungan
} // Akhir dari fungsi l

int is_item_in_inventory(int itemID) {
    for (int i = 0; i < mainPlayer.inventory_count; i++) {
        if (mainPlayer.inventory[i].itemID == itemID) {
            return mainPlayer.inventory[i].quantity; // Mengembalikan jumlah item
        }
    }
    return 0; // Item tidak ditemukan
}

// Fungsi untuk menambah Item (Contoh: Item ID 103 = Ramuan Kecil)
void tambahkan_item_ke_bag(int item_id_baru, int jumlah) {
    // 1. Cek apakah item sudah ada di Inventory
    for (int i = 0; i < mainPlayer.inventory_count; i++) {
        // PERBAIKAN: Menggunakan mainPlayer.inventory
        if (mainPlayer.inventory[i].itemID == item_id_baru) {
            mainPlayer.inventory[i].quantity += jumlah;
            struct Item item = get_item_by_id(item_id_baru);
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

void kembali_ke_main() {
    printf("\nAnda berhasil kabur dari pertarungan!\n");
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
        // Item: 61-85 (25%)
        printf("Anda menemukan sebuah item tersembunyi!\n");

        // BARU: 1. Tentukan Rarity item
        int item_rarity = get_random_rarity(); 
        
        // BARU: 2. Dapatkan item yang sesuai Rarity
        struct Item item_ditemukan = get_random_item_by_rarity(item_rarity);
        
        // 3. Tambahkan item ke bag (misal: selalu 1 buah)
        tambahkan_item_ke_bag(item_ditemukan.itemID, 1);
        
        printf("Anda menemukan item Rarity %d: %s.\n", item_rarity, item_ditemukan.nama);
        
        // ----------------------------------------------------
    }  
    else { 
        // Kosong: 86-99 (14%)
        printf("Anda menjelajah, tetapi tidak terjadi apa-apa.\n");
    }
}


//========================================================================================================================================================== inventory backpack>>>>
// game.c


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


//===============================================================================================================================================use item and use skill
void use_skill() {
    int skill_id_baru;
    int skill_slot;
    
    printf("\n--- UBAH SKILL LOADOUT ---\n");
    
    // Tampilkan Daftar Skill Tersedia
    printf("Skill Tersedia (ID | Nama | CD): \n");
    for (int i = 0; i < JUMLAH_SKILL; i++) {
        printf("  ID %d: %s (CD: %d)\n", 
               daftarSkill[i].skillID, daftarSkill[i].nama, daftarSkill[i].cooldown_max);
    }

    // Input Slot
    printf("Pilih Slot (1 atau 2) yang ingin diubah: ");
    if (scanf("%d", &skill_slot) != 1 || (skill_slot != 1 && skill_slot != 2)) {
        printf("Input slot tidak valid.\n");
        
        // GUNAKAN KURUNG KURAWAL untuk logika pembersihan dan return:
        while (getchar() != '\n'); 
        return; 
    }
    // HANYA pembersihan buffer setelah input yang berhasil:
    while (getchar() != '\n');

    // Input ID Skill Baru (Contoh perbaikan di sekitar baris 333)
    printf("Masukkan ID Skill baru yang akan dipasang: ");
    if (scanf("%d", &skill_id_baru) != 1) {
        printf("Input ID skill tidak valid.\n");
        
        // GUNAKAN KURUNG KURAWAL untuk logika pembersihan dan return:
        while (getchar() != '\n'); 
        return; 
    }
    // HANYA pembersihan buffer setelah input yang berhasil:
    while (getchar() != '\n');  // Membersihkan buffer

    // Cari Indeks Skill berdasarkan ID yang dimasukkan user
    int skill_index = -1;
    for (int i = 0; i < JUMLAH_SKILL; i++) {
        if (daftarSkill[i].skillID == skill_id_baru) {
            skill_index = i;
            break;
        }
    }

    if (skill_index == -1) {
        printf("Skill dengan ID %d tidak ditemukan.\n", skill_id_baru);
        return;
    }
    
    // Terapkan Perubahan
    if (skill_slot == 1) {
        mainPlayer.active_skill_1_index = skill_index;
        printf("Slot 1 berhasil diubah menjadi: %s\n", daftarSkill[skill_index].nama);
    } else { // skill_slot == 2
       mainPlayer.active_skill_2_index = skill_index;
        printf("Slot 2 berhasil diubah menjadi: %s\n", daftarSkill[skill_index].nama);
    }
    
    // Reset Cooldown skill yang baru dipasang
    if (skill_slot == 1) mainPlayer.skill_1_cd = 0;
    if (skill_slot == 2) mainPlayer.skill_2_cd = 0;
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

void apply_stat_boosts() {
    // Fungsi untuk memperbarui stat total Player
    // Dalam game yang kompleks, ini akan dipanggil setelah equip/unequip

    // Reset ATK dasar
    mainPlayer.ATK = 2; // Asumsi ATK dasar Player adalah 2

    // Tambahkan BONUS_ATK
    mainPlayer.ATK += mainPlayer.bonus_atk;
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

//==================================================================================================================================================LOGIN System
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
        mainPlayer.ATK = 2; 
        // ... (Set stat dasar lainnya) ...
        
        // --- INISIALISASI INVENTORY ---
        tambahkan_item_ke_bag(101, 1); 
        tambahkan_item_ke_bag(103, 5); 
        // -----------------------------

        strcpy(mainPlayer.username, username);
        save_game_data(); 
        
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

//====================================================================================================================================Game Start>>>
void help(){
    printf("\n--- DAFTAR PERINTAH ---\n");
    printf("EXPLORE\n");
    printf("BAG\n");
    printf("USE_EQUIPMENT\n");
    printf("USE_SKILL\n");
    printf("QUIT\n");
    printf("HELP\n"); // Jangan lupa tambahkan 'help' itu sendiri!
    printf("------------------------\n");
}

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
        else if (strcmp(aksiPengguna, "USE_SKILL") == 0) {
            use_skill(); 
        }  
        else if (strcmp(aksiPengguna, "EXPLORE") == 0) {
            explore(); 
        } 
        else if (strcmp(aksiPengguna, "QUIT") == 0 || strcmp(aksiPengguna, "quit") == 0) {
            save_game_data(); // Simpan data sebelum keluar
            printf("Menyimpan dan keluar. Sampai jumpa!\n");
            return; // Keluar dari main_loop
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