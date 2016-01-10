#ifndef SIMPLEBST_HPP
#define SIMPLEBST_HPP

#include "simpleNode.hpp"
#include <string>
#include <sstream>

class simpleBST
{
    simpleNode* root;
    int[] deleteMin(simpleNode*);
public:
    simpleBST();
    ~simpleBST();
    simpleNode* getRoot();
    void insert(int, simpleNode*);
    void Delete(int, simpleNode*);
    bool search(int, simpleNode*);
    std::string list(simpleNode*);

};

#endif // SIMPLEBST_HPP
