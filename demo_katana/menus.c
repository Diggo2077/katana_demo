#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//

#include "headers/katana.h"
#include "headers/artes.h"
#include "headers/combate.h"
#include "headers/menus.h"

// Menu Principal do Jogo

int menu_principal (int *capitulo) {

	int escolha_menu, zero = 0, resultado = 0;

    printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
    printf ("\n|M|E|N|U| |P|R|I|N|C|I|P|A|L|");
    printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");

	printf ("\n*---------------*");
	printf ("\n| 1 - CONTINUAR |");
	printf ("\n*---------------*");
	printf ("\n| 2 - NOVO JOGO |");
	printf ("\n*---------------*");
	printf ("\n| 3 - PRATICAR  |");
	printf ("\n*---------------*");
	printf ("\n| 4 - CRÉDITOS  |");
	printf ("\n*---------------*");
	printf ("\n| 5 - OPÇÕES    |");
	printf ("\n*---------------*");
    printf ("\n| 6 - SAIR      |");
    printf ("\n*---------------*\n");

    printf ("\n>>> Comando: ");
    
    do {

        scanf ("%d", &escolha_menu);
        fflush (stdin);

    } while (escolha_menu < 1 || escolha_menu > 6);

    switch (escolha_menu) {
    
        case 1:

            return 1;
            break;

        case 2:

            *capitulo = 1;
            return 0;
            break;

        case 3: 

            while (resultado != 1) {
        
                resultado = duelo (100, &zero, 100, &zero, 100,
                100, 100, &zero, "Miyamoto Musashi", 100, 100, 100, 100);
                if (resultado != 1) menu_combate ();

            } 
            break;

        case 4:

            ascii_art (0);
            break;
            
        case 5:
        
        	//menu_texto (&texto);
        	printf ("\nErro\n");
        	break;

        case 6:

            exit (0);
            break;

    }

    return menu_principal (capitulo);

}

// Função do Menu do Jogador

int menu_jogador (int *nivel, int *exp, int *atributos, int *vida, int *ataque, 
                  int *defesa, int *velocidade, int *resistencia, int *lesao, 
                  int *fadiga, int *vigor, int *ryos, int *medicinal, 
                  int *revigorante, int *potencializadora) {
    
    int escolha_jogador;

	printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+");
    printf ("\n|M|E|N|U| |D|O| |J|O|G|A|D|O|R|");
    printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+\n");

    printf ("\n*------------------*");
    printf ("\n| 1 - CONTINUAR    |");
    printf ("\n*------------------*");
    printf ("\n| 2 - INVENTÁRIO   |");
    printf ("\n*------------------*");
    printf ("\n| 3 - ATRIBUTOS    |");
    printf ("\n*------------------*");
    printf ("\n| 4 - SAIR DO JOGO |");
    printf ("\n*------------------*\n");

    printf ("\n>>> Comando: ");

    do {

        scanf ("%d", &escolha_jogador);
        fflush (stdin);

    } while (escolha_jogador < 1 || escolha_jogador > 4);

    switch (escolha_jogador) {

        case 1:

            return 0;
            break;

        case 2:

            inventario (ryos, medicinal, revigorante, potencializadora,
                        lesao, fadiga, vigor);
            break;

        case 3:

            atributs (nivel, exp, atributos, vida, ataque, 
                      defesa, velocidade, resistencia,
                      lesao, fadiga, vigor);
            break;

        case 4:

            exit (0);
            break;

    }

    return menu_jogador(nivel, exp, atributos, vida, ataque, 
                        defesa, velocidade, resistencia, lesao, 
                        fadiga, vigor, ryos, medicinal, 
                        revigorante, potencializadora);

}

// Função para Atualizar o Nível

