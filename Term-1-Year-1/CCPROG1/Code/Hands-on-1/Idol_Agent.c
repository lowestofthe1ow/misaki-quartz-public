/******************
You are NOT allowed to modify this code (Except for Line no. 11)

This file is merely used for checking your solution
******************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Marqueses.c" // Modify this into your SURNAME.c. Ex: "Yazawa.c"



enum TWICE {
	backup_dancer,
	jihyo,
	nayeon,
	jeongyeon,
	momo,
	sana,
	mina,
	dahyun,
	chaeyoung,
	tzuyu
};



void init(char TWICE[10][35])
{
	
	strcpy(TWICE[0],"backup_dancer");
	strcpy(TWICE[1],"Jihyo");
	strcpy(TWICE[2],"Nayeon");
	strcpy(TWICE[3],"Jeongyeon");
	strcpy(TWICE[4],"Momo");
	strcpy(TWICE[5],"Sana");
	strcpy(TWICE[6],"Mina");
	strcpy(TWICE[7],"Dahyun");
	strcpy(TWICE[8],"Chaeyoung");
	strcpy(TWICE[9],"Tzuyu");
}

void speak(char name[])
{
	printf ("%s: Hello! My name is %s\n",name,name);
	
}
void introduction(char TWICE[10][35],int group,int checkerFlag)
{
	char formation[50];
	
	sprintf(formation,"%d",group);
	
	int n = strlen(formation);
	
	while (n)
		if (checkerFlag)
			speak(TWICE[extractDigit(group,n--)]);
		else
			speak(TWICE[extractDigit_FromAgent(group,n--)]);
}

void performance1(char TWICE[10][35],int group)
{
	char formation[9];	
	
	/* 1st number */
	sprintf(formation,"%d%d%d",nayeon,tzuyu,jeongyeon);
	if (isSuccessfulTrio(atoi(formation),nayeon,jeongyeon,tzuyu))
		printf ("First number is successful with %s, %s, and %s!\n",TWICE[nayeon],TWICE[jeongyeon],TWICE[tzuyu]);
	else
		printf ("First number is unsuccessful. :(\n");
	
	/* 2nd number. All is present */
	sprintf(formation,"%d%d%d%d",sana,mina,dahyun,chaeyoung);
	if (isSuccessfulTrio(atoi(formation),mina,sana,chaeyoung))
		printf  ("Second number is successful!\n");
	else
		printf ("Second number is unsuccessful. :(\n");
	
	/* 3rd checker. All TWICE members should be present. */
	if (isSuccessfulGroup(group))
		printf ("All members of TWICE performed the last number!\n");
	else
		printf ("Not all members are present. :(");
}

void performance2(char TWICE[10][35],int group)
{
	char formation[5];
	
	
	/* 1st number */
	sprintf(formation,"%d%d%d",nayeon,tzuyu,jeongyeon);
	if (isSuccessfulTrio(atoi(formation),nayeon,jeongyeon,tzuyu))
		printf ("First number is successful with %s, %s, and %s!\n",TWICE[nayeon],TWICE[jeongyeon],TWICE[tzuyu]);
	else
		printf ("First number is unsuccessful. :(\n");
	
	/* 2nd number. Chaeyoung is absent. Replaced by momo*/
	sprintf(formation,"%d%d%d%d",sana,mina,dahyun,momo);
	if (isSuccessfulTrio(atoi(formation),mina,sana,chaeyoung))
		printf  ("Second number is successful!\n");
	else
		printf ("Second number is unsuccessful. :(\n");
	
	/* 3rd checker. All TWICE members should be present. That's not the case. */
	if (isSuccessfulGroup(group))
		printf ("All members of TWICE performed the last number!\n");
	else
		printf ("Not all members are present. :(");
}

