#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
struct movie {
  string title;
  int year;
} films[3];
void printMovie(movie movie_t);
int main() {
  string str;
  movie mine;
  movie yours;
  movie *ptr;
  ptr = &mine;
  mine.title = "A space odessey";
  mine.year = 1947;
  cout << "Enter title" << endl;
  getline(cin, yours.title);
  cout << "Enter year" << endl;
  getline(cin, str);
  stringstream(str) >> yours.year;
  cout<<(*ptr).year<<endl;
  //printMovie(mine);
  //printMovie(yours);
}
void printMovie(movie movie_t) {
  cout << "Movie title: " << movie_t.title << endl;
  cout << "Movie release: " << movie_t.year << endl;
}
