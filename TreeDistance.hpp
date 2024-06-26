#ifndef TreeDistance_hpp
#define TreeDistance_hpp

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Node.hpp"
#include "LabelTree.hpp"
#include <chrono>

using namespace std;

class TreeEditDistance
{
private:
    int insertCost = 1;
    int deleteCost = 1;
    int substituteCost = 1;
    long long operationCount = 0;

    /**
     * Calculates the tree edit distance between two trees.
     *
     * @param T1 Pointer to the root node of the first tree.
     * @param T2 Pointer to the root node of the second tree.
     * @return The tree edit distance between the two trees.
     */
    int treeEditDist(Node *T1, Node *T2, int insertCost, int deleteCost, int substituteCost)
    {

        chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

        operationCount = 0; // Reset operation count
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

        // cout << "T1_nodes: " << T1_nodes.size() << endl;
        //  for (auto node : T1_nodes)
        //      cout << node->getLabel() << " ";
        //  cout << endl;
        // cout << "T2_nodes: " << T2_nodes.size() << endl;
        //  for (auto node : T2_nodes)
        //      cout << node->getLabel() << " ";
        //  cout << endl;

        int n1 = T1_nodes.size();
        int n2 = T2_nodes.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; ++i)
        {
            dp[i][0] = dp[i - 1][0] + deleteCost;
            operationCount++;
        }
        for (int j = 1; j <= n2; ++j)
        {
            dp[0][j] = dp[0][j - 1] + insertCost;
            operationCount++;
        }

        for (int i = 1; i <= n1; ++i)
        {
            for (int j = 1; j <= n2; ++j)
            {
                int cost = (T1_nodes[i - 1]->getLabel() == T2_nodes[j - 1]->getLabel()) ? 0 : substituteCost;
                dp[i][j] = min({dp[i - 1][j] + deleteCost, dp[i][j - 1] + insertCost, dp[i - 1][j - 1] + cost});
                operationCount++;
            }
        }

        chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
        chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout << "Execution time: " << duration.count() << " nanoseconds" << endl;
        cout << "Operation count: " << operationCount << endl;
        return dp[n1][n2];
    }

    /**
     * Calculates the size of the subtree rooted at the given node.
     *
     * @param node The root node of the subtree.
     * @return The size of the subtree.
     */
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

    /**
     * Retrieves the nodes of a tree in post-order traversal.
     *
     * @param node The root node of the tree.
     * @return A vector containing the nodes of the tree in post-order traversal.
     */
    vector<Node *> getPostOrderNodes(Node *node)
    {
        vector<Node *> nodes;
        if (node)
            postOrder(node, nodes);
        return nodes;
    }

    /**
     * Traverses the tree in post-order and stores the nodes in a vector.
     *
     * @param node The current node being visited.
     * @param nodes The vector to store the nodes in post-order.
     */
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
    /**
     * Sets the cost of inserting a node.
     *
     * @param cost The cost of inserting a node.
     */
    void setInsertCost(int cost)
    {
        insertCost = cost;
    }

    /**
     * Gets the cost of inserting a node.
     *
     * @return The cost of inserting a node.
     */
    int getInsertCost() const
    {
        return insertCost;
    }

    /**
     * Sets the cost of deleting a node.
     *
     * @param cost The cost of deleting a node.
     */
    void setDeleteCost(int cost)
    {
        deleteCost = cost;
    }

    /**
     * Gets the cost of deleting a node.
     *
     * @return The cost of deleting a node.
     */
    int getDeleteCost() const
    {
        return deleteCost;
    }

    /**
     * Sets the cost of substituting a node.
     *
     * @param cost The cost of substituting a node.
     */
    void setSubstituteCost(int cost)
    {
        substituteCost = cost;
    }

    /**
     * Gets the cost of substituting a node.
     *
     * @return The cost of substituting a node.
     */
    int getSubstituteCost() const
    {
        return substituteCost;
    }

    /**
     * Computes the tree edit distance between two trees.
     *
     * @param tree1 The first tree.
     * @param tree2 The second tree.
     * @return The tree edit distance between the two trees.
     */
    int calculateTreeDistance(LabelTree &tree1, LabelTree &tree2)
    {
        return treeEditDist(tree1.getRoot(), tree2.getRoot(), insertCost, deleteCost, substituteCost);
    }
};

#endif
