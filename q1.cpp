/**
 * @file q1.cpp
 * @author Ishan Pandey
 * @brief Solution of problem 1 of L3
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
 * @brief This class represents the nodes of the Trees
 * 
 */
class node
{
    public:
        int data;
        int height=0;
        char color;
        node *left=NULL;
        node *right = NULL;
        node *parent=NULL;
};
/**
 * @brief This function finds the level of each node
 * 
 * @param p Points to the node whose level is to be found
 * @param level stores the depth
 * @param max stores maximum value of level
 */
void find_level(node *p,int level,int &max)
{
    if(p==NULL)
    return;
    max=max>level?max:level;
    find_level(p->left,level+1,max);
    find_level(p->right,level+1,max);
}
/**
 * @brief This function corrects the balance of each node in the tree
 * 
 * @param p Points to the node whose balance is to be corrected 
 * @return ** void 
 */
void fix_height(node *p)
{
    if(!p)
    return;
    int lev_left=0;
    int lev_right=0;
    find_level(p->left,1,lev_left);
    find_level(p->right,1,lev_right);
    p->height=lev_left-lev_right;
    fix_height(p->left);
    fix_height(p->right);
}
/**
 * @brief This class represents the Binary Search Tree data structure
 * 
 */
class BST
{
    public:
    node *first=NULL;
    /**
     * @brief This function stores the data in tree
     * 
     * @param x stores the value of the data to be inserted
     */
    void insert(int x)
    {
            node *newnode=new node;
            newnode->data=x;
            if(first==NULL)
            {
                first=newnode;
                first->height=0;
            }
            else
            {
                node *p=first;
                node *q=p;
                int dir;
                while(p!=NULL)
                {
                    q=p;
                    if(x>p->data)
                    {
                        p=p->right;
                        dir=1;
                    }
                    else if(x<p->data)
                    {
                        p=p->left;
                        dir=0;
                    }
                    else
                    break;
                    
                }
                if(p==NULL)
                {
                    if(dir)
                    q->right=newnode;
                    else
                    q->left=newnode;
                }
                else
                {
                    delete newnode;
                    printf("Node already exists\n");
                    return;
                }
                p=first;
                q=newnode;
                int lev_left=0;
                int lev_right=0;
                while(p!=q)
                {
                    lev_left=0;
                    lev_right=0;
                    find_level(p->left,1,lev_left);
                    find_level(p->right,1,lev_right);
                    p->height=lev_left-lev_right;
                    if(x>p->data)
                    {
                        p=p->right;
                    }
                    else if(x<p->data)
                    {
                        p=p->left;
                    }
                    else
                    break;
                    
                }
            }
            
    }
    
};
/**
 * @brief This function prints all nodes the route from first to node containing the data x
 * 
 * @param first Points to a node of the tree
 * @param x stores the data of the node which is to be reached
 */
void print_paths(node *first,int x)
{
    node *p=first;
    cout<<p->data;
    if((!p->left)&&(!p->right))
    {
        cout<<endl;
        return;
    }
    node *q=p;
    if(x>p->data)
    {
        q=p->right;
    }
    else if(x<p->data)
    {
        q=p->left;
    }
    while(p->data!=x)
    {
        if(x>p->data)
        {
            p=p->right;
            cout<<"->"<<p->data;
        }
        else if(x<p->data)
        {
            p=p->left;
            cout<<"->"<<p->data;
        }
        
    }
    cout<<endl;
    print_paths(q,x);

}
/**
 * @brief Used to find the leaves of the tree
 * 
 * @param p Points to a node which is checked for a leaf
 * @param first Points to the head node of the tree
 */
void leaf(node *p,node *first)
{
    if((!p->left)&&(!p->right))
    print_paths(first,p->data);
    else
    {
        if(p->left)
        leaf(p->left,first);
        if(p->right)
        leaf(p->right,first);
    }
}
/**
 * @brief Used display inorder traversal of the tree
 * 
 * @param p Points to a node
 */
void inorder(node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}
/**
 * @brief Prints the tree with level wise indentation
 * 
 * @param p Points to a node
 * @param indent Specifies the amount of indentaion for a particular call
 * @param is_rbt Specifies whether the tree is red black or not
 */
void print2(node *p,int indent, bool is_rbt)
{
    if(p==NULL)
    return;
    for(int j=0;j<indent;j++)
    {
        cout<<"\t";
    }
    if((p->right!=NULL)||(p->left!=NULL))
    {
        cout<<p->data<<"["<<abs(p->height)<<"]";
    }
    else
    cout<<p->data;

    if(is_rbt)
    {
        if(p->color=='b')
        cout<<"[BLACK]"<<endl;
        else
        cout<<"[RED]"<<endl;
    }
    else
    {
        cout<<endl;
    }
    
    print2(p->left,indent+1,is_rbt);
    print2(p->right,indent+1,is_rbt);
}
/**
 * @brief Represents AVL tree data structure
 * 
 */
