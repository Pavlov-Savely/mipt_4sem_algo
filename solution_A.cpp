#include <iostream>
#include <string>
#include <vector>

class JoinView {
public:
  JoinView(const std::string &str, const std::string &obr, char delim = '#')
      : str(str), obr(obr), delim(delim) {}

  char operator[](std::size_t index) const {
    if (index < obr.length()) {
      return obr[index];
    } else if (index == obr.length()) {
      return delim;
    } else {
      return str[index - obr.length() - 1];
    }
  }

  std::size_t length() const { return str.length() + obr.length() + 1; }

private:
  const std::string &str;
  const std::string &obr;
  char delim;
};

void PrefixFunction(std::vector<int> &pi, const JoinView &s) {
  const std::size_t &n = s.length();
  pi[0] = 0;

  for (std::size_t i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    pi[i] = j;
  }
}

std::vector<int> FinOccurrences(const std::string &str, const std::string &obr) {
  std::vector<int> positions;
  int obr_len = obr.length();

  JoinView joined(str, obr);

  std::vector<int> p(joined.length());

  PrefixFunction(p, joined);

  for (std::size_t i = obr_len + 1; i < p.size(); ++i) {
    if (p[i] == obr_len) {
      positions.push_back(i - 2 * obr_len);
    }
  }
  return std::move(positions);
}

int main() {
  std::string str;
  std::string obr;

  std::cin >> str;
  std::cin >> obr;

  std::vector<int> &&positions = FinOccurrences(str, obr);

  for (int position : positions) {
    std::cout << position << std::endl;
  }

  return 0;
}