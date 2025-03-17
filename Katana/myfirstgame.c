#include "headers.h"

int main (int argc, char const *argv[])
{
    setlocale (LC_ALL, "pt_BR.UTF-8");
    
    c = loadConfigs ();
    if (c.txt_speed == 1) speed = 350;
    else if (c.txt_speed == 2) speed = 200;
    else speed = 0;
    mainMenu (&c, &p);
}

void msleep (int mlseconds)
{
    #ifdef _WIN32
        Sleep (mlseconds / 1000);
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
	    printf ("\n| 4 - CR?DITOS  |");
	    printf ("\n*---------------*");
	    printf ("\n| 5 - OP??ES    |");
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

void options (Configs *c, Character *p)
{
    system (CLEAR);
    
    int n = 0, s = 0, l = 0;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("\n+-+-+-+-+-+-+");
        printf ("\n|O|P|?|?|E|S|");
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

        do
        {
            scanf ("%d", &n);
        } 
        while (n < 1 || n > 4);

        system (CLEAR);

        switch (n)
        {
            case 1:
            
                printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+");
                printf ("\n|V|E|L|O|C|I|D|A|D|E| |D|O| |T|E|X|T|O|");
                printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+\n");

                printf ("\n*-----------------*");
	            printf ("\n| 1 - LENTO       |");
	            printf ("\n*-----------------*");
	            printf ("\n| 2 - R?PIDO      |");
	            printf ("\n*-----------------*");
	            printf ("\n| 3 - INSTANT?NEO |");
	            printf ("\n*-----------------*");
	            printf ("\n| 4 - SAIR        |");
	            printf ("\n*-----------------*\n");

                printf ("\n>>> Comando: ");

                do
                {
                    scanf ("%d", &s);
                } 
                while (s < 1 || s > 4);

                system (CLEAR);

                switch (s)
                {
                    case 1:

                        c->txt_speed = 1;
                        printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+");
                        printf ("\n|V|E|L|O|C|I|D|A|D|E| |L|E|N|T|A|");
                        printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+\n");
                        saveConfigs (*c);
                        pause (c);
                        options (c, p);
                        break;

                    case 2:

                        c->txt_speed = 2;
                        printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+");
                        printf ("\n|V|E|L|O|C|I|D|A|D|E| |R|?|P|I|D|A|");
                        printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+\n");
                        saveConfigs (*c);
                        pause (c);
                        options (c, p);
                        break;

                    case 3:

                        c->txt_speed = 3;
                        printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+-+");
                        printf ("\n|V|E|L|O|C|I|D|A|D|E| |I|N|S|T|A|N|T|?|N|E|A|");
                        printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+-+\n");
                        saveConfigs (*c);
                        pause (c);
                        options (c, p);
                        break;

                    case 4:

                        options (c, p);
                        break;
                }
                break;

            case 2:

                printf ("\n+-+-+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+");
                printf ("\n|L|I|N|G|U|A|G|E|M| |D|O| |J|O|G|O|");
                printf ("\n+-+-+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+\n");

                printf ("\n*-------------------------*");
                printf ("\n| 1 - INGL?S              |");
                printf ("\n*-------------------------*");
                printf ("\n| 2 - PORTUGU?S DO BRASIL |");
                printf ("\n*-------------------------*");
                printf ("\n| 3 - SAIR                |");
                printf ("\n*-------------------------*\n");

                printf ("\n>>> Comando: ");

                do
                {
                    scanf ("%d", &l);
                } 
                while (l < 1 || l > 3);

                system (CLEAR);

                switch (l)
                {
                    case 1:
                        
                        strcpy(c->language, "EN-US");
                        printf ("\n+-+-+-+-+-+-+");
                        printf ("\n|I|N|G|L|?|S|");
                        printf ("\n+-+-+-+-+-+-+\n");
                        saveConfigs (*c);
                        pause (c);
                        options (c, p);
                        break;
                    
                    case 2:

                        strcpy(c->language, "PT-BR");
                        printf ("\n+-+-+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+-+");
                        printf ("\n|P|O|R|T|U|G|U|?|S| |D|O| |B|R|A|S|I|L|");
                        printf ("\n+-+-+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+-+\n");
                        saveConfigs (*c);
                        pause (c);
                        options (c, p);
                        break;

                    case 3:

                        options (c, p);
                        break;
                }
                break;
        
            case 3:
                
                //
                break;

            case 4:

                mainMenu (c, p);
                break;
        
        }
        
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

        do
        {
            scanf ("%d", &n);
        } 
        while (n < 1 || n > 4);

        system (CLEAR);

        switch (n)
        {
            case 1:
            
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
                scanf ("%d", &s);
            } 
            while (s < 1 || s > 4);

            system (CLEAR);

            switch (s)
            {
                case 1:

                    c->txt_speed = 1;
                    printf ("\n+-+-+-+-+ +-+-+-+-+-+");
                    printf ("\n|S|L|O|W| |S|P|E|E|D|");
                    printf ("\n+-+-+-+-+ +-+-+-+-+-+\n");
                    saveConfigs (*c);
                    pause (c);
                    options (c, p);
                    break;

                case 2:

                    c->txt_speed = 2;
                    printf ("\n+-+-+-+-+ +-+-+-+-+-+");
                    printf ("\n|F|A|S|T| |S|P|E|E|D|");
                    printf ("\n+-+-+-+-+ +-+-+-+-+-+\n");
                    saveConfigs (*c);
                    pause (c);
                    options (c, p);
                    break;

                case 3:

                    c->txt_speed = 3;
                    printf ("\n+-+-+-+-+-+-+-+ +-+-+-+-+-+");
                    printf ("\n|I|N|S|T|A|N|T| |S|P|E|E|D|");
                    printf ("\n+-+-+-+-+-+-+-+ +-+-+-+-+-+\n");
                    saveConfigs (*c);
                    pause (c);
                    options (c, p);
                    break;

                case 4:

                    options (c, p);
                    break;
            }
            break;

            case 2:

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
                    scanf ("%d", &l);
                } 
                while (l < 1 || l > 3);

                system (CLEAR);

                switch (l)
                {
                    case 1:
                        
                        strcpy(c->language, "EN-US");
                        printf ("\n+-+-+-+-+-+-+-+");
                        printf ("\n|E|N|G|L|I|S|H|");
                        printf ("\n+-+-+-+-+-+-+-+\n");
                        saveConfigs (*c);
                        pause (c);
                        options (c, p);
                        break;                    
                
                    case 2:

                        strcpy(c->language, "PT-BR");
                        printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+ +-+-+-+-+-+-+");
                        printf ("\n|P|O|R|T|U|G|U|E|S|E| |-| |B|R|A|Z|I|L|");
                        printf ("\n+-+-+-+-+-+-+-+-+-+-+ +-+ +-+-+-+-+-+-+\n");
                        saveConfigs (*c);
                        pause (c);
                        options (c, p);
                        break;

                    case 3:

                        options (c, p);
                        break;
                }
                break;
            
            case 3:

                break;

            case 4:

                mainMenu(c, p);
                break;
                
        }
    }
}

