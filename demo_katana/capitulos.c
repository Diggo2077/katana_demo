#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers/katana.h"
#include "headers/menus.h"
#include "headers/combate.h"
#include "headers/artes.h"
#include "headers/capitulos.h"

char caractere;

void background () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina0.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");

        pause ();

}

void capitulo1_1 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina1.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");

        pause ();

}

void capitulo1_2 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina2.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();

}

void capitulo1_3 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina3.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();

}

void capitulo1_4 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina4.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();
        
}

void capitulo1_5 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina5.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();

}

void capitulo2_1 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina6.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();

}

void capitulo2_2 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina7.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();

}

void capitulo2_3 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina8.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();

}

void capitulo2_4 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina9.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();

}

void capitulo3_1 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina10.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();
}

void capitulo3_2 () {

		int escolha_bk = 0;
		
		FILE *pagina;
        
        pagina = fopen ("paginas/pagina11.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();

		printf ("\n*----------------------------*");
		printf ("\n|           ESCOLHA          |");
		printf ("\n*----------------------------*");
		printf ("\n| 1 - MATAR SHISHIDO BAIKEN  |");
		printf ("\n*----------------------------*");
		printf ("\n| 2 - POUPAR SHISHIDO BAIKEN |");
		printf ("\n*----------------------------*\n");

		printf ("\n>>> Comando: ");

		do {

			scanf ("%d", &escolha_bk);
			fflush (stdin);
	
		} while (escolha_bk != 1 && escolha_bk != 2);

		if (escolha_bk == 2) {
 
		printf ("\n— Não vou te matar. Deixo que o destino decida seu fim. — disse Takeshi, virando-se e deixando Baiken");
		printf ("\npara trás.\n");

		} else {

		printf ("\nEm um golpe misericordioso, Takeshi tira a vida de Shishido Baiken. Logo depois, Takeshi segue sua jornada");
		printf ("\nrumo a Yonezawa.\n");

}

pause ();

}

void capitulo3_3 () {

FILE *pagina;
        
        pagina = fopen ("paginas/pagina12.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();

pause ();

}

void capitulo3_4 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina13.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();

}

void capitulo3_5 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina14.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();

}

void capitulo_final1_1 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina15.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();
}

void capitulo_final1_d () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina17-2.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();
}

void capitulo_final1_2 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina16.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();;

}

void capitulo_final1_3 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina17.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();

pause ();

}

void capitulo_final1_4 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina18.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();

}

void capitulo_final2 () {

		FILE *pagina;
        
        pagina = fopen ("paginas/pagina19.txt", "r");

        if (pagina == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");
            exit (1);

        }

        while ((caractere = fgetc (pagina)) != EOF) {

            printf("%c", caractere);
            usleep (15000);

        }

        fclose (pagina);
        
        printf ("\n");
        
        pause ();

}

int capitulo1 (int *capitulo, int *nivel, int *exp, int *atributos, int *ryos, int *medicinal, int *revigorante,
               int *potencializadora, int *vida, int *lesao, int *ataque, int *vigor, int *defesa,
               int *velocidade, int *resistencia, int *fadiga) {

    int resultado = 0;

    lvl (nivel, exp, atributos);

    background ();

    ascii_art (6);

    capitulo1_1 ();

    ascii_art (5);

    capitulo1_2 ();

    while (resultado != 1) {
        
        resultado = duelo (*vida, lesao, *ataque, vigor, *defesa,
        *velocidade, *resistencia, fadiga, "Asano Nagamoto", 100, 100, 100, 100);
        if (resultado != 1) menu_combate ();

    }

    pos_batalha (&resultado, exp, 12500, ryos, 10);
    lvl (nivel, exp, atributos);

    menu_jogador (nivel, exp, atributos, vida, ataque, 
                  defesa, velocidade, resistencia, lesao, 
                  fadiga, vigor, ryos, medicinal, 
                  revigorante, potencializadora);

    capitulo1_3 ();
            
    while (resultado != 1) {
        
        resultado = duelo (*vida, lesao, *ataque, vigor, *defesa,
        *velocidade, *resistencia, fadiga, "Hideyashi Shira", 100, 100, 100, 100);
        if (resultado != 1) menu_combate ();

    }

    pos_batalha (&resultado, exp, 12500, ryos, 10);
    lvl (nivel, exp, atributos);

    menu_jogador (nivel, exp, atributos, vida, ataque, 
                  defesa, velocidade, resistencia, lesao, 
                  fadiga, vigor, ryos, medicinal, 
                  revigorante, potencializadora);

    capitulo1_4 ();

    while (resultado != 1) {
        
        resultado = duelo_vs_3 (*vida, lesao, *ataque, vigor, *defesa,
        *velocidade, *resistencia, fadiga, "Shira", 100, 100, 100, 100);
        if (resultado != 1) menu_combate ();

    }

    pos_batalha (&resultado, exp, 12500, ryos, 30);
    lvl (nivel, exp, atributos);

    menu_jogador (nivel, exp, atributos, vida, ataque, 
                  defesa, velocidade, resistencia, lesao, 
                  fadiga, vigor, ryos, medicinal, 
                  revigorante, potencializadora);

    *capitulo = 2;

    return 0;
}

