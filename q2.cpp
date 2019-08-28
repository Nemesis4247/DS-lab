/**
 * @file q2.cpp
 * @author Ishan Pandey
 * @brief Solution of problem 2 of L3
 * @version 0.1
 * @date 2019-08-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string>
using namespace std;
/**
 * @brief This class represents the nodes of the linked list
 * 
 */
class node
{
    public:
        int data=0;
        node *link=NULL;
};
/**
 * @brief Points to the head node of the linked list
 * 
 */
node *first=NULL;
/**
 * @brief This functions is used to insert the array in the linked list
 * 
 * @param x is the data that is to be inserted
 * @param a is the array which stores the xor of the entries
 * @param n is the number of elements stored in the array
 */
void insert(int x,int a[],int n)
{
    node *newnode=new node;
    newnode->data=x;
    if(first==NULL)
    {
        first=newnode;
        a[0]=x;
    }
    else
    {
        node *p=first;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=newnode;
        a[n]=x^a[n-1];
    }
}
/**
 * @brief This function prints and counts the number of triplets
 * 
 * @param i Starting index of triplet
 * @param k ending index of triplet
 * @param count stores the number of triplets found so far
 */
void print1(int i,int k,int &count)
{
    i++;
    k++;
    for(int j=i+1;j<=k;j++)
    {
        cout<<"("<<i<<","<<j<<","<<k<<")"<<endl;
        count++;
    }
}
/**
 * @brief Main function
 * 
 * @return int 
 */
int main()
{
    int a[1000];
    int n;
    int count=0;
    cout<<"Enter the number of positive integers"<<endl;
    cin>>n;
    int input;
    cout<<"Enter the numbers\n";
    for(int i=0;i<n;i++)
    {
        cin>>input;
        insert(input,a,i);
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        print1(0,i,count);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            print1(i+1,j,count);
        }
    }
    
    cout<<count<<endl;
}