int firstAttack (int stamina01, int stamina02)
{
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
        n = rand() % 2;
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
            msleep (2000);
            return 3;
        }
        else if (choice == 2 && stamina < 15)
        {
            printf ("*---VIGOR INSUFICIENTE!---*\n\n\n");
            msleep (2000);
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
            msleep (2000);
            return 3;
        }
        else if (choice == 2 && stamina < 15)
        {
            printf ("*---INSUFFICIENT STAMINA!---*\n\n\n");
            msleep (2000);
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
    float critical = attack * 0.8;
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
            damage *= 1.75;
            printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+");
            printf ("\n|D|A|N|O| |C|R|?|T|I|C|O|");
            printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+");
        }
        else
        {
            damage *= 1.75;
            printf ("\n+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+");
            printf ("\n|C|R|I|T|I|C|A|L| |D|A|M|A|G|E|");
            printf ("\n+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+");
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

        msleep (3000000);

        printf ("\n\n==> %s inflige %03d de dano a %s <==\n", name, damage, e_name);

        msleep (2000000);

        printf ("\n\n*---Vida de %s: %03d---*\n", e_name, e_health);

        msleep (1000000);

    }
    else
    {
        printf ("==> %s attacks %s with his Katana <==\n", name, e_name);

        msleep (3000000);

        printf ("\n\n==> %s deals %03d damage to %s <==\n", name, damage, e_name);

        msleep (2000000);

        printf ("\n\n*---Life of %s: %03d---*\n", e_name, e_health);

        msleep (1000000);
    }
    
    if (e_health == 0)
    {
        msleep (500000);
        system (CLEAR);
        if (strcmp (c->language, "PT-BR") == 0) printf ("*---%s foi derrotado!---*\n", e_name);
        else printf ("*---%s was defeated!---*\n", e_name);
    }
}

