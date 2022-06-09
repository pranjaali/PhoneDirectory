# PhoneDirectory
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
#include <iomanip>
using namespace std;
// =============================================================
class node
{
public:
    char name[50];
    char place[50];
    char phoneNo[50];
    char emailAdd[50];
    node *prev, *next;
    ;
    node(char name[], char place[], char phoneNo[], char emailAdd[])
    {
        strcpy(this->name, name);
        strcpy(this->place, place);
        strcpy(this->phoneNo, phoneNo);
        strcpy(this->emailAdd, emailAdd);
        prev = NULL;
        next = NULL;
    }
    friend class nodelist;
};
// ----------------------------
class nodelist
{
    //  private:
    node *head, *newn, *ptr;
    node *ptr1, *ptr2, *dup;

public:
    node *preven;
    // -------------------------
    void insert();
    void accept();
    void display();
    void update(char n[]);
    void deleteContact(char n[]);
    void searchContact(char n[]);

    // -------------------------
    nodelist()
    {
        head = NULL;
        newn = NULL;
        ptr = NULL;
        ptr1 = NULL;
        ptr2 = NULL;
        dup = NULL;
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
    do
    {
        cout << "ENTER YOUR NAME:\n";
        cin >> name;

        cout << "ENTER YOUR PLACE:\n";
        cin >> place;

        // do
        // {
        //     cout << "ENTER YOUR VALID 10 DIGIT PHONE NUMBER:\n";
        //     cin >> phoneNo;
        // } while (strlen(phoneNo) != 10);

        cout << "ENTER YOUR VALID EMAIL ADDRESS:\n";
        cin >> emailAdd;

        newn = new node(name, place, phoneNo, emailAdd);
        if (head == NULL)
        {
            head = newn;
        }
        else if (head != NULL)
        {
            ptr = head;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newn;
            newn->prev = ptr;
        }

        //  ---------------------------------------------
        cout << "Enter y to continue...\nEnter n to stop:\n";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

// -----------------DISPLAY-----------------------------
void nodelist::display()
{
    ptr = head;
    cout << setw(30) << "______________________________________________________________________" << endl;
    cout << setw(25) << "NAME" << setw(25) << "PLACE" << setw(25) << "PHONE NUMBER" << setw(15) << "EMAIL" << endl;
    cout << "\t\t\t___________________________________________________________" << endl;

    while (ptr != NULL)
    {
        cout << setw(25) << ptr->name << setw(20) << ptr->place << setw(20) << ptr->phoneNo << setw(15) << ptr->emailAdd << endl;

        ptr = ptr->next;
    }
    cout << "\t\t\t___________________________________________________________" << endl;
}
// ----------------INSERT--------------------------------------
void nodelist::insert()
{
    accept();
}
// ----------------UPDATE--------------------------------------
void nodelist::update(char name[50])
{
    ptr = head;
    char choice;

    while (ptr != NULL)
    {
        if (strcmp(name, ptr->name) == 0)
        {
            do
            {
                cout << "WHAT DO YOU WANT TO UPDATE:" << endl;
                cout << "1.NAME\n2.PHONE NUMBER\n3.EMAIL ADDRESS\n4.PLACE\n"
                     << endl;
                cin >> choice;
                switch (choice)
                {
                case '1':
                {
                    cout << "ENTER NEW NAME:\n";
                    cin >> ptr->name;
                    break;
                }
                case '2':
                {
                    cout << "ENTER NEW PHONE NUMBER" << endl;
                    cin >> ptr->phoneNo;
                    while (strlen(ptr->phoneNo) != 10)
                    {
                        cout << "ENTER VALID PHONE NUMBER:" << endl;
                        cin >> ptr->phoneNo;
                    }
                    break;
                }
                case '3':
                {
                    cout << "ENTER VALID EMAIL ADDRESS:\n";
                    cin >> ptr->emailAdd;
                    break;
                }
                case '4':
                {
                    cout << "ENTER VALID PLACE:\n";
                    cin >> ptr->place;
                    break;
                }
                }
                cout << "DO YOU WANT TO CONTINUE....." << endl;
                cin >> choice;

            } while (choice == 'y' || choice == 'Y');
        }

        ptr = ptr->next;
    }
}
// ---------------DELETE CONTACT-------------------------------
void nodelist::deleteContact(char name[50])
{   int cnt=0;
    ptr=head;
    if(ptr==NULL)
    {
        cout<<"CONTACT LIST IS EMPTY:\n"<<"CAN NOT PERFORN DELETE OPERATION\n";
    }
    else if(ptr!=NULL)
    {
        while(ptr!=NULL)
        {
            if(strcmp(name,ptr->name)==0)
            { 
                cnt=1;
                break;
            }
            else if(strcmp(name,ptr->name)!=0)
            {
                cnt=2;
            }
            ptr=ptr->next;
        }
        // ----------------------------------------------
        if(cnt==1 && ptr==head && ptr->next==NULL)
                {
                    delete(ptr);
                    cout<<"CONTACT DELETED SUCCESFULLY\n";
                    head=NULL; 
                    
                }
                else if(cnt==1 && ptr==head && ptr->next!=NULL)
                {   head=ptr->next;
                    ptr->next->prev=NULL;
                    delete(ptr);
                    

                     cout<<"CONTACT DELETED SUCCESFULLY\n";
                }
                else if(cnt==1 && ptr!=head && ptr->next==NULL)
                {
                    ptr->prev->next=NULL;
                    delete(ptr);
                    cout<<"CONTACT DELETED SUCCESFULLY\n";
                }
                else if(cnt==1 && ptr!=head && ptr->next!=NULL)
                {
                    ptr->prev->next=ptr->next;
                    ptr->next->prev=ptr->prev;
                    delete(ptr);
                     cout<<"CONTACT DELETED SUCCESFULLY\n";

                }
                else if(cnt==2)
                {
                cout<<name<<"IS NOT PRESENT IN CONTACT LILST"<<endl;
                }
        // ---------------------------------------------
    }

    
}
// ---------------DELETE SAME NAME IN PHONEBOOK-----------------------------------
// ---------------DELETE SAME NUMBER IN PHONE BOOK---------------------------------
// ---------------SEARCH CONTACT---------------------------------------------------
// ---------------search using name------------------------------------------------


// =============================================================
int main()
{
    nodelist contact;
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
        {
            char name[50];
            cout << "ENTER CONTACT NAME YOU WANT TO UPDATE:\n";
            cin >> name;
            contact.update(name);
        }
        case 4:
        {
            char name[50];
            cout<<"ENTER NAME YOU WANT TO DELETE:\n";
            cin>>name;
            contact.deleteContact(name);
        }
        case 10:
        {
            break;
        }
        }
    } while (choice != 10);
    return 0;
}
