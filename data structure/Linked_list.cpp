#include<bits/stdc++.h>
#include<iostream>

struct node{
    int val;
    node* next;
};
node* head;

void Insert()
{
    int ch;
    int c;
    node* n=new node();
    node* temp=head;
    int e;
    std::cout<<"\nEnter the Element to Insert:";
    std::cin>>e;
    std::cout<<"\n1.Insert At Beginning.";
    std::cout<<"\n2.Insert At Position.";
    std::cout<<"\n3.Insert At End.";
    std::cout<<"\nEnter the choice: ";
    std::cin>>ch;
    switch(ch)
    {
    case 1:
        n->val=e;
        n->next=NULL;
        if(head==NULL)
        {
            head=n;
        }
        else
        {
            n->next=head;
            head=n;
        }
        std::cout<<"\nInserted!";
        break;
    case 2:
        int p;
        std::cout<<"\nEnter the position:";
        std::cin>>p;
        n->val=e;
        n->next=NULL;
        c=0;
        while(temp!=NULL)
        {
            if(c==p-1)
            {
                n->next=temp->next;
                temp->next=n;
                std::cout<<"\nInserted!!";
            }
            c++;
            temp=temp->next;
        }
        break;
    case 3:
        n->val=e;
        n->next=NULL;
        if(head==NULL)
        {
            head=n;
            std::cout<<"\nInserted!!!";
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n;
            n->next=NULL;
            std::cout<<"\nInserted!!!";
        }
        break;
    default:
        std::cout<<"\nInvalid choice!!";
    }
    std::cout<<std::endl;
}

void Delete()
{
   int ch;
   int p;
   int c;
   node* temp;
   node* temp2;
    std::cout<<"\n1.Delete From Beginning.";
    std::cout<<"\n2.Delete From position.";
    std::cout<<"\n3.Delete From End.";
    std::cout<<"\nEnter the choice: ";
    std::cin>>ch;
    switch(ch)
    {
    case 1:
        if(head==NULL)
        {
            std::cout<<"\nUnderflow!!";
        }
        else
        {
            temp=head;
            head=temp->next;
            delete (temp);
            std::cout<<"\nDeleted!";
        }
        break;
    case 2:
        if(head==NULL)
        {
            std::cout<<"\nunderflow!!";
        }
        else
        std::cout<<"Enter the Position to Delete:";
        std::cin>>p;
        temp=head;
        if(p==0)
        {
            temp=head;
            head=temp->next;
            delete temp;
            std::cout<<"\nDeleted!";
            break;
        }
        for(int i=0;temp!=NULL && i<p-1;i++)
        {
            temp=temp->next;
        }
        temp2=temp->next->next;
        delete(temp->next);
        temp->next=temp2;
        break;
    case 3:
        if(head->next==NULL)
        {
            temp=head;
            head=temp->next;
            delete temp;
            std::cout<<"\nDeleted!!!";
        }
        else if(head==NULL)
        {
            std::cout<<"\nUnderflow!";
        }
        else
        {
            temp=head;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=NULL;
            std::cout<<"\nDeleted!!!";
        }
        break;
    default:
        std::cout<<"\nInvalid choice!!";
    }
std::cout<<std::endl;
}
void search(int e)
{
    node* temp=head;
    int val=0;
    while(temp!=NULL)
    {
        if(temp->val==e)
        {
            val=temp->val;
        }
        temp=temp->next;
    }
    if(val==e)
    {
        std::cout<<"\nElement "<<e<<" is present in List!";
    }
    else
    {
        std::cout<<"\nElement "<<e<<" not Found!!";
    }
    std::cout<<std::endl;
}

void display()
{
    if(head==NULL)
    {
        std::cout<<"\nUnderflow!!";
    }
    node* temp=head;
    while(temp!=NULL)
    {
        std::cout<<"["<<temp->val<<"]->";
        temp=temp->next;
    }
    std::cout<<"NULL";
    std::cout<<std::endl;
}
int main()
{
    int choice=0;
    int x=0;

    do{
        std::cout<<"====LINKED-LIST====";
        std::cout<<"\n1.Insert";
        std::cout<<"\n2.Delete";
        std::cout<<"\n3.Search";
        std::cout<<"\n4.Print";
        std::cout<<"\n5.Exit";
        std::cout<<"\nEnter the Choice: ";
        std::cin>>choice;

        switch(choice)
        {
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            int ele;
            std::cout<<"\nEnter the Element to be searched:";
            std::cin>>ele;
            search(ele);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            std::cout<<"\nInvalid choice!!";

        }
    }while(choice!=5);
    return 0;
}
