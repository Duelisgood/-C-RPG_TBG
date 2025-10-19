// File: src/enchanter.c (Ganti seluruh isinya dengan ini)
#include <stdio.h>
#include <string.h>

#include "enchanter.h"
#include "player_manager.h"
#include "utilities.h"
#include "data/item_data.h"
#define MAX_INPUT 50

// --- FUNGSI-FUNGSI ENCHANTER ---

void enchant_weapon_menu() {
    // 1. Cek apakah ada senjata yang sedang dipakai menggunakan indeks slot
    if (mainPlayer.equipped_weapon_slot_index == -1) {
        printf("Anda harus memakai sebuah senjata untuk bisa memperkuatnya.\n");
        return;
    }

    // 2. Dapatkan data dari slot inventaris yang sedang dipakai
    int slot_index = mainPlayer.equipped_weapon_slot_index;
    // Gunakan pointer agar kita bisa mengubah nilai enchant_level secara langsung
    struct InventorySlot* weapon_slot = &mainPlayer.inventory[slot_index];
    struct Item weapon_data = get_item_by_id(weapon_slot->itemID);
    
    int current_level = weapon_slot->enchant_level;

    printf("\n--- Perkuat Senjata ---\n");
    printf("Senjata Saat Ini: %s\n", weapon_data.nama);
    printf("Level             : +%d\n", current_level);

    // 3. Cek apakah sudah mencapai level maksimal
    if (current_level >= 3) {
        printf("Senjata ini sudah mencapai level perkuatan maksimal!\n");
        return;
    }

    // 4. Hitung biaya dan bonus untuk level selanjutnya
    int base_cost = weapon_data.rarity * 100;
    int enchant_cost = base_cost * (current_level + 1);
    int bonus_damage = weapon_data.rarity;

    printf("Bonus Selanjutnya   : +%d ATK\n", bonus_damage);
    printf("Biaya Perkuatan   : %d Gold\n", enchant_cost);
    printf("---------------------------\n");
    printf("Emas Anda         : %d Gold\n", mainPlayer.GOLD);

    // 5. Validasi Gold pemain
    if (mainPlayer.GOLD < enchant_cost) {
        printf("Emas Anda tidak cukup.\n");
        return;
    }

    // 6. Minta konfirmasi dari pemain
    printf("Perkuat senjata ini? [Y/N]: ");
    char confirm[10];
    bacaInput(confirm);

    if (strcmp(confirm, "Y") == 0) {
        // 7. Lakukan proses enchant
        mainPlayer.GOLD -= enchant_cost;
        weapon_slot->enchant_level++; // Tingkatkan level enchant pada item di inventaris

        // 8. Hitung ulang semua stat dan simpan permainan
        recalculate_all_bonuses();
        apply_stat_boosts();

        printf("Sukses! %s berhasil diperkuat ke level +%d!\n", weapon_data.nama, weapon_slot->enchant_level);
        printf("ATK Anda sekarang: %d\n", mainPlayer.ATK);
        save_game_data();
    } else {
        printf("Batal memperkuat senjata.\n");
    }
}

// --- FUNGSI BARU UNTUK ARMOR ---
void enchant_armor_menu() {
    // 1. Cek apakah ada armor yang sedang dipakai
    if (mainPlayer.equipped_armor_slot_index == -1) {
        printf("Anda harus memakai sebuah armor untuk bisa memperkuatnya.\n");
        return;
    }

    // 2. Dapatkan data dari slot inventaris yang sedang dipakai
    int slot_index = mainPlayer.equipped_armor_slot_index;
    struct InventorySlot* armor_slot = &mainPlayer.inventory[slot_index];
    struct Item armor_data = get_item_by_id(armor_slot->itemID);
    
    int current_level = armor_slot->enchant_level;

    printf("\n--- Perkuat Armor ---\n");
    printf("Armor Saat Ini  : %s\n", armor_data.nama);
    printf("Level           : +%d\n", current_level);

    // 3. Cek apakah sudah mencapai level maksimal
    if (current_level >= 3) {
        printf("Armor ini sudah mencapai level perkuatan maksimal!\n");
        return;
    }

    // 4. Hitung biaya dan bonus untuk level selanjutnya
    int base_cost = armor_data.rarity * 100;
    int enchant_cost = base_cost * (current_level + 1);
    int bonus_defense = armor_data.rarity;

    printf("Bonus Selanjutnya : +%d DEF\n", bonus_defense);
    printf("Biaya Perkuatan : %d Gold\n", enchant_cost);
    printf("---------------------------\n");
    printf("Emas Anda       : %d Gold\n", mainPlayer.GOLD);

    // 5. Validasi Gold pemain
    if (mainPlayer.GOLD < enchant_cost) {
        printf("Emas Anda tidak cukup.\n");
        return;
    }

    // 6. Minta konfirmasi dari pemain
    printf("Perkuat armor ini? [Y/N]: ");
    char confirm[10];
    bacaInput(confirm);

    if (strcmp(confirm, "Y") == 0) {
        // 7. Lakukan proses enchant
        mainPlayer.GOLD -= enchant_cost;
        armor_slot->enchant_level++; // Tingkatkan level enchant pada item di inventaris

        // 8. Hitung ulang semua stat dan simpan permainan
        recalculate_all_bonuses();
        apply_stat_boosts();

        printf("Sukses! %s berhasil diperkuat ke level +%d!\n", armor_data.nama, armor_slot->enchant_level);
        printf("DEF Anda sekarang: %d\n", mainPlayer.DEF);
        save_game_data();
    } else {
        printf("Batal memperkuat armor.\n");
    }
}

