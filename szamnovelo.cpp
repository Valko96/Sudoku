#include "widget.hpp";
#include "szamnovelo.hpp"
#include "graphics.hpp"
#include <sstream>
#include <iostream>


using namespace genv;
using namespace std;

void szamnovelo :: doboz()
  {

    stringstream ss;
    ss << szam;
    string kiir;
    if(szam==0)
    {
        kiir="";
    }
    else
    {

        ss >> kiir;
    }
    if(szam ==0)
    {
        gout << color(0,255,0) << move_to(X,Y) << box(szelesseg,magassag);
        gout << color(255,255,255) << move_to(X+szelesseg-gout.twidth("+"),Y+(szelesseg/2)) <<color(0,0,255)<<text("+");
        gout <<  move_to((X)+szelesseg-(szelesseg/6),Y+magassag/2)<<line_to(X+szelesseg,Y+magassag/2);
        gout << move_to(X+szelesseg-(szelesseg/6),Y+magassag/2+(magassag/3))<<text("-");
        gout << color(255,255,255) << move_to(X+(szelesseg/2),Y+(magassag/2)) << text(kiir);
    }
    else
    {
        gout << color(255,0,0) << move_to(X,Y) << box(szelesseg,magassag);
        gout << color(255,255,255) << move_to(X+szelesseg-gout.twidth("+"),Y+(szelesseg/2)) <<color(0,0,255)<<text("+");
        gout <<  move_to((X)+szelesseg-(szelesseg/6),Y+magassag/2)<<line_to(X+szelesseg,Y+magassag/2);
        gout << move_to(X+szelesseg-(szelesseg/6),Y+magassag/2+(magassag/3))<<text("-");
        gout << color(255,255,255) << move_to(X+(szelesseg/2),Y+(magassag/2)) << text(kiir);
    }
  }

int szamnovelo :: holvan(event ev)
    {
    if(irhato)

      {

        if(ev.pos_x>szelesseg+X-20 && ev.pos_x<=X+szelesseg && ev.pos_y>=Y && ev.pos_y<=Y+magassag/2)
        {
            return 1;
        }
        else if(ev.pos_x>X+szelesseg-20 && ev.pos_x<=X+szelesseg && ev.pos_y>=Y+magassag/2 && ev.pos_y<=Y+magassag)
        {
            return 2;
        }
        else if(ev.pos_x>=X && ev.pos_x<=X+szelesseg && ev.pos_y>=Y &&ev.pos_y<=Y+magassag)
        {
            return 3;
        }
        else
        {
            return -1;
        }
      }
    }
void szamnovelo :: kezel(event ev)
{

    if(ev.type==ev_mouse && ev.button==btn_left && holvan(ev)== 1)
    {
        szam+=1;

    }
    else if(ev.type==ev_mouse && ev.button==btn_left && holvan(ev)== 2)
    {
        szam-=1;
    }
    if(ev.type==ev_key && ev.keycode==key_up)
    {
        szam+=1;
    }
    else if(ev.type==ev_key && ev.keycode==key_down)
    {
        szam-=1;
    }
    if(ev.type==ev_key && ev.keycode==key_pgup)
    {
        szam+=10;
    }
    if(ev.type==ev_key && ev.keycode==key_pgdn)
    {
        szam-=10;
    }

    if(szam>=maximum)
    {
        szam=maximum;
    }
    if (szam <= minimum)
    {
        szam=minimum;
    }


}
void szamnovelo::mentes(event ev)
{
    if(ev.type==ev_key && ev.keycode==key_space)
           {

            kifajl.open("Szamlalo.txt");
            kifajl << "Selected display's number: " << szam << endl;
            kifajl.close();
            gout << color(0,255,0) << move_to(szelesseg/3,magassag/2) << text("The selected display's number has been saved.");

           }

}
