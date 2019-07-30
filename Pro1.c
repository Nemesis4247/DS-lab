#include <stdio.h>
#include<string.h>
#include <conio.h>
#include<stdlib.h>
#include<stdbool.h>
#define bool _Bool
/**@brief Contains the nodes of doubly circular linked list.
 * 
 * 
 * Contains roll no, name, date of birth, address and phone number for each student
*  
**/
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
/**@brief This function inserts a new node and hence the record of a new student in the system
*  
* @param Student name, Date of birth, address and phone number
**/
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
            struct node *p=first;
            int roll =first_element();
            if(((first->roll_no)<roll)&&(((first->left)->roll_no)>roll))
            {
                while(((p->roll_no)>roll)||(((p->right)->roll_no)<roll))
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
/**@brief Swaps the entire data of two nodes
*  
* @param Two pointer objects of node.
**/
void swap_data(struct node *p,struct node *q)
{
    int temp=p->roll_no;
    p->roll_no=q->roll_no;
    q->roll_no=temp;
    long long int temp1=p->phone;
    p->phone=q->phone;
    q->phone=temp1;
    char temp2[50];
    strcpy(temp2,p->name);
    strcpy(p->name,q->name);
    strcpy(q->name,temp2);
    char temp3[50];
    strcpy(temp3,p->DOB);
    strcpy(p->DOB,q->DOB);
    strcpy(q->DOB,temp3);
    char temp4[50];
    strcpy(temp4,p->address);
    strcpy(p->address,q->address);
    strcpy(q->address,temp4);
}
///@brief This function sorts the list in lexicographical order as per student names.
void sort_name()
{
    for(struct node *p=first;p->right!=first;p=p->right)
    {
        for(struct node *q=p->right;q!=first;q=q->right)
        {
            if(strcmp(p->name,q->name)>0)
            {
                swap_data(p,q);
            }
        }
    }
    printf("Sorted successfully!\n");
}

///@brief This function is used to display the data of all students enrolled
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
/**@brief This is function is used to modify the data of a particular student
*  
* @param Student roll no, Student name, Date of birth, address and phone number
*
* @return nothing
*/
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
/**@brief This function is used to delete the record of a particular student.
*  
* @param Student roll no
*
* @return nothing
*/

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

/** @brief This function is used to search the name of a particular student enrolled in the system
 * 
 * @param Student name
 * 
 * @return nothing
 */
void Search(char name1[50])
{
    struct node *p=first;
    int count=0;
    name1[strlen(name1)-1]='\0';
    if(first==NULL)
    {
         printf("Roll no not found\n");
         return;
    }
    if(strcmp(p->name,name1)==0)
    {
        printf("Roll no=%d\n",p->roll_no);
        printf("Name=%s\n",p->name);
        printf("Date of birth=%s\n",p->DOB);
        printf("\n\n");
        count++;
    }
    

    p=p->right;
    while (p!=first)
    {
        if(strcmp(p->name,name1)==0)
        {
            printf("Roll no=%d\n",p->roll_no);
            printf("Name=%s\n",p->name);
            printf("Date of birth=%s\n",p->DOB);
            printf("\n\n");
            count++;
            
        }
        p=p->right;
    }
    if(count==0)
    {
        printf("Roll no not found\n");
    }
    
}

int main()
{
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
        printf("4 : Sort student data\n");
        printf("5 : Search for a student\n");
        printf("6 : Print the list of enrolled students\n");
        printf("7 : Exit program\n");
    
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
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
            strcpy(name,(token));
            token=strtok(NULL,",");
            strcpy(DOB,token);
            token=strtok(NULL,"\"");
            strcpy(address,token);
            token=strtok(NULL,",");
            phone=atoll(token);
            if(name[strlen(name)-1]==' ')
            name[strlen(name)-1]='\0';
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
        case 4:
            sort_name();
            break;
        case 5:
            printf("Enter Name you want to search:\n");
            //scanf("%s",&name);
            getchar();
            fgets(name, 50, stdin); 
            
            //strcat(name," ");
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

/** @brief This function is used to insert the deleted roll no in the queue.
 * 
 * @param Student roll no
 */
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
/** @brief This function deletes roll no at first position
 */
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
/**@brief This function checks whether queue is empty or not
* 
* @return boolean value true or false
*/
bool isempty_queue()
{
    if((front==-1)||(front>rear))
    return 1;
    return 0;
}
/**@brief This function returns the deleted roll no stored at first position in the queue. 
* 
* @return integer value of first element
*/
int first_element()
{
    return queue_array[front];
}
