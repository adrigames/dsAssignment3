#include "simpleNode.hpp"

simpleNode::simpleNode(int label)
{
    this->label = label;
    this->times = 1;
    this->leftChild = NULL;
    this->rightChild = NULL;
}

simpleNode::~simpleNode()
{
}

int simpleNode::getLabel()
{
    return this->label;
    }

int simpleNode::getTimes()
{
    return this->times;
    }

simpleNode** simpleNode::getLeftChild()
{
    return &this->leftChild;
    }

simpleNode** simpleNode::getRightChild()
{
    return &this->rightChild;
    }

void simpleNode::setLabel(int label)
{
    this->label = label;
    }

void simpleNode::setTimes(int times)
{
    this->times = times;
    }

void simpleNode::increaseTimes()
{
    this->times++;
    }

void simpleNode::decreaseTimes()
{
    this->times--;
    }

void simpleNode::setLeftChild(simpleNode* leftChild)
{
    this->leftChild = leftChild;
    }

void simpleNode::setRightChild(simpleNode* rightChild)
{
    this->rightChild = rightChild;
    }