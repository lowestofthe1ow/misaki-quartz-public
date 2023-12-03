/******************************************************************
 * This is to certify that this project is my own work, based on my personal efforts in studying and
 * applying the concepts learned. I have constructed the functions and their respective algorithms
 * and corresponding code by myself. The program was run, tested, and debugged by my own efforts. I
 * further certify that I have not copied in part or whole or otherwise plagiarized the work of
 * other students and/or persons.
 * Lorenz Bernard Baduria Marqueses, 12307637
 ******************************************************************/

/* Description: A turn-based, singleplayer battling game inspired by RPG battle systems
 * Programmed by: Lorenz Bernard B. Marqueses, S13
 * Last modified: 24 November 2023
 * Version: 1.0.1
 * Acknowledgements:
 *      International Organization for Standardization. (2007). ISO/IEC 9899 committee draft.
 *              In Open Standards (WG14/N1256). Retrieved November 22, 2023, from
 *              https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf
 *      King, K. N. (2008). C programming: A modern approach.
 *              In W.W. Norton & Company eBooks (2nd ed.).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WINDOW_WIDTH 80
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
printBorder (int  nWidth,
             char cPrepend,
             char cBorderChar,
             char cAppend,
             char cSeparator)
{
        /* Print the opening character */
        printf ("%c", cPrepend);

        /* Print the border character nWidth - 2 times */
        int i;
        for (i = 0; i < nWidth - 2; i++)
                printf ("%c", cBorderChar);

        /* Print the closing character and the separator character */
        printf ("%c%c", cAppend, cSeparator);
}

/* This function prints a "block" nWidth characters wide split into the following parts:
 * - An opening character, followed by a whitespace
 * - Text that takes up at least nWidth - 4 characters of space
 * - A closing character, preceded by a whitespace
 * It is then followed by the separator character cSeparator
 * Precondition: nWidth is at least 5, and nJustification is 0, 1, or 2.
 * @param nJustification is how the text cText will be justified; 0 is left, 1 is center
 * @param nWidth is the width of the whole "block" measured in characters
 * @param cPrepend is the character to the left of the border
 * @param cText is the string of text to be printed
 * @param cAppend is the character to the right of the border
 * @param cSeparator is the character printed immediately following the "block"
 */
void
printBlock (int   nJustification,
            int   nWidth,
            char  cPrepend,
            char *cText,
            char  cAppend,
            char  cSeparator)
{
        /* Initialize the number to be used in format specifier as half of the text display width
         * plus half of the string length
         * Value is calculated first as floating point before being stored in an integer to preserve
         * precision
         */
        int nRightJustify = (nWidth - 4) / 2.0 + strlen (cText) / 2.0;

        /* Format text to be left- or center-justified */
        /* Left justify */
        if (nJustification == 0) 
                printf ("%c %*s %c%c", cPrepend, -nWidth + 4, cText, cAppend, cSeparator);
        /* Center justify */
        else
                printf ("%c %*s %*c%c",
                        cPrepend,
                        nRightJustify,
                        cText,
                        nWidth - nRightJustify - 3,
                        cAppend,
                        cSeparator);
}

/* This function prints a prompt for the user to press the Enter key. */
void
playerConfirm ()
{
        printf (">> Press Enter to proceed.");
        getchar ();
}

/* This function prints the title screen.
 */
void
showTitleScreen ()
{
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printBlock (1,
                    WINDOW_WIDTH,
                    '|',
                    "   ________    ___    ____  _______  __________  ____ ",
                    '|',
                    '\n');
        printBlock (1,
                    WINDOW_WIDTH,
                    '|',
                    "  / ____/ /   /   |  / __ \\/  _/   |/_  __/ __ \\/ __ \\",
                    '|',
                    '\n');
        printBlock (1,
                    WINDOW_WIDTH,
                    '|',
                    " / / __/ /   / /| | / / / // // /| | / / / / / / /_/ /",
                    '|',
                    '\n');
        printBlock (1,
                    WINDOW_WIDTH,
                    '|',
                    "/ /_/ / /___/ ___ |/ /_/ // // ___ |/ / / /_/ / _, _/ ",
                    '|',
                    '\n');
        printBlock (1,
                    WINDOW_WIDTH,
                    '|',
                    "\\____/_____/_/  |_/_____/___/_/  |_/_/  \\____/_/ |_|  ",
                    '|',
                    '\n');
        printBorder (WINDOW_WIDTH, '|', ' ', '|', '\n');
        printBlock (1, WINDOW_WIDTH, '|', "<< Go with the light at your back, hero. >>", '|', '\n');
        printBorder (WINDOW_WIDTH, '|', ' ', '|', '\n');
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printf ("\n");

        playerConfirm ();
}

/* This function prints a prompt that allows the user to select a gameplay mode
 * @return 0 or 1, depending on the mode chosen.
 */
int
promptSelectMode ()
{
        system ("cls");
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printBlock (1, WINDOW_WIDTH, '|', "Select a mode", '|', '\n');
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');

        printf ("\n");

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '=', ']', '\n');

        printBlock (0, COLUMN_WIDTH_1, '|', "[0] Standard game", '|', ' ');
        printBlock (0,
                    COLUMN_WIDTH_2,
                    '|',
                    "Choose among sets of weapons and armor to equip",
                    '|',
                    '\n');

        printBlock (0, COLUMN_WIDTH_1, '|', "[1] Dev mode", '|', ' ');
        printBlock (0, COLUMN_WIDTH_2, '|', "Manually input player and enemy stats", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '=', ']', '\n');

        printf ("\n");

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', '\n');

        printBlock (0, COLUMN_WIDTH_1, '|', "Choose. (0/1)", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', '\n');

        printf (">> ");

        int nInput = 0;

        /* Get input */
        scanf (" %d", &nInput);
        getchar ();

        /* Validate input, can only be 0 or 1
         * getchar() removes trailing newline from input stream
         */
        while (nInput < 0 || nInput > 1) {
                printf (">> Invalid input. Try again: ");
                scanf (" %d", &nInput);
                getchar ();
        }

        return nInput;
}

/* This function displays a summary of the target's stats and equipment
 * Precondition: nHP, nATK, nDEF, nSPD are non-negative and less than or equal to 999
 *               nCrit is non-negative and less than or equal to 100
 * @param nHP is the target's HP stat
 * @param nATK is the target's ATK stat
 * @param nDEF is the target's DEF stat
 * @param nSPD is the target's SPD stat
 * @param nCrit is the target's critical hit chance
 * @param *cSelectedWeaponName is the name of the target's weapon
 * @param *cSelectedArmorName is the name of the target's armor
 */
