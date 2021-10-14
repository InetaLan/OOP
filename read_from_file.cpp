
#include "studentai.h"
#include "read_from_file.h"
#include "countWordsInString.h"

void read_from_file(vector<studentai>& Eil, int* pazymiu_sk)
{
    int student_counter = 0;
    int temp;
    std::ifstream fileRead;
    string buff;


    try
    {
        fileRead.open("studentai100000.txt.txt");

        if (!fileRead.is_open())
            throw 0;

        getline(fileRead >> std::ws, buff);
        *pazymiu_sk = countWordsInString(buff) - 3;
        while (true)
        {
            Eil.resize(Eil.size() + 1);
            fileRead >> Eil.at(student_counter).Vard;
            if (fileRead.eof())
            {
                Eil.pop_back(); break;
            }
            fileRead >> Eil.at(student_counter).Pav;
            for (int i = 0; i < *pazymiu_sk; i++)
            {
                fileRead >> temp;
                Eil.at(student_counter).paz.push_back(temp);
            }
            fileRead >> Eil.at(student_counter).egz;

            Eil.at(student_counter).GP = Eil.at(student_counter).GP / *pazymiu_sk;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP * 0.4 + 0.6 * Eil.at(student_counter).egz;
            student_counter++;

        }

    }
    catch (int klaid)
    {
        std::cout << "Tokio failo nėra" << klaid << std::endl;
    }
}