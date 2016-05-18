#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <stdio.h>
#include <unistd.h>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;
#include "Command.h"
#include "Test.h"

Test::Test(vector<string> commandVec)
{
    this->cmdVec = commandVec;
}

int Test::getrunstat()
{
    return this->runStat;
}

int Test::execute()
{
    bool dashf = false;
    bool dashd = false;
    for(unsigned i = 0; i < cmdVec.size(); ++i)
    {
        if(cmdVec.at(i) == "-d")
        {
            dashd = true;
        }
        if(cmdVec.at(i) == "-f")
        {
            dashf = true;
        }
    }
    runStat = 1;
    char** cstrings = new char*[cmdVec.size() + 1];
    unsigned i = 0;
    for(; i < this->cmdVec.size(); ++i)
    {
        cstrings[i] = new char[cmdVec[i].size() + 1];
        std::strcpy(cstrings[i], cmdVec[i].c_str());
    }
    cstrings[i] = NULL;
    struct stat sb;
    
    if(!dashf && !dashd)
    {
        if (stat(cstrings[2], &sb) == -1) {
            cout << "False" << endl;
            runStat = -1;
            return runStat;
        }
        cout << "True" << endl;
        return runStat + 1;
    }
    else if(dashd)
    {
        if (stat(cstrings[2], &sb) == -1) {
            cout << "False" << endl;
            runStat = -1;
            return runStat;
        }
        
        switch (sb.st_mode & S_IFMT) {
        case S_IFDIR:  dashd = false;                   break;
        }
        
        if(!dashd)
        {
            cout << "True" << endl;
            return runStat + 1;
        }
        cout << "False" << endl;
        return runStat - 1;
    }
    else{
        if (stat(cstrings[2], &sb) == -1) {
            cout << "False" << endl;
            runStat = -1;
            return runStat;
        }
        switch (sb.st_mode & S_IFMT) {
        case S_IFREG:  dashf = false;                    break;
        }
        
        if(!dashf)
        {
            cout << "True" << endl;
            return runStat + 1;
        }
        cout << "False" << endl;
        return runStat - 1;
    }
    delete[] cstrings;
    return runStat;
}