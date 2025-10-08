#include "game_data.h" 

//Definisi dan Inisialisasi Daftar Item
struct Item daftarItem[] = {
// =================================================================
// ============== RARITY 1 (UMUM) - ATK/DEF +1 hingga +3 ============
// =================================================================
    {.itemID = 101, .nama = "Pedang Kayu", .harga = 50, .rarity = 1, .type = "WEAPON", .stat_boost = 1 },
    {.itemID = 105, .nama = "Dagger Tumpul", .harga = 75, .rarity = 1, .type = "WEAPON", .stat_boost = 3 },
    {.itemID = 120, .nama = "Rompi Kain", .harga = 40, .rarity = 1, .type = "ARMOR", .stat_boost = 2 },
    {.itemID = 125, .nama = "Perisai Kayu", .harga = 60, .rarity = 1, .type = "ARMOR", .stat_boost = 3 },
    // -- 10 ITEM BARU RARITY 1 --
    {.itemID = 131, .nama = "Topi Petualang", .harga = 20, .rarity = 1, .type = "ARMOR", .stat_boost = 1 },
    {.itemID = 132, .nama = "Sarung Tangan Kain", .harga = 15, .rarity = 1, .type = "ARMOR", .stat_boost = 1 },
    {.itemID = 133, .nama = "Sepatu Bot Kulit", .harga = 25, .rarity = 1, .type = "ARMOR", .stat_boost = 1 },
    {.itemID = 134, .nama = "Gada Kayu", .harga = 40, .rarity = 1, .type = "WEAPON", .stat_boost = 2 },
    {.itemID = 135, .nama = "Busur Pendek", .harga = 65, .rarity = 1, .type = "WEAPON", .stat_boost = 2 },
    {.itemID = 136, .nama = "Belati Karatan", .harga = 35, .rarity = 1, .type = "WEAPON", .stat_boost = 1 },
    {.itemID = 137, .nama = "Jubah Lusuh", .harga = 30, .rarity = 1, .type = "ARMOR", .stat_boost = 2 },
    {.itemID = 138, .nama = "Perisai Rotan", .harga = 55, .rarity = 1, .type = "ARMOR", .stat_boost = 2 },
    {.itemID = 139, .nama = "Tombak Bambu", .harga = 50, .rarity = 1, .type = "WEAPON", .stat_boost = 2 },
    {.itemID = 150, .nama = "Ramuan Penyembuh Kecil", .harga = 30, .rarity = 1, .type = "CONSUMABLE", .stat_boost = 10 },
    // -- Chest --
    {.itemID = 701, .nama = "Kunci Peti Kayu Tua", .harga = 25, .rarity = 1, .type = "CHEST", .stat_boost = 601},
    {.itemID = 702, .nama = "Kunci Kantong Kulit", .harga = 25, .rarity = 1, .type = "CHEST", .stat_boost = 602},
    {.itemID = 703, .nama = "Kunci Kotak Goblin", .harga = 20, .rarity = 1, .type = "CHEST", .stat_boost = 603},
    {.itemID = 704, .nama = "Kunci Ransel Pengelana", .harga = 30, .rarity = 1, .type = "CHEST", .stat_boost = 604},
    {.itemID = 705, .nama = "Kunci Simpanan Bandit", .harga = 35, .rarity = 1, .type = "CHEST", .stat_boost = 605},


// =================================================================
// ============== RARITY 2 (TIDAK UMUM) - ATK/DEF +4 hingga +7 =====
// =================================================================
    {.itemID = 201, .nama = "Short Sword", .harga = 250, .rarity = 2, .type = "WEAPON", .stat_boost = 5 },
    {.itemID = 205, .nama = "Mace Berduri", .harga = 300, .rarity = 2, .type = "WEAPON", .stat_boost = 7 },
    {.itemID = 102, .nama = "Perisai Besi", .harga = 200, .rarity = 2, .type = "ARMOR", .stat_boost = 5 },
    {.itemID = 225, .nama = "Chain Mail", .harga = 350, .rarity = 2, .type = "ARMOR", .stat_boost = 7 },
    // -- 10 ITEM BARU RARITY 2 --
    {.itemID = 231, .nama = "Helm Kulit Keras", .harga = 180, .rarity = 2, .type = "ARMOR", .stat_boost = 4 },
    {.itemID = 232, .nama = "Kapak Tangan Besi", .harga = 280, .rarity = 2, .type = "WEAPON", .stat_boost = 6 },
    {.itemID = 233, .nama = "Jubah Pengelana", .harga = 210, .rarity = 2, .type = "ARMOR", .stat_boost = 5 },
    {.itemID = 234, .nama = "Pelindung Kaki Besi", .harga = 240, .rarity = 2, .type = "ARMOR", .stat_boost = 6 },
    {.itemID = 235, .nama = "Panah Otomatis", .harga = 320, .rarity = 2, .type = "WEAPON", .stat_boost = 5 },
    {.itemID = 236, .nama = "Pedang Lebar", .harga = 290, .rarity = 2, .type = "WEAPON", .stat_boost = 6 },
    {.itemID = 237, .nama = "Tombak Besi", .harga = 260, .rarity = 2, .type = "WEAPON", .stat_boost = 5 },
    {.itemID = 238, .nama = "Baju Zirah Kulit", .harga = 200, .rarity = 2, .type = "ARMOR", .stat_boost = 6 },
    {.itemID = 239, .nama = "Sarung Tangan Berduri", .harga = 190, .rarity = 2, .type = "ARMOR", .stat_boost = 4 },
     // -- Chest --
    {.itemID = 711, .nama = "Kunci Peti Besi", .harga = 75, .rarity = 2, .type = "CHEST", .stat_boost = 611},
    {.itemID = 712, .nama = "Kunci Kargo Penyelundup", .harga = 85, .rarity = 2, .type = "CHEST", .stat_boost = 612},
    {.itemID = 713, .nama = "Kunci Peti Prajurit", .harga = 80, .rarity = 2, .type = "CHEST", .stat_boost = 613},
    {.itemID = 714, .nama = "Kunci Kotak Persenjataan", .harga = 70, .rarity = 2, .type = "CHEST", .stat_boost = 614},
    {.itemID = 715, .nama = "Kunci Warisan Terlupakan", .harga = 100, .rarity = 2, .type = "CHEST", .stat_boost = 615},
    

// =================================================================
// ============== RARITY 3 (LANGKA) - ATK/DEF +8 hingga +12 ========
// =================================================================
    {.itemID = 301, .nama = "Great Axe", .harga = 800, .rarity = 3, .type = "WEAPON", .stat_boost = 10 },
    {.itemID = 305, .nama = "Katana Baja", .harga = 1000, .rarity = 3, .type = "WEAPON", .stat_boost = 12 },
    {.itemID = 320, .nama = "Steel Plate", .harga = 950, .rarity = 3, .type = "ARMOR", .stat_boost = 9 },
    {.itemID = 325, .nama = "Helm Bertanduk", .harga = 700, .rarity = 3, .type = "ARMOR", .stat_boost = 12 },
    // -- 10 ITEM BARU RARITY 3 --
    {.itemID = 331, .nama = "Pedang Ksatria", .harga = 980, .rarity = 3, .type = "WEAPON", .stat_boost = 11 },
    {.itemID = 332, .nama = "Baju Zirah Baja", .harga = 1100, .rarity = 3, .type = "ARMOR", .stat_boost = 10 },
    {.itemID = 333, .nama = "Sarung Tangan Baja", .harga = 650, .rarity = 3, .type = "ARMOR", .stat_boost = 8 },
    {.itemID = 334, .nama = "Panah Pemburu", .harga = 850, .rarity = 3, .type = "WEAPON", .stat_boost = 9 },
    {.itemID = 335, .nama = "Perisai Menara", .harga = 900, .rarity = 3, .type = "ARMOR", .stat_boost = 11 },
    {.itemID = 336, .nama = "Belati Elf", .harga = 900, .rarity = 3, .type = "WEAPON", .stat_boost = 11 },
    {.itemID = 337, .nama = "Jubah Ajaib", .harga = 750, .rarity = 3, .type = "ARMOR", .stat_boost = 8 },
    {.itemID = 338, .nama = "Palu Perang", .harga = 920, .rarity = 3, .type = "WEAPON", .stat_boost = 10 },
    {.itemID = 339, .nama = "Sepatu Bot Baja", .harga = 680, .rarity = 3, .type = "ARMOR", .stat_boost = 8 },
    {.itemID = 350, .nama = "Ramuan Penyembuh Sedang", .harga = 200, .rarity = 3, .type = "CONSUMABLE", .stat_boost = 50 },
     // -- Chest --
    {.itemID = 721, .nama = "Kunci Peti Baja Berukir", .harga = 200, .rarity = 3, .type = "CHEST", .stat_boost = 621},
    {.itemID = 722, .nama = "Kunci Kotak Emas", .harga = 250, .rarity = 3, .type = "CHEST", .stat_boost = 622},
    {.itemID = 723, .nama = "Kunci Harta Karun Orc", .harga = 180, .rarity = 3, .type = "CHEST", .stat_boost = 623},
    {.itemID = 724, .nama = "Kunci Simpanan Ksatria", .harga = 220, .rarity = 3, .type = "CHEST", .stat_boost = 624},
    {.itemID = 725, .nama = "Kunci Relik Reruntuhan", .harga = 230, .rarity = 3, .type = "CHEST", .stat_boost = 625},


// =================================================================
// ============== RARITY 4 (EPIC) - ATK/DEF +13 hingga +20 =========
// =================================================================
    {.itemID = 401, .nama = "Rune Sword", .harga = 3500, .rarity = 4, .type = "WEAPON", .stat_boost = 16 },
    {.itemID = 405, .nama = "Halberd Energi", .harga = 4200, .rarity = 4, .type = "WEAPON", .stat_boost = 20 },
    {.itemID = 420, .nama = "Mithril Mail", .harga = 3800, .rarity = 4, .type = "ARMOR", .stat_boost = 18 },
    {.itemID = 425, .nama = "Shield of Aegis", .harga = 4500, .rarity = 4, .type = "ARMOR", .stat_boost = 20 },
    // -- 10 ITEM BARU RARITY 4 --
    {.itemID = 431, .nama = "Pedang Api", .harga = 3900, .rarity = 4, .type = "WEAPON", .stat_boost = 17 },
    {.itemID = 432, .nama = "Perisai Es", .harga = 4100, .rarity = 4, .type = "ARMOR", .stat_boost = 19 },
    {.itemID = 433, .nama = "Helm Elven", .harga = 3200, .rarity = 4, .type = "ARMOR", .stat_boost = 14 },
    {.itemID = 434, .nama = "Tombak Petir", .harga = 3700, .rarity = 4, .type = "WEAPON", .stat_boost = 16 },
    {.itemID = 435, .nama = "Jubah Penyihir Agung", .harga = 3600, .rarity = 4, .type = "ARMOR", .stat_boost = 15 },
    {.itemID = 436, .nama = "Palu Perang Dwarven", .harga = 3900, .rarity = 4, .type = "WEAPON", .stat_boost = 18 },
    {.itemID = 437, .nama = "Busur Kristal", .harga = 4000, .rarity = 4, .type = "WEAPON", .stat_boost = 15 },
    {.itemID = 438, .nama = "Sarung Tangan Obsidian", .harga = 3400, .rarity = 4, .type = "ARMOR", .stat_boost = 13 },
    {.itemID = 439, .nama = "Pelindung Kaki Mithril", .harga = 3500, .rarity = 4, .type = "ARMOR", .stat_boost = 14 },
    {.itemID = 450, .nama = "Ramuan Penyembuh Besar", .harga = 800, .rarity = 4, .type = "CONSUMABLE", .stat_boost = 150 },
     // -- Chest --
    {.itemID = 731, .nama = "Kunci Kristal Ajaib", .harga = 600, .rarity = 4, .type = "CHEST", .stat_boost = 631},
    {.itemID = 732, .nama = "Kunci Elven", .harga = 750, .rarity = 4, .type = "CHEST", .stat_boost = 632},
    {.itemID = 733, .nama = "Kunci Ahli Sihir", .harga = 700, .rarity = 4, .type = "CHEST", .stat_boost = 633},
    {.itemID = 734, .nama = "Kunci Dwarven", .harga = 800, .rarity = 4, .type = "CHEST", .stat_boost = 634},
    {.itemID = 735, .nama = "Kunci Kuil Kuno", .harga = 900, .rarity = 4, .type = "CHEST", .stat_boost = 635},

// =================================================================
// ============== RARITY 5 (LEGENDARY) - ATK/DEF +25 hingga +40 ====
// =================================================================
    {.itemID = 501, .nama = "Dragon Blade", .harga = 9000, .rarity = 5, .type = "WEAPON", .stat_boost = 30 },
    {.itemID = 104, .nama = "Pedang Legendary", .harga = 50000, .rarity = 5, .type = "WEAPON", .stat_boost = 35 }, 
    {.itemID = 520, .nama = "Godly Plate", .harga = 12000, .rarity = 5, .type = "ARMOR", .stat_boost = 30 },
    {.itemID = 525, .nama = "Crown of Ancients", .harga = 15000, .rarity = 5, .type = "ARMOR", .stat_boost = 40 },
    // -- 10 ITEM BARU RARITY 5 --
    {.itemID = 531, .nama = "Armor Sisik Naga", .harga = 25000, .rarity = 5, .type = "ARMOR", .stat_boost = 38 },
    {.itemID = 532, .nama = "Palu Dewa Perang", .harga = 30000, .rarity = 5, .type = "WEAPON", .stat_boost = 36 },
    {.itemID = 533, .nama = "Jubah Bayangan", .harga = 18000, .rarity = 5, .type = "ARMOR", .stat_boost = 25 },
    {.itemID = 534, .nama = "Staf Kuno", .harga = 28000, .rarity = 5, .type = "WEAPON", .stat_boost = 32 },
    {.itemID = 535, .nama = "Perisai Cermin", .harga = 22000, .rarity = 5, .type = "ARMOR", .stat_boost = 35 },
    {.itemID = 536, .nama = "Busur Cahaya", .harga = 18000, .rarity = 5, .type = "WEAPON", .stat_boost = 28 },
    {.itemID = 537, .nama = "Pelindung Kaki Titan", .harga = 16000, .rarity = 5, .type = "ARMOR", .stat_boost = 38 },
    {.itemID = 538, .nama = "Excalibur", .harga = 60000, .rarity = 5, .type = "WEAPON", .stat_boost = 40 },
    {.itemID = 539, .nama = "Helm Dewa Matahari", .harga = 20000, .rarity = 5, .type = "ARMOR", .stat_boost = 26 },
    {.itemID = 550, .nama = "Elixir Kehidupan", .harga = 5000, .rarity = 5, .type = "CONSUMABLE", .stat_boost = 999 },
     // -- Chest --
    {.itemID = 741, .nama = "Kunci Sisik Naga", .harga = 2500, .rarity = 5, .type = "CHEST", .stat_boost = 641},
    {.itemID = 742, .nama = "Kunci Warisan Dewa", .harga = 3500, .rarity = 5, .type = "CHEST", .stat_boost = 642},
    {.itemID = 743, .nama = "Kunci Obsidian", .harga = 3000, .rarity = 5, .type = "CHEST", .stat_boost = 643},
    {.itemID = 744, .nama = "Kunci Raja Iblis", .harga = 5000, .rarity = 5, .type = "CHEST", .stat_boost = 644},
    {.itemID = 745, .nama = "Kunci Takdir", .harga = 6000, .rarity = 5, .type = "CHEST", .stat_boost = 645},
};


