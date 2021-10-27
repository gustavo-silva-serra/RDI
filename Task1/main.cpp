#include <iostream>

using namespace std;

string convertAmount2Words(int m, int n);

int main()
{
    struct Param {
        int m;
        int n;
        string correct;
    };
    Param values[] = { {27567001, 0, "Vinte e sete milhões quinhentos e sessenta e sete mil e um reais"},
        {27567011, 0, "Vinte e sete milhões quinhentos e sessenta e sete mil e onze reais"},
        {999999999, 0, "Novecentos e noventa e nove milhões novecentos e noventa e nove mil e novecentos e noventa e nove reais"},
        {1000000000, 0, ""},
        {1000080, 0, "Um milhão e oitenta reais"},
        {111, 0, "Cento e onze reais"},
        {1,11, "Um real e onze centavos"},
        {23,01, "Vinte e três reais e um centavo"},
        {1000,01, "Mil reais e um centavo"},
        {1000000, 0 , "Um milhão de reais"},
        {1, 0, "Um real"},
        {10, 0, "Dez reais"},
        {11, 0, "Onze reais"},
        {100, 0, "Cem reais"},
        {101, 0, "Cento e um reais"},
        {111, 0, "Cento e onze reais"},
        {200, 0, "Duzentos reais"},
        {1001,00, "Mil e um reais"},
        {0, 20, "Vinte centavos"},
        {0,1, "Um centavo"} };
    int test = 0;
    for (auto v : values) {
        string result = convertAmount2Words(v.m, v.n);
        if (result != v.correct) {
            cout << ++test << ": Failed!!! R$ " << v.m << "," << v.n << endl;
            cout << "  Expected: " << v.correct << endl;
            cout << "  Got: " << result << endl;
        }
        else {
            cout << ++test << ": Ok " << result << endl;
        }
    }

    return 0;
}