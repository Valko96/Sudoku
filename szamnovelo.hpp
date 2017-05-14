#ifndef SZAMNOVELO_HPP_INCLUDED
#define SZAMNOVELO_HPP_INCLUDED

#include "widget.hpp"
#include "fstream"


class szamnovelo : public widget
{
    int szam=0;
    int minimum;
    int maximum;
    ofstream kifajl;

  public:
    szamnovelo(int x0, int y0, int szelesseg0, int magassag0, int mini=0, int maxi=100, int kezdeti=0, bool irhato=false) : widget(x0, y0, szelesseg0, magassag0)
    {
        minimum=mini;
        maximum=maxi;
        szam=kezdeti;
    }

    void doboz();
    void gombok();
    int holvan(event ev);
    void kezel(event ev);
    string aktualis();
    void mentes(event ev);
    int szamma(string karakter);
    void karakterre(int szam);
    void elhelyez(int szam);
    bool irhato;


};

#endif // SZAMNOVELO_HPP_INCLUDED