const int JUMLAH_ITEM = sizeof(daftarItem) / sizeof(daftarItem[0]);

//Definisi dan Inisialisasi Daftar Monster
struct Monster daftarMonster[] = {
// =================================================================
// ============== RARITY 1 (ID 1001 - 1010) - UMUM ================
// =================================================================
    { .monsterID = 1001, .nama = "Laba-Laba Kecil", .healthPoint = 7, .attackPower = 2, .rarity = 1, .skillPower = 3, .goldDrop = 6, .expDrop = 8 },
    { .monsterID = 1002, .nama = "Slime Hijau", .healthPoint = 10, .attackPower = 1, .rarity = 1, .skillPower = 4, .goldDrop = 5, .expDrop = 10 },
    { .monsterID = 1003, .nama = "Goblin Cilik", .healthPoint = 5, .attackPower = 3, .rarity = 1, .skillPower = 5, .goldDrop = 8, .expDrop = 7 },
    { .monsterID = 1004, .nama = "Kelelawar", .healthPoint = 8, .attackPower = 2, .rarity = 1, .skillPower = 3, .goldDrop = 7, .expDrop = 9 },
    { .monsterID = 1005, .nama = "Jamur Beracun", .healthPoint = 9, .attackPower = 1, .rarity = 1, .skillPower = 5, .goldDrop = 5, .expDrop = 6 },
    { .monsterID = 1006, .nama = "Tikus Hutan", .healthPoint = 6, .attackPower = 3, .rarity = 1, .skillPower = 4, .goldDrop = 10, .expDrop = 5 },
    { .monsterID = 1007, .nama = "Ulat Raksasa", .healthPoint = 10, .attackPower = 1, .rarity = 1, .skillPower = 3, .goldDrop = 6, .expDrop = 10 },
    { .monsterID = 1008, .nama = "Belalang Liar", .healthPoint = 7, .attackPower = 2, .rarity = 1, .skillPower = 4, .goldDrop = 9, .expDrop = 8 },
    { .monsterID = 1009, .nama = "Semut Prajurit", .healthPoint = 6, .attackPower = 3, .rarity = 1, .skillPower = 5, .goldDrop = 7, .expDrop = 7 },
    { .monsterID = 1010, .nama = "Cacing Tanah", .healthPoint = 8, .attackPower = 2, .rarity = 1, .skillPower = 3, .goldDrop = 5, .expDrop = 9 },

// =================================================================
// ============ RARITY 2 (ID 2001 - 2010) - TIDAK UMUM =============
// =================================================================
    { .monsterID = 2001, .nama = "Serigala Hutan", .healthPoint = 20, .attackPower = 6, .rarity = 2, .skillPower = 8, .goldDrop = 20, .expDrop = 25 },
    { .monsterID = 2002, .nama = "Bandit Biasa", .healthPoint = 25, .attackPower = 4, .rarity = 2, .skillPower = 10, .goldDrop = 30, .expDrop = 15 },
    { .monsterID = 2003, .nama = "Skeleton Prajurit", .healthPoint = 15, .attackPower = 8, .rarity = 2, .skillPower = 6, .goldDrop = 18, .expDrop = 28 },
    { .monsterID = 2004, .nama = "Gargoyle Kecil", .healthPoint = 22, .attackPower = 5, .rarity = 2, .skillPower = 9, .goldDrop = 25, .expDrop = 20 },
    { .monsterID = 2005, .nama = "Beruang Muda", .healthPoint = 24, .attackPower = 7, .rarity = 2, .skillPower = 7, .goldDrop = 15, .expDrop = 30 },
    { .monsterID = 2006, .nama = "Slime Biru", .healthPoint = 18, .attackPower = 5, .rarity = 2, .skillPower = 10, .goldDrop = 22, .expDrop = 18 },
    { .monsterID = 2007, .nama = "Perompak", .healthPoint = 21, .attackPower = 6, .rarity = 2, .skillPower = 8, .goldDrop = 30, .expDrop = 15 },
    { .monsterID = 2008, .nama = "Zombie", .healthPoint = 25, .attackPower = 4, .rarity = 2, .skillPower = 6, .goldDrop = 15, .expDrop = 28 },
    { .monsterID = 2009, .nama = "Goblin Penjaga", .healthPoint = 17, .attackPower = 7, .rarity = 2, .skillPower = 9, .goldDrop = 28, .expDrop = 22 },
    { .monsterID = 2010, .nama = "Piranha Raksasa", .healthPoint = 19, .attackPower = 8, .rarity = 2, .skillPower = 7, .goldDrop = 20, .expDrop = 25 },

// =================================================================
// ============ RARITY 3 (ID 3001 - 3010) - LANGKA ================
// =================================================================
    { .monsterID = 3001, .nama = "Orc Warlord", .healthPoint = 40, .attackPower = 12, .rarity = 3, .skillPower = 15, .goldDrop = 50, .expDrop = 60 },
    { .monsterID = 3002, .nama = "Penyihir Gelap", .healthPoint = 35, .attackPower = 9, .rarity = 3, .skillPower = 18, .goldDrop = 70, .expDrop = 35 },
    { .monsterID = 3003, .nama = "Minotaur Muda", .healthPoint = 50, .attackPower = 15, .rarity = 3, .skillPower = 11, .goldDrop = 40, .expDrop = 70 },
    { .monsterID = 3004, .nama = "Specter", .healthPoint = 30, .attackPower = 10, .rarity = 3, .skillPower = 17, .goldDrop = 65, .expDrop = 45 },
    { .monsterID = 3005, .nama = "Griffin Kecil", .healthPoint = 45, .attackPower = 13, .rarity = 3, .skillPower = 14, .goldDrop = 55, .expDrop = 55 },
    { .monsterID = 3006, .nama = "Golem Batu", .healthPoint = 50, .attackPower = 9, .rarity = 3, .skillPower = 11, .goldDrop = 35, .expDrop = 70 },
    { .monsterID = 3007, .nama = "Kesatria Jatuh", .healthPoint = 40, .attackPower = 14, .rarity = 3, .skillPower = 16, .goldDrop = 60, .expDrop = 50 },
    { .monsterID = 3008, .nama = "Harimau Saber", .healthPoint = 38, .attackPower = 15, .rarity = 3, .skillPower = 12, .goldDrop = 45, .expDrop = 65 },
    { .monsterID = 3009, .nama = "Slime Merah", .healthPoint = 33, .attackPower = 10, .rarity = 3, .skillPower = 18, .goldDrop = 70, .expDrop = 40 },
    { .monsterID = 3010, .nama = "Medusa", .healthPoint = 48, .attackPower = 11, .rarity = 3, .skillPower = 13, .goldDrop = 50, .expDrop = 60 },

// =================================================================
// ============ RARITY 4 (ID 4001 - 4010) - EPIC ===================
// =================================================================
    { .monsterID = 4001, .nama = "Elder Dragon", .healthPoint = 80, .attackPower = 20, .rarity = 4, .skillPower = 25, .goldDrop = 120, .expDrop = 150 },
    { .monsterID = 4002, .nama = "Lich", .healthPoint = 65, .attackPower = 18, .rarity = 4, .skillPower = 30, .goldDrop = 150, .expDrop = 80 },
    { .monsterID = 4003, .nama = "Giant Cyclops", .healthPoint = 100, .attackPower = 25, .rarity = 4, .skillPower = 20, .goldDrop = 90, .expDrop = 140 },
    { .monsterID = 4004, .nama = "Chimera", .healthPoint = 75, .attackPower = 22, .rarity = 4, .skillPower = 28, .goldDrop = 130, .expDrop = 110 },
    { .monsterID = 4005, .nama = "Vampire Lord", .healthPoint = 90, .attackPower = 20, .rarity = 4, .skillPower = 26, .goldDrop = 110, .expDrop = 120 },
    { .monsterID = 4006, .nama = "Kraken Tentacle", .healthPoint = 95, .attackPower = 19, .rarity = 4, .skillPower = 22, .goldDrop = 80, .expDrop = 130 },
    { .monsterID = 4007, .nama = "Phoenix", .healthPoint = 60, .attackPower = 25, .rarity = 4, .skillPower = 29, .goldDrop = 140, .expDrop = 90 },
    { .monsterID = 4008, .nama = "Abyssal Horror", .healthPoint = 88, .attackPower = 16, .rarity = 4, .skillPower = 27, .goldDrop = 100, .expDrop = 150 },
    { .monsterID = 4009, .nama = "Raksasa Es", .healthPoint = 98, .attackPower = 24, .rarity = 4, .skillPower = 21, .goldDrop = 115, .expDrop = 135 },
    { .monsterID = 4010, .nama = "Raja Kobold", .healthPoint = 70, .attackPower = 23, .rarity = 4, .skillPower = 24, .goldDrop = 135, .expDrop = 105 },

// =================================================================
// ============ RARITY 5 (ID 5001 - 5010) - LEGENDARY/BOSS =========
// =================================================================
    { .monsterID = 5001, .nama = "Archdemon", .healthPoint = 180, .attackPower = 35, .rarity = 5, .skillPower = 45, .goldDrop = 300, .expDrop = 350 },
    { .monsterID = 5002, .nama = "Ancient God", .healthPoint = 200, .attackPower = 26, .rarity = 5, .skillPower = 50, .goldDrop = 350, .expDrop = 180 },
    { .monsterID = 5003, .nama = "World Serpent", .healthPoint = 150, .attackPower = 40, .rarity = 5, .skillPower = 38, .goldDrop = 250, .expDrop = 300 },
    { .monsterID = 5004, .nama = "Titan Stone", .healthPoint = 190, .attackPower = 28, .rarity = 5, .skillPower = 40, .goldDrop = 200, .expDrop = 320 },
    { .monsterID = 5005, .nama = "Shadow King", .healthPoint = 160, .attackPower = 38, .rarity = 5, .skillPower = 48, .goldDrop = 320, .expDrop = 250 },
    { .monsterID = 5006, .nama = "Cosmic Horror", .healthPoint = 140, .attackPower = 30, .rarity = 5, .skillPower = 42, .goldDrop = 180, .expDrop = 340 },
    { .monsterID = 5007, .nama = "Queen Fairy", .healthPoint = 120, .attackPower = 32, .rarity = 5, .skillPower = 35, .goldDrop = 280, .expDrop = 280 },
    { .monsterID = 5008, .nama = "The Destroyer", .healthPoint = 170, .attackPower = 36, .rarity = 5, .skillPower = 46, .goldDrop = 220, .expDrop = 330 },
    { .monsterID = 5009, .nama = "Divine Avatar", .healthPoint = 165, .attackPower = 33, .rarity = 5, .skillPower = 41, .goldDrop = 290, .expDrop = 290 },
    { .monsterID = 5010, .nama = "Time Keeper", .healthPoint = 185, .attackPower = 31, .rarity = 5, .skillPower = 49, .goldDrop = 270, .expDrop = 310 }
};

 // JANGAN LUPA UPDATE JUMLAH MONSTER!
