//
//  main.cpp
//  310_MinimumHeightTrees
//
//  Created by Jane Jane on 10/6/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
using namespace std;


/*
 
 For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.
 
 Format
 The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
 
 You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 
 Example 1 :
 
 Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 
 0
 |
 1
 / \
 2   3
 
 Output: [1]
 Example 2 :
 
 Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 
 0  1  2
 \ | /
 3
 |
 4
 |
 5
 
 Output: [3, 4]
 */

/*
 Input:
 8
 [[0,1],[1,2],[2,3],[0,4],[4,5],[4,6],[6,7]]
 Output:
 [0,1,4]
 Expected:
 [0]
 */
/*
 i learned how to use iterator in map and set.
 i also learned how to do insert, earse, find using iterator in map and set!!!
 */

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    map<int, set<int>> table;
    map<int, set<int>>::iterator it;
    set<int>::iterator setIt;
    int numOfPairs = (int) edges.size();
    vector<int> finalNodes;
    vector<int> leaveToBeRemoved;
    int nodeCount = n;
    
    if (n == 1) {
        finalNodes.push_back(0);
        return finalNodes;
    }
    if (n == 2) {
        finalNodes.push_back(edges[0].first);
        finalNodes.push_back(edges[0].second);
    }
    //create the table of the tree
    //the table will indicate from node 0 to node n-1, what are the nodes that are connected to each node
    
    //extract the node from each pair and put it onto the table
    for (int i = 0; i < numOfPairs; i++) {
        table[edges[i].first].insert(edges[i].second);
        table[edges[i].second].insert(edges[i].first);
    }

    
    while (nodeCount > 2 || finalNodes.size() > 2) {
        leaveToBeRemoved.clear();
        finalNodes.clear();
        //put the leave that need to be removed onto a vector
        for (it=table.begin(); it != table.end(); it++) {
            if (it->second.size() == 1) {
                leaveToBeRemoved.push_back(it->first);
            }
        }
        //remove the leave nodes from the table
        for (int i = 0; i < leaveToBeRemoved.size(); i++) {
            it = table.find(leaveToBeRemoved[i]);
            table.erase(it);
        }
        
        //number of leave left
        nodeCount = nodeCount - (int)leaveToBeRemoved.size();
        
        //go to the rest of the node to remove the node that needed to be remove
        for (it=table.begin(); it != table.end(); it++) {
            for (int i = 0; i < leaveToBeRemoved.size(); i++)
            {
                setIt = it->second.find(leaveToBeRemoved[i]);
                if (setIt != it->second.end()) {
                    it->second.erase(setIt);
                }
            }
            int cur = it->first;

            finalNodes.push_back(cur);
        }
        
    
    }
    
    return finalNodes;
}
/*n
 /////the following method will exceed the time limit.... so need to solve in the above way
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<set<int>> table (n);
    vector <bool> isRoot (n, true);
    int numOfPairs = (int) edges.size();
    vector<int> finalNodes;
    vector<int> leaveToBeRemoved;
    int nodeCount = n;
 
    if (n == 1) {
        finalNodes.push_back(0);
        return finalNodes;
    }
    if (n == 2) {
        finalNodes.push_back(edges[0].first);
        finalNodes.push_back(edges[0].second);
    }
    //create the table of the tree
    //the table will indicate from node 0 to node n-1, what are the nodes that are connected to each node
 
    //extract the node from each pair and put it onto the table
    for (int i = 0; i < numOfPairs; i++) {
        table[edges[i].first].insert(edges[i].second);
        table[edges[i].second].insert(edges[i].first);
    }
 
 
    while (nodeCount > 2 || finalNodes.size() > 2) {
        leaveToBeRemoved.clear();
        finalNodes.clear();
        //put the leave that need to be removed onto a vector
        for (int leaveNode = 0; leaveNode < n; leaveNode++) {
            if (table[leaveNode].size() == 1) {
                leaveToBeRemoved.push_back(leaveNode);
                isRoot[leaveNode] = false;
            }
        }
        //number of leave left
        nodeCount = nodeCount - (int)leaveToBeRemoved.size();
        //go to the rest of the node to remove the node that needed to be remove
        for (int leaveNode = 0; leaveNode < n; leaveNode++) {
            if (isRoot[leaveNode] == true) {
                for (int removeIndex = 0; removeIndex < leaveToBeRemoved.size(); removeIndex++) {
                    table[leaveNode].erase(leaveToBeRemoved[removeIndex]);
                }
                finalNodes.push_back(leaveNode);
            }
        }
    }
 
    return finalNodes;
}
 */

/*
 Input:
 8
 [[0,1],[1,2],[2,3],[0,4],[4,5],[4,6],[6,7]]
 Output:
 [0,1,4]
 Expected:
 [0]
 */


int main(int argc, const char * argv[]) {
    vector<pair<int, int>> treeIn = {{0, 1}, {1, 2}, {2, 3}, {0, 4}, {4, 5},{4,6}, {6,7}};
    vector<int> ret;
    ret = findMinHeightTrees(8, treeIn);
    
    return 0;
}
