// File: src/item_data.h
#ifndef ITEM_DATA_H
#define ITEM_DATA_H
#include "game_data.h" // Diperlukan untuk MAX_NAMA

struct Item {
    int itemID;
    char nama[MAX_NAMA];
    int harga;
    int rarity; 
    char type[15];
    int stat_boost; 
};

extern struct Item daftarItem[];
extern const int JUMLAH_ITEM;

#endif