const int JUMLAH_MONSTER = sizeof(daftarMonster) / sizeof(daftarMonster[0]);

struct Skill daftarSkill[] = {
// =================================================================
// ============== RARITY 1 (ID 101 - 105) - DASAR =================
// =================================================================
    {.skillID = 101, .nama = "Quick Stab", .cooldown_max = 2, .rarity = 1, .effect_type = "ATTACK", .effect_value = 3},
    {.skillID = 102, .nama = "Minor Heal", .cooldown_max = 3, .rarity = 1, .effect_type = "HEAL", .effect_value = 5}, // Mirip Minor Heal lama
    {.skillID = 103, .nama = "Deflect", .cooldown_max = 2, .rarity = 1, .effect_type = "HEAL", .effect_value = 4},
    
// =================================================================
// ============== RARITY 2 (ID 201 - 205) - STANDAR ===============
// =================================================================
    {.skillID = 201, .nama = "Power Slash", .cooldown_max = 3, .rarity = 2, .effect_type = "ATTACK", .effect_value = 7}, // Mirip Power Slash lama
    {.skillID = 202, .nama = "First Aid", .cooldown_max = 4, .rarity = 2, .effect_type = "HEAL", .effect_value = 10}, // Mirip Defense Stance lama
    {.skillID = 203, .nama = "Quick Shot", .cooldown_max = 3, .rarity = 2, .effect_type = "ATTACK", .effect_value = 6},

// =================================================================
// ============== RARITY 3 (ID 301 - 305) - KUAT ==================
// =================================================================
    {.skillID = 301, .nama = "Wild Swing", .cooldown_max = 4, .rarity = 3, .effect_type = "ATTACK", .effect_value = 15},
    {.skillID = 302, .nama = "Regenerate", .cooldown_max = 5, .rarity = 3, .effect_type = "HEAL", .effect_value = 18},
    {.skillID = 303, .nama = "Shadow Strike", .cooldown_max = 4, .rarity = 3, .effect_type = "ATTACK", .effect_value = 12},

// =================================================================
// ============== RARITY 4 (ID 401 - 405) - ELITE =================
// =================================================================
    {.skillID = 401, .nama = "Critical Focus", .cooldown_max = 5, .rarity = 4, .effect_type = "ATTACK", .effect_value = 25},
    {.skillID = 402, .nama = "Mass Healing", .cooldown_max = 6, .rarity = 4, .effect_type = "HEAL", .effect_value = 30},
    {.skillID = 403, .nama = "Triple Shot", .cooldown_max = 5, .rarity = 4, .effect_type = "ATTACK", .effect_value = 20}, // Mirip Triple Shot lama

// =================================================================
// ============== RARITY 5 (ID 501 - 505) - ULTIMATE ==============
// =================================================================
    {.skillID = 501, .nama = "Execute", .cooldown_max = 7, .rarity = 5, .effect_type = "ATTACK", .effect_value = 45},
    {.skillID = 502, .nama = "Emergency Mend", .cooldown_max = 9, .rarity = 5, .effect_type = "HEAL", .effect_value = 50} // Mirip Emergency Mend lama
};