void
showCurrentStatsEquip (int   nHP,
                       int   nATK,
                       int   nDEF,
                       int   nSPD,
                       int   nCrit,
                       char *cSelectedWeaponName,
                       char *cSelectedArmorName)
{
        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_1, '[', '=', ']', '\n');

        printBlock (1, COLUMN_WIDTH_1, '|', "Stats", '|', ' ');
        printBlock (1, COLUMN_WIDTH_1, '|', "Weapon", '|', ' ');
        printBlock (1, COLUMN_WIDTH_1, '|', "Armor", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder (COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder (COLUMN_WIDTH_1, '[', '-', ']', '\n');

        printf ("| ATK   \\ DEF   \\ SPD%*c ", COLUMN_WIDTH_1 - 21, '|');
        printBlock (0, COLUMN_WIDTH_1, '|', cSelectedWeaponName, '|', ' ');
        printBlock (0, COLUMN_WIDTH_1, '|', cSelectedArmorName, '|', '\n');

        printf ("| %-4d  / %-4d  / %-4d%*c ", nATK, nDEF, nSPD, COLUMN_WIDTH_1 - 22, '|');
        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', '\n');

        printf ("| Base HP: %3d%*c ", nHP, COLUMN_WIDTH_1 - 14, '|');
        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', '\n');

        printf ("| Critical chance: %3d%%%*c ", nCrit, COLUMN_WIDTH_1 - 23, '|');
        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_1, '[', '=', ']', '\n');
}

/* This function 'equips' a weapon on the target and returns the weapon name
 * 'Equipping' refers to adding the weapon's stats to the target's
 * Precondition: nInput is 0, 1, 2, or 3
 *               *nTargetATK and *nTargetSPD are non-negative and less than or equal to 999
 * @param *nTargetATK is a pointer to the address storing the target's ATK stat
 * @param *nTargetSPD is a pointer to the address storing the target's SPD stat
 * @param nInput is the integer indicating the chosen weapon
 * @return A string literal containing the weapon's name
 */
char *
equipWeapon (int *nTargetATK,
             int *nTargetSPD,
             int  nInput)
{
        /* 'Equip' weapon based on selection input */
        switch (nInput) {
        default:
        case 0:
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
 *               *nTargetHP, *nTargetDEF, and *nTargetSPD are non-negative and less than or equal to
 *               999
 * @param *nTargetATK is a pointer to the address storing the target's ATK stat
 * @param *nTargetSPD is a pointer to the address storing the target's SPD stat
 * @param nInput is the integer indicating the chosen armor
 * @return A string literal containing the armor's name
 */
char *
equipArmor (int *nTargetHP,
            int *nTargetDEF,
            int *nTargetSPD,
            int  nInput)
{
        /* 'Equip' armor based on selection input */
        switch (nInput) {
        default:
        case 0:
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
        system ("cls");

        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');

        printBlock (1, WINDOW_WIDTH, '|', "Select a weapon.", '|', '\n');

        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');

        printf ("\n");

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '=', ']', '\n');

        printBlock (1, COLUMN_WIDTH_1, '|', "Weapon", '|', ' ');
        printBlock (1, COLUMN_WIDTH_2, '|', "Details", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '-', ']', '\n');

        printBlock (0, COLUMN_WIDTH_1, '|', "[0] Dagger", '|', ' ');
        printBlock (0,
                    COLUMN_WIDTH_2,
                    '|',
                    "A low-ATK weapon that slightly improves speed.",
                    '|',
                    '\n');

        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBlock (0, COLUMN_WIDTH_2, '|', "(ATK + 15, SPD + 3)", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '-', ']', '\n');

        printBlock (0, COLUMN_WIDTH_1, '|', "[1] Katana", '|', ' ');
        printBlock (0,
                    COLUMN_WIDTH_2,
                    '|',
                    "A slim blade with moderately high ATK power.",
                    '|',
                    '\n');

        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBlock (0, COLUMN_WIDTH_2, '|', "(ATK + 20)", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '-', ']', '\n');

        printBlock (0, COLUMN_WIDTH_1, '|', "[2] Broadsword", '|', ' ');
        printBlock (0,
                    COLUMN_WIDTH_2,
                    '|',
                    "A high-ATK blade that slightly lowers speed.",
                    '|',
                    '\n');

        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBlock (0, COLUMN_WIDTH_2, '|', "(ATK + 40, SPD - 5)", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '-', ']', '\n');

        printBlock (0, COLUMN_WIDTH_1, '|', "[3] Fist", '|', ' ');
        printBlock (0,
                    COLUMN_WIDTH_2,
                    '|',
                    "Using only your fists greatly improves speed.",
                    '|',
                    '\n');

        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBlock (0, COLUMN_WIDTH_2, '|', "(SPD + 10)", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '=', ']', '\n');

        printf ("\n");

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '=', ']', '\n');

        printBlock (0, COLUMN_WIDTH_1, '|', "Choose. (0/1/2/3)", '|', ' ');
        printBlock (0,
                    COLUMN_WIDTH_2,
                    '|',
                    "Current stats: 100 HP / 10 ATK / 10 DEF / 10 SPD",
                    '|',
                    '\n');

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '=', ']', '\n');

        printf (">> ");

        int nInput = 0;

        /* Get input */
        scanf (" %d", &nInput);
        getchar ();

        /* Validate input, can only be 0, 1, 2, or 3
         * getchar() removes trailing newline from input stream
         */
        while (nInput < 0 || nInput > 3) {
                printf (">> Invalid input. Try again: ");
                scanf (" %d", &nInput);
                getchar ();
        }

        return nInput;
}

/* This function prints a series of prompts that allow the user to select an armor.
 * @return 0, 1, 2, or 3, depending on the armor chosen.
 */
