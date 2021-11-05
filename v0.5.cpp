#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <chrono>
#include <list>

using namespace std;

struct studentas {
	string Vard, Pav;
	vector<int> paz = { 0 };
	int egz;
	float GP = 0;
};

studentas get(list<studentas> sar, int i)
{
	list<studentas>::iterator it = sar.begin();
	for (int z = 0; z < i; z++)
	{
		++it;
	}
	return *it;
}

int random()
{
	return rand() % 10 + 1;
}


vector<int> auto_paz(int kiek_paz)
{
	vector<int> skaiciai;
	for (int i = 0; i < kiek_paz; i++)
	{
		skaiciai.push_back(random());
	}
	return skaiciai;
}


float galut_paz(vector<int> skaiciai)
{
	studentas Eil;
	Eil.GP = 0.4 * accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * random();
	return Eil.GP;
}


int generavimas(vector<int> pazymiai)
{
	int k;
	cout << "Kokio dydzio studentu sarasa sugeneruoti?" << endl;
	cin >> k;
	string pavadinimas = "Studentai_" + to_string(k) + ".txt";
	auto start = chrono::high_resolution_clock::now();
	auto st = start;
	ofstream out_data(pavadinimas);
	vector<int> skaiciai;
	studentas Eil;
	out_data
		<< setw(20) << left << "Vardas"
		<< setw(20) << left << "Pavarde"
		<< setw(20) << left << "Galutinis(vid.)\n"
		<< left << "------------------------------------------------------------\n";

	for (int z = 1; z <= k; z = z + 1)
	{
		skaiciai = auto_paz(5);
		out_data << setw(20) << "Vardas" + to_string(z) <<
			setw(20) << "Pavarde" + to_string(z) <<
			setw(18) << galut_paz(skaiciai) << endl;
		skaiciai.clear();
	}

	/*auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> diff = end - start;
	cout << "Failo su " + to_string(k) + " studentu/-ais kurimas uztruko: " << diff.count() << " s\n";*/

	return k;
}


void read_from_file(list<studentas>& Eil, int k)
{
	int student_counter = 0;
	ifstream fileRead;
	string pavadinimas = "Studentai_" + to_string(k) + ".txt";
	string buff;
	fileRead.open(pavadinimas);
	if (fileRead.is_open())
	{
		auto start = chrono::high_resolution_clock::now();
		auto st = start;
		getline(fileRead >> ws, buff);
		while (student_counter < k)
		{
			studentas stud;

			fileRead >> stud.Vard;
			fileRead >> stud.Pav;
			fileRead >> stud.GP;
			Eil.push_back(stud);
			student_counter++;
		}
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> diff = end - start;
		cout << "Failo su " + to_string(k) + " studentu/-ais nuskaitymas uztruko: " << diff.count() << " s\n";
	}
}

int main()
{
	vector<int> skaiciai;
	int k = generavimas(skaiciai);
	list<studentas> studentai;
	read_from_file(studentai, k);
	list<studentas> moksliukai;
	list<studentas> vargsiukai;
	int varg = 0;
	int moks = 0;
	float paz = 5.00;

	auto start = chrono::high_resolution_clock::now();
	auto st = start;
	for (int i = 0; i < k; i++)
	{
		if (get(studentai, i ).GP < paz)
		{
			vargsiukai.push_back(get(studentai,i));
			varg++;
		}
	}

	for (int j = 0; j < k; j++)
	{
		int gpp = get(studentai, j).GP;
		if (get(studentai, j).GP >= paz)
		{
			moksliukai.push_back(get(studentai, j));
			moks++;
		}
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> diff = end - start;

	cout << "Failo rusiavimas su " + to_string(k) + " studentu/-ais i dvi grupes uztruko : " << diff.count() << " s\n";

	string pav;
	pav = "vargsiukai_" + to_string(k) + ".txt";
	ofstream varg_failas(pav);
	auto start1 = chrono::high_resolution_clock::now();
	auto st1 = start1;

	for (int i = 0; i < k; i++)
	{
		if (get(vargsiukai, i).GP < paz)
		{
			varg_failas << get(vargsiukai, i).Vard << setw(20) << get(vargsiukai, i).Pav << setw(18) << get(vargsiukai, i).GP << endl;
		}

	}

	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<double> diff1 = end1 - start1;
	cout << "Failo isvedimas su " + to_string(k) + " studentu/-ais  i vargsiukus uztruko : " << diff1.count() << " s\n";

	pav = "moksliukai_" + to_string(k) + ".txt";
	ofstream moks_failas(pav);
	auto start2 = chrono::high_resolution_clock::now();
	auto st2 = start2;

	for (int j = 0; j < k; j++)
	{
		if (get(moksliukai, j).GP >= paz)
		{
			moks_failas << get(moksliukai, j).Vard << setw(20) << get(moksliukai, j).Pav << setw(18) << get(moksliukai, j).GP << endl;
		}
	}
	auto end2 = std::chrono::high_resolution_clock::now();
	chrono::duration<double> diff2 = end2 - start2;
	cout << "Failo isvedimas su " + to_string(k) + " studentu/-ais  i moksliukus uztruko : " << diff2.count() << " s\n";
}