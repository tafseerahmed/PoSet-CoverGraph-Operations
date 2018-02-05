#include <iostream>
#include <vector>
#include <utility>
#include "covergraph.h"

int main() {
    int nodes;
    std::cout<<"Enter number of nodes in the cover graph: ";
    std::cin>>nodes;
    CoverGraph C(nodes);
    while (1) {
        int x ;
        std::cout << " 1. INIT\n 2. Delete Minimal Element\n 3. List Minimal Elements\n 4. Exit \n\n Enter your choice: ";
        std::cin>>x;
        switch (x) {
            case 1:C.INIT();break;
            case 2:C.DelMin();break;
            case 3:C.ListMin();break;
            case 4:exit(0);
            default:std::cout <<"Wrong choice, try again\n";
        }
    }
}