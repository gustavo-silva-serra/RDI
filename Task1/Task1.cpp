#include <string>
#include <locale>

using namespace std;

const char* units[] = { "", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove" };
const char* tens10[] = { "dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove" };
const char* tens[] = {"" , "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa" };
const char* hundreds[] = { "", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos" };

/** Concats a string, if original string already has data use a separator.
*/
string& concatSeparator(string& s1, const string& s2, const char* sep)
{
    if (s2.empty()) {
        return s1; // nothing to be done
    }
    if (s1.length() > 0) {
        s1 += sep;
    }
    s1 += s2;
    return s1;
}

string convertIntegerPart(int m, const char* plural, const char* singular)
{
    string ret;

    if (m == 1) {
        return singular;
    }

    if (m == 100) {
        ret = "cem";
    } else if (m > 100) {
        ret = hundreds[m / 100];
    }
    m %= 100;

    if (m > 9 && m < 20) { // m = 11, 12... 19
        concatSeparator(ret, tens10[m - 10], " e ");
    } else {
        concatSeparator(ret, tens[m / 10], " e ");
        concatSeparator(ret, units[m % 10], " e ");
    }

    if (ret.length() > 0) {
        return concatSeparator(ret, plural, " ");
    }
    
    return ret;
}

string convertAmount2Words(int m, int n)
{
    // Necessary to print accented words in terminal
    setlocale(LC_ALL, ".UTF8");

    if (m >= 1000000000 || m < 0 || n > 99 || n < 0) {
        // Maybe throw an exception?
        return "";
    }

    int hundred = m % 1000;
    int thousand = (m / 1000) % 1000;
    int million = (m / 1000000);

    string result = convertIntegerPart(million, "milhões", "um milhão");
    concatSeparator(result, convertIntegerPart(thousand, "mil", "mil"), " ");
    concatSeparator(result, convertIntegerPart(hundred, "", "um"), " e ");

    if (hundred == 0 && thousand == 0 && million > 0)
        result += " de";

    if (result.length()) {
        result += (m > 1 ? " reais" : " real");
    }

    concatSeparator(result, convertIntegerPart(n, "centavos", "um centavo"), " e ");

    result[0] = toupper(result[0]);

    return result;
}

