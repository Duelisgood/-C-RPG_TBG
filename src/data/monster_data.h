// File: src/monster_data.h
#ifndef MONSTER_DATA_H
#define MONSTER_DATA_H
#include "game_data.h" // Diperlukan untuk MAX_NAMA

struct Monster {
    int monsterID;
    char nama[MAX_NAMA];
    int healthPoint;
    int attackPower;
    int rarity; 
    int skillPower;
    int goldDrop;           
    int expDrop;
};

extern struct Monster daftarMonster[];
extern const int JUMLAH_MONSTER;

#endif