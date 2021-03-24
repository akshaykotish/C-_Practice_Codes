#include<stdio.h>
#include<conio.h>

char to_print[1000];
char input_txt[1000];
char from_change[1000];
char to_change[1000];
char current_status[1000];
int pointer = 0;

int to_print_Length()
{
	int len = 0;
	char c= to_print[0];
	while(c != '\0')
	{
		char c= to_print[0];
		len++;
	}
	return len;
}


int input_txt_Length()
{
	int len = 0;
	char c= input_txt[0];
	while(c != '\0')
	{
		char c= input_txt[0];
		len++;
	}
	return len;
}

int from_change_Length()
{
	int len = 0;
	char c= from_change[0];
	while(c != '\0')
	{
		char c= from_change[0];
		len++;
	}
	return len;
}

int to_change_Length()
{
	int len = 0;
	char c= to_change[0];
	while(c != '\0')
	{
		char c= to_change[0];
		len++;
	}
	return len;
}

int current_status_Length()
{
	int len = 0;
	char c= current_status[0];
	while(c != '\0')
	{
		char c= current_status[0];
		len++;
	}
	return len;
}

void Input()
{
	gets(input_txt);
	gets(from_change);
	gets(to_change);
}

void Matching()
{
	printf("Pos1\n");
	int i=0;
	int from_len = from_change_Length();
	
	int j = pointer;
	int input_txt_len = input_txt_Length();
	
	int count = 0;
	while(i < from_len)
	{
		if(input_txt[j] == from_change[i])
		{
			count++;
		}
		else{
			count = 0;
			break;
		}
		i++;
		j++;
	}
	
	if(count == from_len)
	{
		current_status[0] = 'M';
		current_status[1] = 'a';
		current_status[2] = 't';
		current_status[3] = 'c';
		current_status[4] = 'h';
		current_status[5] = 'e';
		current_status[6] = 'd';
		int k = 0;
		int l = 0;
		while(k < input_txt_len)
		{
			if(k == pointer)
			{
				int temp = 0;
				int to_chng_len = to_change_Length();
				while(temp < to_chng_len)
				{
					to_print[l] = to_change[temp];
					l++;
					temp++;
				}
				k = k + from_len - 1;
			}
			else{
				to_print[l] = input_txt[k];
				l++;
				k++;
			}
		}
	}
	else{
	printf("Pos2\n");
		current_status[0] = 'N';
		current_status[1] = 'o';
		current_status[2] = 't';
		current_status[3] = ' ';
		current_status[4] = 'M';
		current_status[5] = 'a';
		current_status[6] = 't';
		current_status[7] = 'c';
		current_status[8] = 'h';
		current_status[9] = 'e';
		current_status[10] = 'd';
	}
	printf("Pos3\n");
}


int main()
{
	Input();
	int len = input_txt_Length();
	pointer = 0;
	printf("running")
	while(pointer < len)
	{
		Matching();
		printf("%s\n", to_print);
		pointer++;
	}
}