int
promptArmorSelect ()
{
        system ("cls");

        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');

        printBlock (1, WINDOW_WIDTH, '|', "Select an armor.", '|', '\n');

        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');

        printf ("\n");

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '=', ']', '\n');

        printBlock (1, COLUMN_WIDTH_1, '|', "Armor", '|', ' ');
        printBlock (1, COLUMN_WIDTH_2, '|', "Details", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '-', ']', '\n');

        printBlock (0, COLUMN_WIDTH_1, '|', "[0] Mythril", '|', ' ');
        printBlock (0,
                    COLUMN_WIDTH_2,
                    '|',
                    "Lightweight armor that increases DEF and SPD.",
                    '|',
                    '\n');

        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBlock (0, COLUMN_WIDTH_2, '|', "(DEF + 3, SPD + 3)", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '-', ']', '\n');

        printBlock (0, COLUMN_WIDTH_1, '|', "[1] Chainmail", '|', ' ');
        printBlock (0,
                    COLUMN_WIDTH_2,
                    '|',
                    "Standard chainmail armor that boosts DEF and HP",
                    '|',
                    '\n');

        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBlock (0, COLUMN_WIDTH_2, '|', "(DEF + 8, HP + 5)", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '-', ']', '\n');

        printBlock (0, COLUMN_WIDTH_1, '|', "[2] Adamantite armor", '|', ' ');
        printBlock (0,
                    COLUMN_WIDTH_2,
                    '|',
                    "Heavy armor than boosts DEF and HP; lowers SPD.",
                    '|',
                    '\n');

        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBlock (0, COLUMN_WIDTH_2, '|', "(DEF + 18, HP + 10, SPD - 4)", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '-', ']', '\n');

        printBlock (0, COLUMN_WIDTH_1, '|', "[3] No armor", '|', ' ');
        printBlock (0, COLUMN_WIDTH_2, '|', "Wearing no armor greatly improves speed.", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
        printBlock (0, COLUMN_WIDTH_2, '|', "(SPD + 10)", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '=', ']', '\n');

        printf ("\n");

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '=', ']', '\n');

        printBlock (0, COLUMN_WIDTH_1, '|', "Choose. (0/1/2/3)", '|', ' ');
        printBlock (0, COLUMN_WIDTH_2, '|', "Current stats: 100/10/10/10", '|', '\n');

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '=', ']', '\n');

        printf (">> ");

        int nInput = 0;

        /* Get input and flush input stream */
        scanf (" %d", &nInput);
        getchar ();

        /* Validate input, can only be 0, 1, 2, or 3
         * getchar() removes trailing newline from input stream
         */
        while (nInput < 0 || nInput > 3) {
                printf (">> Invalid input. Try again: ");
                scanf (" %d", &nInput);
                getchar ();
        }

        return nInput;
}

/* This function prompts the user to select weapons and armor
 * After selecting, it shows a confirmation of the player's stats and equipment
 * Precondition: *nPlayerHP, *nPlayerATK, *nPlayerDEF, and *nPlayerSPD are non-negative and less
 *               than or equal to 999
 *               *nPlayerCrit is non-negative and less than or equal to 100
 * @param *nPlayerHP is a pointer to the address storing the player's HP stat
 * @param *nPlayerATK is a pointer to the address storing the player's ATK stat
 * @param *nPlayerDEF is a pointer to the address storing the player's DEF stat
 * @param *nPlayerSPD is a pointer to the address storing the player's SPD stat
 * @param *nPlayerCrit is a pointer to the address storing the player's critical hit chance
 * @return 0 if the player cancelled, 1 if the player confirmed
 */
int
promptPlayerEquipConfirm (int *nPlayerHP,
                          int *nPlayerATK,
                          int *nPlayerDEF,
                          int *nPlayerSPD,
                          int *nPlayerCrit)
{
        /* Select a weapon, 'equip' it, then store chosen weapon name as string literal */
        char *cWeaponName = equipWeapon (nPlayerATK, nPlayerSPD, promptWeaponSelect ());

        system ("cls");

        /* Print weapon selection confirmation message */
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printBlock (1, WINDOW_WIDTH, '|', "You selected the following weapon:", '|', '\n');
        printBlock (1, WINDOW_WIDTH, '|', cWeaponName, '|', '\n');
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        playerConfirm ();

        /* Select an armor, 'equip' it, then store chosen armor name as string literal */
        char *cArmorName = equipArmor (nPlayerHP, nPlayerDEF, nPlayerSPD, promptArmorSelect ());

        system ("cls");

        /* Print armor confirmation message */
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printBlock (1, WINDOW_WIDTH, '|', "You selected the following armor:", '|', '\n');
        printBlock (1, WINDOW_WIDTH, '|', cArmorName, '|', '\n');
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        playerConfirm ();

        system ("cls");

        /* Print equipment confirmation screen */
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printBlock (1, WINDOW_WIDTH, '|', "You will battle with the following stats:", '|', '\n');
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printf ("\n");
        showCurrentStatsEquip (*nPlayerHP,
                               *nPlayerATK,
                               *nPlayerDEF,
                               *nPlayerSPD,
                               *nPlayerCrit,
                               cWeaponName,
                               cArmorName);
        printf ("\n");

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '=', ']', '\n');

        printBlock (0, COLUMN_WIDTH_1, '|', "Proceed? (Y/y/N/n)", '|', ' ');
        printBlock (0,
                    COLUMN_WIDTH_2,
                    '|',
                    "TIP: Canceling will let you change equipment.",
                    '|',
                    '\n');

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '=', ']', '\n');
        printf (">> ");

        char cInput;

        /* Get player confirmation input (Y, y, N, or n) */
        scanf (" %c", &cInput);
        getchar ();

        /* Validate input */
        while (cInput != 'Y' && cInput != 'y' && cInput != 'N' && cInput != 'n') {
                printf (">> Invalid input. Try again: ");
                scanf (" %c", &cInput);
                getchar ();
        }

        if (cInput == 'Y' || cInput == 'y') {
                return 1;
        }

        return 0;
}

/* This function shows to the user the enemy's selected equipment
 * Precondition: *nEnemyHP, *nEnemyATK, *nEnemyDEF, and *nEnemySPD are non-negative and less than or
 *               equal to 999
 *               *nEnemyCrit is non-negative and less than or equal to 100
 * @param *nEnemyHP is a pointer to the address storing the enemy's HP stat
 * @param *nEnemyATK is a pointer to the address storing the enemy's ATK stat
 * @param *nEnemyDEF is a pointer to the address storing the enemy's DEF stat
 * @param *nEnemySPD is a pointer to the address storing the enemy's SPD stat
 * @param *nEnemyCrit is a pointer to the address storing the enemy's critical chance stat
 */
void
promptEnemyEquipConfirm (int *nEnemyHP,
                         int *nEnemyATK,
                         int *nEnemyDEF,
                         int *nEnemySPD,
                         int *nEnemyCrit)
{
        int nWeaponInput = rand () % 4;
        int nArmorInput = rand () % 4;

        char *cWeaponName = equipWeapon (nEnemyATK, nEnemySPD, nWeaponInput);
        char *cArmorName = equipArmor (nEnemyHP, nEnemyDEF, nEnemySPD, nArmorInput);

        system ("cls");

        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printBlock (1, WINDOW_WIDTH, '|', "The enemy is selecting their equipment!", '|', '\n');
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        playerConfirm ();

        system ("cls");

        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printBlock (1,
                    WINDOW_WIDTH,
                    '|',
                    "The enemy has chosen the following equipment:",
                    '|',
                    '\n');
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printf ("\n");
        showCurrentStatsEquip (*nEnemyHP,
                               *nEnemyATK,
                               *nEnemyDEF,
                               *nEnemySPD,
                               *nEnemyCrit,
                               cWeaponName,
                               cArmorName);
        playerConfirm ();
}

