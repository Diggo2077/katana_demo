#ifndef HEADERS_H
#define HEADERS_H

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

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

int speed;

typedef struct mainCharacter_
{
    int level = 1;
    int xp = 0;
    int attributes = 0;
    int ryos = 200;
    int health;
    int injury;
    int attack;
    int bonus = 0;
    int defense;
    int dodge = 0;
    int stamina;
    int fatigue = 0;
    int ginseng = 0;
    int elixir = 0;
    int sake = 0;
    int tiger = 0;
    int fenix = 0;
    int dragon = 0;
    int chapter;
} 
Character;

typedef struct Opponents_
{
    char name[40];
    int level;
    int health;
    int ginseng = 0;
    int injury = 0;
    int attack;
    int bonus = 0;
    int defense;
    int dodge = 0;
    int stamina;
    int fatigue = 0;
} 
Opponents;

typedef struct Configs_
{
    char language[10];
    int txt_speed;
}
Configs;

Character loadGame ();
void saveGame (Character p);
Configs loadConfigs ();
void saveConfigs (Configs c);
void msleep (int mlseconds);
void pause (const Configs *c);
void asciiArt (const Configs *c, int n);
int mainMenu (Configs *c, Character *p);
void options (Configs *c, Character *p);

int training (Configs *c);
Opponents chooseCharacter (Opponents *character, int n);

Configs c;
Character p;

void saveConfigs (Configs c)
{
    FILE *archive = fopen ("saves/configs.dat", "wb");
    fwrite (&c, sizeof(Configs), 1, archive);
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

void saveGame (Character p) 
{
    FILE *archive = fopen ("saves/save.dat", "wb");
    fwrite (&p, sizeof(Character), 1, archive);
    fclose (archive);
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

void pause (const Configs *c)
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
            msleep (speed);
        }

        fclose (credits);

        pause (c);

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
                msleep (speed);
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
                msleep (speed);
        }

        fclose (archive);

        pause (c);
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
                msleep (speed);
        }

        fclose (archive);

        pause (c);
    }

    return;
}

#endif