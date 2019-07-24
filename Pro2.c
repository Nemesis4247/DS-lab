#include<stdio.h>
#include<stdlib.h>
int size=0;
struct node
{
    int data;
    struct node *link;
}*frontmost,*rearmost;
void insertF(int x)
{
    size++;
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=NULL;
    if(frontmost==NULL)
    {
        frontmost=newnode;
        rearmost=newnode;
        rearmost->link==NULL;
    }
    else
    {
        newnode->link=frontmost;
        frontmost=newnode;
    }
}
void insertR(int x)
{
    size++;
  struct node *newnode = (struct node*) malloc(sizeof(struct node));;
  newnode->data=x;
  newnode->link=NULL;
  if(frontmost==NULL)
  {
      frontmost=newnode;
      rearmost=newnode;
      rearmost->link==NULL;
  }
  else
  {
      rearmost->link=newnode;
      rearmost=newnode;
      rearmost->link==NULL;
  }
}
void deleteF()
{
    if(frontmost==NULL)
    {
        printf("Cannot delete.Deque is empty!\n");
    }
    else if((frontmost->link)==NULL)
    {
        size--;
        struct node *p=frontmost;
        frontmost=NULL;
        rearmost=NULL;
        //delete p;
    }
    else
    {
        size--;
        struct node *p=frontmost;
        frontmost=frontmost->link;
       // delete p;
    }
}
void deleteR()
{
    if(frontmost==NULL)
    {
        printf("Cannot delete.Deque is empty!\n");
    }
    else if((frontmost->link)==NULL)
    {
        size--;
        struct node *p=frontmost;
        frontmost=NULL;
        rearmost=NULL;
        //delete p;
    }
    else
    {
        size--;
        struct node *p1=rearmost;
        struct node *p=frontmost;
        while((p->link)!=rearmost)
        {
            p=p->link;
        }
        rearmost=p;
        //delete p1;
    }
}
int main()
{
  struct node *p;
  int Maxsize=1;
  //int size=0;
  int choice;
  int x;
  while(1)
    {
        printf("enter the choice \n");
        printf("1 : Insert element from front\n2 : Insert element from rear\n");
        printf("3 : Delete an element from front\n4 : Delete an element from rear\n");
        printf("5. Check number of entries in the Deque\n");
        printf("6. Check Maximum size of the Deque\n");
        printf("7. View entries of the Deque\n");
        printf("8. Exit\n");
        scanf("%d", &choice);
        switch (choice)    
        {
        case 1: 
            printf("Enter Data\n");
            scanf("%d",&x);
            if(size==Maxsize)
            {
                Maxsize=2*Maxsize;
            }
            insertF(x);
            break;
        case 2:    
            printf("Enter Data\n");
            
            scanf("%d",&x);
            if(size==Maxsize)
            {
                Maxsize=2*Maxsize;
              }
              insertR(x);
              break;
        case 3: 
            deleteF();
            if(((float)size==(float)Maxsize/2)&&(Maxsize%2==0))
            {
                Maxsize=Maxsize/2;
            }
            break;
        case 4: 
            deleteR(frontmost,rearmost,&size);
            if(((float)size==(float)Maxsize/2)&&(Maxsize%2==0))
            {
                Maxsize=Maxsize/2;
            }
            break;
        case 5: 
            printf("Number of entries=%d\n",size);
            break;
        case 6: 
            printf("Maximum Size=%d\n",Maxsize);
            break;
        case 7:
        	p=frontmost;
        	while(p!=NULL)
        	{
        		printf("%d\t",p->data);
        		p=p->link;
			}
			printf("\n");
			break;
        case 8: 
            exit(0);
        default: 
            printf("wrong choice\n");
            break;
        }
    }

}

