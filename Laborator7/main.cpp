#include <iostream>
#include "Tree.h"
#include "TemperaturesLiterals.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    cout << "---Temperature---" << endl;

    cout << "300 Kelvin in Celsius: " << a << "°C\n";
    cout << "120 Fahrenheit in Celsius: " << b << "°C\n";

    cout << "-----Tree-----" << endl;
    Tree<string> myTree;
    auto* root = myTree.add_node(nullptr, "Root");
    myTree.add_node(root, "Banana");
    myTree.add_node(root, "Apple");
    myTree.add_node(root, "Cherry");

    cout << "\nBefore sort:\n";
    myTree.print();

    myTree.sort(root);

    cout << "\nAfter sort:\n";
    myTree.print();

    cout << "\nTotal nodes in tree: " << myTree.count(nullptr) << "\n";

    return 0;
}