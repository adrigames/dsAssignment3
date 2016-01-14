#include "MainHandler.hpp"

MainHandler::MainHandler()
{
    this->positive = new simpleBST();
    this->negative = new simpleBST();
    this->complex = new complexBST();
    std::cout<<"Created trees..."<<std::endl;
    this->complexOrg = false;
    this->io = new IOHandler(this->positive, this->negative, this->complex);
    std::cout<<"Created data..."<<std::endl;
    this->io->load();
    std::cout<<"Loaded data..."<<std::endl;
}

MainHandler::~MainHandler()         //In case of this object being destroyed
{
    if(this->io != NULL)            //Save
    {
        this->io->save();
        }
}

void MainHandler::drawMenu(bool* exit)
{
    system("cls"); //Clean screen 
    int option = -1;
    std::cout<<'\t'<<(char)201<<(char)205<<(char)187<<\
    "Please, select an option:"<<std::endl;
    std::cout<<'\t'<<(char)186<<1<<(char)186<<\
    "PROCESS NUMBER"<<"\t\t"<<std::endl;
    std::cout<<'\t'<<(char)186<<2<<(char)186<<\
    "CHANGE STORAGE"<<"\t\t"<<std::endl;
    std::cout<<'\t'<<(char)186<<3<<(char)186<<\
    "LIST"<<"\t\t"<<std::endl;
    std::cout<<'\t'<<(char)186<<4<<(char)186<<\
    "EXTRACT"<<"\t\t\t"<<std::endl;
    std::cout<<'\t'<<(char)186<<5<<(char)186<<\
    "EXIT"<<"\t\t\t"<<std::endl;
    std::cout<<'\t'<<(char)200<<(char)205<<(char)188<<std::endl<<std::endl;
    std::cout<<"\t\tOption (you can enter batchs. If an option requires an argument, the following number will be taken as such): ";
    if(std::cin>>option){
        std::cout<<std::endl;
        this->processInput(option, exit);
        }
    else
    {
        std::cout<<"INPUT ERROR: INVALID INPUT"<<std::endl; //Throw error
        //Clean buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    system("pause");
    }

void MainHandler::processInput(int option, bool* exit)
{
    //Once option is captured, process and execute it.
{
    switch(option)
    {
        case 1: this->processnumber();                          //Option 1: insert a new number
                break;
        case 2: this->changeOrganization();
                break;
        case 3: this->list();
                break;
        case 4: this->extract();
                break;               
        case 5: this->Exit(exit);
                break;
        default: std::cout<<"Invalid option.\nInsert new option."<<std::endl;
        }
    return;
    }
}
    
void MainHandler::processnumber()
//Process number function
{
    long int input = 0;
    do
    {
        if(std::cin.fail())
        {
            std::cout<<"Invalid input detected.\nPlease, insert number."<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        std::cout<<"Enter number: "<<std::endl;
        std::cin>>input;
        }while(std::cin.fail());
        this->io->processNumber(input, this->complexOrg);
    }

void MainHandler::list()
{
    clock_t c1, c2;
    c1 = clock();
    if(complexOrg)
    {
        try{
            std::cout<<this->complex->list();
        }catch(std::runtime_error r)
        {
            }
        }
    else
    {
        try{
        std::cout<<this->positive->list(*(this->positive->getRoot()));
        }catch(std::runtime_error r){
            }
        try{
        std::cout<<this->negative->list(*(this->negative->getRoot()));
        }catch(std::runtime_error r)
        {
            }
        }
    c2 = clock();
    long elapsed_time = ((double)(c2-c1)/CLOCKS_PER_SEC)*1000;
    int hours = floor(elapsed_time/(3600*1000));
    elapsed_time -= hours*3600*1000;
    int minutes = floor(elapsed_time/(60000));
    elapsed_time -= minutes*60000;
    int seconds = floor(elapsed_time/1000);
    elapsed_time -= seconds*1000;
    int milliseconds = elapsed_time;
    printf("Elapsed time: %2i:%2i:%2i.%3i\n", hours, minutes, seconds, milliseconds);
    }

void MainHandler::extract()
{
    int number;
    do{
        if(std::cin.fail())
            {
                std::cout<<"Invalid input detected.\nPlease, insert number."<<std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
        std::cout<<"Insert number to be erased: "<<std::endl;
        std::cin>>number;
        }while(std::cin.fail());
    if(this->complexOrg)
    {
        this->complex->Delete(number, number<0, this->complex->getRoot());
        }
    else
    {
        if(number<0)
        {
            this->negative->Delete(number, this->negative->getRoot());
            }
        else
        {
            this->positive->Delete(number, this->positive->getRoot());
            }
        }
    }

void MainHandler::changeOrganization()
{
    if(complexOrg)
    {
        while(*this->complex->getRoot() != NULL)
        {
            int values[3];
            this->complex->getNode(values, this->complex->getRoot());
            int i = 0;
            if(values[1]>0)
                for(i=0; i<values[1]; i++)
                    this->io->processNumber(values[0], false);
            if(values[2]>0)
                for(i=0; i<values[2]; i++)
                    this->io->processNumber(-values[0], false);
            }
        }
    else
    {
        int values[2];
        int i = 0;
        while(*this->positive->getRoot() != NULL)
        {
            this->positive->getNode(values, this->positive->getRoot());
            if(values[1] != 0)
                for(i=0; i<values[1]; i++)
                {
                    io->processNumber(values[0], true);
                }
            }
        while(*this->negative->getRoot() != NULL)
        {
            this->negative->getNode(values, this->negative->getRoot());
            if(values[1] != 0)
                for(i=0; i<values[1]; i++)
                {
                    io->processNumber(values[0], true);
                }
            }
        }
    this->complexOrg = !this->complexOrg;
    }

bool MainHandler::confirmExit()
{
    char option = ' ';
    std::cout<<"Are you sure you want to exit? (y/n) ";
    std::cin>>option;
    switch(option)
    {
        case 'y': case 'Y': return true;
        case 'n': case 'N': return false;
        default: std::cout<<"INVALID OPTION. PLEASE, ENTER y(Yes) OR n(No)."<<std::endl;
                 system("PAUSE");
                 return confirmExit();
        }
    }

void MainHandler::Exit(bool* exit)
{
    if(this->confirmExit())
    {
        if(!this->complexOrg)
        //Ensure that complex organization is active
        {
            this->changeOrganization();
            }
        //Save
        this->io->save();
        *exit = true;
        }
    }