class AVL
{
    public:
        node *first=NULL;
        /**
         * @brief used for insertion of data in avl tree
         * 
         * @param x stores the data
         */
        void insertion(int x)
        {
            node *newnode=new node;
            newnode->data=x;
            if(first==NULL)
            {
                first=newnode;
                first->height=0;
            }
            else
            {
                node *p=first;
                node *q=p;
                node *imb=NULL;
                int dir;
                while(p!=NULL)
                {
                    q=p;
                    if(x>p->data)
                    {
                        p=p->right;
                        dir=1;
                    }
                    else if(x<p->data)
                    {
                        p=p->left;
                        dir=0;
                    }
                    else
                    break;
                    
                }
                if(p==NULL)
                {
                    if(dir)
                    q->right=newnode;
                    else
                    q->left=newnode;
                }
                else
                {
                    delete newnode;
                    printf("Node already exists\n");
                    return;
                }
                p=first;
                q=newnode;
                int lev_left=0;
                int lev_right=0;
                while(p!=q)
                {
                    lev_left=0;
                    lev_right=0;
                    find_level(p->left,1,lev_left);
                    find_level(p->right,1,lev_right);
                    p->height=lev_left-lev_right;
                    if((p->height>1)||(p->height<-1))
                    imb=p;
                    if(x>p->data)
                    {
                        p=p->right;
                    }
                    else if(x<p->data)
                    {
                        p=p->left;
                    }
                    else
                    break;
                    
                }
                if(imb!=NULL)
                {
                    if(imb->height==-2)
                    {
                        node *b=imb->right;
                        if(b->height==-1)
                        RRimbalance(imb);
                        else
                        RLimbalance(imb);
                    }
                    else
                    {
                        node *b=imb->left;
                        if(b->height==-1)
                        LRimbalance(imb);
                        else
                        LLimbalance(imb);
                    }
                }
                
            }
            
        }
        
        void RRimbalance(node *a)
        {
            node *b=a->right;
            node *al=a->left;
            node *bl=b->left;
            node *br=b->right;
            int temp=a->data;
            a->data=b->data;
            b->data=temp;
            a->height=0;
            b->height=0;
            a->left=b;
            a->right=br;
            b->right=bl;
            b->left=al;
        }
        void RLimbalance(node *a)
        {
            node *b=a->right;
            node *al=a->left;
            node *c=b->left;
            node *br=b->right;
            node *cr=c->right;
            node *cl=c->left;
            int temp=a->data;
            a->data=c->data;
            c->data=temp;

            b->left=cr;
            a->left=c;
            c->left=al;
            c->right=cl;
            b->height=(cr->height)-(br->height);
            c->height=(al->height)-(cl->height);
            a->height=(c->height)-(b->height);
        }
        void LRimbalance(node *a)
        {
            node *b=a->left;
            node *ar=a->right;
            node *bl=b->left;
            node *c=b->right;
            node *cr=c->right;
            node *cl=c->left;
            int temp=a->data;
            a->data=c->data;
            c->data=temp;
            b->right=cl;
            a->right=c;
            c->left=cr;
            c->right=ar;
            b->height=(bl->height)-(cl->height);
            c->height=(cr->height)-(ar->height);
            a->height=(b->height)-(c->height);
        }
        void LLimbalance(node *a)
        {
            node *b=a->left;
            node *ar=a->right;
            node *bl=b->left;
            node *br=b->right;
            int temp=a->data;
            a->data=b->data;
            b->data=temp;
            a->height=0;
            b->height=0;
            a->left=bl;
            a->right=b;
            b->right=ar;
            b->left=br;
        }
};
/**
 * @brief Creates avl tree from inorder traversal of bst
 * 
 * @param p Points to the nodes of the bst
 * @param a object of AVL class
 */
void convert_avl(node *p,AVL& a)
{
    if(p!=NULL)
    {
        convert_avl(p->left,a);
        a.insertion(p->data);
        convert_avl(p->right,a);
    }
}
/**
 * @brief Represents the Red black tree data structure
 * 
 */
class RBtree
{
    public :
      node *root;
      node *q;
      RBtree()
      {
              q=NULL;
              root=NULL;
      }
      void insert(int );
      void insertfix(node *);
      void leftrotate(node *);
      void rightrotate(node *);
};
/**
 * @brief Used for insertion in the RBtree
 * 
 * @param z stores data to be inserted
 */
