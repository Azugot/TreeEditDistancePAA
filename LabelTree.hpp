#ifndef LabelTree_hpp
#define LabelTree_hpp


#include <String>
#include "Node.hpp"
#include <iostream>
using namespace std;

class LabelTree
{
private:
    string name;
    Node *root;

public:
    /**
     * @brief Constructs a new LabelTree object with the given name.
     *
     * @param name The name of the LabelTree.
     */
    LabelTree(string name)
    {
        this->name = name;
        this->root = new Node();
    }

    /**
     * Returns the root node of the tree.
     *
     * @return A pointer to the root node of the tree.
     */
    Node *getRoot() const
    {
        return root;
    }

    /**
     * Adds a new node to the tree with the specified parent and child labels.
     * If the parent node is not found, an error message is displayed and the function returns.
     *
     * @param parentLabel The label of the parent node.
     * @param childLabel The label of the child node to be added.
     */
    void addNode(string parentLabel, string childLabel)
    {
        Node *parentNode = root->findNode(parentLabel);
        if (parentNode == nullptr)
        {
            cout << "Parent node not found" << endl;
            return;
        }
        Node *childNode = new Node(childLabel);
        parentNode->addChild(childNode);
    }

    /**
     * Removes a child node with the specified label from the parent node with the specified label.
     * If either the parent node or the child node is not found, an error message is displayed.
     *
     * @param parentLabel The label of the parent node.
     * @param childLabel The label of the child node to be removed.
     */
    void removeNode(string parentLabel, string childLabel)
    {
        Node *parentNode = root->findNode(parentLabel);
        if (parentNode == nullptr)
        {
            cout << "Parent node not found" << endl;
            return;
        }
        Node *childNode = parentNode->findNode(childLabel);
        if (childNode == nullptr)
        {
            cout << "Child node not found" << endl;
            return;
        }
        parentNode->removeNode(childNode);
    }

    /**
     * Prints the labels of the tree nodes in a hierarchical structure.
     *
     * @param node The root node of the tree to be printed.
     * @param depth The current depth of the node in the tree (default is 0).
     */
    void printTree(Node *node, int depth = 0) const
    {
        if (node == nullptr)
            return;
        for (int i = 0; i < depth; ++i)
            cout << "  ";
        cout << node->getLabel() << endl;
        for (auto child : node->getChildren())
        {
            printTree(child, depth + 1);
        }
    }
};

#endif