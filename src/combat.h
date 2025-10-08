// combat.h
#ifndef COMBAT_H
#define COMBAT_H

struct Monster;
// --- Prototipe Fungsi Pertarungan ---
void explore();
void start_fight(struct Monster musuh);
void lakukan_pertarungan(struct Monster musuh);
void monster_turn(struct Monster *musuh); // <--- FIX: Monster_turn
void kembali_ke_main(); // <--- FIX: kembali_ke_main

#endif