void RBtree::insert(int z)
{
     int i=0;
     node *p,*q;
     node *t=new node;
     t->data=z;
     t->left=NULL;
     t->right=NULL;
     t->color='r';
     p=root;
     q=NULL;
     if(root==NULL)
     {
           root=t;
           t->parent=NULL;
     }
     else
     {
         while(p!=NULL)
         {
              q=p;
              if(p->data<t->data)
                  p=p->right;
              else
                  p=p->left;
         }
         t->parent=q;
         if(q->data<t->data)
              q->right=t;
         else
              q->left=t;
     }
     insertfix(t);
}
void RBtree::insertfix(node *t)
{
     node *u;
     if(root==t)
     {
         t->color='b';
         return;
     }
     while(t->parent!=NULL&&t->parent->color=='r')
     {
           node *g=t->parent->parent;
           if(g->left==t->parent)
           {
                        if(g->right!=NULL)
                        {
                              u=g->right;
                              if(u->color=='r')
                              {
                                   t->parent->color='b';
                                   u->color='b';
                                   g->color='r';
                                   t=g;
                              }
                        }
                        else
                        {
                            if(t->parent->right==t)
                            {
                                 t=t->parent;
                                 leftrotate(t);
                            }
                            t->parent->color='b';
                            g->color='r';
                            rightrotate(g);
                        }
           }
           else
           {
                        if(g->left!=NULL)
                        {
                             u=g->left;
                             if(u->color=='r')
                             {
                                  t->parent->color='b';
                                  u->color='b';
                                  g->color='r';
                                  t=g;
                             }
                        }
                        else
                        {
                            if(t->parent->left==t)
                            {
                                   t=t->parent;
                                   rightrotate(t);
                            }
                            t->parent->color='b';
                            g->color='r';
                            leftrotate(g);
                        }
           }
           root->color='b';
     }
}
/**
 * @brief performs left rotation
 * 
 * @param p points to the node of RBtree
 */
void RBtree::leftrotate(node *p)
{
     if(p->right==NULL)
           return ;
     else
     {
           node *y=p->right;
           if(y->left!=NULL)
           {
                  p->right=y->left;
                  y->left->parent=p;
           }
           else
                  p->right=NULL;
           if(p->parent!=NULL)
                y->parent=p->parent;
           if(p->parent==NULL)
                root=y;
           else
           {
               if(p==p->parent->left)
                       p->parent->left=y;
               else
                       p->parent->right=y;
           }
           y->left=p;
           p->parent=y;
     }
}
/**
 * @brief Preforms right rotation
 * 
 * @param p Points to a node of RBtree
 */
void RBtree::rightrotate(node *p)
{
     if(p->left==NULL)
          return ;
     else
     {
         node *y=p->left;
         if(y->right!=NULL)
         {
                  p->left=y->right;
                  y->right->parent=p;
         }
         else
                 p->left=NULL;
         if(p->parent!=NULL)
                 y->parent=p->parent;
         if(p->parent==NULL)
               root=y;
         else
         {
             if(p==p->parent->left)
                   p->parent->left=y;
             else
                   p->parent->right=y;
         }
         y->right=p;
         p->parent=y;
     }
}
/**
 * @brief Main function
 * 
 * @return int 
 */
int main()
{
    AVL avl;
    BST bst;
    RBtree rbt;
    int choice;
    while(1)
    {
        cout<<"Enter your choice:"<<endl;
        cout<<"1. To insert a node in the BST and in the red-black tree "<<endl;
        cout<<"2. To create AVL tree from the inorder traversal of the BST"<<endl;
        cout<<"3. To print the inorder traversal of the BST/AVL/red-black tree"<<endl;
        cout<<"4. To display all the paths in the BST/AVL tree/red-black tree"<<endl;
        cout<<"5. To print the BST/AVL tree/red-black Tree in the terminal using level-wise indentation (print color for red-black tree) "<<endl;
        cout<<"6. Exit "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the element you want to insert:"<<endl;
                int x;
                cin>>x;
                bst.insert(x);
                rbt.insert(x);
                fix_height(rbt.root);
                break;
            case 2:
                delete avl.first;
                convert_avl(bst.first,avl);
                cout<<"AVL tree created successfully"<<endl;
                break;
                
            case 3:
                cout<<"1.) Binary Search tree"<<endl;
                cout<<"2.) AVL Tree"<<endl;
                cout<<"3.) Red-Black tree"<<endl;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                        inorder(bst.first);
                        cout<<endl;
                        break;
                    case 2:
                        inorder(avl.first);
                        cout<<endl;
                        break;
                    case 3:
                        inorder(rbt.root);
                        cout<<endl;
                        break;
                }
                break;
            case 4:
                cout<<"1.) Binary Search tree"<<endl;
                cout<<"2.) AVL Tree"<<endl;
                cout<<"3.) Red-Black tree"<<endl;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                        leaf(bst.first,bst.first);
                        break;
                    case 2:
                        leaf(avl.first,avl.first);
                        break;
                    case 3:
                        leaf(rbt.root,rbt.root);
                        break;
                }
                break;
            case 5:
                cout<<"1.) Binary Search tree"<<endl;
                cout<<"2.) AVL Tree"<<endl;
                cout<<"3.) Red-Black tree"<<endl;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                        cout<<"Tree:"<<endl;
                        print2(bst.first,0,0);
                        break;
                    case 2:
                        cout<<"Tree:"<<endl;
                        print2(avl.first,0,0);
                        break;
                    case 3:
                        cout<<"Tree:"<<endl;
                        print2(rbt.root,0,1);
                        break;
                }
                break;
            case 6:
                exit(0);
                break;
            default:
                cout<<"Wrong input"<<endl;
                break;
        }
    }
    return 0;
}