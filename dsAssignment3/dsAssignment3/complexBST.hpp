#ifndef COMPLEXBST_HPP
#define COMPLEXBST_HPP

#include <string>
#include <sstream>
#include <cstddef>
#include <stdexcept>
#include "complexNode.hpp"

class complexBST
{
    complexNode* root;
    void deleteMin(int[], complexNode**);
    std::string createList(bool, complexNode*);
public:
    complexBST();
    ~complexBST();
    complexNode** getRoot();
    void insert(complexNode**, complexNode*);
    void Delete(int, bool, complexNode**);
    bool search(int, complexNode*);
    std::string list();
    std::string listSave(complexNode*);
    void getNode(int[], complexNode**);

};

#endif // COMPLEXBST_HPP
