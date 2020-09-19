#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ essxtension!"};
    msg.push_back("asdf");
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}