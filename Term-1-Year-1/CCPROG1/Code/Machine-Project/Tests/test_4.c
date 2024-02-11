#define WINDOW_WIDTH 80 // ISO/ANSI screen width is 80 characters.
#define COLUMN_WIDTH_1 WINDOW_WIDTH / 3
#define COLUMN_WIDTH_2 WINDOW_WIDTH / 3 * 2 + 1

void
beginBattle (/* Player stats */
             int       *nPlayerCurrentHP,
             int       *nPlayerBaseHP,
             int       *nPlayerATK,
             int       *nPlayerDEF,
             int       *nPlayerSPD,
             int       *nPlayerCrit,
             /* Enemy stats */
             int       *nEnemyCurrentHP,
             int       *nEnemyBaseHP,
             int       *nEnemyATK,
             int       *nEnemyDEF,
             int       *nEnemySPD,
             int       *nEnemyCrit)
{
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
                printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
                printf("| Enter an action (0/1/2).%*c\n", WINDOW_WIDTH - 26, '|');
                printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');                   
                updateBattleScreen(/* Player stats */
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
                printf(">> ");
                scanf(" %d", &nPlayerAction);
                getchar();
                
                /* Validate input (0, 1, or 2 only) */
                while (nPlayerAction < 0 || nPlayerAction > 2) {
                        printf(">> Invalid input. Try again: ");
                        scanf(" %d", &nPlayerAction);
                        getchar();
                }
                
                /* Randomly pick enemy action
                 * Modulo bias in rand() % n is negligible for small n
                 */
                nEnemyAction = rand() % 3;
                
                /* Clear screen */
                system("cls");
                
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
                /* If neither of the previous conditions AND at least one of the following are true:
                 * - Enemy SPD is greater than player SPD AND the player did not choose to block
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
                /* If none of the previous conditions have been met, then a SPD tie has occurred
                 * TODO: Add function that allows for simultaneous processing of player and enemy actions
                 */
                } else {
                        /* Announce SPD tie */
                        printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
                        printf("| A SPD tie has occurred!%*c\n", WINDOW_WIDTH - 25, '|');
                        printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
                        updateBattleScreen(/* Player stats */
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
                        playerConfirm();
                        system("cls");
                        
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
                        printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
                        printf("| And, at the same time...%*c\n", WINDOW_WIDTH - 26, '|');
                        printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
                        updateBattleScreen(/* Player stats */
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
                        playerConfirm();
                        system("cls");
                        
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
/*
int main()
{
        int nPlayerHP = 100, nPlayerATK = 11, nPlayerDEF = 12, nPlayerSPD = 13, nPlayerCrit = 15;
        int nEnemyHP = 100, nEnemyATK = 9, nEnemyDEF = 8, nEnemySPD = 13, nEnemyCrit = 15;
        
        int nPlayerCurrentHP = nPlayerHP, nEnemyCurrentHP = nEnemyHP;
        
        beginBattle (&nPlayerCurrentHP, &nPlayerHP, &nPlayerATK, &nPlayerDEF, &nPlayerSPD, &nPlayerCrit,
                     &nEnemyCurrentHP, &nEnemyHP, &nEnemyATK, &nEnemyDEF, &nEnemySPD, &nEnemyCrit);
}*/
