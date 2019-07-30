#include<stdio.h>
#include<stdlib.h>
///@brief This variable stores the number of nodes and hence the maximum size of the deque
int size=0;
///@brief This variable stores the number of entries in the deque
 int entries=0;
 /**@brief Contains the nodes of the linked list.
 * 
 * 
 * Contains Data for each node of the deque and a pointer for next node.
*  
**/
struct node
{
    int data;
    struct node *link;
}*frontmost,*rearmost;
/**@brief This function inserts a new node from front
*  
* @param No parameters
**/
void insertF()
{
    size++;
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data=-1;
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
/**@brief This function inserts a new node from rear
*  
* @param No parameters
**/
void insertR()
{
    size++;
  struct node *newnode = (struct node*) malloc(sizeof(struct node));
  newnode->data=-1;
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
/**@brief This function is used to delete a node from front
*  
* @param No parameters
*
* @return nothing
*/
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
        free(p);
    }
    else
    {
        size--;
        struct node *p=frontmost;
        frontmost=frontmost->link;
        free(p);
    }
}
/**@brief This function is used to delete a node from rear
*  
* @param No parameters
*
* @return nothing
*/
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
        free(p);
    }

    else
    {
        size--;
        struct node *p=frontmost;
        while((p->link)!=rearmost)
        {
            p=p->link;
        }
        rearmost=p;
        p=p->link;
        free(p);
        rearmost->link=NULL;
    }
}
/**@brief This function inserts a new element from front
*  
* @param data of element to be inserted
**/
void putF(int x)
{
    entries++;
    struct node *p=frontmost;
    if((p->link==NULL)&&(p->data==-1))
    {
        p->data=x;
        return;
    }
    while (((p->link)!=NULL))
    {
        if(((p->link)->data)!=-1)
        break;
        p=p->link;
    }
    p->data=x;
}
/**@brief This function inserts a new element from rear
*  
* @param data of element to be inserted
**/
void putR(int x)
{
    entries++;
    struct node *p=frontmost;
    if((p->link==NULL)&&(p->data==-1))
    {
        p->data=x;
        return;
    }
    while (((p->link)!=NULL))
    {
        if(((p->link)->data)!=-1)
        break;
        p=p->link;
    }
    if(p->link==NULL)
    {
        p->data=x;
        return;
    }
    p=p->link;
    while((p->data!=-1))
    {
        p=p->link;
    }
    p->data=x;
}
int main()
{
  struct node *p=frontmost;
  //int Maxsize=1;
  int choice;
  insertF();
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
            if(size==entries)
            {
                int l=size;
                while(l--)
                {
                    insertF();
                }
            }
            if(frontmost->data!=-1)
            {
                insertF();
                deleteR();
            }
            putF(x);
            printf("Inserted Successfully!\n");
            break;
        case 2:    
            printf("Enter Data\n");
            
            scanf("%d",&x);
           if(size==entries)
            {
                int l=size;
                while(l--)
                {
                    insertR();
                }
            }
            if(rearmost->data!=-1)
            {
                insertR();
                deleteF();
            }
            putR(x);
            printf("Inserted Successfully!\n");
            break;
        case 3: 
            p=frontmost;
            while (((p)!=NULL))
            {
                if((p)->data!=-1)
                break;
                p=p->link;
            }
            if(p==NULL)
            {
                printf("Cannot delete list is empty!\n");
                goto v;
            }
            if(p->data!=-1)
            {
                p->data=-1;
                entries--;
            }
            if(((float)entries==(float)size/2)&&(size%2==0))
            {
                int l=entries;
                while(l--)
                {
                    if(frontmost->data==-1)
                    {deleteF();}
                    if(rearmost->data==-1)
                    {deleteR();}
                }
            }
            
            else
            {
                printf("Deleted Successfully!\n");
            }
            v:
            break;
        case 4: 
            p=frontmost;
            while (((p)!=NULL))
            {
                if((p)->data!=-1)
                break;
                p=p->link;
            }
            if(p==NULL)
            {
                printf("Cannot delete list is empty!\n");
                goto u;
            }
            while((p->link)!=NULL)
            {
                if((p->link)->data==-1)
                break;
                p=p->link;
            }
            p->data=-1;
            entries--;
            if(entries==size/2)
            {
                int l=entries;
                while(l--)
                {
                    if(frontmost->data==-1)
                    {deleteF();}
                    else if(rearmost->data==-1)
                    {
                        deleteR();
                    }
                }
            }
            printf("Deleted Successfully!\n");
            u:
            break;
        case 5: 
            printf("Number of entries=%d\n",entries);
            break;
        case 6: 
            printf("Maximum Size=%d\n",size);
            break;
        case 7:
        	p=frontmost;
        	while(p!=rearmost)
        	{
        		printf("%d\t",p->data);
        		p=p->link;
			}
            printf("%d\t",p->data);
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

