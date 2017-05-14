#ifndef MEZOERTEK_HPP_INCLUDED
#define MEZOERTEK_HPP_INCLUDED


#include <vector>
#include <iostream>

//using namespace genv;
using namespace std;

void beolvas(vector<vector <string>> &vektor_egesz);
void egyesit(vector<vector <string>> &vektor_egesz,vector<vector<string> > &n);
void ellenoriz(vector<vector <string>> &vektor_egesz,vector<vector<string> > &n);
class mezoertek
{

    public:

        vector<vector<string> > csinal();
        vector<vector<string> > n;
    private:

};

#endif // MEZOERTEK_HPP_INCLUDED
