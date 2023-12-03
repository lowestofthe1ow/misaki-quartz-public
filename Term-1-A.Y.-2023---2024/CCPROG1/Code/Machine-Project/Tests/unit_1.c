#define WINDOW_WIDTH 80 // ISO/ANSI screen width is 80 characters.
#define COLUMN_WIDTH_1 WINDOW_WIDTH / 3
#define COLUMN_WIDTH_2 WINDOW_WIDTH / 3 * 2 + 1

/* This function displays a summary of the target's stats and equipment
 * @param nHP is the target's HP stat
 * @param nATK is the target's ATK stat
 * @param nDEF is the target's DEF stat
 * @param nSPD is the target's SPD stat
 * @param nCrit is the target's critical hit chance
 * @param *cSelectedWeaponName is the name of the target's weapon
 * @param *cSelectedArmorName is the name of the target's armor
 */
void
showCurrentStatsEquip (int      nHP,
                       int      nATK,
                       int      nDEF,
                       int      nSPD,
                       int      nCrit,
                       char    *cSelectedWeaponName,
                       char    *cSelectedArmorName)
{        
        printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder(COLUMN_WIDTH_1, '[', '=', ']', '\n');
        
        printBlock(1, COLUMN_WIDTH_1, '|', "Stats", '|', ' ');
        printBlock(1, COLUMN_WIDTH_1, '|', "Weapon", '|', ' ');
        printBlock(1, COLUMN_WIDTH_1, '|', "Armor", '|', '\n');
        
        printBorder(COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder(COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder(COLUMN_WIDTH_1, '[', '-', ']', '\n');
        
        printf("| ATK   \\ DEF   \\ SPD%*c ", COLUMN_WIDTH_1 - 21, '|');
        printBlock(0, COLUMN_WIDTH_1, '|', cSelectedWeaponName, '|', ' ');
        printBlock(0, COLUMN_WIDTH_1, '|', cSelectedArmorName, '|', '\n');
        
        printf("| %-4d  / %-4d  / %-4d%*c ", nATK, nDEF, nSPD, COLUMN_WIDTH_1 - 22, '|');
        printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBorder(COLUMN_WIDTH_1, '|', ' ', '|', '\n');
        
        printBorder(COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBorder(COLUMN_WIDTH_1, '|', ' ', '|', '\n');
        
        printf("| Base HP: %3d%*c ", nHP, COLUMN_WIDTH_1 - 14, '|');
        printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBorder(COLUMN_WIDTH_1, '|', ' ', '|', '\n');
        
        printf("| Critical chance: %3d%%%*c ", nCrit, COLUMN_WIDTH_1 - 23, '|');
        printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBorder(COLUMN_WIDTH_1, '|', ' ', '|', '\n');
        
        printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder(COLUMN_WIDTH_1, '[', '=', ']', '\n');
}

/* This function 'equips' a weapon on the target and returns the weapon name
 * 'Equipping' refers to adding the weapon's stats to the target's
 * Precondition: nInput is 0, 1, 2, or 3
 * @param *nTargetATK is a pointer to the address storing the target's ATK stat
 * @param *nTargetSPD is a pointer to the address storing the target's SPD stat
 * @param nInput is the integer indicating the chosen weapon
 * @return A string literal containing the weapon's name
 */
char *
equipWeapon(int         *nTargetATK,
            int         *nTargetSPD,
            int         nInput)
{
        /* 'Equip' weapon based on selection input */
        switch (nInput) {
                default: case 0:
                        *nTargetATK += 15;
                        *nTargetSPD += 3;
                        return "Dagger";
                case 1:
                        *nTargetATK += 20;
                        return "Katana";
                case 2:
                        *nTargetATK += 40;
                        *nTargetSPD -= 5;
                        return "Broadsword";
                case 3:
                        *nTargetSPD += 10;
                        return "Fist";
        }
}

/* This function 'equips' an armor on the target and returns the armor name
 * 'Equipping' refers to adding the armor's stats to the target's
 * Precondition: nInput is 0, 1, 2, or 3
 * @param *nTargetATK is a pointer to the address storing the target's ATK stat
 * @param *nTargetSPD is a pointer to the address storing the target's SPD stat
 * @param nInput is the integer indicating the chosen armor
 * @return A string literal containing the armor's name
 */
char *
equipArmor(int *nTargetHP,
           int *nTargetDEF,
           int *nTargetSPD,
           int  nInput)
{
        /* 'Equip' armor based on selection input */
        switch (nInput) {
                default: case 0:
                        *nTargetDEF += 3;
                        *nTargetSPD += 3;
                        return "Mythril";
                case 1:
                        *nTargetHP += 5;
                        *nTargetDEF += 8;
                        return "Chainmail";
                case 2:
                        *nTargetHP += 10;
                        *nTargetDEF += 18;
                        *nTargetSPD -= 4;
                        return "Adamantite armor";
                case 3:
                        *nTargetSPD += 10;
                        return "No armor";
        }
}

/* This function prints a series of prompts that allow the user to select a weapon.
 * @return 0, 1, 2, or 3, depending on the weapon chosen.
 */
int
promptWeaponSelect ()
{
	system("cls");
	
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	
	printBlock(1, WINDOW_WIDTH, '|', "Select a weapon.", '|', '\n');
	
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	
	printf("\n");
	
	printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '=', ']', '\n');
	
	printBlock(1, COLUMN_WIDTH_1, '|', "Weapon", '|', ' ');
	printBlock(1, COLUMN_WIDTH_2, '|', "Details", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '-', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '-', ']', '\n');
	
	printBlock(0, COLUMN_WIDTH_1, '|', "[0] Dagger", '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "A low-ATK weapon that slightly improves speed.", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "(ATK + 15, SPD + 3)", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '-', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '-', ']', '\n');
	
	printBlock(0, COLUMN_WIDTH_1, '|', "[1] Katana", '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "A slim blade with moderately high ATK power.", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "(ATK + 20)", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '-', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '-', ']', '\n');
	
	printBlock(0, COLUMN_WIDTH_1, '|', "[2] Broadsword", '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "A high-ATK blade that slightly lowers speed.", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "(ATK + 40, SPD - 5)", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '-', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '-', ']', '\n');
	
	printBlock(0, COLUMN_WIDTH_1, '|', "[3] Fist", '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "Using only your fists greatly improves speed.", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "(SPD + 10)", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '=', ']', '\n');
	
	printf("\n");
	
	printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '=', ']', '\n');
	
	printBlock(0, COLUMN_WIDTH_1, '|', "Choose. (0/1/2/3)", '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "Current stats: 100 HP / 10 ATK / 10 DEF / 10 SPD", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '=', ']', '\n');
	
	printf(">> ");
	
	int nInput = 0;
	
	/* Get input */
	scanf(" %d", &nInput);
	getchar();
	
	/* Validate input, can only be 0, 1, 2, or 3 
         * getchar() removes trailing newline from input stream
         */
	while (nInput < 0 || nInput > 3) {
		printf(">> Invalid input. Try again: ");
		scanf(" %d", &nInput);
		getchar();
	}
	
	return nInput;
}

/* This function prints a series of prompts that allow the user to select an armor.
 * @return 0, 1, 2, or 3, depending on the armor chosen.
 */
int
promptArmorSelect ()
{
	system("cls");
	
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	
	printBlock(1, WINDOW_WIDTH, '|', "Select an armor.", '|', '\n');
	
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	
	printf("\n");
	
	printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '=', ']', '\n');
	
	printBlock(1, COLUMN_WIDTH_1, '|', "Armor", '|', ' ');
	printBlock(1, COLUMN_WIDTH_2, '|', "Details", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '-', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '-', ']', '\n');
	
	printBlock(0, COLUMN_WIDTH_1, '|', "[0] Mythril", '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "Lightweight armor that increases DEF and SPD.", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "(DEF + 3, SPD + 3)", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '-', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '-', ']', '\n');
	
	printBlock(0, COLUMN_WIDTH_1, '|', "[1] Chainmail", '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "Standard chainmail armor that boosts DEF and HP", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "(DEF + 8, HP + 5)", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '-', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '-', ']', '\n');
	
	printBlock(0, COLUMN_WIDTH_1, '|', "[2] Adamantite armor", '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "Heavy armor than boosts DEF and HP; lowers SPD.", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "(DEF + 18, HP + 10, SPD - 4)", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '-', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '-', ']', '\n');
	
	printBlock(0, COLUMN_WIDTH_1, '|', "[3] No armor", '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "Wearing no armor greatly improves speed.", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "(SPD + 10)", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '=', ']', '\n');
	
	printf("\n");
	
	printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '=', ']', '\n');
	
	printBlock(0, COLUMN_WIDTH_1, '|', "Choose. (0/1/2/3)", '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "Current stats: 100/10/10/10", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '=', ']', '\n');
	
	printf(">> ");
	
	int nInput = 0;
	
	/* Get input and flush input stream */
	scanf(" %d", &nInput);
	getchar();
	
	/* Validate input, can only be 0, 1, 2, or 3 
         * getchar() removes trailing newline from input stream
         */
	while (nInput < 0 || nInput > 3) {
		printf(">> Invalid input. Try again: ");
		scanf(" %d", &nInput);
		getchar();
	}
	
	return nInput;
}

