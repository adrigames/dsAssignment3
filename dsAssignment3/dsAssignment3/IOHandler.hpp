#ifndef IOHANDLER_HPP
#define IOHANDLER_HPP

#include "simpleBST.hpp"
#include "simpleNode.hpp"
#include "complexBST.hpp"
#include "complexNode.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>

class IOHandler
{
    simpleBST* positive;
    simpleBST* negative;
    complexBST* complex;
public:
    IOHandler(simpleBST*, simpleBST*, complexBST*);
    ~IOHandler();
    void save();
    void load();
    void processNumber(int, bool);
};

#endif // IOHANDLER_HPP
