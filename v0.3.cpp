
#include "read_from_file.h"
#include "countWordsInString.h"
#include "studentai.h"
#include "mediana.h"
#include "print.h"


using namespace std;

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
