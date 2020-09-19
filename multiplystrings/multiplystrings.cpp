#include <vector>
#include <algorithm>
#include <string>

using namespace std;
void joinSecondStringToFirst(string &s1, string &s2, int offset)
{
    auto iters1 = rbegin(s1);
    auto iters2 = rbegin(s2);
    int carry = 0;
    while (offset--)
    {
        if (iters1 != rend(s1))
        {
            iters1++;
        }
    }
    while (iters2 != rend(s2))
    {
        int sint1 = 0;
        int sint2 = 0;
        if (iters1 != rend(s1))
        {
            if (*iters1 == '*')
                sint1 = 0;
            else
                sint1 = *iters1 - '0';
        }
        if (iters2 != rend(s2))
        {
            sint2 = *iters2 - '0';
            iters2++;
        }
        char val = (sint1 + sint2 + carry) % 10 + '0';
        carry = (sint1 + sint2 + carry) / 10;
        *iters1 = val;
        if (iters1 != rend(s1))
            iters1++;
    }
    if (carry)
        *iters1 = carry + '0';
}
void multiplyStrings(string &s1, string &s2, int length1, int length2, string &output)
{
    string &multiplier = s1;
    string &multiplicand = s2;
    if (length1 > length2)
    {
        multiplier.swap(multiplicand);
    }

    int offset = -1;
    for (auto it = rbegin(multiplier); it != rend(multiplier); ++it)
    {
        int multiplyingInt = *it - '0';
        int carry = 0;
        string intermediate = "";
        for (auto itMultiplicand = rbegin(multiplicand); itMultiplicand != rend(multiplicand); ++itMultiplicand)
        {
            int multiplicandInt = *itMultiplicand - '0';
            int result = multiplyingInt * multiplicandInt;
            result += carry;
            char val = result % 10 + '0';
            carry = result / 10;
            intermediate.push_back(val);
        }
        if (carry)
            intermediate.push_back(
                carry + '0');
        reverse(intermediate.begin(), intermediate.end());
        joinSecondStringToFirst(output, intermediate, ++offset);
    }
    return output;
}
int main()
{
    // string multiplier1 = "456";
    //string multiplier1 = "27121";
    //string multiplier2 = "51221";
    string multiplier1 = "10";
    string multiplier2 = "10";
    int length1 = multiplier1.length();
    int length2 = multiplier2.length();
    int maxLength = length1 + length2;
    string output(length1 + length2, '*');
    if (multiplier1 != "0" && multiplier2 != "0")
    {
        multiplyStrings(multiplier1, multiplier2, length1, length2, output);
    }
    else
        output = "0";
    if (*begin(output) == '*')
        output.erase(begin(output));
    return 1;
}
