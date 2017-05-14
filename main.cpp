#include "graphics.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "widget.hpp"
#include "szamnovelo.hpp"
#include "mezoertek.hpp"


using namespace genv;
using namespace std;

const unsigned int X = 700;
const unsigned int Y = 600;



int main()
{
    vector<vector <string>>vektor_egesz;
    vector<vector <string>>n;
    beolvas(vektor_egesz);
    egyesit(vektor_egesz, n);



    vector<widget*> wektor;
    gout.open(X,Y);
    int b=0;

    for(int i=0; i<9; i++)
    {
        int x=0;
        int y=0;
        int a;

        for(int j=0; j<9; j++)
          {
            stringstream ss;
            ss << n[i][j];
            int s;
            ss >> s;

            szamnovelo* s1= new szamnovelo(50+b,50+x,50,50,0,9,s);
            if(s==0){s1->irhato=true;}
            s1->valasztva=false;
            x=x+s1->szeles()+2;
            wektor.push_back(s1);
            y++;
            a=s1->magas();
          }
          b+=a+2;
    }




    event ev;

    while(gin >> ev)
    {

        gout << move_to(0,0) << color(0,0,0) << box(X,Y);
        for(int i=0; i<wektor.size(); i++)
        {
            wektor[i]->doboz();



        }
        gout << refresh;



        if(ev.type==ev_mouse && ev.button==btn_left)
        {
            ellenoriz(vektor_egesz,n);
            for(int i=0; i<wektor.size(); i++)
            {
                if(wektor[i]-> holvan(ev) == -1)
                {
                    wektor[i]->valasztva=false;
                }
                else
                {
                    wektor[i]->valasztva=true;
                }
            }
        }
        for(int i=0; i<wektor.size(); i++)
        {
            if(wektor[i]->valasztva)
            {
                wektor[i]->kezel(ev);

            }
        }
    }

    return 0;

}
