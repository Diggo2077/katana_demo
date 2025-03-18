#ifndef HEADERS_H
#define HEADERS_H

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

// Structs

typedef struct
{
    int level;
    int xp;
    int attributes;
    int ryos;
    int health;
    int bonus_hp;
    int attack;
    int bonus_ttk;
    int bonus;
    int defense;
    int dodge;
    int stamina;
    int bonus_sta;
    int ginseng;
    int elixir;
    int sake;
    int tiger;
    int fenix;
    int dragon;
    int chapter;
    Armor gi;
} 
Character;

typedef struct
{
    char name[40];
    int level;
    int health;
    int elixir;
    int bonus_hp;
    int attack;
    int bonus;
    int defense;
    int dodge;
    int stamina;
    int bonus_sta;
} 
Opponents;

typedef struct
{
    int armor;
    int health;
    int attack;
    int defense;
    int stamina;
} 
Armor;

typedef struct
{
    char language[10];
    int txt_speed;
}
Configs;

// Saved Data

Configs c;
Character p;

/*FUNCTIONS*/

// Options

void saveConfigs (Configs c)
{
    FILE *archive = fopen ("saves/configs.dat", "wb");
    fwrite (&c, sizeof(Configs), 1, archive);
    fclose (archive);
}

void saveGame (Character p) 
{
    FILE *archive = fopen ("saves/save.dat", "wb");
    fwrite (&p, sizeof(Character), 1, archive);
    fclose (archive);
}
 
Configs loadConfigs ()
{
    FILE *archive = fopen ("saves/configs.dat", "rb");

    if (archive == NULL)
    {
        int n = 0;

        printf ("\n+-+-+ +-+-+-+-+-+ +-+-+-+-+ +-+-+-+-+-+");
        printf ("\n|N|O| |S|A|V|E|D| |D|A|T|A| |F|O|U|N|D|");
        printf ("\n+-+-+ +-+-+-+-+-+ +-+-+-+-+ +-+-+-+-+-+\n");

        printf ("\n>>> DO YOU WANT TO CREATE NEW SAVE DATA?\n");

        printf ("\n*-------------------*");
	    printf ("\n| 1 - NEW SAVE DATA |");
	    printf ("\n*-------------------*");
	    printf ("\n| 2 - QUIT GAME     |");
        printf ("\n*-------------------*\n");

        printf ("\n>>>  ");

        do 
        {
            scanf ("%d", &n);
        } 
        while (n < 1 || n > 2);

        system (CLEAR);

        switch (n)
        {
            case 1:
            
                strcpy (c.language, "EN-US");
                c.txt_speed = 2;
                saveConfigs (c);
                printf ("\n+-+-+-+-+-+ +-+-+-+-+ +-+-+-+-+-+-+-+");
                printf ("\n|S|A|V|E|D| |D|A|T|A| |C|R|E|A|T|E|D|");
                printf ("\n+-+-+-+-+-+ +-+-+-+-+ +-+-+-+-+-+-+-+\n");
                break;
        
            case 2:

                exit(0);
                break;
            }
    }
    else
    {
        fread (&c, sizeof(Configs), 1, archive);
    }

    fclose (archive);
    return c;
}

Character loadGame ()
{
    FILE *archive = fopen ("saves/save.dat", "rb");

    if (archive == NULL)
    {
        printf ("\nError opening file!!\n");
    }

    fread (&p, sizeof (Character), 1, archive);
    fclose (archive);
    return p;
}

void pauseGame (const Configs *c)
{
    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("\n\nPressione ENTER para continuar: ");
	    getchar ();
        getchar ();
        system (CLEAR);
    }
    else
    {
        printf ("\n\nPress ENTER to continue: ");
	    getchar ();
        getchar ();
        system (CLEAR);
    }

    return;
}

void asciiArt (const Configs *c, int n)
{
    int x;
    char filename[30];

    if (n == 0) 
    {
        system (CLEAR);
        FILE *credits;

        if (strcmp (c->language, "PT-BR") == 0)
        {
            strcpy (filename, "arts/credits-pt.txt");
        } 
        else 
        {
            strcpy (filename, "arts/credits-en.txt");
        }

        credits = fopen (filename, "r");

        if (credits == NULL) 
        {
            if (strcmp (c->language, "PT-BR") == 0)
            {
                printf ("\nErro ao abrir o arquivo: %s\n", filename);
                return;
            }
            else
            {
                printf ("\nError opening the file: %s\n", filename);
                return;
            }
        }

        while ((x = fgetc (credits)) != EOF)
        {
            putchar (x);
            msleep (c->txt_speed);
        }

        fclose (credits);

        pauseGame (c);

    }
    else if (n == 1) 
    {
        system (CLEAR);  
        FILE *archive;

        if (strcmp (c->language, "PT-BR") == 0)
        {
            strcpy (filename, "arts/main-pt.txt");
        } 
        else 
        {
            strcpy (filename, "arts/main-en.txt");
        }

        archive = fopen (filename, "r");

        if (archive == NULL) 
        {
            if (strcmp (c->language, "PT-BR") == 0)
            {
                printf ("\nErro ao abrir o arquivo: %s\n", filename);
                return;
            }
            else
            {
                printf ("\nError opening the file: %s\n", filename);
                return;
            }
        }

        while ((x = fgetc (archive)) != EOF)
        {
                putchar (x);
                msleep (c->txt_speed);
        }

        fclose (archive);
    }
    else if (n == 7)
    {
        system (CLEAR);  
        FILE *archive;

        if (strcmp (c->language, "PT-BR") == 0)
        {
            strcpy (filename, "arts/play1win-pt.txt");
        } 
        else 
        {
            strcpy (filename, "arts/play1win-en.txt");
        }

        archive = fopen (filename, "r");

        if (archive == NULL) 
        {
            if (strcmp (c->language, "PT-BR") == 0)
            {
                printf ("\nErro ao abrir o arquivo: %s\n", filename);
                return;
            }
            else
            {
                printf ("\nError opening the file: %s\n", filename);
                return;
            }
        }

        while ((x = fgetc (archive)) != EOF)
        {
                putchar (x);
                msleep (c->txt_speed);
        }

        fclose (archive);

        pauseGame (c);
    }
    else if (n == 8)
    {
        system (CLEAR);  
        FILE *archive;

        if (strcmp (c->language, "PT-BR") == 0)
        {
            strcpy (filename, "arts/play2win-pt.txt");
        } 
        else 
        {
            strcpy (filename, "arts/play2win-en.txt");
        }

        archive = fopen (filename, "r");

        if (archive == NULL) 
        {
            if (strcmp (c->language, "PT-BR") == 0)
            {
                printf ("\nErro ao abrir o arquivo: %s\n", filename);
                return;
            }
            else
            {
                printf ("\nError opening the file: %s\n", filename);
                return;
            }
        }

        while ((x = fgetc (archive)) != EOF)
        {
                putchar (x);
                msleep (c->txt_speed);
        }

        fclose (archive);

        pauseGame (c);
    }

    return;
}

void msleep (int mlseconds)
{
    #ifdef _WIN32
        if (mlseconds > 1000) mlseconds /= 1000; 
        Sleep (mlseconds);
    #else
        usleep (mlseconds);
    #endif
    
    return;
}

int mainMenu (Configs *c, Character *p)
{
    system (CLEAR);

    asciiArt(c, 1);

    int n = 0;
    
    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
        printf ("\n|M|E|N|U| |P|R|I|N|C|I|P|A|L|");
        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");

	    printf ("\n*---------------*");
	    printf ("\n| 1 - CONTINUAR |");
	    printf ("\n*---------------*");
	    printf ("\n| 2 - NOVO JOGO |");
	    printf ("\n*---------------*");
	    printf ("\n| 3 - TREINO    |");
	    printf ("\n*---------------*");
	    printf ("\n| 4 - CRÉDITOS  |");
	    printf ("\n*---------------*");
	    printf ("\n| 5 - OPÇÕES    |");
	    printf ("\n*---------------*");
        printf ("\n| 6 - SAIR      |");
        printf ("\n*---------------*\n");

        printf ("\n>>> Comando: ");
    }
    else
    {
        printf ("\n+-+-+-+-+ +-+-+-+-+");
        printf ("\n|M|A|I|N| |M|E|N|U|");
        printf ("\n+-+-+-+-+ +-+-+-+-+\n");

	    printf ("\n*---------------*");
	    printf ("\n| 1 - CONTINUE  |");
	    printf ("\n*---------------*");
	    printf ("\n| 2 - NEW GAME  |");
	    printf ("\n*---------------*");
	    printf ("\n| 3 - TRAINING  |");
	    printf ("\n*---------------*");
	    printf ("\n| 4 - CREDITS   |");
	    printf ("\n*---------------*");
	    printf ("\n| 5 - OPTIONS   |");
	    printf ("\n*---------------*");
        printf ("\n| 6 - QUIT      |");
        printf ("\n*---------------*\n");

        printf ("\n>>> Command: ");
    }

    do 
    {
        scanf ("%d", &n);
    } 
    while (n < 1 || n > 6);

    system (CLEAR);

    switch (n) 
    {
        case 1:
            return 1;
            break;
        case 2:
            p->chapter = 1;
            return 0;
            break;
        case 3: 
            training (c);
            break;
        case 4:
            asciiArt (c, 0);
            break;
        case 5:
        	options (c, p);
        	break;
        case 6:
            exit (0);
            break;
    }
    return mainMenu (c, p);
}

void speedMenu (Configs *c, Character *p)
{
    int n;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+");
        printf ("\n|V|E|L|O|C|I|D|A|D|E| |D|O| |T|E|X|T|O|");
        printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+\n");

        printf ("\n*-----------------*");
        printf ("\n| 1 - LENTO       |");
        printf ("\n*-----------------*");
        printf ("\n| 2 - RÁPIDO      |");
        printf ("\n*-----------------*");
        printf ("\n| 3 - INSTANTÂNEO |");
        printf ("\n*-----------------*");
        printf ("\n| 4 - SAIR        |");
        printf ("\n*-----------------*\n");

        printf ("\n>>> Comando: ");

        do
        {
            scanf ("%d", &n);
        } 
        while (n < 1 || n > 4);

        system (CLEAR);

        switch (n)
        {
            case 1:
                c->txt_speed = 15000;
                printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+");
                printf ("\n|V|E|L|O|C|I|D|A|D|E| |L|E|N|T|A|");
                printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+\n");
                saveConfigs (*c);
                pauseGame (c);
                options (c, p);
                break;
            case 2:
                c->txt_speed = 5000;
                printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+");
                printf ("\n|V|E|L|O|C|I|D|A|D|E| |R|Á|P|I|D|A|");
                printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+\n");
                saveConfigs (*c);
                pauseGame (c);
                options (c, p);
                break;
            case 3:
                c->txt_speed = 0;
                printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+-+");
                printf ("\n|V|E|L|O|C|I|D|A|D|E| |I|N|S|T|A|N|T|Â|N|E|A|");
                printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+-+\n");
                saveConfigs (*c);
                pauseGame (c);
                options (c, p);
                break;
            case 4:
                options (c, p);
                break;
        }
    }
    else
    {
        printf ("\n+-+-+-+-+ +-+-+-+-+-+");
        printf ("\n|T|E|X|T| |S|P|E|E|D|");
        printf ("\n+-+-+-+-+ +-+-+-+-+-+\n");

        printf ("\n*-------------*");
        printf ("\n| 1 - SLOW    |");
        printf ("\n*-------------*");
        printf ("\n| 2 - FAST    |");
        printf ("\n*-------------*");
        printf ("\n| 3 - INSTANT |");
        printf ("\n*-------------*");
        printf ("\n| 4 - QUIT    |");
        printf ("\n*-------------*\n");

        printf ("\n>>> Command: ");

        do
        {
            scanf ("%d", &n);
        } 
        while (n < 1 || n > 4);

        system (CLEAR);

        switch (n)
        {
            case 1:
                c->txt_speed = 15000;
                printf ("\n+-+-+-+-+ +-+-+-+-+-+");
                printf ("\n|S|L|O|W| |S|P|E|E|D|");
                printf ("\n+-+-+-+-+ +-+-+-+-+-+\n");
                saveConfigs (*c);
                pauseGame (c);
                options (c, p);
                break;
            case 2:
                c->txt_speed = 5000;
                printf ("\n+-+-+-+-+ +-+-+-+-+-+");
                printf ("\n|F|A|S|T| |S|P|E|E|D|");
                printf ("\n+-+-+-+-+ +-+-+-+-+-+\n");
                saveConfigs (*c);
                pauseGame (c);
                options (c, p);
                break;
            case 3:
                c->txt_speed = 0;
                printf ("\n+-+-+-+-+-+-+-+ +-+-+-+-+-+");
                printf ("\n|I|N|S|T|A|N|T| |S|P|E|E|D|");
                printf ("\n+-+-+-+-+-+-+-+ +-+-+-+-+-+\n");
                saveConfigs (*c);
                pauseGame (c);
                options (c, p);
                break;
            case 4:
                options (c, p);
                break;
        }
    }
}