const int JUMLAH_SKILL = sizeof(daftarSkill) / sizeof(daftarSkill[0]);

struct Chest daftarChest[] = {
    // =================================================================
    // ====================== RARITY 1 CHESTS ==========================
    // (Drop: 4 item Rarity 1, 1 item Rarity 2)
    // =================================================================
    {
        .chestID = 601, 
        .nama = "Peti Kayu Tua", 
        .rarity = 1, 
        .price = 100, 
        .drop_item_ids = {101, 120, 134, 137, 201}, // Hadiah: Short Sword (R2)
        .drop_count = 5
    },
    {
        .chestID = 602, 
        .nama = "Kantong Kulit Lusuh", 
        .rarity = 1, 
        .price = 110, 
        .drop_item_ids = {105, 131, 132, 138, 225}, // Hadiah: Chain Mail (R2)
        .drop_count = 5
    },
    {
        .chestID = 603, 
        .nama = "Kotak Perbekalan Goblin", 
        .rarity = 1, 
        .price = 90, 
        .drop_item_ids = {136, 139, 133, 135, 102}, // Hadiah: Perisai Besi (R2)
        .drop_count = 5
    },
    {
        .chestID = 604, 
        .nama = "Ransel Pengelana", 
        .rarity = 1, 
        .price = 120, 
        .drop_item_ids = {125, 101, 137, 138, 232}, // Hadiah: Kapak Tangan Besi (R2)
        .drop_count = 5
    },
    {
        .chestID = 605, 
        .nama = "Simpanan Bandit", 
        .rarity = 1, 
        .price = 150, 
        .drop_item_ids = {105, 134, 136, 139, 236}, // Hadiah: Pedang Lebar (R2)
        .drop_count = 5
    },

