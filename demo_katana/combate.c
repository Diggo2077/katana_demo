#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "headers/artes.h"
#include "headers/combate.h"

// Função das Batalhas do Jogo

int duelo (int vida, int *lesao, int ataque, int *vigor, int defesa, int velocidade,
           int resistencia, int *fadiga, char nome[], int inim_vida, int inim_ataque, int inim_defesa, 
           int inim_velocidade) {
		   
		   int escolha_luta, rodada = 1, dano, esquiva = 0, bonus_dano = 0, 
               ferida = vida - *lesao, cansaco = resistencia - *fadiga;
		   
           ascii_art (2);

		   srand (time(NULL));

           vida = vida * 10;
           vida -= *lesao;
           resistencia -= *fadiga;
           inim_vida = inim_vida * 10;

           while (vida != 0 || inim_vida != 0) {

               printf ("\n\n+-+-+-+-+-+-+ +--+");
               printf ("\n|R|O|D|A|D|A| |%02d|", rodada);
               printf ("\n+-+-+-+-+-+-+ +--+\n");

               if (velocidade > inim_velocidade || velocidade == inim_velocidade) {

                   printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+");
                   printf ("\n|M|E|N|U| |D|A| |B|A|T|A|L|H|A|");
                   printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+\n");

                   printf ("\n*---------------------------------------*");
                   printf ("\n| 1 - ATACAR / -30PTS DE RESISTÊNCIA    |");
                   printf ("\n*---------------------------------------*");
                   printf ("\n| 2 - DEFENDER / -5PTS DE RESISTÊNCIA  |");
                   printf ("\n*---------------------------------------*");
                   printf ("\n| 3 - DESCANSAR / +25PTS DE RESISTÊNCIA |");
                   printf ("\n*---------------------------------------*\n");

                   printf ("\n*---RESISTÊNCIA: %d---*\n", resistencia);

                   printf ("\n\n>>> Comando: ");

                   do {

                       scanf ("%d", &escolha_luta);
                       fflush (stdin);

                   } while (escolha_luta < 1 || escolha_luta > 3);
                   
                   if (escolha_luta == 1 && resistencia < 20) {
                       
                       escolha_luta = 3;

                       printf ("\n\n*---VIGOR INSUFICIENTE!---*\n");

                       printf ("\n\n>>> Takeshi está vulnerável...\n");
                   
                   }
                   
                   if (escolha_luta == 2 && resistencia < 10) {
                       
                       escolha_luta = 3;

                       printf ("\n\n*---VIGOR INSUFICIENTE!---*\n");

                       printf ("\n\n>>> Takeshi está vulnerável...\n");
                   
                   }

                   switch (escolha_luta) {

                       case 1: 

                           resistencia -= 30;
                           if (resistencia < 0) resistencia = 0;

                           printf ("\n\n>>> Takeshi ataca o %s com sua Katana...\n\n", nome);

                           dano = (ataque + *vigor) + (rand() % 30);
                           dano = dano < 0 ? 0 : dano;
                           dano -= (inim_defesa / 5);
                           dano = dano + bonus_dano;
                           inim_vida -= dano;
                           bonus_dano = 0;
                           if (inim_vida < 0) inim_vida = 0;

                           printf ("\n...Takeshi inflige %d de dano a %s...\n", dano, nome);

                           printf ("\n\n*---Vida de %s: %d---*\n", nome, inim_vida);
                           
                           if (inim_vida == 0) {
                       
                               printf ("\n\n*---%s foi derrotado!---*", nome);
                               
                               /**fadiga += (resistencia - cansaco) / 10;
                               if (*fadiga < 0) *fadiga = 0;
                               *lesao += (vida - ferida) / 10;
                               if (*lesao < 0) *lesao = 0;*/ 
                               *vigor = 0;

                               ascii_art (3);
                       
                       	       return 1;
                       
                           }

                           break;

                        case 2:
                        
                           resistencia -= 5;
                           if (resistencia < 0) resistencia = 0;

                           printf ("\n\n>>> Takeshi planeja se defender do ataque de %s...\n", nome);

                           esquiva = (defesa / 5) + (velocidade / 5) + (rand() % 50);
                           esquiva = esquiva < 0 ? 0 : esquiva;
                           if (bonus_dano < 150) bonus_dano += 50;

                           printf ("\n\n*---BÔNUS DE DEFESA: %d---*\n", esquiva);

                           printf ("\n*---BÔNUS DE DANO: %d---*\n", bonus_dano);

                           break;
                           
                        case 3:
                        
                           resistencia += 25;
                           if (resistencia > cansaco) resistencia = cansaco;

                           printf ("\n\n>>> Takeshi está vulnerável...\n");

                           break;

                   }
                   
                   printf ("\n\n*---%s avança para cima de Takeshi---*\n\n", nome);
				   
                   printf ("\n>>> %s irá atacar...\n\n", nome);

                   dano = inim_ataque + (rand() % 15);
                   dano = dano < 0 ? 0 : dano;
                   if (esquiva > 0) dano -= esquiva;
                   dano -= (defesa / 5);
                   vida -= dano;
                   if (vida < 0) vida = 0;
                   esquiva = 0;

                   printf ("\n...%s inflige %d de dano a Takeshi\n", nome, dano);
                   
                   printf ("\n\n*---Vida de Takeshi: %d---*\n", vida);
                   
                   if (vida == 0) {

                       printf ("\n>>> Takeshi foi derrotado!\n");

                       ascii_art (4);
                       
                       return 2;
                       
                   } 
                   
                   } else {
                       
                       printf ("\n\n*---%s avança para cima de Takeshi---*\n\n", nome);
               	   
               	       printf ("\n>>> %s irá atacar...\n\n", nome);

                       dano = inim_ataque + (rand() % 15);
                       dano = dano < 0 ? 0 : dano;
                       if (esquiva > 0) dano -= esquiva;
                       dano -= (defesa / 5);
                       vida -= dano;
                       if (vida < 0) vida = 0;
                       esquiva = 0;

                       printf ("\n>>> %s inflige %d de dano a Takeshi\n", nome, dano);

                       printf ("\n\n*---Vida de Takeshi: %d---*\n", vida);

                       if (vida == 0) {
                       
                           printf ("\n>>> Takeshi foi derrotado!\n");

                           ascii_art (4);
                       
                           return 2;
                       
                        } 
                        
                       printf ("\n\n*---Vez de Takeshi---*\n\n");
                   
                       printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+");
                       printf ("\n|M|E|N|U| |D|A| |B|A|T|A|L|H|A|");
                       printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+\n");
                       
                       printf ("\n*--------------------------------------*");
                       printf ("\n| 1 - ATACAR / -30PTS DE RESISTÊNCIA   |");
                       printf ("\n*--------------------------------------*");
                       printf ("\n| 2 - DEFENDER / -10PTS DE RESISTÊNCIA |");
                       printf ("\n*--------------------------------------*");
                       printf ("\n| 3 - DESCANSAR / +20PTS DE RESISTÊNCIA |");
                       printf ("\n*---------------------------------------*\n");


                       printf ("\n*---RESISTÊNCIA: %d---*\n", resistencia - *fadiga);

                       printf ("\n\n>>> Comando: ");

                       do {

                           scanf ("%d", &escolha_luta);
                           fflush (stdin);

                       } while (escolha_luta < 1 || escolha_luta > 3);
                   
                       if (escolha_luta == 1 && resistencia < 20) {
                       
                           escolha_luta = 3;

                           printf ("\n\n>>> Vigor insuficiente!\n");

                           printf ("\n\n>>> Takeshi está vulnerável...\n");
                   
                        }
                   
                       if (escolha_luta == 2 && resistencia < 10) {
                       
                           escolha_luta = 3;

                           printf ("\n\n>>> Vigor insuficiente!\n");

                           printf ("\n\n>>> Takeshi está vulnerável...\n");
                   
                       }

                       switch (escolha_luta) {

                           case 1:

                               resistencia -= 30;
                               if (resistencia < 0) resistencia = 0;

                               printf ("\n\n>>> Takeshi ataca o %s com sua Katana...\n", nome);

                               dano = (ataque + *vigor) + (rand() % 30);
                               dano = dano < 0 ? 0 : dano;
                               dano -= (inim_defesa / 5);
                               dano = dano + bonus_dano;
                               inim_vida -= dano;
                               bonus_dano = 0;
                               if (inim_vida < 0) inim_vida = 0;

                               printf ("\n...Takeshi inflige %d de dano a %s...\n", dano, nome);

                               printf ("\n\n*---Vida de %s: %d---*\n", nome, inim_vida);
                           
                               if (inim_vida == 0) {
                       
                                   printf ("\n\n>>> %s foi derrotado!", nome);
                               
                                   /**fadiga += (resistencia - cansaco) / 10;
                                   if (*fadiga < 0) *fadiga = 0;
                                   *lesao += (vida - ferida) / 10;
                                   if (*lesao < 0) *lesao = 0;*/ 
                                   *vigor = 0;

                                   ascii_art (3);
                       
                       	           return 1;
                       
                                }

                               break;

                            case 2:
                        
                               resistencia -= 5;
                               if (resistencia < 0) resistencia = 0;

                               printf ("\n\n>>> Takeshi planeja se defender do ataque de %s...\n", nome);

                               esquiva = (defesa / 5) + (velocidade / 3) + (rand() % 20);
                               esquiva = esquiva > 0 ? 0 : esquiva;
                               if (bonus_dano < 150) bonus_dano += 50;

                               printf ("\n\n*---BÔNUS DE DEFESA: %d---*\n", esquiva);

                               printf ("\n*---BÔNUS DE DANO: %d---*\n", bonus_dano);

                               break;
                           
                            case 3:
                        
                               resistencia += 25;
                               if (resistencia > cansaco) resistencia = cansaco;

                               printf ("\n\n>>> Takeshi está vulnerável...\n");

                               break;

                        }
                   
                    }
           
               resistencia += 15;
               if (resistencia > cansaco) resistencia = cansaco;
               rodada++;
           
           }

        return 0;

}

