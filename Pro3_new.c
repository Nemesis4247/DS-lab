#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>
#define bool _Bool
 #define STB_IMAGE_IMPLEMENTATION
 #include "stb_image.h"
 #define STB_IMAGE_WRITE_IMPLEMENTATION
 #include "stb_image_write.h"

int main()
{
    int width, height,channels;
    stbi_info("Q3_ip.jpg", &width, &height, &channels);
    printf("helo");
    int *red=(int*)malloc(4*width*height);
    int *green=(int*)malloc(4*width*height);
    int *blue=(int*)malloc(4*width*height);
    FILE *fp=fopen("Q3_ip_Red.dat","rb");
    if ( fp == NULL ) 
    { 
        printf( "File failed to open." ) ; 
        exit(0);
    } 
    char *buffer=(char*)malloc(width+1);
    strcpy(buffer,"start");
    int i=0;

    printf("%d\n",width);
    while(buffer!=NULL)
    {
        fgets(buffer,sizeof(buffer),fp);
        
        char *token=strtok(buffer,",");
        int i=0;
 
        while(token!=NULL)
        {
            red[i]=atoi(token);
            //printf("%s\n",token);
            token=strtok(NULL,",");
            i++;
        }
         printf("%d\n",i);
    }
    fclose(fp);
    printf("%d",red[0]);
}
