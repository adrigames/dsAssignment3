#ifndef SIMPLENODE_HPP
#define SIMPLENODE_HPP

class simpleNode
{
    int label;
    int times;
    simpleNode *leftChild;
    simpleNode *rightChild;
public:
    simpleNode(int);
    ~simpleNode();
    int getLabel();
    int getTimes();
    simpleNode* getLeftChild();
    simpleNode* getRightChild();
    void setLabel(int);
    void setTimes(int);
    void increaseTimes();
    void decreaseTimes();
    void setLeftChild(simpleNode*);
    void setRightChild(simpleNode*);
};

#endif // SIMPLENODE_HPP
