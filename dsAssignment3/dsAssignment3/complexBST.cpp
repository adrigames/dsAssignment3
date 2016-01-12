#include "complexBST.hpp"

complexBST::complexBST()
{
    this->root = NULL;
}

complexBST::~complexBST()
{
}

void complexBST::deleteMin(int result[3], complexNode** n)
{
    if(*(*n)->getLeftChild() == NULL)
    {
        result[0] = (*n)->getLabel();
        result[1] = (*n)->getPosTimes();
        result[2] = (*n)->getNegTimes();
        delete *n;
        }
    else
    {
        deleteMin(result, (*n)->getLeftChild());
        }
    }

complexNode** complexBST::getRoot()
{
    return &this->root;
    }

std::string complexBST::createList(bool neg, complexNode* n)
//This function is used to create strings in a fashion similar to that implemented in the simpleBST class
{
    std::stringstream stream;
    if(*n->getLeftChild() != NULL)
        stream<<this->createList(neg, *n->getLeftChild());
    if(neg)
    {
        if(n->getNegTimes()>0)
            stream<<"\"-\", "<<n->getLabel()<<", "<<n->getNegTimes()<<" times\n";
        }
    else
    {
        if(n->getPosTimes()>0)
            stream<<"\"+\", "<<n->getLabel()<<", "<<n->getPosTimes()<<" times\n";
        }
    if(*n->getRightChild() != NULL)
        stream<<this->createList(neg, *n->getRightChild());
    return stream.str();
    }

void complexBST::insert(complexNode** rt, complexNode* n)
{
    if(*rt == NULL){
        *rt = n;
    }
    else if(n->getLabel()<(*rt)->getLabel()){
                this->insert((*rt)->getLeftChild(), n);
            }
            else if(n->getLabel()>(*rt)->getLabel()){
                this->insert((*rt)->getRightChild(), n);
            }
            else if(n->getLabel() == (*rt)->getLabel())
            {
                if(n->getPosTimes()>0)
                    (*rt)->increasePosTimes();
                else if(n->getNegTimes()>0)
                    (*rt)->increaseNegTimes();
            }
    }
    
void complexBST::Delete(int value, bool neg, complexNode** n)
{
    int aux[3];
    if(!neg)
    {
        if(*n != NULL)
        {
            if(value < (*n)->getLabel())
            {
                Delete(value, neg, (*n)->getLeftChild());
            }
            else if(value > (*n)->getLabel())
            {
                Delete(value, neg, (*n)->getRightChild());
            }
            else if(value == (*n)->getLabel())
            {
                (*n)->decreasePosTimes();
                if ((*n)->getPosTimes() <= 0 && (*n)->getNegTimes() <= 0)
                {
                  if(*(*n)->getRightChild() != NULL){
                        deleteMin(aux, (*n)->getRightChild());
                        (*n)->setLabel(aux[0]);
                        (*n)->setPosTimes(aux[1]);
                        (*n)->setNegTimes(aux[2]);
                    }
                    else
                    {
                        complexNode* aux = *n;
                        *n = NULL;
                        delete aux;
                        }
                }
            }
        }
    }
        else
            if(*n != NULL)
        {
            if(-value < (*n)->getLabel())
            {
                Delete(value, neg, (*n)->getLeftChild());
            }
            else if(-value > (*n)->getLabel())
            {
                Delete(value, neg, (*n)->getRightChild());
            }
            else if(-value == (*n)->getLabel())
            {
                (*n)->decreaseNegTimes();
                if ((*n)->getPosTimes() <= 0 && (*n)->getNegTimes() <= 0)
                {
                    if(*(*n)->getRightChild() != NULL){
                        deleteMin(aux, (*n)->getRightChild());
                        (*n)->setLabel(aux[0]);
                        (*n)->setPosTimes(aux[1]);
                        (*n)->setNegTimes(aux[2]);
                    }
                    else
                    {
                        complexNode* aux = *n;
                        *n = NULL;
                        delete aux;
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
        return search(value, *n->getLeftChild());
        }
    else if(value > n->getLabel())
    {
        return search(value, *n->getRightChild());
        }
        return false;
    }

std::string complexBST::list()
//This function creates the complete list of values along with the times they appeared
{
    if (this->root == NULL) throw std::runtime_error("List is empty");
    std::string result = createList(false, this->root);
    result += createList(true, this->root);
    return result;
    }

std::string complexBST::listSave(complexNode* n)
// Create save string
{
    std::stringstream stream;
    int i = 0;
    if(*n->getLeftChild() != NULL)
        stream<<this->listSave(*n->getLeftChild());
    if(n->getPosTimes()>0)
        {
            for(i=0; i<n->getPosTimes();i++)
            {
                stream<<n->getLabel();
                if(i == n->getPosTimes()-1 && n->getNegTimes() <= 0)
                    stream<<".\n";
                else
                    stream<<',';
                }
            }
        if(n->getNegTimes()>0)
        {
            for(i=0; i<n->getNegTimes(); i++)
            {
                stream<<-n->getLabel();
                if(i == n->getNegTimes()-1)
                    stream<<".\n";
                else
                    stream<<',';
                }
            }
        if(*n->getRightChild() != NULL)
            stream<<this->listSave(*n->getRightChild());
        return stream.str();
    }

void complexBST::getNode(int values[3], complexNode** n)
{
    if(this->root == NULL)
    {
        values[0] = 0;
        values[1] = 0;
        values[2] = 0;
        complexNode* aux = *n;
        *n = NULL;
        delete aux;
        return;
        }
    if(*(*n)->getLeftChild() == NULL && *(*n)->getRightChild() == NULL)
    {
        values[0] = (*n)->getLabel();
        values[1] = (*n)->getPosTimes();
        values[2] = (*n)->getPosTimes();
        complexNode* aux = *n;
        *n = NULL;
        delete aux;;
        return;
        }
    if(*(*n)->getLeftChild() != NULL)
    {
        this->getNode(values, (*n)->getLeftChild());
        return;
        }
    else if(*(*n)->getRightChild() != NULL)
    {
        this->getNode(values, (*n)->getRightChild());
        }
    }