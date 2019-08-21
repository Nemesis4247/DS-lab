#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
/**@brief This function decrypts the text stored in a string if it is provided with 'a' and 'b' inverse
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
/**@brief In this function we store the text from encrypted file and decrypt it using transpose function
 * @aparam It takes 3 arguments from commandline namely n ,a and b
 */
int main(int argc,char *argv[])
{
    char *text=(char*)malloc(1000);
    char *buffer=(char*)malloc(1000);
    FILE *fp=fopen("outputfile.txt","r");
    if ( fp == NULL ) 
    { 
        printf( "Output file failed to open.\n" ) ; 
    }
    fgets (buffer, 1000, fp );
    strcpy(text,buffer);
    while( fgets (buffer, 1000, fp ) != NULL ) 
    {
        strcat(text,buffer);
    }
    printf("%s\n",text);
    fclose(fp);
    int l=strlen(text);
    int n=atoi(argv[1]);
    int a1=atoi(argv[2]);
    int b1=atoi(argv[3]);
    if(a1<0)
    a1=n+a1;
    if(b1<0)
    b1+=n;
    int a;
    int q=1;
    while ((q*n+1)%a1!=0)
    {
        q++;
    }
    a=(q*n+1)/a1;
    q=1;
    printf("%d\n",a);

    while((q*n-b1*a)<=0)
    {
        q++;
    }
    int b=q*n-b1*a;
    printf("%d\n",b);
    int end=l-l%n;
    for(int i=0;i<end;i+=n)
    {
        transpose(text,i,a,b,n);
    }

    for(int i=l;i<end+n;i++)
    {
        text[i]='*';
    }
    long long int l1=strlen(text);
    text[l1]='\0';
    transpose(text, end,a,b,n);
    fp=fopen("decryptedOutput.txt","w");
    if ( fp == NULL ) 
    { 
        printf( "decryptedOutput file failed to open.\n" ) ; 
    }
    for(int i=0;i<end+n;i++)
    {
        if(text[i]=='*')
        text[i]='\0';
    }
    fputs(text,fp);
    fclose(fp);
}