// ***********************************************
// * Name: LinkList.cpp                          *
// * Description: Implementation file for doubly *
// *              linked list of PieCake_struct  *
// *              objects.                       *
// * Author: Betty Phipps                        *
// * Date: 04/07/2025                            *
//************************************************
#include "linklist.h"
#include <iostream>
#include <iomanip>

// ***********************************************
// * Name: LinkList                              *       
// * Description: Constructor creates an empty   *
//*               link list with dummy tail and  *
//*                head points to tail           *
// *              and the previous and next      *
//*                pointers are nullptr          *
// * Author: Betty Phipps                        *
// * Date: 04/07/2025                            *
//************************************************
LinkList::LinkList() {
    //creating dummy head and tail
    head = new PieCake_struct();
    tail = new PieCake_struct();
    head->next = tail;              //head points to tail
    tail->prev = head;              //tail points to head
    current = nullptr;              //initially null record
    count = 0;                      //inital size is 0
}

// ***********************************************
// * Name: ~LinkList                             *
// * Description: Deconstructor deletes the list *
//*               one record at a time and sets  *
//*               counter to zero                *
// * Author: Betty Phipps                        *
// * Date: 04/07/2025                            *
//************************************************
LinkList::~LinkList(){
    PieCake_struct* temp = head;        //starting point for traversing the linked list
    while (temp != nullptr){
        PieCake_struct* nextNode = temp->next;  //checks if null and current node is deleted
        delete temp;
        temp = nextNode;
    }
    head = tail = current = nullptr;
    count = 0;
}

// ***********************************************
// * Name: Empty                                 *
// * Description: Returns true if list is empty  *
// * Author: Betty Phipps                        * 
// * Date: 04/07/2025                            *
//************************************************
bool LinkList::Empty(){
    return head->next == tail;          //if list is empty, return true
}

// ***********************************************
// * Name: Size                                  *    
// * Description: Returns the number of records  *
// * Author: Betty Phipps                        *    
// * Date: 04/07/2025                            *
//************************************************
int LinkList::Size(){
    return count;
}

// ************************************************
// * Name: Find                                   *
// * Description: Finds the record with an id     *
//*               that matches the number past    *
//*               in with index. Sets the current *
//*               pointer to that record. Returns *
//*                 true if found.                *
// * Author: Betty Phipps                         *
// * Date: 04/07/2025                             *
//*************************************************
bool LinkList::Find(const int index){
    if (Empty()){
        current = nullptr;
        return false;
    } else {
        PieCake_struct* currentNode = head->next;   //Start search from the first actual record

        while (currentNode != tail){
            if (currentNode->id == index){
                current = currentNode;
                return true;
            }
            currentNode = currentNode->next;
        }
    }

    current = nullptr;
    return false;
}

// ************************************************
// * Name: Push_Back                              *
// * Description: Inserts the record right before *
//*               the tail. Point to head if list *
//*                is empty.                      *
// * Author: Betty Phipps                         *
// * Date: 04/07/2025                             *
//*************************************************      
void LinkList::Push_Back( PieCake_struct * p ){
    if (!p) return;     //protect from null pointer 

    if (Empty()){
        head->next = p;
        tail->prev = p;
        p->next = tail;
        p->prev = head;
    } else {
        PieCake_struct* last = tail->prev;
        last->next = p;
        p->prev = last;
        p->next = tail;
        tail->prev = p;
    }
    count++;
}

// ***********************************************
// * Name: Delete                                *
// * Description: Deletes the record at the      *
//*               current pointer                *
// * Author: Betty Phipps                        *
// * Date: 04/07/2025                            *
//************************************************
bool LinkList::Delete(){
    if (current == nullptr){
        return false;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    current = nullptr;
    count--;
    return true;

}

// ***********************************************
// * Name: Print                                 *
// * Description: Prints the report, counts the  *
//*               number of records that men,    *
//*               women, and other chose Cake    *
//*               or Pie.                        *
// * Author: Betty Phipps                        *
// * Date: 04/07/2025                            *
//************************************************
void LinkList::Print(){
    List();
    int men_pie = 0, men_cake = 0;
    int women_pie = 0, women_cake = 0;
    int other_pie = 0, other_cake = 0;

    PieCake_struct* node = head->next;
    while (node != tail){
        char s = toupper(node->sex);
        char choice = toupper(node->pORc);

        if (s == 'M'){
            if (choice == 'P') men_pie++;
            else if (choice == 'C') men_cake++;
        } else if (s == 'F'){
            if (choice == 'P') women_pie++;
            else if (choice == 'C') women_cake++;
        } else {
            if (choice == 'P') other_pie++;
            else if (choice == 'C') other_cake++;
        }
        node = node->next;
    }
    int total = men_pie + men_cake + women_pie + women_cake + other_pie + other_cake;

    cout<<"Men who believe Cheescake is Pie:"<<setw(4)<<men_pie<<endl;
    cout<<"Men who believe Cheescake is Cake:"<<setw(4)<<men_cake<<endl;
    cout<<"Women who believe Cheescake is Pie:"<<setw(4)<<women_pie<<endl;
    cout<<"Women who believe Cheescake is Cake:"<<setw(4)<<women_cake<<endl;
    cout<<"Other who believe Cheescake is Pie:"<<setw(4)<<other_pie<<endl;
    cout<<"Other who believe Cheescake is Cake:"<<setw(4)<<other_cake<<endl;
    cout<<setw(17)<<"Total:"<<setw(10)<<total<<endl;
}

// ***********************************************
// * Name: List                                  *
// * Description: Prints the records out to      *
//*               standard output                *
// * Author: Betty Phipps                        *
// * Date: 04/07/2025                            *
//************************************************
void LinkList::List(){
    cout<< " T H E  G R E A T   C H E E S E C A K E  S U R V E Y\n"<<endl;
    cout<<" ID   FIRST NAME      MI   LAST NAME           SEX SURVEY"<<endl;

    PieCake_struct* node = head->next;

    while (node != tail && node != nullptr){
        string sexStr = (node->sex =='F') ? "Female" :
                        (node->sex =='M') ? "Male" :
                        (node->sex =='O') ? "Other" : "Unknown";
           
        string survStr = (node->pORc =='P') ? "Pie" :
                        (node->pORc =='C') ? "Cake" : "Unknown";

        cout<<left
            <<setw(6)<<node->id
            <<setw(15)<<node->fname
            <<setw(5)<<node->mi
            <<setw(20)<<node->lname
            <<setw(10)<<sexStr
            <<setw(10)<<survStr
            <<endl;

        node = node->next;
    }
}