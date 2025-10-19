// File: src/quest.c
#include <stdio.h>
#include <string.h>

#include "quest.h"
#include "player_manager.h"
#include "utilities.h"
#include "data/monster_data.h"
#include "combat.h" // Diperlukan untuk start_fight

// Struktur internal untuk menyimpan info tantangan quest
typedef struct {
    int monster_id;
    int min_level;
    char* lore_intro;
    int is_main_boss; // 0 = sub, 1 = main
} QuestChallenge;

// Fungsi helper untuk mendapatkan data tantangan berdasarkan stage
QuestChallenge get_challenge_data(int stage) {
    QuestChallenge challenge = {0, 0, "", 0};
    switch (stage) {
        // --- Rarity 1 ---
        case 0: challenge = (QuestChallenge){6001, 1, "Goblin pertama yang terpengaruh energi gelap menghalangi jalan.", 0}; break;
        case 1: challenge = (QuestChallenge){6002, 1, "Gerombolan goblin ini tampaknya menjaga jalan masuk.", 0}; break;
        case 2: challenge = (QuestChallenge){6003, 1, "Aura gelap terasa lebih kuat di depan.", 0}; break;
        case 3: challenge = (QuestChallenge){6004, 1, "Satu lagi penjaga sebelum pemimpin mereka.", 0}; break;
        case 4: challenge = (QuestChallenge){6010, 1, "Di depanmu berdiri Grak, matanya bersinar karena kekuatan aneh.", 1}; break;
        
        // --- Rarity 2 ---
        case 5: challenge = (QuestChallenge){6011, 5, "Kerangka pertama bangkit menjaga area pemakaman tua.", 0}; break;
        case 6: challenge = (QuestChallenge){6012, 5, "Semakin banyak kerangka terpengaruh energi gelap.", 0}; break;
        case 7: challenge = (QuestChallenge){6013, 5, "Penjaga makam ini semakin kuat.", 0}; break;
        case 8: challenge = (QuestChallenge){6014, 5, "Hanya satu lagi sebelum penjaga utama.", 0}; break;
        case 9: challenge = (QuestChallenge){6020, 5, "Di tengah ruangan makam, Kapten Krek bangkit.", 1}; break;
        
        // --- Rarity 3 ---
        case 10: challenge = (QuestChallenge){6021, 10, "Konstruk batu kuno aktif dan menghalangi jalan.", 0}; break;
        case 11: challenge = (QuestChallenge){6022, 10, "Konstruk penjaga berikutnya menghadangmu.", 0}; break;
        case 12: challenge = (QuestChallenge){6023, 10, "Pertahanan kuno ini tampaknya tak ada habisnya.", 0}; break;
        case 13: challenge = (QuestChallenge){6024, 10, "Inti energi dari konstruksi ini semakin dekat.", 0}; break;
        case 14: challenge = (QuestChallenge){6030, 10, "Sebuah Golem Obsidian raksasa menghalangi jembatan.", 1}; break;
        
        // --- Rarity 4 ---
        case 15: challenge = (QuestChallenge){6031, 15, "Jejak bayangan muncul dari retakan di dinding.", 0}; break;
        case 16: challenge = (QuestChallenge){6032, 15, "Figur kelam menatapmu dari kegelapan.", 0}; break;
        case 17: challenge = (QuestChallenge){6033, 15, "Penampakan mengerikan mencoba menghentikan langkahmu.", 0}; break;
        case 18: challenge = (QuestChallenge){6034, 15, "Pelayan kegelapan terakhir sebelum sang utusan.", 0}; break;
        case 19: challenge = (QuestChallenge){6040, 15, "Sosok berjubah gelap muncul, memancarkan aura dingin.", 1}; break;
        
        // --- Rarity 5 ---
        case 20: challenge = (QuestChallenge){6041, 20, "Imp api neraka keluar dari retakan yang semakin besar.", 0}; break;
        case 21: challenge = (QuestChallenge){6042, 20, "Prajurit iblis brutal meraung menantangmu.", 0}; break;
        case 22: challenge = (QuestChallenge){6043, 20, "Penyihir iblis melancarkan sihir gelap ke arahmu.", 0}; break;
        case 23: challenge = (QuestChallenge){6044, 20, "Jenderal iblis, penjaga terakhir Malakor, berdiri di depanmu.", 0}; break;
        case 24: challenge = (QuestChallenge){6050, 20, "Dari dalam retakan, Archdemon Malakor muncul!", 1}; break;

        // --- Akhir Quest ---
        default: challenge = (QuestChallenge){0, 0, "Anda telah menyelesaikan semua tantangan!", 0}; break;
    }
    return challenge;
}

