// =============================================================
//PROJECT NAME          :PHONE BOOK USING DOUBLY LINK LIST
// PROGRAMMING LANGUAGE :C++   (supporst oop concept)
// DATA STRUCTURE USED  :DOUBLY LINK LIST(A doubly-linked list is particularly nice because you can iterate and search from the front (head) of the end of the list or the back (tail))
// DEVELOPER            :PRANJALI BHAUSAHEB SATHE
// AIM                  :TO MANAGE CONTACT LIST AND ALSO PERFORM DIFFERENT OPERATIONS (SEARCHING,SORTIONG)
// STARTING DATE        :01/06/2022
// =============================================================
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// =============================================================
// =============================================================
#include <iostream>
#include <cstring>
using namespace std;
// =============================================================
class node
{
public:
    char name[50];
    char place[50];
    char phoneNo[50];
    char emailAdd[50];
    node *prev,*next;;
    node(char name[], char place[], char phoneNo[], char emailAdd[])
    {
        strcpy(this->name, name);
        strcpy(this->place, place);
        strcpy(this->phoneNo, phoneNo);
        strcpy(this->emailAdd, emailAdd);
        prev=NULL;
        next=NULL;

    }
    friend class nodelist;
};
// ----------------------------
class nodelist{
    //  private:
     node *head,*newn,*ptr;
     node *ptr1,*ptr2,*dup;

     public:
     node *preven;
    // -------------------------
    void insert();
    void accept();
    void display();
    void update(char n[]);

    // -------------------------
    nodelist()
    {
        head=NULL;
        newn=NULL;
        ptr=NULL;
        ptr1=NULL;
        ptr2=NULL;
        dup=NULL;

    }
     
};
// -------------------------------------------------------------
void nodelist::accept()
{
    char name[50];
    char place[50];
    char phoneNo[12];
    char emailAdd[50];
    char choice;
    do{
       cout<<"ENTER YOUR NAME:\n";
       cin>>name;

       cout<<"ENTER YOUR PLACE:\n";
       cin>>place;

       do{
           cout<<"ENTER YOUR VALID 10 DIGIT PHONE NUMBER:\n";
           cin>>phoneNo;
       }while(strlen(phoneNo)!=10);
      
       cout<<"ENTER YOUR VALID EMAIL ADDRESS:\n";
       cin>>emailAdd;

       newn=new node(name,place,phoneNo,emailAdd);
       if(head==NULL)
       {
           head=newn;

       }
       else if(head!=NULL)
       {
          ptr=head;

          while(ptr->next!=NULL)
          {
              ptr=ptr->next;
          }
          ptr->next=newn;
          newn->prev=ptr;
       }



    //  ---------------------------------------------
     cout<<"Enter y to continue...\nEnter n to stop:\n";
     cin>>choice;
    }while(choice=='y' || choice=='Y');

}

// -----------------DISPLAY-----------------------------
void nodelist::display()
{        ptr=head;
            cout<<"________________________________________________________"<<endl;
             cout<<"|\tNAME\t|\tPLACE\t|\tPHONE NUMBER\t| :"<<endl;
             cout<<"|_______________|_______________|_______________________|"<<endl;
         while(ptr!=NULL)
         {   
             cout<<"|\t"<<ptr->name<<"\t|"<<"\t"<<ptr->place<<"\t|"<<"\t"<<ptr->phoneNo<<"\t|"<<endl;
              cout<<"|_______________|_______________|_______________________|"<<endl;
            //  cout<<"________________________________________________________"<<endl;
            ptr=ptr->next;
         }
    
}
// ----------------INSERT--------------------------------------
void nodelist::insert()
{
    accept();
}
// ----------------UPDATE--------------------------------------
void nodelist::update(char n[20])
    {
        char ans;
        int c;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(n,ptr->name)==0)
            {
                
                do
                {
                    cout<<"\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.G-MAIL\n";
                cin>>c;
                switch(c)
                {
                    case 1:
                    cout<<"ENTER NEW-NAME=";
                    cin>>ptr->name;
                    break;
                    case 2:
                    cout<<"ENTER NEW PHONE-NUMBER?";
                    cin>>ptr->phoneNo;
                    while(strlen(ptr->phoneNo)!=10)
    {
    cout<<"ENTER VALID NUMBER  :";
    cin>>ptr->phoneNo;
    }
                    break;
                    case 3:
                    cout<<"ENTER NEW G-MAIL";
                    cin>>ptr->emailAdd;
                    break;
                }
                cout<<"DO YOU WANT TO CONTINUE UPDATING?";
                cin>>ans;
                }while(ans=='y');
            }
            ptr=ptr->next;
        }
    }
// =============================================================
int main()
{   nodelist contact;
    int choice = 0;
    do
    {
        cout << "                         ENETR THE NUMBER OF OPERATION YOU WANT TO PERFORM\n\n";
        cout << "\t\t\t|==================================================|\n";
        cout << "\t\t\t|\t           PHONE BOOK                      |\n";
        cout << "\t\t\t|==================================================|\n";
        cout << "\t\t\t|\t1].DISPLAY PHONE BOOK                      |\n";
        cout << "\t\t\t|\t2].INSERT NEW CONTACT                      |\n";
        cout << "\t\t\t|\t3].UPDATE DETAILS ON EXISTING CONTACt      |\n";
        cout << "\t\t\t|\t4].DELETE CONTACT                          |\n";
        cout << "\t\t\t|\t5].DELETE SAME NAME IN PHONEBOOK           |\n";
        cout << "\t\t\t|\t6].DELETE SAME NAME IN PHONEBOOK           |\n";
        cout << "\t\t\t|\t7].SEARCH                                  |\n";
        cout << "\t\t\t|\t10].EXIT                                   |\n";
        cout << "\t\t\t|==================================================|\n";

        // cout<<"1.DISPLAY PHONE BOOK\n2.INSERT NEW CONTACT\n3.UPDATE DETAILS ON EXISTING CONTACT\n4.DELETE CONTACT\n5.DELETE SAME NAME IN PHONEBOOK\n6.DELETE SAME NAME IN PHONEBOOK\n7.SEARCH\n10.EXIT\n"<<endl;
        cin >> choice;
        // ----------------------
        switch (choice)
        {
        case 1:
        {   
            contact.display();
            break;
        }
        case 2:
        {  
            contact.insert();
            break;
        }
        case 3:
        {   char name[50];
            cout<<"ENTER CONTACT NAME YOU WANT TO UPDATE:\n";
            cin>>name;
            contact.update(name);
        }
        case 10:
        {
            break;
        }
        }
    } while (choice != 10);
    return 0;
}
