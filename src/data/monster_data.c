#include "monster_data.h"

struct Monster daftarMonster[] = {
// =================================================================
// ============== RARITY 1 (ID 1001 - 1010) - UMUM ================
// HP 10 - 20 ============= ATK 3 - 5 ================== SKILL 5 - 6
// =================================================================
    { .monsterID = 1001, .nama = "Laba-Laba Kecil", .healthPoint = 12, .attackPower = 3, .rarity = 1, .skillPower = 5, .goldDrop = 6, .expDrop = 8, .is_quest_boss = 0 },
    { .monsterID = 1002, .nama = "Slime Hijau", .healthPoint = 18, .attackPower = 3, .rarity = 1, .skillPower = 5, .goldDrop = 5, .expDrop = 10, .is_quest_boss = 0 },
    { .monsterID = 1003, .nama = "Goblin Cilik", .healthPoint = 15, .attackPower = 4, .rarity = 1, .skillPower = 6, .goldDrop = 8, .expDrop = 7, .is_quest_boss = 0 },
    { .monsterID = 1004, .nama = "Kelelawar", .healthPoint = 13, .attackPower = 3, .rarity = 1, .skillPower = 5, .goldDrop = 7, .expDrop = 9, .is_quest_boss = 0 },
    { .monsterID = 1005, .nama = "Jamur Beracun", .healthPoint = 19, .attackPower = 3, .rarity = 1, .skillPower = 5, .goldDrop = 5, .expDrop = 6, .is_quest_boss = 0 },
    { .monsterID = 1006, .nama = "Tikus Hutan", .healthPoint = 16, .attackPower = 4, .rarity = 1, .skillPower = 5, .goldDrop = 10, .expDrop = 5, .is_quest_boss = 0 },
    { .monsterID = 1007, .nama = "Ulat Raksasa", .healthPoint = 15, .attackPower = 3, .rarity = 1, .skillPower = 5, .goldDrop = 6, .expDrop = 10, .is_quest_boss = 0 },
    { .monsterID = 1008, .nama = "Belalang Liar", .healthPoint = 17, .attackPower = 3, .rarity = 1, .skillPower = 5, .goldDrop = 9, .expDrop = 8, .is_quest_boss = 0 },
    { .monsterID = 1009, .nama = "Semut Prajurit", .healthPoint = 20, .attackPower = 4, .rarity = 1, .skillPower = 6, .goldDrop = 7, .expDrop = 7, .is_quest_boss = 0 },
    { .monsterID = 1010, .nama = "Cacing Tanah", .healthPoint = 14, .attackPower = 3, .rarity = 1, .skillPower = 5, .goldDrop = 5, .expDrop = 9, .is_quest_boss = 0 },

// =================================================================
// ============ RARITY 2 (ID 2001 - 2010) - TIDAK UMUM =============
// HP 25 - 45 ============= ATK 6 - 10 ================== SKILL 8-15
// =================================================================
    { .monsterID = 2001, .nama = "Serigala Hutan", .healthPoint = 30, .attackPower = 6, .rarity = 2, .skillPower = 8, .goldDrop = 20, .expDrop = 25, .is_quest_boss = 0 },
    { .monsterID = 2002, .nama = "Bandit Biasa", .healthPoint = 25, .attackPower = 6, .rarity = 2, .skillPower = 10, .goldDrop = 30, .expDrop = 15, .is_quest_boss = 0 },
    { .monsterID = 2003, .nama = "Skeleton Prajurit", .healthPoint = 28, .attackPower = 8, .rarity = 2, .skillPower = 6, .goldDrop = 18, .expDrop = 28, .is_quest_boss = 0 },
    { .monsterID = 2004, .nama = "Gargoyle Kecil", .healthPoint = 35, .attackPower = 7, .rarity = 2, .skillPower = 9, .goldDrop = 25, .expDrop = 20, .is_quest_boss = 0 },
    { .monsterID = 2005, .nama = "Beruang Muda", .healthPoint = 40, .attackPower = 7, .rarity = 2, .skillPower = 7, .goldDrop = 15, .expDrop = 30, .is_quest_boss = 0 },
    { .monsterID = 2006, .nama = "Slime Biru", .healthPoint = 32, .attackPower = 6, .rarity = 2, .skillPower = 10, .goldDrop = 22, .expDrop = 18, .is_quest_boss = 0 },
    { .monsterID = 2007, .nama = "Perompak", .healthPoint = 26, .attackPower = 6, .rarity = 2, .skillPower = 8, .goldDrop = 30, .expDrop = 15, .is_quest_boss = 0 },
    { .monsterID = 2008, .nama = "Zombie", .healthPoint = 25, .attackPower = 6, .rarity = 2, .skillPower = 6, .goldDrop = 15, .expDrop = 28, .is_quest_boss = 0 },
    { .monsterID = 2009, .nama = "Goblin Penjaga", .healthPoint = 27, .attackPower = 7, .rarity = 2, .skillPower = 9, .goldDrop = 28, .expDrop = 22, .is_quest_boss = 0 },
    { .monsterID = 2010, .nama = "Piranha Raksasa", .healthPoint = 25, .attackPower = 8, .rarity = 2, .skillPower = 7, .goldDrop = 20, .expDrop = 25, .is_quest_boss = 0 },

// =================================================================
// ============ RARITY 3 (ID 3001 - 3010) - LANGKA ================
// HP 50 - 80 ============= ATK 11 - 18 ================== SKILL 13-20
// =================================================================
    { .monsterID = 3001, .nama = "Orc Warlord", .healthPoint = 65, .attackPower = 14, .rarity = 3, .skillPower = 15, .goldDrop = 50, .expDrop = 60, .is_quest_boss = 0 },
    { .monsterID = 3002, .nama = "Penyihir Gelap", .healthPoint = 50, .attackPower = 11, .rarity = 3, .skillPower = 18, .goldDrop = 70, .expDrop = 35, .is_quest_boss = 0 },
    { .monsterID = 3003, .nama = "Minotaur Muda", .healthPoint = 80, .attackPower = 16, .rarity = 3, .skillPower = 11, .goldDrop = 40, .expDrop = 70, .is_quest_boss = 0 },
    { .monsterID = 3004, .nama = "Specter", .healthPoint = 55, .attackPower = 12, .rarity = 3, .skillPower = 17, .goldDrop = 65, .expDrop = 45, .is_quest_boss = 0 },
    { .monsterID = 3005, .nama = "Griffin Kecil", .healthPoint = 70, .attackPower = 13, .rarity = 3, .skillPower = 14, .goldDrop = 55, .expDrop = 55, .is_quest_boss = 0 },
    { .monsterID = 3006, .nama = "Golem Batu", .healthPoint = 75, .attackPower = 11, .rarity = 3, .skillPower = 11, .goldDrop = 35, .expDrop = 70, .is_quest_boss = 0 },
    { .monsterID = 3007, .nama = "Kesatria Jatuh", .healthPoint = 60, .attackPower = 14, .rarity = 3, .skillPower = 16, .goldDrop = 60, .expDrop = 50, .is_quest_boss = 0 },
    { .monsterID = 3008, .nama = "Harimau Saber", .healthPoint = 58, .attackPower = 15, .rarity = 3, .skillPower = 12, .goldDrop = 45, .expDrop = 65, .is_quest_boss = 0 },
    { .monsterID = 3009, .nama = "Slime Merah", .healthPoint = 52, .attackPower = 12, .rarity = 3, .skillPower = 18, .goldDrop = 70, .expDrop = 40, .is_quest_boss = 0 },
    { .monsterID = 3010, .nama = "Medusa", .healthPoint = 68, .attackPower = 13, .rarity = 3, .skillPower = 13, .goldDrop = 50, .expDrop = 60, .is_quest_boss = 0 },

// =================================================================
// ============ RARITY 4 (ID 4001 - 4010) - EPIC ===================
// HP 90 - 150 ============= ATK 20 - 30 ================== SKILL 20-30
// =================================================================
    { .monsterID = 4001, .nama = "Elder Dragon", .healthPoint = 130, .attackPower = 25, .rarity = 4, .skillPower = 25, .goldDrop = 120, .expDrop = 150, .is_quest_boss = 0 },
    { .monsterID = 4002, .nama = "Lich", .healthPoint = 95, .attackPower = 28, .rarity = 4, .skillPower = 30, .goldDrop = 150, .expDrop = 80, .is_quest_boss = 0 },
    { .monsterID = 4003, .nama = "Giant Cyclops", .healthPoint = 150, .attackPower = 26, .rarity = 4, .skillPower = 20, .goldDrop = 90, .expDrop = 140, .is_quest_boss = 0 },
    { .monsterID = 4004, .nama = "Chimera", .healthPoint = 110, .attackPower = 24, .rarity = 4, .skillPower = 28, .goldDrop = 130, .expDrop = 110, .is_quest_boss = 0 },
    { .monsterID = 4005, .nama = "Vampire Lord", .healthPoint = 120, .attackPower = 23, .rarity = 4, .skillPower = 26, .goldDrop = 110, .expDrop = 120, .is_quest_boss = 0 },
    { .monsterID = 4006, .nama = "Kraken Tentacle", .healthPoint = 140, .attackPower = 22, .rarity = 4, .skillPower = 22, .goldDrop = 80, .expDrop = 130, .is_quest_boss = 0 },
    { .monsterID = 4007, .nama = "Phoenix", .healthPoint = 90, .attackPower = 27, .rarity = 4, .skillPower = 29, .goldDrop = 140, .expDrop = 90, .is_quest_boss = 0 },
    { .monsterID = 4008, .nama = "Abyssal Horror", .healthPoint = 115, .attackPower = 21, .rarity = 4, .skillPower = 27, .goldDrop = 100, .expDrop = 150, .is_quest_boss = 0 },
    { .monsterID = 4009, .nama = "Raksasa Es", .healthPoint = 145, .attackPower = 24, .rarity = 4, .skillPower = 21, .goldDrop = 115, .expDrop = 135, .is_quest_boss = 0 },
    { .monsterID = 4010, .nama = "Raja Kobold", .healthPoint = 100, .attackPower = 23, .rarity = 4, .skillPower = 24, .goldDrop = 135, .expDrop = 105, .is_quest_boss = 0 },

// =================================================================
// ============ RARITY 5 (ID 5001 - 5010) - LEGENDARY/BOSS =========
// HP 180 - 300+ ============= ATK 35 - 50+ ================== SKILL 35-55
// =================================================================
    { .monsterID = 5001, .nama = "Archdemon", .healthPoint = 240, .attackPower = 40, .rarity = 5, .skillPower = 45, .goldDrop = 300, .expDrop = 350, .is_quest_boss = 0 },
    { .monsterID = 5002, .nama = "Ancient God", .healthPoint = 300, .attackPower = 38, .rarity = 5, .skillPower = 50, .goldDrop = 350, .expDrop = 180, .is_quest_boss = 0 }, // HP tinggi, ATK sedikit lebih rendah
    { .monsterID = 5003, .nama = "World Serpent", .healthPoint = 220, .attackPower = 42, .rarity = 5, .skillPower = 38, .goldDrop = 250, .expDrop = 300, .is_quest_boss = 0 },
    { .monsterID = 5004, .nama = "Titan Stone", .healthPoint = 280, .attackPower = 36, .rarity = 5, .skillPower = 40, .goldDrop = 200, .expDrop = 320, .is_quest_boss = 0 }, // HP tinggi, ATK standar
    { .monsterID = 5005, .nama = "Shadow King", .healthPoint = 200, .attackPower = 45, .rarity = 5, .skillPower = 48, .goldDrop = 320, .expDrop = 250, .is_quest_boss = 0 }, // HP standar, ATK tinggi
    { .monsterID = 5006, .nama = "Cosmic Horror", .healthPoint = 190, .attackPower = 39, .rarity = 5, .skillPower = 42, .goldDrop = 180, .expDrop = 340, .is_quest_boss = 0 },
    { .monsterID = 5007, .nama = "Queen Fairy", .healthPoint = 180, .attackPower = 35, .rarity = 5, .skillPower = 35, .goldDrop = 280, .expDrop = 280, .is_quest_boss = 0 }, // Di batas bawah
    { .monsterID = 5008, .nama = "The Destroyer", .healthPoint = 250, .attackPower = 50, .rarity = 5, .skillPower = 46, .goldDrop = 220, .expDrop = 330, .is_quest_boss = 0 }, // ATK Maksimal
    { .monsterID = 5009, .nama = "Divine Avatar", .healthPoint = 260, .attackPower = 37, .rarity = 5, .skillPower = 41, .goldDrop = 290, .expDrop = 290, .is_quest_boss = 0 },
    { .monsterID = 5010, .nama = "Time Keeper", .healthPoint = 270, .attackPower = 48, .rarity = 5, .skillPower = 49, .goldDrop = 270, .expDrop = 310, .is_quest_boss = 0 }, // HP tinggi, ATK tinggi

// --- WORLD QUEST BOSSES ---

