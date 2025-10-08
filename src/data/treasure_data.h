// File: src/treasure_data.h
#ifndef TREASURE_DATA_H
#define TREASURE_DATA_H
#include "game_data.h" // Diperlukan untuk MAX_NAMA

#define MAX_SKILL_DROPS 4
#define MAX_CHEST_DROPS 5

struct Chest {
    int chestID;
    char nama[MAX_NAMA];
    int rarity;      
    int price;      
    int drop_item_ids[MAX_CHEST_DROPS]; 
    int drop_count; 
};

struct SkillBook {
    int bookID;
    char nama[MAX_NAMA];
    int rarity;
    int drop_skill_ids[MAX_SKILL_DROPS];
    int drop_count;
};

extern struct Chest daftarChest[];
extern const int JUMLAH_CHEST;
extern struct SkillBook daftarSkillBook[];
extern const int JUMLAH_SKILLBOOK;

#endif