// Fungsi untuk menampilkan status quest saat ini
void show_world_quest_status() {
    printf("\n--- World Quest: Ancaman dari Retakan Bayangan ---\n");
    QuestChallenge current_challenge = get_challenge_data(mainPlayer.world_quest_stage);

    // Tampilkan lore berdasarkan stage
    switch (mainPlayer.world_quest_stage) {
        // --- Tahap 1 ---
        case 0: printf("Energi aneh merembes dari kedalaman... Monster menjadi lebih ganas.\n"); break;
        case 1: printf("Goblin pertama kalah, tapi energi gelap masih terasa kuat.\n"); break;
        case 2: printf("Jalan masuk gua goblin terbuka, aura gelap menguat.\n"); break;
        case 3: printf("Kau semakin dekat dengan pemimpin para goblin.\n"); break;
        case 4: printf("Para penjaga telah kalah, hanya pemimpin mereka yang tersisa.\n"); break;
        
        // --- Tahap 2 ---
        case 5: printf("Grak kalah! Jalan terbuka, tapi energi gelap masih kuat dari kedalaman.\n"); break;
        case 6: printf("Kerangka pertama tumbang, area pemakaman di depan mata.\n"); break;
        case 7: printf("Para penjaga makam ini lebih kuat dari kerangka biasa.\n"); break;
        case 8: printf("Kau merasakan kehadiran kuat dari pusat pemakaman.\n"); break;
        case 9: printf("Hanya letnan kerangka yang tersisa sebelum sang kapten.\n"); break;

        // --- Tahap 3 ---
        case 10: printf("Kapten Krek kembali beristirahat. Catatan menunjuk ke konstruksi kuno di bawah.\n"); break;
        case 11: printf("Konstruk batu pertama hancur, namun masih banyak lagi di depan.\n"); break;
        case 12: printf("Lorong-lorong kuno ini dilindungi dengan baik.\n"); break;
        case 13: printf("Kau merasakan getaran dari konstruksi yang lebih besar.\n"); break;
        case 14: printf("Para konstruksi kecil telah dibersihkan, penjaga utama menanti.\n"); break;

        // --- Tahap 4 ---
        case 15: printf("Golem hancur. Kau merasakan kehadiran cerdas dan jahat dari sisi lain jembatan.\n"); break;
        case 16: printf("Makhluk bayangan ini cepat dan sulit dilawan.\n"); break;
        case 17: printf("Aura dari retakan dimensi terasa semakin nyata.\n"); break;
        case 18: printf("Kau hampir mencapai sumber dari para pelayan kegelapan ini.\n"); break;
        case 19: printf("Para pelayan telah lenyap, kini sang utusan sendiri yang muncul.\n"); break;

        // --- Tahap 5 ---
        case 20: printf("Utusan itu lenyap, menggumamkan nama 'Malakor'. Retakan di depanmu berdenyut hebat.\n"); break;
        case 21: printf("Iblis pertama dari retakan telah kau kalahkan.\n"); break;
        case 22: printf("Gerombolan iblis ini adalah pertahanan terakhir sang Archdemon.\n"); break;
        case 23: printf("Kau semakin dekat dengan Malakor, aura jahatnya menyesakkan.\n"); break;
        case 24: printf("Sang Jenderal Iblis telah tumbang. Tidak ada lagi yang menghalangi jalanmu.\n"); break;
        
        // --- Akhir Quest ---
        case 25: printf("Malakor telah dikalahkan! Retakan menutup, dan ancaman berakhir... untuk saat ini.\n"); break;
        
        default: printf("Melanjutkan investigasi...\n"); break;
    }

    if (current_challenge.monster_id != 0) {
        struct Monster next_boss_data = get_monster_by_id(current_challenge.monster_id);
        printf("\nTantangan Berikutnya: %s\n", current_challenge.lore_intro);
        printf("Musuh              : %s (HP: %d, ATK: %d)\n", next_boss_data.nama, next_boss_data.healthPoint, next_boss_data.attackPower);
        printf("Level Minimum      : %d\n", current_challenge.min_level);
        printf("Ketik 'CHALLENGE' untuk menghadapi tantangan ini.\n");
    } else {
        printf("\nSelamat! Anda telah mengalahkan semua ancaman!\n");
    }
    printf("----------------------------------------------------\n");
}

