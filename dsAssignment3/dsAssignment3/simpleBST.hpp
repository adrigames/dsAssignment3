#ifndef SIMPLEBST_HPP
#define SIMPLEBST_HPP

#include "simpleNode.hpp"
#include <string>
#include <sstream>
#include <cstddef>
#include <stdexcept>

#include <iostream>

class simpleBST
{
    simpleNode* root;
    void deleteMin(int[], simpleNode**);
public:
    simpleBST();
    ~simpleBST();
    simpleNode** getRoot();
    void insert(simpleNode**, simpleNode*);
    void Delete(int, simpleNode**);
    bool search(int, simpleNode*);
    std::string list(simpleNode*);
    void getNode(int[], simpleNode**);
};

#endif // SIMPLEBST_HPP
