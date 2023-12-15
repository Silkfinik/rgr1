#include <iostream>
#include <string>

class List {
protected:
    struct ListItem {
        int age;
        ListItem *Next;
    };
    ListItem *First;
public:
    List(){
        First = nullptr;
    };
    List(const List&);
    virtual~List();
    void InsertFirst(const int &AInfo);
    void InsertLast(const int &AInfo);
    bool DeleteFirst();
    bool DeleteLast();
    void DeleteInfo(const int& a);
    void Erase();
    List & operator = (const List &);
    void ListPrint() const;
    List operator+(const List& sec) const;
    int find_count(int age, int& counter) const;
    void ForEach (int(int&));
    void ForEach (void(int))const;
protected:
    void Clone(const List &);
};