int duelo_vs_3 (int vida, int *lesao, int ataque, int *vigor, int defesa, int velocidade,
           int resistencia, int *fadiga, char nome[], int inim_vida, int inim_ataque, int inim_defesa, 
           int inim_velocidade) {
		   
		   int escolha_luta, rodada = 1, dano, esquiva = 0, bonus_dano = 0;
		   
           ascii_art (2);

		   srand (time(NULL));
           
           printf ("\n*---FÚRIA DO GUERREIRO ATIVADA---*\n");

           vida = vida * 10;
           ataque = ataque * 10;
           defesa *= 5;
           resistencia = resistencia * 5;
           inim_vida = inim_vida * 30;
           inim_ataque = inim_ataque * 3;

           int cansaco = resistencia;

           while (vida != 0 || inim_vida != 0) {

                printf ("\n\n+-+-+-+-+-+-+ +--+");
                printf ("\n|R|O|D|A|D|A| |%02d|", rodada);
                printf ("\n+-+-+-+-+-+-+ +--+\n");

                       
                printf ("\n\n*---A Gangue %s avança para cima de Takeshi---*\n\n", nome);
               	   
               	printf ("\n>>> A Gangue %s irá atacar...\n\n", nome);

                dano = inim_ataque + (rand() % 15);
                dano = dano < 0 ? 0 : dano;
                if (esquiva > 0) dano -= esquiva;
                dano -= (defesa / 5);
                vida -= dano;
                if (vida < 0) vida = 0;
                esquiva = 0;

                printf ("\n>>> A Gangue %s inflige %d de dano a Takeshi\n", nome, dano);

                printf ("\n\n*---Vida de Takeshi: %d---*\n", vida);

                if (vida == 0) {
                       
                    printf ("\n>>> Takeshi foi derrotado!\n");

                    ascii_art (4);
                       
                    return 2;
                       
                } 
                        
                printf ("\n\n*---Vez de Takeshi---*\n\n");

                printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+");
                printf ("\n|M|E|N|U| |D|A| |B|A|T|A|L|H|A|");
                printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+\n");
                       
                printf ("\n*--------------------------------------*");
                printf ("\n| 1 - ATACAR / -75PTS DE RESISTÊNCIA   |");
                printf ("\n*--------------------------------------*");
                printf ("\n| 2 - DEFENDER / -25PTS DE RESISTÊNCIA |");
                printf ("\n*--------------------------------------*");
                printf ("\n| 3 - DESCANSAR / +100PTS DE RESISTÊNCIA |");
                printf ("\n*---------------------------------------*\n");


                printf ("\n*---RESISTÊNCIA: %d---*\n", resistencia - *fadiga);

                printf ("\n\n>>> Comando: ");

                do {

                    scanf ("%d", &escolha_luta);
                    fflush (stdin);

                } while (escolha_luta < 1 || escolha_luta > 3);
                   
                if (escolha_luta == 1 && resistencia < 75) {
                       
                    escolha_luta = 3;

                    printf ("\n\n>>> Vigor insuficiente!\n");

                    printf ("\n\n>>> Takeshi está vulnerável...\n");
                   
                }
                
                if (escolha_luta == 2 && resistencia < 25) {
                       
                    escolha_luta = 3;

                    printf ("\n\n>>> Vigor insuficiente!\n");

                    printf ("\n\n>>> Takeshi está vulnerável...\n");

                }

                switch (escolha_luta) {

                    case 1:

                        resistencia -= 75;
                        if (resistencia < 0) resistencia = 0;

                        printf ("\n\n>>> Takeshi ataca a Gangue %s com sua Katana...\n", nome);


                        dano = ataque + (rand() % 30);
                        dano = dano < 0 ? 0 : dano;
                        dano -= (inim_defesa / 5);
                        dano = dano + bonus_dano;
                        inim_vida -= dano;
                        bonus_dano = 0;
                        if (inim_vida < 0) inim_vida = 0;

                        printf ("\n...Takeshi inflige %d de dano a Gangue %s...\n", dano, nome);


                        printf ("\n\n*---Vida da Gangue %s: %d---*\n", nome, inim_vida);

                           
                        if (inim_vida == 0) {
                       
                            printf ("\n\n>>> A Gangue %s foi derrotada!", nome);

                            ascii_art (3);
                       
                       	    return 1;
                       
                        }

                        break;

                    case 2:
                        
                        resistencia -= 25;
                        if (resistencia < 0) resistencia = 0;


                        printf ("\n\n>>> Takeshi planeja se defender dos ataques da Gangue %s...\n", nome);


                        esquiva = (defesa / 3) + (rand() % 20);
                        esquiva = esquiva > 0 ? 0 : esquiva;
                        if (bonus_dano < 100) bonus_dano += 25;

                        printf ("\n\n*---BÔNUS DE DEFESA: %d---*\n", esquiva);

                        printf ("\n*---BÔNUS DE DANO: %d---*\n", bonus_dano);

                        break;
                           
                    case 3:
                        
                        resistencia += 100;
                        if (resistencia > cansaco) resistencia = cansaco;


                        printf ("\n\n>>> Takeshi está vulnerável...\n");
                               
                        break;

                }
                   
            }
           
            resistencia += 25;
            if (resistencia > cansaco) resistencia = cansaco;
            rodada++;
           
           

        return 0;

}

