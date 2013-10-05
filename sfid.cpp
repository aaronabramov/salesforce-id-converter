#include <iostream>
#include <sstream>
#include <bitset>

#define BASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ012345"

using namespace std;

int main (int argc, char *argv[]) {
  string id = argv[1];
  string chars;
  string checksum;
  string binary;
  stringstream ss;

  if (id.length() != 15 && id.length() != 18) {
    cout << "Id sholud be either 15 or 18 char long" << endl;
    return 1;
  }

  for (int i = 0; i < 3; ++i) {
    chars = id.substr(i * 5, 5);

    for (int n = 5; n > 0; n--) {
      ss << isupper(chars[n - 1]);
    }

    binary = ss.str();
    ss.str("");
    bitset<5> x(binary);

    checksum += BASE[x.to_ulong()];
  }
  cout << id.substr(0, 15) << checksum << endl;
  return 0;
}
