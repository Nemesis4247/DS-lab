#include <stdio.h>
#include<string.h>
#include <conio.h>
#include<stdlib.h>
#include<stdbool.h>
#define bool _Bool

struct node
{
    int roll_no;
    char name[50];
    char DOB[50];
    char address[100];
    long long int phone;
    struct node *left;
    struct node *right;
}*first;
#define MAX 50
 
void insert_queue();
void pop();
int first_element();
bool isempty_queue();
int queue_array[MAX];
int rear = - 1;
int front = - 1;

void insert(char name1[50],char DOB1[50], char address1[100], long long int phone1)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->left=NULL;
    newnode->right=NULL;
    strncpy(newnode->name,name1,50);
    strncpy(newnode->address,address1,100);
    strncpy(newnode->DOB,DOB1,50);
    newnode->phone=phone1;
    if(isempty_queue())
    {
        if(first==NULL)
        {
            first=newnode;
            first->left=first;
            first->right=first;
            first->roll_no=101;
        }
        else
        {
            newnode->left=first->left;
            newnode->right=first;
            (first->left)->right=newnode;
            first->left=newnode;
            newnode->roll_no=(newnode->left)->roll_no+1;
        }
    }
    else
    {
        if(first==NULL)
        {
            first=newnode;
            first->left=first;
            first->right=first;
            first->roll_no=first_element();
            pop();
        }
        else
        {
           /* newnode->left=first->left;
            newnode->right=first;
            (first->left)->right=newnode;
            first->left=newnode;
            newnode->roll_no=first_element();
            pop();*/
            struct node *p=first;
            int roll =first_element();
            if(((first->roll_no)<roll)&&(((first->left)->roll_no)>roll))
            {
                while(((p->roll_no)<roll)&&(((p->right)->roll_no)>roll))
                {
                    p=p->right;
                }
            }
            else
            {
                p=p->left;
            }
            
            newnode->right=p->right;
            (p->right)->left=newnode;
            p->right=newnode;
            newnode->left=p;
            newnode->roll_no=roll;
            if((first->roll_no)>roll)
            first=newnode;
            pop();
        }
    }
    
}
/*
void swap1(char **str1_ptr, char **str2_ptr) 
{ 
  char *temp = *str1_ptr; 
  *str1_ptr = *str2_ptr; 
  *str2_ptr = temp; 
} 
void swap_data(struct node *p,struct node *q)
{
    int temp=p->roll_no;
    p->roll_no=q->roll_no;
    q->roll_no=temp;
    long int temp1=p->phone;
    p->phone=q->phone;
    q->phone=temp1;
    swap1(&(p->name),&(q->name));
    swap1(&(p->address),&(q->address));
    swap1(&(p->DOB),&(q->DOB));
}
void sort_name()
{
    for(struct node *p=first;p!=NULL;p=p->right)
    {
        struct node *top=p;
        for(struct node *q=p->right;q!=NULL;q=q->right)
        {
            if(strcmp(top->name,q->name)>0)
            {
                swap_data(top,q);
            }
        }
    }
}
*/
void print()
{
    struct node *p=first;
    printf("roll no=%d\n",p->roll_no);
    printf("Name=%s\n",p->name);
    printf("Date of birth=%s\n",p->DOB);
    printf("Address=%s\n",p->address);
    printf("Phone number=%lld\n",p->phone);
    printf("\n\n");
    p=p->right;
    while(p!=first)
    {
        printf("roll no=%d\n",p->roll_no);
        printf("Name=%s\n",p->name);
        printf("Date of birth=%s\n",p->DOB);
        printf("Address=%s\n",p->address);
        printf("Phone number=%lld\n",p->phone);
        printf("\n\n");
        p=p->right;
    }
}

void modify(int roll,char name1[50],char DOB1[50], char address1[100], long long int phone1)
{
    struct node *p=first;
    if(p->roll_no==roll)
    {
        strncpy(p->name,name1,50);
        strncpy(p->address,address1,100);
        strncpy(p->DOB,DOB1,50);
        p->phone=phone1;
    }
     else
    {
    	p=p->right;
        while ((p->roll_no!=roll)&&(p!=first))
        {
            p=p->right;
        }
        if(p==first)
        {
            printf("Error! Roll no not found");
        }
        else
        {
            {
                strncpy(p->name,name1,50);
                strncpy(p->address,address1,100);
                strncpy(p->DOB,DOB1,50);
                p->phone=phone1; 
            }
        }
        
    }

}

