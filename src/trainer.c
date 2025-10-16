// File: src/trainer.c
#include <stdio.h>
#include <string.h>

#include "trainer.h"
#include "player_manager.h"
#include "utilities.h"
#include "data/skill_data.h"

#define MAX_INPUT 50

void forget_skill_menu() {
    printf("\n--- Lupakan Skill ---\n");
    printf("Pilih skill untuk dilupakan dan diubah menjadi Experience Points (XP).\n");

    if (mainPlayer.owned_skill_count <= 2) {
        printf("Anda harus memiliki lebih dari 2 skill untuk bisa melupakan salah satunya.\n");
        return;
    }

    printf("\nSkill yang Anda Miliki:\n");
    for (int i = 0; i < mainPlayer.owned_skill_count; i++) {
        struct Skill s = get_skill_by_id(mainPlayer.owned_skill_ids[i]);
        int exp_reward = s.rarity * 50; // Contoh: Rarity 1 = 50 XP, Rarity 5 = 250 XP
        printf("  ID: %d | %s (Rarity: %d) | Hadiah: %d XP\n", s.skillID, s.nama, s.rarity, exp_reward);
    }
    printf("--------------------------------\n");

    int skill_id_to_forget;
    printf("Masukkan ID skill yang ingin dilupakan (atau 0 untuk batal): ");
    if (scanf("%d", &skill_id_to_forget) != 1) {
        printf("Input tidak valid.\n");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n');

    if (skill_id_to_forget == 0) {
        printf("Batal melupakan skill.\n");
        return;
    }

    // Validasi
    int skill_index = -1;
    for (int i = 0; i < mainPlayer.owned_skill_count; i++) {
        if (mainPlayer.owned_skill_ids[i] == skill_id_to_forget) {
            skill_index = i;
            break;
        }
    }

    if (skill_index == -1) {
        printf("Anda tidak memiliki skill dengan ID tersebut.\n");
        return;
    }

    if (skill_index == mainPlayer.active_skill_1_index || skill_index == mainPlayer.active_skill_2_index) {
        printf("Anda tidak bisa melupakan skill yang sedang aktif.\n");
        return;
    }

    // Proses melupakan skill
    struct Skill skill_to_forget = get_skill_by_id(skill_id_to_forget);
    int exp_reward = skill_to_forget.rarity * 50;

    printf("Anda akan melupakan '%s' dan mendapatkan %d XP. Lanjutkan? [Y/N]: ", skill_to_forget.nama, exp_reward);
    char confirm[10];
    bacaInput(confirm);

    if (strcmp(confirm, "Y") == 0) {
        // Geser semua skill setelahnya untuk menutupi celah
        for (int i = skill_index; i < mainPlayer.owned_skill_count - 1; i++) {
            mainPlayer.owned_skill_ids[i] = mainPlayer.owned_skill_ids[i + 1];
        }
        mainPlayer.owned_skill_count--;
        mainPlayer.XP += exp_reward;

        printf("Anda berhasil melupakan '%s' dan mendapatkan %d XP!\n", skill_to_forget.nama, exp_reward);
        
        // Penting: Perbarui indeks skill aktif jika posisinya bergeser
        if (mainPlayer.active_skill_1_index > skill_index) mainPlayer.active_skill_1_index--;
        if (mainPlayer.active_skill_2_index > skill_index) mainPlayer.active_skill_2_index--;

        check_for_level_up(); // Cek apakah XP cukup untuk naik level
        save_game_data();
    } else {
        printf("Batal melupakan skill.\n");
    }
}

void enchant_skill_menu() {
    printf("\n--- Perkuat Skill (Enchant) ---\n");
    printf("Fitur ini belum tersedia.\n");

}

void open_trainer_menu() {
    char input[MAX_INPUT];
    int at_trainer = 1;

    while (at_trainer) {
        printf("\n=== Pelatih Skill ===\n");
        printf("Seorang master tua menyambut Anda. 'Apa yang bisa kubantu, petualang?'\n");
        printf("Pilih Opsi: [FORGET] (Lupakan skill untuk XP) | [ENCHANT] (Perkuat skill) | [EXIT]\n");
        bacaInput(input);

        if (strcmp(input, "FORGET") == 0) {
            forget_skill_menu();
        } else if (strcmp(input, "ENCHANT") == 0) {
            enchant_skill_menu();
        } else if (strcmp(input, "EXIT") == 0) {
            printf("'Kembalilah jika kau butuh bimbingan.'\n");
            at_trainer = 0;
        } else {
            printf("Perintah tidak dikenal.\n");
        }
    }
}