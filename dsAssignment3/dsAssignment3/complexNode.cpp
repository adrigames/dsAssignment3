#include "complexNode.hpp"

complexNode::complexNode(int value)
{
    if(value < 0)
    {
        this->label = -value;
        this->negTimes = 1;
        this->posTimes = 0;
        }
    else
    {
        this->label = value;
        this->posTimes = 1;
        this->negTimes = 0;
        }
    this->leftChild = NULL;
    this->rightChild = NULL;
}

complexNode::~complexNode()
{
}

int complexNode::getLabel()
{
    return this->label;
    }

int complexNode::getPosTimes()
{
    return this->posTimes;
    }

int complexNode::getNegTimes()
{
    return this->negTimes;
    }

complexNode** complexNode::getLeftChild()
{
    return &this->leftChild;
    }

complexNode** complexNode::getRightChild()
{
    return &this->rightChild;
    }

void complexNode::setLabel(int label)
{
    this->label = label;
    }

void complexNode::setPosTimes(int times)
{
    this->posTimes = times;
    }

void complexNode::setNegTimes(int times)
{
    this->negTimes = times;
    }

void complexNode::increasePosTimes()
{
    this->posTimes++;
    }

void complexNode::decreasePosTimes()
{
    this->posTimes--;
    }

void complexNode::increaseNegTimes()
{
    this->negTimes++;
    }

void complexNode::decreaseNegTimes()
{
    this->negTimes--;
    }

void complexNode::setLeftChild(complexNode* leftChild)
{
    this->leftChild = leftChild;
    }

void complexNode::setRightChild(complexNode* rightChild)
{
    this->rightChild = rightChild;
    }
