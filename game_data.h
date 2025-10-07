#ifndef GAME_DATA_H
#define GAME_DATA_H
#define MAX_NAMA 50
#define MAX_INVENTORY_SLOTS 50

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

struct Skill {
    int skillID;
    char nama[MAX_NAMA];
    int cooldown_max;       // Cooldown maksimal dalam turn
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
};


// [Deklarasi Global]
extern struct Player mainPlayer; 

extern struct Skill daftarSkill[];
extern const int JUMLAH_SKILL;

extern struct Item daftarItem[];
extern const int JUMLAH_ITEM;

extern struct Monster daftarMonster[];
extern const int JUMLAH_MONSTER;

#endif