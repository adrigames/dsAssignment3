#include "complexBST.hpp"

complexBST::complexBST()
{
    this->root = NULL;
}

complexBST::~complexBST()
{
}

int[] complexBST::deleteMin(complexNode* n)
{
    int aux[3];
    if(n->getLeftChild() == NULL)
    {
        aux[0] = n->getLabel();
        aux[1] = n->getPosTimes();
        aux[2] = n->getNegTimes();
        n = n->getRightChild();
        }
    else
    {
        return deleteMin(n->getLeftChild());
        }
    }

std::string complexBST::createList(bool neg, complexNode* n)
//This function is used to create strings in a fashion similar to that implemented in the simpleBST class
{
    if(n->getLeftChild() == NULL && n->getRightChild() == NULL)
    {
        if(neg)
            if(n->getNegTimes()>0)
                return "\"-\""<<n->getLabel()<<", "<<n->getNegTimes()<<" times\n";
            else return "";
        else
            if(n->getPosTimes()>0)
                return "\"+\""<<n->getLabel()<<", "<<n->getPosTimes()<<" times\n";
            else return "";
        }
    else if(n->getRightChild() == NULL)
    {
        if(neg)
            if(n->getNegTimes()>0)
                return createList(neg, n->getLeftChild())<<"\"-\""<<n->getLabel()<<", "<<n->getNegTimes()<<" times\n";
            else return createList(neg, n->getLeftChild());
        else
            if(n->getPosTimes()>0)
                return createList(neg, n->getLeftChild())<<"\"+\""<<n->getLabel()<<", "<<n->getPosTimes()<<" times\n";
            else return createList(neg, n->getLeftChild());
        }
    else if(n->getLeftChild() == NULL)
    {
        if(neg)
            if(n->getNegTimes()>0)
                return "\"-\""<<n->getLabel()<<", "<<n->getNegTimes()<<" times\n"<<createList(neg, n->getRightChild());
            else return createList(neg, n->getRightChild());
        else
            if(n->getPosTimes()>0)
                return "\"+\""<<n->getLabel()<<", "<<n->getPosTimes()<<" times\n"<<createList(neg, n->getRightChild());
            else return createList(neg, n->getRightChild());
        }
    else if(n->getLeftChild() != NULL && n->getRightChild() != NULL)
    {
        if(neg)
            if(n->getNegTimes()>0)
                return createList(neg, n->getLeftChild())<<"\"-\""<<n->getLabel()<<", "\
                <<n->getNegTimes()<<" times\n"<<createList(neg, n->getRightChild());
            else return createList(neg, n->getLeftChild())<<createList(neg, n->getRightChild());
        else
            if(n->getPosTimes()>0)
                return createList(neg, n->getLeftChild())<<"\"+\""<<n->getLabel()<<", "\
                <<n->getPosTimes()<<" times\n"<<createList(neg, n->getRightChild());
            else return createList(neg, n->getLeftChild())<<createList(neg, n->getRightChild());
        }
    }

void complexBST::insert(int value, complexNode* n)
{
    bool neg = (value < 0);
    if(!neg)
        {
        if(n == NULL)
        {
            n = complexNode(value);
            }
        else if(value < n->getLabel())
        {
            insert(value, n->getLeftChild());
            }
        else if(value > n->getLabel())
        {
            insert(value, n->getRightChild());
            }
        else if(value == n->getLabel())
        {
            n->increasePosTimes();
            }
    }
    else
    {
        if(n == NULL)
        {
            n = complexNode(value);
            }
        else if(-value < n->getLabel())
        {
            insert(value, n->getLeftChild());
            }
        else if(-value > n->getLabel())
        {
            insert(value, n->getRightChild());
            }
        else if(-value == n->getLabel())
        {
            n->increaseNegTimes();
            }
        }
    }
    
void complexBST::Delete(int value, bool neg, complexNode* n)
{
    int aux[3];
    if(!neg)
    {
        if(n != NULL)
        {
            if(value < n->getLabel())
            {
                Delete(value, neg, n->getLeftChild());
            }
            else if(value > n->getLabel())
            {
                Delete(value, neg, n->getRightChild());
            }
            else if(value == n->getLabel())
            {
                n->decreasePosTimes();
                if (n->getPosTimes() <= 0 && n->getNegTimes() <= 0)
                {
                    aux = deleteMin(n->getRightChild());
                    n->setLabel(aux[0]);
                    n->setPosTimes(aux[1]);
                    n->setNegTimes(aux[2]);
                }
            }
        }
        else
            if(n != NULL)
        {
            if(value < n->getLabel())
            {
                Delete(value, neg, n->getLeftChild());
            }
            else if(value > n->getLabel())
            {
                Delete(value, neg, n->getRightChild());
            }
            else if(value == n->getLabel())
            {
                n->decreaseNegTimes();
                if (n->getPosTimes() <= 0 && n->getNegTimes() <= 0)
                {
                    aux = deleteMin(n->getRightChild());
                    n->setLabel(aux[0]);
                    n->setPosTimes(aux[1]);
                    n->setNegTimes(aux[2]);
                }
            }
        }
    }
}

bool complexBST::search(int value, complexNode* n)
{
    bool neg = (value < 0);
    if(neg) value = -value;
    if(n == NULL)
    {
        return false;
        }
    else if(value == n->getLabel())
    {
        if(neg && n->getNegTimes()>0)
            return true;
        else if(!neg && n->getPosTimes()>0)
            return true;
        else return false;
        }
    else if(value < n->getLabel())
    {
        return search(value, n->getLeftChild());
        }
    else if(value > n->getLabel())
    {
        return search(value, n->getRightChild());
        }
    }

std::string complexBST::list(complexNode* n)
//This function creates the complete list of values along with the times they appeared
{
    std::string result = createList(false, n);
    result += createList(true, n);
    return result;
    }

std::string complexBST::listSave(complexNode* n)
{
    std::string result = "";
    }