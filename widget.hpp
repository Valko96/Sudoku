#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED
#include <iostream>
#include "graphics.hpp"
#include <fstream>

using namespace genv;
using namespace std;
class widget
{
protected:

    int X;
    int Y;
    unsigned int szelesseg;
    unsigned int magassag;

public:

    widget(int x0, int y0, unsigned int szelesseg0, unsigned int magassag0);
    bool valasztva;
    bool tartalom;
    virtual void doboz()=0;
    virtual int holvan(event ev)=0;
    virtual void kezel(event ev)=0;
    virtual void mentes(event ev)=0;
    int szeles();
    int magas();

};


#endif // WIDGET_H_INCLUDED