    // =================================================================
    // ====================== RARITY 2 CHESTS ==========================
    // (Drop: 4 item Rarity 2, 1 item Rarity 3)
    // =================================================================
    {
        .chestID = 611, 
        .nama = "Peti Besi Diperkuat", 
        .rarity = 2, 
        .price = 300, 
        .drop_item_ids = {201, 225, 232, 238, 301}, // Hadiah: Great Axe (R3)
        .drop_count = 5
    },
    {
        .chestID = 612, 
        .nama = "Kargo Penyelundup", 
        .rarity = 2, 
        .price = 350, 
        .drop_item_ids = {205, 231, 234, 236, 305}, // Hadiah: Katana Baja (R3)
        .drop_count = 5
    },
    {
        .chestID = 613, 
        .nama = "Peti Harta Karun Prajurit", 
        .rarity = 2, 
        .price = 320, 
        .drop_item_ids = {102, 233, 237, 239, 320}, // Hadiah: Steel Plate (R3)
        .drop_count = 5
    },
    {
        .chestID = 614, 
        .nama = "Kotak Persenjataan Barak", 
        .rarity = 2, 
        .price = 280, 
        .drop_item_ids = {201, 232, 235, 236, 331}, // Hadiah: Pedang Ksatria (R3)
        .drop_count = 5
    },
    {
        .chestID = 615, 
        .nama = "Warisan Terlupakan", 
        .rarity = 2, 
        .price = 400, 
        .drop_item_ids = {225, 234, 238, 102, 332}, // Hadiah: Baju Zirah Baja (R3)
        .drop_count = 5
    },

