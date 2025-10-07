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
    {.itemID = 103, .nama = "Ramuan Kecil", .harga = 25, .rarity = 1, .type = "CONSUMABLE", .stat_boost = 0 },

// =================================================================
// ============== RARITY 2 (TIDAK UMUM) - ATK/DEF +4 hingga +7 =====
// =================================================================
    {.itemID = 201, .nama = "Short Sword", .harga = 250, .rarity = 2, .type = "WEAPON", .stat_boost = 5 },
    {.itemID = 205, .nama = "Mace Berduri", .harga = 300, .rarity = 2, .type = "WEAPON", .stat_boost = 7 },
    {.itemID = 102, .nama = "Perisai Besi", .harga = 200, .rarity = 2, .type = "ARMOR", .stat_boost = 5 }, // Item lama
    {.itemID = 225, .nama = "Chain Mail", .harga = 350, .rarity = 2, .type = "ARMOR", .stat_boost = 7 },

// =================================================================
// ============== RARITY 3 (LANGKA) - ATK/DEF +8 hingga +12 ========
// =================================================================
    {.itemID = 301, .nama = "Great Axe", .harga = 800, .rarity = 3, .type = "WEAPON", .stat_boost = 10 },
    {.itemID = 305, .nama = "Katana Baja", .harga = 1000, .rarity = 3, .type = "WEAPON", .stat_boost = 12 },
    {.itemID = 320, .nama = "Steel Plate", .harga = 950, .rarity = 3, .type = "ARMOR", .stat_boost = 9 },
    {.itemID = 325, .nama = "Helm Bertanduk", .harga = 700, .rarity = 3, .type = "ARMOR", .stat_boost = 12 },

// =================================================================
// ============== RARITY 4 (EPIC) - ATK/DEF +13 hingga +20 =========
// =================================================================
    {.itemID = 401, .nama = "Rune Sword", .harga = 3500, .rarity = 4, .type = "WEAPON", .stat_boost = 16 },
    {.itemID = 405, .nama = "Halberd Energi", .harga = 4200, .rarity = 4, .type = "WEAPON", .stat_boost = 20 },
    {.itemID = 420, .nama = "Mithril Mail", .harga = 3800, .rarity = 4, .type = "ARMOR", .stat_boost = 18 },
    {.itemID = 425, .nama = "Shield of Aegis", .harga = 4500, .rarity = 4, .type = "ARMOR", .stat_boost = 20 },

// =================================================================
// ============== RARITY 5 (LEGENDARY) - ATK/DEF +25 hingga +40 ====
// =================================================================
    {.itemID = 501, .nama = "Dragon Blade", .harga = 9000, .rarity = 5, .type = "WEAPON", .stat_boost = 30 },
    // Pedang Legendary (Stat disesuaikan agar sesuai dengan skala Rarity 5)
    {.itemID = 104, .nama = "Pedang Legendary", .harga = 50000, .rarity = 5, .type = "WEAPON", .stat_boost = 35 }, 
    {.itemID = 520, .nama = "Godly Plate", .harga = 12000, .rarity = 5, .type = "ARMOR", .stat_boost = 30 },
    {.itemID = 525, .nama = "Crown of Ancients", .harga = 15000, .rarity = 5, .type = "ARMOR", .stat_boost = 40 }
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
    {.skillID = 1, .nama = "Minor Heal", .cooldown_max = 2, .effect_type = "HEAL", .effect_value = 5},
    {.skillID = 2, .nama = "Power Slash", .cooldown_max = 3, .effect_type = "ATTACK", .effect_value = 3},
    {.skillID = 3, .nama = "Defense Stance", .cooldown_max = 4, .effect_type = "HEAL", .effect_value = 10}, 
    {.skillID = 4, .nama = "Triple Shot", .cooldown_max = 5, .effect_type = "ATTACK", .effect_value = 8}, 
    {.skillID = 5, .nama = "Emergency Mend", .cooldown_max = 6, .effect_type = "HEAL", .effect_value = 25}
};

const int JUMLAH_SKILL = sizeof(daftarSkill) / sizeof(daftarSkill[0]);