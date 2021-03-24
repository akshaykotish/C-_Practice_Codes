#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
char *output;
int length;
int Error_Find = 0;
void Set_Output(char e[], int len)
{
	output = malloc(len +1);
	output = e;
	length = len;
}


char brackets[100];
int top = 0;
int ind = 0;

int x = 0;
int y = 0;


void Add_Bracket_in_Stack(char bracket)
{
	brackets[top] = bracket;
	top++;
}

void Display(char c[])
{
	int i=0;
	while(c[i] != NULL)
	{    
		  printf("[0m");
		if(c[i] == '(' || c[i] == ')' || c[i] == '[' || c[i] == ']')
		{
			printf("\e[43m");
			printf("%c", c[i]);
		}
		else if(c[i] == '<' || c[i] == '>')
		{
			printf("\e[41m	");
			printf("%c", c[i]);
		}
		
		else if(c[i] == '{' || c[i] == '}')
		{
			printf("\e[44m");
			printf("%c", c[i]);
		}
		
		else if(i >= x || i <= y)
		{
			printf("\e[41m");
			printf("%c", c[i]);
		}
		else{
			printf("\e[40m");
			printf("%c", c[i]);
		}
		  printf("[0m");
		  
		  printf("\e[0m	");
		  
		  
		  

		i++;
	}
}

void Error(int chng, char c, char msg[])
{
	Error_Find = 1;
	
	char *temp = malloc(length + 150);
	
	int m=0;
	while(m < length+150)
	{
		temp[m] = ' ';
		m++;
	}
	
	int spaces = 0;
	int to_add = 0;
	
	int i=0;
	int j=0;
	while(i < length)
	{	
		
	
		temp[j] = output[i];
		
	
		
		if(i < chng)
		{
			spaces++;
		}
		
		if(temp[j] == '\n' && i < chng)
		{
			spaces = 0;
		}
		
		if(i==chng)
		{
			to_add = 1;
		}
		
		if(temp[j] == '\n' && to_add==1)
		{
			to_add = 0;
			
			int k=0;
			while(k<spaces)
			{
				j++;
				temp[j] = ' ';
				k++;
			}
			j++;
			temp[j] = '^';
			j++;
			temp[j] = '\n';	
			k = 0;
			while(k<spaces)
			{
				j++;
				temp[j] = ' ';
				k++;
			}
			j++;
			x = j;
			temp[j] = (char)(39);
			j++;
			temp[j] = c;
			j++;
			temp[j] = (char)(39);
			j++;
			temp[j] = ' ';
			k = 0;
			while(msg[k] != NULL)
			{
				j++;
				temp[j] = msg[k];
				k++;
			}
			j++;
			y = j;
			temp[j] = '\n';
		}
		
		i++;
		j++;
	}
	Display(temp);
}

void Remove_Bracket_in_Stack(char bracket)
{
	if(top != 0)
	{
		if(bracket == '>' && brackets[top-1]=='<')
		{
			brackets[top-1] = ' ';
			top--;
		}
		else if(bracket == ')' && brackets[top-1]=='(')
		{
			
			brackets[top-1] = ' ';
			top--;
		}
		else if(bracket == ']' && brackets[top-1]=='[')
		{
			
			brackets[top-1] = ' ';
			top--;
		}
		else if(bracket == '}' && brackets[top-1]=='{')
		{
			
			brackets[top-1] = ' ';
			top--;
		}
		else
		{
			if(brackets[top-1] == '(')
			{
				Error(ind, ')', "expected");
			}
			else if(brackets[top-1] == '[')
			{
				Error(ind, ']', "expected");
			}
			else if(brackets[top-1] == '{')
			{
				Error(ind, '}', "expected");
			}
			else if(brackets[top-1] == '<')
			{
				Error(ind, '>', "expected");
			}
		}
	}
	else{
			if(bracket == ')')
			{
				Error(ind, '(', "expected before this");
			}
			else if(bracket == ']')
			{
				Error(ind, '[', "expected before this");
			}
			else if(bracket == '}')
			{
				Error(ind, '{', "expected before this");
			}
			else if(bracket == '>')
			{
				Error(ind, '<', "expected before this");
			}
	}
}

void Check_Bracket()
{
	if(output[ind] == '<' || output[ind] == '{' || output[ind] == '(' || output[ind] == '[') 
	{
		char c = (char)output[ind];
		Add_Bracket_in_Stack(c);
	}
	else if(output[ind] == '>' || output[ind] == '}' || output[ind] == ')' || output[ind] == ']') 
	{
		char c = (char)output[ind];
		Remove_Bracket_in_Stack(c);
	}
}

void Final_Check()
{
		
		ind=ind-1;
	if(top > 0)
	{
		char c= brackets[top-1];
		
			if(brackets[top-1] == '(')
			{
				Error(ind, ')', "expected before End of Code");
			}
			else if(brackets[top-1] == '[')
			{
				Error(ind, ']', "expected before End of Code");
			}
			else if(brackets[top-1] == '{')
			{
				Error(ind, '}', "expected before End of Code");
			}
			else if(brackets[top-1] == '<')
			{
				Error(ind, '>', "expected before End of Code");
			}
		
	}
	else{
		Error(ind, ' ', "All Good");
	}
}

void Handle_Text()
{
	while(output[ind] != NULL)
	{
		if(Error_Find == 0)
		{
			Check_Bracket();
			ind++;
		}
		else{
			break;
		}
	}
	Final_Check();
} 

int main()
{
	Set_Output("#include<stdio.h>\nint main()\n{\nprintf{'hello world'};\nreturn 0;\n", 200);
	Handle_Text();
}
