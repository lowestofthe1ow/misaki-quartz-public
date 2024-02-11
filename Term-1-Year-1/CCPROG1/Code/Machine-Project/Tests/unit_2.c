#define WINDOW_WIDTH 80 // ISO/ANSI screen width is 80 characters.
#define COLUMN_WIDTH_1 WINDOW_WIDTH / 3
#define COLUMN_WIDTH_2 WINDOW_WIDTH / 3 * 2 + 1

/* This function prints a health bar of width nWidth
 * Remaining health is represented with the '#' character
 * Depleted health is represented with the ':' character
 * @param nWidth is the width of the health bar
 * @param nCurrentHP is the remaining HP value
 * @param nMaxHP is the base (max) HP value
 */
void
printGauge (int         nWidth,
            int         nCurrentHP,
            int         nMaxHP)
{
        /* Initialize number of '#' characters to be printed */
        int nCharsRemaining = 1.0 * nCurrentHP / nMaxHP * (nWidth - 4);
        
        /* Initialize number of ':' characters to be printed */
        int nCharsDepleted = nWidth - 4 - nCharsRemaining;
        
        /* Declare control/index variable for loops */
        int i;
        
        /* Print opening bracket */
        printf("[ ");
        
        /* Print '#' characters (remaining HP) */
        for (i = 0; i < nCharsRemaining; i++)
                printf("#");

        /* Print ':' characters (depleted HP) */
        for (i = 0; i < nCharsDepleted; i++)
                printf(":");

        /* Print closing bracket */
        printf(" ]");
}

/* This function prints the current state of the battle
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
 * @param nShowInstructions is a flag that determines whether to show list of actions and instructions
 */
void
updateBattleScreen (/* Player stats */
                    int         nPlayerCurrentHP,
                    int         nPlayerBaseHP,
                    int         nPlayerATK,
                    int         nPlayerDEF,
                    int         nPlayerSPD,
                    int         nPlayerCrit,
                    /* Enemy stats */
                    int         nEnemyCurrentHP,
                    int         nEnemyBaseHP,
                    int         nEnemyATK,
                    int         nEnemyDEF,
                    int         nEnemySPD,
                    int         nEnemyCrit,
                    /* 'Show instructions' flag */
                    int         nShowInstructions)
{
        printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder(COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printBorder(COLUMN_WIDTH_1, '[', '=', ']', '\n');
        
        printBlock(1, COLUMN_WIDTH_1, '|', "You", '|', ' ');
        printBlock(1, COLUMN_WIDTH_1, ' ', "VS", ' ', ' ');
        printBlock(1, COLUMN_WIDTH_1, '|', "Enemy", '|', '\n');
        
        printGauge(COLUMN_WIDTH_1, nPlayerCurrentHP, nPlayerBaseHP);
        printf(" ");
        printBorder(COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printGauge(COLUMN_WIDTH_1, nEnemyCurrentHP, nEnemyBaseHP);
        printf("\n");
        
        printf("| HP: %3d / %-3d%*c ", nPlayerCurrentHP, nPlayerBaseHP, COLUMN_WIDTH_1 - 15, '|');
        printBorder(COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printf("| HP: %3d / %-3d%*c\n", nEnemyCurrentHP, nEnemyBaseHP, COLUMN_WIDTH_1 - 15, '|');
        
        printBorder(COLUMN_WIDTH_1, '[', '-', ']', ' ');
        printBorder(COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printBorder(COLUMN_WIDTH_1, '[', '-', ']', '\n');
        
        printf("| ATK   \\ DEF   \\ SPD%*c ", COLUMN_WIDTH_1 - 21, '|');
        printBorder(COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printf("| ATK   / DEF   / SPD%*c\n", COLUMN_WIDTH_1 - 21, '|');
        
        printf("| %-4d  / %-4d  / %-4d%*c ", nPlayerATK, nPlayerDEF, nPlayerSPD, COLUMN_WIDTH_1 - 22, '|');
        printBorder(COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printf("| %-4d  \\ %-4d  \\ %-4d%*c\n", nEnemyATK, nEnemyDEF, nEnemySPD, COLUMN_WIDTH_1 - 22, '|');
        
        printf("| Critical chance: %3d%%%*c ", nPlayerCrit, COLUMN_WIDTH_1 - 23, '|');
        printBorder(COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printf("| Critical chance: %3d%%%*c\n", nEnemyCrit, COLUMN_WIDTH_1 - 23, '|');
        
        printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder(COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printBorder(COLUMN_WIDTH_1, '[', '=', ']', '\n');
        
        printf("\n");
        
        printBlock(1, COLUMN_WIDTH_1, ' ', "O", ' ', ' ');
        printBorder(COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printBlock(1, COLUMN_WIDTH_1, ' ', "O", ' ', '\n');
        
        printBlock(1, COLUMN_WIDTH_1, ' ', "/|\\", ' ', ' ');
        printBorder(COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printBlock(1, COLUMN_WIDTH_1, ' ', "/|\\", ' ', '\n');
        
        printBlock(1, COLUMN_WIDTH_1, ' ', "/ \\", ' ', ' ');
        printBorder(COLUMN_WIDTH_1, ' ', ' ', ' ', ' ');
        printBlock(1, COLUMN_WIDTH_1, ' ', "/ \\", ' ', '\n');
        
        printf("\n");
        
        printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder(COLUMN_WIDTH_2, '[', '=', ']', '\n');
        
        /* Hide or show options and instructions for action selection */
        if (nShowInstructions) {
                printBlock(0, COLUMN_WIDTH_1, '|', "[0] Attack", '|', ' ');
                printBlock(0, COLUMN_WIDTH_2, '|', "Deal damage to the enemy.", '|', '\n');
                printBlock(0, COLUMN_WIDTH_1, '|', "[1] Block", '|', ' ');
                printBlock(0, COLUMN_WIDTH_2, '|', "Brace yourself. (Doubles DEF this turn)", '|', '\n');
                printBlock(0, COLUMN_WIDTH_1, '|', "[2] Charge", '|', ' ');
                printBlock(0, COLUMN_WIDTH_2, '|', "Charge power. (Doubles ATK and SPD next turn)", '|', '\n');
        } else {
                printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
                printBorder(COLUMN_WIDTH_2, '|', ' ', '|', '\n');
                printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
                printBorder(COLUMN_WIDTH_2, '|', ' ', '|', '\n');
                printBorder(COLUMN_WIDTH_1, '|', ' ', '|', ' ');
                printBorder(COLUMN_WIDTH_2, '|', ' ', '|', '\n');
        }        
        
        printBorder(COLUMN_WIDTH_1, '[', '=', ']', ' ');
        printBorder(COLUMN_WIDTH_2, '[', '=', ']', '\n');
}