    // =================================================================
    // ====================== RARITY 3 CHESTS ==========================
    // (Drop: 4 item Rarity 3, 1 item Rarity 4)
    // =================================================================
    {
        .chestID = 621, 
        .nama = "Peti Baja Berukir", 
        .rarity = 3, 
        .price = 800, 
        .drop_item_ids = {301, 320, 331, 338, 401}, // Hadiah: Rune Sword (R4)
        .drop_count = 5
    },
    {
        .chestID = 622, 
        .nama = "Kotak Emas Terkunci", 
        .rarity = 3, 
        .price = 1000, 
        .drop_item_ids = {305, 325, 332, 335, 405}, // Hadiah: Halberd Energi (R4)
        .drop_count = 5
    },
    {
        .chestID = 623, 
        .nama = "Harta Karun Orc", 
        .rarity = 3, 
        .price = 750, 
        .drop_item_ids = {301, 334, 336, 339, 420}, // Hadiah: Mithril Mail (R4)
        .drop_count = 5
    },
    {
        .chestID = 624, 
        .nama = "Peti Simpanan Ksatria", 
        .rarity = 3, 
        .price = 900, 
        .drop_item_ids = {320, 331, 332, 337, 425}, // Hadiah: Shield of Aegis (R4)
        .drop_count = 5
    },
    {
        .chestID = 625, 
        .nama = "Relik dari Reruntuhan", 
        .rarity = 3, 
        .price = 950, 
        .drop_item_ids = {305, 325, 336, 338, 431}, // Hadiah: Pedang Api (R4)
        .drop_count = 5
    },