void languageMenu (Configs *c, Character *p)
{
    int n;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("\n+-+-+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+");
        printf ("\n|L|I|N|G|U|A|G|E|M| |D|O| |J|O|G|O|");
        printf ("\n+-+-+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+\n");

        printf ("\n*-------------------------*");
        printf ("\n| 1 - INGLÊS              |");
        printf ("\n*-------------------------*");
        printf ("\n| 2 - PORTUGUÊS DO BRASIL |");
        printf ("\n*-------------------------*");
        printf ("\n| 3 - SAIR                |");
        printf ("\n*-------------------------*\n");

        printf ("\n>>> Comando: ");

        do
        {
            scanf ("%d", &n);
        } 
        while (n < 1 || n > 3);

        system (CLEAR);

        switch (n)
        {
            case 1:
                strcpy(c->language, "EN-US");
                printf ("\n+-+-+-+-+-+-+");
                printf ("\n|I|N|G|L|Ê|S|");
                printf ("\n+-+-+-+-+-+-+\n");
                saveConfigs (*c);
                pauseGame (c);
                options (c, p);
                break;
            case 2:
                strcpy(c->language, "PT-BR");
                printf ("\n+-+-+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+-+");
                printf ("\n|P|O|R|T|U|G|U|Ê|S| |D|O| |B|R|A|S|I|L|");
                printf ("\n+-+-+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+-+\n");
                saveConfigs (*c);
                pauseGame (c);
                options (c, p);
                break;
            case 3:
                options (c, p);
                break;
        }
    }
    else
    {
        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+");
        printf ("\n|G|A|M|E| |L|A|N|G|U|A|G|E|");
        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+\n");

        printf ("\n*-------------------------*");
        printf ("\n| 1 - ENGLISH             |");
        printf ("\n*-------------------------*");
        printf ("\n| 2 - PORTUGUESE - BRAZIL |");
        printf ("\n*-------------------------*");
        printf ("\n| 3 - QUIT                |");
        printf ("\n*-------------------------*\n");

        printf ("\n>>> Command: ");

        do
        {
            scanf ("%d", &n);
        } 
        while (n < 1 || n > 3);

        system (CLEAR);

        switch (n)
        {
            case 1:
                strcpy(c->language, "EN-US");
                printf ("\n+-+-+-+-+-+-+-+");
                printf ("\n|E|N|G|L|I|S|H|");
                printf ("\n+-+-+-+-+-+-+-+\n");
                saveConfigs (*c);
                pauseGame (c);
                options (c, p);
                break;                    
            case 2:
                strcpy(c->language, "PT-BR");
                printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+ +-+-+-+-+-+-+");
                printf ("\n|P|O|R|T|U|G|U|E|S|E| |-| |B|R|A|Z|I|L|");
                printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+ +-+-+-+-+-+-+\n");
                saveConfigs (*c);
                pauseGame (c);
                options (c, p);
                break;
            case 3:
                options (c, p);
                break;
        }
    }
}

void helpOutput (Configs *c)
{

}

void options (Configs *c, Character *p)
{
    system (CLEAR);
    int n;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("\n+-+-+-+-+-+-+");
        printf ("\n|O|P|Ç|Õ|E|S|");
        printf ("\n+-+-+-+-+-+-+\n");

	    printf ("\n*-------------------------*");
	    printf ("\n| 1 - VELOCIDADE DO TEXTO |");
	    printf ("\n*-------------------------*");
	    printf ("\n| 2 - LINGUAGEM DO JOGO   |");
	    printf ("\n*-------------------------*");
	    printf ("\n| 3 - AJUDA               |");
	    printf ("\n*-------------------------*");
	    printf ("\n| 4 - SAIR                |");
	    printf ("\n*-------------------------*\n");

        printf ("\n>>> Comando: ");
    }
    else
    {
        printf ("\n+-+-+-+-+-+-+-+");
        printf ("\n|O|P|T|I|O|N|S|");
        printf ("\n+-+-+-+-+-+-+-+\n");

	    printf ("\n*-------------------*");
	    printf ("\n| 1 - TEXT SPEED    |");
	    printf ("\n*-------------------*");
	    printf ("\n| 2 - GAME LANGUAGE |");
	    printf ("\n*-------------------*");
	    printf ("\n| 3 - HELP          |");
	    printf ("\n*-------------------*");
	    printf ("\n| 4 - QUIT          |");
	    printf ("\n*-------------------*\n");

        printf ("\n>>> Command: ");
    }

    do
    {
        scanf ("%d", &n);
    } 
    while (n < 1 || n > 4);

    system (CLEAR);

    switch (n)
    {
        case 1:
            speedMenu (c, p);
            break;
        case 2:
            languageMenu (c, p);
            break;
        case 3:
            helpOutput (c);
            break;
        case 4:
            mainMenu (c, p);
            break;
    }
    return;
}

// Main Story Tools

int lvl (Configs *c, Character *p)
{
    int old_level = p->level;

    if (p->xp >= 0 && p->xp <= 1000) p->level = 1;
    else if (p->xp >= 1000 && p->xp < 3000) p->level = 2;
    else if (p->xp >= 3000 && p->xp < 5000) p->level = 3;
    else if (p->xp >= 5000 && p->xp < 7000) p->level = 4;
    else if (p->xp >= 7000 && p->xp < 10000) p->level = 5;
    else if (p->xp >= 10000 && p->xp < 25000) p->level = 6;
    else if (p->xp >= 25000 && p->xp < 50000) p->level = 7;
    else if (p->xp >= 50000 && p->xp < 75000) p->level = 8;
    else if (p->xp >= 75000 && p->xp < 100000) p->level = 9;
    else 
    {
        p->level = 10; 
        p->xp = 100000;
    }

    if (p->level != old_level) 
    {
        system (CLEAR);
        if (strcmp (c->language, "PT-BR") == 0)
        {
            printf ("\n+-+-+-+-+ +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
            printf ("\n|N|O|V|O| |N|Í|V|E|L| |A|L|C|A|N|Ç|A|D|O|");
            printf ("\n+-+-+-+-+ +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");
        }
        else
        {
            printf ("\n+-+-+-+ +-+-+-+-+-+ +-+-+-+-+-+-+-+");
            printf ("\n|N|E|W| |L|E|V|E|L| |R|E|A|C|H|E|D|");
            printf ("\n+-+-+-+ +-+-+-+-+-+ +-+-+-+-+-+-+-+\n");
        }
        p->attributes += (p->level - old_level);
        pauseGame (c);
    }
    return 0;
}

int xpCalc (Configs *c, Character *p, int n)
{
    if (n == 1) p->xp += 2000;
    else if (n == 2) p->xp += 3500;
    else if (n == 3) p->xp += 4000;
    else if (n == 4) p->xp += 5000;
    else if (n == 5) p->xp += 7000;
    else if (n == 6) p->xp += 8000;
    else if (n == 7) p->xp += 10000;
    else if (n == 8) p->xp += 12500;
    else if (n == 9) p->xp += 15000;
    else if (n == 10) p->xp += 20000;

    return lvl(c, p);
}

void ryosCalc (Character *p, int n)
{
    if (n == 1) p->ryos += 20;
    else if (n == 2) p->ryos += 30;
    else if (n == 3) p->ryos += 50;
    else if (n == 4) p->ryos += 70;
    else if (n == 5) p->ryos += 100;
    else if (n == 6) p->ryos += 120;
    else if (n == 7) p->ryos += 250;
    else if (n == 8) p->ryos += 300;
    else if (n == 9) p->ryos += 400;
    else if (n == 10) p->ryos += 500;
}

void showAttributes (Configs *c, Character *p)
{
    int attr = 0;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("\n+-+-+-+-+-+ +-+ +-+-+-+-+-+-+-+-+-+");
        printf ("\n|N|Í|V|E|L| |E| |A|T|R|I|B|U|T|O|S|");
        printf ("\n+-+-+-+-+-+ +-+ +-+-+-+-+-+-+-+-+-+\n");
    
        printf ("\n*----------------------------------------*");
        printf ("\n|               Nível: %02d                |", p->level);
        printf ("\n*----------------------------------------*");
        printf ("\n|         Experiência: %06d            |", p->xp);
        printf ("\n*----------------------------------------*");
        printf ("\n| Pontos de Habilidades Disponíveis: %02d  |", p->attributes);
        printf ("\n*----------------------------------------*\n");
    
        printf ("\n*-----------------------*");
        printf ("\n| Vida: %03d - %02d        |", (p->health + p->gi.health) * 10, p->bonus_hp);
        printf ("\n*-----------------------*");
        printf ("\n| Ataque: %03d + %02d      |", p->attack + p->gi.attack, p->bonus_ttk);
        printf ("\n*-----------------------*");
        printf ("\n| Defesa: %03d           |", p->defense + p->gi.defense);
        printf ("\n*-----------------------*");
        printf ("\n| Resistência: %03d - %02d |", (p->stamina + p->gi.stamina) * 5, p->bonus_sta);
        printf ("\n*-----------------------*\n");
    
        if (p->attributes > 0) 
        {
            printf ("\n*---Pontos de Habilidade Disponíveis: %02d---*\n", p->attributes);
    
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

            do 
            {
                scanf ("%d", &attr);
            }
            while (attr < 1 || attr > 6);

            switch (attr) 
            {
                case 1:
                    printf ("\n\n*---VIDA +1---*\n\n");
                    p->health += 1;
                    p->attributes -= 1;
                    break;
                case 2:
                    printf ("\n\n*---ATAQUE +1---*\n\n");
                    p->attack += 1;
                    p->attributes -= 1;
                    break;
                case 3:
                    printf ("\n\n*---DEFESA +1---*\n\n");
                    p->defense += 1;
                    p->attributes -= 1;
                    break;
                case 4:
                    printf ("\n\n*---RESISTÊNCIA +1---*\n\n");
                    p->stamina += 1;
                    p->attributes -= 1;
                    break;
                case 5:
                    return;
            }
        } 
        else pauseGame (c);
    }
    else
    {
        printf ("\n+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+-+-+-+");
        printf ("\n|L|E|V|E|L| |A|N|D| |A|T|T|R|I|B|U|T|E|S|");
        printf ("\n+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+-+-+-+\n");
    
        printf ("\n*-----------------------------*");
        printf ("\n|           Level: %02d         |", p->level);
        printf ("\n*-----------------------------*");
        printf ("\n|     Experience: %06d      |", p->xp);
        printf ("\n*-----------------------------*");
        printf ("\n| Available Skill Points: %02d  |", p->attributes);
        printf ("\n*-----------------------------*\n");
    
        printf ("\n*-------------------*");
        printf ("\n| Health: %03d - %02d  |", (p->health + p->gi.health) * 10, p->bonus_hp);
        printf ("\n*-------------------*");
        printf ("\n| Attack: %03d + %02d  |", p->attack + p->gi.attack, p->bonus_ttk);
        printf ("\n*-------------------*");
        printf ("\n| Defense: %03d         |", p->defense + p->gi.defense);
        printf ("\n*-------------------*");
        printf ("\n| Stamina: %03d - %02d |", (p->stamina + p->gi.stamina) * 5, p->bonus_sta);
        printf ("\n*-------------------*\n");
    
        if (p->attributes > 0) 
        {
            printf ("\n*---Available Skill Points: %02d---*\n", p->attributes);
    
            printf ("\n*-------------*");
            printf ("\n| 1 - HEALTH  |");
            printf ("\n*-------------*");
            printf ("\n| 2 - ATTACK  |");
            printf ("\n*-------------*");
            printf ("\n| 3 - DEFENSE |");
            printf ("\n*-------------*");
            printf ("\n| 4 - STAMINA |");
            printf ("\n*-------------*");
            printf ("\n| 5 - QUIT    |");
            printf ("\n*-------------*\n");

            printf ("\n>>> Command: ");

            do 
            {
                scanf ("%d", &attr);
            }
            while (attr < 1 || attr > 6);

            switch (attr) {

                case 1:
                    printf ("\n\n*---HEALTH +1---*\n\n");
                    p->health += 1;
                    p->attributes -= 1;
                    break;
                case 2:
                    printf ("\n\n*---ATTACK +1---*\n\n");
                    p->attack += 1;
                    p->attributes -= 1;
                    break;
                case 3:
                    printf ("\n\n*---DEFENSE +1---*\n\n");
                    p->defense += 1;
                    p->attributes -= 1;
                    break;
                case 4:
                    printf ("\n\n*---STAMINA +1---*\n\n");
                    p->stamina += 1;
                    p->attributes -= 1;
                    break;
                case 5:
                    return;
            }
        } 
    }
    pauseGame (c);
    return showAttributes (c, p);
}

