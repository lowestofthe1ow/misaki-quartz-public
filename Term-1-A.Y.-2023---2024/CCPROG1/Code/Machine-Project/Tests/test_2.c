#define WINDOW_WIDTH 80 // ISO/ANSI screen width is 80 characters.
#define COLUMN_WIDTH_1 WINDOW_WIDTH / 3
#define COLUMN_WIDTH_2 WINDOW_WIDTH / 3 * 2 + 1

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
                    int         showInstructions)
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
        if (showInstructions) {
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

/*
int maain()
{
        int nPlayerHP = 100, nPlayerATK = 10, nPlayerDEF = 10, nPlayerSPD = 10, nPlayerCrit = 15;
        int nEnemyHP = 100, nEnemyATK = 10, nEnemyDEF = 10, nEnemySPD = 10, nEnemyCrit = 15;
        
        updateBattleScreen (nPlayerHP, nPlayerHP, nPlayerATK, nPlayerDEF, nPlayerSPD, nPlayerCrit,
                         nEnemyHP, nEnemyHP, nEnemyATK, nEnemyDEF, nEnemySPD, nEnemyCrit,
                         1);
                         
        return 0;
}*/