    // --- Tahap 1: Ancaman Goblin (Rarity 1) ---
    // R1 Base (Avg HP ~15, Avg ATK ~3.5)
    { .monsterID = 6001, .nama = "Goblin Pengintai Grunt", .healthPoint = 17, .attackPower = 4, .rarity = 1, .skillPower = 7, .goldDrop = 100, .expDrop = 10, .is_quest_boss = 1 },
    { .monsterID = 6002, .nama = "Goblin Pelacak Jejak", .healthPoint = 18, .attackPower = 4, .rarity = 1, .skillPower = 7, .goldDrop = 100, .expDrop = 12, .is_quest_boss = 1 },
    { .monsterID = 6003, .nama = "Goblin Pemukul Brutal", .healthPoint = 20, .attackPower = 5, .rarity = 1, .skillPower = 8, .goldDrop = 100, .expDrop = 14, .is_quest_boss = 1 },
    { .monsterID = 6004, .nama = "Goblin Penjaga Pintu", .healthPoint = 21, .attackPower = 5, .rarity = 1, .skillPower = 8, .goldDrop = 100, .expDrop = 16, .is_quest_boss = 1 },
    { .monsterID = 6010, .nama = "Grak, Si Goblin Buas", .healthPoint = 23, .attackPower = 5, .rarity = 1, .skillPower = 9, .goldDrop = 500, .expDrop = 0, .is_quest_boss = 1 }, // Boss Utama R1

