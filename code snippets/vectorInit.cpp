#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
//Specify length and initializer
int length = 10;
int num = 3;
vector<int> v1(length,num);
//initializing from values

vector<int> v{10,30,40};

//initialize from another array

vector<int> v2(v.begin(), v.end());

//all elements with a particular value
vector<int> v3(10);
fill(v3.begin(),v3.end(),5);



