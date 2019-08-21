#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int value=1;
/**@brief This structure stores nodes of the quad tree 
 */
struct node
{
    int label;
    int bit;
    int lev;
    int isleaf;
    struct node *p1;
    struct node *p2;
    struct node *p3;
    struct node *p4;
}*first;
/**@brief This function takes in the array of region breaks it into quadrants and recursively calls itself until it finds all ones or all zeroes
 * @param array of region, array of labels, starting and ending index of rows and columns and a pointer of a node of quad tree
 */
void divide(int **region,int **label,int startx,int endx,int starty,int endy,int level,struct node *p)
{
    
    int flag=1;
    int val=region[startx][starty];
    for(int i=startx;i<=endx;i++)
    {
        for(int j=starty;j<=endy;j++)
        {
            if(region[i][j]!=val)
            {
                flag=0;
                break;
            }
        }
    }
    if(flag==0)
    {
        p->isleaf=0;
        int quad=(endx-startx+1)/2;
        p->p1=(struct node*)malloc(sizeof(struct node));
        p->p2=(struct node*)malloc(sizeof(struct node));
        p->p3=(struct node*)malloc(sizeof(struct node));
        p->p4=(struct node*)malloc(sizeof(struct node));
        divide(region,label,startx,startx+quad-1,starty,starty+quad-1,level+1,p->p1);
        divide(region,label,startx,startx+quad-1,starty+quad,endy,level+1,p->p2);
        divide(region,label,startx+quad,endx,starty,starty+quad-1,level+1,p->p3);
        divide(region,label,startx+quad,endx,starty+quad,endy,level+1,p->p4);
    }
    if(flag==1)
    {
        p->isleaf=1;
       for(int i=startx;i<=endx;i++)
        {
            for(int j=starty;j<=endy;j++)
            {
                label[i][j]=value;
            }
        }
        p->label=value;
        p->bit=val;
        p->lev=level; 
        value++;
        return;
    }
}
/**@brief This function is used to print the tree in post order
 * @param Pointer of node of the quad tree
 */
void postorder(struct node *p)
{
    if(p->isleaf==1)
    {
        printf("(%d,%d,%d) ",p->label,p->bit,p->lev);
    }
    else
    {
        postorder(p->p1);
        postorder(p->p2);
        postorder(p->p3);
        postorder(p->p4);
    }
    
}
/**@brief This function reads input file to get region array and calls the recursive divide function.
 */
int main()
{
    int *region[1024];
    first=(struct node*)malloc(sizeof(struct node));
    for (int i=0; i<1024; i++) 
    region[i] = (int *)malloc(1024 * sizeof(int));
    FILE *fp=fopen("input.txt","r");
    char *buffer=(char*)malloc(1024);
    int index1=0;
    while( fgets (buffer, 1000, fp ) != NULL )
    {
        char *token=strtok(buffer," ");
        int index2=0;
        region[index1][index2]=atoi(token);
        index2++;
        while(token!=NULL)
        {
            token=strtok(NULL," ");
            region[index1][index2]=atoi(token);
            index2++;
        }
        index1++;
    }
    
    int n=(int)pow(2,(int)(log((float)index1)/log(2.00))+1);
    n=n-index1;

    for(int i=index1;i>=0;i--)
    {
        for(int j=index1;j>=0;j--)
        {
            region[i][j+n]=region[i][j];
        }
    }
    
    for(int i=index1+n;i>=0;i--)
    {
        for(int j=index1+n;j>=0;j--)
        {
            region[i+n][j]=region[i][j];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+index1;j++)
        {
            region[i][j]=0;
        }
    }
    for(int i=0;i<n+index1;i++)
    {
        for(int j=0;j<n;j++)
        {
            region[i][j]=0;
        }
    }
    int len=index1+n;
    int *label[len];
    for (int i=0; i<len; i++) 
    label[i] = (int *)malloc(len * sizeof(int));
    divide(region,label,0,len-1,0,len-1,0,first);
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            printf("%d ",label[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    postorder(first);
}