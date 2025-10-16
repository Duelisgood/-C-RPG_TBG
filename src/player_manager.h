// player_manager.h
#ifndef PLAYER_MANAGER_H
#define PLAYER_MANAGER_H


// Diperlukan untuk mengakses struct Player dan Item
#include "data/game_data.h"


// --- Prototipe Fungsi Player Management ---
void save_game_data();
void load_game_data(const char *username);
void login_system();
void check_for_level_up();
void recalculate_all_bonuses();

// Fungsi Item dan Skill
void tambahkan_item_ke_bag(int item_id_baru, int jumlah);
void remove_item_from_bag(int itemID, int quantity);
void open_chest_menu();
void learn_new_skill(int skill_id);
void use_equipment();
void change_skill();

// Fungsi Tampilan Menu
void bag();
void help(); // Asumsi fungsi help() diletakkan di Player Manager/Utilities
void apply_stat_boosts();
void learn_skill_menu(); 



#endif