int defenseCalc (Configs *c, char name[], int half_def, int bonus, char e_name[])
{
    int dodge = (half_def) + (rand () % (half_def));
    dodge = dodge < 0 ? 0 : dodge;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("==> %s planeja se def do ataque de %s <==\n", name, e_name);

        printf ("\n\n*---B?nus de Defesa: %d---*\n", dodge);

        printf ("\n*---B?nus de Ataque: %d---*\n", bonus);
    }
    else
    {
        printf ("==> %s plans to defend %s's attack <==\n", name, e_name);

        printf ("\n\n*---Defense Bonus: %d---*\n", dodge);

        printf ("\n*---Attack Bonus: %d---*\n", bonus);
    }

    return dodge;
}

void battleMenu (Configs *c, char name[], int health, int stamina, int bonus, int e_health, int e_stamina)
{
    if (strcmp (c->language, "PT-BR") == 0)
    {
        system (CLEAR);

        printf ("\n==> Hora de agir, %s <==\n", name);

        msleep (3000);

        printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+");
        printf ("\n|M|E|N|U| |D|A| |B|A|T|A|L|H|A|");
        printf ("\n+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+\n");

        printf ("\n*----------------------*");
        printf ("\n| VIDA: %03d            |", health);
        printf ("\n*----------------------*");
        printf ("\n| RESIST?NCIA: %03d     |", stamina);
        printf ("\n*----------------------*");
        printf ("\n| B?NUS DE ATAQUE: %03d |", bonus);
        printf ("\n*----------------------*\n");

        printf ("\n*-------------------------------------------*");
        printf ("\n| 1 - ATACAR / -35 PONTOS DE RESIST?NCIA    |");
        printf ("\n*-------------------------------------------*");
        printf ("\n| 2 - DEFENDER / -15 PONTOS DE RESIST?NCIA  |");
        printf ("\n*-------------------------------------------*");
        printf ("\n| 3 - DESCANSAR / +50 PONTOS DE RESIST?NCIA |");
        printf ("\n*-------------------------------------------*\n");

        printf ("\n*---Vida do Inimigo: %d---*\n", e_health);

        printf ("\n*---Resist?ncia do Inimigo: %d---*\n", e_stamina);

        printf ("\n\n>>> Comando: ");
    }
    else
    {
        system (CLEAR);

        printf ("\n==> Time to act, %s <==\n", name);

        msleep (3000);

        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+");
        printf ("\n|M|E|N|U| |B|A|T|T|L|E|");
        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+\n");

        printf ("\n*----------------------*");
        printf ("\n| HEALTH: %03d          |", health);
        printf ("\n*----------------------*");
        printf ("\n| STAMINA: %03d         |", stamina);
        printf ("\n*----------------------*");
        printf ("\n| ATTACK BONUS: %03d    |", bonus);
        printf ("\n*----------------------*\n");

        printf ("\n*-------------------------------------------*");
        printf ("\n| 1 - ATTACK / -35 STAMINA POINTS           |");
        printf ("\n*-------------------------------------------*");
        printf ("\n| 2 - DEFEND / -15 STAMINA POINTS           |");
        printf ("\n*-------------------------------------------*");
        printf ("\n| 3 - REST / +50 STAMINA POINTS             |");
        printf ("\n*-------------------------------------------*\n");

        printf ("\n*---Enemy Life: %d---*\n", e_health);

        printf ("\n*---Enemy Stamina: %d---*\n", e_stamina);

        printf ("\n\n>>> Command: ");
    }

    return;
}

int aiDecision (Configs *c, Opponents ai, Opponents player)
{
    int dmgPotential = damageCalc (c, ai.attack, ai.bonus, player.dodge, player.defense * 0.5);
    int playDmgPotential = damageCalc (c, player.attack, player.bonus, ai.dodge, ai.defense * 0.5);

    if (ai.stamina >= 35 && dmgPotential >= player.health) return 1;
    else if ((ai.stamina >= 15 && ai.stamina <= 35) && dmgPotential >= player.health) return 3;
    else if (ai.stamina >= 15 && ai.health <= player.health && playDmgPotential > (ai.health * 0.5)) return 2;

    if (ai.stamina >= 35)
    {
        if (ai.health > player.health || ai.bonus >= ((ai.defense / 4) + 15) * 2) return 1;
        else return 2;
    }
    else if (ai.stamina < 15) return 3;

    return (rand() % 2) + 1;
}