int capitulo2 (int *capitulo, int *nivel, int *exp, int *atributos, int *ryos, int *medicinal, int *revigorante,
               int *potencializadora, int *vida, int *lesao, int *ataque, int *vigor, int *defesa,
               int *velocidade, int *resistencia, int *fadiga) {

    int resultado = 0;

    ascii_art (7);

    menu_cidade (exp, ryos, medicinal, revigorante, potencializadora);

    capitulo2_1 ();

    while (resultado != 1) {
        
        resultado = duelo (*vida, lesao, *ataque, vigor, *defesa,
        *velocidade, *resistencia, fadiga, "Ono Yamato", 100, 100, 100, 100);
        if (resultado != 1) menu_combate ();

        }

    pos_batalha (&resultado, exp, 12500, ryos, 20);
    lvl (nivel, exp, atributos);

    menu_jogador (nivel, exp, atributos, vida, ataque, 
                  defesa, velocidade, resistencia, lesao, 
                  fadiga, vigor, ryos, medicinal, 
                  revigorante, potencializadora);

    capitulo2_2 ();

    while (resultado != 1) {
        
       resultado = duelo (*vida, lesao, *ataque, vigor, *defesa,
       *velocidade, *resistencia, fadiga, "Ono Tadaaki", 100, 100, 100, 100);
       if (resultado != 1) menu_combate ();

    }

    pos_batalha (&resultado, exp, 12500, ryos, 20);
    lvl (nivel, exp, atributos);

    menu_jogador (nivel, exp, atributos, vida, ataque, 
                  defesa, velocidade, resistencia, lesao, 
                  fadiga, vigor, ryos, medicinal, 
                  revigorante, potencializadora);

    capitulo2_3 ();

    while (resultado != 1) {
        
        resultado = duelo (*vida, lesao, *ataque, vigor, *defesa,
        *velocidade, *resistencia, fadiga, "Itō Ittōsai", 100, 100, 100, 100);
        if (resultado != 1) menu_combate ();

    }

    pos_batalha (&resultado, exp, 12500, ryos, 30);
    lvl (nivel, exp, atributos);

    menu_jogador (nivel, exp, atributos, vida, ataque, 
                  defesa, velocidade, resistencia, lesao, 
                  fadiga, vigor, ryos, medicinal, 
                  revigorante, potencializadora);

    capitulo2_4 ();

    *capitulo = 3;

    return 0;

}