void performance3(char TWICE[10][35],int group)
{
	char formation[2];
	
	sprintf(formation,"%d",nayeon);
	group = atoi(formation);
	
	/* 1st number */
	sprintf(formation,"%d",nayeon);
	if (isSuccessfulTrio(atoi(formation),nayeon,jeongyeon,tzuyu))
		printf ("First number is successful with %s, %s, and %s!\n",TWICE[nayeon],TWICE[jeongyeon],TWICE[tzuyu]);
	else
		printf ("First number is unsuccessful. :(\n");
	
	/* 2nd number. All is present */
	sprintf(formation,"%d",nayeon);
	if (isSuccessfulTrio(atoi(formation),mina,sana,chaeyoung))
		printf  ("Second number is successful!\n");
	else
		printf ("Second number is unsuccessful. :(\n");
	
	
	if (isSuccessfulGroup(group))
		printf ("All members of TWICE performed the last number!\n");
	else
		printf ("Not all members are present. :(");
}

void performance4 (int group)
{
	if (isSuccessfulGroup(group))
		printf ("All members of TWICE are present!\n");
	else
		printf ("Not all members are present. :(");
}

int main()
{
	int idol_group, scenario, checkerFlag;
	char TWICE[10][35];
	char lineCheck[51],l1[51],l2[52];
	FILE *checker;
	
	init(TWICE);
	
	checker = fopen(NICO_YAZAWA,MAKI_NISHIKINO);
	
	if (checker != NULL)
	{
		fgets(lineCheck,sizeof(lineCheck),checker);
		sscanf(lineCheck,"%s%s%d",l1,l2,&checkerFlag);
		if (checkerFlag != 0)
			checkerFlag = 1;
	}
	else
		checkerFlag = 1;
		
	printf ("Check your HO1!\n");
	if (checkerFlag == 1)
		printf ("Check extractDigit()? YES\n");
	else
		printf ("Check extractDigit()? NO\n");
	printf ("\n");
	printf ("Enter test set 1 - 4:\n");
	printf ("[1] - Complete TWICE group\n");
	printf ("[2] - Chaeyoung is sick\n");
	printf ("[3] - Nayeon is all alone\n");
	printf ("[4] - Manually enter formation");
	printf ("\n");
	printf ("Test set: ");
	
	scanf ("%d",&scenario);
	
	system ("cls");
	
	if (scenario == 1)
	{
		idol_group = 123876549;
		printf ("Scenario: Complete TWICE group\n");
		printf ("Hana, dul set...\n");
		printf ("ANNYEONG HASEYO! TWICE IMNIDA!\n");
		printf ("\n");
		printf ("%d detected formation!...\n",idol_group);
		printf ("***AI Translating to English Commence***\n");
		printf ("\n");
		
		introduction(TWICE,idol_group,checkerFlag);
		
		printf ("\n");
		
		performance1(TWICE,idol_group);
	}
	
	else if (scenario == 2)
	{
		idol_group = 12396754;
		printf ("Scenario: Chaeyoung is sick\n");
		printf ("Hana, dul set...\n");
		printf ("ANNYEONG HASEYO! TWICE IMNIDA!\n");
		printf ("\n");
		printf ("%d detected formation!...\n",idol_group);
		printf ("***AI Translating to English Commence***\n");
		printf ("\n");
		
		introduction(TWICE,idol_group,checkerFlag);
		
		printf ("\n");
		
		performance2(TWICE,idol_group);
	}
	
	else if (scenario == 3)
	{
		idol_group = nayeon;
		printf ("Scenario: Nayeon is all alone\n");
		printf ("Hana, dul set...\n");
		printf ("ANNYEONG HASEYO! TWICE IMNIDA!\n");
		printf ("\n");
		printf ("%d detected formation!...\n",idol_group);
		printf ("***AI Translating to English Commence***\n");
		printf ("\n");
		
		introduction(TWICE,idol_group,checkerFlag);
		
		printf ("\n");
		
		performance3(TWICE,idol_group);
	}
	else if (scenario == 4)
	{
		printf ("Enter idol formation: ");
		scanf ("%d",&idol_group);
		
		printf ("\n");
		printf ("Scenario: Manual formation\n");
		printf ("Hana, dul set...\n");
		printf ("ANNYEONG HASEYO! TWICE IMNIDA!\n");
		printf ("\n");
		printf ("%d detected formation!...\n",idol_group);
		printf ("***AI Translating to English Commence***\n");
		printf ("\n");
		
		introduction(TWICE,idol_group,checkerFlag);
		
		printf ("\n");
		
		performance4(idol_group);
	}
	return 0;
}