/* This function prompts the user to select weapons and armor
 * After selecting, it shows a confirmation of the player's stats and equipment
 * @param *nPlayerHP is a pointer to the address storing the player's HP stat
 * @param *nPlayerATK is a pointer to the address storing the player's ATK stat
 * @param *nPlayerDEF is a pointer to the address storing the player's DEF stat
 * @param *nPlayerSPD is a pointer to the address storing the player's SPD stat
 * @param *nPlayerCrit is a pointer to the address storing the player's critical hit chance
 * @return 0 if the player cancelled, 1 if the player confirmed
 */
int
promptPlayerEquipConfirm (int  *nPlayerHP,
                          int  *nPlayerATK,
                          int  *nPlayerDEF,
                          int  *nPlayerSPD,
                          int  *nPlayerCrit)
{
        /* Select a weapon, 'equip' it, then store chosen weapon name as string literal */
        char * cWeaponName = equipWeapon(nPlayerATK, nPlayerSPD, promptWeaponSelect());
        
        system("cls");

	/* Print weapon selection confirmation message */
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "You selected the following weapon:", '|', '\n');
	printBlock(1, WINDOW_WIDTH, '|', cWeaponName, '|', '\n');
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	playerConfirm();
        
         /* Select an armor, 'equip' it, then store chosen armor name as string literal */
        char * cArmorName = equipArmor(nPlayerHP, nPlayerDEF, nPlayerSPD, promptArmorSelect());
        
        system("cls");
	
	/* Print armor confirmation message */
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "You selected the following armor:", '|', '\n');
	printBlock(1, WINDOW_WIDTH, '|', cArmorName, '|', '\n');
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	playerConfirm();
	
	system("cls");
	
	/* Print equipment confirmation screen */
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "You will battle with the following stats:", '|', '\n');
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	printf("\n");
        showCurrentStatsEquip(*nPlayerHP,
                              *nPlayerATK,
                              *nPlayerDEF,
                              *nPlayerSPD,
                              *nPlayerCrit,
                              cWeaponName,
                              cArmorName);
        printf("\n");
	
	printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '=', ']', '\n');
	
	printBlock(0, COLUMN_WIDTH_1, '|', "Proceed? (Y/y/N/n)", '|', ' ');
	printBlock(0, COLUMN_WIDTH_2, '|', "TIP: Canceling will let you change equipment.", '|', '\n');
	
	printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
	printBorder(COLUMN_WIDTH_2, '[', '=', ']', '\n');
	printf(">> ");
	
	char cInput;
	
	/* Get player confirmation input (Y, y, N, or n) */
	scanf(" %c", &cInput);
	getchar();
	
	/* Validate input */
	while (cInput != 'Y' && cInput != 'y' && cInput != 'N' && cInput != 'n') {
		printf(">> Invalid input. Try again: ");
		scanf(" %c", &cInput);
		getchar();
	}
	
	if (cInput == 'Y' || cInput == 'y') {
		return 1;
	}
	
	return 0;
}

