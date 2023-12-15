#include "header.h"

void List::InsertFirst(const int &AInfo)
{
    ListItem *P = new ListItem;
    P->age = AInfo;
    P->Next = First;
    First = P;
}

void List::InsertLast(const int &AInfo) {
    if(First != nullptr) {
        ListItem *temp = First;
        ListItem *insert = new ListItem;
        insert->age = AInfo;
        while(temp->Next != nullptr){
            temp = temp->Next;
        }
        temp->Next = insert;
        insert->Next = nullptr;
    }
    else {
        InsertFirst(AInfo);
    }
}

bool List::DeleteFirst()
{
    if (First == NULL) {
        return false; // Список пустой
    }
    ListItem *P = First;
    First = First->Next;
    delete P;
    return true;
}

bool List::DeleteLast() {
    if (First == NULL) {
        return false; // Список пустой
    }
    if (First->Next == nullptr){
        DeleteFirst();
    }
    else{
        ListItem* temp = First;
        ListItem* prev = nullptr;
        while (temp->Next != nullptr) {
            prev = temp;
            temp = temp->Next;
        }
        delete temp;
        prev->Next = nullptr;
    }
}

void List::DeleteInfo(const int &a) {
    ListItem* temp = First;
    ListItem* prev = nullptr;
    while (temp != nullptr) {
        if (temp->age == a) {
            if (prev != nullptr) {
                prev->Next = temp->Next;
            } else {
                First = temp->Next;
            }
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->Next;
    }
}

void List::Clone(const List &L){
    ListItem *p, *q, *r;
    r=NULL;
    p=L.First;
    while (p!=NULL)
    {
        q=new ListItem;
        q->age=p->age;
        q->Next=NULL;
        if (r==NULL)
            First = q;
        else
            r->Next=q;
        r=q;
        p=p->Next;
    }
}

void List::Erase(){
    ListItem *p, *q;
    p=First;
    while (p!=NULL)
    {
        q=p->Next;
        delete p;
        p=q;
    }
    First=NULL;
}

List::~List()
{
    Erase();
}

List::List(const List& L)
{
    Clone(L);
}

List& List::operator = (const List &L)
{
    if (&L==this)
        return *this; // проверка на самоприсваивание
    Erase();
    Clone(L);
    return *this;
}

void List::ListPrint()const
{
    ListItem *P = First;
    if (P == NULL)
        std::cout << "List is empty!" << std::endl;
    if (P != NULL)
    {
        std::cout << "List elements:" << std::endl;
        while(P != NULL)
        {
            std::cout << P->age << std::endl;
            P = P->Next;
        }
    };
}

List List::operator+(const List& sec) const {
    List result;
    ListItem* temp = First;
    while (temp != nullptr) {
        result.InsertLast(temp->age);
        temp = temp->Next;
    }
    temp = sec.First;
    while (temp != nullptr) {
        result.InsertLast(temp->age);
        temp = temp->Next;
    }
    return result;
}

int List::find_count(int age, int& counter) const {
    ListItem* temp = First;
    counter = 0;
    while (temp != nullptr) {
        counter++;
        if (temp->age == age) {
            return counter;
        }
        temp = temp->Next;
    }
    return counter;
}

int modify(int& a){
    return a + 1;
}

void List::ForEach (int Fun(int& a)){
    ListItem *P = First;
    if (P == NULL)
        std::cout << "List is empty!" << std::endl;
    if (P != NULL){
        ListItem* temp = First;
        while (temp != nullptr) {
            temp->age = Fun(temp->age);
            temp = temp->Next;
        }
    }
}

void Print(int x)
{
    std::cout << x << std::endl;
}

void List::ForEach(void Fun(int))const
{
    ListItem *P = First;
    if (P == NULL)
        std::cout << "List is empty!" << std::endl;
    if (P != NULL)
    {
        std::cout << "List elements: " << std::endl;
        while(P != NULL)
        {
            Fun(P->age);
            P = P->Next;
        }
    };
}
