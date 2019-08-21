#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
/**@brief text from inputfile and decrypted file is copied into strings and then compared whether they are same or not.
 */
int main()
{
    char *text_in=(char*)malloc(1000);
    char *buffer=(char*)malloc(1000);
    char *text_decrypt=(char*)malloc(1000);
    FILE *fp=fopen("inputfile.txt","r");
    if ( fp == NULL ) 
    { 
        printf( "file failed to open.\n" ) ; 
        return 10;
    }
    fgets (buffer, 1000, fp );
    strcpy(text_in,buffer);
    while( fgets (buffer, 1000, fp ) != NULL ) 
    {
        strcat(text_in,buffer);
    }
    fclose(fp);
    fp=fopen("decryptedOutput.txt","r");
    if ( fp == NULL ) 
    { 
        printf( "file failed to open.\n" ) ;
        return 10; 
    }
    fgets (buffer, 1000, fp );
    strcpy(text_decrypt,buffer);
    while( fgets (buffer, 1000, fp ) != NULL ) 
    {
        strcat(text_decrypt,buffer);
    }
    if(strcmp(text_decrypt,text_in)==0)
    {
        printf("Both the texts are same\n");
    }
    else
    {
        printf("Texts are different\n");
    }
    
}