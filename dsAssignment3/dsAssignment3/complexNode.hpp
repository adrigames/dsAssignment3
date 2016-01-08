#ifndef COMPLEXNODE_HPP
#define COMPLEXNODE_HPP

class complexNode
{
    int label;
    int posTimes;
    int negTimes;
    complexNode* leftChild;
    complexNode* rightChild;
public:
    complexNode(int);
    ~complexNode();
    int getLabel();
    int getPosTimes();
    int getNegTimes();
    complexNode* getLeftChild();
    complexNode* getRightChild();
    void increasePosTimes();
    void decreasePosTimes();
    void increaseNegTimes();
    void decreaseNegTimes();
    void setLeftChild(complexNode*);
    void setRightChild(complexNode*);
};

#endif // COMPLEXNODE_HPP
