// game_data.h

#ifndef GAME_DATA_H
#define GAME_DATA_H

#define MAX_NAMA 50

// Definisi Struktur untuk Item
struct Item {
    int itemID;
    char nama[MAX_NAMA];
    int harga;
};

// Definisi Struktur untuk Monster
struct Monster {
    int monsterID;
    char nama[MAX_NAMA];
    int healthPoint;
    int attackPower;
};
struct Skill {
    int skillID;
    char nama[MAX_NAMA];
    int cooldown_max;       // Cooldown maksimal dalam turn
    char effect_type[10];   // "HEAL" atau "ATTACK"
    int effect_value;       // Nilai efek (HP atau Damage tambahan)
};


extern struct Skill daftarSkill[];
extern const int JUMLAH_SKILL;

extern struct Item daftarItem[];
extern const int JUMLAH_ITEM;

extern struct Monster daftarMonster[];
extern const int JUMLAH_MONSTER;

#endif