void inventory (Configs *c, Character *p)
{
    int choice = 0;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("\n+-+-+-+-+-+-+-+-+-+-+");
        printf ("\n|I|N|V|E|N|T|Á|R|I|O|");
        printf ("\n+-+-+-+-+-+-+-+-+-+-+\n");

        printf ("\n*---Ryōs: %03d---*\n", p->ryos);

        printf ("\n*----------------------------------*");
        printf ("\n| Pílulas de Ginseng: %d/1          |", p->ginseng);
        printf ("\n*----------------------------------*");
        printf ("\n| Elixir da Cura do Imperador: %d/3 |", p->elixir);
        printf ("\n*----------------------------------*");
        printf ("\n| Saquê de Fogo do Dragão: %d/1     |", p->sake);
        printf ("\n*----------------------------------*\n");

        printf ("\n*----------------------------------*");
        printf ("\n| 1 - PÍLULAS DE GINSENG           |");
        printf ("\n*----------------------------------*");
        printf ("\n| 2 - ELIXIR DA CURA DO IMPERADOR  |");
        printf ("\n*----------------------------------*");
        printf ("\n| 3 - SAQUÊ DO FOGO DO DRAGÃO      |");
        printf ("\n*----------------------------------*");
        printf ("\n| 4 - SAIR                         |");
        printf ("\n*----------------------------------*\n");

        printf ("\n>>> Comando: ");

        do 
        {
            scanf ("%d", &choice);
        } 
        while (choice < 1 || choice > 4);

        switch (choice) 
        {
        case 1:
            if (p->ginseng == 0) printf ("\n\n*---PÍLULAS INSUFICIENTES---*\n\n");
            else if (p->bonus_hp >= 50) printf ("\n\n*---ENERGIA MÁXIMA---*\n\n");
            else 
            {
                p->ginseng -= 1;
                p->bonus_sta += 50;
                if (p->bonus_sta >= 50) p->bonus_sta = 50;
                printf ("\n\n*---BÔNUS DE RESISTÊNCIA = %d---*", p->bonus_sta);
                printf ("\n\n==>-1 PÍLULAS DE GINSENG<==\n\n");
            }
            break;
        case 2:
            printf ("\n\n*---DISPONÍVEL APENAS EM BATALHAS---*\n\n");
            break;
        case 3:
            if (p->sake == 0) printf ("\n\n*---SAQUÊS INSUFICIENTES---*\n\n");
            else if (p->bonus_ttk >= 5) printf ("\n\n*---EFEITO MÁXIMO ALCANÇADO---*\n\n");
            else {
                p->sake -= 1;
                p->bonus_ttk += 5;
                printf ("\n\n*---BÔNUS DE ATAQUE = %d---*", p->bonus_ttk);
                printf ("\n\n==>-1 SAQUÊ DO FOGO DO DRAGÃO<==\n\n");
            }
            break;
        case 4:
            return;
        }
    }
    else
    {
        printf ("\n+-+-+-+-+-+-+-+-+-+");
        printf ("\n|I|N|V|E|N|T|O|R|Y|");
        printf ("\n+-+-+-+-+-+-+-+-+-+\n");

        printf ("\n*---Ryōs: %03d---*\n", p->ryos);

        printf ("\n*-------------------------------*");
        printf ("\n| Ginseng Pills: %d/3            |", p->ginseng);
        printf ("\n*----------------------------------*");
        printf ("\n| Emperor's Healing Elixir: %d/1 |", p->elixir);
        printf ("\n*----------------------------------*");
        printf ("\n| Dragon Fire Sake: %d/1         |", p->sake);
        printf ("\n*----------------------------------*\n");

        printf ("\n*------------------------------*");
        printf ("\n| 1 - GINSENG PILLS            |");
        printf ("\n*------------------------------*");
        printf ("\n| 2 - EMPEROR'S HEALING ELIXIR |");
        printf ("\n*------------------------------*");
        printf ("\n| 3 - DRAGON FIRE SAKE         |");
        printf ("\n*------------------------------*");
        printf ("\n| 4 - QUIT                     |");
        printf ("\n*------------------------------*\n");

        printf ("\n>>> Command: ");

        do 
        {
            scanf ("%d", &choice);
        } 
        while (choice < 1 || choice > 4);

        switch (choice) 
        {
        case 1:
            if (p->ginseng == 0) printf ("\n\n*---INSUFFICIENT PILLS---*\n\n");
            else if (p->bonus_sta >= 50) printf ("\n\n*---MAXIMUM ENERGY---*\n\n");
            else 
            {
                p->ginseng -= 1;
                p->bonus_sta += 50;
                if (p->bonus_sta >= 50) p->bonus_sta = 50;
                printf ("\n\n*---RESISTANCE BONUS = %d---*", p->bonus_sta);
                printf ("\n\n==>-1 GINSENG PILLS<==\n\n");
            }
            break;
        case 2:
            printf ("\n\n*---AVAILABLE ONLY IN BATTLES---*\n\n");
            break;
        case 3:
            if (p->sake == 0) printf ("\n\n*---INSUFFICIENT SAKES---*\n\n");
            else if (p->bonus_ttk >= 5) printf ("\n\n*---MAXIMUM EFFECT ACHIEVED---*\n\n");
            else {
                p->sake += 1;
                p->bonus_ttk += 5;
                printf ("\n\n*---ATTACK BONUS = %d---*", p->bonus_ttk);
                printf ("\n\n==>-1 DRAGON FIRE SAKE<==\n\n");
            }
            break;
        case 4:
            return;
        }
    }
    pauseGame (c);
    return inventory (c, p);
}

Armor changeEquip (Armor *equip, int n)
{
    if (n == 1)
    {
        equip->armor = n;
        equip->health = 0;
        equip->attack = 0;
        equip->defense = 0;
        equip->stamina = 0;
    }
    else if (n == 2)
    {
        equip->armor = n;
        equip->health = 2;
        equip->attack = 1;
        equip->defense = 6;
        equip->stamina = 1;
    }
    else if (n == 3)
    {
        equip->armor = n;
        equip->health = 5;
        equip->attack = 1;
        equip->defense = 3;
        equip->stamina = 1;
    }
    else if (n == 4)
    {
        equip->armor = n;
        equip->health = 2;
        equip->attack = 6;
        equip->defense = 1;
        equip->stamina = 1;
    }

    return *equip; 
} 

