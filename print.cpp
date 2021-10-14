
#include "studentai.h"
#include "print.h"
#include "mediana.h"


void print(vector<studentai> Eil, int pazymiu_sk) 
{
    ofstream output;
    output.open("rezultatai.txt");
    output
        //cout
        << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < Eil.size(); i++)
    {
        output
            //cout
            << setw(20) << left << Eil[i].Vard
            << setw(20) << left << Eil[i].Pav
            << setw(18) << left << Eil[i].GP
            << count_median(Eil[i].paz) << endl;
    }
    output.close();
}