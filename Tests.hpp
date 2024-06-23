#ifndef Tests_hpp
#define Tests_hpp

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "LabelTree.hpp"
#include "TreeDistance.hpp"

using namespace std;

class Tests
{
public:
    void runTests()
    {
        cout << "Running tests..." << endl;
        runTreeSamples();
    }

    void verify(LabelTree tree1, LabelTree tree2, int expectedDistance)
    {
        TreeEditDistance ted;
        int distance = ted.calculateTreeDistance(tree1, tree2);
        if (distance == expectedDistance)
        {
            cout << "Test Passed" << endl;
            cout << "Given/Expet: " << distance << "/" << expectedDistance << "\n"
                 << endl;
        }
        else
        {
            cout << "Test Failed" << endl;
            cout << "Given/Expet: " << distance << "/" << expectedDistance << "\n"
                 << endl;
        }
    }

    void runTreeSamples()
    {
        TreeEditDistance ted;

        // Test Case 1
        // Tree1 3
        LabelTree tree1("Tree1");
        tree1.addNode("", "A");
        tree1.addNode("A", "B");
        tree1.addNode("A", "C");
        tree1.addNode("B", "D");
        tree1.addNode("B", "E");

        LabelTree tree2("Tree2");
        tree2.addNode("", "A");
        tree2.addNode("A", "B");
        tree2.addNode("A", "E");
        tree2.addNode("E", "C");
        tree2.addNode("E", "D");

        verify(tree1, tree2, 4);
        tree1.resetTree();
        tree2.resetTree();

        // Test Case 2
        // Tree2 2
        LabelTree tree3("Tree3");
        tree3.addNode("", "X");
        tree3.addNode("X", "Y");
        tree3.addNode("X", "Z");
        tree3.addNode("Y", "A");
        tree3.addNode("Z", "B");

        LabelTree tree4("Tree4");
        tree4.addNode("", "X");
        tree4.addNode("X", "Y");
        tree4.addNode("X", "B");
        tree4.addNode("Y", "A");
        tree4.addNode("B", "Z");
        verify(tree3, tree4, 2);
        tree3.resetTree();
        tree4.resetTree();

        // Test Case 3
        // Tree3 4
        LabelTree tree5("Tree5");
        tree5.addNode("", "M");
        tree5.addNode("M", "N");
        tree5.addNode("M", "O");
        tree5.addNode("N", "P");
        tree5.addNode("N", "Q");
        tree5.addNode("Q", "R");
        tree5.addNode("Q", "S");

        LabelTree tree6("Tree6");
        tree6.addNode("", "M");
        tree6.addNode("M", "N");
        tree6.addNode("M", "Q");
        tree6.addNode("Q", "P");
        tree6.addNode("Q", "R");
        tree6.addNode("Q", "S");
        tree6.addNode("R", "O");
        verify(tree5, tree6, 4);
        tree5.resetTree();
        tree6.resetTree();

        // Test Case 4
        // Tree4 2
        LabelTree tree7("Tree7");
        tree7.addNode("", "F");
        tree7.addNode("F", "G");
        tree7.addNode("F", "H");
        tree7.addNode("G", "I");
        tree7.addNode("G", "J");

        LabelTree tree8("Tree8");
        tree8.addNode("", "F");
        tree8.addNode("F", "G");
        tree8.addNode("F", "I");
        tree8.addNode("I", "H");
        tree8.addNode("H", "J");
        verify(tree7, tree8, 3);
        tree7.resetTree();
        tree8.resetTree();

        // Test Case 5
        // Tree5 3
        LabelTree tree9("Tree9");
        tree9.addNode("", "K");
        tree9.addNode("K", "L");
        tree9.addNode("K", "M");
        tree9.addNode("L", "N");
        tree9.addNode("L", "O");

        LabelTree tree10("Tree10");
        tree10.addNode("", "K");
        tree10.addNode("K", "L");
        tree10.addNode("K", "O");
        tree10.addNode("O", "N");
        tree10.addNode("O", "M");
        verify(tree9, tree10, 4);
        tree9.resetTree();
        tree10.resetTree();

        // Test Case 6
        // Tree6 1
        LabelTree tree11("Tree11");
        tree11.addNode("", "P");
        tree11.addNode("P", "Q");
        tree11.addNode("P", "R");
        tree11.addNode("Q", "S");
        tree11.addNode("Q", "T");

        LabelTree tree12("Tree12");
        tree12.addNode("", "P");
        tree12.addNode("P", "Q");
        tree12.addNode("P", "S");
        tree12.addNode("S", "R");
        tree12.addNode("S", "T");
        verify(tree11, tree12, 4);
        tree11.resetTree();
        tree12.resetTree();

        // Test Case 7
        // Tree7 2
        LabelTree tree13("Tree13");
        tree13.addNode("", "U");
        tree13.addNode("U", "V");
        tree13.addNode("U", "W");
        tree13.addNode("V", "X");
        tree13.addNode("V", "Y");

        LabelTree tree14("Tree14");
        tree14.addNode("", "U");
        tree14.addNode("U", "V");
        tree14.addNode("U", "X");
        tree14.addNode("X", "W");
        tree14.addNode("W", "Y");
        verify(tree13, tree14, 3);
        tree13.resetTree();
        tree14.resetTree();

        // Test Case 8
        // Tree8 2
        LabelTree tree15("Tree15");
        tree15.addNode("", "Z");
        tree15.addNode("Z", "A1");
        tree15.addNode("Z", "B1");
        tree15.addNode("A1", "C1");
        tree15.addNode("A1", "D1");

        LabelTree tree16("Tree16");
        tree16.addNode("", "Z");
        tree16.addNode("Z", "A1");
        tree16.addNode("Z", "C1");
        tree16.addNode("C1", "B1");
        tree16.addNode("B1", "D1");
        verify(tree15, tree16, 3);
        tree15.resetTree();
        tree16.resetTree();

        // Test Case 9
        // Tree9 1
        LabelTree tree17("Tree17");
        tree17.addNode("", "E1");
        tree17.addNode("E1", "F1");
        tree17.addNode("E1", "G1");
        tree17.addNode("F1", "H1");
        tree17.addNode("F1", "I1");

        LabelTree tree18("Tree18");
        tree18.addNode("", "E1");
        tree18.addNode("E1", "F1");
        tree18.addNode("E1", "H1");
        tree18.addNode("H1", "G1");
        tree18.addNode("H1", "I1");
        verify(tree17, tree18, 4);
        tree17.resetTree();
        tree18.resetTree();

        // Test Case 10
        // Tree10 3
        LabelTree tree19("Tree19");
        tree19.addNode("", "J1");
        tree19.addNode("J1", "K1");
        tree19.addNode("J1", "L1");
        tree19.addNode("K1", "M1");
        tree19.addNode("K1", "N1");

        LabelTree tree20("Tree20");
        tree20.addNode("", "J1");
        tree20.addNode("J1", "K1");
        tree20.addNode("J1", "N1");
        tree20.addNode("N1", "M1");
        tree20.addNode("N1", "L1");
        verify(tree19, tree20, 4);
        tree19.resetTree();
        tree20.resetTree();
    }
};

#endif