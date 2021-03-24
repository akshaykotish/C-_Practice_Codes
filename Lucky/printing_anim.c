	#include<stdio.h>
	#include<conio.h>
	#include <stdlib.h>
	
	char to_backup[1000];
	char to_print[1000];
	char input_txt[1000];
	char from_change[1000];
	char to_change[1000];
	char current_status[1000];
	int sts = 0;
	int pointer = 0;
	
	void Display()
	{
		system("CLS");    
						
		if(sts == 3)
		{
			printf("\033[0;33m");
		}
		else{
			printf("\033[0m");
		}		  
											
		printf("%s\n",to_print);
		int i =0;
		while(i<pointer)
		{
			printf(" ");
			i++;
		}
		 
		printf("^\n");
		
		i =0;
		while(i<pointer)
		{
			printf(" ");			i++;

		}
		if(sts == 0)
		{
			  printf("\033[1;31m"); 
		}
		else if(sts == 2)
		{
			printf("\033[0;32m");
		}
		else if(sts == 3)
		{
			printf("\033[0;33m");
		}
		printf("%s\n",current_status);
		Sleep(1000);	  
		printf("\033[0m");
	}
	
	
	int to_print_Length()
	{
		int len = 0;
		char c= to_print[0];
		while(c != '\0')
		{
			if(((int)c>=65 && (int)c<=90) || ((int)c>=97 && (int)c<=122) || (c == ' '))
			{
				c= to_print[len];
				len++;
			}
			else{
				break;	
			}
		}
		return len-1;
	}
	
	
	int input_txt_Length()
	{
		int len = 0;
		char c= input_txt[0];
		while(c != '\0')
		{
			if(((int)c>=65 && (int)c<=90) || ((int)c>=97 && (int)c<=122) || (c == ' '))
			{
				c= input_txt[len];
				len++;
			}
			else{
				break;	
			}
		}
		return len-1;
	}
	
	int from_change_Length()
	{
		int len = 0;
		char c= from_change[0];
		while(c != '\0')
		{
			if(((int)c>=65 && (int)c<=90) || ((int)c>=97 && (int)c<=122) || (c == ' '))
			{
				c= from_change[len];
				len++;
			}
			else{
				break;	
			}
		}
		return len-1;
	}
	
	int to_change_Length()
	{
		int len = 0;
		char c= to_change[0];
		while(c != '\0')
		{
			if(((int)c>=65 && (int)c<=90) || ((int)c>=97 && (int)c<=122) || (c == ' '))
			{
				c= to_change[len];
				len++;
			}
			else{
				break;	
			}
		}
		return len-1;
	}
	
	int current_status_Length()
	{
		int len = 0;
		char c= current_status[len];
		while(c != '\0')
		{
			if(((int)c>=65 && (int)c<=90) || ((int)c>=97 && (int)c<=122) || (c == ' '))
			{
				c= current_status[len];
				len++;
			}
			else{
				break;	
			}
		}
		return len-1;
	}
	
	void Input()
	{
		printf("Input Text\n");
		gets(input_txt);
		printf("Input From Change\n");
		gets(from_change);
		printf("Input to Change\n");
		gets(to_change);
	}
	
	
	void Init_To_Print()
	{
		int i=0;
		while(i < input_txt_Length())
		{
			to_print[i] = input_txt[i];
			i++;
		}
	}
	
	void Init_input_txt()
	{
		int i=0;
		while(i < to_print_Length())
		{
			input_txt[i] = to_print[i];
			i++;
		}
	}
	
	void Empty_To_Print()
	{
		int i=0;
		while(i < to_print_Length())
		{
			to_print[i] = '\0';
			i++;
		}
	}
	
	void Matched()
	{
		current_status[0] = 'M';
		current_status[1] = 'a';
		current_status[2] = 't';
		current_status[3] = 'c';
		current_status[4] = 'h';
		current_status[5] = 'e';
		current_status[6] = 'd';
		current_status[7] = ' ';
		current_status[8] = ' ';
		current_status[9] = ' ';
		current_status[10] = ' ';
		sts = 1;
	}
	
	void Not_Matched()
	{
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
			sts = 0;
	}
	
	void Done()
	{
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
			sts = 0;
	}
	
		void END()
	{
			current_status[0] = 'E';
			current_status[1] = 'N';
			current_status[2] = 'D';
			current_status[3] = ' ';
			current_status[4] = ' ';
			current_status[5] = ' ';
			current_status[6] = ' ';
			current_status[7] = ' ';
			current_status[8] = ' ';
			current_status[9] = ' ';
			current_status[10] = ' ';
			sts = 3;
	}
	
	void Replaced()
	{
		current_status[0] = 'R';
		current_status[1] = 'e';
		current_status[2] = 'p';
		current_status[3] = 'l';
		current_status[4] = 'a';
		current_status[5] = 'c';
		current_status[6] = 'e';
		current_status[7] = 'd';
		current_status[8] = ' ';
		current_status[9] = ' ';
		current_status[10] = ' ';
		sts = 2;
	}
	
	void Matching()
	{
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
				return ;
			}
			i++;
			j++;
		}
		
		if(count == from_len)
		{
			Matched();
			sts = 1;
			
			int i =0;
			int j= 0;
			while(i<input_txt_Length())
			{
				if(i == pointer)
				{
					int k = 0;
					while(k<to_change_Length())
					{
						to_print[j] = to_change[k];
						j++;
						k++;
					}
					i = i + from_change_Length();
				}
				else{
					to_print[j] = input_txt[i];
					i++;
					j++;
				}
				
				if(i >= input_txt_Length() + to_change_Length() - from_change_Length())
				{
					to_print[j] = '\0';
				}
			}
			Init_input_txt();
			
			Replaced();
			
			Display();
			pointer = pointer + to_change_Length();
			Not_Matched();
		}
		else{
			Not_Matched();
			
		}
		
		
	}
	
	void Txt_Backup()
	{
		int i=0;
		while(i < input_txt_Length())
		{
			to_backup[i] = input_txt[i];
			i++;
		}
	}
	
	void Final_Show()
	{
		system("CLS");    
		printf("%s\n", to_backup);
		printf("%s\n", to_print);
	}
	
	int main()
	{
		Input();
		Init_To_Print();
		Txt_Backup();
		pointer = 0;
		while(pointer < input_txt_Length())
		{
			Matching();
			Display();
			pointer++;
		}
		
		END();
		Display();
		Final_Show();	
	}

