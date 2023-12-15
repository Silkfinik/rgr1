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
        L.ForEach(modify);
        L.ListPrint();
    }
    catch (char*)
    {
        std::cout << "EMPTY!!!" << std::endl;
    }
    return 0;
}