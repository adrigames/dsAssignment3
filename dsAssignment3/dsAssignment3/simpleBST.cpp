#include "simpleBST.hpp"

simpleBST::simpleBST()
{
    this.root = NULL;
}

simpleBST::~simpleBST()
{
}

int[] simpleBST::deleteMin(simpleNode* n)
{
    int aux[2];
    if(n->getLeftChild() == NULL)
    {
        aux[0] = n->getLabel();
        aux[1] = n->getTimes();
        n = n->getRightChild();
        }
    else
    {
        return deleteMin(n->getLeftChild());
        }
    }

void simpleBST::insert(int value, simpleNode* n)
{
    if(n == NULL)
    {
        n = simpleNode(value);
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
        n->increaseTimes();
        }
    }
    
void simpleBST::Delete(int value, simpleNode* n)
{
    int aux[2];
    if(n != NULL)
    {
        if(value < n->getLabel())
        {
            Delete(value, n->getLeftChild());
            }
        else if(value > n->getLabel())
        {
            Delete(value, n->getRightChild());
            }
        else if(value == n->getLabel())
        {
            n->decreaseTimes();
            if (n->getTimes() <= 0)
            {
                aux = deleteMin(n->getRightChild());
                n->setLabel(aux[0]);
                n->setTimes(aux[1]);
                }
            }
        }
    }

bool simpleBST::search(int value, simpleNode* n)
{
    if(n == NULL)
    {
        return false;
        }
    else if(value == n->getLabel())
    {
        return true;
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