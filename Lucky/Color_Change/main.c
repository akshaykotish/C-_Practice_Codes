#include"color.h"
#include<stdio.h>
#include<conio.h>
int main(int argc, char* argv[])
{
	if(argc != 0)
	{
		FILE *fp ;
         char data[1000] ;
         fp = fopen(argv[1], "r" ) ;
         if ( fp == NULL )
         {
                 printf( "Could not open file test.c" ) ;
                 return 1;
         }
         //while( fgets ( data, 1000, fp ) != NULL );
         
         int j=0;
         char ch[200];
         while(!feof(fp))
         {
             fgets(ch, 200, fp);
             int k= 0;
             while(ch[k] != NULL)
             {
                 data[j] = (char)ch[k];
                 k++;
                 j++;
             }
         }
         fclose(fp);
         Set_Output(data, j);
         Handle_Text();
	}
	return 0;
}
