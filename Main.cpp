#include <iostream>
#include "TreeDistance.hpp"
#include "LabelTree.hpp"

using namespace std;

int main()
{
    // Create trees for comparison
    LabelTree tree1("Tree1");
    tree1.addNode("", "A");
    tree1.addNode("A", "B");
    tree1.addNode("B", "C");

    LabelTree tree2("Tree2");
    tree2.addNode("", "A");
    tree2.addNode("A", "B");
    tree2.addNode("B", "C");

    // Create TreeEditDistance object
    TreeEditDistance ted;
    int distance = ted.compute(tree1, tree2);
    cout << "Tree Edit Distance: " << distance << endl;
    return 0;
}