int executeTurn (Configs *c, Opponents *ttk, Opponents *def, int isPlayerTurn)
{
    int choice, damage, half_def, max_bonus;

    if (isPlayerTurn == 1 || isPlayerTurn == 2) 
    battleMenu (c, ttk->name, ttk->health, ttk->stamina, ttk->bonus, def->health, def->stamina);

    if (isPlayerTurn)
    {
        do 
        {
            scanf ("%d", &choice);
        } 
        while (choice < 1 || choice > 3);
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

            msleep (3000);

            damage = damageCalc (c, ttk->attack, ttk->bonus, def->dodge, half_def);
            if (damage < 0) damage = 0;

            def->health -= damage;
            if (def->health < 0) def->health = 0;

            ttk->bonus = 0;
            def->dodge = 0;

            damageResult (c, ttk->name, def->name, def->health, damage);

            if (def->health == 0) 
            {
                pause (c);
                if (isPlayerTurn == 1) asciiArt (c, 7);
                else if (isPlayerTurn == 2) asciiArt (c, 8);
                else asciiArt (c, 9);
                return 1;
            }
            break;

        case 2:
            
            ttk->stamina -= 15;
            if (ttk->stamina < 0) ttk->stamina = 0;

            msleep (3000);

            if (max_bonus > ttk->bonus) ttk->bonus += (ttk->defense / 4) + 15;
            ttk->dodge = defenseCalc (c, ttk->name, half_def, ttk->bonus, def->name);

            msleep (1000);
            break;

        case 3:

            ttk->stamina += 50;
            ttk->dodge = 0;

            printf ("==> %s %s <==\n", ttk->name, strcmp (c->language, "PT-BR") == 0 ? "est? vulner?vel" : "is vulnerable");
            msleep (3000);
            break;
    }

    pause(c);
    system(CLEAR);
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

        first = firstAttack (P1.stamina, P2.stamina);
        msleep (5000);
        
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

        first = firstAttack (player.stamina, ai.stamina);
        msleep (5000);

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

        if (strcmp (c->language, "PT-BR") == 0)
        {
            printf ("\n*---Vida do %s: %d---*\n", ai1.name, ai1.health);

            printf ("\n*---Resist?ncia do %s: %d---*\n", ai1.name, ai1.stamina);

            printf ("\n*---B?nus de Ataque do %s: %d---*\n", ai1.name, ai1.bonus);

            printf ("\n%%---%%---%%---%%---%%---%%---%%---%%---%%\n");

            printf ("\n*---Vida do %s: %d---*\n", ai2.name, ai2.health);

            printf ("\n*---Resist?ncia do %s: %d---*\n", ai2.name, ai2.stamina);

            printf ("\n*---B?nus de Ataque do %s: %d---*\n", ai2.name, ai2.bonus);
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
        
        pause (c);
        first = firstAttack (ai1.stamina, ai2.stamina);
        msleep (5000);

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

Opponents chooseCharacter (Opponents *character, int n)
{
    if (n == 1)
    {
        strcpy(character->name, "Miyamoto Musashi");
        character->level = 10;
        character->healing = 0;
        character->injury = 0;
        character->fatigue = 0;
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
        character->healing = 0;
        character->injury = 0;
        character->fatigue = 0;
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
        character->healing = 0;
        character->injury = 0;
        character->fatigue = 0;
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
        character->healing = 0;
        character->injury = 0;
        character->fatigue = 0;
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
        character->healing = 0;
        character->injury = 0;
        character->fatigue = 0;
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
        character->healing = 0;
        character->injury = 0;
        character->fatigue = 0;
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
        character->healing = 0;
        character->injury = 0;
        character->fatigue = 0;
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
        character->healing = 0;
        character->injury = 0;
        character->fatigue = 0;
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
        character->healing = 0;
        character->injury = 0;
        character->fatigue = 0;
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
        character->healing = 0;
        character->injury = 0;
        character->fatigue = 0;
        character->health = 29;
        character->attack = 33;
        character->defense = 24;
        character->stamina = 14;
        character->bonus = 0; 
        character->dodge = 0;
    }

    return *character;
}

int trainingMenu (Configs *c)
{
    int gamemode;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("\n+-+-+-+-+-+-+-+-+-+ +-+ +-+-+-+-+ +-+-+ +-+-+-+-+");
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
                pause (c);
                break;

            case 2:

                system (CLEAR);
                printf ("\n+-+-+-+-+ +-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
                printf ("\n|M|O|D|O| |D|O|I|S| |J|O|G|A|D|O|R|E|S|");
                printf ("\n+-+-+-+-+ +-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");
                pause (c);
                break;

            case 3:

                system (CLEAR);
                printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+");
                printf ("\n|M|O|D|O| |E|S|P|E|C|T|A|D|O|R|");
                printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+\n");
                pause (c);
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
        printf ("\n| RESIST?NCIA: 23 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+");
        printf ("\n|S|A|S|A|K|I| |K|O|J|I|R|O|");
        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 22        |");
        printf ("\n| ATAQUE: 35      |");
        printf ("\n| DEFESA: 22      |");
        printf ("\n| RESIST?NCIA: 21 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+ +-+-+-+-+-+-+-+");
        printf ("\n|I|T|O| |I|T|T|O|S|A|I|");
        printf ("\n+-+-+-+ +-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 28        |");
        printf ("\n| ATAQUE: 32      |");
        printf ("\n| DEFESA: 20      |");
        printf ("\n| RESIST?NCIA: 20 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+-+-+-+ +-+-+-+-+-+");
        printf ("\n|H|A|T|T|O|R|I| |H|A|N|Z|O|");
        printf ("\n+-+-+-+-+-+-+-+ +-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 20        |");
        printf ("\n| ATAQUE: 26      |");
        printf ("\n| DEFESA: 22      |");
        printf ("\n| RESIST?NCIA: 32 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
        printf ("\n|H|O|N|D|A| |T|A|D|A|K|A|T|S|U|");
        printf ("\n+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 30        |");
        printf ("\n| ATAQUE: 28      |");
        printf ("\n| DEFESA: 30      |");
        printf ("\n| RESIST?NCIA: 12 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+");
        printf ("\n|D|A|T|E| |M|A|S|A|M|U|N|E|");
        printf ("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 26        |");
        printf ("\n| ATAQUE: 30      |");
        printf ("\n| DEFESA: 24      |");
        printf ("\n| RESIST?NCIA: 20 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+");
        printf ("\n|S|A|N|A|D|A| |Y|U|K|I|M|U|R|A|");
        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 25        |");
        printf ("\n| ATAQUE: 27      |");
        printf ("\n| DEFESA: 25      |");
        printf ("\n| RESIST?NCIA: 23 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+-+ +-+-+-+-+-+-+-+-+");
        printf ("\n|Y|A|G|Y|U| |M|U|N|E|N|O|R|I|");
        printf ("\n+-+-+-+-+-+ +-+-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 24        |");
        printf ("\n| ATAQUE: 28      |");
        printf ("\n| DEFESA: 26      |");
        printf ("\n| RESIST?NCIA: 22 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
        printf ("\n|I|S|H|I|D|A| |M|I|T|S|U|N|A|R|I|");
        printf ("\n+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 22        |");
        printf ("\n| ATAQUE: 18      |");
        printf ("\n| DEFESA: 26      |");
        printf ("\n| RESIST?NCIA: 34 |");
        printf ("\n*-----------------*\n");

        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+");
        printf ("\n|K|A|T|O| |K|I|Y|O|M|A|S|A|");
        printf ("\n+-+-+-+-+ +-+-+-+-+-+-+-+-+\n");
        printf ("\n*-----------------*");
	    printf ("\n| VIDA: 29        |");
        printf ("\n| ATAQUE: 33      |");
        printf ("\n| DEFESA: 24      |");
        printf ("\n| RESIST?NCIA: 14 |");
        printf ("\n*-----------------*\n");
    }
    else
    {
        printf ("\n+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+");
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
                pause (c);
                break;

            case 2:

                system (CLEAR);
                printf ("\n+-+-+-+ +-+-+-+-+-+-+-+ +-+-+-+-+");
                printf ("\n|T|W|O| |P|L|A|Y|E|R|S| |M|O|D|E|");
                printf ("\n+-+-+-+ +-+-+-+-+-+-+-+ +-+-+-+-+\n");
                pause (c);
                break;

            case 3:

                system (CLEAR);
                printf ("\n+-+-+-+-+-+-+-+-+-+ +-+-+-+-+");
                printf ("\n|S|P|E|C|T|A|D|O|R| |M|O|D|E|");
                printf ("\n+-+-+-+-+-+-+-+-+-+ +-+-+-+-+\n");
                pause (c);
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

        printf ("\n===> JOGADOR 1 <===\n");

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
            printf ("\n\n===> JOGADOR 2 <===\n");

            printf ("\n+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+-+-+-+");
            printf ("\n|E|S|C|O|L|H|A| |S|E|U| |P|E|R|S|O|N|A|G|E|M|");
            printf ("\n+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+-+-+-+\n");
        }
        else 
        {
            printf ("\n+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+-+-+-+");
            printf ("\n|E|S|C|O|L|H|A| |S|E|U| |A|D|V|E|R|S|?|R|I|O|");
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

        printf ("\n===> PLAYER 1 <===\n");

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
            printf ("\n\n===> PLAYER 2 <===\n");

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

int lvl (Configs *c, Character *Takeshi) 
{
    int old_level = Takeshi->level;

    if (Takeshi->xp >= 0 && Takeshi->xp <= 1000) Takeshi->level = 1;
    else if (Takeshi->xp >= 1000 && Takeshi->xp < 3000) Takeshi->level = 2;
    else if (Takeshi->xp >= 3000 && Takeshi->xp < 5000) Takeshi->level = 3;
    else if (Takeshi->xp >= 5000 && Takeshi->xp < 7000) Takeshi->level = 4;
    else if (Takeshi->xp >= 7000 && Takeshi->xp < 10000) Takeshi->level = 5;
    else if (Takeshi->xp >= 10000 && Takeshi->xp < 25000) Takeshi->level = 6;
    else if (Takeshi->xp >= 25000 && Takeshi->xp < 50000) Takeshi->level = 7;
    else if (Takeshi->xp >= 50000 && Takeshi->xp < 75000) Takeshi->level = 8;
    else if (Takeshi->xp >= 75000 && Takeshi->xp < 100000) Takeshi->level = 9;
    else Takeshi->level = 10;

    if (Takeshi->level != old_level) 
    {
        if (strcmp (c->language, "PT-BR") == 0)
        {
            printf ("\n+-+-+-+-+ +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
            printf ("\n|N|O|V|O| |N|?|V|E|L| |A|L|C|A|N|?|A|D|O|");
            printf ("\n+-+-+-+-+ +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");
        }
        else
        {
            printf ("\n+-+-+-+ +-+-+-+-+-+ +-+-+-+-+-+-+-+");
            printf ("\n|N|E|W| |L|E|V|E|L| |R|E|A|C|H|E|D|");
            printf ("\n+-+-+-+ +-+-+-+-+-+ +-+-+-+-+-+-+-+\n");
        }

        Takeshi->attributes += (Takeshi->level - old_level);
        pause (c);
    }
    return 0;
}

void showAttributes (Configs *c, Character *Takeshi)
{
    int attr = 0;

    if (strcmp (c->language, "PT-BR") == 0)
    {
        printf ("\n+-+-+-+-+-+ +-+ +-+-+-+-+-+-+-+-+-+");
        printf ("\n|N|?|V|E|L| |E| |A|T|R|I|B|U|T|O|S|");
        printf ("\n+-+-+-+-+-+ +-+ +-+-+-+-+-+-+-+-+-+\n");
    
        printf ("\n*----------------------------------------*");
        printf ("\n|               N?vel: %02d                |", Takeshi->level);
        printf ("\n*----------------------------------------*");
        printf ("\n|         Experi?ncia: %06d            |", Takeshi->xp);
        printf ("\n*----------------------------------------*");
        printf ("\n| Pontos de Habilidades Dispon?veis: %02d  |", Takeshi->attributes);
        printf ("\n*----------------------------------------*\n");
    
        printf ("\n*-----------------------*");
        printf ("\n| Vida: %03d - %02d        |", Takeshi->health * 10, Takeshi->injury);
        printf ("\n*-----------------------*");
        printf ("\n| Ataque: %03d + %02d      |", Takeshi->attack, Takeshi->bonus);
        printf ("\n*-----------------------*");
        printf ("\n| Defesa: %03d           |", Takeshi->defense);
        printf ("\n*-----------------------*");
        printf ("\n| Resist?ncia: %03d - %02d |", Takeshi->stamina * 5, Takeshi->fatigue);
        printf ("\n*-----------------------*\n");
    
        if (Takeshi->attributes > 0) 
        {
            printf ("\n*---Pontos de Habilidade Dispon?veis: %02d---*\n", Takeshi->attributes);
    
            printf ("\n*-----------------*");
            printf ("\n| 1 - VIDA        |");
            printf ("\n*-----------------*");
            printf ("\n| 2 - ATAQUE      |");
            printf ("\n*-----------------*");
            printf ("\n| 3 - DEFESA      |");
            printf ("\n*-----------------*");
            printf ("\n| 4 - VELOCIDADE  |");
            printf ("\n*-----------------*");
            printf ("\n| 5 - RESIST?NCIA |");
            printf ("\n*-----------------*");
            printf ("\n| 6 - SAIR        |");
            printf ("\n*-----------------*\n");

            printf ("\n>>> Comando: ");

            do 
            {
                scanf ("%d", &attr);
            }
            while (attr < 1 || attr > 6);

            switch (attr) {

                case 1:
                    printf ("\n\n*---VIDA +1---*\n\n");
                    Takeshi->health += 1;
                    Takeshi->attributes -= 1;
                    break;
                case 2:
                    printf ("\n\n*---ATAQUE +1---*\n\n");
                    Takeshi->attack += 1;
                    Takeshi->attributes -= 1;
                    break;
                case 3:
                    printf ("\n\n*---DEFESA +1---*\n\n");
                    Takeshi->defense += 1;
                    Takeshi->attributes -= 1;
                    break;
                case 4:
                    printf ("\n\n*---RESIST?NCIA +1---*\n\n");
                    Takeshi->stamina += 1;
                    Takeshi->attributes -= 1;
                    break;
                case 5:
                    return 0;
            }
            pause (c);
            return showAttributes (c, Takeshi);
        } 
        else pause (c);
    }
    else
    {
        printf ("\n+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+-+-+-+");
        printf ("\n|L|E|V|E|L| |A|N|D| |A|T|T|R|I|B|U|T|E|S|");
        printf ("\n+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+-+-+-+\n");
    
        printf ("\n*-----------------------------*");
        printf ("\n|           Level: %02d         |", Takeshi->level);
        printf ("\n*-----------------------------*");
        printf ("\n|     Experience: %06d      |", Takeshi->xp);
        printf ("\n*-----------------------------*");
        printf ("\n| Available Skill Points: %02d  |", Takeshi->attributes);
        printf ("\n*-----------------------------*\n");
    
        printf ("\n*-------------------*");
        printf ("\n| Health: %03d - %02d  |", Takeshi->health * 10, Takeshi->injury);
        printf ("\n*-------------------*");
        printf ("\n| Attack: %03d + %02d  |", Takeshi->attack, Takeshi->bonus);
        printf ("\n*-------------------*");
        printf ("\n| Defense: %03d         |", Takeshi->defense);
        printf ("\n*-------------------*");
        printf ("\n| Stamina: %03d - %02d |", Takeshi->stamina * 5, Takeshi->fatigue);
        printf ("\n*-------------------*\n");
    
        if (Takeshi->attributes > 0) 
        {
            printf ("\n*---Available Skill Points: %02d---*\n", Takeshi->attributes);
    
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
                    Takeshi->health += 1;
                    Takeshi->attributes -= 1;
                    break;
                case 2:
                    printf ("\n\n*---ATTACK +1---*\n\n");
                    Takeshi->attack += 1;
                    Takeshi->attributes -= 1;
                    break;
                case 3:
                    printf ("\n\n*---DEFENSE +1---*\n\n");
                    Takeshi->defense += 1;
                    Takeshi->attributes -= 1;
                    break;
                case 4:
                    printf ("\n\n*---STAMINA +1---*\n\n");
                    Takeshi->stamina += 1;
                    Takeshi->attributes -= 1;
                    break;
                case 5:
                    return 0;
            }
            pause (c);
            return showAttributes (c, Takeshi);
        } 
        else pause (c);
    }
}

void inventory (Configs *c, Character *Takeshi)
{
        int choice = 0;

        printf ("\n+-+-+-+-+-+-+-+-+-+-+");
        printf ("\n|I|N|V|E|N|T|?|R|I|O|");
        printf ("\n+-+-+-+-+-+-+-+-+-+-+\n");

        printf ("\n*---Ry?s: %03d---*\n", Takeshi->ryos);

        printf ("\n*----------------------------------*");
        printf ("\n| P?lulas de Ginseng: %d/3          |", Takeshi->ginseng);
        printf ("\n*----------------------------------*");
        printf ("\n| Elixir da Cura do Imperador: %d/1 |", Takeshi->elixir);
        printf ("\n*----------------------------------*");
        printf ("\n| Saqu? de Fogo do Drag?o: %d/1     |", Takeshi->sake);
        printf ("\n*----------------------------------*\n");

        printf ("\n*---Armadura do Tigre de K?zuke: %s---*", Takeshi->tiger == 1 ? "Equipar" : "N?o Possu?do");
        printf ("\n*---Armadura da F?nix Imortal: %s---*", Takeshi->fenix == 1 ? "Equipar" : "N?o Possu?do");
        printf ("\n*---Armadura do Drag?o Celestial: %s---*\n", Takeshi->dragon == 1 ? "Equipar" : "N?o Possu?do");

        printf ("\n*----------------------------------*");
        printf ("\n| 1 - P?LULAS DE GINSENG           |");
        printf ("\n*----------------------------------*");
        printf ("\n| 2 - ELIXIR DA CURA DO IMPERADOR  |");
        printf ("\n*----------------------------------*");
        printf ("\n| 3 - SAQU? DO FOGO DO DRAG?O      |");
        printf ("\n*----------------------------------*");
        printf ("\n| 4 - ARMADURA DO TIGRE DE K?ZUKE  |");
        printf ("\n*----------------------------------*");
        printf ("\n| 5 - ARMADURA DA F?NIX IMORTAL    |");
        printf ("\n*----------------------------------*");
        printf ("\n| 6 - ARMADURA DO DRAG?O CELESTIAL |");
        printf ("\n*----------------------------------*");
        printf ("\n| 7 - SAIR                         |");
        printf ("\n*----------------------------------*\n");

        printf ("\n>>> Comando: ");

        do 
        {
        scanf ("%d", &choice);
        } 
        while (choice < 1 || choice > 7);

        switch (escolha_erva) {

        case 1:

            if (*medicinal == 0) printf ("\n\n*---P?LULAS INSUFICIENTES---*\n\n");
            else if (*lesao == 0) printf ("\n\n*---ENERGIA M?XIMA---*\n\n");
            else {
                *medicinal -= 1;
                *lesao -= 100;
                if (*lesao < 0) *lesao = 0;
                printf ("\n\n*---LES?O = %d---*", *lesao);
                printf ("\n\n===>-1 P?LULAS DE GINSENG<===\n\n");

            }
            break;

        case 2:

            if (*revigorante == 0) printf ("\n\n*---ELIXIR INSUFICIENTE---*\n\n");
            else if (*fadiga == 0) printf ("\n\n*---ENERGIA M?XIMA---*\n\n");
            else {
                *revigorante -= 1;
                *fadiga -= 100;
                if (*fadiga < 0) *fadiga = 0;
                printf ("\n\n*---FADIGA = %d---*", *fadiga);
                printf ("\n\n===>-1 ELIXIR DA CURA DO IMPERADOR<===\n\n");
            }
            break;

        case 3:

            if (*potencializadora == 0) printf ("\n\n*---SAQU?S INSUFICIENTES---*\n\n");
            else if (*vigor == 25) printf ("\n\n*---EFEITO M?XIMO ALCAN?ADO---*\n\n");
            else {
                *potencializadora += 1;
                *vigor = 25;
                printf ("\n\n*---VIGOR = %d---*", *vigor);
                printf ("\n\n===>-1 SAQU? DO FOGO DO DRAG?O<===\n\n");
            }
            break;

        case 4:

            return 0;

        }


        pause ();

        return inventario (ryos, medicinal, revigorante, potencializadora, lesao, fadiga, vigor);

}
}