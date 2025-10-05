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
};


extern struct Item daftarItem[];
extern const int JUMLAH_ITEM;

extern struct Monster daftarMonster[];
extern const int JUMLAH_MONSTER;

#endif