#include "simpleBST.hpp"

simpleBST::simpleBST()
{
    this->root = NULL;
}

simpleBST::~simpleBST()
{
}

void simpleBST::deleteMin(int values[2], simpleNode** n)
{
    if(*(*n)->getLeftChild() == NULL)
    {
        std::cout<<"No left child"<<std::endl;
        simpleNode* aux = *n;
        values[0] = (*n)->getLabel();
        values[1] = (*n)->getTimes();
        std::cout<<"Values acquired"<<std::endl;
        if((*n)->getRightChild() != NULL)
        {
            *n = *(*n)->getRightChild();
            delete aux;
        }
        else delete *n;
        }
    else
    {
        deleteMin(values, (*n)->getLeftChild());
        }
    }

simpleNode** simpleBST::getRoot()
{
    return &this->root;
    }

void simpleBST::insert(simpleNode** rt, simpleNode* n)
{
    bool neg = (n->getLabel() < 0);
    if(*rt == NULL){
        *rt = n;
    }
    else
    {
        if(!neg){
            if(n->getLabel()<(*rt)->getLabel())
                this->insert((*rt)->getLeftChild(), n);
            else if(n->getLabel()>(*rt)->getLabel())
                this->insert((*rt)->getRightChild(), n);
            else if(n->getLabel() == (*rt)->getLabel())
                (*rt)->increaseTimes();
        }
        else{
            if(-n->getLabel()<-(*rt)->getLabel())
                this->insert((*rt)->getLeftChild(), n);
            else if(-n->getLabel()>-(*rt)->getLabel())
                this->insert((*rt)->getRightChild(), n);
            else if(-n->getLabel() == -(*rt)->getLabel())
                (*rt)->increaseTimes();
            }
        }
    }
    
void simpleBST::Delete(int value, simpleNode** n)
{
    int aux[2];
    if(*n != NULL)
    {
        if(value < (*n)->getLabel())
        {
            Delete(value, (*n)->getLeftChild());
            }
        else if(value > (*n)->getLabel())
        {
            Delete(value, (*n)->getRightChild());
            }
        else if(value == (*n)->getLabel())
        {
            (*n)->decreaseTimes();
            if ((*n)->getTimes() <= 0)
            {
                if(*(*n)->getRightChild() != NULL){
                    deleteMin(aux, (*n)->getRightChild());
                    (*n)->setLabel(aux[0]);
                    (*n)->setTimes(aux[1]);
                    }
                else{
                    simpleNode* aux = *n;
                    *n = NULL;
                    delete aux;
                    }
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
        return search(value, *(n->getLeftChild()));
        }
    else if(value > n->getLabel())
    {
        return search(value, *(n->getRightChild()));
        }
    return false;
    }

std::string simpleBST::list(simpleNode* n)
{
    if (n == NULL) throw std::runtime_error("List is empty");
    std::stringstream stream;
    bool neg = (n->getLabel()<0);
    if(*(n->getLeftChild()) != NULL)
        stream<<this->list(*(n->getLeftChild()));
    if(neg)
        stream<<"\"-\", "<<-n->getLabel()<<", "<<n->getTimes()<<" times.\n";
    else
        stream<<"\"+\", "<<n->getLabel()<<", "<<n->getTimes()<<" times.\n";
    if(*(n->getRightChild()) != NULL)
        stream<<this->list(*(n->getRightChild()));
    return stream.str();
    }

void simpleBST::getNode(int values[2], simpleNode** n)
{
    if(*n == NULL)
    {
        values[0] = 0;
        values[1] = 0;
        return;
    }
    if(*(*n)->getLeftChild() == NULL && *(*n)->getRightChild() == NULL)
    {
        std::cout<<"Lowest absolute value node located"<<std::endl;
        values[0] = (*n)->getLabel();
        values[1] = (*n)->getTimes();
        std::cout<<"Data acquired"<<std::endl;
        simpleNode* aux = *n;
        *n = NULL;
        delete aux;
        std::cout<<"Node taken out"<<std::endl;
        return;
        }
    if(*(*n)->getLeftChild() != NULL){
        this->getNode(values, (*n)->getLeftChild());
        return;
    }
    if(*(*n)->getRightChild() != NULL)
        this->getNode(values, (*n)->getRightChild());
    }