#include "BinaryTree.h"

int main(){
    BinaryTree<string> bt;

    bt.insert("Piglet");
    bt.insert("Eeyore");
    bt.insert("Roo");
    bt.insert("Tigger");
    bt.insert("Chris");
    bt.insert("Pooh");
    bt.insert("Kanga");
    
    cout << "先序遍历：\n";
    bt.pre();

    return 0;
}