#include "function.cpp"

int main(){
    try {
        List L;
        L.InsertFirst(10);
        L.InsertFirst(20);
        L.InsertFirst(30);
        L.ListPrint();
        List M = L;
        M.ListPrint();
        List Z = M + L;
        Z.ListPrint();
        L.DeleteInfo(10);
        L.ListPrint();
        int a = -1;
        L.find_count(40, a);
        L.ForEach(modify);
        std::cout << "Number of comparisons: " << a << std::endl;
        L.ListPrint();
        L.ForEach(Print);
    }
    catch (char*)
    {
        std::cout << "EMPTY!!!" << std::endl;
    }
    return 0;
}