/* This function prints a health bar of width nWidth
 * Precondition: nCurrentHP and nMaxHP are non-negative and less than or equal to 999
 *               nCurrentHP is less than or equal to nMaxHP
 *               nWidth is at least 5
 * Remaining health is represented with the '#' character
 * Depleted health is represented with the ':' character
 * @param nWidth is the width of the health bar
 * @param nCurrentHP is the remaining HP value
 * @param nMaxHP is the base (max) HP value
 */
void
printGauge (int nWidth,
            int nCurrentHP,
            int nMaxHP)
{
        /* Initialize number of '#' characters to be printed */
        int nCharsRemaining = 1.0 * nCurrentHP / nMaxHP * (nWidth - 4);

        /* Initialize number of ':' characters to be printed */
        int nCharsDepleted = nWidth - 4 - nCharsRemaining;

        /* Declare control/index variable for loops */
        int i;

        /* Print opening bracket */
        printf ("[ ");

        /* Print '#' characters (remaining HP) */
        for (i = 0; i < nCharsRemaining; i++)
                printf ("#");

        /* Print ':' characters (depleted HP) */
        for (i = 0; i < nCharsDepleted; i++)
                printf (":");

        /* Print closing bracket */
        printf (" ]");
}

/* This function prints the current state of the battle
 * Precondition: nPlayerCrit and nEnemyCrit are non-negative and less than or equal to 999
 *               nShowInstructions is 0 or 1
 *               Remaining parameters are non-negative and less than or equal to 999
 * @param nPlayerHP is the player's HP stat
 * @param nPlayerATK is the player's ATK stat
 * @param nPlayerDEF is the player's DEF stat
 * @param nPlayerSPD is the player's SPD stat
 * @param nPlayerCrit is the player's critical chance stat
 * @param nEnemyHP is the enemy's HP stat
 * @param nEnemyATK is the enemy's ATK stat
 * @param nEnemyDEF is the enemy's DEF stat
 * @param nEnemySPD is the enemy's SPD stat
 * @param nEnemyCrit is the enemy's critical chance stat
 * @param nShowInstructions is a flag that determines whether to show list of actions and
 *        instructions
 */
