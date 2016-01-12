#include <iostream>
#include "MainHandler.hpp"

int main(int argc, char **argv)
{
	MainHandler* Main = new MainHandler();
    bool exit = false;
    while(!exit)
    {
        Main->drawMenu(&exit);
        }
}
