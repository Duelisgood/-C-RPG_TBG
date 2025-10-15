// File: src/shop.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Diperlukan untuk rand()

#include "shop.h"
#include "player_manager.h"
#include "utilities.h"
#include "data/item_data.h"
#define MAX_INPUT 50
#define MAX_USERNAME 50
// --- [BARU] PENGATURAN TOKO ---
#define SHOP_INVENTORY_SIZE 7 // Jumlah item yang dijual setiap kali toko di-refresh

// --- [BARU] KOLAM ITEM MASTER UNTUK TOKO ---
// Ini adalah daftar SEMUA item yang BISA MUNCUL di toko.
// Kita akan mengambil sampel acak dari daftar ini.
const int master_shop_pool[] = {
    // --- Rarity 1 (Sangat Umum) ---
    101, 120, 160, // Item dasar (Pedang, Rompi, Topi)
    134, 137, 163, // Item dasar lainnya (Gada, Jubah, Tudung)
    150, // Ramuan Penyembuh Kecil
    701, 703, 705, // Kunci Rarity 1
    80, 83,         // Buku Rarity 1

    // --- Rarity 2 (Cukup Umum) ---
    201, 225, 260, // Item standar (Short Sword, Chain Mail, Helm Prajurit)
    232, 238, 264, // Item standar lainnya (Kapak, Zirah Kulit, Helm Infanteri)
    711, 714,      // Kunci Rarity 2
    84, 85,         // Buku Rarity 2

    // --- Rarity 3 (Jarang) ---
    301, 320, 360, // Item kuat (Great Axe, Steel Plate, Helm Ksatria)
    331, 332, 363, // Item kuat lainnya
    350, // Ramuan Penyembuh Sedang
    721, 722,      // Kunci Rarity 3
    81, 86,         // Buku Rarity 3

    // --- Rarity 4 (Sangat Jarang) ---
    401, // Rune Sword
    420, // Mithril Mail
    460, // Helm Mithril
    731,  // Kunci Kristal Ajaib

    // -- Rarity 5
    643
};

const int master_pool_size = sizeof(master_shop_pool) / sizeof(master_shop_pool[0]);


int current_shop_inventory[SHOP_INVENTORY_SIZE];


void refresh_shop_inventory() {
    int selected_count = 0;
    int is_duplicate;

    while (selected_count < SHOP_INVENTORY_SIZE) {
        // 1. Ambil item acak dari master pool
        int random_index = rand() % master_pool_size;
        int candidate_item_id = master_shop_pool[random_index];

        // 2. Cek duplikasi untuk memastikan item yang sama tidak muncul dua kali
        is_duplicate = 0;
        for (int i = 0; i < selected_count; i++) {
            if (current_shop_inventory[i] == candidate_item_id) {
                is_duplicate = 1;
                break;
            }
        }

        // 3. Jika tidak duplikat, tambahkan ke inventaris toko saat ini
        if (!is_duplicate) {
            current_shop_inventory[selected_count] = candidate_item_id;
            selected_count++;
        }
    }
}



void show_buy_menu() {
    printf("\n--- Selamat Datang! Silakan lihat barang kami ---\n");
    printf("Item yang Tersedia Hari Ini:\n");

    // [MODIFIKASI] Loop sekarang melalui inventaris acak saat ini
    for (int i = 0; i < SHOP_INVENTORY_SIZE; i++) {
        struct Item item = get_item_by_id(current_shop_inventory[i]);
        if (item.itemID != 0) {
            printf("  ID: %-5d | Nama: %-30s | Rarity: %d | Harga: %d Gold\n", item.itemID, item.nama, item.rarity, item.harga);
        }
    }
    printf("---------------------------------------------------\n");
    printf("Emas Anda: %d Gold\n", mainPlayer.GOLD);

    int item_id_to_buy;
    printf("Masukkan ID item yang ingin dibeli (atau 0 untuk kembali): ");
    if (scanf("%d", &item_id_to_buy) != 1) {
        printf("Input tidak valid.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    if (item_id_to_buy == 0) return;

    // Validasi apakah item yang dipilih memang dijual saat ini
    int item_is_for_sale = 0;
    for (int i = 0; i < SHOP_INVENTORY_SIZE; i++) {
        if (current_shop_inventory[i] == item_id_to_buy) {
            item_is_for_sale = 1;
            break;
        }
    }

    if (!item_is_for_sale) {
        printf("Item dengan ID tersebut tidak dijual saat ini.\n");
        return;
    }

    struct Item item_to_buy = get_item_by_id(item_id_to_buy);
    if (mainPlayer.GOLD >= item_to_buy.harga) {
        mainPlayer.GOLD -= item_to_buy.harga;
        tambahkan_item_ke_bag(item_to_buy.itemID, 1);
        printf("Berhasil membeli %s seharga %d Gold.\n", item_to_buy.nama, item_to_buy.harga);
        save_game_data();
    } else {
        printf("Emas tidak cukup untuk membeli %s.\n", item_to_buy.nama);
    }
}

void show_sell_menu() {
    printf("\n--- Apa yang ingin Anda jual? ---\n");
    if (mainPlayer.inventory_count == 0) {
        printf("Tas Anda kosong.\n");
        return;
    }

    printf("Item di Tas Anda:\n");
    for (int i = 0; i < mainPlayer.inventory_count; i++) {
        struct Item item = get_item_by_id(mainPlayer.inventory[i].itemID);
        int sell_price = item.harga * 0.4;
        if (sell_price < 1) sell_price = 1;
        
        printf("  ID: %-5d | Nama: %-30s | Jual: %d Gold (x%d)\n", 
               item.itemID, item.nama, sell_price, mainPlayer.inventory[i].quantity);
    }
    printf("---------------------------------------------------\n");
    printf("Emas Anda: %d Gold\n", mainPlayer.GOLD);

    int item_id_to_sell;
    printf("Masukkan ID item yang ingin dijual (atau 0 untuk kembali): ");
    if (scanf("%d", &item_id_to_sell) != 1) {
        printf("Input tidak valid.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    if (item_id_to_sell == 0) return;

    if (is_item_in_inventory(item_id_to_sell) > 0) {
        struct Item item_to_sell = get_item_by_id(item_id_to_sell);
        int sell_price = item_to_sell.harga * 0.4;
        if (sell_price < 1) sell_price = 1;

        mainPlayer.GOLD += sell_price;
        remove_item_from_bag(item_to_sell.itemID, 1);
        printf("Berhasil menjual %s dan mendapatkan %d Gold.\n", item_to_sell.nama, sell_price);
        save_game_data();
    } else {
        printf("Anda tidak memiliki item dengan ID tersebut.\n");
    }
}

// --- FUNGSI UTAMA TOKO (DIMODIFIKASI) ---
void open_shop_menu() {
    // [MODIFIKASI] Panggil fungsi refresh setiap kali toko dibuka!
    refresh_shop_inventory();
    printf("Anda memasuki toko. Barang dagangan hari ini terlihat segar...\n");

    char input[MAX_INPUT];
    int in_shop = 1;

    while (in_shop) {
        printf("\n=== Toko ===\n");
        printf("Pilih Aksi: [BUY] | [SELL] | [EXIT]\n");
        bacaInput(input);

        if (strcmp(input, "BUY") == 0) {
            show_buy_menu();
        } else if (strcmp(input, "SELL") == 0) {
            show_sell_menu();
        } else if (strcmp(input, "EXIT") == 0) {
            printf("Terima kasih sudah berkunjung!\n");
            in_shop = 0;
        } else {
            printf("Perintah tidak dikenal di toko.\n");
        }
    }
}