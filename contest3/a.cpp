#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


typedef struct Node {
    std::vector<int> childrenIds;
    int depth;
    int parentId;
    int branchDepth;
} Node;


void updateParentBranchDepth(Node treeNodes[], int childId) {
    while (treeNodes[childId].parentId != childId) {
        if (treeNodes[treeNodes[childId].parentId].branchDepth <= treeNodes[childId].branchDepth) {
            treeNodes[treeNodes[childId].parentId].branchDepth = treeNodes[childId].branchDepth + 1;
        }
        
        childId = treeNodes[childId].parentId;
    }
}


int main() {
    int treeSize;
    std::cin >> treeSize;

    Node treeNodes[treeSize];
    treeNodes[0].depth = 0;
    treeNodes[0].parentId = 0;
    treeNodes[0].branchDepth = 0;
    std::vector<int> leafs = {0};
    int maxDepth = 0;
    for (int nodeId = 1; nodeId < treeSize; nodeId++) {
        std::cin >> treeNodes[nodeId].parentId;
        treeNodes[nodeId].depth = treeNodes[treeNodes[nodeId].parentId].depth + 1;
        treeNodes[treeNodes[nodeId].parentId].childrenIds.push_back(nodeId);
        treeNodes[nodeId].branchDepth = 0;
        
        /*std::cout << "BAM BAM: ";
        std::cout << treeNodes[treeNodes[nodeId].parentId].branchDepth;
        std::cout << " ";
        std::cout << treeNodes[nodeId].parentId << std::endl;*/
        
        if (treeNodes[nodeId].depth > maxDepth) {
            maxDepth = treeNodes[nodeId].depth;
        }
    }
    std::cout << maxDepth;
    std::cout << " ";

    
    for (int nodeId = 0; nodeId < treeSize; nodeId++) {
        if (treeNodes[nodeId].branchDepth == 0) {
            updateParentBranchDepth(treeNodes, nodeId);
        }
    }
    
    
    /*std::cout << std::endl;
    for (int nodeId = 0; nodeId < treeSize - 1; nodeId++) {
        std::cout << treeNodes[nodeId].branchDepth << " ";
    }
    std::cout << treeNodes[treeSize-1].branchDepth << std::endl;*/
    

    int maxDistance = 0;
    std::queue<int> nodeQueue;
    nodeQueue.push(0); 
    while (nodeQueue.size() > 0) {
        int maxDepthId = -1;
        int maxDepth = 0;
        int prevMaxDepthId;
        int prevMaxDepth = 0;
        for (int id : treeNodes[nodeQueue.front()].childrenIds) {
            if (treeNodes[id].branchDepth + 1 > maxDepth) {
                prevMaxDepth = maxDepth;
                prevMaxDepthId = maxDepthId;
                maxDepth = treeNodes[id].branchDepth + 1;
                maxDepthId = id;
            } else if (treeNodes[id].branchDepth + 1 > prevMaxDepth) {
                prevMaxDepth = treeNodes[id].branchDepth + 1;
                prevMaxDepthId = id;
            }
        }

        /*std::cout << std::endl;
        std::cout << "HOHOL: ";
        std::cout << maxDepth;
        std::cout << " ";
        std::cout << prevMaxDepth;
        std::cout << " ";
        std::cout << maxDepthId << std::endl;*/
        if (maxDepth + prevMaxDepth > maxDistance) {
            maxDistance = maxDepth + prevMaxDepth;
        }

        if (maxDistance < (maxDepth - 1) * 2) {
            nodeQueue.push(maxDepthId);
            if (maxDepth == prevMaxDepth) {
                nodeQueue.push(prevMaxDepthId);
            }
        }
        nodeQueue.pop();
    }
    std::cout << maxDistance << std::endl;

    for (int nodeId = 0; nodeId < treeSize - 1; nodeId++) {
        std::cout << treeNodes[nodeId].depth << " ";
    }
    std::cout << treeNodes[treeSize-1].depth;
}