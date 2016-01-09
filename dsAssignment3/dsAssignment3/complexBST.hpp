#ifndef COMPLEXBST_HPP
#define COMPLEXBST_HPP

#include <string>
#include "complexNode.hpp"

class complexBST
{
    complexNode* root;
    int[] deleteMin(complexNode*);
    std::string createList(bool, complexNode*);
public:
    complexBST();
    ~complexBST();
    void insert(int, complexNode*);
    void Delete(int, complexNode*);
    bool search(int, complexNode*);
    std::string list();
    std::string listSave(complexNode*);

};

#endif // COMPLEXBST_HPP
