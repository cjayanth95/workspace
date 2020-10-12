#include <iostream>
#include <vector>

using namespace std;

struct MissingAndDuplicate {
  int missing;
  int duplicate;
};

MissingAndDuplicate FindMissingAndDuplicate(const vector<int> &A) {
  int miss_duplicate_XOR = 0;
  for (int i = 0; i < (int)A.size(); i++) {
    miss_duplicate_XOR ^= i ^ A[i];
  }
  int differBit = miss_duplicate_XOR & (~(miss_duplicate_XOR - 1));
  int bitSetXOR = 0;
  for (int i = 0; i < (int)A.size(); i++) {
    if (i ^ differBit)
      bitSetXOR ^= i;

    if (A[i] & differBit)
      bitSetXOR ^= A[i];
  }
  cout << bitSetXOR << endl;
  for (int i = 0; i < (int)A.size(); i++) {
    if (bitSetXOR == A[i])
      return {miss_duplicate_XOR ^ bitSetXOR, bitSetXOR};
  }
  return {bitSetXOR, miss_duplicate_XOR ^ bitSetXOR};
}

int main() {
  // vector<int> A = {0, 1, 2, 2, 3, 4, 5, 6, 8};
  vector<int> A = {5, 3, 0, 3, 1, 2};
  MissingAndDuplicate miss_dup = FindMissingAndDuplicate(A);
  cout << miss_dup.duplicate << "  " << miss_dup.missing << endl;
}
