// File: src/quest.h
#ifndef QUEST_H
#define QUEST_H

// Prototipe fungsi quest
void show_world_quest_status();
void challenge_quest_boss();
void handle_quest_boss_victory(int defeated_monster_rarity, int is_main_boss); // 0=sub, 1=main

#endif