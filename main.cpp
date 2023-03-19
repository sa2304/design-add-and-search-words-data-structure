#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class WordDictionary {
 public:
  WordDictionary() {
    //FIXME
  }

  void addWord(string word) {
    //FIXME
  }

  bool search(string word) {
    //FIXME
    return false;
  }
};

void Test1() {
  WordDictionary dict;
  dict.addWord("bad"s);
  dict.addWord("dad"s);
  dict.addWord("mad"s);
  assert(!dict.search("pad"s));
  assert(dict.search("bad"s));
  assert(dict.search(".ad"s));
  assert(dict.search("b.."s));
}

int main() {
  Test1();
  cout << "Ok!" << endl;
  return 0;
}
