#include "graphedge.h"
#include "graphnode.h"
#include <iostream>                         // for debugging

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // delete _chatBot;                     // ****************** Task 0.  This is what makes the original code crash when shut-down. ***********************

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)             // *************************** Task 3. ***************************************
{
    _childEdges.push_back(std::move(edge));                                     // modify for exclusive ownership
}

void GraphNode::MoveChatbotHere(ChatBot chatbot)                                // ************************** 
{
    _chatBot = std::move(chatbot);                                              // modify for exclusive ownership
    _chatBot.SetCurrentNode(this);                                              // cont.
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    ChatBot movedchatbot = ChatBot("../images/chatbot.png");                    // *************************** Task 4. ***************************************
    newNode -> MoveChatbotHere(std::move(_chatBot));                            // *************************** 
}

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    return _childEdges[index].get();                                            // ****************************** Task 3. ************************************
}