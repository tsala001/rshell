#include <iostream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include "Base.h"
using namespace std;

Processes::Processes()
{
    currCmds.size() = 0;
    string andand == "&&";
    string oror = "||";
    string semicolon = ";";
    string comment = "#";
}

Processes::~Processes()
{
    for(int i = 0; i < currCmds; ++i)
    {
        delete currCmds.at(i):
    }
}

void Processes::addCmd(Base* nxtCmd)
{
    this->currCmds.push_back(nxtCmd);
}

void Processes::execute()
{
    
}

void Processes::parse()
{
    
}