void delete(int roll)
{
    struct node *p=first;
    if(first==NULL)
    {
        printf("Cannot delete, List is empty!\n");
        return;
    }
    if(p->roll_no==roll)
    {
        (p->left)->right=p->right;
        (p->right)->left=p->left;
        first=p->right;
        free(p);
        insert_queue(roll);
    }
    else
    {
    	p=p->right;
        while ((p->roll_no!=roll)&&(p!=first))
        {
            p=p->right;
        }
        if(p==first)
        {
            printf("Roll no not found\n");
        }
        else
        {
            {
                 (p->left)->right=p->right;
                 (p->right)->left=p->left;
                 free(p);
                 insert_queue(roll);
            }
        }
        
    }
    
}

void Search(char name1[50])
{
    struct node *p=first;
    if(strcmp(p->name,name1)==0)
    {
        printf("Roll no=%d\n",p->roll_no);
        printf("Name=%s\n",p->name);
        printf("Date of birth=%s\n",p->DOB);
        printf("\n\n");
        return;
    }
    else
    {
        p=p->right;
         while (strcmp(p->name,name1)&&(p!=first))
         {
             p=p->right;
         }
         if(p==first)
        {
            printf("Roll no not found\n");
        }
        else
        {
            printf("Roll no=%d\n",p->roll_no);
            printf("Name=%s\n",p->name);
            printf("Date of birth=%s\n",p->DOB);
            printf("\n\n");
            return;
        }
        
    }
    
}

int main()
{
    /*delete(108);
    insert("Ishan","10-03-2001","anpara",9027259122);
    
    insert("Ashi","01-03-2009","anpara",9027259199);
    insert("hemant","01-03-2000","anpara",9027259198);
    insert("hemil","01-03-1999","anpara",9027259197);
    
     delete(102);
    delete(101);
   // print();
    insert("Pandey","10-03-2001","anpara",9027259123);
    insert("Ashish","01-03-2000","anpara",9027259099);
    insert("Anmol","01-03-2000","anpara",9027259196);
    //print();
    modify(103,"karan","sksm","kjnkjn",023023020323);
    print();*/
    FILE *fp;
    char buffer[1024];
    char name[50],DOB[50],address[100];
    long long int phone;
    int choice;
    int row;
     int roll;
    while(1)
    {
        printf("Enter the choice:-\n");
        printf("1 : Insert student data\n");
        printf("2 : Delete student data\n");
        printf("3 : Modify student data\n");
        //printf("4 : Sort student data\n");
        printf("5 : Search for a student\n");
        printf("6 : Print the list of enrolled students\n");
        printf("7 : Exit program\n");
    
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            // FILE *fp;
            //char buffer[1024];
            fp=fopen("studentData.csv","r");
            fgets(buffer,sizeof(buffer),fp);
            printf("Enter row number:\n");
            scanf("%d",&row);
            if(row==1)
            {
                printf("There is nothing in row no. 1\n");
                break;
            }
            for(int i=2;i<row;i++)
            {
                fgets(buffer,sizeof(buffer),fp);
            }
            fgets(buffer,sizeof(buffer),fp);
            if(buffer=="")
            {
                printf("Row not found\n");
                break;
            }
            char *token=strtok(buffer,",");
            token=strtok(NULL,",");
            strcpy(name,token);
            token=strtok(NULL,",");
            strcpy(DOB,token);
            token=strtok(NULL,"\"");
            //token=strtok(NULL,"\"");
            strcpy(address,token);
            //token=strtok(NULL,",");
            token=strtok(NULL,",");
            phone=atoll(token);
            insert(name,DOB,address,phone);
            fclose(fp);
            break;
        case 2:
            printf("Enter roll no which you want to delete\n");
            scanf("%d",&roll);
            delete(roll);
            break;
        case 3:
            printf("Enter roll no of student whose data you want to modify\n");
            scanf("%d",&roll);
            printf("Enter name\n");
            scanf("%s",&name);
            printf("Enter Date of birth\n");
            scanf("%s",&DOB);
            printf("Enter Address \n");
            scanf("%s",&address);
            modify(roll,name,DOB,address,phone);
        case 5:
            printf("Enter Name you want to search:\n");
            scanf("%s",&name);
            Search(name);
            break;
        case 6:
            print();
            break;
        case 7:
            exit(0);
        default:
            printf("Wrong input\n");
            break;

    }
    }
}


void insert_queue(int roll)
{
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == -1)
        front = 0;
        rear = rear + 1;
        queue_array[rear] =roll;
    }
}
 
void pop()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        front = front + 1;
    }
}
bool isempty_queue()
{
    if((front==-1)||(front>rear))
    return 1;
    return 0;
}
int first_element()
{
    return queue_array[front];
}
