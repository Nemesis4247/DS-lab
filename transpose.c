#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
/**@brief This function encrypts the text stored in a string
 * @param text, start index, a, b and n
 * @return void
 */
void transpose(char *text,int start,int a,int b,int n)
{
    char trans_text[n];
    for(int i=0;i<n;i++)
    {
        int j=(a*i+b)%(n);
        trans_text[i]=text[start+j];
    }
    for(int i=0;i<n;i++)
    text[i+start]=trans_text[i];
}
/**@brief In this function we store the text from file and encrypt it using transpose function
 * @param It takes 4 arguments from commandline namely n ,a, b and file name in which text is stored 
 */
int main(int argc,char *argv[])
{
    char *text=(char*)malloc(1000);
    char *buffer=(char*)malloc(1000);
    FILE *fp=fopen(argv[4],"r");
    if ( fp == NULL ) 
    { 
        printf( "file failed to open.\n" ) ; 
        return 10;  
    }
    fgets (buffer, 1000, fp );
    strcpy(text,buffer);
    while( fgets (buffer, 1000, fp ) != NULL ) 
    {
        strcat(text,buffer);
    }
    printf("%s\n",text);
    fclose(fp);
    printf("%d\n%d\n",(int)text[15],(int)text[16]);
    int l=strlen(text);
    int n=atoi(argv[1]);
    int a=atoi(argv[2]);
    int b=atoi(argv[3]);
    if(n<1)
    {
        printf("The vale of n should be atleast one\n");
        return 10;
    }
    if(a<0)
    a=n+a;
    if(b<0)
    b+=n;
    int end=l-l%n;
    for(int i=0;i<end;i+=n)
    {
        transpose(text,i,a,b,n);
    }

    for(int i=l;i<end+n;i++)
    {
        text[i]='*';
    }
    transpose(text, end,a,b,n);
    
    fp=fopen("outputfile.txt","w");
    if ( fp == NULL ) 
    { 
        printf( "file failed to open.\n" ) ; 
    }
    fputs(text,fp);
    fclose(fp);
}