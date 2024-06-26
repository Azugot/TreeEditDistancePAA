#ifndef Tests_hpp
#define Tests_hpp

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "LabelTree.hpp"
#include "TreeDistance.hpp"
#include "KleinTreeDistance.hpp"

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

            cout << "Given/Expet: " << distance << "/" << expectedDistance << "\n";
            cout << "Test Passed" << endl;
        }
        else
        {
            cout << "Given/Expet: " << distance << "/" << expectedDistance << "\n";
            cout << "Test Failed" << endl;
        }

        tree1.resetTree();
        tree2.resetTree();
    }

    void verifyKlein(LabelTree tree1, LabelTree tree2, int expectedDistance)
    {
        KleinTreeDistance ted;
        int distance = ted.calculateTreeDistance(tree1, tree2);
        if (distance == expectedDistance)
        {

            cout << "Given/Expet: " << distance << "/" << expectedDistance << "\n";
            cout << "Test Passed(KLEIN)" << endl
                 << endl;
        }
        else
        {

            cout << "Given/Expet: " << distance << "/" << expectedDistance << "\n";
            cout << "Test Failed(KLEIN)" << endl
                 << endl;
        }

        tree1.resetTree();
        tree2.resetTree();
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
        verifyKlein(tree1, tree2, 4);

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
        verifyKlein(tree5, tree6, 4);

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
        verifyKlein(tree7, tree8, 3);

        // Test Case 6
        // Tree6 1
        LabelTree tree11("Tree11");
        tree11.addNode("", "P");
        tree11.addNode("P", "Q");
        tree11.addNode("P", "R");
        tree11.addNode("Q", "S");
        tree11.addNode("Q", "T");

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
        verifyKlein(tree15, tree16, 3);

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
        verifyKlein(tree17, tree18, 4);

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

        // Tree8A
        LabelTree tree8A("Tree8A");
        tree8A.addNode("", "F");
        tree8A.addNode("F", "D");
        tree8A.addNode("F", "E");
        tree8A.addNode("D", "A");
        tree8A.addNode("D", "C");
        tree8A.addNode("C", "B");
        tree8A.addNode("E", "G");
        tree8A.addNode("E", "H");

        // Tree8B
        LabelTree tree8B("Tree8B");
        tree8B.addNode("", "F");
        tree8B.addNode("F", "C");
        tree8B.addNode("F", "E");
        tree8B.addNode("C", "D");
        tree8B.addNode("D", "A");
        tree8B.addNode("D", "B");
        tree8B.addNode("E", "G");
        tree8B.addNode("E", "H");
        verify(tree8A, tree8B, 2);
        verifyKlein(tree8A, tree8B, 2);

        LabelTree tree16A("Tree16A");
        tree16A.addNode("", "F");
        tree16A.addNode("F", "D");
        tree16A.addNode("F", "E");
        tree16A.addNode("D", "A");
        tree16A.addNode("D", "C");
        tree16A.addNode("C", "B");
        tree16A.addNode("E", "G");
        tree16A.addNode("E", "H");
        tree16A.addNode("A", "I");
        tree16A.addNode("A", "J");
        tree16A.addNode("B", "K");
        tree16A.addNode("B", "L");
        tree16A.addNode("G", "M");
        tree16A.addNode("G", "N");
        tree16A.addNode("H", "O");
        tree16A.addNode("H", "P");

        // Tree16B
        LabelTree tree16B("Tree16B");
        tree16B.addNode("", "F");
        tree16B.addNode("F", "C");
        tree16B.addNode("F", "E");
        tree16B.addNode("C", "D");
        tree16B.addNode("D", "A");
        tree16B.addNode("D", "B");
        tree16B.addNode("E", "G");
        tree16B.addNode("E", "H");
        tree16B.addNode("A", "I");
        tree16B.addNode("A", "J");
        tree16B.addNode("B", "K");
        tree16B.addNode("B", "L");
        tree16B.addNode("G", "M");
        tree16B.addNode("G", "N");
        tree16B.addNode("H", "O");
        tree16B.addNode("H", "P");
        verify(tree16A, tree16B, 2);
        verifyKlein(tree16A, tree16B, 2);

        // Tree32A
        LabelTree tree32A("Tree32A");
        tree32A.addNode("", "F");
        tree32A.addNode("F", "D");
        tree32A.addNode("F", "E");
        tree32A.addNode("D", "A");
        tree32A.addNode("D", "C");
        tree32A.addNode("C", "B");
        tree32A.addNode("E", "G");
        tree32A.addNode("E", "H");
        tree32A.addNode("A", "I");
        tree32A.addNode("A", "J");
        tree32A.addNode("B", "K");
        tree32A.addNode("B", "L");
        tree32A.addNode("G", "M");
        tree32A.addNode("G", "N");
        tree32A.addNode("H", "O");
        tree32A.addNode("H", "P");
        tree32A.addNode("I", "Q");
        tree32A.addNode("I", "R");
        tree32A.addNode("J", "S");
        tree32A.addNode("J", "T");
        tree32A.addNode("K", "U");
        tree32A.addNode("K", "V");
        tree32A.addNode("L", "W");
        tree32A.addNode("L", "X");
        tree32A.addNode("M", "Y");
        tree32A.addNode("M", "Z");
        tree32A.addNode("N", "8");
        tree32A.addNode("N", "9");
        tree32A.addNode("O", "2");
        tree32A.addNode("O", "4");
        tree32A.addNode("P", "3");
        tree32A.addNode("P", "1");

        // Tree32B
        LabelTree tree32B("Tree32B");
        tree32B.addNode("", "F");
        tree32B.addNode("F", "C");
        tree32B.addNode("F", "E");
        tree32B.addNode("C", "D");
        tree32B.addNode("D", "A");
        tree32B.addNode("D", "B");
        tree32B.addNode("E", "G");
        tree32B.addNode("E", "H");
        tree32B.addNode("A", "I");
        tree32B.addNode("A", "J");
        tree32B.addNode("B", "K");
        tree32B.addNode("B", "L");
        tree32B.addNode("G", "M");
        tree32B.addNode("G", "N");
        tree32B.addNode("H", "O");
        tree32B.addNode("H", "P");
        tree32B.addNode("I", "Q");
        tree32B.addNode("I", "R");
        tree32B.addNode("J", "S");
        tree32B.addNode("J", "T");
        tree32B.addNode("K", "U");
        tree32B.addNode("K", "V");
        tree32B.addNode("L", "W");
        tree32B.addNode("L", "X");
        tree32B.addNode("M", "Y");
        tree32B.addNode("M", "Z");
        tree32B.addNode("N", "8");
        tree32B.addNode("N", "9");
        tree32B.addNode("O", "1");
        tree32B.addNode("O", "0");
        tree32B.addNode("P", "9");
        tree32B.addNode("P", "4");
        verify(tree32A, tree32B, 6);
        verifyKlein(tree32A, tree32B, 6);

        // Tree64A
        LabelTree tree64A("Tree64A");
        tree64A.addNode("", "F");
        tree64A.addNode("F", "1");
        tree64A.addNode("F", "E");
        tree64A.addNode("1", "A");
        tree64A.addNode("1", "C");
        tree64A.addNode("C", "B");
        tree64A.addNode("E", "G");
        tree64A.addNode("E", "H");
        tree64A.addNode("A", "I");
        tree64A.addNode("A", "J");
        tree64A.addNode("B", "K");
        tree64A.addNode("B", "L");
        tree64A.addNode("G", "M");
        tree64A.addNode("G", "N");
        tree64A.addNode("H", "O");
        tree64A.addNode("H", "P");
        tree64A.addNode("I", "Q");
        tree64A.addNode("I", "R");
        tree64A.addNode("J", "S");
        tree64A.addNode("J", "T");
        tree64A.addNode("K", "U");
        tree64A.addNode("K", "V");
        tree64A.addNode("L", "W");
        tree64A.addNode("L", "X");
        tree64A.addNode("M", "Y");
        tree64A.addNode("M", "Z");
        tree64A.addNode("N", "8");
        tree64A.addNode("N", "9");
        tree64A.addNode("O", "1");
        tree64A.addNode("O", "0");
        tree64A.addNode("P", "9");
        tree64A.addNode("P", "4");
        tree64A.addNode("Q", "A");
        tree64A.addNode("Q", "B");
        tree64A.addNode("R", "C");
        tree64A.addNode("R", "D");
        tree64A.addNode("S", "E");
        tree64A.addNode("S", "F");
        tree64A.addNode("T", "G");
        tree64A.addNode("T", "H");
        tree64A.addNode("U", "I");
        tree64A.addNode("U", "J");
        tree64A.addNode("V", "K");
        tree64A.addNode("V", "L");
        tree64A.addNode("W", "M");
        tree64A.addNode("W", "N");
        tree64A.addNode("X", "O");
        tree64A.addNode("X", "P");
        tree64A.addNode("Y", "Q");
        tree64A.addNode("Y", "R");
        tree64A.addNode("Z", "S");
        tree64A.addNode("Z", "T");
        tree64A.addNode("8", "U");
        tree64A.addNode("8", "V");
        tree64A.addNode("9", "W");
        tree64A.addNode("9", "X");
        tree64A.addNode("0", "Y");
        tree64A.addNode("0", "Z");
        tree64A.addNode("4", "1");
        tree64A.addNode("4", "2");
        tree64A.addNode("A", "3");
        tree64A.addNode("A", "4");
        tree64A.addNode("B", "5");
        tree64A.addNode("B", "6");
        tree64A.addNode("C", "7");
        tree64A.addNode("C", "8");

        LabelTree tree64B("Tree64B");
        tree64B.addNode("", "F");
        tree64B.addNode("F", "C");
        tree64B.addNode("F", "E");
        tree64B.addNode("C", "D");
        tree64B.addNode("D", "A");
        tree64B.addNode("D", "B");
        tree64B.addNode("E", "G");
        tree64B.addNode("E", "H");
        tree64B.addNode("A", "I");
        tree64B.addNode("A", "J");
        tree64B.addNode("B", "K");
        tree64B.addNode("B", "L");
        tree64B.addNode("G", "M");
        tree64B.addNode("G", "N");
        tree64B.addNode("H", "O");
        tree64B.addNode("H", "P");
        tree64B.addNode("I", "Q");
        tree64B.addNode("I", "R");
        tree64B.addNode("J", "S");
        tree64B.addNode("J", "T");
        tree64B.addNode("K", "U");
        tree64B.addNode("K", "V");
        tree64B.addNode("L", "W");
        tree64B.addNode("L", "X");
        tree64B.addNode("M", "Y");
        tree64B.addNode("M", "Z");
        tree64B.addNode("N", "8");
        tree64B.addNode("N", "9");
        tree64B.addNode("O", "1");
        tree64B.addNode("O", "0");
        tree64B.addNode("P", "9");
        tree64B.addNode("P", "4");
        tree64B.addNode("Q", "A");
        tree64B.addNode("Q", "B");
        tree64B.addNode("R", "C");
        tree64B.addNode("R", "D");
        tree64B.addNode("S", "E");
        tree64B.addNode("S", "F");
        tree64B.addNode("T", "G");
        tree64B.addNode("T", "H");
        tree64B.addNode("U", "I");
        tree64B.addNode("U", "J");
        tree64B.addNode("V", "K");
        tree64B.addNode("V", "L");
        tree64B.addNode("W", "M");
        tree64B.addNode("W", "N");
        tree64B.addNode("X", "O");
        tree64B.addNode("X", "P");
        tree64B.addNode("Y", "Q");
        tree64B.addNode("Y", "R");
        tree64B.addNode("Z", "S");
        tree64B.addNode("Z", "T");
        tree64B.addNode("8", "U");
        tree64B.addNode("8", "V");
        tree64B.addNode("9", "W");
        tree64B.addNode("9", "X");
        tree64B.addNode("0", "Y");
        tree64B.addNode("0", "Z");
        tree64B.addNode("4", "1");
        tree64B.addNode("4", "2");
        verify(tree64A, tree64B, 8);
        verifyKlein(tree64A, tree64B, 8);

        LabelTree tree128A("Tree128A");
        tree128A.addNode("", "F");
        tree128A.addNode("F", "D1");
        tree128A.addNode("F", "E");
        tree128A.addNode("D1", "A");
        tree128A.addNode("D1", "C");
        tree128A.addNode("C", "B");
        tree128A.addNode("E", "G");
        tree128A.addNode("E", "H");
        tree128A.addNode("A", "I");
        tree128A.addNode("A", "J");
        tree128A.addNode("B", "K");
        tree128A.addNode("B", "L");
        tree128A.addNode("G", "M");
        tree128A.addNode("G", "N");
        tree128A.addNode("H", "O");
        tree128A.addNode("H", "P");
        tree128A.addNode("I", "Q");
        tree128A.addNode("I", "R");
        tree128A.addNode("J", "S");
        tree128A.addNode("J", "T");
        tree128A.addNode("K", "U");
        tree128A.addNode("K", "V");
        tree128A.addNode("L", "W");
        tree128A.addNode("L", "X");
        tree128A.addNode("M", "Y");
        tree128A.addNode("M", "Z");
        tree128A.addNode("N", "8");
        tree128A.addNode("N", "9");
        tree128A.addNode("O", "1");
        tree128A.addNode("O", "0");
        tree128A.addNode("P", "9");
        tree128A.addNode("P", "4");
        tree128A.addNode("Q", "A");
        tree128A.addNode("Q", "B");
        tree128A.addNode("R", "C");
        tree128A.addNode("R", "D");
        tree128A.addNode("S", "E");
        tree128A.addNode("S", "F");
        tree128A.addNode("T", "G");
        tree128A.addNode("T", "H");
        tree128A.addNode("U", "I");
        tree128A.addNode("U", "J");
        tree128A.addNode("V", "K");
        tree128A.addNode("V", "L");
        tree128A.addNode("W", "M");
        tree128A.addNode("W", "N");
        tree128A.addNode("X", "O");
        tree128A.addNode("X", "P");
        tree128A.addNode("Y", "Q");
        tree128A.addNode("Y", "R");
        tree128A.addNode("Z", "S");
        tree128A.addNode("Z", "T");
        tree128A.addNode("8", "U");
        tree128A.addNode("8", "V");
        tree128A.addNode("9", "W");
        tree128A.addNode("9", "X");
        tree128A.addNode("0", "Y");
        tree128A.addNode("0", "Z");
        tree128A.addNode("4", "1");
        tree128A.addNode("4", "2");
        tree128A.addNode("A", "3");
        tree128A.addNode("A", "4");
        tree128A.addNode("B", "5");
        tree128A.addNode("B", "6");
        tree128A.addNode("C", "7");
        tree128A.addNode("C", "8");
        tree128A.addNode("D", "9");
        tree128A.addNode("D", "0");
        tree128A.addNode("E", "1");
        tree128A.addNode("E", "2");
        tree128A.addNode("F", "3");
        tree128A.addNode("F", "4");
        tree128A.addNode("G", "5");
        tree128A.addNode("G", "6");
        tree128A.addNode("H", "7");
        tree128A.addNode("H", "8");
        tree128A.addNode("I", "9");
        tree128A.addNode("I", "A");
        tree128A.addNode("J", "B");
        tree128A.addNode("J", "C");
        tree128A.addNode("K", "D");
        tree128A.addNode("K", "E");
        tree128A.addNode("L", "F");
        tree128A.addNode("L", "G");
        tree128A.addNode("M", "H");
        tree128A.addNode("M", "I");
        tree128A.addNode("N", "J");
        tree128A.addNode("N", "K");
        tree128A.addNode("O", "L");
        tree128A.addNode("O", "M");
        tree128A.addNode("P", "N");
        tree128A.addNode("P", "O");
        tree128A.addNode("Q", "P");
        tree128A.addNode("Q", "Q");
        tree128A.addNode("R", "R");
        tree128A.addNode("R", "S");
        tree128A.addNode("S", "T");
        tree128A.addNode("S", "U");
        tree128A.addNode("T", "V");
        tree128A.addNode("T", "W");
        tree128A.addNode("U", "X");
        tree128A.addNode("U", "Y");
        tree128A.addNode("V", "Z");
        tree128A.addNode("V", "8");
        tree128A.addNode("W", "9");
        tree128A.addNode("W", "0");
        tree128A.addNode("X", "1");
        tree128A.addNode("X", "2");
        tree128A.addNode("Y", "3");
        tree128A.addNode("Y", "4");
        tree128A.addNode("Z", "5");
        tree128A.addNode("Z", "6");

        LabelTree tree128B("Tree128B");
        tree128B.addNode("", "F");
        tree128B.addNode("F", "C");
        tree128B.addNode("F", "E");
        tree128B.addNode("C", "D");
        tree128B.addNode("D", "A");
        tree128B.addNode("D", "B");
        tree128B.addNode("E", "G");
        tree128B.addNode("E", "H");
        tree128B.addNode("A", "I");
        tree128B.addNode("A", "J");
        tree128B.addNode("B", "K");
        tree128B.addNode("B", "L");
        tree128B.addNode("G", "M");
        tree128B.addNode("G", "N");
        tree128B.addNode("H", "O");
        tree128B.addNode("H", "P");
        tree128B.addNode("I", "Q");
        tree128B.addNode("I", "R");
        tree128B.addNode("J", "S");
        tree128B.addNode("J", "T");
        tree128B.addNode("K", "U");
        tree128B.addNode("K", "V");
        tree128B.addNode("L", "W");
        tree128B.addNode("L", "X");
        tree128B.addNode("M", "Y");
        tree128B.addNode("M", "Z");
        tree128B.addNode("N", "8");
        tree128B.addNode("N", "9");
        tree128B.addNode("O", "1");
        tree128B.addNode("O", "0");
        tree128B.addNode("P", "9");
        tree128B.addNode("P", "4");
        tree128B.addNode("Q", "A");
        tree128B.addNode("Q", "B");
        tree128B.addNode("R", "C");
        tree128B.addNode("R", "D");
        tree128B.addNode("S", "E");
        tree128B.addNode("S", "F");
        tree128B.addNode("T", "G");
        tree128B.addNode("T", "H");
        tree128B.addNode("U", "I");
        tree128B.addNode("U", "J");
        tree128B.addNode("V", "K");
        tree128B.addNode("V", "L");
        tree128B.addNode("W", "M");
        tree128B.addNode("W", "N");
        tree128B.addNode("X", "O");
        tree128B.addNode("X", "P");
        tree128B.addNode("Y", "Q");
        tree128B.addNode("Y", "R");
        tree128B.addNode("Z", "S");
        tree128B.addNode("Z", "T");
        tree128B.addNode("8", "U");
        tree128B.addNode("8", "V");
        tree128B.addNode("9", "W");
        tree128B.addNode("9", "X");
        tree128B.addNode("0", "Y");
        tree128B.addNode("0", "Z");
        tree128B.addNode("4", "1");
        tree128B.addNode("4", "2");
        tree128B.addNode("A", "3");
        tree128B.addNode("A", "4");
        tree128B.addNode("B", "5");
        tree128B.addNode("B", "6");
        tree128B.addNode("C", "7");
        tree128B.addNode("C", "8");
        tree128B.addNode("D", "9");
        tree128B.addNode("D", "0");
        tree128B.addNode("E", "1");
        tree128B.addNode("E", "2");
        tree128B.addNode("F", "3");
        tree128B.addNode("F", "4");
        tree128B.addNode("G", "5");
        tree128B.addNode("G", "6");
        tree128B.addNode("H", "7");
        tree128B.addNode("H", "8");
        tree128B.addNode("I", "9");
        tree128B.addNode("I", "A");
        tree128B.addNode("J", "B");
        tree128B.addNode("J", "C");
        tree128B.addNode("K", "D");
        tree128B.addNode("K", "E");
        tree128B.addNode("L", "F");
        tree128B.addNode("L", "G");
        tree128B.addNode("M", "H");
        tree128B.addNode("M", "I");
        tree128B.addNode("N", "J");
        tree128B.addNode("N", "K");
        tree128B.addNode("O", "L");
        tree128B.addNode("O", "M");
        tree128B.addNode("P", "N");
        tree128B.addNode("P", "O");
        tree128B.addNode("Q", "P");
        tree128B.addNode("Q", "Q");
        tree128B.addNode("R", "R");
        tree128B.addNode("R", "S");
        tree128B.addNode("S", "T");
        tree128B.addNode("S", "U");
        tree128B.addNode("T", "V");
        tree128B.addNode("T", "W");
        tree128B.addNode("U", "X");
        tree128B.addNode("U", "Y");
        tree128B.addNode("V", "Z");
        tree128B.addNode("V", "8");
        tree128B.addNode("W", "9");
        tree128B.addNode("W", "0");
        verify(tree128A, tree128B, 16);
        verifyKlein(tree128A, tree128B, 16);
    }
};

#endif