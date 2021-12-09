#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
using namespace std;

int main() {
    LinkedList<int> listOne;
    listOne.addElem(2);

    LinkedList<int> list1(listOne);
    listOne.addElem(4);

    auto itOne = list1.begin();
    cout << (itOne.hasNext()) << endl;

    LinkedList<int> list2(std::move(listOne));
    cout << (listOne.empty()) << endl;



    LinkedList<int> listTwo;
    listTwo.addElem(2);
    listTwo.addElem(3);
    listTwo.addElem(4);

    //2 4 3
    for (int i: listTwo) {
        std::cout << i << " ";
    }
    cout << endl;

    cout << (listTwo.size() == 3) << endl;

    auto itTwo = listTwo.searchElem(2);
    cout << (*itTwo) << endl;
    cout << (itTwo.hasNext()) << endl;

    auto it1 = listTwo.searchElem(4);
    listTwo.addElem(7, it1);
    listTwo.addElem(21, it1);
    it1++;
    cout << (*it1) << endl;
    it1++;
    cout << (*it1) << endl;

    listTwo.deleteElem(it1);

    cout << (*it1) << endl;

    //2 4 21  3
    for (int i: listTwo) {
        std::cout << i << " ";
    }
    cout << endl;

    listTwo.clear();

    cout << (listTwo.empty()) << endl;

}
