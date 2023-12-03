#include <stdio.h>
#include <string.h> // Needed functions: strlen()
#include <stdlib.h>
#include <time.h>

#define WINDOW_WIDTH 80 // ISO/ANSI screen width is 80 characters.
#define COLUMN_WIDTH_1 WINDOW_WIDTH / 3
#define COLUMN_WIDTH_2 WINDOW_WIDTH / 3 * 2 + 1

/* This function prints a "block" of width nWidth characters, split into three parts:
 * - An opening character
 * - A "border" character repeated nWidth - 2 times
 * - A closing character
 * It is then followed by the separator character cSeparator
 * Precondition: nWidth is at least 3
 * @param nWidth is the width of the whole "block" measured in characters
 * @param cPrepend is the character to the left of the border
 * @param cBorderChar is the character repeated to form the border
 * @param cAppend is the character to the right of the border
 * @param cSeparator is the character printed immediately following the "block"
 */
void
printBorder(int         nWidth,
            char        cPrepend,
            char        cBorderChar,
            char        cAppend,
            char        cSeparator)
{
	/* Print the opening character */
	printf("%c", cPrepend);
	
	/* Print the border character nWidth - 2 times */
	int i;
	for (i = 0; i < nWidth - 2; i++)
		printf("%c", cBorderChar);
	
	/* Print the closing character and the separator character */
	printf("%c%c", cAppend, cSeparator);
}

/* This function prints a "block" nWidth characters wide split into the following parts:
 * - An opening character, followed by a whitespace
 * - Text that takes up at least nWidth - 4 characters of space
 * - A closing character, preceded by a whitespace
 * It is then followed by the separator character cSeparator
 * Precondition: nWidth is at least 5, and nJustification is 0, 1, or 2.
 * @param nJustification is how the text cText will be justified; 0 is left, 1 is center, and 2 is right.
 * @param nWidth is the width of the whole "block" measured in characters
 * @param cPrepend is the character to the left of the border
 * @param cText is the string of text to be printed
 * @param cAppend is the character to the right of the border
 * @param cSeparator is the character printed immediately following the "block"
 */
void
printBlock (int         nJustification,
            int         nWidth,
            char        cPrepend,
            char       *cText,
            char        cAppend,
            char        cSeparator)
{
	/* Initialize the number to be used in format specifier as half of the text display width plus half of the string length
	 * Value is calculated first as floating point before being stored in an integer to preserve precision
	 */
	int nRightJustify = (nWidth - 4) / 2.0 + strlen(cText) / 2.0;
	
	/* Format text to be left-, center-, or right-justified */
	switch (nJustification) {
		/* Left justify */
		default:
			printf("%c %*s %c%c", cPrepend, -nWidth + 4, cText, cAppend, cSeparator);
			break;
		/* Center justify */
		case 1:
			printf("%c %*s %*c%c", cPrepend, nRightJustify, cText, nWidth - nRightJustify - 3, cAppend, cSeparator);
			break;
		/* Right justify */
		case 2:
			printf("%c %*s %c%c", cPrepend, nWidth - 4, cText, cAppend, cSeparator);
			break;
	}
}

/* This function prints a prompt for the user to press the Enter key. */
void
playerConfirm ()
{
	printf(">> Press Enter to proceed.");
	getchar();
}

/* This function prints the title screen. 
 * TODO: Polish
 */
void
showTitleScreen ()
{
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "   ________    ___    ____  _______  __________  ____ ", '|', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "  / ____/ /   /   |  / __ \\/  _/   |/_  __/ __ \\/ __ \\", '|', '\n');
	printBlock(1, WINDOW_WIDTH, '|', " / / __/ /   / /| | / / / // // /| | / / / / / / /_/ /", '|', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "/ /_/ / /___/ ___ |/ /_/ // // ___ |/ / / /_/ / _, _/ ", '|', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "\\____/_____/_/  |_/_____/___/_/  |_/_/  \\____/_/ |_|  ", '|', '\n');
	printBorder(WINDOW_WIDTH, '|', ' ', '|', '\n');
	printBlock(1, WINDOW_WIDTH, '|', "<< Go with the light at your back, hero. >>", '|', '\n');
	printBorder(WINDOW_WIDTH, '|', ' ', '|', '\n');
	printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
	printf("\n");
	
	playerConfirm();
}

/* This function prints a series of prompts that allow the user to select a weapon.
 * It returns 0, 1, 2, or 3 depending on the weapon chosen.
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
 * It returns 0, 1, 2, or 3 depending on the armor chosen.
 */
int promptArmorSelect ()
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

int
promptEquipConfirm (int        *nPlayerHP,
                    int        *nPlayerATK,
                    int        *nPlayerDEF,
                    int        *nPlayerSPD)
{
        char * cWeaponName = equipWeapon(&nPlayerATK, &nPlayerSPD, promptWeaponSelect());
        char * cArmorName = equipArmor(&nPlayerHP, &nPlayerDEF, &nPlayerSPD, promptArmorSelect());
}

/*
int amain()
{
	
}*/
