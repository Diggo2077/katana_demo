#include <stdio.h>
#include <unistd.h>
#include "headers/artes.h"

// Função das Artes - Fonte: Emoji Combos

void ascii_art (int n) {

    char caractere;
	
    if (n == 1) {

        FILE *capa;
        
        capa = fopen ("artes/capa.txt", "r");

        if (capa == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");

            return;
        }

        while ((caractere = fgetc (capa)) != EOF) {

            printf("%c", caractere);
            usleep (250);

        }

        fclose (capa);

		printf ("\n\n*---BEM-VINDO AO MUNDO DE KATANA---*\n");

        pause ();
		
	} else if (n == 2) {
        
        FILE *duelo;
        
        duelo = fopen ("artes/duelo.txt", "r");

        if (duelo == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");

            return;
        }

        while ((caractere = fgetc (duelo)) != EOF) {

            printf ("%c", caractere);
            usleep (250);

        }

        fclose (duelo);

        pause ();

	} else if (n == 3) {
	        
        FILE *vitoria;
        
        vitoria = fopen ("artes/vitoria.txt", "r");

        if (vitoria == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");

            return;
        }

        while ((caractere = fgetc (vitoria)) != EOF) {

            printf ("%c", caractere);
            usleep (250);

        }

        fclose (vitoria);

		pause ();
	
    } else if (n == 4) {
	        
        FILE *derrota;
        
        derrota = fopen ("artes/derrota.txt", "r");

        if (derrota == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");

            return;
        }

        while ((caractere = fgetc (derrota)) != EOF) {

            printf ("%c", caractere);
            usleep (250);

        }

        fclose (derrota);

		pause ();
		
	} else if (n == 5) {
       
        FILE *escarlate;
        
        escarlate = fopen ("artes/escarlate.txt", "r");

        if (escarlate == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");

            return;
        }

        while ((caractere = fgetc (escarlate)) != EOF) {

            printf ("%c", caractere);
            usleep (250);

        }

        fclose (escarlate);

		pause ();
		
	} else if (n == 6) {
        
        FILE *parte1;
        
        parte1 = fopen ("artes/parte1.txt", "r");

        if (parte1 == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");

            return;
        }

        while ((caractere = fgetc (parte1)) != EOF) {

            printf ("%c", caractere);
            usleep (250);

        }

        fclose (parte1);

		pause ();
		
	} else if (n == 7) {
        
        FILE *parte2;
        
        parte2 = fopen ("artes/parte2.txt", "r");

        if (parte2 == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");

            return;
        }

        while ((caractere = fgetc (parte2)) != EOF) {

            printf ("%c", caractere);
            usleep (250);

        }

        fclose (parte2);

		pause ();
		
	} else if (n == 8) {
	        
        FILE *parte3;
        
        parte3 = fopen ("artes/parte3.txt", "r");

        if (parte3 == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");

            return;
        }

        while ((caractere = fgetc (parte3)) != EOF) {

            printf ("%c", caractere);
            usleep (250);

        }

        fclose (parte3);

		pause ();
		
	} else if (n == 9) {
        
        FILE *final1;
        
        final1 = fopen ("artes/final1.txt", "r");

        if (final1 == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");

            return;
        }

        while ((caractere = fgetc (final1)) != EOF) {

            printf ("%c", caractere);
            usleep (250);

        }

        fclose (final1);

		pause ();
	
	} else if (n == 10) {
        
        FILE *final2;
        
        final2 = fopen ("artes/final2.txt", "r");

        if (final2 == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");

            return;
        }

        while ((caractere = fgetc (final2)) != EOF) {

            printf ("%c", caractere);
            usleep (250);

        }

        fclose (final2);

        pause ();

	} else if (n == 11) {
        
        FILE *game_over;
        
        game_over = fopen ("artes/game_over.txt", "r");

        if (game_over == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");

            return;
        }

        while ((caractere = fgetc (game_over)) != EOF) {

            printf ("%c", caractere);
            usleep (250);

        }

        fclose (game_over);

        pause ();

    } else {
        
        FILE *creditos;
        
        creditos = fopen ("artes/creditos.txt", "r");

        if (creditos == NULL) {

            printf ("\nErro ao abrir o arquivo!\n");

            return;
        }

        while ((caractere = fgetc (creditos)) != EOF) {

            printf ("%c", caractere);
            usleep (250);

        }

        fclose (creditos);

        pause ();

    }
		
}
