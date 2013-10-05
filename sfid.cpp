#include <iostream>
#include <sstream>
#include <bitset>
#include <algorithm>

#define BASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456"

using namespace std;

int main (int argc, char *argv[]) {
  string id = argv[1];
  string chars;
  string checksum = "";
  string binary = "";

  for (int i = 0; i < 3; ++i) {
    chars = id.substr(i * 5, 5);
    binary.empty();
    stringstream ss;

    for (char & c : chars) {
      ss << isupper(c);
    }

    binary = ss.str();
    reverse(binary.begin(), binary.end());
    bitset<5> x(binary);

    checksum += BASE[x.to_ulong()];
  }
  cout << id.substr(0, 15) << checksum << endl;
  return 0;
}
