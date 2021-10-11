#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>

using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::string;
using std::vector;

struct studentai {
    string Vard, Pav;
    vector<int> paz = { 0 };
    int egz;
    float GP = 0;
};

float count_median(vector<int> pazymiai);
void print(vector<studentai> Eil, int pazymiu_sk);
unsigned int countWordsInString(string const& str);
void read_from_file(vector<studentai>& Eil, int* pazymiu_sk);

int main()
{
    int pazymiu_sk;
    char temp;
    vector<studentai> Eil;
    read_from_file(Eil, &pazymiu_sk);
    print(Eil, pazymiu_sk);
    system("pause");
    return 0;
}


float count_median(vector<int> pazymiai) //funkcija suskaiciuoja mediana
{
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        if (pazymiai[i] != 0)
        {
            counter++;
        }
        if (pazymiai[i] == -1)
        {
            pazymiai[i] = 0;
            counter--;
            break;
        }
    }
    if (counter % 2 == 0)
    {
        return float(((pazymiai[counter / 2 - 1]) + (pazymiai[(counter / 2)])) / 2.0);
    }
    else
    {
        return float(pazymiai[(counter / 2)]);
    }
}

void print(vector<studentai> Eil, int pazymiu_sk) //atspausdina rezultatus
{
    std::ofstream output;
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

unsigned int countWordsInString(string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<string>(stream), std::istream_iterator<string>());
}

void read_from_file(vector<studentai>& Eil, int* pazymiu_sk)
{
    int student_counter = 0;
    int temp;
    std::ifstream fileRead;
    string buff;
    fileRead.open("studentai100000.txt.txt");
    if (fileRead.is_open())
    {
        getline(fileRead >> std::ws, buff);
        *pazymiu_sk = countWordsInString(buff) - 3;
        while (true)
        {

            Eil.resize(Eil.size() + 1);
            fileRead >> Eil.at(student_counter).Vard;
            if (fileRead.eof()) { Eil.pop_back(); break; }
            fileRead >> Eil.at(student_counter).Pav;
            for (int i = 0; i < *pazymiu_sk; i++)
            {
                fileRead >> temp;
                Eil.at(student_counter).paz.push_back(temp);
            }
            fileRead >> Eil.at(student_counter).egz;
            //std::cout << Eil.at(student_counter).Vard;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP / *pazymiu_sk;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP * 0.4 + 0.6 * Eil.at(student_counter).egz;
            student_counter++;
        }
    }
    else { cout << "Failo atidaryti nepavyko\n"; }
}