int equipments (Configs *c, Character *p)
{
    int choice;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("\n*---Gi: %s---*", p->gi.armor == 1 ? "Equipado" : "Equipar");
        printf ("\n*---Armadura do Tigre de Kōzuke: %s---*", p->tiger == 1 ? "Equipado" : "Equipar");
        printf ("\n*---Armadura da Fênix Imortal: %s---*", p->fenix == 1 ? "Equipado" : "Equipar");
        printf ("\n*---Armadura do Dragão Celestial: %s---*\n", p->dragon == 1 ? "Equipado" : "Equipar");
    
        printf ("\n*----------------------------------*");
        printf ("\n| 1 - GI                           |");
        printf ("\n*----------------------------------*");
        printf ("\n| 2 - ARMADURA DO TIGRE DE KŌZUKE  |");
        printf ("\n*----------------------------------*");
        printf ("\n| 3 - ARMADURA DA FÊNIX IMORTAL    |");
        printf ("\n*----------------------------------*");
        printf ("\n| 4 - ARMADURA DO DRAGÃO CELESTIAL |");
        printf ("\n*----------------------------------*");
        printf ("\n| 5 - SAIR                         |");
        printf ("\n*----------------------------------*\n");

        printf ("\n>>> Comando: ");

        do
        {
            scanf ("%d", &choice);
        } 
        while (choice < 1 || choice > 5);
        
        switch (choice)
        {
            case 1:
                if (p->gi.armor != 1)
                {
                    printf ("\n\n==> Gi equipado com sucesso! <==\n\n");
                    p->gi = changeEquip (&p->gi, choice);
                }
                else
                {
                    printf ("\n\n==> Gi já equipado <==\n\n");
                }
                break;
            case 2:
                if (p->tiger == 1 && p->gi.armor != 2)
                {
                    printf ("\n\n==> Armadura do Tigre de Kōzuke equipado com sucesso! <==\n\n");
                    p->gi = changeEquip (&p->gi, choice);
                }
                else if (p->tiger == 1 && p->gi.armor == 2)
                {
                    printf ("\n\n==> Armadura já equipada <==");
                }
                else
                {
                    printf ("\n\n==> Armadura não-possuída <==\n\n");
                }
                break;
            case 3:
                if (p->fenix == 1 && p->gi.armor != 3)
                {
                    printf ("\n\n==> Armadura da Fênix Imortal equipado com sucesso! <==\n\n");
                    p->gi = changeEquip (&p->gi, choice);
                }
                else if (p->fenix == 1 && p->gi.armor == 3)
                {
                    printf ("\n\n==> Armadura já equipada <==");
                }
                else
                {
                    printf ("\n\n==> Armadura não-possuída <==\n\n");
                }
                break;
            case 4:
                if (p->dragon == 1 && p->gi.armor != 4)
                {
                    printf ("\n\n==> Armadura do Dragão Celestial equipado com sucesso! <==\n\n");
                    p->gi = changeEquip (&p->gi, choice);
                }
                else if (p->dragon == 1 && p->gi.armor == 4)
                {
                    printf ("\n\n==> Armadura já equipada <==");
                }
                else
                {
                    printf ("\n\n==> Armadura não-possuída <==\n\n");
                }
                break;
            case 5:
                return 0;
        }
    }
    else
    {
        printf ("\n*---Gi: %s---*", p->gi.armor == 1 ? "Equipped" : "Equip");
        printf ("\n*---Kōzuke's Tiger Armor: %s---*", p->tiger == 1 ? "Equipped" : "Equip");
        printf ("\n*---Immortal Phoenix Armor: %s---*", p->fenix == 1 ? "Equipped" : "Equip");
        printf ("\n*---Celestial Dragon Armor: %s---*\n", p->dragon == 1 ? "Equipped" : "Equip");
    
        printf ("\n*----------------------------*");
        printf ("\n| 1 - GI                     |");
        printf ("\n*----------------------------*");
        printf ("\n| 2 - KŌZUKE'S TIGER ARMOR   |");
        printf ("\n*----------------------------*");
        printf ("\n| 3 - IMMORTAL PHOENIX ARMOR |");
        printf ("\n*----------------------------*");
        printf ("\n| 4 - CELESTIAL DRAGON ARMOR |");
        printf ("\n*----------------------------*");
        printf ("\n| 5 - QUIT                   |");
        printf ("\n*----------------------------*\n");

        printf ("\n>>> Command: ");

        do
        {
            scanf ("%d", &choice);
        } 
        while (choice < 1 || choice > 5);
        
        switch (choice)
        {
            case 1:
                if (p->gi.armor != 1)
                {
                    printf ("\n\n==> Gi equipped successfully! <==\n\n");
                    p->gi = changeEquip (&p->gi, choice);
                }
                else
                {
                    printf ("\n\n==> Gi already equipped <==\n\n");
                }
                break;
            case 2:
                if (p->tiger == 1 && p->gi.armor != 2)
                {
                    printf ("\n\n==> Kōzuke's Tiger Armor has been successfully equipped! <==\n\n");
                    p->gi = changeEquip (&p->gi, choice);
                }
                else if (p->tiger == 1 && p->gi.armor == 2)
                {
                    printf ("\n\n==> Armor already equipped <==");
                }
                else
                {
                    printf ("\n\n==> Unowned Armor <==\n\n");
                }
                break;
            case 3:
                if (p->fenix == 1 && p->gi.armor != 3)
                {
                    printf ("\n\n==> Immortal Phoenix Armor has been successfully equipped! <==\n\n");
                    p->gi = changeEquip (&p->gi, choice);
                }
                else if (p->fenix == 1 && p->gi.armor == 3)
                {
                    printf ("\n\n==> Armor already equipped <==");
                }
                else
                {
                    printf ("\n\n==> Unowned Armor <==\n\n");
                }
                break;
            case 4:
                if (p->dragon == 1 && p->gi.armor != 4)
                {
                    printf ("\n\n==> Celestial Dragon Armor has been successfully equipped! <==\n\n");
                    p->gi = changeEquip (&p->gi, choice);
                }
                else if (p->dragon == 1 && p->gi.armor == 4)
                {
                    printf ("\n\n==> Armor already equipped <==");
                }
                else
                {
                    printf ("\n\n==> Unowned Armor <==\n\n");
                }
                break;
            case 5:
                return 0;
        }
    }
    return equipments (c, p);
}

void shop (Configs *c, Character *p)
{
    int choice;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("\n+-+-+-+-+-+-+-+-+-+-+");
        printf ("\n|I|N|V|E|N|T|Á|R|I|O|");
        printf ("\n+-+-+-+-+-+-+-+-+-+-+\n");

        printf ("\n*---Ryōs: %03d---*\n", p->ryos);

        printf ("\n*----------------------------------*");
        printf ("\n| Pílulas de Ginseng: %d/3          |", p->ginseng);
        printf ("\n*----------------------------------*");
        printf ("\n| Elixir da Cura do Imperador: %d/1 |", p->elixir);
        printf ("\n*----------------------------------*");
        printf ("\n| Saquê de Fogo do Dragão: %d/1     |", p->sake);
        printf ("\n*----------------------------------*\n");

        printf ("\n*---Armadura do Tigre de Kōzuke: %s---*", p->tiger == 1 ? "Possuído" : "Não-Possuído");
        printf ("\n*---Armadura da Fênix Imortal: %s---*", p->fenix == 1 ? "Possuído" : "Não-Possuído");
        printf ("\n*---Armadura do Dragão Celestial: %s---*\n", p->dragon == 1 ? "Possuído" : "Não-Possuído");

        printf ("\n+-+-+-+-+");
        printf ("\n|L|O|J|A|");
        printf ("\n+-+-+-+-+\n");

        printf ("\n*---------------------------------------------*");
        printf ("\n| 1 - PÍLULAS DE GINSENG: 200 Ryōs            |");
        printf ("\n*---------------------------------------------*");
        printf ("\n| 2 - ELIXIR DA CURA DO IMPERADOR: 150 Ryōs   |");
        printf ("\n*---------------------------------------------*");
        printf ("\n| 3 - SAQUÊ DO FOGO DO DRAGÃO: 250 Ryōs       |");
        printf ("\n*---------------------------------------------*");
        printf ("\n| 4 - ARMADURA DO TIGRE DE KŌZUKE: 1500 Ryōs  |");
        printf ("\n*---------------------------------------------*");
        printf ("\n| 5 - ARMADURA DA FÊNIX IMORTAL: 1800 Ryōs    |");
        printf ("\n*---------------------------------------------*");
        printf ("\n| 6 - ARMADURA DO DRAGÃO CELESTIAL: 2200 Ryōs |");
        printf ("\n*---------------------------------------------*");
        printf ("\n| 7 - SAIR                                    |");
        printf ("\n*-------------------------------------------*\n");

        printf ("\n>>> Comando: ");

        do 
        {
            scanf ("%d", &choice);
        } 
        while (choice < 1 || choice > 7);

        switch (choice) 
        {
            case 1:
                if (p->ginseng >= 1) printf ("\n*---ESTOQUE CHEIO---*\n");
                else if (p->ryos < 200) printf ("\n*---DINHEIRO INSUFICIENTE---*\n");
                else 
                {
                    p->ginseng += 1;
                    p->ryos -= 200;
                    printf ("\n\n==> +1 PÍLULA DE GINSENG <==\n\n");
                }
                break;
            case 2:
                if (p->elixir >= 3) printf ("\n\n*---ESTOQUE CHEIO---*\n\n");
                else if (p->ryos < 150) printf ("\n\n*---DINHEIRO SUFICIENTE---*\n\n");
                else 
                {
                    p->elixir += 1;
                    p->ryos -= 150;
                    printf ("\n\n==> +1 ELIXIR DA CURA DO IMPERADOR <==\n\n");
                }
                break;

            case 3:
                if (p->sake >= 1) printf ("\n\n*---ESTOQUE CHEIO---*\n\n");
                else if (p->ryos < 250) printf ("\n\n*---DINHEIRO INSUFICIENTE---*\n\n");
                else 
                {
                    p->sake += 1;
                    p->ryos -= 250;
                    printf ("\n\n==> +1 SAQUÊ DO FOGO DO DRAGÃO <==\n\n");
                }
                break;

            case 4:
                if (p->tiger >= 1) printf ("\n\n*---ARMADURA JÁ POSSUÍDA---*\n\n");
                else if (p->ryos < 2) printf ("\n\n*---DINHEIRO INSUFICIENTE---*\n\n");
                else
                {
                    p->tiger = 1;
                    p->ryos -= 1500;
                    printf ("\n\n==> ARMADURA DO TIGRE DE KŌZUKE COMPRADA <==\n\n");
                }
                break;
            case 5: 
                if (p->fenix >= 1) printf ("\n\n*---ARMADURA JÁ POSSUÍDA---*\n\n");
                else if (p->ryos < 2) printf ("\n\n*---DINHEIRO INSUFICIENTE---*\n\n");
                else
                {
                    p->fenix = 1;
                    p->ryos -= 1800;
                    printf ("\n\n==> ARMADURA DA FÊNIX IMORTAL COMPRADA <==\n\n");
                }
                break;
            case 6:
                if (p->dragon >= 1) printf ("\n\n*---ARMADURA JÁ POSSUÍDA---*\n\n");
                else if (p->ryos < 2) printf ("\n\n*---DINHEIRO INSUFICIENTE---*\n\n");
                else
                {
                    p->dragon = 1;
                    p->ryos -= 2200;
                    printf ("\n\n==> ARMADURA DO DRAGÃO CELESTIAL COMPRADA <==\n\n");
                }
                break;
            case 7:
                return;
        }
    }
    else
    {
        printf ("\n+-+-+-+-+-+-+-+-+-+");
        printf ("\n|I|N|V|E|N|T|O|R|Y|");
        printf ("\n+-+-+-+-+-+-+-+-+-+\n");

        printf ("\n*---Ryōs: %03d---*\n", p->ryos);

        printf ("\n*-------------------------------*");
        printf ("\n| Ginseng Pills: %d/3            |", p->ginseng);
        printf ("\n*----------------------------------*");
        printf ("\n| Emperor's Healing Elixir: %d/1 |", p->elixir);
        printf ("\n*----------------------------------*");
        printf ("\n| Dragon Fire Sake: %d/1         |", p->sake);
        printf ("\n*----------------------------------*\n");

        printf ("\n*---Kōzuke's Tiger Armor: %s---*", p->tiger == 1 ? "Owned" : "Non-Owned");
        printf ("\n*---Immortal Phoenix Armor: %s---*", p->fenix == 1 ? "Owned" : "Non-Owned");
        printf ("\n*---Celestial Dragon Armor: %s---*\n", p->dragon == 1 ? "Owned" : "Non-Owned");

        printf ("\n+-+-+-+-+");
        printf ("\n|S|H|O|P|");
        printf ("\n+-+-+-+-+\n");

        printf ("\n*----------------------------------------*");
        printf ("\n| 1 - GINSENG PILLS: 200 Ryōs            |");
        printf ("\n*----------------------------------------*");
        printf ("\n| 2 - EMPEROR'S HEALING ELIXIR: 150 Ryōs |");
        printf ("\n*----------------------------------------*");
        printf ("\n| 3 - DRAGON'S FIRE SAKE: 250 Ryōs       |");
        printf ("\n*----------------------------------------*");
        printf ("\n| 4 - KŌZUKE'S TIGER ARMOR: 1500 Ryōs    |");
        printf ("\n*----------------------------------------*");
        printf ("\n| 5 - IMMORTAL PHOENIX ARMOR: 1800 Ryōs  |");
        printf ("\n*----------------------------------------*");
        printf ("\n| 6 - CELESTIAL DRAGON ARMOR: 2200 Ryōs  |");
        printf ("\n*----------------------------------------*");
        printf ("\n| 7 - QUIT                               |");
        printf ("\n*----------------------------------------*\n");

        printf ("\n>>> Command: ");

        do 
        {
            scanf ("%d", &choice);
        } 
        while (choice < 1 || choice > 7);

        switch (choice) 
        {
            case 1:
                if (p->ginseng >= 1) printf ("\n*---FULL STOCK---*\n");
                else if (p->ryos < 200) printf ("\n*---ENOUGH MONEY---*\n");
                else 
                {
                    p->ginseng += 1;
                    p->ryos -= 200;
                    printf ("\n\n==> +1 GINSENG PILL <==\n\n");
                }
                break;
            case 2:
                if (p->elixir >= 3) printf ("\n\n*---FULL STOCK---*\n\n");
                else if (p->ryos < 150) printf ("\n\n*---ENOUGH MONEY---*\n\n");
                else 
                {
                    p->elixir += 1;
                    p->ryos -= 150;
                    printf ("\n\n==> +1 EMPEROR'S HEALING ELIXIR <==\n\n");
                }
                break;

            case 3:
                if (p->sake >= 1) printf ("\n\n*---FULL STOCK---*\n\n");
                else if (p->ryos < 250) printf ("\n\n*---ENOUGH MONEY---*\n\n");
                else 
                {
                    p->sake += 1;
                    p->ryos -= 250;
                    printf ("\n\n==> +1 DRAGON'S FIRE SAKE <==\n\n");
                }
                break;

            case 4:
                if (p->tiger >= 1) printf ("\n\n*---ARMOR ALREADY OWNED---*\n\n");
                else if (p->ryos < 2) printf ("\n\n*---ENOUGH MONEY---*\n\n");
                else
                {
                    p->tiger = 1;
                    p->ryos -= 1500;
                    printf ("\n\n==> KŌZUKE'S TIGER ARMOR PURCHASED <==\n\n");
                }
                break;
            case 5: 
                if (p->fenix >= 1) printf ("\n\n*---ARMOR ALREADY OWNED---*\n\n");
                else if (p->ryos < 2) printf ("\n\n*---ENOUGH MONEY---*\n\n");
                else
                {
                    p->fenix = 1;
                    p->ryos -= 1800;
                    printf ("\n\n==> IMMORTAL PHOENIX ARMOR PURCHASED <==\n\n");
                }
                break;
            case 6:
                if (p->dragon >= 1) printf ("\n\n*---ARMOR ALREADY OWNED---*\n\n");
                else if (p->ryos < 2) printf ("\n\n*---ENOUGH MONEY---*\n\n");
                else
                {
                    p->dragon = 1;
                    p->ryos -= 2200;
                    printf ("\n\n==> CELESTIAL DRAGON ARMOR PURCHASED <==\n\n");
                }
                break;
            case 7:
                return;
        }
    }
    pauseGame (c);
    return shop (c, p);
}

