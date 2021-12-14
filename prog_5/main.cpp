#include <iostream>
#include "BinaryTree.h"

int main() {
    //insert and print
    vector<bool> arr1{};
    BinaryTree binaryTree1(2);

    arr1.push_back(true);
    binaryTree1.insert(3, arr1);
    arr1.pop_back();
    arr1.push_back(false);
    binaryTree1.insert(11, arr1);
    arr1.push_back(false);
    binaryTree1.insert(7, arr1);

    std::cout << binaryTree1;

    //CountOfEven, allPositives, average
    vector<bool> arr2{};
    BinaryTree binaryTree2(22);

    arr2.push_back(true);
    binaryTree2.insert(4, arr2);
    arr2.pop_back();
    arr2.push_back(false);
    binaryTree2.insert(18, arr2);
    arr2.push_back(false);
    binaryTree2.insert(5, arr2);

    cout << binaryTree2.countOfEven() << endl; //3
    cout << binaryTree2.average() << endl; //12.25
    cout << binaryTree2.allPositive() << endl; //true

    binaryTree2.insert(-10, arr2);

    cout << binaryTree2.allPositive() << endl; //false;

    vector<bool> arr3;

    BinaryTree binaryTree3;

    /*      8
     *   3    10
     * -1  6    12
     *      8  7    */
    binaryTree3.insert(8, arr3);
    arr3.push_back(false);
    binaryTree3.insert(3, arr3);
    arr3.push_back(false);
    binaryTree3.insert(-1, arr3);
    arr3.pop_back();
    arr3.push_back(true);
    binaryTree3.insert(6, arr3);
    arr3.push_back(true);
    binaryTree3.insert(8, arr3);

    arr3.clear();
    arr3.push_back(true);
    binaryTree3.insert(10, arr3);
    arr3.push_back(true);
    binaryTree3.insert(12, arr3);
    arr3.push_back(false);
    binaryTree3.insert(7, arr3);
    BinaryTree binaryTree4 = binaryTree3;

    /*      8
     *   3    10
     * -1  6    12
     *         14   */

    binaryTree4.deleteLeaves();
    binaryTree4.insert(14, arr3);


    vector<bool> arr4{};
    BinaryTree binaryTree5;

    /*      8
     *   3    10
     * -1  6    12
     *      8  7    */
    binaryTree5.insert(8, arr4);
    arr4.push_back(false);
    binaryTree5.insert(3, arr4);
    arr4.push_back(false);
    binaryTree5.insert(-1, arr4);
    arr4.pop_back();
    arr4.push_back(true);
    binaryTree5.insert(6, arr4);
    arr4.push_back(true);
    binaryTree5.insert(8, arr4);

    arr4.clear();
    arr4.push_back(true);
    binaryTree5.insert(10, arr4);
    arr4.push_back(true);
    binaryTree5.insert(12, arr4);
    arr4.push_back(false);
    binaryTree5.insert(7, arr4);

    arr4.clear();
    arr4.push_back(false);
    arr4.push_back(true);
    vector<bool> bArr = binaryTree5.searchElem(6);
    if (arr4 == bArr) {
        cout << true;
    }
    //binaryTree5.searchElem(99);
}

