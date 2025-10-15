// File: src/game_data.h (VERSI BARU)
#ifndef GAME_DATA_H
#define GAME_DATA_H

#define MAX_NAMA 50
#define MAX_INVENTORY_SLOTS 50


struct InventorySlot {
    int itemID;
    int quantity;
};

struct Player {
    
    char username[50];
    int HP;
    int MAX_HP;
    int ATK;
    int DEF;
    int LEVEL;
    int XP;
    int GOLD;
    int equipped_weapon_id;
    int bonus_atk;
    int equipped_armor_id;
    int bonus_def;
    int equipped_helmet_id; 
    int bonus_hp;
    int skill_1_cd;
    int skill_2_cd;
    int active_skill_1_index;
    int active_skill_2_index;
    struct InventorySlot inventory[100];
    int inventory_count;
    int max_inventory_slots;
    int owned_skill_ids[50];
    int owned_skill_count;
    int max_skills_owned;
};

extern struct Player mainPlayer; 

#endif