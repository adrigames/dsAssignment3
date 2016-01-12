#ifndef MAINHANDLER_HPP
#define MAINHANDLER_HPP

#include "simpleBST.hpp"
#include "complexBST.hpp"
#include "IOHandler.hpp"
#include <cstddef>
#include <iostream>
#include <windows.h>
#include <limits>
#include <exception>
#include <stdexcept>

class MainHandler
{
private:
    simpleBST* positive;
    simpleBST* negative;
    complexBST* complex;
    IOHandler* io;
    bool complexOrg;
    
    void processInput(int, bool*);
    void processnumber();
    void list(void);
    void extract(void);
    void changeOrganization(void);
    bool confirmExit(void);
    void Exit(bool*);
public:
    MainHandler();
    ~MainHandler();
    void drawMenu(bool*);

};

#endif // MAINHANDLER_HPP

