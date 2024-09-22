#include <iostream>
#include <string>
#include <vector>

using namespace std;

class JoinView {
public:
  JoinView(const string &obr, const string &str, char separator)
      : obr(obr), str(str), separator(separator) {}

  char operator[](size_t index) const {
    if (index < obr.length()) {
      return obr[index];
    } else if (index == obr.length()) {
      return separator;
    } else {
      return str[index - obr.length() - 1];
    }
  }

  size_t length() const { return obr.length() + 1 + str.length(); }

private:
  const string &obr;
  const string &str;
  char separator;
};

vector<int> FinOccurrences(const string &str, const string &obr) {
  vector<int> positions;
  int obr_len = obr.length();

  JoinView joined(obr, str, '#');

  vector<int> pi(obr_len + 1);

  int j = 0;
  for (int i = 1; i <= obr_len; ++i) {
    while (j > 0 && joined[i] != joined[j]) {
      j = pi[j - 1];
    }
    if (joined[i] == joined[j]) {
      j++;
    }
    pi[i] = j;
  }

  j = 0;
  for (int i = obr_len + 1; i < joined.length(); ++i) {
    while (j > 0 && joined[i] != joined[j]) {
      j = pi[j - 1];
    }
    if (joined[i] == joined[j]) {
      j++;
    }
    if (j == obr_len) {
      positions.push_back(i - 2 * obr_len);
      j = pi[j - 1];
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