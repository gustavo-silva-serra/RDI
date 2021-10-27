#include <iostream>
#include <string>

using namespace std;

const char* isPalindromePermutation(const char* input)
{
    // assumes all characters are lowercase
    const int NUM_OF_CHAR = 26;
    int occurrences[NUM_OF_CHAR] = {}; // how many times each char appears in input
    bool odd_occurrence = false;

    // memset(occurrences, 0, sizeof(occurrences));
    for (const char* p = input; *p; ++p)
    {
        occurrences[*p - 'a']++;
    }

    for (int i = 0; i < NUM_OF_CHAR; ++i)
    {
        if (occurrences[i] % 2 != 0) // not even
        {
            if (odd_occurrence) // this is not our first odd
            {
                return "NO";
            }
            odd_occurrence = true;
        }
    }

    return "YES";
}

int main()
{
    cout << isPalindromePermutation("carroaco") << endl;
    cout << isPalindromePermutation("abcabcabc") << endl;
    cout << isPalindromePermutation("aa") << endl;
    cout << isPalindromePermutation("abba") << endl;
    cout << isPalindromePermutation("abcba") << endl;
    cout << isPalindromePermutation("o") << endl;
    cout << isPalindromePermutation("oc") << endl;

    return 0;
}
