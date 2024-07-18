#ifndef MENUS_H
#define MENUS_H

int menu_principal (int *capitulo);

int menu_jogador (int *nivel, int *exp, int *atributos, int *vida, int *ataque, 
                  int *defesa, int *velocidade, int *resistencia, int *lesao, 
                  int *fadiga, int *vigor, int *ryos, int *medicinal, 
                  int *revigorante, int *potencializadora);

int lvl (int *nivel, int *exp, int *atributos);

int atributs (int *nivel, int *exp, int *atributos, int *vida, int *ataque, 
              int *defesa, int *velocidade, int *resistencia,
              int *lesao, int *fadiga, int *vigor);

int loja (int *ryos, int *medicinal, int *revigorante, int *potencializadora);

int inventario (int *ryos, int *medicinal, int *revigorante, int *potencializadora,
                int *lesao, int *fadiga, int *vigor);

int menu_combate ();

int menu_cidade (int *exp, int *ryos, int *medicinal, int *revigorante, int *potencializadora);

// int menu_texto (int *texto);

#endif