int duelo_vs_10 (int vida, int *lesao, int ataque, int *vigor, int defesa, int velocidade,
                 int resistencia, int *fadiga, char nome[], int inim_vida, int inim_ataque, int inim_defesa, 
                 int inim_velocidade) {
		   
		   int escolha_luta, rodada = 1, dano, esquiva = 0, bonus_dano = 0;
		   
           ascii_art (2);

		   srand (time(NULL));
           
           printf ("\n*---FÚRIA DO GUERREIRO ATIVADA---*\n");

           vida = vida * 10;
           ataque = ataque * 25;
           defesa *= 10;
           resistencia = resistencia * 10;
           inim_vida = inim_vida * 100;
           inim_ataque = inim_ataque * 10;

           int cansaco = resistencia;

           while (vida != 0 || inim_vida != 0) {

                printf ("\n\n+-+-+-+-+-+-+ +--+");
                printf ("\n|R|O|D|A|D|A| |%02d|", rodada);
                printf ("\n+-+-+-+-+-+-+ +--+\n");

                       
                printf ("\n\n*---Os Samurais %s avançam para cima de Takeshi---*\n\n", nome);
               	   
               	printf ("\n>>> Os Samurais %s irão atacar...\n\n", nome);

                dano = inim_ataque + (rand() % 15);
                dano = dano < 0 ? 0 : dano;
                if (esquiva > 0) dano -= esquiva;
                dano -= (defesa / 5);
                vida -= dano;
                if (vida < 0) vida = 0;
                esquiva = 0;

                printf ("\n>>> Os Samurais %s infligem %d de dano a Takeshi\n", nome, dano);

                printf ("\n\n*---Vida de Takeshi: %d---*\n", vida);

                if (vida == 0) {
                       
                    printf ("\n>>> Takeshi foi derrotado!\n");

                    ascii_art (4);
                       
                    return 2;
                       
                } 
                        
                printf ("\n\n*---Vez de Takeshi---*\n\n");

                printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+");
                printf ("\n|M|E|N|U| |D|A| |B|A|T|A|L|H|A|");
                printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+\n");
                       
                printf ("\n*--------------------------------------*");
                printf ("\n| 1 - ATACAR / -100PTS DE RESISTÊNCIA   |");
                printf ("\n*--------------------------------------*");
                printf ("\n| 2 - DEFENDER / -50PTS DE RESISTÊNCIA |");
                printf ("\n*--------------------------------------*");
                printf ("\n| 3 - DESCANSAR / +150PTS DE RESISTÊNCIA |");
                printf ("\n*---------------------------------------*\n");


                printf ("\n*---RESISTÊNCIA: %d---*\n", resistencia);

                printf ("\n\n>>> Comando: ");

                do {

                    scanf ("%d", &escolha_luta);
                    fflush (stdin);

                } while (escolha_luta < 1 || escolha_luta > 3);
                   
                if (escolha_luta == 1 && resistencia < 100) {
                       
                    escolha_luta = 3;

                    printf ("\n\n>>> Vigor insuficiente!\n");

                    printf ("\n\n>>> Takeshi está vulnerável...\n");
                   
                }
                
                if (escolha_luta == 2 && resistencia < 50) {
                       
                    escolha_luta = 3;

                    printf ("\n\n>>> Vigor insuficiente!\n");

                    printf ("\n\n>>> Takeshi está vulnerável...\n");

                }

                switch (escolha_luta) {

                    case 1:

                        resistencia -= 100;
                        if (resistencia < 0) resistencia = 0;

                        printf ("\n\n>>> Takeshi ataca os Samurais %s com sua Katana...\n", nome);


                        dano = ataque + (rand() % 30);
                        dano = dano < 0 ? 0 : dano;
                        dano -= (inim_defesa / 5);
                        dano = dano + bonus_dano;
                        inim_vida -= dano;
                        bonus_dano = 0;
                        if (inim_vida < 0) inim_vida = 0;

                        printf ("\n...Takeshi inflige %d de dano aos Samurais %s...\n", dano, nome);


                        printf ("\n\n*---Vida total dos Samurais %s: %d---*\n", nome, inim_vida);

                           
                        if (inim_vida == 0) {
                       
                            printf ("\n\n>>> Os Samurais %s foram derrotados!", nome);

                            ascii_art (3);
                       
                       	    return 1;
                       
                        }

                        break;

                    case 2:
                        
                        resistencia -= 50;
                        if (resistencia < 0) resistencia = 0;


                        printf ("\n\n>>> Takeshi planeja se defender dos ataques dos Samurais %s...\n", nome);


                        esquiva = (defesa / 3) + (rand() % 20);
                        esquiva = esquiva > 0 ? 0 : esquiva;
                        if (bonus_dano < 300) bonus_dano += 100;

                        printf ("\n\n*---BÔNUS DE DEFESA: %d---*\n", esquiva);

                        printf ("\n*---BÔNUS DE DANO: %d---*\n", bonus_dano);

                        break;
                           
                    case 3:
                        
                        resistencia += 150;
                        if (resistencia > cansaco) resistencia = cansaco;


                        printf ("\n\n>>> Takeshi está vulnerável...\n");
                               
                        break;

                }
                   
            }
           
            resistencia += 25;
            if (resistencia > cansaco) resistencia = cansaco;
            rodada++;
           
           

        return 0;

}

void treino (int *exp, int *pratica) {

    printf ("\nTakeshi caminha para um local isolado e treina com sua Katana ao ar livre...\n");
    
    *exp += 3000;
    *pratica = 0;

}

void pos_batalha (int *resultado, int *exp, int xp, int *ryos, int moedas) {

    *resultado = 0;

    *exp += xp;
    *ryos += moedas;

}
