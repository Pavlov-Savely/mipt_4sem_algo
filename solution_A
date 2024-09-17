#include <iostream>
#include <vector>
#include <string>

using namespace std; 

vector<int> PrefixFunction(const string& s) {
  int n = s.length();  
  vector<int> pi(n);
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    pi[i] = j;
  }
  return pi;
}

vector<int> FinOccurrences(const string& str, const string& obr) {
  vector<int> positions;
  int obr_len = obr.length();

  vector<int> p = PrefixFunction(obr + '#' + str);

  for (int i = obr_len + 1; i < p.size(); ++i) {
    if (p[i] == obr_len) {
      positions.push_back(i - 2 * obr_len);
    }
  }
  return positions;
}

int main() {
  string str;
  string obr;
  
  cin >> str;
  cin >> obr;

  vector<int> positions = FinOccurrences(str, obr);

  for (int position : positions) {
    cout << position << endl;
  }

  return 0;
}
