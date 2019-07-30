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
/** @brief This function sets the red value of a red shade pixel to be zero
 * 
 * @param arrays containing values of red, blue and green values of pixels, width and height of the image
 */
void remove_red(int *red[],int *green[],int *blue[],int width,int height)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            if((red[i][j]>green[i][j])&&(red[i][j]>blue[i][j]))
            {
                red[i][j]=0;
            }
        }
           
    }

}
/** @brief This function sets the green value of a green shade pixel to be zero
 * 
 * @param arrays containing values of red, blue and green values of pixels, width and height of the image
 */
void remove_green(int *red[],int *green[],int *blue[],int width,int height)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            if((green[i][j]>red[i][j])&&(green[i][j]>blue[i][j]))
            {
                green[i][j]=0;
            }
        }
           
    }

}
/** @brief This function sets the blue value of a blue shade pixel to be zero
 * 
 * @param arrays containing values of red, blue and green values of pixels, width and height of the image
 */
void remove_blue(int *red[],int *green[],int *blue[],int width,int height)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            if((blue[i][j]>green[i][j])&&(blue[i][j]>red[i][j]))
            {
                blue[i][j]=0;
            }
        }
           
    }

}
/** @brief This function sets the red and green value of a blue shade pixel to be zero
 * 
 * @param arrays containing values of red, blue and green values of pixels, width and height of the image
 */
void blue_only(int *red[],int *green[],int *blue[],int width,int height)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            if((blue[i][j]>green[i][j])&&(blue[i][j]>red[i][j]))
            {
                green[i][j]=0;
                red[i][j]=0;
            }
        }
           
    }
}
/** @brief This function sets the blue and green value of a red shade pixel to be zero
 * 
 * @param arrays containing values of red, blue and green values of pixels, width and height of the image
 */
void red_only(int *red[],int *green[],int *blue[],int width,int height)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            if((red[i][j]>green[i][j])&&(red[i][j]>blue[i][j]))
            {
                green[i][j]=0;
                blue[i][j]=0;
            }
        }
           
    }
}
/** @brief This function sets the red and blue value of a green shade pixel to be zero
 * 
 * @param arrays containing values of red, blue and green values of pixels, width and height of the image
 */
void green_only(int *red[],int *green[],int *blue[],int width,int height)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            if((green[i][j]>red[i][j])&&(green[i][j]>blue[i][j]))
            {
                blue[i][j]=0;
                red[i][j]=0;
            }
        }
           
    }
}
/** @brief This function is used to display the pixel value of the image at particular co-ordinates
 * 
 * @param arrays containing values of red, blue and green values of pixels, width and height of the image, x co-ordinate and y co-ordinate
 */
void pixelValue(int *red[],int *green[],int *blue[],int width,int height,int x,int y)
{
    if(x>height)
    {
        printf("Value of x is too large!\n");
        return;
    }
    if(y>width)
    {
        printf("Value of y is too large!\n");
        return;
    }
    printf("Red value of pixel=%d\n",red[x-1][y-1]);
    printf("Green value of pixel=%d\n",green[x-1][y-1]);
    printf("Blue value of pixel=%d\n",blue[x-1][y-1]);
}
int main()
{
    int width, height,channels;
    int x,y;
    stbi_info("Q3_ip.jpg", &width, &height, &channels);
    int *red[height];
    int *green[height];
    int *blue[height];
    for (int i=0; i<height; i++) 
    red[i] = (int *)malloc(width * sizeof(int));
    for (int i=0; i<height; i++) 
    green[i] = (int *)malloc(width * sizeof(int));
    for (int i=0; i<height; i++) 
    blue[i] = (int *)malloc(width * sizeof(int));
    FILE *fp=fopen("Q3_ip_Red.dat","rb");
    if ( fp == NULL ) 
    { 
        printf( "File failed to open." ) ; 
        exit(0);
    } 
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            fscanf(fp, "%d,", &red[i][j]);
        }
           fscanf(fp, "%d", &red[i][width-1]);
    }
    fclose(fp);
    fp=fopen("Q3_ip_Green.dat","rb");
    if ( fp == NULL ) 
    { 
        printf( "File failed to open." ) ; 
        exit(0);
    }
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            fscanf(fp, "%d,", &green[i][j]);
        }
           fscanf(fp, "%d", &green[i][width-1]);
    }
    fclose(fp);
    fp=fopen("Q3_ip_Blue.dat","rb");
    if ( fp == NULL ) 
    { 
        printf( "File failed to open." ) ; 
        exit(0);
    }
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            fscanf(fp, "%d,", &blue[i][j]);
        }
           fscanf(fp, "%d", &blue[i][width-1]);
    }
    red_only(red,green,blue,width,height);
    int choice;
    while(1)
    {
        printf("Enter your choice\n");
        printf("1 : Enter co-ordinates\n");
        printf("2 : Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter x co-ordinate:\n");
                scanf("%d",&x);
                printf("Enter y co-ordinate:\n");
                scanf("%d",&y);
                pixelValue(red,green,blue,width,height,x,y);
                break;
            case 2:
                exit(0);
        }
    }
    
}
