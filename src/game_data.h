#ifndef GAME_DATA_H
#define GAME_DATA_H
#define MAX_NAMA 50
#define MAX_INVENTORY_SLOTS 50
#define MAX_SKILLS_OWNED 10
#define MAX_SKILL_DROPS 4
#define MAX_CHEST_DROPS 5 // Maksimal 5 jenis item yang bisa dijatuhkan satu peti

// Definisi Struct baru untuk Loot Box/Chest
struct Chest {
    int chestID;
    char nama[MAX_NAMA];
    int rarity;      
    int price;      
    int drop_item_ids[MAX_CHEST_DROPS]; 
    int drop_count; 
};
// Definisi Struktur untuk Item
struct Item {
    int itemID;
    char nama[MAX_NAMA];
    int harga;
    int rarity; 
    char type[15];
    int stat_boost; 
};

// Definisi Struktur untuk Monster
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

// game_data.h
struct Skill {
    int skillID;
    char nama[MAX_NAMA];
    int cooldown_max;       // Cooldown maksimal dalam turn
    int rarity;             // BARU: Rarity Skill
    char effect_type[10];   // "HEAL" atau "ATTACK"
    int effect_value;       // Nilai efek (HP atau Damage tambahan)
};

struct InventorySlot {
    int itemID;     // ID item (untuk mencari di daftarItem global)
    int quantity;   // Jumlah item yang dimiliki
};

struct Player {
    char username[50];
    int HP;      
    int MAX_HP; 
    int ATK;
    int DEF;
    int LEVEL;
    int XP;
    int GOLD;

    int equipped_weapon_id;
    int bonus_atk;

    int equipped_armor_id; // <-- DITAMBAHKAN
    int bonus_def;      

    // Skill Cooldown (Pindahkan dari variabel global)
    int skill_1_cd;
    int skill_2_cd;
    int active_skill_1_index;
    int active_skill_2_index;

    // Inventory Array
    struct InventorySlot inventory[MAX_INVENTORY_SLOTS];
    int inventory_count; // Jumlah slot yang terisi (bukan jumlah item)

    int owned_skill_ids[MAX_SKILLS_OWNED]; // Array ID Skill yang dimiliki (misal: {101, 102, 0, ...})
    int owned_skill_count;
};

struct SkillBook {
    int bookID;
    char nama[MAX_NAMA];
    int rarity;
    int drop_skill_ids[MAX_SKILL_DROPS];
    int drop_count; // Selalu 4 untuk kasus ini
};

extern struct SkillBook daftarSkillBook[];
extern const int JUMLAH_SKILLBOOK;


// [Deklarasi Global]
extern struct Chest daftarChest[];
extern const int JUMLAH_CHEST;

extern struct Player mainPlayer; 

extern struct Skill daftarSkill[];
extern const int JUMLAH_SKILL;

extern struct Item daftarItem[];
extern const int JUMLAH_ITEM;

extern struct Monster daftarMonster[];
extern const int JUMLAH_MONSTER;

#endif