#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {

vector<int> vect {10,20,20};
int length = vect.size();
vector<int> vect1(10);
fill(vect1.begin(), vect1.end(),10);
std::partial_sum(vect.begin(),vect.end(),begin(vect));
return 0;
}