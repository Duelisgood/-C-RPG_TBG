// File: src/game_data.h (VERSI BARU)
#ifndef GAME_DATA_H
#define GAME_DATA_H

#define MAX_NAMA 50
#define MAX_INVENTORY_SLOTS 50
#define MAX_SKILLS_OWNED 10

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
    struct InventorySlot inventory[MAX_INVENTORY_SLOTS];
    int inventory_count;
    int owned_skill_ids[MAX_SKILLS_OWNED];
    int owned_skill_count;
};

extern struct Player mainPlayer; 

#endif