void
updateBattleScreen (/* Player stats */
                    int nPlayerCurrentHP,
                    int nPlayerBaseHP,
                    int nPlayerATK,
                    int nPlayerDEF,
                    int nPlayerSPD,
                    int nPlayerCrit,
                    /* Enemy stats */
                    int nEnemyCurrentHP,
                    int nEnemyBaseHP,
                    int nEnemyATK,
                    int nEnemyDEF,
                    int nEnemySPD,
                    int nEnemyCrit,
                    /* 'Show instructions' flag */
                    int nShowInstructions)
{
        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printBorder (COLUMN_WIDTH_1, '[', '=', ']', '\n');

        printBlock (1, COLUMN_WIDTH_1, '|', "You", '|', ' ');
        printBlock (1, COLUMN_WIDTH_1, ' ', "VS", ' ', ' ');
        printBlock (1, COLUMN_WIDTH_1, '|', "Enemy", '|', '\n');

        printGauge (COLUMN_WIDTH_1, nPlayerCurrentHP, nPlayerBaseHP);
        printf (" ");
        printBorder (COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printGauge (COLUMN_WIDTH_1, nEnemyCurrentHP, nEnemyBaseHP);
        printf ("\n");

        printf ("| HP: %3d / %-3d%*c ", nPlayerCurrentHP, nPlayerBaseHP, COLUMN_WIDTH_1 - 15, '|');
        printBorder (COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printf ("| HP: %3d / %-3d%*c\n", nEnemyCurrentHP, nEnemyBaseHP, COLUMN_WIDTH_1 - 15, '|');

        printBorder (COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder (COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printBorder (COLUMN_WIDTH_1, '[', '-', ']', '\n');

        printf ("| ATK   \\ DEF   \\ SPD%*c ", COLUMN_WIDTH_1 - 21, '|');
        printBorder (COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printf ("| ATK   / DEF   / SPD%*c\n", COLUMN_WIDTH_1 - 21, '|');

        printf ("| %-4d  / %-4d  / %-4d%*c ",
                nPlayerATK,
                nPlayerDEF,
                nPlayerSPD,
                COLUMN_WIDTH_1 - 22,
                '|');
        printBorder (COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printf ("| %-4d  \\ %-4d  \\ %-4d%*c\n",
                nEnemyATK,
                nEnemyDEF,
                nEnemySPD,
                COLUMN_WIDTH_1 - 22,
                '|');

        printf ("| Critical chance: %3d%%%*c ", nPlayerCrit, COLUMN_WIDTH_1 - 23, '|');
        printBorder (COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printf ("| Critical chance: %3d%%%*c\n", nEnemyCrit, COLUMN_WIDTH_1 - 23, '|');

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printBorder (COLUMN_WIDTH_1, '[', '=', ']', '\n');

        printf ("\n");

        printBlock (1, COLUMN_WIDTH_1, ' ', "O", ' ', ' ');
        printBorder (COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printBlock (1, COLUMN_WIDTH_1, ' ', "O", ' ', '\n');

        printBlock (1, COLUMN_WIDTH_1, ' ', "/|\\", ' ', ' ');
        printBorder (COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printBlock (1, COLUMN_WIDTH_1, ' ', "/|\\", ' ', '\n');

        printBlock (1, COLUMN_WIDTH_1, ' ', "/ \\", ' ', ' ');
        printBorder (COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printBlock (1, COLUMN_WIDTH_1, ' ', "/ \\", ' ', '\n');

        printf ("\n");

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '=', ']', '\n');

        /* Hide or show options and instructions for action selection */
        if (nShowInstructions) {
                printBlock (0, COLUMN_WIDTH_1, '|', "[0] Attack", '|', ' ');
                printBlock (0, COLUMN_WIDTH_2, '|', "Deal damage to the enemy.", '|', '\n');
                printBlock (0, COLUMN_WIDTH_1, '|', "[1] Block", '|', ' ');
                printBlock (0,
                            COLUMN_WIDTH_2,
                            '|',
                            "Brace yourself. (Doubles DEF this turn)",
                            '|',
                            '\n');
                printBlock (0, COLUMN_WIDTH_1, '|', "[2] Charge", '|', ' ');
                printBlock (0,
                            COLUMN_WIDTH_2,
                            '|',
                            "Charge power. (Doubles ATK and SPD next turn)",
                            '|',
                            '\n');
        } else {
                printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
                printBorder (COLUMN_WIDTH_2, '|', ' ', '|', '\n');
                printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
                printBorder (COLUMN_WIDTH_2, '|', ' ', '|', '\n');
                printBorder (COLUMN_WIDTH_1, '|', ' ', '|', ' ');
                printBorder (COLUMN_WIDTH_2, '|', ' ', '|', '\n');
        }

        printBorder (COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder (COLUMN_WIDTH_2, '[', '=', ']', '\n');
}

/* This function calculates damage dealt by the actor to the target and updates the target's HP
 * Precondition: nActorATK, *nTargetCurrentHP, and nTargetDEF are non-negative and less than or
 *               equal to 999
 *               nActorCrit is non-negative and less than or equal to 100
 *               nActorIsPlayer is 0 or 1
 * @param nActorATK is the actor's ATK stat
 * @param nActorCrit is the actor's critical chance stat
 * @param *nTargetCurrentHP is the pointer to the address storing the target's current HP
 * @param nTargetDEF is the target's DEF stat
 * @param nActorIsPlayer is a flag that determines whether the actor is the player or the enemy (for
 *        printing)
 */
void
processAttack (int  nActorATK,
               int  nActorCrit,
               int *nTargetCurrentHP,
               int  nTargetDEF,
               int  nActorIsPlayer)
{
        /* Roll for a critical hit */
        int nCritRoll = rand () % 100;

        /* Initialize damage dealt as 0 */
        int nDamage = 0;

        /* If a critical hit is rolled, ignore target DEF
         * nCritRoll will have a value from 0 to 99 (100 possible values)
         * If nActorCrit = 15, these possible values of nCritRoll that result in a critical hit:
         * 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14
         * Hence, there is a 15/100 = 15% chance of rolling a critical hit
         */
        if (nCritRoll < nActorCrit)
                nDamage = nActorATK;
        /* If a critical hit is not rolled, calculate damage as actor ATK - target DEF,
         * (Only calculate if actor ATK > target DEF, otherwise damage remains as its default value
         * of 0)
         */
        else if (nActorATK > nTargetDEF)
                nDamage = nActorATK - nTargetDEF;

        /* If damage is greater than enemy remaining HP, set damage to match it */
        if (nDamage > *nTargetCurrentHP)
                nDamage = *nTargetCurrentHP;

        /* Subtract damage from target HP */
        *nTargetCurrentHP -= nDamage;

        /* Print message depending on if actor is the player or the opponent */
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        if (nActorIsPlayer)
                /* Message differs if actor landed a critical hit */
                if (nCritRoll < nActorCrit)
                        printf ("| You landed a critical hit! DEF ignored. Dealt %3d damage.%*c\n",
                                nDamage,
                                WINDOW_WIDTH - 59,
                                '|');
                else
                        printf ("| You attacked! Dealt %3d damage.%*c\n",
                                nDamage,
                                WINDOW_WIDTH - 33,
                                '|');
        else if (nCritRoll < nActorCrit)
                printf ("| Enemy landed a critical hit! DEF ignored. Dealt %3d damage.%*c\n",
                        nDamage,
                        WINDOW_WIDTH - 61,
                        '|');
        else
                printf ("| Enemy attacked! Dealt %3d damage.%*c\n",
                        nDamage,
                        WINDOW_WIDTH - 35,
                        '|');
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
}

/* This function modifies the actor's DEF stat when the Block action is selected
 * Precondition: *nActorDEF is non-negative and less than or equal to 999
 *               nActorIsPlayer is 0 or 1
 * @param *nActorDEF is a pointer to the address storing the actor's DEF stat
 * @param nActorIsPlayer is a flag that determines whether the actor is the player or the enemy (for
 *        printing)
 */
void
processBlock (int *nActorDEF,
              int  nActorIsPlayer)
{
        /* Multiply actor DEF by 2 */
        *nActorDEF *= 2;

        /* Print message depending on if actor is the player or opponent */
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        if (nActorIsPlayer)
                printf ("| You blocked! DEF doubled this turn.%*c\n", WINDOW_WIDTH - 37, '|');
        else
                printf ("| Enemy blocked! DEF doubled this turn.%*c\n", WINDOW_WIDTH - 39, '|');
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
}

/* This function modifies the actor's ATK and SPD stat when the Charge action is selected
 * If the flag at the address provided by *nActorIsCharging is alread enabled, it is disabled and
 * ATK and SPD remain doubled
 * Precondition: *nActorATK and *nActorSPD are non-negative and less than or equal to 999
 *               nActorIsCharging is 0 or 1
 * @param *nActorATK is a pointer to the address storing the actor's DEF stat
 * @param *nActorSPD is a pointer to the address storing the actor's ATK stat
 * @param nActorIsPlayer is a flag that determines whether the actor is the player or the enemy (for
 *        printing)
 * @param *nActorIsCharging is a pointer to the address storing the flag that identifies whether the
 *        actor is currently charging
 */
void
processCharge (int *nActorATK,
               int *nActorSPD,
               int  nActorIsPlayer,
               int *nActorIsCharging)
{
        /* Handle action depending on if actor is the player or opponent */
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        /* If charging flag is 0 (false) */
        if (*nActorIsCharging == 0) {
                /* Double actor ATK and SPD */
                *nActorATK *= 2;
                *nActorSPD *= 2;

                /* Print message depending on if actor is the player or opponent */
                if (nActorIsPlayer)
                        printf ("| You charged! ATK and SPD doubled until the end of the next "
                                "turn.%*c\n",
                                WINDOW_WIDTH - 66,
                                '|');
                else
                        printf ("| Enemy charged! ATK and SPD doubled until the end of the next "
                                "turn.%*c\n",
                                WINDOW_WIDTH - 68,
                                '|');
                /* If charging flag is true */
        } else {
                /* Disable charging flag to "delay" ATK/SPD reset by 1 turn for the actor */
                *nActorIsCharging = 0;

                /* Print message depending on if actor is the player or opponent */
                if (nActorIsPlayer)
                        printf ("| You kept charging! ATK and SPD doubled until the end of the "
                                "next turn.%*c\n",
                                WINDOW_WIDTH - 72,
                                '|');
                else
                        printf ("| Enemy kept charging! ATK and SPD doubled until the end of the "
                                "next "
                                "turn.%*c\n",
                                WINDOW_WIDTH - 74,
                                '|');
        }
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
}

/* This function processes the action selected by either the player or the enemy and calls the
 * relevant function for handling it
 * @param nAction is the selected action
 * @param *nPlayerCurrentHP is a pointer to the address storing the player's current HP
 * @param *nPlayerBaseHP is a pointer to the address storing the player's base HP stat
 * @param *nPlayerATK is a pointer to the address storing the player's ATK stat
 * @param *nPlayerDEF is a pointer to the address storing the player's DEF stat
 * @param *nPlayerSPD is a pointer to the address storing the player's SPD stat
 * @param *nPlayerCrit is a pointer to the address storing the player's critical chance stat
 * @param *nEnemyCurrentHP is a pointer to the address storing the enemy's current HP
 * @param *nEnemyBaseHP is a pointer to the address storing the enemy's base HP stat
 * @param *nEnemyATK is a pointer to the address storing the enemy's ATK stat
 * @param *nEnemyDEF is a pointer to the address storing the enemy's DEF stat
 * @param *nEnemySPD is a pointer to the address storing the enemy's SPD stat
 * @param *nEnemyCrit is a pointer to the address storing the enemy's critical chance stat
 * @param *nActorIsCharging is a pointer to the address storing the flag that identifies whether the
 *        actor is currently charging
 * @param nActorIsPlayer is a flag that determines whether the actor is the player or the enemy (for
 *        printing)
 */
void
processAction (int  nAction,
               /* Actor stats */
               int *nActorCurrentHP,
               int *nActorBaseHP,
               int *nActorATK,
               int *nActorDEF,
               int *nActorSPD,
               int *nActorCrit,
               /* Target stats */
               int *nTargetCurrentHP,
               int *nTargetBaseHP,
               int *nTargetATK,
               int *nTargetDEF,
               int *nTargetSPD,
               int *nTargetCrit,
               /* Flags */
               int *nActorIsCharging,
               int  nActorIsPlayer)
{
        /* Determine which action to take */
        switch (nAction) {
        /* Attack action (nAction == 0) */
        case 0:
                processAttack (*nActorATK,
                               *nActorCrit,
                               nTargetCurrentHP,
                               *nTargetDEF,
                               nActorIsPlayer);
                break;
        /* Block action (nAction == 1) */
        case 1:
                processBlock (nActorDEF, nActorIsPlayer);
                break;
        /* Charge action (nAction == 2) */
        case 2:
                processCharge (nActorATK, nActorSPD, nActorIsPlayer, nActorIsCharging);
                break;
        }

        /* Update battle screen */
        if (nActorIsPlayer)
                updateBattleScreen (/* Actor stats */
                                    *nActorCurrentHP,
                                    *nActorBaseHP,
                                    *nActorATK,
                                    *nActorDEF,
                                    *nActorSPD,
                                    *nActorCrit,
                                    /* Target stats */
                                    *nTargetCurrentHP,
                                    *nTargetBaseHP,
                                    *nTargetATK,
                                    *nTargetDEF,
                                    *nTargetSPD,
                                    *nTargetCrit,
                                    /* 'Show instructions' flag */
                                    0);
        else
                updateBattleScreen (/* Target stats */
                                    *nTargetCurrentHP,
                                    *nTargetBaseHP,
                                    *nTargetATK,
                                    *nTargetDEF,
                                    *nTargetSPD,
                                    *nTargetCrit,
                                    /* Actor stats */
                                    *nActorCurrentHP,
                                    *nActorBaseHP,
                                    *nActorATK,
                                    *nActorDEF,
                                    *nActorSPD,
                                    *nActorCrit,
                                    /* 'Show instructions' flag */
                                    0);

        /* Wait for player confirmation, then clear screen */
        playerConfirm ();
        system ("cls");
}

/* This function handles the main battle gameplay loop
 * Precondition: *nPlayerCrit and *nEnemyCrit are non-negative and less than or equal to 100
 *               All other parameters are non-negative and less than or equal to 999
 * @param *nPlayerCurrentHP is a pointer to the address storing the player's current HP
 * @param *nPlayerBaseHP is a pointer to the address storing the player's base HP stat
 * @param *nPlayerATK is a pointer to the address storing the player's ATK stat
 * @param *nPlayerDEF is a pointer to the address storing the player's DEF stat
 * @param *nPlayerSPD is a pointer to the address storing the player's SPD stat
 * @param *nPlayerCrit is a pointer to the address storing the player's critical chance stat
 * @param *nEnemyCurrentHP is a pointer to the address storing the enemy's current HP
 * @param *nEnemyBaseHP is a pointer to the address storing the enemy's base HP stat
 * @param *nEnemyATK is a pointer to the address storing the enemy's ATK stat
 * @param *nEnemyDEF is a pointer to the address storing the enemy's DEF stat
 * @param *nEnemySPD is a pointer to the address storing the enemy's SPD stat
 * @param *nEnemyCrit is a pointer to the address storing the enemy's critical chance stat
 */
void
beginBattle (/* Player stats */
             int *nPlayerCurrentHP,
             int *nPlayerBaseHP,
             int *nPlayerATK,
             int *nPlayerDEF,
             int *nPlayerSPD,
             int *nPlayerCrit,
             /* Enemy stats */
             int *nEnemyCurrentHP,
             int *nEnemyBaseHP,
             int *nEnemyATK,
             int *nEnemyDEF,
             int *nEnemySPD,
             int *nEnemyCrit)
{
        system ("cls");

        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printBlock (1, WINDOW_WIDTH, '|', "The enemy gladiator challenges you!", '|', '\n');
        printBlock (1, WINDOW_WIDTH, '|', "Reduce their HP to 0 to win!", '|', '\n');
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        playerConfirm ();

        system ("cls");

        /* Declare variables for player and enemy actions */
        int nPlayerAction, nEnemyAction;

        /* Initialize flags for player and enemy charge actions as 0 (false) */
        int nPlayerIsCharging = 0, nEnemyIsCharging = 0;

        /* Each turn of the battle takes place within one iteration of this loop
         * The loop ends when either the player's or the enemy's (or both) HP reaches 0.
         * One turn involves the following step-by-step process:
         * 1. Take player and enemy inputs
         * 2. Process action order
         * 3. Process player and enemy actions
         * 4. Reset player and enemy ATK and SPD if relevant flag is active
         * 5. Activate flag to reset player and enemy ATK and SPD if Charge action was taken
         * 6. Reset player and enemy DEF if Block action was taken
         */
        while (*nPlayerCurrentHP > 0 && *nEnemyCurrentHP > 0) {
                /* Print instructions to select an action */
                printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
                printf ("| Enter an action (0/1/2).%*c\n", WINDOW_WIDTH - 26, '|');
                printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
                updateBattleScreen (/* Player stats */
                                    *nPlayerCurrentHP,
                                    *nPlayerBaseHP,
                                    *nPlayerATK,
                                    *nPlayerDEF,
                                    *nPlayerSPD,
                                    *nPlayerCrit,
                                    /* Enemy stats */
                                    *nEnemyCurrentHP,
                                    *nEnemyBaseHP,
                                    *nEnemyATK,
                                    *nEnemyDEF,
                                    *nEnemySPD,
                                    *nEnemyCrit,
                                    /* 'Show instructions' flag */
                                    1);

                /* Get player action
                 * getchar() removes trailing newline from input stream
                 */
                printf (">> ");
                scanf (" %d", &nPlayerAction);
                getchar ();

                /* Validate input (0, 1, or 2 only) */
                while (nPlayerAction < 0 || nPlayerAction > 2) {
                        printf (">> Invalid input. Try again: ");
                        scanf (" %d", &nPlayerAction);
                        getchar ();
                }

                /* Randomly pick enemy action
                 * Modulo bias in rand() % n is negligible for small n
                 */
                nEnemyAction = rand () % 3;

                /* Clear screen */
                system ("cls");

                /* Process action order
                 * If at least one of the following conditions are true:
                 * - Player SPD is greater than enemy SPD AND the enemy did not choose to block
                 * - The player chose to block
                 * The player's action will be processed before the enemy's
                 */
                if ((*nPlayerSPD > *nEnemySPD && nEnemyAction != 1) || nPlayerAction == 1) {
                        /* Process player action */
                        processAction (nPlayerAction,
                                       /* Player stats */
                                       nPlayerCurrentHP,
                                       nPlayerBaseHP,
                                       nPlayerATK,
                                       nPlayerDEF,
                                       nPlayerSPD,
                                       nPlayerCrit,
                                       /* Enemy stats */
                                       nEnemyCurrentHP,
                                       nEnemyBaseHP,
                                       nEnemyATK,
                                       nEnemyDEF,
                                       nEnemySPD,
                                       nEnemyCrit,
                                       /* Flags */
                                       &nPlayerIsCharging,
                                       1);

                        /* Only process the enemy's action if HP has not yet dropped to 0 */
                        if (*nEnemyCurrentHP > 0)
                                /* Process enemy action
                                 * Note inverted order of enemy and player stats
                                 */
                                processAction (nEnemyAction,
                                               /* Enemy stats */
                                               nEnemyCurrentHP,
                                               nEnemyBaseHP,
                                               nEnemyATK,
                                               nEnemyDEF,
                                               nEnemySPD,
                                               nEnemyCrit,
                                               /* Player stats */
                                               nPlayerCurrentHP,
                                               nPlayerBaseHP,
                                               nPlayerATK,
                                               nPlayerDEF,
                                               nPlayerSPD,
                                               nPlayerCrit,
                                               /* Flags */
                                               &nEnemyIsCharging,
                                               0);
                        /* If neither of the previous conditions AND at least one of the following
                         * are true:
                         * - Enemy SPD is greater than player SPD AND the player did not choose to
                         * block
                         * - The enemy chose to block
                         * The enemy's action will be processed before the player's
                         */
                } else if ((*nEnemySPD > *nPlayerSPD && nPlayerAction != 1) || nEnemyAction == 1) {
                        /* Process enemy action */
                        processAction (nEnemyAction,
                                       /* Enemy stats */
                                       nEnemyCurrentHP,
                                       nEnemyBaseHP,
                                       nEnemyATK,
                                       nEnemyDEF,
                                       nEnemySPD,
                                       nEnemyCrit,
                                       /* Player stats */
                                       nPlayerCurrentHP,
                                       nPlayerBaseHP,
                                       nPlayerATK,
                                       nPlayerDEF,
                                       nPlayerSPD,
                                       nPlayerCrit,
                                       /* Flags */
                                       &nEnemyIsCharging,
                                       0);

                        /* Only process the player's action if HP has not yet dropped to 0 */
                        if (*nPlayerCurrentHP > 0)
                                /* Process player action */
                                processAction (nPlayerAction,
                                               /* Player stats */
                                               nPlayerCurrentHP,
                                               nPlayerBaseHP,
                                               nPlayerATK,
                                               nPlayerDEF,
                                               nPlayerSPD,
                                               nPlayerCrit,
                                               /* Enemy stats */
                                               nEnemyCurrentHP,
                                               nEnemyBaseHP,
                                               nEnemyATK,
                                               nEnemyDEF,
                                               nEnemySPD,
                                               nEnemyCrit,
                                               /* Flags */
                                               &nPlayerIsCharging,
                                               1);
                        /* If none of the previous conditions have been met, then a SPD tie has
                         * occurred
                         */
                } else {
                        /* Announce SPD tie */
                        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
                        printf ("| A SPD tie has occurred!%*c\n", WINDOW_WIDTH - 25, '|');
                        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
                        updateBattleScreen (/* Player stats */
                                            *nPlayerCurrentHP,
                                            *nPlayerBaseHP,
                                            *nPlayerATK,
                                            *nPlayerDEF,
                                            *nPlayerSPD,
                                            *nPlayerCrit,
                                            /* Enemy stats */
                                            *nEnemyCurrentHP,
                                            *nEnemyBaseHP,
                                            *nEnemyATK,
                                            *nEnemyDEF,
                                            *nEnemySPD,
                                            *nEnemyCrit,
                                            /* 'Show instructions' flag */
                                            0);
                        playerConfirm ();
                        system ("cls");

                        /* Process player action */
                        processAction (nPlayerAction,
                                       /* Player stats */
                                       nPlayerCurrentHP,
                                       nPlayerBaseHP,
                                       nPlayerATK,
                                       nPlayerDEF,
                                       nPlayerSPD,
                                       nPlayerCrit,
                                       /* Enemy stats */
                                       nEnemyCurrentHP,
                                       nEnemyBaseHP,
                                       nEnemyATK,
                                       nEnemyDEF,
                                       nEnemySPD,
                                       nEnemyCrit,
                                       /* Flags */
                                       &nPlayerIsCharging,
                                       1);

                        /* Announce simultaneous action */
                        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
                        printf ("| And, at the same time...%*c\n", WINDOW_WIDTH - 26, '|');
                        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
                        updateBattleScreen (/* Player stats */
                                            *nPlayerCurrentHP,
                                            *nPlayerBaseHP,
                                            *nPlayerATK,
                                            *nPlayerDEF,
                                            *nPlayerSPD,
                                            *nPlayerCrit,
                                            /* Enemy stats */
                                            *nEnemyCurrentHP,
                                            *nEnemyBaseHP,
                                            *nEnemyATK,
                                            *nEnemyDEF,
                                            *nEnemySPD,
                                            *nEnemyCrit,
                                            /* 'Show instructions' flag */
                                            0);
                        playerConfirm ();
                        system ("cls");

                        /* Process enemy action */
                        processAction (nEnemyAction,
                                       /* Enemy stats */
                                       nEnemyCurrentHP,
                                       nEnemyBaseHP,
                                       nEnemyATK,
                                       nEnemyDEF,
                                       nEnemySPD,
                                       nEnemyCrit,
                                       /* Player stats */
                                       nPlayerCurrentHP,
                                       nPlayerBaseHP,
                                       nPlayerATK,
                                       nPlayerDEF,
                                       nPlayerSPD,
                                       nPlayerCrit,
                                       /* Flags */
                                       &nEnemyIsCharging,
                                       0);
                }

                /* If player and/or enemy chose to block, reset DEF */
                if (nPlayerAction == 1)
                        *nPlayerDEF /= 2;
                if (nEnemyAction == 1)
                        *nEnemyDEF /= 2;

                /* If player and/or enemy chose to charge, reset ATK/SPD */
                if (nPlayerIsCharging) {
                        *nPlayerATK /= 2;
                        *nPlayerSPD /= 2;
                        nPlayerIsCharging = 0;
                }
                if (nEnemyIsCharging) {
                        *nEnemyATK /= 2;
                        *nEnemySPD /= 2;
                        nEnemyIsCharging = 0;
                }

                /* If player and/or enemy has charged ATK/SPD, enable flag
                 * This will allow them to be reset next turn
                 */
                if (nPlayerAction == 2)
                        nPlayerIsCharging = 1;
                if (nEnemyAction == 2)
                        nEnemyIsCharging = 1;
        }
}

/* This function handles inputting of stats for either the player or the enemy
 * @param *nTargetHP is a pointer to the address storing the target's HP stat
 * @param *nTargetATK is a pointer to the address storing the target's ATK stat
 * @param *nTargetDEF is a pointer to the address storing the target's DEF stat
 * @param *nTargetSPD is a pointer to the address storing the target's SPD stat
 * @param *nTargetCrit is a pointer to the address storing the target's critical chance stat
 */
void
promptSetStats (int *nTargetHP,
                int *nTargetATK,
                int *nTargetDEF, 
                int *nTargetSPD,
                int *nTargetCrit)
{
        int nStatsConfirmed = 0;

        /* Get and validate stats input
         * getchar() removes trailing newline from input stream
         */
        while (nStatsConfirmed == 0) {
                /* scanf() must read exactly 5 inputs */
                if (scanf (" %d/%d/%d/%d/%d",
                           nTargetHP,
                           nTargetATK,
                           nTargetDEF,
                           nTargetSPD,
                           nTargetCrit)
                    != 5)
                        printf (">> Invalid input. Try again: ");
                /* HP, ATK, DEF, and SPD must be at most 999 */
                else if (*nTargetHP < 0 || *nTargetATK < 0 || *nTargetDEF < 0 || *nTargetSPD < 0
                         || *nTargetCrit < 0)
                        printf (">> Stats cannot be lower than 0. Try again: ");
                /* HP, ATK, DEF, and SPD must be at most 999 */
                else if (*nTargetHP > 999 || *nTargetATK > 999 || *nTargetDEF > 999
                         || *nTargetSPD > 999)
                        printf (">> HP, ATK, DEF, and SPD cannot be higher than 999. Try again: ");
                /* nTargetCrit must be at most 100 */
                else if (*nTargetCrit > 100)
                        printf (">> Critical hit chance cannot be higher than 100. Try again: ");
                /* Input is valid */
                else
                        nStatsConfirmed = 1;
                getchar ();
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
                int *nPlayerHP,
                int *nPlayerATK,
                int *nPlayerDEF,
                int *nPlayerSPD,
                int *nPlayerCrit,
                /* Enemy stats */
                int *nEnemyHP,
                int *nEnemyATK,
                int *nEnemyDEF,
                int *nEnemySPD,
                int *nEnemyCrit)
{
        system ("cls");
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printBlock (1,
                    WINDOW_WIDTH,
                    '|',
                    "Enter player stats separated by forward slashes (HP/ATK/DEF/SPD/CRIT)",
                    '|',
                    '\n');
        printBlock (1,
                    WINDOW_WIDTH,
                    '|',
                    "Critical chance is expressed as a number from 0 to 100.",
                    '|',
                    '\n');
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printf (">> ");

        /* Prompt user to input stats for the player */
        promptSetStats (nPlayerHP, nPlayerATK, nPlayerDEF, nPlayerSPD, nPlayerCrit);

        system ("cls");
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printBlock (1,
                    WINDOW_WIDTH,
                    '|',
                    "Enter enemy stats separated by forward slashes (HP/ATK/DEF/SPD/CRIT)",
                    '|',
                    '\n');
        printBlock (1,
                    WINDOW_WIDTH,
                    '|',
                    "Critical chance is expressed as a number from 0 to 100.",
                    '|',
                    '\n');
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printf (">> ");

        /* Prompt user to input stats for the enemy */
        promptSetStats (nEnemyHP, nEnemyATK, nEnemyDEF, nEnemySPD, nEnemyCrit);
}

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
              int *nPlayerHP,
              int *nPlayerATK,
              int *nPlayerDEF,
              int *nPlayerSPD,
              int *nPlayerCrit,
              /* Enemy stats */
              int *nEnemyHP,
              int *nEnemyATK,
              int *nEnemyDEF,
              int *nEnemySPD,
              int *nEnemyCrit)
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

        promptEnemyEquipConfirm (nEnemyHP, nEnemyATK, nEnemyDEF, nEnemySPD, nEnemyCrit);
}

/* Main function */
int
main ()
{
        /* Initialize seed for rand() */
        srand (time (NULL));

        /* Print the title screen */
        showTitleScreen ();

        /* Initialize player and enemy stats */
        int nPlayerHP = 100, nPlayerATK = 10, nPlayerDEF = 10, nPlayerSPD = 10, nPlayerCrit = 15;
        int nEnemyHP = 100, nEnemyATK = 10, nEnemyDEF = 10, nEnemySPD = 10, nEnemyCrit = 15;

        /* Determine gameplay mode */
        int nIsDevMode = promptSelectMode ();

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

        /* Announce game end, followed by results */
        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');
        printBlock (1, WINDOW_WIDTH, '|', "G A M E   O V E R", '|', '\n');

        if (nPlayerCurrentHP == 0 && nEnemyCurrentHP > 0)
                printBlock (1, WINDOW_WIDTH, '|', "You lost...", '|', '\n');
        else if (nPlayerCurrentHP > 0 && nEnemyCurrentHP == 0)
                printBlock (1, WINDOW_WIDTH, '|', "You won!", '|', '\n');
        else
                printBlock (1, WINDOW_WIDTH, '|', "It's a draw!", '|', '\n');

        printBorder (WINDOW_WIDTH, '[', '=', ']', '\n');

        playerConfirm ();
}