    // =================================================================
    // ====================== RARITY 4 CHESTS ==========================
    // (Drop: 4 item Rarity 4, 1 item Rarity 5)
    // =================================================================
    {
        .chestID = 631, 
        .nama = "Peti Kristal Ajaib", 
        .rarity = 4, 
        .price = 2500, 
        .drop_item_ids = {401, 420, 431, 436, 501}, // Hadiah: Dragon Blade (R5)
        .drop_count = 5
    },
    {
        .chestID = 632, 
        .nama = "Peti Harta Karun Elven", 
        .rarity = 4, 
        .price = 3000, 
        .drop_item_ids = {405, 425, 433, 437, 104}, // Hadiah: Pedang Legendary (R5)
        .drop_count = 5
    },
    {
        .chestID = 633, 
        .nama = "Simpanan Ahli Sihir", 
        .rarity = 4, 
        .price = 2800, 
        .drop_item_ids = {434, 435, 438, 439, 520}, // Hadiah: Godly Plate (R5)
        .drop_count = 5
    },
    {
        .chestID = 634, 
        .nama = "Peti Harta Karun Dwarven", 
        .rarity = 4, 
        .price = 3200, 
        .drop_item_ids = {420, 432, 436, 401, 525}, // Hadiah: Crown of Ancients (R5)
        .drop_count = 5
    },
    {
        .chestID = 635, 
        .nama = "Hadiah dari Kuil Kuno", 
        .rarity = 4, 
        .price = 3500, 
        .drop_item_ids = {405, 425, 431, 437, 531}, // Hadiah: Armor Sisik Naga (R5)
        .drop_count = 5
    },

