// Bibliotecas Utilizadas

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 
#include <unistd.h> 

// Cabeçalhos

#include "headers/katana.h"
#include "headers/artes.h"
#include "headers/menus.h"
#include "headers/combate.h"
#include "headers/capitulos.h"

Progresso p;

int main (int argc, char const *argv[]) {

	int old;
    
    ascii_art (1); // Capa do Jogo

    old = menu_principal (&p.capitulo);

    if (old == 1) p = carregar_jogo (p);

    if (p.capitulo == 1) {

        inicial ();

        capitulo1 (&p.capitulo, &p.nivel, &p.exp, &p.atributos, &p.ryos, &p.medicinal, &p.revigorante,
                   &p.potencializadora, &p.vida, &p.lesao, &p.ataque, &p.vigor, &p.defesa,
                   &p.velocidade, &p.resistencia, &p.fadiga);
                   
        salvamento_manual (p);

    }
    
    if (p.capitulo == 2) {
    
    	capitulo2 (&p.capitulo, &p.nivel, &p.exp, &p.atributos, &p.ryos, &p.medicinal, &p.revigorante,
                   &p.potencializadora, &p.vida, &p.lesao, &p.ataque, &p.vigor, &p.defesa,
                   &p.velocidade, &p.resistencia, &p.fadiga);
                   
        salvamento_manual (p);
                   
    }
    
    if (p.capitulo == 3) {
    
    	capitulo3 (&p.capitulo, &p.nivel, &p.exp, &p.atributos, &p.ryos, &p.medicinal, &p.revigorante,
                   &p.potencializadora, &p.vida, &p.lesao, &p.ataque, &p.vigor, &p.defesa,
                   &p.velocidade, &p.resistencia, &p.fadiga);
                   
        salvamento_manual (p);
                   
    }

    return 0;
}

// Função para Salvar o Progresso

void salvar_jogo (Progresso p) {

    FILE *arquivo = fopen ("saves/save.dat", "wb");
    fwrite (&p, sizeof(Progresso), 1, arquivo);
    fclose (arquivo);

}

// Função para Carregar o Progresso

Progresso carregar_jogo (Progresso p) {
    
    FILE *arquivo = fopen ("saves/save.dat", "rb");

    if (arquivo == NULL) {

        printf ("\nErro ao abrir o arquivo!\n");
        
    }

    fread (&p, sizeof(Progresso), 1, arquivo);
    fclose (arquivo);
    return p;

}

// Função para o Usuário Salvar o Jogo

void salvamento_manual (Progresso p) {

    int escolha_save;

    printf ("\n\n*---DESEJA SALVAR O JOGO?---*\n");
    
    printf ("\n*------------*");
	printf ("\n| 1 - SALVAR |");
	printf ("\n*------------*");
	printf ("\n| 2 - PULAR  |");
	printf ("\n*------------*\n");
	
    printf ("\n>>> Comando: ");
    
    do {

        scanf ("%d", &escolha_save);
        fflush (stdin);

    } while (escolha_save != 1 && escolha_save != 2);
    
    if (escolha_save == 1) {

        salvar_jogo (p);
        printf ("\n\n*---JOGO SALVO COM SUCESSO!---*\n\n");
        pause ();

    }

}

int pause () {

    int enter;
    
    printf ("\nInsira qualquer número e pressione ENTER para continuar: ");
	scanf ("%d", &enter);
	fflush (stdin);

    return 0;

}

void inicial () {

    p.nivel = 1;
    p.exp = 0;
    p.atributos = 0;
    p.ryos = 0;
    p.medicinal = 0;
    p.revigorante = 0;
    p.potencializadora = 0;
    p.vida = 100;
    p.lesao = 0;
    p.ataque = 100;
    p.vigor = 0;
    p.defesa = 100;
    p.velocidade = 100;
    p.resistencia = 100;
    p.fadiga = 0;
    p.capitulo = 1;

}
