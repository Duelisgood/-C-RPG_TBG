#include "game_data.h" 

//Definisi dan Inisialisasi Daftar Item
struct Item daftarItem[] = {
    
    {.itemID = 101, .nama = "Pedang Kayu", .harga = 50,.rarity = 1, .type = "WEAPON",.stat_boost = 1 },
    {.itemID = 102, .nama = "Perisai Besi", .harga = 200,.rarity = 2, .type = "ARMOR",.stat_boost = 5 },
    {.itemID = 103, .nama = "Ramuan Kecil", .harga = 25,.rarity = 1,.type = "CONSUMABLE",.stat_boost = 0 },
    {.itemID = 104, .nama = "Pedang Legendary", .harga = 5000,.rarity = 5,.type = "WEAPON",.stat_boost = 20}
};

const int JUMLAH_ITEM = sizeof(daftarItem) / sizeof(daftarItem[0]);

//Definisi dan Inisialisasi Daftar Monster
struct Monster daftarMonster[] = {
   
    { .monsterID = 201, .nama = "Goblin Kecil", .healthPoint = 10, .attackPower = 2, .rarity = 1, .skillPower = 4, .goldDrop = 5, .expDrop = 10 },
    { .monsterID = 202, .nama = "Orc ", .healthPoint = 15, .attackPower = 5, .rarity = 2, .skillPower = 5, .goldDrop = 15, .expDrop = 30 },
    { .monsterID = 203, .nama = "Raja Serigala", .healthPoint = 150, .attackPower = 25, .rarity = 4, .skillPower = 10,.goldDrop = 50, .expDrop = 100 }
};

const int JUMLAH_MONSTER = sizeof(daftarMonster) / sizeof(daftarMonster[0]);

struct Skill daftarSkill[] = {
    {.skillID = 1, .nama = "Minor Heal", .cooldown_max = 2, .effect_type = "HEAL", .effect_value = 5},
    {.skillID = 2, .nama = "Power Slash", .cooldown_max = 3, .effect_type = "ATTACK", .effect_value = 3},
    {.skillID = 3, .nama = "Defense Stance", .cooldown_max = 4, .effect_type = "HEAL", .effect_value = 10}, 
    {.skillID = 4, .nama = "Triple Shot", .cooldown_max = 5, .effect_type = "ATTACK", .effect_value = 8}, 
    {.skillID = 5, .nama = "Emergency Mend", .cooldown_max = 6, .effect_type = "HEAL", .effect_value = 25}
};

const int JUMLAH_SKILL = sizeof(daftarSkill) / sizeof(daftarSkill[0]);