    // =================================================================
    // ====================== RARITY 5 CHESTS ==========================
    // (Drop: 5 item Rarity 5)
    // =================================================================
    {
        .chestID = 641, 
        .nama = "Peti Harta Karun Naga", 
        .rarity = 5, 
        .price = 10000, 
        .drop_item_ids = {501, 520, 531, 532, 536},
        .drop_count = 5
    },
    {
        .chestID = 642, 
        .nama = "Peti Warisan Dewa", 
        .rarity = 5, 
        .price = 15000, 
        .drop_item_ids = {104, 525, 533, 534, 538},
        .drop_count = 5
    },
    {
        .chestID = 643, 
        .nama = "Peti Obsidian Berkilau", 
        .rarity = 5, 
        .price = 12000, 
        .drop_item_ids = {501, 535, 537, 539, 520},
        .drop_count = 5
    },
    {
        .chestID = 644, 
        .nama = "Peti Harta Karun Raja Iblis", 
        .rarity = 5, 
        .price = 20000, 
        .drop_item_ids = {104, 532, 531, 538, 525},
        .drop_count = 5
    },
    {
        .chestID = 645, 
        .nama = "Peti Takdir", 
        .rarity = 5, 
        .price = 25000, 
        .drop_item_ids = {534, 535, 536, 537, 539},
        .drop_count = 5
    }
};

const int JUMLAH_CHEST = sizeof(daftarChest) / sizeof(daftarChest[0]);