// utilities.h
#ifndef UTILITIES_H
#define UTILITIES_H

// Perlu di-include untuk tipe struct Monster, Item, dan Player
#include "game_data.h" 

// ==========================================================
// I. FUNGSI UTILITAS DASAR (Definisi di utilities.c)
// ==========================================================
void cls();
void bersihkanString(char *str);
void bacaInput(char *input);     // BARU: Input CLI Aman
void help();                     // BARU: Tampilan Daftar Perintah
void apply_stat_boosts();        // BARU: Kalkulasi stat total Player

// ==========================================================
// II. FUNGSI QUERY DATA & INVENTORY
// ==========================================================
struct Item get_item_by_id(int id);
struct Skill get_skill_by_id(int id); // BARU: Untuk mengambil data skill
int is_item_in_inventory(int itemID);

// ==========================================================
// III. FUNGSI RANDOM & ENCOUNTER
// ==========================================================
int get_random_rarity();
struct Monster get_random_monster_by_rarity(int required_rarity);
struct Item get_random_item_by_rarity(int required_rarity);
struct Skill get_random_skill_by_rarity(int required_rarity);

// ==========================================================
// IV. FUNGSI PERTARUNGAN
// ==========================================================
void heal_to_max_hp(); // Pemulihan setelah/selama pertarungan
void drop_chest_key_by_rarity(int monster_rarity);

#endif