/* This function shows to the user the enemy's selected equipment
 * @param *nEnemyHP is a pointer to the address storing the enemy's HP stat
 * @param *nEnemyATK is a pointer to the address storing the enemy's ATK stat
 * @param *nEnemyDEF is a pointer to the address storing the enemy's DEF stat
 * @param *nEnemySPD is a pointer to the address storing the enemy's SPD stat
 * @param *nEnemyCrit is a pointer to the address storing the enemy's critical chance stat
 */
void
promptEnemyEquipConfirm (int  *nEnemyHP,
                         int  *nEnemyATK,
                         int  *nEnemyDEF,
                         int  *nEnemySPD,
                         int  *nEnemyCrit)
{
        int nWeaponInput = rand() % 4;
        int nArmorInput = rand() % 4;
        
        char * cWeaponName = equipWeapon(nEnemyATK, nEnemySPD, nWeaponInput);
        char * cArmorName = equipArmor(nEnemyHP, nEnemyDEF, nEnemySPD, nArmorInput);
        
        system("cls");
        
        printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "The enemy is selecting their equipment!", '|', '\n');
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
        playerConfirm();
        
        system("cls");
        
        printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "The enemy has chosen the following equipment:", '|', '\n');
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	printf("\n");
        showCurrentStatsEquip(*nEnemyHP,
                              *nEnemyATK,
                              *nEnemyDEF,
                              *nEnemySPD,
                              *nEnemyCrit,
                              cWeaponName,
                              cArmorName);
        playerConfirm();
}
