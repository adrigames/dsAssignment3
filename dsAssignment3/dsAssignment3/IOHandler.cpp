#include "IOHandler.hpp"

IOHandler::IOHandler(simpleBST* positive, simpleBST* negative, complexBST* complex)
{
    this->positive = positive;
    this->negative = negative;
    this->complex = complex;
}

IOHandler::~IOHandler()
{
}

void IOHandler::save()
// Since contains of both organizations are always the same, data will be taken from complex.
// This is done because it eases formatting according to the guidelines.
{
    std::ofstream output;
    std::string data = "";
    data += this->complex->listSave(complex->getRoot());
    output.open("output.numbers.txt");      //Write to file
    if(output.is_open())
    {
        output<<data;
        std::cout<<"Data saved successfuly"<<std::endl;
        output.close();
        }
    else
    {
        std::cout<<"ERROR: COULD NOT WRITE FILE"<<std::endl;
        }
    }
    
void IOHandler::load()
{
    std::ifstream input;
    input.open("input.numbers.txt");    //Open file
    if(input.is_open())
    {
        std::string contents = "";
        std::string line;
        std::string section;
        while(!input.eof()){            //While end hasn't been reached
            getline(input, line);       //Read line
        while (line.length() > 0)
        //Parse line
        {
            section = line.substr(0, line.find(','));
            line.erase(0, line.find(','));
            if(line.find(',') != ~0U)
                line.erase(0, line.find(',')+1);
            if(section.find('.') != ~0U)
                section = section.substr(0, section.find('.'));
            std::istringstream convert(section);
            int aux = 0;
            convert>>aux;
            std::cout<<"Inserting "<<aux<<std::endl;
            if(convert.fail())
                aux = 0;                                //Not an integer
            else
                {
                    this->processNumber(aux);           //If converted to integer, process it
                    }
            }
        }
    }
    }

void IOHandler::processNumber(int value)
{
    if (value<0)                        //Check if value is negative
        {
            this->negative->insert(value, this->negative->getRoot());   //Insert in negative BST
            }
    else                                //Number is positive
    {
        this->positive->insert(value, this->positive->getRoot());       //Insert in positive BST
        }
    this->complex->insert(value, this->complex->getRoot());     //Whatever the case, insert in complex
    }