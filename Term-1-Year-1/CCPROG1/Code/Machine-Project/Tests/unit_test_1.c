#include "unit_test_0.c"
#include "unit_test_1.c"
#include "unit_test_2.c"
#include "unit_test_3.c"
#include "unit_test_4.c"

#define WINDOW_WIDTH 80 // ISO/ANSI screen width is 80 characters.
#define COLUMN_WIDTH_1 WINDOW_WIDTH / 3
#define COLUMN_WIDTH_2 WINDOW_WIDTH / 3 * 2 + 1

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

char *
equipArmor(int *nTargetHP,
           int *nTargetDEF,
           int *nTargetSPD,
           int  nInput)
{
        /* 'Equip' weapon based on selection input */
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

int
promptEquipConfirm (int        *nPlayerHP,
                    int        *nPlayerATK,
                    int        *nPlayerDEF,
                    int        *nPlayerSPD)
{
        char * cWeaponName = equipWeapon(nPlayerATK, nPlayerSPD, promptWeaponSelect());
        char * cArmorName = equipArmor(nPlayerHP, nPlayerDEF, nPlayerSPD, promptArmorSelect());
}

/*
int main()
{
        int nPlayerHP = 100, nPlayerATK = 10, nPlayerDEF = 10, nPlayerSPD = 10, nPlayerCrit = 15;
        int nEnemyHP = 100, nEnemyATK = 10, nEnemyDEF = 10, nEnemySPD = 10, nEnemyCrit = 15;
        
        char * cWeaponName = equipWeapon(&nPlayerATK, &nPlayerSPD, promptWeaponSelect());
        char * cArmorName = equipArmor(&nPlayerHP, &nPlayerDEF, &nPlayerSPD, promptArmorSelect());
        
        system("cls");
        
        showCurrentStatsEquip(nPlayerHP, nPlayerATK, nPlayerDEF, nPlayerSPD, nPlayerCrit, cWeaponName, cArmorName);
        return 0;
}*/