    // --- Tahap 2: Penjaga Makam (Rarity 2) ---
    // R2 Base (Avg HP ~30, Avg ATK ~7)
    { .monsterID = 6011, .nama = "Kerangka Penjaga Awam", .healthPoint = 33, .attackPower = 8, .rarity = 2, .skillPower = 10, .goldDrop = 200, .expDrop = 25, .is_quest_boss = 1 },
    { .monsterID = 6012, .nama = "Kerangka Prajurit Kuno", .healthPoint = 36, .attackPower = 8, .rarity = 2, .skillPower = 11, .goldDrop = 200, .expDrop = 30, .is_quest_boss = 1 },
    { .monsterID = 6013, .nama = "Kerangka Pengawal Elit", .healthPoint = 39, .attackPower = 9, .rarity = 2, .skillPower = 12, .goldDrop = 200, .expDrop = 35, .is_quest_boss = 1 },
    { .monsterID = 6014, .nama = "Letnan Kerangka", .healthPoint = 42, .attackPower = 10, .rarity = 2, .skillPower = 13, .goldDrop = 200, .expDrop = 40, .is_quest_boss = 1 },
    { .monsterID = 6020, .nama = "Kapten Krek, Tengkorak Penjaga", .healthPoint = 45, .attackPower = 11, .rarity = 2, .skillPower = 14, .goldDrop = 1000, .expDrop = 0, .is_quest_boss = 1 }, // Boss Utama R2