int playerMenu (Configs *c, Character *p)
{    
    int n;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+");
        printf ("\n|M|E|N|U| |D|O| |J|O|G|A|D|O|R|");
        printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+\n");

        printf ("\n*------------------------------*");
        printf ("\n| 1 - CONTINUAR                |");
        printf ("\n*------------------------------*");
        printf ("\n| 2 - INVENTÁRIO               |");
        printf ("\n*------------------------------*");
        printf ("\n| 3 - EQUIPAMENTOS             |");
        printf ("\n*------------------------------*");
        printf ("\n| 4 - ATRIBUTOS                |");
        printf ("\n*------------------------------*");
        printf ("\n| 5 - OPÇÕES                   |");
        printf ("\n*------------------------------*");
        printf ("\n| 6 - VOLTAR AO MENU PRINCIPAL |");
        printf ("\n*------------------------------*\n");

        printf ("\n>>> Comando: ");
    }
    else
    {
        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+");
        printf ("\n|P|L|A|Y|E|R| |M|E|N|U|");
        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+\n");

        printf ("\n*-------------------------*");
        printf ("\n| 1 - CONTINUE            |");
        printf ("\n*-------------------------*");
        printf ("\n| 2 - INVENTORY           |");
        printf ("\n*-------------------------*");
        printf ("\n| 3 - EQUIPMENTS          |");
        printf ("\n*-------------------------*");
        printf ("\n| 3 - ATTRIBUTES          |");
        printf ("\n*-------------------------*");
        printf ("\n| 4 - OPTIONS             |");
        printf ("\n*------- -----------------*");
        printf ("\n| 5 - RETURN TO MAIN MENU |");
        printf ("\n*-------------------------*\n");

        printf ("\n>>> Command: ");
    }

    do 
    {
        scanf ("%d", &n);
    } 
    while (n < 1 || n > 6);

    switch (n) 
    {
        case 1:
            return 0;
            break;
        case 2:
            inventory (c, p);
            break;
        case 3:
            equipments (c, p);
            break;
        case 4:
            showAttributes (c, p);
            break;
        case 5:
            options (c, p);
            break;
        case 6:
            return mainMenu (c, p);
            break;
    }
    return playerMenu (c, p);
}

void cityMenu (Configs *c, Character *p)
{
    int n;

    if (strcmp (c->language, "PT-BR") == 0) 
    {
        printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+");
        printf ("\n|M|E|N|U| |D|A| |C|I|D|A|D|E|");
        printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+\n");

        printf ("\n*------------------------------*");
        printf ("\n| 1 - CONTINUAR                |");
        printf ("\n*------------------------------*");
        printf ("\n| 2 - LOJA                     |");
        printf ("\n*------------------------------*");
        printf ("\n| 3 - INVENTÁRIO               |");
        printf ("\n*------------------------------*");
        printf ("\n| 4 - EQUIPAMENTOS             |");
        printf ("\n*------------------------------*");
        printf ("\n| 5 - ATRIBUTOS                |");
        printf ("\n*------------------------------*");
        printf ("\n| 6 - TREINAR                  |");
        printf ("\n*------------------------------*");
        printf ("\n| 7 - VOLTAR AO MENU PRINCIPAL |");
        printf ("\n*------------------------------*\n");
        
        printf ("\n>>> Comando: ");
    }
    else
    {
        printf ("\n+-+-+-+-+ +-+-+-+-+");
        printf ("\n|C|I|T|Y| |M|E|N|U|");
        printf ("\n+-+-+-+-+ +-+-+-+-+\n");

        printf ("\n*-------------------------*");
        printf ("\n| 1 - CONTINUE            |");
        printf ("\n*-------------------------*");
        printf ("\n| 2 - SHOP                |");
        printf ("\n*-------------------------*");
        printf ("\n| 3 - INVENTORY           |");
        printf ("\n*-------------------------*");
        printf ("\n| 4 - EQUIPMENTS          |");
        printf ("\n*-------------------------*");
        printf ("\n| 5 - ATTRIBUTES          |");
        printf ("\n*-------------------------*");
        printf ("\n| 6 - TRAINING            |");
        printf ("\n*-------------------------*");
        printf ("\n| 7 - RETURN TO MAIN MENU |");
        printf ("\n*-------------------------*\n");
        
        printf ("\n>>> Command: ");
    }
        do 
        {
            scanf ("%d", &n);
        } 
        while (n < 1 || n > 7);

        switch (n) 
        {
            case 1:
                return;
                break;
            case 2:
                shop (c, p);
                break;
            case 3:
                inventory (c, p);
                break;
            case 4:
                equipments (c, p);
                break;
            case 5:
                showAttributes (c, p);
                break;
            case 6:
                Opponents player, shadow;
                player = trainCharacter (c, &player, p);
                strcpy (player.name, "Takeshi");       
                shadow = trainCharacter (c, &shadow, p);
                fightPvE (c, player, shadow);
                break;
            case 7:
                mainMenu (c, p);
                break;
        }
        return cityMenu (c, p);
}

// Training Tools

Opponents chooseCharacter (Opponents *character, int n)
{
    if (n == 1)
    {
        strcpy(character->name, "Miyamoto Musashi");
        character->level = 10;
        character->elixir = 0;
        character->bonus_hp = 0;
        character->bonus_sta = 0;
        character->health = 27;
        character->attack = 30;
        character->defense = 20;
        character->stamina = 23;
        character->bonus = 0; 
        character->dodge = 0;
    }
    else if (n == 2)
    {
        strcpy(character->name, "Sasaki Kojiro");
        character->level = 10;
        character->elixir = 0;
        character->bonus_hp = 0;
        character->bonus_sta = 0;
        character->health = 22;
        character->attack = 35;
        character->defense = 22;
        character->stamina = 21;
        character->bonus = 0; 
        character->dodge = 0;
    }
    else if (n == 3)
    {
        strcpy(character->name, "Ito Ittosai");
        character->level = 10;
        character->elixir = 0;
        character->bonus_hp = 0;
        character->bonus_sta = 0;
        character->health = 28;
        character->attack = 32;
        character->defense = 20;
        character->stamina = 20;
        character->bonus = 0; 
        character->dodge = 0;
    }
    else if (n == 4)
    {
        strcpy(character->name, "Hattori Hanzo");
        character->level = 10;
        character->elixir = 0;
        character->bonus_hp = 0;
        character->bonus_sta = 0;
        character->health = 20;
        character->attack = 26;
        character->defense = 22;
        character->stamina = 32;
        character->bonus = 0; 
        character->dodge = 0;
    }
    else if (n == 5)
    {
        strcpy(character->name, "Honda Tadakatsu");
        character->level = 10;
        character->elixir = 0;
        character->bonus_hp = 0;
        character->bonus_sta = 0;
        character->health = 30;
        character->attack = 28;
        character->defense = 30;
        character->stamina = 12;
        character->bonus = 0; 
        character->dodge = 0;
    }
    else if (n == 6)
    {
        strcpy(character->name, "Date Masamune");
        character->level = 10;
        character->elixir = 0;
        character->bonus_hp = 0;
        character->bonus_sta = 0;
        character->health = 26;
        character->attack = 30;
        character->defense = 24;
        character->stamina = 20;
        character->bonus = 0; 
        character->dodge = 0;
    }
    else if (n == 7)
    {
        strcpy(character->name, "Sanada Yukimura");
        character->level = 10;
        character->elixir = 0;
        character->bonus_hp = 0;
        character->bonus_sta = 0;
        character->health = 25;
        character->attack = 27;
        character->defense = 25;
        character->stamina = 23;
        character->bonus = 0; 
        character->dodge = 0;
    }
    else if (n == 8)
    {
        strcpy(character->name, "Yagyu Munenori");
        character->level = 10;
        character->elixir = 0;
        character->bonus_hp = 0;
        character->bonus_sta = 0;
        character->health = 24;
        character->attack = 28;
        character->defense = 26;
        character->stamina = 22;
        character->bonus = 0; 
        character->dodge = 0;
    }
    else if (n == 9)
    {
        strcpy(character->name, "Ishida Mitsunari");
        character->level = 10;
        character->elixir = 0;
        character->bonus_hp = 0;
        character->bonus_sta = 0;
        character->health = 22;
        character->attack = 18;
        character->defense = 26;
        character->stamina = 34;
        character->bonus = 0; 
        character->dodge = 0;
    }
    else if (n == 10)
    {
        strcpy(character->name, "Kato Kiyomasa");
        character->level = 10;
        character->elixir = 0;
        character->bonus_hp = 0;
        character->bonus_sta = 0;
        character->health = 29;
        character->attack = 33;
        character->defense = 24;
        character->stamina = 14;
        character->bonus = 0; 
        character->dodge = 0;
    }

    return *character;
}

