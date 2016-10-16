#include<iostream>
using namespace std; 
char s;
int a;
int no;
struct node           
{
    int data;        
    struct node *next; 
};
typedef struct node Node;
Node *head;

class llist
{
    public:  
         void create();
             void insert();
             void del();
             void traverse();
             void modify();
             void insertBegin();
             void insertMiddle(int);
             void insertEnd();
             void deleteBegin();
             void deleteMiddle(int);
             void deleteEnd();
             void search();
             void deletenode(int);
             int count;
             llist()             //List constructor 
             {
                 count=0;
             }
         };

        int main()                //main program begins
         {
             llist l;

             int n;
             cout << "If you want to create a circular list enter y" << endl;
             cin >> s;
             if(s=='y'||s=='Y')
             {
                 l.create();
             }
             do
             {

                    cout << endl;             
                    cout << "enter 1 to insert in beginning" << endl;
                    cout << "enter 2 to insert after a particular element" << endl;
                    cout << "enter 3 to insert at end of the list" << endl;
                    cout << "enter 4 to delete 1st" << endl;
                    cout << "enter 5 to delete after particular element" << endl;
                    cout << "enter 8 to exit" << endl; 
                    cin >> n;

        switch(n)
        {
            case 1: l.insertBegin();
                        break;  
            case 2: cout << "enter the number after which you want to:" << endl;
                       cin >> a;
                       l.insertMiddle(a);        
                        break;
        case 3: l.insertEnd();
                     break;
            case 4: l.deleteBegin();
            break;  
            case 5: cout << "enter after" << endl;
                         cin >> no;
                         l.deleteMiddle(no);
                         break;
                case 6: cout << "enter the node no. u wanna delete" << endl;
                        cin >> no;
                        l.deletenode(no);
                        break; 
            case 7: l.deleteEnd();
            break;

           }            
    }while(n!=8);

            
            return 0;
        }

//Implementation of all the functions from the class llist

void llist::create()
{
    Node *temp;
    do
    {
         Node *node;
    node=new Node;

        cout << "enter the data of node" << endl;
        cin >> node->data;
        node->next=head;
        if(head!=NULL)
        {
            temp->next=node;
            temp=node;
            node->next=head;
        }
        else
        {
            temp=node;
            head=node;
            node->next=head;
        }
        cout << "do you want to enter more " << endl;
        cin >> s;
        }while(s=='y'||s=='Y');

         traverse();
     }
     void llist::traverse()
     {
         Node *temp;
         temp=head;
         if(head==NULL)
         {
             cout << "empty" << endl;
         }
         else
         {
             while(temp->next!=head)
             {
                 cout << temp->data << "-";
                 temp=temp->next;
                 count  ;
             }  
             cout << temp->data;
             count  ;
         }
     }

       void llist::insertBegin()  
       {
           Node *node,*temp;
           node=new Node;
           cout << "enter the data of node" << endl;
           cin >> node->data;
           temp=head;
           if(head==NULL)
           {
               head=node;
               head->next=node;
           }
           else
           {    
         while(temp->next!=head)
         {
             temp=temp->next;
         }
         temp->next=node;
         node->next=head;
         head=node;
     }        
       traverse();
   }

               void llist::insertMiddle(int a)
               {
                   Node *node,*temp;
                   node=new Node;
                   cout << "enter the data of the node:" << endl;
                   cin >> no;
                   temp=head;
                   while(temp->next!=head)
                   {
                       if(temp->data==a)
                       {
                           break;
                       }
                       temp=temp->next;
                   }
                   if(temp->next==head)
                   {
                       cout << "Element is not found" << endl;
                       return;
                   }
                   else
                   {

                   node->data=no;
                   node->next=temp->next;
                   temp->next=node;
               }    
                   traverse();
               }

     void llist::insertEnd()
     {
         Node *node,*temp;
         node=new Node;
         cout << "enter data of the node" << endl;
         cin >> node->data;

         if(head==NULL)
         {
             head=node;
             node->next=head;
         }
         else
         {

         temp=head;
         while(temp->next!=head)
         { 
             temp=temp->next;
         }

         temp->next=node;
         node->next=head;
  }

       traverse();

}   
void llist::deleteBegin()
{
    Node *temp;
    if(head==NULL)
    {
        cout << "no element is found" << endl;
        return;
    }
    else
    {
    temp=head;
    while(temp->next!=head)

    {
        temp=temp->next;
    }    
        if(head->next==head)
        {
            temp=head;
            head=NULL;
                delete temp;
            }
            else
            {

     temp->next=head->next;
     temp=head;
     head=head->next;
        delete temp;
    }
}    
    traverse();
}   
void llist::deleteMiddle(int s)  
{
    Node *temp,*loc,*h;
    loc=head;
    h=head;
    if(head==NULL)
    {
        cout << "Sorry!! List is Empty" << endl;
        return;
    }
    else
    {    
    if(h->next==head)
    {
        temp=head;
        head=NULL;
        delete temp;
    }
    else
    {

    while(loc->next!=head)
    {
        if(loc->data==s)
        break;
        loc=loc->next;
    }

    if(loc->next==head )

    {
        if(loc->data==s)
        {

        temp=head;

        loc->next=head->next;
        head=head->next;
        delete temp;
    }
    else
    {
        cout << "Please check the number you are entering" << endl;

        }        
    }
    else
    {

    temp=loc->next;
    loc->next=temp->next;
    delete temp;
  }  
 }
 }
traverse();   
}   
void llist::deletenode(int n)
{
    Node *temp,*d;

    temp=head;
    int i=1;
    while(i < n-1)
    {
        temp=temp->next;
    i  ;
    }
    d=temp->next;
    temp->next=d->next;
    delete d;
traverse();
}
   void llist::deleteEnd() 
   {
       Node *temp,*d,*j;
       temp=head;
       while(temp->next!=NULL)
       {
           d=temp;
           temp=temp->next;
       }

       d->next=NULL;
       delete temp;
       traverse();

   }