int capitulo3 (int *capitulo, int *nivel, int *exp, int *atributos, int *ryos, int *medicinal, int *revigorante,
               int *potencializadora, int *vida, int *lesao, int *ataque, int *vigor, int *defesa,
               int *velocidade, int *resistencia, int *fadiga) {

	int resultado = 0, escolha_final = 0, escolha_final2 = 0;
	
	ascii_art (8);
	
	capitulo3_1 ();
	
	while (resultado != 1) {
        
        resultado = duelo (*vida, lesao, *ataque, vigor, *defesa,
        *velocidade, *resistencia, fadiga, "Shishido Baiken", 100, 100, 100, 100);
        if (resultado != 1) menu_combate ();

    }

    pos_batalha (&resultado, exp, 12500, ryos, 20);
    lvl (nivel, exp, atributos);

    menu_jogador (nivel, exp, atributos, vida, ataque, 
                  defesa, velocidade, resistencia, lesao, 
                  fadiga, vigor, ryos, medicinal, 
                  revigorante, potencializadora);
                  
	capitulo3_2 ();
	
	menu_cidade (exp, ryos, medicinal, revigorante, potencializadora);
	
	capitulo3_3 ();
	
	while (resultado != 1) {
        
        resultado = duelo (*vida, lesao, *ataque, vigor, *defesa,
        *velocidade, *resistencia, fadiga, "Uesugi Harunori", 100, 100, 100, 100);
        if (resultado != 1) menu_combate ();

    }

    pos_batalha (&resultado, exp, 12500, ryos, 20);
    lvl (nivel, exp, atributos);

    menu_jogador (nivel, exp, atributos, vida, ataque, 
                  defesa, velocidade, resistencia, lesao, 
                  fadiga, vigor, ryos, medicinal, 
                  revigorante, potencializadora);
	
	capitulo3_4 ();
	
	while (resultado != 1) {
        
        resultado = duelo (*vida, lesao, *ataque, vigor, *defesa,
        *velocidade, *resistencia, fadiga, "Uesugi Kagekatsu", 100, 100, 100, 100);
        if (resultado != 1) menu_combate ();

    }

    pos_batalha (&resultado, exp, 0, ryos, 20);
    lvl (nivel, exp, atributos);

    menu_jogador (nivel, exp, atributos, vida, ataque, 
                  defesa, velocidade, resistencia, lesao, 
                  fadiga, vigor, ryos, medicinal, 
                  revigorante, potencializadora);
                  
	capitulo3_5 ();

	printf ("\n*----------------------------*");
	printf ("\n|           ESCOLHA           |");
	printf ("\n*----------------------------*");
	printf ("\n| 1 - MATAR UESUGI KAGEKATSU  |");
	printf ("\n*----------------------------*");
	printf ("\n| 2 - POUPAR UESUGI KAGEKATSU |");
	printf ("\n*----------------------------*\n");

	printf ("\n>>> Comando: ");

	do {

		scanf ("%d", &escolha_final);
		fflush (stdin);
	
	} while (escolha_final != 1 && escolha_final != 2);
	
	if (escolha_final == 1) {
		
		ascii_art (10);
		
		capitulo_final1_1 ();
		
		while (resultado != 1) {
        
        	resultado = duelo_vs_10 (*vida, lesao, *ataque, vigor, *defesa,
        	*velocidade, *resistencia, fadiga, "Uesugi", 100, 100, 100, 100);
        	if (resultado != 1) {
        	
        		capitulo_final1_d ();
        		ascii_art (11);
        		*capitulo = 4;
        		return 0;
        	
        	}

    	}
    	
    	capitulo_final1_2 ();
    	
    	escolha_final = 0;
    	
    	printf ("\n*----------------------*");
		printf ("\n|        ESCOLHA       |");
		printf ("\n*----------------------*");
		printf ("\n| 1 - LUTAR ATÉ O FIM  |");
		printf ("\n*----------------------*");
		printf ("\n| 2 - DESISTIR         |");
		printf ("\n*----------------------*\n");

		printf ("\n>>> Comando: ");

		do {

			scanf ("%d", &escolha_final2);
			fflush (stdin);
	
		} while (escolha_final2 != 1 && escolha_final2 != 2);
		
		if (escolha_final2 == 1) {
    	
    		while (resultado != 1) {
        
        		resultado = duelo_vs_10 ((*vida / 2), lesao, (*ataque / 5), vigor, (*defesa / 5),
        		*velocidade, (*resistencia / 10), fadiga, "do Shogun", 500, 300, 200, 100);
        		if (resultado != 1) {
        	
        			capitulo_final1_3 ();
        			capitulo_final1_4 ();
        			ascii_art (11);
        			*capitulo = 4;
        			return 0;
        	
        		}

    		}
    		
    	} else {
    	
    		capitulo_final1_4 ();
        	ascii_art (11);
        	*capitulo = 4;
        	return 0;
        	
    	}
    	
	} else {
		
		ascii_art (9);
		capitulo_final2 ();
		ascii_art (11);
		*capitulo = 4;
		return 0;
	
	}
	
	*capitulo = 4;
	
	return 0;
	
}
