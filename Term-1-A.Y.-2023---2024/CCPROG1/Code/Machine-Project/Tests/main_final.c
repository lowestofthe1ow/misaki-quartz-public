#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "unit_0.c"
#include "unit_1.c"
#include "unit_2.c"
#include "unit_3.c"
#include "unit_4.c"

#define WINDOW_WIDTH 80 // ISO/ANSI screen width is 80 characters.
#define COLUMN_WIDTH_1 WINDOW_WIDTH / 3
#define COLUMN_WIDTH_2 WINDOW_WIDTH / 3 * 2 + 1

/* This function handles the selection of equipment for the player and the enemy
 * @param *nPlayerHP is a pointer to the address storing the player's HP stat
 * @param *nPlayerATK is a pointer to the address storing the player's ATK stat
 * @param *nPlayerDEF is a pointer to the address storing the player's DEF stat
 * @param *nPlayerSPD is a pointer to the address storing the player's SPD stat
 * @param *nPlayerCrit is a pointer to the address storing the player's critical chance stat
 * @param *nEnemyHP is a pointer to the address storing the enemy's HP stat
 * @param *nEnemyATK is a pointer to the address storing the enemy's ATK stat
 * @param *nEnemyDEF is a pointer to the address storing the enemy's DEF stat
 * @param *nEnemySPD is a pointer to the address storing the enemy's SPD stat
 * @param *nEnemyCrit is a pointer to the address storing the enemy's critical chance stat
 */
void
statsByEquip (/* Player stats */
              int    *nPlayerHP,
              int    *nPlayerATK,
              int    *nPlayerDEF,
              int    *nPlayerSPD,
              int    *nPlayerCrit,
              /* Enemy stats */
              int    *nEnemyHP,
              int    *nEnemyATK,
              int    *nEnemyDEF,
              int    *nEnemySPD,
              int    *nEnemyCrit)
{
        int equipConfirmed = 0;
        
        while (equipConfirmed == 0) {
                *nPlayerHP = 100;
                *nPlayerATK = 10;
                *nPlayerDEF = 10;
                *nPlayerSPD = 10;
                *nPlayerCrit = 15;
                equipConfirmed = promptPlayerEquipConfirm (nPlayerHP,
                                                           nPlayerATK,
                                                           nPlayerDEF,
                                                           nPlayerSPD,
                                                           nPlayerCrit);
        }
        
        promptEnemyEquipConfirm (nEnemyHP,
                                 nEnemyATK,
                                 nEnemyDEF,
                                 nEnemySPD,
                                 nEnemyCrit);;
}

/* This function handles inputting of stats for either the player or the enemy
 * @param *nTargetHP is a pointer to the address storing the target's HP stat 
 * @param *nTargetATK is a pointer to the address storing the target's ATK stat
 * @param *nTargetDEF is a pointer to the address storing the target's DEF stat
 * @param *nTargetSPD is a pointer to the address storing the target's SPD stat
 * @param *nTargetCrit is a pointer to the address storing the target's critical chance stat
 */
void
promptSetStats (int    *nTargetHP,
                int    *nTargetATK,
                int    *nTargetDEF,
                int    *nTargetSPD,
                int    *nTargetCrit)
{
        int nStatsConfirmed = 0;
	
	/* Get and validate stats input
         * getchar() removes trailing newline from input stream
         */
	while (nStatsConfirmed == 0) {
	        /* scanf() must read exactly 5 inputs */
		if (scanf(" %d/%d/%d/%d/%d", nTargetHP, nTargetATK, nTargetDEF, nTargetSPD, nTargetCrit) != 5)
		      printf(">> Invalid input. Try again: ");
		/* HP, ATK, DEF, and SPD must be at most 999 */
		else if (*nTargetHP > 999 || *nTargetATK > 999 || *nTargetDEF > 999 || *nTargetSPD > 999)
		      printf(">> HP, ATK, DEF, and SPD cannot be higher than 999. Try again: ");
		/* nTargetCrit must be at most 100 */
		else if (*nTargetCrit > 100)
		      printf(">> Critical hit chance cannot be higher than 100. Try again: ");
		/* Input is valid */
		else
		      nStatsConfirmed = 1;
		getchar();
	}
}

/* This function handles the setting of stats for the player and the enemy when Dev Mode is selected
 * @param *nPlayerHP is a pointer to the address storing the player's HP stat
 * @param *nPlayerATK is a pointer to the address storing the player's ATK stat
 * @param *nPlayerDEF is a pointer to the address storing the player's DEF stat
 * @param *nPlayerSPD is a pointer to the address storing the player's SPD stat
 * @param *nPlayerCrit is a pointer to the address storing the player's critical chance stat
 * @param *nEnemyHP is a pointer to the address storing the enemy's HP stat
 * @param *nEnemyATK is a pointer to the address storing the enemy's ATK stat
 * @param *nEnemyDEF is a pointer to the address storing the enemy's DEF stat
 * @param *nEnemySPD is a pointer to the address storing the enemy's SPD stat
 * @param *nEnemyCrit is a pointer to the address storing the enemy's critical chance stat
 */
