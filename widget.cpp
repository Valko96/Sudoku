#include "widget.hpp"
#include <iostream>
#include "graphics.hpp"

using namespace genv;


widget :: widget (int x0, int y0, unsigned int szelesseg0, unsigned int magassag0)
{
    X=x0;
    Y=y0;
    szelesseg=szelesseg0;
    magassag=magassag0;
    valasztva=false;

}
   void widget :: doboz()
    {
        gout << color(255,0,0) << move_to(X,Y) << box(szelesseg,magassag);
    }
    int widget :: szeles()
    {
        return szelesseg;
    }
    int widget :: magas()
    {
        return magassag;
    }



