#include "skill_data.h"

struct Skill daftarSkill[] = {
// =================================================================
// ============== RARITY 1 (ID 101 - 113) - DASAR ==================
// =================================================================
    {.skillID = 101, .nama = "Quick Stab", .cooldown_max = 2, .rarity = 1, .effect_type = "ATTACK", .effect_value = 3},
    {.skillID = 102, .nama = "Minor Heal", .cooldown_max = 3, .rarity = 1, .effect_type = "HEAL", .effect_value = 5},
    {.skillID = 103, .nama = "Deflect", .cooldown_max = 2, .rarity = 1, .effect_type = "HEAL", .effect_value = 4},
    {.skillID = 104, .nama = "Bash", .cooldown_max = 3, .rarity = 1, .effect_type = "ATTACK", .effect_value = 4},
    {.skillID = 105, .nama = "Mend Wound", .cooldown_max = 4, .rarity = 1, .effect_type = "HEAL", .effect_value = 6},
    {.skillID = 106, .nama = "Throw Rock", .cooldown_max = 2, .rarity = 1, .effect_type = "ATTACK", .effect_value = 3},
    {.skillID = 107, .nama = "Guard", .cooldown_max = 3, .rarity = 1, .effect_type = "HEAL", .effect_value = 5},
    {.skillID = 108, .nama = "Trip", .cooldown_max = 2, .rarity = 1, .effect_type = "ATTACK", .effect_value = 3},
    {.skillID = 109, .nama = "Rally", .cooldown_max = 4, .rarity = 1, .effect_type = "HEAL", .effect_value = 7},
    {.skillID = 110, .nama = "Headbutt", .cooldown_max = 3, .rarity = 1, .effect_type = "ATTACK", .effect_value = 5},
    {.skillID = 111, .nama = "Patch Up", .cooldown_max = 3, .rarity = 1, .effect_type = "HEAL", .effect_value = 6},
    {.skillID = 112, .nama = "Simple Shot", .cooldown_max = 2, .rarity = 1, .effect_type = "ATTACK", .effect_value = 3},
    {.skillID = 113, .nama = "Encourage", .cooldown_max = 4, .rarity = 1, .effect_type = "HEAL", .effect_value = 5},

// =================================================================
// ============== RARITY 2 (ID 201 - 213) - STANDAR ===============
// =================================================================
    {.skillID = 201, .nama = "Power Slash", .cooldown_max = 3, .rarity = 2, .effect_type = "ATTACK", .effect_value = 7},
    {.skillID = 202, .nama = "First Aid", .cooldown_max = 4, .rarity = 2, .effect_type = "HEAL", .effect_value = 10},
    {.skillID = 203, .nama = "Quick Shot", .cooldown_max = 3, .rarity = 2, .effect_type = "ATTACK", .effect_value = 6},
    {.skillID = 204, .nama = "Shield Bash", .cooldown_max = 4, .rarity = 2, .effect_type = "ATTACK", .effect_value = 8},
    {.skillID = 205, .nama = "Healing Light", .cooldown_max = 5, .rarity = 2, .effect_type = "HEAL", .effect_value = 12},
    {.skillID = 206, .nama = "Fire Dart", .cooldown_max = 3, .rarity = 2, .effect_type = "ATTACK", .effect_value = 9},
    {.skillID = 207, .nama = "Stone Skin", .cooldown_max = 4, .rarity = 2, .effect_type = "HEAL", .effect_value = 11},
    {.skillID = 208, .nama = "Aimed Shot", .cooldown_max = 3, .rarity = 2, .effect_type = "ATTACK", .effect_value = 8},
    {.skillID = 209, .nama = "Soothing Mist", .cooldown_max = 5, .rarity = 2, .effect_type = "HEAL", .effect_value = 14},
    {.skillID = 210, .nama = "Double Strike", .cooldown_max = 4, .rarity = 2, .effect_type = "ATTACK", .effect_value = 10},
    {.skillID = 211, .nama = "Protective Ward", .cooldown_max = 5, .rarity = 2, .effect_type = "HEAL", .effect_value = 13},
    {.skillID = 212, .nama = "Hamstring", .cooldown_max = 3, .rarity = 2, .effect_type = "ATTACK", .effect_value = 7},
    {.skillID = 213, .nama = "Cure Wounds", .cooldown_max = 4, .rarity = 2, .effect_type = "HEAL", .effect_value = 12},

// =================================================================
// ============== RARITY 3 (ID 301 - 313) - KUAT ===================
// =================================================================
    {.skillID = 301, .nama = "Wild Swing", .cooldown_max = 4, .rarity = 3, .effect_type = "ATTACK", .effect_value = 15},
    {.skillID = 302, .nama = "Regenerate", .cooldown_max = 5, .rarity = 3, .effect_type = "HEAL", .effect_value = 18},
    {.skillID = 303, .nama = "Shadow Strike", .cooldown_max = 4, .rarity = 3, .effect_type = "ATTACK", .effect_value = 12},
    {.skillID = 304, .nama = "Whirlwind", .cooldown_max = 5, .rarity = 3, .effect_type = "ATTACK", .effect_value = 16},
    {.skillID = 305, .nama = "Greater Heal", .cooldown_max = 6, .rarity = 3, .effect_type = "HEAL", .effect_value = 20},
    {.skillID = 306, .nama = "Ice Shard", .cooldown_max = 4, .rarity = 3, .effect_type = "ATTACK", .effect_value = 14},
    {.skillID = 307, .nama = "Iron Will", .cooldown_max = 5, .rarity = 3, .effect_type = "HEAL", .effect_value = 19},
    {.skillID = 308, .nama = "Poison Stab", .cooldown_max = 4, .rarity = 3, .effect_type = "ATTACK", .effect_value = 13},
    {.skillID = 309, .nama = "Blessing", .cooldown_max = 6, .rarity = 3, .effect_type = "HEAL", .effect_value = 22},
    {.skillID = 310, .nama = "Sunder Armor", .cooldown_max = 5, .rarity = 3, .effect_type = "ATTACK", .effect_value = 17},
    {.skillID = 311, .nama = "Rejuvenation", .cooldown_max = 6, .rarity = 3, .effect_type = "HEAL", .effect_value = 21},
    {.skillID = 312, .nama = "Cleave", .cooldown_max = 4, .rarity = 3, .effect_type = "ATTACK", .effect_value = 15},
    {.skillID = 313, .nama = "Holy Light", .cooldown_max = 5, .rarity = 3, .effect_type = "HEAL", .effect_value = 20},

// =================================================================
// ============== RARITY 4 (ID 401 - 413) - ELITE ==================
// =================================================================
    {.skillID = 401, .nama = "Critical Focus", .cooldown_max = 5, .rarity = 4, .effect_type = "ATTACK", .effect_value = 24}, 
    {.skillID = 402, .nama = "Mass Healing", .cooldown_max = 6, .rarity = 4, .effect_type = "HEAL", .effect_value = 30}, 
    {.skillID = 403, .nama = "Triple Shot", .cooldown_max = 5, .rarity = 4, .effect_type = "ATTACK", .effect_value = 18}, 
    {.skillID = 404, .nama = "Fireball", .cooldown_max = 6, .rarity = 4, .effect_type = "ATTACK", .effect_value = 26}, 
    {.skillID = 405, .nama = "Sanctuary", .cooldown_max = 7, .rarity = 4, .effect_type = "HEAL", .effect_value = 35}, 
    {.skillID = 406, .nama = "Thunder Strike", .cooldown_max = 5, .rarity = 4, .effect_type = "ATTACK", .effect_value = 25}, 
    {.skillID = 407, .nama = "Barrier", .cooldown_max = 6, .rarity = 4, .effect_type = "HEAL", .effect_value = 32}, 
    {.skillID = 408, .nama = "Vanish", .cooldown_max = 5, .rarity = 4, .effect_type = "ATTACK", .effect_value = 20},
    {.skillID = 409, .nama = "Circle of Healing", .cooldown_max = 7, .rarity = 4, .effect_type = "HEAL", .effect_value = 38}, 
    {.skillID = 410, .nama = "Explosive Arrow", .cooldown_max = 6, .rarity = 4, .effect_type = "ATTACK", .effect_value = 28}, 
    {.skillID = 411, .nama = "Aegis", .cooldown_max = 7, .rarity = 4, .effect_type = "HEAL", .effect_value = 36}, 
    {.skillID = 412, .nama = "Blade Dance", .cooldown_max = 5, .rarity = 4, .effect_type = "ATTACK", .effect_value = 26}, 
    {.skillID = 413, .nama = "Restoration", .cooldown_max = 6, .rarity = 4, .effect_type = "HEAL", .effect_value = 34}, 

// =================================================================
// ============== RARITY 5 (ID 501 - 512) - ULTIMATE ===============
// =================================================================
    {.skillID = 501, .nama = "Execute", .cooldown_max = 7, .rarity = 5, .effect_type = "ATTACK", .effect_value = 40}, 
    {.skillID = 502, .nama = "Emergency Mend", .cooldown_max = 9, .rarity = 5, .effect_type = "HEAL", .effect_value = 50}, 
    {.skillID = 503, .nama = "Meteor Shower", .cooldown_max = 8, .rarity = 5, .effect_type = "ATTACK", .effect_value = 45}, 
    {.skillID = 504, .nama = "Divine Intervention", .cooldown_max = 10, .rarity = 5, .effect_type = "HEAL", .effect_value = 60}, 
    {.skillID = 505, .nama = "Dragon's Breath", .cooldown_max = 7, .rarity = 5, .effect_type = "ATTACK", .effect_value = 42}, 
    {.skillID = 506, .nama = "Final Stand", .cooldown_max = 9, .rarity = 5, .effect_type = "HEAL", .effect_value = 55}, 
    {.skillID = 507, .nama = "Soul Rip", .cooldown_max = 8, .rarity = 5, .effect_type = "ATTACK", .effect_value = 38}, 
    {.skillID = 508, .nama = "Phoenix Down", .cooldown_max = 10, .rarity = 5, .effect_type = "HEAL", .effect_value = 65}, 
    {.skillID = 509, .nama = "Annihilation", .cooldown_max = 7, .rarity = 5, .effect_type = "ATTACK", .effect_value = 48}, 
    {.skillID = 510, .nama = "Tree of Life", .cooldown_max = 9, .rarity = 5, .effect_type = "HEAL", .effect_value = 62}, 
    {.skillID = 511, .nama = "Obliterate", .cooldown_max = 8, .rarity = 5, .effect_type = "ATTACK", .effect_value = 46}, 
    {.skillID = 512, .nama = "Miracle", .cooldown_max = 12, .rarity = 5, .effect_type = "HEAL", .effect_value = 70}  
};

const int JUMLAH_SKILL = sizeof(daftarSkill) / sizeof(daftarSkill[0]);