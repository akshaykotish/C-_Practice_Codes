#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <dos.h>



char str[200];
int maxvl = 200;
int pntr = 0;
int status = 0;
char rep_frm[200];
char rep_to[200];
int tocolor;

void Input()
{
	gets(str); 
	gets(rep_frm); 
	gets(rep_to); 
}

void Match()
{
	int flag = 0;
	int i=0;
	while(i<200)
	{
		char c = rep_frm[i];
		if(c != '\0' && ((int)c>=65 && (int)c<=90) || ((int)c>=97 && (int)c<=122) || (c == ' '))
		{
			if(rep_frm[i] == str[pntr + i])
			{
				flag = 1;
				tocolor++;
			}
			else{
				flag = 0;
				tocolor=0;
				break;
			}
		}
		else{
			break;
		}
		i++;
	}
	if(flag == 1)
	{
		status = 1;
	}
	else{
		status = 0;
	}
}

void Display()
{
	Match();
	int i = 0;
	while(i<maxvl)
	{
		char c = str[i];
		if(c != '\0' && ((int)c>=65 && (int)c<=90) || ((int)c>=97 && (int)c<=122) || (c == ' '))
		{
		
			if(status == 0)
			{
				printf("%c", c);
			}
			else{ 
				if(i == pntr)
				{
					printf("%s", rep_to);
					i = i+tocolor -1;	
					
				}
				else{
					printf("%c", c);
				}

			}
		}
		i++;
	}
	i = 0;
	printf("\n");
	while(i<pntr)
	{
		printf(" ");
		i++;
	}
	printf("^\n");
	i=0;
	while(i<pntr)
	{
		printf(" ");
		i++;
	}
	if(status == 1)
	{
		printf("Matched\n");
		status = 2;
	}
	else if(status == 2)
	{
		printf("Replaced\n");
		status = 0;
	}
	else{
		printf("Not Matched\n");
	}
}

int main()
{
	Input();
	while(str[pntr] != '\0')
	{
		system("CLS");
		Display();
		pntr++;
		Sleep(1000);
	}
}
