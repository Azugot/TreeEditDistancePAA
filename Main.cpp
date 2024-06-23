#include <iostream>
#include "TreeDistance.hpp"
#include "LabelTree.hpp"
#include "Tests.hpp"

using namespace std;

int main()
{
    // Create trees for comparison


    //f(d(a c(b)) e)" e "f(c(d(a b)) e)
    Tests t = Tests();
    t.runTests();
    LabelTree tree1("Tree1");
    tree1.addNode("", "F");
    tree1.addNode("F", "D");
    tree1.addNode("F", "E");
    tree1.addNode("D", "A");
    tree1.addNode("D", "C");
    tree1.addNode("C", "B");

    LabelTree tree2("Tree2");
    tree2.addNode("", "F");
    tree2.addNode("F", "C");
    tree2.addNode("F", "E");
    tree2.addNode("C", "D");
    tree2.addNode("D", "A");
    tree2.addNode("D", "B");

    // Create TreeEditDistance object
    TreeEditDistance ted;
    //int distance = ted.calculateTreeDistance(tree1, tree2);
    //cout << "Tree Edit Distance: " << distance << endl;
    return 0;
}