    // --- Tahap 3: Konstruksi Kuno (Rarity 3) ---
    // R3 Base (Avg HP ~65, Avg ATK ~13)
    { .monsterID = 6021, .nama = "Konstruk Batu Kecil", .healthPoint = 72, .attackPower = 14, .rarity = 3, .skillPower = 14, .goldDrop = 300, .expDrop = 50, .is_quest_boss = 1 },
    { .monsterID = 6022, .nama = "Konstruk Penjaga Menengah", .healthPoint = 78, .attackPower = 16, .rarity = 3, .skillPower = 15, .goldDrop = 300, .expDrop = 55, .is_quest_boss = 1 },
    { .monsterID = 6023, .nama = "Konstruk Pertahanan Besar", .healthPoint = 85, .attackPower = 17, .rarity = 3, .skillPower = 16, .goldDrop = 300, .expDrop = 60, .is_quest_boss = 1 },
    { .monsterID = 6024, .nama = "Konstruk Inti Energi", .healthPoint = 91, .attackPower = 18, .rarity = 3, .skillPower = 17, .goldDrop = 300, .expDrop = 65, .is_quest_boss = 1 },
    { .monsterID = 6030, .nama = "Golem Obsidian Buatan", .healthPoint = 98, .attackPower = 20, .rarity = 3, .skillPower = 18, .goldDrop = 1500, .expDrop = 0, .is_quest_boss = 1 }, // Boss Utama R3

