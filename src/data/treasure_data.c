#include "skill_data.h"
#include "data/treasure_data.h"

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
    {
        .chestID = 651, 
        .nama = "Kotak Perkakas Tua", 
        .rarity = 1, 
        .price = 125, 
        .drop_item_ids = {160, 161, 131, 134, 260}, // Drop utama: Helm R1, Hadiah: Helm Prajurit (R2)
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
    {
        .chestID = 661, 
        .nama = "Peti Baja Milisi", 
        .rarity = 2, 
        .price = 380, 
        .drop_item_ids = {260, 262, 231, 201, 360}, // Drop utama: Helm R2, Hadiah: Helm Ksatria (R3)
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
    {
        .chestID = 671, 
        .nama = "Peti Perang Gladiator", 
        .rarity = 3, 
        .price = 950, 
        .drop_item_ids = {360, 362, 331, 301, 460}, // Drop utama: Helm R3, Hadiah: Helm Mithril (R4)
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
    {
        .chestID = 681, 
        .nama = "Warisan Komandan Jatuh", 
        .rarity = 4, 
        .price = 3300, 
        .drop_item_ids = {461, 463, 436, 405, 561}, // Drop utama: Helm R4, Hadiah: Mahkota Raja Kuno (R5)
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
    },
    {
        .chestID = 691, 
        .nama = "Peti Pusaka Surgawi", 
        .rarity = 5, 
        .price = 22000, 
        .drop_item_ids = {560, 562, 563, 538, 520}, 
        .drop_count = 5
    },
};

const int JUMLAH_CHEST = sizeof(daftarChest) / sizeof(daftarChest[0]);

// File: game_data.c

// (Tambahkan di dekat daftar global lainnya)
struct SkillBook daftarSkillBook[] = {
    // =================================================================
    // ====================== RARITY 1 BOOKS ===========================
    // =================================================================
    {
        .bookID = 801, .nama = "Buku Teknik Dasar", .rarity = 1,
        .drop_skill_ids = {101, 104, 110, 112}, // Quick Stab, Bash, Headbutt, Simple Shot
        .drop_count = 4
    },
    {
        .bookID = 802, .nama = "Catatan Pertolongan Pertama", .rarity = 1,
        .drop_skill_ids = {102, 103, 105, 111}, // Minor Heal, Deflect, Mend Wound, Patch Up
        .drop_count = 4
    },

    // =================================================================
    // ====================== RARITY 2 BOOKS ===========================
    // =================================================================
    {
        .bookID = 811, .nama = "Manual Taktik Ranger", .rarity = 2,
        .drop_skill_ids = {203, 208, 210, 212}, // Quick Shot, Aimed Shot, Double Strike, Hamstring
        .drop_count = 4
    },
    {
        .bookID = 812, .nama = "Ajaran Pelindung Suci", .rarity = 2,
        .drop_skill_ids = {202, 205, 207, 211}, // First Aid, Healing Light, Stone Skin, Protective Ward
        .drop_count = 4
    },

    // =================================================================
    // ====================== RARITY 3 BOOKS ===========================
    // =================================================================
    {
        .bookID = 821, .nama = "Codex Prajurit", .rarity = 3,
        .drop_skill_ids = {301, 303, 310, 312}, // Wild Swing, Shadow Strike, Sunder Armor, Cleave
        .drop_count = 4
    },
    {
        .bookID = 822, .nama = "Buku Mantra Alam", .rarity = 3,
        .drop_skill_ids = {302, 305, 309, 313}, // Regenerate, Greater Heal, Blessing, Holy Light
        .drop_count = 4
    },

    // =================================================================
    // ====================== RARITY 4 BOOKS ===========================
    // =================================================================
    {
        .bookID = 831, .nama = "Ensiklopedia Sihir Penghancur", .rarity = 4,
        .drop_skill_ids = {401, 404, 406, 410}, // Critical Focus, Fireball, Thunder Strike, Explosive Arrow
        .drop_count = 4
    },
    {
        .bookID = 832, .nama = "Kitab Pemulihan Agung", .rarity = 4,
        .drop_skill_ids = {402, 405, 409, 411}, // Mass Healing, Sanctuary, Circle of Healing, Aegis
        .drop_count = 4
    },

    // =================================================================
    // ====================== RARITY 5 BOOKS ===========================
    // =================================================================
    {
        .bookID = 841, .nama = "Grimoire Terlarang", .rarity = 5,
        .drop_skill_ids = {501, 503, 507, 509}, // Execute, Meteor Shower, Soul Rip, Annihilation
        .drop_count = 4
    },
    {
        .bookID = 842, .nama = "Gulungan Keajaiban", .rarity = 5,
        .drop_skill_ids = {502, 504, 508, 512}, // Emergency Mend, Divine Intervention, Phoenix Down, Miracle
        .drop_count = 4
    }
};

const int JUMLAH_SKILLBOOK = sizeof(daftarSkillBook) / sizeof(daftarSkillBook[0]);