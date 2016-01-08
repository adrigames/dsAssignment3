#ifndef SIMPLEBST_HPP
#define SIMPLEBST_HPP

#include "simpleNode.hpp"
#include <string>

class simpleBST
{
    simpleNode* root;
    int[] deleteMin(simpleNode*);
public:
    simpleBST();
    ~simpleBST();
    void insert(int, simpleNode*);
    void Delete(int, simpleNode*);
    bool search(int, simpleNode*);
    std::string list();
    std::string listSave();

};

#endif // SIMPLEBST_HPP
