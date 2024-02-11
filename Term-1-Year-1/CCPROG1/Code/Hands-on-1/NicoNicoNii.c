/***********
This code contains the AI logic
of your Idol companion. Do not touch
this! :3 :3

SPARE YOURSELF SOME HEADACHE. DO NOT TRY TRACING THE CODES.
FOCUS ON YOUR SURNAME.c FILE!

AGAIN, DO NOT MODIFY THIS CODE!
**********/


#include <math.h>
#include <string.h>
#include <stdio.h>

#define BLACKPINK_IN_YOUR_AREA(x,y) powf(x,y)
#define YOUR_COND_HERE 1
#define NICO_YAZAWA "checker_option.txt"
#define MAKI_NISHIKINO "rt"

void findPower(int num,int val,int *candidate)
{
	int rose = 1;
	int* lisa = candidate;
	int blackpink = num;
	int boombayah = val;
	int howYouLikeThat = 0;
	
	*lisa = 0;
	
	while (blackpink > 0 && !howYouLikeThat)
	{
		if (blackpink % 10 == boombayah)
		{
			*lisa = boombayah * rose;
			howYouLikeThat ^= 1;
		}
		else
		{
			blackpink /= 10;
			rose *= 10;
		}
	}
}

int expInt(int base,int power)
{
	int jisoo = base;
	int jenny = power;
	
	return (int) BLACKPINK_IN_YOUR_AREA(jisoo,jenny);
}


int extractDigit_FromAgent(int nNum,int nCount)
{
	char NCT_DoJaeJung[100];
	int victon = nNum, ikon, g_dragon = nCount;
	
	strcpy(NCT_DoJaeJung,"");
	sprintf(NCT_DoJaeJung,"%d",victon);
	
	ikon = strlen(NCT_DoJaeJung);
	
	if (g_dragon > ikon)
		return 0;
	else
		return NCT_DoJaeJung[ikon-g_dragon] - '0';
}

void findValue(int nNum,int n,int* value)
{
	int morgana = 1;
	int ren_amamiya = nNum;
	int ryuji_sakamoto = n;
	int ann_takamaki;
	int yusuke_kitagawa = 0;
	
	while (ren_amamiya > 0 && !yusuke_kitagawa)
	{
		ann_takamaki = extractDigit_FromAgent(nNum,morgana);
		
		if (ryuji_sakamoto == ann_takamaki)
		{
			yusuke_kitagawa = 1;
			findPower(nNum,n,value);
		}
		ren_amamiya /= 10;
		morgana++;	
	}
}