void
statsByDevMode (/* Player stats */
                int    *nPlayerHP,
                int    *nPlayerATK,
                int    *nPlayerDEF,
                int    *nPlayerSPD,
                int    *nPlayerCrit,
                /* Enemy stats */
                int    *nEnemyHP,
                int    *nEnemyATK,
                int    *nEnemyDEF,
                int    *nEnemySPD,
                int    *nEnemyCrit)
{
	system("cls");
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "Enter player stats separated by forward slashes (HP/ATK/DEF/SPD/CRIT)", '|', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "Critical chance is expressed as a number from 0 to 100.", '|', '\n');
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	printf(">> ");
	
	/* Prompt user to input stats for the player */
	promptSetStats (nPlayerHP,
                        nPlayerATK,
                        nPlayerDEF,
                        nPlayerSPD,
                        nPlayerCrit);
        
	system("cls");
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "Enter enemy stats separated by forward slashes (HP/ATK/DEF/SPD/CRIT)", '|', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "Critical chance is expressed as a number from 0 to 100.", '|', '\n');
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	printf(">> ");
	
	/* Prompt user to input stats for the enemy */
	promptSetStats (nEnemyHP,
                        nEnemyATK,
                        nEnemyDEF,
                        nEnemySPD,
                        nEnemyCrit);;
}

/* This function prints a prompt that allows the user to select a gameplay mode
 * @return 0 or 1, depending on the mode chosen.
 */
int
promptSelectMode ()
{
	system("cls");
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "Select a mode", '|', '\n');
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	
	printf("\n");
	
	printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '=', ']', '\n');
	
	printBlock(0, COLUMN_WIDTH_1, '|', "[0] Standard game", '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "Choose among sets of weapons and armor to equip", '|', '\n');
	
	printBlock(0, COLUMN_WIDTH_1, '|', "[1] Dev mode", '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "Manually input player and enemy stats", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '=', ']', '\n');
	
	printf("\n");
	
	printBorder(COLUMN_WIDTH_1, '[', '=', ']', '\n');
	
	printBlock(0, COLUMN_WIDTH_1, '|', "Choose. (0/1)", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '=', ']', '\n');
	
	printf(">> ");
	
	int nInput = 0;
	
	/* Get input */
	scanf(" %d", &nInput);
	getchar();
	
	/* Validate input, can only be 0 or 1
         * getchar() removes trailing newline from input stream
         */
	while (nInput < 0 || nInput > 1) {
		printf(">> Invalid input. Try again: ");
		scanf(" %d", &nInput);
		getchar();
	}
	
	return nInput;
}

int
main ()
{
        /* Initialize seed for rand() */
        srand(time(NULL));
        
        /* Print the title screen */
        showTitleScreen();
        
        /* Initialize player and enemy stats */
        int nPlayerHP = 100, nPlayerATK = 10, nPlayerDEF = 10, nPlayerSPD = 10, nPlayerCrit = 15;
        int nEnemyHP = 100, nEnemyATK = 10, nEnemyDEF = 10, nEnemySPD = 10, nEnemyCrit = 15;
        
        /* Determine gameplay mode */
        int nIsDevMode = promptSelectMode();
        
        /* Set player and enemy stats depending on whether gamplay mode is Standard or Dev Mode */
        if (nIsDevMode)
                /* Set stats manually (Dev Mode) */
                statsByDevMode (&nPlayerHP,
                                &nPlayerATK,
                                &nPlayerDEF,
                                &nPlayerSPD,
                                &nPlayerCrit,
                                &nEnemyHP,
                                &nEnemyATK,
                                &nEnemyDEF,
                                &nEnemySPD,
                                &nEnemyCrit);
        else
                /* Set stats through equipmment (Standard) */
                statsByEquip (&nPlayerHP,
                              &nPlayerATK,
                              &nPlayerDEF,
                              &nPlayerSPD,
                              &nPlayerCrit,
                              &nEnemyHP,
                              &nEnemyATK,
                              &nEnemyDEF,
                              &nEnemySPD,
                              &nEnemyCrit);

        /* Initialize player and enemy's current HP as max of their respective base values */
        int nPlayerCurrentHP = nPlayerHP, nEnemyCurrentHP = nEnemyHP;
        
        /* Begin the battle loop */
        beginBattle (&nPlayerCurrentHP,
                     &nPlayerHP,
                     &nPlayerATK,
                     &nPlayerDEF,
                     &nPlayerSPD,
                     &nPlayerCrit,
                     &nEnemyCurrentHP,
                     &nEnemyHP,
                     &nEnemyATK,
                     &nEnemyDEF,
                     &nEnemySPD,
                     &nEnemyCrit);
        
        printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
        printBlock(1, WINDOW_WIDTH, '|', "G A M E   O V E R", '|', '\n');
	
        if (nPlayerCurrentHP == 0 && nEnemyCurrentHP > 0)
                printBlock(1, WINDOW_WIDTH, '|', "You lost...", '|', '\n');
        else if (nPlayerCurrentHP > 0 && nEnemyCurrentHP == 0)
                printBlock(1, WINDOW_WIDTH, '|', "You won!", '|', '\n');
        else
                printBlock(1, WINDOW_WIDTH, '|', "It's a draw!", '|', '\n');
        
        printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
        
        playerConfirm();
}