int lvl (int *nivel, int *exp, int *atributos) {

    int old_nivel = *nivel;
    
    // Sistema de Níveis do Jogo

    if (*exp >= 0 && *exp <= 1000) {
        *nivel = 1;
    } else if (*exp >= 1000 && *exp < 3000) {
        *nivel = 2;
    } else if (*exp >= 3000 && *exp < 5000) {
        *nivel = 3;
    } else if (*exp >= 5000 && *exp < 7000) {
        *nivel = 4;
    } else if (*exp >= 7000 && *exp < 10000) {
        *nivel = 5;
    } else if (*exp >= 10000 && *exp < 25000) {
        *nivel = 6;
    } else if (*exp >= 25000 && *exp < 50000) {
        *nivel = 7;
    } else if (*exp >= 50000 && *exp < 75000) {
        *nivel = 8;
    } else if (*exp >= 75000 && *exp < 100000) {
        *nivel = 9;
    } else {
        *nivel = 10;
    } 

    if (*nivel != old_nivel) {

        printf ("\n+-+-+-+-+ +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
        printf ("\n|N|O|V|O| |N|Í|V|E|L| |A|L|C|A|N|Ç|A|D|O|");
        printf ("\n+-+-+-+-+ +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");

        *atributos += (*nivel - old_nivel); // A Cada Nível Ganho, +1 Atributo

        pause ();
        
    }

    return 0;

}

// Função para Acessar o Menu de Atributos

int atributs (int *nivel, int *exp, int *atributos, int *vida, int *ataque, 
              int *defesa, int *velocidade, int *resistencia,
              int *lesao, int *fadiga, int *vigor) {

    int escolha_atrbts;

    printf ("\n+-+-+-+-+-+ +-+ +-+-+-+-+-+-+-+-+-+");
    printf ("\n|N|Í|V|E|L| |E| |A|T|R|I|B|U|T|O|S|");
    printf ("\n+-+-+-+-+-+ +-+ +-+-+-+-+-+-+-+-+-+\n");

    printf ("\n*----------------------------------------*");
    printf ("\n|               Nível: %02d                |", *nivel);
    printf ("\n*----------------------------------------*");
    printf ("\n|         Experiência: %06d            |", *exp);
    printf ("\n*----------------------------------------*");
    printf ("\n| Pontos de Habilidades Disponíveis: %02d  |", *atributos);
    printf ("\n*----------------------------------------*\n");

    printf ("\n*-----------------------*");
    printf ("\n| Vida: %03d - %02d        |", *vida, *lesao);
    printf ("\n*-----------------------*");
    printf ("\n| Ataque: %03d + %02d      |", *ataque, *vigor);
    printf ("\n*-----------------------*");
    printf ("\n| Defesa: %03d           |", *defesa);
    printf ("\n*-----------------------*");
    printf ("\n| Velocidade: %03d       |", *velocidade);
    printf ("\n*-----------------------*");
    printf ("\n| Resistência: %03d - %02d |", *resistencia, *fadiga);
    printf ("\n*-----------------------*\n");

    if (*atributos > 0) {

        printf ("\n*---Pontos de Habilidade Disponíveis: %02d---*\n", *atributos);

        printf ("\n*-----------------*");
        printf ("\n| 1 - VIDA        |");
        printf ("\n*-----------------*");
        printf ("\n| 2 - ATAQUE      |");
        printf ("\n*-----------------*");
        printf ("\n| 3 - DEFESA      |");
        printf ("\n*-----------------*");
        printf ("\n| 4 - VELOCIDADE  |");
        printf ("\n*-----------------*");
        printf ("\n| 5 - RESISTÊNCIA |");
        printf ("\n*-----------------*");
        printf ("\n| 6 - SAIR        |");
        printf ("\n*-----------------*\n");

        printf ("\n>>> Comando: ");

        do {

            scanf ("%d", &escolha_atrbts);
            fflush (stdin);

        } while (escolha_atrbts < 1 || escolha_atrbts > 6);

        switch (escolha_atrbts) {

            case 1:

                printf ("\n\n*---VIDA +25---*\n\n");
                *vida += 25;
                *atributos -= 1;
                break;

            case 2:

                printf ("\n\n*---ATAQUE +25---*\n\n");
                *ataque += 25;
                *atributos -= 1;
                break;

            case 3:

                printf ("\n\n*---DEFESA +25---*\n\n");
                *defesa += 25;
                *atributos -= 1;
                break;

            case 4:

                printf ("\n\n*---VELOCIDADE +25---*\n\n");
                *velocidade += 25;
                *atributos -= 1;
                break;

            case 5:

                printf ("\n\n*---RESISTÊNCIA +25---*\n\n");
                *resistencia += 25;
                *atributos -= 1;
                break;

            case 6:

                return 0;

        }

        pause ();
        
        return atributs (nivel, exp, atributos, vida, ataque, defesa, velocidade, 
                         resistencia, lesao, fadiga, vigor);

    } else {

        
        pause ();
        
    }
        
    return 0;

}

// Função para Acessar a Loja

int loja (int *ryos, int *medicinal, int *revigorante, int *potencializadora) {

    int escolha_loja;

    printf ("\n+-+-+-+-+-+-+-+-+-+-+");
    printf ("\n|I|N|V|E|N|T|Á|R|I|O|");
    printf ("\n+-+-+-+-+-+-+-+-+-+-+\n");

    printf ("\n*---Ryōs: %03d---*\n", *ryos);

    printf ("\n*------------------------------*");
    printf ("\n| Ervas Medicinais: %d/5        |", *medicinal);
    printf ("\n*------------------------------*");
    printf ("\n| Ervas Revigorantes: %d/5      |", *revigorante);
    printf ("\n*------------------------------*");
    printf ("\n| Ervas Potencializadoras: %d/3 |", *potencializadora);
    printf ("\n*------------------------------*\n");

    printf ("\n+-+-+-+-+");
    printf ("\n|L|O|J|A|");
    printf ("\n+-+-+-+-+\n");

    printf ("\n*--------------------------------------*");
    printf ("\n| 1 - ERVAS MEDICINAIS: 10 Ryōs        |");
    printf ("\n*--------------------------------------*");
    printf ("\n| 2 - ERVAS REVIGORANTES: 10 Ryōs      |");
    printf ("\n*--------------------------------------*");
    printf ("\n| 3 - ERVAS POTENCIALIZADORAS: 20 Ryōs |");
    printf ("\n*--------------------------------------*");
    printf ("\n| 4 - SAIR                             |");
    printf ("\n*--------------------------------------*\n");

    printf ("\n>>> Comando: ");

    do {

        scanf ("%d", &escolha_loja);
        fflush (stdin);

    } while (escolha_loja < 1 || escolha_loja > 4);

    switch (escolha_loja) {

        case 1:

            if (*medicinal == 5) printf ("\n*---ESTOQUE CHEIO---*\n");
            else if (*ryos < 10) printf ("\n*---DINHEIRO INSUFICIENTE---*\n");
            else {
                *medicinal += 1;
                *ryos -= 10;
                printf ("\n\n*--- +1 ERVA MEDICINAL---*\n\n");
            }
            break;

        case 2:

            if (*revigorante == 5) printf ("\n\n*---ESTOQUE CHEIO---*\n\n");
            else if (*ryos < 10) printf ("\n\n*---DINHEIRO SUFICIENTE---*\n\n");
            else {
                *revigorante += 1;
                *ryos -= 10;
                printf ("\n\n*--- +1 ERVA REVIGORANTE---*\n\n");
            }
            break;

        case 3:

            if (*potencializadora == 3) printf ("\n\n*---ESTOQUE CHEIO---*\n\n");
            else if (*ryos < 20) printf ("\n\n*---DINHEIRO INSUFICIENTE---*\n\n");
            else {
                *potencializadora += 1;
                *ryos -= 20;
                printf ("\n\n*--- +1 ERVA POTENCIALIZADORA---*\n\n");
            }
            break;

        case 4:

            return 0;
    
    }


    pause ();

    return loja (ryos, medicinal, revigorante, potencializadora);

}

// Função para Acessar o Inventário

int inventario (int *ryos, int *medicinal, int *revigorante, int *potencializadora,
                int *lesao, int *fadiga, int *vigor) {

    int escolha_erva;

    printf ("\n+-+-+-+-+-+-+-+-+-+-+");
    printf ("\n|I|N|V|E|N|T|Á|R|I|O|");
    printf ("\n+-+-+-+-+-+-+-+-+-+-+\n");

    printf ("\n*---Ryōs: %03d---*\n", *ryos);

    printf ("\n*------------------------------*");
    printf ("\n| Ervas Medicinais: %d/5        |", *medicinal);
    printf ("\n*------------------------------*");
    printf ("\n| Ervas Revigorantes: %d/5      |", *revigorante);
    printf ("\n*------------------------------*");
    printf ("\n| Ervas Potencializadoras: %d/3 |", *potencializadora);
    printf ("\n*------------------------------*\n");

    printf ("\n*-----------------------------*");
    printf ("\n| 1 - ERVAS MEDICINAIS        |");
    printf ("\n*-----------------------------*");
    printf ("\n| 2 - ERVAS REVIGORANTES      |");
    printf ("\n*-----------------------------*");
    printf ("\n| 3 - ERVAS POTENCIALIZADORAS |");
    printf ("\n*-----------------------------*");
    printf ("\n| 4 - SAIR                    |");
    printf ("\n*-----------------------------*\n");

    printf ("\n>>> Comando: ");

    do {

        scanf ("%d", &escolha_erva);
        fflush (stdin);

    } while (escolha_erva < 1 || escolha_erva > 4);

    switch (escolha_erva) {

        case 1:

            if (*medicinal == 0) printf ("\n\n*---ERVAS INSUFICIENTES---*\n\n");
            else if (*lesao == 0) printf ("\n\n*---ENERGIA MÁXIMA---*\n\n");
            else {
                *medicinal -= 1;
                *lesao -= 100;
                if (*lesao < 0) *lesao = 0;
                printf ("\n\n*---LESÃO = %d---*", *lesao);
                printf ("\n\n*--- -1 ERVA MEDICINAL---*\n\n");
    
            }
            break;

        case 2:

            if (*revigorante == 0) printf ("\n\n*---ERVAS INSUFICIENTES---*\n\n");
            else if (*fadiga == 0) printf ("\n\n*---ENERGIA MÁXIMA---*\n\n");
            else {
                *revigorante -= 1;
                *fadiga -= 100;
                if (*fadiga < 0) *fadiga = 0;
                printf ("\n\n*---FADIGA = %d---*", *fadiga);
                printf ("\n\n*--- -1 ERVA REVIGORANTE---*\n\n");
            }
            break;

        case 3:

            if (*potencializadora == 0) printf ("\n\n*---ERVAS INSUFICIENTES---*\n\n");
            else if (*vigor == 25) printf ("\n\n*---EFEITO MÁXIMO ALCANÇADO---*\n\n");
            else {
                *potencializadora += 1;
                *vigor = 25;
                printf ("\n\n*---VIGOR = %d---*", *vigor);
                printf ("\n\n*--- -1 ERVA POTENCIALIZADORA---*\n\n");
            }
            break;

        case 4:

            return 0;
    
    }


    pause ();

    return inventario (ryos, medicinal, revigorante, potencializadora, lesao, fadiga, vigor);

}

int menu_combate () {

    int escolha_combate;

    printf ("\n*----------------------*");
    printf ("\n| 1 - TENTAR NOVAMENTE |");
    printf ("\n*----------------------*");
    printf ("\n| 2 - SAIR DO JOGO     |");
    printf ("\n*----------------------*\n");
    
    printf ("\n>>> Comando: ");

    do {

        scanf ("%d", &escolha_combate);
        fflush (stdin);

    } while (escolha_combate != 1 && escolha_combate != 2);

    switch (escolha_combate) {

        case 1:

            return 0;
            break;
        
        case 2:

            exit (0);
            break;

    }

    return 0;

}

int menu_cidade (int *exp, int *ryos, int *medicinal, int *revigorante, int *potencializadora) {

    int escolha_cidade;

    printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+");
    printf ("\n|M|E|N|U| |D|A| |C|I|D|A|D|E|");
    printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+\n");

    printf ("\n*------------------*");
    printf ("\n| 1 - CONTINUAR    |");
    printf ("\n*------------------*");
    printf ("\n| 2 - LOJA         |");
    printf ("\n*------------------*");
    printf ("\n| 3 - TREINAR      |");
    printf ("\n*------------------*");
    printf ("\n| 4 - SAIR DO JOGO |");
    printf ("\n*------------------*\n");
    
    printf ("\n>>> Comando: ");

    do {

        scanf ("%d", &escolha_cidade);
        fflush (stdin);

    } while (escolha_cidade < 1 || escolha_cidade > 4);

    switch (escolha_cidade) {

        case 1:

            return 0;
            break;
        
        case 2:

            loja (ryos, medicinal, revigorante, potencializadora);
            break;

        case 3:

            /*if (pratica == 1) {

                treino (exp, &pratica);

            } else {

                printf ("\nNão é hora de treinar!\n");

            }*/
            printf ("\nErro\n");
            break;

        case 4:

            exit (0);
            break;

    }

    return menu_cidade (exp, ryos, medicinal, revigorante, potencializadora);

}

/*int menu_texto (int *texto) {
	
	int escolha_txt = 0;
	
	printf ("\n*-----------------------------*");
    if (*texto == 1) printf ("\n| 1 - VELOCIDADE: INSTANTÂNEO |");
    else printf ("\n| 1 - VELOCIDADE: LENTA       |");
    printf ("\n*-----------------------------*");
    printf ("\n| 2 - SAIR                    |");
    printf ("\n*-----------------------------*\n");
    
    do {

        scanf ("%d", &escolha_txt);
        fflush (stdin);

    } while (escolha_txt != 1 && escolha_txt != 2);
    
    switch (escolha_txt) {
    
    	case 1:
    	
    		if (*texto == 1) texto = 0;
    		else *texto = 1;
    		break;
    		
    	case 2:
    	
    		return 0;
    		break;
    		
    }
    
    return menu_texto (texto); 

}*/
