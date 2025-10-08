// File: src/skill_data.h
#ifndef SKILL_DATA_H
#define SKILL_DATA_H
#include "game_data.h" // Diperlukan untuk MAX_NAMA

struct Skill {
    int skillID;
    char nama[MAX_NAMA];
    int cooldown_max;
    int rarity;
    char effect_type[10];
    int effect_value;
};

extern struct Skill daftarSkill[];
extern const int JUMLAH_SKILL;

#endif