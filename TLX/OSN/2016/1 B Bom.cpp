#include <iostream>

using namespace std;

int subtask1_l = 22;
int subtask1[22] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 3, 4, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3};
int subtask2_l = 22;
int subtask2[22] = {1, 1, 2, 2, 3, 3, 4, 4, 2, 3, 4, 2, 3, 4, 2, 3, 4, 2, 3, 4, 2, 3};
string s;
int n, t, r;

int main() {
  getline(cin, s);
  cin >> n >> t >> r;

  if (s[1] == '1') {
    for (int i=0; i<subtask1_l; i++) {
      cout << subtask1[i] << endl << flush;
    }
  }

  if (s[2] == '2') {
    for (int i=0; i<subtask2_l; i++) {
      cout << subtask2[i] << endl << flush;
    }
  }
}