// Fungsi untuk memulai pertarungan quest
void challenge_quest_boss() {
    QuestChallenge challenge = get_challenge_data(mainPlayer.world_quest_stage);

    if (challenge.monster_id == 0) {
        printf("Tidak ada tantangan tersisa.\n");
        return;
    }

    if (mainPlayer.LEVEL < challenge.min_level) {
        printf("Level Anda (%d) belum cukup. Butuh Level %d.\n", mainPlayer.LEVEL, challenge.min_level);
        return;
    }

    struct Monster boss_to_fight = get_monster_by_id(challenge.monster_id);
    if (boss_to_fight.monsterID != 0) {
        printf("\nAnda memasuki area tantangan...\n");
        // Kita langsung mulai pertarungan, tanpa opsi kabur awal
        lakukan_pertarungan(boss_to_fight);
    } else {
        printf("Error: Data bos tidak ditemukan.\n");
    }
}

// Fungsi yang dipanggil setelah mengalahkan bos quest
void handle_quest_boss_victory(int defeated_monster_rarity, int is_main_boss) {
    mainPlayer.world_quest_stage++; // Maju ke stage berikutnya

    int gold_reward = 0;
    int key_rarity = 0;
    int num_keys = 0;

    if (is_main_boss) {
        gold_reward = 500 * defeated_monster_rarity;
        key_rarity = defeated_monster_rarity + 1;
        if (key_rarity > 5) key_rarity = 5; // Batasi rarity kunci maksimal 5
        num_keys = 2;
        printf("Anda mengalahkan Bos Utama!\n");
    } else {
        gold_reward = 100 * defeated_monster_rarity;
        key_rarity = defeated_monster_rarity;
        num_keys = 1;
        printf("Anda mengalahkan Sub-Boss!\n");
    }

    printf("Hadiah: %d Gold.\n", gold_reward);
    mainPlayer.GOLD += gold_reward;

    // Berikan Kunci (Anda perlu fungsi helper untuk mendapatkan ID kunci berdasarkan rarity)
    for (int i = 0; i < num_keys; i++) {
        int key_id = get_random_key_id_by_rarity(key_rarity); // Buat fungsi ini di utilities.c
        if (key_id != 0) {
            tambahkan_item_ke_bag(key_id, 1);
        }
    }

    // Tampilkan lore kemenangan (sebaiknya diambil dari data quest berikutnya)
    QuestChallenge next_challenge = get_challenge_data(mainPlayer.world_quest_stage);
    if (next_challenge.monster_id != 0) {
         // Anda bisa menambahkan lore kemenangan spesifik di sini jika mau
    } else if (mainPlayer.world_quest_stage == 25) { // Cek jika ini stage akhir
        printf("Malakor meraung saat kekuatannya hancur... Retakan menutup...\n");
    }


    save_game_data();
}