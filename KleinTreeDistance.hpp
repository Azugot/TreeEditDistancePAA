#ifndef KleinTreeDistance_hpp
#define KleinTreeDistance_hpp

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "Node.hpp"
#include "LabelTree.hpp"

using namespace std;

class KleinTreeDistance
{
private:
    int insertCost = 1;
    int deleteCost = 1;
    int substituteCost = 1;
    long long operationCount = 0;

    struct Key
    {
        int i, j;
        bool operator==(const Key &other) const
        {
            return (i == other.i && j == other.j);
        }
    };

    struct KeyHasher
    {
        size_t operator()(const Key &k) const
        {
            return ((hash<int>()(k.i)
                     ^ (hash<int>()(k.j) << 1)) >> 1);
        }
    };

    unordered_map<Key, int, KeyHasher> dp;

    int treeEditDist(Node *T1, Node *T2)
    {
        if (!T1)
        {
            operationCount++;
            return getSubtreeSize(T2) * insertCost;
        }
        if (!T2)
        {
            operationCount++;
            return getSubtreeSize(T1) * deleteCost;
        }

        vector<Node *> T1_nodes = getPostOrderNodes(T1);
        vector<Node *> T2_nodes = getPostOrderNodes(T2);

        int n1 = T1_nodes.size();
        int n2 = T2_nodes.size();

        vector<int> dpPrev(n2 + 1, 0);
        vector<int> dpCurr(n2 + 1, 0);

        for (int j = 1; j <= n2; ++j)
        {
            dpPrev[j] = dpPrev[j - 1] + insertCost;
            operationCount++;
        }

        for (int i = 1; i <= n1; ++i)
        {
            dpCurr[0] = dpPrev[0] + deleteCost;
            for (int j = 1; j <= n2; ++j)
            {
                int cost = (T1_nodes[i - 1]->getLabel() == T2_nodes[j - 1]->getLabel()) ? 0 : substituteCost;
                dpCurr[j] = min({dpCurr[j - 1] + insertCost, dpPrev[j] + deleteCost, dpPrev[j - 1] + cost});
                operationCount++;
            }
            dpPrev = dpCurr;
        }

        return dpCurr[n2];
    }

    int getSubtreeSize(Node *node)
    {
        operationCount++;
        if (!node)
            return 0;
        int size = 1;
        for (Node *child : node->getChildren())
        {
            size += getSubtreeSize(child);
        }
        return size;
    }

    vector<Node *> getPostOrderNodes(Node *node)
    {
        vector<Node *> nodes;
        if (node)
            postOrder(node, nodes);
        return nodes;
    }

    void postOrder(Node *node, vector<Node *> &nodes)
    {
        for (Node *child : node->getChildren())
        {
            postOrder(child, nodes);
        }
        nodes.push_back(node);
        operationCount++;
    }

public:
    void setInsertCost(int cost)
    {
        insertCost = cost;
    }

    int getInsertCost() const
    {
        return insertCost;
    }

    void setDeleteCost(int cost)
    {
        deleteCost = cost;
    }

    int getDeleteCost() const
    {
        return deleteCost;
    }

    void setSubstituteCost(int cost)
    {
        substituteCost = cost;
    }

    int getSubstituteCost() const
    {
        return substituteCost;
    }

    int calculateTreeDistance(LabelTree &tree1, LabelTree &tree2)
    {
        operationCount = 0;
        int distance = treeEditDist(tree1.getRoot(), tree2.getRoot());
        
        cout << "Number of operations(KLEIN): " << operationCount << endl;
        
        return distance;
    }
};

#endif