Opponents trainCharacter (Configs *c, Opponents *character, Character *p)
{
    if (strcmp (c->language, "PT-BR") == 0) strcpy (character->name, "Sombra do Takeshi");
    else strcpy (character->name, "Takeshi's Shadow");
    character->level = p->level;
    character->elixir = 0;
    character->bonus_hp = 0;
    character->bonus_sta = 0;
    character->health = p->health;
    character->attack = p->attack;
    character->defense = p->defense;
    character->stamina = p->stamina;
    character->bonus = 0; 
    character->dodge = 0;

    return *character;
}

int trainingMenu (Configs *c)
{
    int gamemode;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("+-+-+-+-+-+-+-+-+-+ +-+ +-+-+-+-+ +-+-+ +-+-+-+-+");
        printf ("\n|S|E|L|E|C|I|O|N|E| |O| |M|O|D|O| |D|E| |J|O|G|O|");
        printf ("\n+-+-+-+-+-+-+-+-+-+ +-+ +-+-+-+-+ +-+-+ +-+-+-+-+\n");

        printf ("\n*--------------------*");
        printf ("\n| 1 - UM JOGADOR     |");
        printf ("\n*--------------------*");
        printf ("\n| 2 - DOIS JOGADORES |");
        printf ("\n*--------------------*");
        printf ("\n| 3 - ESPECTADOR     |");
        printf ("\n*--------------------*");
        printf ("\n| 4 - SAIR           |");
        printf ("\n*--------------------*\n");

        printf ("\n>>> Comando: ");

        do 
        {
            scanf ("%d", &gamemode);
        } 
        while (gamemode < 1 || gamemode > 4);

        switch (gamemode)
        {
            case 1:

                system (CLEAR);
                printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+");
                printf ("\n|M|O|D|O| |U|M| |J|O|G|A|D|O|R|");
                printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+\n");
                pauseGame (c);
                break;

            case 2:

                system (CLEAR);
                printf ("\n+-+-+-+-+ +-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
                printf ("\n|M|O|D|O| |D|O|I|S| |J|O|G|A|D|O|R|E|S|");
                printf ("\n+-+-+-+-+ +-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");
                pauseGame (c);
                break;

            case 3:

                system (CLEAR);
                printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+");
                printf ("\n|M|O|D|O| |E|S|P|E|C|T|A|D|O|R|");
                printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+\n");
                pauseGame (c);
                break;

            case 4:

                return -1;
                break;
        }

        system (CLEAR);

        printf ("\n+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+");
        printf ("\n|M|I|Y|A|M|O|T|O| |M|U|S|A|S|H|I|");
        printf ("\n+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 27        |");
        printf ("\n| ATAQUE: 30      |");
        printf ("\n| DEFESA: 20      |");
        printf ("\n| RESISTÊNCIA: 23 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+");
        printf ("\n|S|A|S|A|K|I| |K|O|J|I|R|O|");
        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 22        |");
        printf ("\n| ATAQUE: 35      |");
        printf ("\n| DEFESA: 22      |");
        printf ("\n| RESISTÊNCIA: 21 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+ +-+-+-+-+-+-+-+");
        printf ("\n|I|T|O| |I|T|T|O|S|A|I|");
        printf ("\n+-+-+-+ +-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 28        |");
        printf ("\n| ATAQUE: 32      |");
        printf ("\n| DEFESA: 20      |");
        printf ("\n| RESISTÊNCIA: 20 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+-+-+-+ +-+-+-+-+-+");
        printf ("\n|H|A|T|T|O|R|I| |H|A|N|Z|O|");
        printf ("\n+-+-+-+-+-+-+-+ +-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 20        |");
        printf ("\n| ATAQUE: 26      |");
        printf ("\n| DEFESA: 22      |");
        printf ("\n| RESISTÊNCIA: 32 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
        printf ("\n|H|O|N|D|A| |T|A|D|A|K|A|T|S|U|");
        printf ("\n+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 30        |");
        printf ("\n| ATAQUE: 28      |");
        printf ("\n| DEFESA: 30      |");
        printf ("\n| RESISTÊNCIA: 12 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+");
        printf ("\n|D|A|T|E| |M|A|S|A|M|U|N|E|");
        printf ("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 26        |");
        printf ("\n| ATAQUE: 30      |");
        printf ("\n| DEFESA: 24      |");
        printf ("\n| RESISTÊNCIA: 20 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+");
        printf ("\n|S|A|N|A|D|A| |Y|U|K|I|M|U|R|A|");
        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 25        |");
        printf ("\n| ATAQUE: 27      |");
        printf ("\n| DEFESA: 25      |");
        printf ("\n| RESISTÊNCIA: 23 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+-+ +-+-+-+-+-+-+-+-+");
        printf ("\n|Y|A|G|Y|U| |M|U|N|E|N|O|R|I|");
        printf ("\n+-+-+-+-+-+ +-+-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 24        |");
        printf ("\n| ATAQUE: 28      |");
        printf ("\n| DEFESA: 26      |");
        printf ("\n| RESISTÊNCIA: 22 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
        printf ("\n|I|S|H|I|D|A| |M|I|T|S|U|N|A|R|I|");
        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 22        |");
        printf ("\n| ATAQUE: 18      |");
        printf ("\n| DEFESA: 26      |");
        printf ("\n| RESISTÊNCIA: 34 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+");
        printf ("\n|K|A|T|O| |K|I|Y|O|M|A|S|A|");
        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 29        |");
        printf ("\n| ATAQUE: 33      |");
        printf ("\n| DEFESA: 24      |");
        printf ("\n| RESISTÊNCIA: 14 |");
        printf ("\n*-----------------*\n");
    }
    else
    {
        printf ("+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+");
        printf ("\n|S|E|L|E|C|T| |G|A|M|E| |M|O|D|E|");
        printf ("\n+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+\n");

        printf ("\n*-------------------*");
        printf ("\n| 1 - SINGLE PLAYER |");
        printf ("\n*-------------------*");
        printf ("\n| 2 - TWO PLAYERS   |");
        printf ("\n*-------------------*");
        printf ("\n| 3 - SPECTADOR     |");
        printf ("\n*-------------------*");
        printf ("\n| 4 - QUIT          |");
        printf ("\n*-------------------*\n");

        printf ("\n>>> Command: ");

        do 
        {
            scanf ("%d", &gamemode);
        } 
        while (gamemode < 1 || gamemode > 4);

        switch (gamemode)
        {
            case 1:

                system (CLEAR);
                printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+ +-+-+-+-+");
                printf ("\n|S|I|N|G|L|E| |P|L|A|Y|E|R| |M|O|D|E|");
                printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+ +-+-+-+-+\n");
                pauseGame (c);
                break;

            case 2:

                system (CLEAR);
                printf ("\n+-+-+-+ +-+-+-+-+-+-+-+ +-+-+-+-+");
                printf ("\n|T|W|O| |P|L|A|Y|E|R|S| |M|O|D|E|");
                printf ("\n+-+-+-+ +-+-+-+-+-+-+-+ +-+-+-+-+\n");
                pauseGame (c);
                break;

            case 3:

                system (CLEAR);
                printf ("\n+-+-+-+-+-+-+-+-+-+ +-+-+-+-+");
                printf ("\n|S|P|E|C|T|A|D|O|R| |M|O|D|E|");
                printf ("\n+-+-+-+-+-+-+-+-+-+ +-+-+-+-+\n");
                pauseGame (c);
                break;

            case 4:

                return -1;
                break;
        }

        system (CLEAR);

        printf ("\n+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+");
        printf ("\n|M|I|Y|A|M|O|T|O| |M|U|S|A|S|H|I|");
        printf ("\n+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+\n");
        printf ("\n*-------------*");
	    printf ("\n| HEALTH: 27  |");
        printf ("\n| ATTACK: 30  |");
        printf ("\n| DEFENSE: 20 |");
        printf ("\n| STAMINA: 23 |");
        printf ("\n*-------------*\n");

        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+");
        printf ("\n|S|A|S|A|K|I| |K|O|J|I|R|O|");
        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+\n");
        printf ("\n*-------------*");
	    printf ("\n| HEALTH: 22  |");
        printf ("\n| ATTACK: 35  |");
        printf ("\n| DEFENSE: 22 |");
        printf ("\n| STAMINA: 21 |");
        printf ("\n*-------------*\n");

        printf ("\n+-+-+-+ +-+-+-+-+-+-+-+");
        printf ("\n|I|T|O| |I|T|T|O|S|A|I|");
        printf ("\n+-+-+-+ +-+-+-+-+-+-+-+\n");
        printf ("\n*-------------*");
	    printf ("\n| HEALTH: 28  |");
        printf ("\n| ATTACK: 32  |");
        printf ("\n| DEFENSE: 20 |");
        printf ("\n| STAMINA: 20 |");
        printf ("\n*-------------*\n");

        printf ("\n+-+-+-+-+-+-+-+ +-+-+-+-+-+");
        printf ("\n|H|A|T|T|O|R|I| |H|A|N|Z|O|");
        printf ("\n+-+-+-+-+-+-+-+ +-+-+-+-+-+\n");
        printf ("\n*-------------*");
	    printf ("\n| HEALTH: 20  |");
        printf ("\n| ATTACK: 26  |");
        printf ("\n| DEFENSE: 22 |");
        printf ("\n| STAMINA: 32 |");
        printf ("\n*-------------*\n");

        printf ("\n+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
        printf ("\n|H|O|N|D|A| |T|A|D|A|K|A|T|S|U|");
        printf ("\n+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");
        printf ("\n*-------------*");
	    printf ("\n| HEALTH: 30  |");
        printf ("\n| ATTACK: 28  |");
        printf ("\n| DEFENSE: 30 |");
        printf ("\n| STAMINA: 12 |");
        printf ("\n*-------------*\n");

        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+");
        printf ("\n|D|A|T|E| |M|A|S|A|M|U|N|E|");
        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+\n");
        printf ("\n*-------------*");
	    printf ("\n| HEALTH: 26  |");
        printf ("\n| ATTACK: 30  |");
        printf ("\n| DEFENSE: 24 |");
        printf ("\n| STAMINA: 20 |");
        printf ("\n*-------------*\n");

        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+");
        printf ("\n|S|A|N|A|D|A| |Y|U|K|I|M|U|R|A|");
        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+\n");
        printf ("\n*-------------*");
	    printf ("\n| HEALTH: 25  |");
        printf ("\n| ATTACK: 27  |");
        printf ("\n| DEFENSE: 25 |");
        printf ("\n| STAMINA: 23 |");
        printf ("\n*-------------*\n");

        printf ("\n+-+-+-+-+-+ +-+-+-+-+-+-+-+-+");
        printf ("\n|Y|A|G|Y|U| |M|U|N|E|N|O|R|I|");
        printf ("\n+-+-+-+-+-+ +-+-+-+-+-+-+-+-+\n");
        printf ("\n*-------------*");
	    printf ("\n| HEALTH: 24  |");
        printf ("\n| ATTACK: 28  |");
        printf ("\n| DEFENSE: 26 |");
        printf ("\n| STAMINA: 22 |");
        printf ("\n*-------------*\n");

        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
        printf ("\n|I|S|H|I|D|A| |M|I|T|S|U|N|A|R|I|");
        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");
        printf ("\n*-------------*");
	    printf ("\n| HEALTH: 22  |");
        printf ("\n| ATTACK: 18  |");
        printf ("\n| DEFENSE: 26 |");
        printf ("\n| STAMINA: 34 |");
        printf ("\n*-------------*\n");

        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+");
        printf ("\n|K|A|T|O| |K|I|Y|O|M|A|S|A|");
        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+\n");
        printf ("\n*-------------*");
	    printf ("\n| HEALTH: 29  |");
        printf ("\n| ATTACK: 33  |");
        printf ("\n| DEFENSE: 24 |");
        printf ("\n| STAMINA: 14 |");
        printf ("\n*-------------*\n");
    }
        printf ("\n%%---%%---%%---%%---%%---%%---%%---%%---%%\n");

        printf ("\n*-----------------------*");
        printf ("\n| 1 - MIYAMOTO MUSASHI  |");
        printf ("\n*-----------------------*");
        printf ("\n| 2 - SASAKI KOJIRO     |");
        printf ("\n*-----------------------*");
        printf ("\n| 3 - ITO ITTOSAI       |");
        printf ("\n*-----------------------*");
        printf ("\n| 4 - HATTORI HANZO     |");
        printf ("\n*-----------------------*");
        printf ("\n| 5 - HONDA TADAKATSU   |");
        printf ("\n*-----------------------*");
        printf ("\n| 6 - DATE MASAMUNE     |");
        printf ("\n*-----------------------*");
        printf ("\n| 7 - SANADA YUKIMURA   |");
        printf ("\n*-----------------------*");
        printf ("\n| 8 - YAGYU MUNENORI    |");
        printf ("\n*-----------------------*");
        printf ("\n| 9 - ISHIDA MITSUNARI  |");
        printf ("\n*-----------------------*");
        printf ("\n| 10 - KATO KIYOMASA    |");
        printf ("\n*-----------------------*\n");

        return gamemode;
}

int training (Configs *c)
{
    Opponents P1, P2;
    int char1 = 0, char2 = 0, gamemode = 0;
    
    if (strcmp (c->language, "PT-BR") == 0)
    {
        gamemode = trainingMenu (c);

        if (gamemode == -1)
        {
            return -1;
        }

        printf ("\n==> JOGADOR 1 <==\n");

        printf ("\n+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+-+-+-+");
        printf ("\n|E|S|C|O|L|H|A| |S|E|U| |P|E|R|S|O|N|A|G|E|M|");
        printf ("\n+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+-+-+-+\n");

        printf("\n>>> Comando: ");
    
        do 
        {
            scanf ("%d", &char1);
        } 
        while (char1 < 1 || char1 > 10);

        if (gamemode == 2)
        {
            printf ("\n\n==> JOGADOR 2 <==\n");

            printf ("\n+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+-+-+-+");
            printf ("\n|E|S|C|O|L|H|A| |S|E|U| |P|E|R|S|O|N|A|G|E|M|");
            printf ("\n+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+-+-+-+\n");
        }
        else 
        {
            printf ("\n+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+-+-+-+");
            printf ("\n|E|S|C|O|L|H|A| |S|E|U| |A|D|V|E|R|S|Á|R|I|O|");
            printf ("\n+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+-+-+-+\n");
        }

        printf("\n>>> Comando: ");
    
        do 
        {
            scanf ("%d", &char2);
        } 
        while (char2 < 1 || char2 > 10);
    }
    else
    {
        gamemode = trainingMenu (c);

        printf ("\n==> PLAYER 1 <==\n");

        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
        printf ("\n|C|H|O|O|S|E| |Y|O|U|R| |C|H|A|R|A|C|T|E|R|");
        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");

        printf("\n>>> Command: ");
    
        do 
        {
            scanf ("%d", &char1);
        } 
        while (char1 < 1 || char1 > 10);

        if (gamemode == 2)
        {
            printf ("\n\n==> PLAYER 2 <==\n");

            printf ("\n+-+-+-+-+-+-+ +-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
            printf ("\n|C|H|O|O|S|E| |Y|O|U|R| |C|H|A|R|A|C|T|E|R|");
            printf ("\n+-+-+-+-+-+-+ +-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");
        }
        else 
        {
            printf ("\n+-+-+-+-+-+-+ +-+-+-+-+ +-+-+-+-+-+-+-+-+");
            printf ("\n|C|H|O|O|S|E| |Y|O|U|R| |O|P|P|O|N|E|N|T|");
            printf ("\n+-+-+-+-+-+-+ +-+-+-+-+ +-+-+-+-+-+-+-+-+\n");
        }

        printf("\n>>> Command: ");
    
        do 
        {
            scanf ("%d", &char2);
        } 
        while (char2 < 1 || char2 > 10);
    }

    P1 = chooseCharacter (&P1, char1);
    P2 = chooseCharacter (&P2, char2);

    switch (gamemode)
    {
    case 1:
        fightPvE (c, P1, P2);
        break;
    case 2:
        fightPvP (c, P1, P2);
        break;
    case 3:
        fightEvE (c, P1, P2);
        break;
    default:
        return 0;
    }

    return 0;
}
 
// Combat Tools

int firstAttack (int stamina01, int stamina02)
{
    srand (time (NULL));
    int n = 0;

    if (stamina01 > stamina02)
    {
        return 1;
    }
    else if (stamina02 > stamina01)
    {
        return 2;
    }
    else
    {
        n = rand () % 2;
        n = n < 0 ? 0 : n;
        n += 1;
        return n;
    }
}

int checkStamina (Configs *c, int stamina, int choice)
{
    if (strcmp (c->language, "PT-BR") == 0)
    {
        if (choice == 1 && stamina < 35)
        {
            printf ("*---VIGOR INSUFICIENTE!---*\n\n\n");
            msleep (c->txt_speed);
            return 3;
        }
        else if (choice == 2 && stamina < 15)
        {
            printf ("*---VIGOR INSUFICIENTE!---*\n\n\n");
            msleep (c->txt_speed);
            return 3;
        }
        else
        {
            return choice;
        }
    }
    else
    {
        if (choice == 1 && stamina < 35)
        {
            printf ("*---INSUFFICIENT STAMINA!---*\n\n\n");
            msleep (c->txt_speed);
            return 3;
        }
        else if (choice == 2 && stamina < 15)
        {
            printf ("*---INSUFFICIENT STAMINA!---*\n\n\n");
            msleep (c->txt_speed);
            return 3;
        }
        else
        {
            return choice;
        }
    }
    return choice;
}

int criticalChance (int attack)
{
    srand (time (NULL));
    float critical = attack * 0.75;
    float chance = rand () % 100 + 1;

    return (chance <= critical);
}

int damageCalc (Configs *c, int attack, int bonus, int dodge, int half_def)
{
    srand (time (NULL));
    int e_dodge;
    int damage = attack + (rand () % 16);
    damage = damage < 0 ? 0 : damage;
    if (strcmp (c->language, "PT-BR") == 0)
    {
        if (criticalChance (damage))
        {
            damage *= 1.85;
            printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+");
            printf ("\n|D|A|N|O| |C|R|Í|T|I|C|O|");
            printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+\n\n\n");
        }
    }
    else
    {
        if (criticalChance (damage))
        {
            damage *= 1.85;
            printf ("\n+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+");
            printf ("\n|C|R|I|T|I|C|A|L| |D|A|M|A|G|E|");
            printf ("\n+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+\n\n\n");
        }
    }
    e_dodge = (half_def) + (rand () % (half_def));
    e_dodge = e_dodge < 0 ? 0 : e_dodge;
    damage -= e_dodge + dodge;
    damage = damage + bonus + 15;
    if (damage < 0) damage = 0;

    return damage;
}

void damageResult (Configs *c, char name[], char e_name[], int e_health, int damage)
{
    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("==> %s ataca o %s com sua Katana <==\n", name, e_name);

        msleep (c->txt_speed * 1000);

        printf ("\n\n==> %s inflige %03d de dano a %s <==\n", name, damage, e_name);

        msleep (c->txt_speed * 1000);

        printf ("\n\n*---Vida de %s: %03d---*\n", e_name, e_health);

        msleep (c->txt_speed * 1000);

    }
    else
    {
        printf ("==> %s attacks %s with his Katana <==\n", name, e_name);

        msleep (c->txt_speed * 1000);

        printf ("\n\n==> %s deals %03d damage to %s <==\n", name, damage, e_name);

        msleep (c->txt_speed * 1000);

        printf ("\n\n*---Life of %s: %03d---*\n", e_name, e_health);

        msleep (c->txt_speed * 1000);
    }
    
    if (e_health == 0)
    {
        pauseGame (c);
        system (CLEAR);
        if (strcmp (c->language, "PT-BR") == 0) printf ("*---%s foi derrotado!---*\n", e_name);
        else printf ("*---%s was defeated!---*\n", e_name);
    }
}

int defenseCalc (Configs *c, char name[], int half_def, int bonus, char e_name[])
{
    srand (time (NULL));
    int dodge = (half_def) + (rand () % (half_def));
    dodge = dodge < 0 ? 0 : dodge;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("==> %s planeja se defende do ataque de %s <==\n", name, e_name);

        printf ("\n\n*---Bônus de Defesa: %d---*\n", dodge);

        printf ("\n*---Bônus de Ataque: %d---*\n", bonus);
    }
    else
    {
        printf ("==> %s plans to defend %s's attack <==\n", name, e_name);

        printf ("\n\n*---Defense Bonus: %d---*\n", dodge);

        printf ("\n*---Attack Bonus: %d---*\n", bonus);
    }

    return dodge;
}

int aiDecision (Configs *c, Opponents ai, Opponents player)
{
    srand (time (NULL));
    int dmgPotential = damageCalc (c, ai.attack, ai.bonus, player.dodge, player.defense * 0.5);
    int playDmgPotential = damageCalc (c, player.attack, player.bonus, ai.dodge, ai.defense * 0.5);

    if (playDmgPotential >= ai.health && ai.elixir >= 1) return 4;
    else if (ai.stamina >= 35 && dmgPotential >= player.health) return 1;
    else if ((ai.stamina >= 15 && ai.stamina <= 35) && dmgPotential >= player.health) return 3;
    else if (ai.stamina >= 35 && ai.bonus >= ((ai.defense / 4) + 15) * 3) return 1;
    else if (ai.stamina >= 15 && ai.health <= (player.health || playDmgPotential)) return 2;
    else if (ai.stamina >= 35 && (ai.health > player.health || ai.bonus >= ((ai.defense / 4) + 15) * 3)) return 1;
    else if (ai.stamina < 15) return 3;

    return (rand () % 2) + 1;
}

void battleMenu (Configs *c, char name[], int health, int elixir, int stamina, int bonus, int e_health, int e_stamina)
{
    if (strcmp (c->language, "PT-BR") == 0)
    {
        system (CLEAR);

        printf ("\n==> Hora de agir, %s <==\n", name);

        msleep (c->txt_speed * 1000);

        printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+");
        printf ("\n|M|E|N|U| |D|A| |B|A|T|A|L|H|A|");
        printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+\n");

        printf ("\n*----------------------------------*");
        printf ("\n| VIDA: %03d                        |", health);
        printf ("\n*----------------------------------*");
        printf ("\n| RESISTÊNCIA: %03d                 |", stamina);
        printf ("\n*----------------------------------*");
        printf ("\n| BÔNUS DE ATAQUE: %03d             |", bonus);
        printf ("\n*----------------------------------*");
        printf ("\n| ELIXIR DA CURA DO IMPERADOR: %d/3 |", elixir);
        printf ("\n*----------------------------------*\n");

        printf ("\n*-------------------------------------------*");
        printf ("\n| 1 - ATACAR / -35 PONTOS DE RESISTÊNCIA    |");
        printf ("\n*-------------------------------------------*");
        printf ("\n| 2 - DEFENDER / -15 PONTOS DE RESISTÊNCIA  |");
        printf ("\n*-------------------------------------------*");
        printf ("\n| 3 - DESCANSAR / +50 PONTOS DE RESISTÊNCIA |");
        printf ("\n*-------------------------------------------*");
        printf ("\n| 4 - USAR ELIXIR DA CURA DO IMPERADOR      |");
        printf ("\n*-------------------------------------------*\n");

        printf ("\n*---Vida do Inimigo: %d---*\n", e_health);

        printf ("\n*---Resistência do Inimigo: %d---*\n", e_stamina);

        printf ("\n\n>>> Comando: ");
    }
    else
    {
        system (CLEAR);

        printf ("\n==> Time to act, %s <==\n", name);

        msleep (c->txt_speed * 100);

        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+");
        printf ("\n|M|E|N|U| |B|A|T|T|L|E|");
        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+\n");

        printf ("\n*-------------------------------*");
        printf ("\n| HEALTH: %03d                   |", health);
        printf ("\n*-------------------------------*");
        printf ("\n| STAMINA: %03d                  |", stamina);
        printf ("\n*-------------------------------*");
        printf ("\n| ATTACK BONUS: %03d             |", bonus);
        printf ("\n*-------------------------------*");
        printf ("\n| EMPEROR'S HEALING ELIXIR: %d/3 |", elixir);
        printf ("\n*-------------------------------*\n");

        printf ("\n*----------------------------------*");
        printf ("\n| 1 - ATTACK / -35 STAMINA POINTS  |");
        printf ("\n*----------------------------------*");
        printf ("\n| 2 - DEFEND / -15 STAMINA POINTS  |");
        printf ("\n*------- --------------------------*");
        printf ("\n| 3 - REST / +50 STAMINA POINTS    |");
        printf ("\n*----------------------------------*");
        printf ("\n| 4 - USE EMPEROR'S HEALING ELIXIR |");
        printf ("\n*----------------------------------*\n");

        printf ("\n*---Enemy Life: %d---*\n", e_health);

        printf ("\n*---Enemy Stamina: %d---*\n", e_stamina);

        printf ("\n\n>>> Command: ");
    }
    return;
}

int looserMenu (Configs *c, Character *p)
{
    int n;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("\n*------------------------------*");
        printf ("\n| 1 - TENTAR NOVAMENTE         |");
        printf ("\n*------------------------------*");
        printf ("\n| 2 - VOLTAR AO MENU PRINCIPAL |");
        printf ("\n*------------------------------*\n");
        
        printf ("\n>>> Comando: ");
    }
    else
    {
        printf ("\n*-------------------------*");
        printf ("\n| 1 - TRY AGAIN           |");
        printf ("\n*-------------------------*");
        printf ("\n| 2 - RETURN TO MAIN MENU |");
        printf ("\n*-------------------------*\n");
        
        printf ("\n>>> Command: ");
    }
    
    do 
    {
        scanf ("%d", &n);
    } 
    while (n != 1 && n != 2);

    switch (n) 
    {
        case 1:
            return 0;
            break;
        case 2:
            return mainMenu (c, p);
            break;
    }
    return 0;
}

int executeTurn (Configs *c, Opponents *ttk, Opponents *def, int isPlayerTurn)
{
    int choice, damage, half_def, max_bonus;

    if (isPlayerTurn == 1 || isPlayerTurn == 2) 
    battleMenu (c, ttk->name, ttk->health, ttk->elixir, ttk->stamina, ttk->bonus, def->health, def->stamina);

    if (isPlayerTurn)
    {
        do 
        {
            scanf ("%d", &choice);
        } 
        while (choice < 1 || choice > 4);
    } 
    else 
    {
        choice = aiDecision (c, *ttk, *def);
    }

    system (CLEAR);

    choice = checkStamina (c, ttk->stamina, choice);
    half_def = def->defense * 0.5;
    max_bonus = ((ttk->defense / 4) + 15) * 3;

    switch (choice) 
    {
        case 1:
            ttk->stamina -= 35;
            if (ttk->stamina < 0) ttk->stamina = 0;

            damage = damageCalc (c, ttk->attack, ttk->bonus, def->dodge, half_def);
            if (damage < 0) damage = 0;

            def->health -= damage;
            if (def->health < 0) def->health = 0;

            ttk->bonus = 0;
            def->dodge = 0;

            damageResult (c, ttk->name, def->name, def->health, damage);

            if (def->health == 0) 
            {
                pauseGame (c);
                if (isPlayerTurn == 1) asciiArt (c, 7);
                else if (isPlayerTurn == 2) asciiArt (c, 8);
                else asciiArt (c, 9);
                return 1;
            }
            break;
        case 2:
            ttk->stamina -= 15;
            if (ttk->stamina < 0) ttk->stamina = 0;

            if (max_bonus > ttk->bonus) ttk->bonus += (ttk->defense / 4) + 15;
            ttk->dodge = defenseCalc (c, ttk->name, half_def, ttk->bonus, def->name);

            break;
        case 3:
            ttk->stamina += 50;
            ttk->dodge = 0;

            printf ("==> %s %s <==\n", ttk->name, strcmp (c->language, "PT-BR") == 0 ? "está vulnerável" : "is vulnerable");

            msleep (c->txt_speed * 1000);
            break;
        case 4:
            if (ttk->elixir <= 0) 
            {
                ttk->elixir -= 1;
                ttk->health += 50;
                printf ("==> %s <==\n", strcmp (c->language, "PT-BR") == 0 ? "+50 Vida Recuperada!" : "+50 Life Recovered!");
                pauseGame (c);
                return executeTurn (c, ttk, def, isPlayerTurn);
            }
            else
            {
                printf ("==> %s <==\n", strcmp (c->language, "PT-BR") == 0 ? "Elixir Insuficiente!" : "Insufficient Elixir!");
                pauseGame (c);
                return executeTurn (c, ttk, def, isPlayerTurn);
            }
            break;
    }
    pauseGame (c);
    system (CLEAR);
    return 0;
}

int fightPvP (Configs *c, Opponents P1, Opponents P2)
{
    int round = 1, first;

    P1.bonus = 0; P1.dodge = 0;
    P1.bonus = 0; P2.dodge = 0;

    P1.health *= 10;
    P2.health *= 10;
    P1.stamina *= 5;
    P2.stamina *= 5;

    while (P1.health != 0 || P2.health != 0)
    {
        system (CLEAR);
        printf ("\n+-+-+-+-+-+ +--+");
        printf ("\n|R|O|U|N|D| |%02d|", round);
        printf ("\n+-+-+-+-+-+ +--+\n");
        pauseGame (c);

        first = firstAttack (P1.stamina, P2.stamina);
        
        if (first == 1)
        {
            if (executeTurn (c, &P1, &P2, 1)) return 1;     
            if (executeTurn (c, &P2, &P1, 2)) return 1;
        }
        else 
        {
            if (executeTurn(c, &P2, &P1, 2)) return 1;
            if (executeTurn(c, &P1, &P2, 1)) return 1;
        }
        round++;
        P1.stamina += 5;
        P2.stamina += 5;
    }
    return 0;
}

int fightPvE (Configs *c, Opponents player, Opponents ai)
{
    int round = 1, first;

    player.bonus = 0; player.dodge = 0;
    ai.bonus = 0; ai.dodge = 0;

    player.health *= 10;
    ai.health *= 10;
    player.stamina *= 5;
    ai.stamina *= 5;

    while (player.health > 0 && ai.health > 0) 
    {
        system (CLEAR);
        printf("\n+-+-+-+-+-+ +--+");
        printf("\n|R|O|U|N|D| |%02d|", round);
        printf("\n+-+-+-+-+-+ +--+\n");
        pauseGame (c);

        first = firstAttack (player.stamina, ai.stamina);

        if (first == 1) 
        {
            if (executeTurn (c, &player, &ai, 1)) return 1;
            if (executeTurn (c, &ai, &player, 0)) return 2;
        } 
        else 
        {
            if (executeTurn (c, &ai, &player, 0)) return 2;
            if (executeTurn (c, &player, &ai, 1)) return 1;
        }
        player.stamina += 5;
        ai.stamina += 5;
        round++;
    }
    return 0;
}

int fightEvE (Configs *c, Opponents ai1, Opponents ai2)
{
    int round = 1, first;

    ai1.bonus = 0; ai1.dodge = 0;
    ai2.bonus = 0; ai2.dodge = 0;

    ai1.health *= 10;
    ai2.health *= 10;
    ai1.stamina *= 5;
    ai2.stamina *= 5;

    while (ai1.health > 0 && ai2.health > 0) 
    {
        system (CLEAR);
        printf("\n+-+-+-+-+-+ +--+");
        printf("\n|R|O|U|N|D| |%02d|", round);
        printf("\n+-+-+-+-+-+ +--+\n");
        pauseGame (c);

        if (strcmp (c->language, "PT-BR") == 0)
        {
            printf ("\n*---Vida do %s: %d---*\n", ai1.name, ai1.health);

            printf ("\n*---Resistência do %s: %d---*\n", ai1.name, ai1.stamina);

            printf ("\n*---Bônus de Ataque do %s: %d---*\n", ai1.name, ai1.bonus);

            printf ("\n%%---%%---%%---%%---%%---%%---%%---%%---%%\n");

            printf ("\n*---Vida do %s: %d---*\n", ai2.name, ai2.health);

            printf ("\n*---Resistência do %s: %d---*\n", ai2.name, ai2.stamina);

            printf ("\n*---Bônus de Ataque do %s: %d---*\n", ai2.name, ai2.bonus);
        }
        else
        {
            printf ("\n*---%s's Life: %d---*\n", ai1.name, ai1.health);

            printf ("\n*---%s's Stamina: %d---*\n", ai1.name, ai1.stamina);

            printf ("\n*---%s's Attack Bonus: %d---*\n", ai1.name, ai1.bonus);

            printf ("\n%%---%%---%%---%%---%%---%%---%%---%%---%%\n");

            printf ("\n*---%s's Life: %d---*\n", ai2.name, ai2.health);

            printf ("\n*---%s's Stamina: %d---*\n", ai2.name, ai2.stamina);

            printf ("\n*---%s's Attack Bonus: %d---*\n", ai2.name, ai2.bonus);
        }
        
        pauseGame (c);
        first = firstAttack (ai1.stamina, ai2.stamina);

        if (first == 1) 
        {
            if (executeTurn (c, &ai1, &ai2, 0)) return 1;
            if (executeTurn (c, &ai2, &ai1, 0)) return 2;
        } 
        else 
        {
            if (executeTurn (c, &ai2, &ai1, 0)) return 2;
            if (executeTurn (c, &ai1, &ai2, 0)) return 1;
        }
        ai1.stamina += 5;
        ai2.stamina += 5;
        round++;
    }
    return 0;
}
 
#endif