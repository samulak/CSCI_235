/**
Author: Adam Samulak
Class: CSCI 235
Date: April 27, 2020
Instructor: Wole Oyekoya
Assignment: Project 4
**/

// @file Solutions.cpp
#include "Maze.cpp"
#include<map>
#include <stack>
#include <queue>
#include <cstdlib>

namespace solutions
{

int getNumberOfWalls(MazeNode *a_node)
{
    int wall_counter = 0;
    for (directions::nesw dir = directions::NORTH; dir < directions::EAST; dir = directions::nesw(dir + 1))
    {
        if (a_node->getDirectionNode(dir) == nullptr || a_node->getDirectionNode(dir)->isWall() || a_node->getDirectionNode(dir)->isVisited())
        {
            wall_counter++;
        }
    }
    return wall_counter;
}

bool canTravel(MazeNode *a_node)
{
    if (a_node->isVisited() || a_node->isWall())
    {
        return false;
    }
    return true;
}

/*******************Helper Function***********************/
/*********************************************************/

/** checkNeigborNodes: examines neighoring nodes for not-visited nodes
Precondition: MazeNode object exists
Postcondition: Returns a pointer to a not-visited node or if such does not exists
original current_node that was passed as parameter is returned.
**/
MazeNode* checkNeigborNodes(MazeNode *current_node, Maze &a_maze){
  //Inspects nodes in N E S W directions order
  if (current_node->getPos().second != 0 && canTravel(current_node->getDirectionNode(directions::NORTH))) {
    current_node = current_node->getDirectionNode(directions::NORTH);
    return current_node;
  } else if (current_node->getPos().first != a_maze.getLength()-1 && canTravel(current_node->getDirectionNode(directions::EAST))) {
    current_node = current_node->getDirectionNode(directions::EAST);
    return current_node;
  } else if (current_node->getPos().second != a_maze.getWidth()-1 && canTravel(current_node->getDirectionNode(directions::SOUTH))) {
    current_node = current_node->getDirectionNode(directions::SOUTH);
    return current_node;
  } else if (current_node->getPos().first != 0 && canTravel(current_node->getDirectionNode(directions::WEST))) {
    current_node = current_node->getDirectionNode(directions::WEST);
    return current_node;
  }// end if
  return current_node;
}// end of checkNeigborNodes

/** solveDFS: Depth-first search explores a single branch before backtracking
Precondition: Maze object exists
Postcondition: Returns a vector with a ordered sequence of nodes starting from
the first MazeNode and ending with the last MazeNode of the maze.Thus, producing
a solution to the maze.
**/

std::vector<MazeNode> solveDFS(Maze &a_maze)
{
  // Stack tracking visited nodes
  std::stack<MazeNode*> nodeStack;
  a_maze.getCurrentNode()->setVisited();
  // Add the first node to a stack
  nodeStack.push(a_maze.getCurrentNode());
  // Output vector
  std::vector<MazeNode> pathOutput;
  // Temporary pointer
  MazeNode *firstStack;

  // Loop searching a full branch before backtracking
  while (!nodeStack.empty()) {
    firstStack = nodeStack.top();
    firstStack = checkNeigborNodes(firstStack, a_maze);
    // Cheking for not visited MazeNodes if not found backtrack to the previous one
    if (!firstStack->isVisited()) {
      firstStack->setVisited();
      nodeStack.push(firstStack);
    }else{
      nodeStack.pop();
    }// end if
    //Once the lastnode is reached MazeNodes are copied from the stack to the vector
    if (nodeStack.top() == a_maze.getLastNode()) {
      while (!nodeStack.empty()) {
        pathOutput.insert(pathOutput.begin(),*nodeStack.top());
        nodeStack.pop();
      }// end while
    }// end if
  }// end while
  return pathOutput;
}// end of solverDFS

/** solveBFS: Breath-first search explores all the neighbors of the MazeNodes before
moving to the next MazeNode
Precondition: Maze object exists
Postcondition: Returns a vector with a ordered sequence of nodes starting from
the first MazeNode and ending with the last MazeNode of the maze.Thus, producing
a solution to the maze.
**/

std::vector<MazeNode> solveBFS(Maze &a_maze)
{
  // Map allowing for easy backtracking
  std::map<MazeNode*, MazeNode*> nodeMap;
  // Sets the start node to visited
  a_maze.getCurrentNode()->setVisited();
  // Output vector
  std::vector<MazeNode> pathOutput;
  // queue for tracking nodes to create pairs in the nodeMap
  std::queue <MazeNode*> vertexQueue;
  // Temporary pointer
  MazeNode *keyNode;
  // Copy the starting MazeNode on to the queue
  vertexQueue.push(a_maze.getCurrentNode());

  // Nested loop exploring all neigboring MazeNodes first and placing them in a nodeMap
  while (a_maze.getCurrentNode() != a_maze.getLastNode()) {
    vertexQueue.pop();
    while (checkNeigborNodes(a_maze.getCurrentNode(), a_maze) != a_maze.getCurrentNode()) {
      keyNode = checkNeigborNodes(a_maze.getCurrentNode(), a_maze);
      keyNode->setVisited();
      vertexQueue.push(keyNode);
      nodeMap.insert(std::pair<MazeNode*,MazeNode*>(keyNode,a_maze.getCurrentNode()));
    }// end while
    a_maze.setCurrentNode(vertexQueue.front());
  }// end while

  // Iterator nodeMapIt is used to traverse the nodeMap in order to backtrack
  std::map<MazeNode*, MazeNode*>::iterator nodeMapIt = nodeMap.find(a_maze.getLastNode());
  // Loop traverses the nodeMapIt in order to copy MazeNodes into the output vector.
  // It starts from the lastNode to the firstNode
  while (nodeMapIt->second != a_maze.getFirstNode()) {
    pathOutput.insert(pathOutput.begin(),*nodeMapIt->first);
    nodeMapIt = nodeMap.find(nodeMapIt->second);
  }// end while
  pathOutput.insert(pathOutput.begin(),*nodeMapIt->first);
  pathOutput.insert(pathOutput.begin(),*nodeMapIt->second);

  return pathOutput;
}// end of solveBFS

/** solveDEF: Dead-End-Filling search finds dead ends in the maze and fills them
with walls. That leaves only one path that leads from firstNode to lastNode.
Precondition: Maze object exists
Postcondition: Returns a vector with a ordered sequence of nodes starting from
the first MazeNode and ending with the last MazeNode of the maze.Thus, producing
a solution to the maze.
**/

std::vector<MazeNode> solveDEF(Maze &a_maze)
{
// Queue for keeping track of them
std::queue <MazeNode*> vertexQueue;
// Pair used to look for the dead ends in the maze
std::pair<int,int> nodePair;
// Temporary pointer
MazeNode *checkNode;

// Nested loop finds all MazeNodes that are dead ends
  for (size_t col = 0; col < a_maze.getWidth(); col++) {
    for (size_t row = 0; row < a_maze.getLength(); row++) {
      nodePair.first = row;
      nodePair.second = col;
      checkNode = a_maze.contains(nodePair);
      int wall = 0;
      for (size_t dir = 0; dir < 4; dir++) {
        // Function checks wether or not a neigboring node is a wall
        if (checkNode->getPos().second == 0 || checkNode->getPos().first == a_maze.getLength()-1 || checkNode->getPos().second == a_maze.getWidth()-1 ||checkNode->getPos().first == 0) {
          break;
        }else{
          if (true == checkNode->getDirectionNode(directions::nesw(dir))->isWall() && checkNode->isWall() != true) {
            wall++;
          }// end if
        }// end if
      }//end for
      // If a MazeNode has 3 walls (dead end) add it to a vertex stack
      if (wall == 3) {
        vertexQueue.push(checkNode);
      }// end if
      wall = 0;
    }// end for
  }// end for

// Loop filling the dead ends with walls.
// vertexQueue contains all the dead ends
  while (!vertexQueue.empty()) {
    checkNode = vertexQueue.front();
    checkNode->setWall();
    vertexQueue.pop();
    MazeNode *testNode = checkNode;
    checkNode = checkNeigborNodes(checkNode, a_maze);
    // Function checks for number of neigboring nodes for walls
      if (checkNode != testNode) {
        int wall = 0;
        for (size_t dir = 0; dir < 4; dir++) {
          if (checkNode->getPos().second == 0 || checkNode->getPos().first == a_maze.getLength()-1 || checkNode->getPos().second == a_maze.getWidth()-1 ||checkNode->getPos().first == 0) {
            break;
          }else{
            if (true == checkNode->getDirectionNode(directions::nesw(dir))->isWall() && checkNode->isWall() != true) {
              wall++;
            }// end if
          }// end if
        }// end for
        // If MazeNode has 3 walls neigboring it, chnge it to a wall.
        if (wall == 3) {
          checkNode->setWall();
          vertexQueue.push(checkNode);
        }// end if
    }// end if
  }// end while

  // Output vector
  std::vector<MazeNode> pathOutput;
  // Copy first MazeNode
  pathOutput.push_back(*a_maze.getCurrentNode());
  a_maze.getCurrentNode()->setVisited();
  // Since the dead ends are filled the loop checks for nodes and traverses to the last node
  while (a_maze.getCurrentNode() != a_maze.getLastNode()) {
    a_maze.setCurrentNode(checkNeigborNodes(a_maze.getCurrentNode(), a_maze));
    a_maze.getCurrentNode()->setVisited();
    pathOutput.push_back(*a_maze.getCurrentNode());
  }// end while
  return pathOutput;
}// end solveDEF


/** solveCustom: A* algorithm. Using the manhattan distance between the current node
and bot first node and last node to calculate the optimal path.
Precondition: Maze object exists
Postcondition: Returns a vector with a ordered sequence of nodes starting from
the first MazeNode and ending with the last MazeNode of the maze.Thus, producing
a solution to the maze.
**/

std::vector<MazeNode> solveCustom(Maze &a_maze)
{
  // Copy current node
  MazeNode *checkNode = a_maze.getCurrentNode();
  // Variable containing both distances:
  // 1) from current node to first node
  // 2) from current node to second node
  // totalDistance = 1 + 2
  int totalDistance;
  // Pairs for keeping track of nodes and their totalDistance
  std::pair<MazeNode*,int> choosePair;
  std::pair<MazeNode*,int> tempPair;
  // Map for backtracking
  std::map<MazeNode*, MazeNode*> nodeMap;
  // Vector of pairs of a MazeNode and its totalDistance
  std::vector<std::pair<MazeNode*,int>> nodeAndDistanceVector;
  a_maze.getCurrentNode()->setVisited();

  // Checks all neighoring nodes of the current node and save them in a pair with their coresponding totalDistance
  while (a_maze.getCurrentNode() != a_maze.getLastNode()) {
    checkNode = checkNeigborNodes(a_maze.getCurrentNode(), a_maze);
    while (checkNode != a_maze.getCurrentNode()) {
      // Calculate totalDistance for checkNode for both y and x coordinates: totalDistance = |firstNode - chekNode| + |lastNode - chekNode|
      int totalDistance = abs(a_maze.getFirstNode()->getPos().second - checkNode->getPos().second) + abs(a_maze.getFirstNode()->getPos().first - checkNode->getPos().first)
                              + abs(a_maze.getLastNode()->getPos().second - checkNode->getPos().second) + abs(a_maze.getLastNode()->getPos().first - checkNode->getPos().first);
      nodeMap.insert(std::pair<MazeNode*,MazeNode*>(checkNode,a_maze.getCurrentNode()));
      nodeAndDistanceVector.push_back({checkNode,(totalDistance)});
      checkNode->setVisited();
      checkNode = checkNeigborNodes(a_maze.getCurrentNode(), a_maze);
    }// end while

    //Chooses the shortest totalDistance to be examined next
    choosePair = nodeAndDistanceVector.front();
    nodeAndDistanceVector.erase(nodeAndDistanceVector.begin());
    //Loop checing for the shortest distance
    for (size_t i = 0; i < nodeAndDistanceVector.size(); i++) {
      if(choosePair.second > nodeAndDistanceVector[i].second) {
        tempPair = choosePair;
        choosePair = nodeAndDistanceVector[i];
        nodeAndDistanceVector[i] = tempPair;
      }// end if
    }// end for
    // set the currentNode to the chosen node
    a_maze.setCurrentNode(choosePair.first);
  }// end while

  //Output vetor
  std::vector<MazeNode> pathOutput;
  // Iterator nodeMapIt is used to traverse the nodeMap in order to backtrack
  std::map<MazeNode*, MazeNode*>::iterator nodeMapIt = nodeMap.find(a_maze.getLastNode());
  // Loop traverses the nodeMapIt in order to copy MazeNodes into the output vector.
  // It starts from the lastNode to the firstNode
  while (nodeMapIt->second != a_maze.getFirstNode()) {
    pathOutput.insert(pathOutput.begin(),*nodeMapIt->first);
    nodeMapIt = nodeMap.find(nodeMapIt->second);
  }// end while
  pathOutput.insert(pathOutput.begin(),*nodeMapIt->first);
  pathOutput.insert(pathOutput.begin(),*nodeMapIt->second);
  return pathOutput;
}// end solveCustom

} // namespace solutions
