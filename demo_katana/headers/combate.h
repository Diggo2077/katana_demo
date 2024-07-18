#ifndef COMBATE_H
#define COMBATE_H


int duelo (int vida, int *lesao, int ataque, int *vigor, int defesa, int velocidade,
           int resistencia, int *fadiga, char nome[], int inim_vida, int inim_ataque, int inim_defesa, 
           int inim_velocidade);

int duelo_vs_3 (int vida, int *lesao, int ataque, int *vigor, int defesa, int velocidade,
           int resistencia, int *fadiga, char nome[], int inim_vida, int inim_ataque, int inim_defesa, 
           int inim_velocidade);
           
int duelo_vs_10 (int vida, int *lesao, int ataque, int *vigor, int defesa, int velocidade,
           		int resistencia, int *fadiga, char nome[], int inim_vida, int inim_ataque, int inim_defesa, 
           		int inim_velocidade);

void treino (int *exp, int *pratica);

void pos_batalha (int *resultado, int *exp, int xp, int *ryos, int moedas);

#endif
