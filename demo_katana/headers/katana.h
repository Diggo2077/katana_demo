#ifndef KATANA_H
#define KATANA_H

typedef struct Progresso_ {

    int nivel;
    int exp;
    int atributos;
    int ryos;
    int medicinal;
    int revigorante;
    int potencializadora;
    int vida;
    int lesao;
    int ataque;
    int vigor;
    int defesa;
    int velocidade;
    int resistencia;
    int fadiga;
    int capitulo;

} Progresso;

void salvar_jogo (Progresso p);

Progresso carregar_jogo (Progresso p);

void salvamento_manual (Progresso p);

void inicial ();

int pause ();

int main (int argc, char const *argv[]);


#endif
