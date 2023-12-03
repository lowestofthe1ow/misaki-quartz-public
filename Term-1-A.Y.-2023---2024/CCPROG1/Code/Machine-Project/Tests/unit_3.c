#define WINDOW_WIDTH 80 // ISO/ANSI screen width is 80 characters.
#define COLUMN_WIDTH_1 WINDOW_WIDTH / 3
#define COLUMN_WIDTH_2 WINDOW_WIDTH / 3 * 2 + 1

/* This function calculates damage dealt by the actor to the target and updates the target's current HP
 * @param nActorATK is the actor's ATK stat
 * @param nActorCrit is the actor's critical chance stat
 * @param *nTargetCurrentHP is the pointer to the address storing the target's current HP
 * @param nTargetDEF is the target's DEF stat
 * @param nActorIsPlayer is a flag that determines whether the actor is the player or the enemy (for printing)
 */
void
processAttack (int      nActorATK,
               int      nActorCrit,
               int     *nTargetCurrentHP,
               int      nTargetDEF,
               int      nActorIsPlayer)
{
        /* Roll for a critical hit */
        int nCritRoll = rand() % 100;
        
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
         * (Only calculate if actor ATK > target DEF, otherwise damage remains as its default value of 0)
         */
        else if (nActorATK > nTargetDEF)
                nDamage = nActorATK - nTargetDEF;
                
        /* If damage is greater than enemy remaining HP, set damage to match it */
        if (nDamage > *nTargetCurrentHP)
                nDamage = *nTargetCurrentHP;
                
        /* Subtract damage from target HP */
        *nTargetCurrentHP -= nDamage;
        
        /* Print message depending on if actor is the player or the opponent */
        printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
        if (nActorIsPlayer)
                /* Message differs if actor landed a critical hit */
                if (nCritRoll < nActorCrit)
                        printf("| You landed a critical hit! DEF ignored. Dealt %3d damage.%*c\n", nDamage, WINDOW_WIDTH - 59, '|');
                else
                        printf("| You attacked! Dealt %3d damage.%*c\n", nDamage, WINDOW_WIDTH - 33, '|');
        else
                if (nCritRoll < nActorCrit)
                        printf("| Enemy landed a critical hit! DEF ignored. Dealt %3d damage.%*c\n", nDamage, WINDOW_WIDTH - 61, '|');
                else
                        printf("| Enemy attacked! Dealt %3d damage.%*c\n", nDamage, WINDOW_WIDTH - 35, '|');
        printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
}

/* This function modifies the actor's DEF stat when the Block action is selected
 * @param *nActorDEF is a pointer to the address storing the actor's DEF stat
 * @param nActorIsPlayer is a flag that determines whether the actor is the player or the enemy (for printing)
 */
void
processBlock (int      *nActorDEF,
              int       nActorIsPlayer)
{
        /* Multiply actor DEF by 2 */
        *nActorDEF *= 2;
        
        /* Print message depending on if actor is the player or opponent */
        printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
        if (nActorIsPlayer)
                printf("| You blocked! DEF doubled this turn.%*c\n", WINDOW_WIDTH - 37, '|');
        else
                printf("| Enemy blocked! DEF doubled this turn.%*c\n", WINDOW_WIDTH - 39, '|');
        printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
}

/* This function modifies the actor's ATK and SPD stat when the Charge action is selected
 * If the flag at the address provided by *nActorIsCharging is alread enabled, it is disabled and ATK and SPD remain doubled
 * @param *nActorATK is a pointer to the address storing the actor's DEF stat
 * @param *nActorSPD is a pointer to the address storing the actor's ATK stat
 * @param nActorIsPlayer is a flag that determines whether the actor is the player or the enemy (for printing)
 * @param *nActorIsCharging is a pointer to the address storing the flag that identifies whether the actor is currently charging
 */
void
processCharge (int     *nActorATK,
               int     *nActorSPD,
               int      nActorIsPlayer,
               int     *nActorIsCharging)
{
        /* Handle action depending on if actor is the player or opponent */
        printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
        /* If charging flag is 0 (false) */
        if (*nActorIsCharging == 0) {
                /* Double actor ATK and SPD */
                *nActorATK *= 2;
                *nActorSPD *= 2;
                
                /* Print message depending on if actor is the player or opponent */
                if (nActorIsPlayer)
                        printf("| You charged! ATK and SPD doubled until the end of the next turn.%*c\n", WINDOW_WIDTH - 66, '|');
                else
                        printf("| Enemy charged! ATK and SPD doubled until the end of the next turn.%*c\n", WINDOW_WIDTH - 68, '|');
        /* If charging flag is true */
        } else {
                /* Disable charging flag to "delay" ATK/SPD reset by 1 turn for the actor */
                *nActorIsCharging = 0;
                
                /* Print message depending on if actor is the player or opponent */
                if (nActorIsPlayer)
                        printf("| You kept charging! ATK and SPD doubled until the end of the next turn.%*c\n", WINDOW_WIDTH - 72, '|');
                else
                        printf("| Enemy kept charging! ATK and SPD doubled until the end of the next turn.%*c\n", WINDOW_WIDTH - 74, '|');
        }        
        printBorder(WINDOW_WIDTH, '[', '=', ']', '\n');
}

/* This function processes the action selected by either the player or the enemy and calls the relevant function for handling it
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
 * @param *nActorIsCharging is a pointer to the address storing the flag that identifies whether the actor is currently charging
 * @param nActorIsPlayer is a flag that determines whether the actor is the player or the enemy (for printing)
 */
void   
processAction (int      nAction,
               /* Actor stats */
               int     *nActorCurrentHP,
               int     *nActorBaseHP,
               int     *nActorATK,
               int     *nActorDEF,
               int     *nActorSPD,
               int     *nActorCrit,
               /* Target stats */
               int     *nTargetCurrentHP,
               int     *nTargetBaseHP,
               int     *nTargetATK,
               int     *nTargetDEF,
               int     *nTargetSPD,
               int     *nTargetCrit,
               /* Flags */
               int     *nActorIsCharging,
               int      nActorIsPlayer)
{
        /* Determine which action to take */
        switch (nAction) {
                /* Attack action (nAction == 0) */
                case 0:
                        processAttack(*nActorATK, *nActorCrit, nTargetCurrentHP, *nTargetDEF, nActorIsPlayer);
                        break;
                /* Block action (nAction == 1) */
                case 1:
                        processBlock(nActorDEF, nActorIsPlayer);
                        break;
                /* Charge action (nAction == 2) */
                case 2:
                        processCharge(nActorATK, nActorSPD, nActorIsPlayer, nActorIsCharging);
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
        playerConfirm();
        system("cls");
}
