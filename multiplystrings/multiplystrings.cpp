#include <vector>
#include <algorithm>
#include <string>

using namespace std;
string joinSecondStringToFirst(string &s1, string &s2, int offset)
{
    string result = "";
    auto iters1 = rbegin(s1);
    auto iters2 = rbegin(s2);
    int carry = 0;
    while (offset--)
    {
        if (iters1 != rend(s1))
        {
            result.push_back(*iters1);
            iters1++;
        }
    }
    while (iters1 != rend(s1) || iters2 != rend(s2))
    {
        int sint1 = 0;
        int sint2 = 0;
        if (iters1 != rend(s1))
        {

            sint1 = *iters1 - '0';
            iters1++;
        }
        if (iters2 != rend(s2))
        {

            sint2 = *iters2 - '0';
            iters2++;
        }
        char val = (sint1 + sint2 + carry) % 10 + '0';
        carry = (sint1 + sint2 + carry) / 10;
        result.push_back(val);
    }
    if (carry)
        result.push_back(carry + '0');
    reverse(begin(result), end(result));
    return result;
}
string multiplyStrings(string &s1, string &s2)
{
    int length1 = s1.length();
    int length2 = s2.length();
    string &multiplier = s1;
    string &multiplicand = s2;
    string output = "";
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
        output = joinSecondStringToFirst(output, intermediate, ++offset);
    }
    return output;
}
int main()
{
    // string multiplier1 = "456";
    string multiplier1 = "27121";
    string multiplier2 = "51221";
    string output = "0";
    if (multiplier1 != "0" && multiplier2 != "0")
        output = multiplyStrings(multiplier1, multiplier2);
    return 1;
}