    // --- Tahap 4: Utusan dari Balik Tabir (Rarity 4) ---
    // R4 Base (Avg HP ~115, Avg ATK ~24)
    { .monsterID = 6031, .nama = "Jejak Bayangan", .healthPoint = 127, .attackPower = 26, .rarity = 4, .skillPower = 28, .goldDrop = 400, .expDrop = 90, .is_quest_boss = 1 },
    { .monsterID = 6032, .nama = "Figur Kelam", .healthPoint = 138, .attackPower = 29, .rarity = 4, .skillPower = 30, .goldDrop = 400, .expDrop = 100, .is_quest_boss = 1 },
    { .monsterID = 6033, .nama = "Penampakan Mengerikan", .healthPoint = 150, .attackPower = 31, .rarity = 4, .skillPower = 32, .goldDrop = 400, .expDrop = 110, .is_quest_boss = 1 },
    { .monsterID = 6034, .nama = "Pelayan Kegelapan", .healthPoint = 161, .attackPower = 34, .rarity = 4, .skillPower = 34, .goldDrop = 400, .expDrop = 120, .is_quest_boss = 1 },
    { .monsterID = 6040, .nama = "Utusan Bayangan", .healthPoint = 173, .attackPower = 36, .rarity = 4, .skillPower = 36, .goldDrop = 2000, .expDrop = 0, .is_quest_boss = 1 }, // Boss Utama R4

    // --- Tahap 5: Sang Penguasa Retakan (Rarity 5) ---
    // R5 Base (Avg HP ~250, Avg ATK ~40)
    { .monsterID = 6041, .nama = "Imp Api Neraka", .healthPoint = 275, .attackPower = 44, .rarity = 5, .skillPower = 40, .goldDrop = 500, .expDrop = 200, .is_quest_boss = 1 },
    { .monsterID = 6042, .nama = "Prajurit Iblis Brutal", .healthPoint = 300, .attackPower = 48, .rarity = 5, .skillPower = 43, .goldDrop = 500, .expDrop = 220, .is_quest_boss = 1 },
    { .monsterID = 6043, .nama = "Penyihir Iblis", .healthPoint = 325, .attackPower = 52, .rarity = 5, .skillPower = 50, .goldDrop = 500, .expDrop = 240, .is_quest_boss = 1 },
    { .monsterID = 6044, .nama = "Jenderal Iblis", .healthPoint = 350, .attackPower = 56, .rarity = 5, .skillPower = 53, .goldDrop = 500, .expDrop = 260, .is_quest_boss = 1 },
    { .monsterID = 6050, .nama = "Archdemon Malakor", .healthPoint = 375, .attackPower = 60, .rarity = 5, .skillPower = 55, .goldDrop = 2500, .expDrop = 0, .is_quest_boss = 1 } // Boss Utama R5 (Final Boss)

};

const int JUMLAH_MONSTER = sizeof(daftarMonster) / sizeof(daftarMonster[0]);