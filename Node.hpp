#ifndef Node_hpp
#define Node_hpp

#include <vector>
#include <string>

using namespace std;

class Node
{
private:
    string label;
    vector<Node *> children;

public:
    Node()
    {
        this->label = "";
    }
    Node(string label)
    {
        this->label = label;
    }
    void addChild(Node *child)
    {
        children.push_back(child);
    }
    void removeNode(Node *child)
    {
        for (int i = 0; i < children.size(); i++)
        {
            if (children[i] == child)
            {
                children.erase(children.begin() + i);
                return;
            }
        }
    }
    Node *findNode(string label)
    {
        if (this->label == label)
        {
            return this;
        }
        for (Node *child : children)
        {
            Node *foundNode = child->findNode(label);
            if (foundNode != nullptr)
            {
                return foundNode;
            }
        }
        return nullptr;
    }
    string getLabel() const
    {
        return label;
    }
    vector<Node *> getChildren() const
    {
        return children;
    }
};

#endif