// --- FUNGSI BARU UNTUK HELMET ---
void enchant_helmet_menu() {
    
    if (mainPlayer.equipped_helmet_slot_index == -1) {
        printf("Anda harus memakai sebuah helmet untuk bisa memperkuatnya.\n");
        return;
    }

    // 2. Dapatkan data dari slot inventaris yang sedang dipakai
    int slot_index = mainPlayer.equipped_helmet_slot_index;
    struct InventorySlot* helmet_slot = &mainPlayer.inventory[slot_index];
    struct Item helmet_data = get_item_by_id(helmet_slot->itemID);
    
    int current_level = helmet_slot->enchant_level;

    printf("\n--- Perkuat Helmet ---\n");
    printf("Helmet Saat Ini : %s\n", helmet_data.nama);
    printf("Level           : +%d\n", current_level);


    if (current_level >= 3) {
        printf("Helmet ini sudah mencapai level perkuatan maksimal!\n");
        return;
    }

    int base_cost = helmet_data.rarity * 100;
    int enchant_cost = base_cost * (current_level + 1);
    int bonus_hp = helmet_data.rarity;

    printf("Bonus Selanjutnya : +%d MAX HP\n", bonus_hp);
    printf("Biaya Perkuatan : %d Gold\n", enchant_cost);
    printf("---------------------------\n");
    printf("Emas Anda       : %d Gold\n", mainPlayer.GOLD);

    if (mainPlayer.GOLD < enchant_cost) {
        printf("Emas Anda tidak cukup.\n");
        return;
    }

    printf("Perkuat helmet ini? [Y/N]: ");
    char confirm[10];
    bacaInput(confirm);

    if (strcmp(confirm, "Y") == 0) {
    
        mainPlayer.GOLD -= enchant_cost;
        helmet_slot->enchant_level++;

        recalculate_all_bonuses();
        apply_stat_boosts();

        printf("Sukses! %s berhasil diperkuat ke level +%d!\n", helmet_data.nama, helmet_slot->enchant_level);
        printf("MAX HP Anda sekarang: %d\n", mainPlayer.MAX_HP);
        save_game_data();
    } else {
        printf("Batal memperkuat helmet.\n");
    }
}

void open_enchanter_menu() {
    char input[MAX_INPUT];
    int at_enchanter = 1;

    while (at_enchanter) {
        printf("\n=== Ahli Tempa ===\n");
        printf("Seorang ahli tempa menyambutmu di samping bara api. 'Ingin membuat equipment-mu lebih kuat?'\n");
        printf("Pilih Opsi: [WEAPON] | [ARMOR] | [HELMET] | [EXIT]\n");
        bacaInput(input);

        if (strcmp(input, "WEAPON") == 0) {
            enchant_weapon_menu();
        } else if (strcmp(input, "ARMOR") == 0) {
            enchant_armor_menu();
        } else if (strcmp(input, "HELMET") == 0) {
            enchant_helmet_menu();
        } else if (strcmp(input, "EXIT") == 0) {
            printf("'Hati-hati di jalan, petualang.'\n");
            at_enchanter = 0;
        } else {
            printf("Perintah tidak dikenal.\n");
        }
    }
}