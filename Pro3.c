#include <stdio.h>
#include <stdlib.h>
  
 #define STB_IMAGE_IMPLEMENTATION
 #include "stb_image.h"
 #define STB_IMAGE_WRITE_IMPLEMENTATION
 #include "stb_image_write.h"


void ColorOnly(unsigned char *img,int width,int height,int channels,int color)
{
	int color1,color2;
		if(color==0)
	{
		color1=1;
		color2=2;
	}
	else if(color==1)
	{
		color1=0;
		color2=2;
	}
	else
	{
		color1=0;
		color2=1;
	}
	
	size_t img_size = width * height * channels;
	int color_channels =channels;
	
	unsigned char *color_img = malloc(img_size);
	if(color_img == NULL)
	{
		printf("Unable to allocate memory for the new image.\n");
		exit(1);
	}
	color_img=img;
	for(unsigned char *p = img, *pr = color_img; p != img + img_size; p += channels, pr += color_channels)
	{
		if(((int)*(p+color))>((int)*(p+color1))&&(((int)*(p+color))>((int)*(p+color2))))
		{
			*(pr+color1)='0';
			*(pr+color2)='0';
		}
		if(channels == 4)
		{
			*(pr + 3) = *(p + 3);
		}

		
	}
	stbi_write_jpg("Q3_new1.jpg", width, height, color_channels,color_img, 100);
}


void RemoveColor(unsigned char *img,int width,int height,int channels,int color)
{
	int color1,color2;
		if(color==0)
	{
		color1=1;
		color2=2;
	}
	else if(color==1)
	{
		color1=0;
		color2=2;
	}
	else
	{
		color1=0;
		color2=1;
	}
	
	size_t img_size = width * height * channels;
	int color_channels =channels;
	//size_t color_img_size = width * height * color_channels;
	
	unsigned char *color_img = malloc(img_size);
	if(color_img == NULL)
	{
		printf("Unable to allocate memory for the new image.\n");
		exit(1);
	}
	color_img=img;
	for(unsigned char *p = img, *pr = color_img; p != img + img_size; p += channels, pr += color_channels)
	{
		if(((int)*(p+color))>((int)*(p+color1))&&(((int)*(p+color))>((int)*(p+color2))))
		{
			*(pr+color)='0';
		}
		if(channels == 4)
		{
			*(pr + 3) = *(p + 3);
		}

		
	}
	stbi_write_jpg("Q3_new2.jpg", width, height, color_channels,color_img, 100);
}

int main()
{
	int width, height, channels;
	unsigned char *img = stbi_load("Q3_ip.jpg", &width, &height, &channels, 0);
	if(img == NULL) 
	{
		 printf("Error in loading the image\n");
		 exit(1);
	}
//gcc t0.c -o t0
	//ColorOnly(img,width,height,channels,1);	
	RemoveColor(img,width,height,channels,1);	
	
}
