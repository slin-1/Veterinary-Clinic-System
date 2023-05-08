#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

/*
  Class:    View
  Purpose:  The view class is comprised of functions that are strictly for visuals/interactions
            for the user in the terminal.
*/

class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
};

#endif
