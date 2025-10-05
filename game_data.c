#include "game_data.h" 

//Definisi dan Inisialisasi Daftar Item
struct Item daftarItem[] = {
    {101, "Pedang Kayu", 50},
    // Menggunakan Designated Initializers (Lebih direkomendasikan untuk clarity)
    {.itemID = 102, .nama = "Perisai Besi", .harga = 200},
    {103, "Ramuan Kecil", 25}
};


const int JUMLAH_ITEM = sizeof(daftarItem) / sizeof(daftarItem[0]);


//Definisi dan Inisialisasi Daftar Monster
struct Monster daftarMonster[] = {
    {.monsterID = 201, .nama = "Goblin", .healthPoint = 30},
    {.monsterID = 202, .nama = "Orc", .healthPoint = 80},
    {.monsterID = 203, .nama = "Serigala", .healthPoint = 40}
};


const int JUMLAH_MONSTER = sizeof(daftarMonster) / sizeof(daftarMonster[0]);