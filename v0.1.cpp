// v0.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::left;
using std::setw;
using std::istream;

struct studentas {
    string vardas, pavarde;
    float  nd[10]{};
    //Tarkime, kad namų darbų daugiausiai gali būti 10 - 
    // todėl renkamės statinį masyvą ir nurodome masyvo dydį [10]
    float egz;
    float galutinis_vid;
    float galutinis_med;
   
};

void pildymas(studentas& kint); // Funkcijos prototipas, kuris turi būti aprašytas pries funkciją main.
void print(studentas& kin);
void mediana(int pazymiai[]);
int generate_random();
void autoIvedimas(studentas Eil[], int i, int n);


int main()
{
    studentas studentai[30];
    int studsk;
    cout << "Keliu studentu duomenis ivesite? "; cin >> studsk;
    while (int(studsk) < 0 || int(studsk) > 200)
    {
        cout << "Ivesta negalima reiksme - patikslinkite." << endl;
        cout << "Keliu studentu duomenis ivesite? " << endl;
        cin.clear();
        cin.ignore();
    }


    /*std::cout << "Ar norite, kad studentu pazymiai butu suvesti automatiskai - SPAUSKITE \"T\"\n Jeigu norite suvesti duomenis patys - RASYKITE \"N\"\n";
    std::cin >> temp;
    while (temp != 'T' && temp != 't' && temp != 'N' && temp != 'n');
    {
        cout << "Ivesta negalima reiksme - pakartokite." << endl;
        cin.clear();
        cin.ignore();
    }
    for (int i = 0; i < studsk; i++)
    {
        if (temp == 'N' || temp == 'n') { pildymas(Eil, i); }
        else
        {
            autoIvedimas(Eil, i, 10);
        }
    }*/

    for (int i = 0; i < studsk; i++)
        pildymas(studentai[i]);

    cout
        << "\n"
        << left << setw(15) << "Vardas"
        << left << setw(20) << "Pavarde"
        << left << setw(25) << "Egzamino ivertinimas"
        << left << setw(20) << "Galutinis (vidurkis) / "
        << left << setw(20) << "Galutinis (mediana)"
        << endl
        << string(15 + 20 + 3 * 25, '-') << "\n";

    for (int i = 0; i < studsk; i++)
        print(studentai[i]);

}


//Funkcijos kūnas;
void pildymas(studentas& kint) {

    cout << "Iveskite studento varda ir pavarde: "; cin >> kint.vardas >> kint.pavarde;
    int n; //Namų darbų skaičius
    float sum = 0, vid = 0; //Sum-> namų darbų suma, vid-> namų darbų vidurkis;

    cout << "Kiek ivesite namu darbu? (1-10) ";
    while (!(cin >> n) || n < 1 || n>10)
    {
        cout << "Ivesta negalima reiksme - patikslinkite." << endl;
        cout << "Kiek ivesite namu darbu?" << endl;
        cin.clear();
        cin.ignore();
    }

    cout << "Iveskite pazymius: " << endl;
    for (int i = 0; i < n; i++) {
        while (!(cin >> kint.nd[i]) || kint.nd[i] < 1 || kint.nd[i] > 10)
        {
            cout << "Ivesta negalima reiksme - patikslinkite." << endl;
            cout << "Iveskite pazymius: " << endl;
            cin.clear();
            cin.ignore();
        }
        sum += kint.nd[i];
    };

    vid = sum / n;

    cout << "Iveskite egzamino pazymi: ";
    while (!(cin >> kint.egz) || kint.egz < 1 || kint.egz>10)
    {
        cout << "Ivesta negalima reiksme - patikslinkite." << endl;
        cout << "Iveskite egzamino pazymi: ";
        cin.clear();
        cin.ignore();
    }

    float med;
    if (n % 2 == 0)
    {
         med = float(((kint.nd[(n / 2) - 1]) + (kint.nd[(n / 2)])) / 2.0);
    }
    else
    {
         med = kint.nd[(n) / 2];
    }
    cout << endl;


    kint.galutinis_vid = 0.4 * vid + 0.6 * kint.egz;
    kint.galutinis_med = 0.4 * med + 0.6 * kint.egz;
}

void print(studentas& kin) {
    cout
        << left << setw(15) << kin.vardas
        << left << setw(20) << kin.pavarde
        << left << setw(25) << kin.egz
        << left << setw(20) << std::setprecision(3) << kin.galutinis_vid << " / "
        << left << setw(20) << std::setprecision(3) << kin.galutinis_med << endl;
}

/*void mediana(float pazymiai[]) //Funkcija, kuri suranda mediana
{
    int c = 0;

    for (int i = 0; i < 10; i++)
    {
        if (pazymiai[i] > 0) { c++; }
        if (pazymiai[i] == -1) { pazymiai[i] = 0; break; }
    }
    if (c % 2 == 0)
    {
        cout << float(((pazymiai[c / 2-1]) + (pazymiai[(c / 2)])) / 2.0);
    }
    else
    {
        cout << pazymiai[(c/2)];
    }
    cout << endl;
}*/



/*int generate_random() //funkcija generuojanti atisitikitnius skaicius nuo 1 iki 10
{
    srand(time(NULL));
    return rand() % 10 + 1;
}
void autoIvedimas(studentas Eil[], int i, int n) //funckija automatiskai generuoja namu darbu pazymius ir egz. ivertinima
{
    Eil[i].egz = generate_random();
    for (int x = 0; x < n; x++)
    {
        Eil[i].nd[x] = generate_random();
    }

    Eil[i].galut = Eil[i].galut / n;
    Eil[i].galut = Eil[i].galut * 0.4 + Eil[i].egz * 0.6;
}*/