// File: TreeEditDistance.hpp

#ifndef TreeDistance_hpp
#define TreeDistance_hpp

#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Node.hpp"
#include "LabelTree.hpp"

using namespace std;

class TreeEditDistance
{
private:
    /**
     * Calculates the tree edit distance between two trees.
     *
     * @param T1 Pointer to the root node of the first tree.
     * @param T2 Pointer to the root node of the second tree.
     * @return The tree edit distance between the two trees.
     */

    int treeEditDist(Node *T1, Node *T2)
    {
        auto start = chrono::high_resolution_clock::now();
        if (!T1)
            return getSubtreeSize(T2);
        if (!T2)
            return getSubtreeSize(T1);

        vector<Node *> T1_nodes = getPostOrderNodes(T1);

        vector<Node *> T2_nodes = getPostOrderNodes(T2);

        int n1 = T1_nodes.size();
        int n2 = T2_nodes.size();

        // cout << "n1: " << n1 << " n2: " << n2 << endl;

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; ++i)
            dp[i][0] = dp[i - 1][0] + 1;
        for (int j = 1; j <= n2; ++j)
            dp[0][j] = dp[0][j - 1] + 1;

        // Debugging: Print post-order node labels
        cout << "T1 post-order: ";
        for (auto node : T1_nodes)
        {
            cout << node->getLabel() << " ";
        }
        cout << endl;

        cout << "T2 post-order: ";
        for (auto node : T2_nodes)
        {
            cout << node->getLabel() << " ";
        }
        cout << endl;

        for (int i = 1; i <= n1; ++i)
        {
            for (int j = 1; j <= n2; ++j)
            {
                int cost = (T1_nodes[i - 1]->getLabel() == T2_nodes[j - 1]->getLabel()) ? 0 : 1;
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost});
            }
        }

        // Debugging: Print DP table
        // cout << "DP table:" << endl;
        // for (int i = 0; i <= n1; ++i)
        //{
        //    for (int j = 0; j <= n2; ++j)
        //    {
        //        cout << dp[i][j] << " ";
        //    }
        //    cout << endl;
        //}
        //

        // Stop the clock
        chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

        // Calculate duration
        chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(end - start);

        cout << "Execution time: " << duration.count() << " milliseconds" << endl;
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
    }

public:
    /**
     * Computes the tree edit distance between two trees.
     *
     * @param tree1 The first tree.
     * @param tree2 The second tree.
     * @return The tree edit distance between the two trees.
     */
    int calculateTreeDistance(LabelTree &tree1, LabelTree &tree2)
    {
        return treeEditDist(tree1.getRoot(), tree2.getRoot());
    }
};

#endif
