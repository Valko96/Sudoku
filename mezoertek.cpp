#include "mezoertek.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include  <time.h>
#include "widget.hpp"

using namespace std;
void beolvas(vector<vector <string>> &vektor_egesz)
{
    string szam="";
    ifstream befajl("SUDOKU.txt");
    while(befajl.good())
    {
        getline(befajl,szam);
        vector<string>vektor_sor;
    for(int i=0; i<szam.length();i++)
    {
        string sor="";
        sor+=szam[i];
        vektor_sor.push_back(sor);

    }
        vektor_egesz.push_back(vektor_sor);
        vektor_sor.clear();
    }
}

void egyesit(vector<vector <string>> &vektor_egesz,vector<vector<string>> &n)
{
    srand(time(0));

    int szam1 = rand()%9;
    int szam2 = rand()%9;
    int szam3 = rand()%9;
    int szam4 = rand()%9;
    int szam5 = rand()%9;
    int szam6 = rand()%9;
    int szam7 = rand()%9;
    int szam8 = rand()%9;

   for(int i=0; i<9;i++)
   {
       vector<string> asd;
       for(int j=0; j<9;j++)
           {
                asd.push_back(vektor_egesz[i][j]);


           }
           n.push_back(asd);
    }
                n[szam1][szam2] ="0";
                n[szam3][szam4] ="0";
                n[szam4][szam2] ="0";
                n[szam3][szam2] ="0";
                n[szam1][szam4] ="0";
                n[szam2][szam2] ="0";

}

void ellenoriz(vector<vector <string>> &vektor_egesz,vector<vector<string> > &n)
{

     for(int i=0; i<9;i++)
   {

       for(int j=0; j<9;j++)
           {

                    if(n[i][j] == "0" && vektor_egesz[i][j] == n[i][j])
                    {
                        cout << "egyezik" << endl;
                    }



           }

}
}
