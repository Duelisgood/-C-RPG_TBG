#include "item_data.h"
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
    // -- Book --
    {.itemID = 80, .nama = "Buku Teknik Dasar", .harga = 150, .rarity = 1, .type = "BOOK", .stat_boost = 801},
    {.itemID = 83, .nama = "Catatan Pertolongan Pertama", .harga = 160, .rarity = 1, .type = "BOOK", .stat_boost = 802},

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
    // -- Book --
    {.itemID = 84, .nama = "Manual Taktik Ranger", .harga = 500, .rarity = 2, .type = "BOOK", .stat_boost = 811},
    {.itemID = 85, .nama = "Ajaran Pelindung Suci", .harga = 550, .rarity = 2, .type = "BOOK", .stat_boost = 812},

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
    // -- Book --
    {.itemID = 81, .nama = "Codex Prajurit", .harga = 1200, .rarity = 3, .type = "BOOK", .stat_boost = 821},
    {.itemID = 86, .nama = "Buku Mantra Alam", .harga = 1300, .rarity = 3, .type = "BOOK", .stat_boost = 822},


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
    // -- Book --
    {.itemID = 87, .nama = "Ensiklopedia Sihir Penghancur", .harga = 4000, .rarity = 4, .type = "BOOK", .stat_boost = 831},
    {.itemID = 88, .nama = "Kitab Pemulihan Agung", .harga = 4200, .rarity = 4, .type = "BOOK", .stat_boost = 832},


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
    // -- Book --
    {.itemID = 82, .nama = "Grimoire Terlarang", .harga = 30000, .rarity = 5, .type = "BOOK", .stat_boost = 841},
    {.itemID = 89, .nama = "Gulungan Keajaiban", .harga = 32000, .rarity = 5, .type = "BOOK", .stat_boost = 842},
};


const int JUMLAH_ITEM = sizeof(daftarItem) / sizeof(daftarItem[0]);