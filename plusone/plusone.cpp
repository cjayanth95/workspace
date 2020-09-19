#include <vector>
using namespace std;

int main()
{
    vector<int> v{9, 9, 9, 9};
    //vector<int> v{0};
    bool carry = true;
    for (auto it = v.rbegin(); it != v.rend(); ++it)
    {
        if (*it == 9 && carry)
        {
            *it = 0;
        }
        else if (carry)
        {
            carry = false;
            (*it)++;
        }
    }
    if(carry)
    v.insert(begin(v),1);

    return 0;

}