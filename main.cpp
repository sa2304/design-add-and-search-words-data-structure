#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class WordDictionary {
  struct Node {
    array<unique_ptr<Node>, 26> children;
    bool is_word = false;
  };

  Node root;

  bool search(const string& word, int pos, Node* node) {
    for (int i = pos; i < word.size(); ++i) {
      char c = word[i];
      if ('.' == c) {
        for (int l = 0; l < 26; ++l) {
          Node* child = node->children[l].get();
          if (child) {
            if (search(word, i + 1, child)) return true;
          }
        }
        return false;
      } else {
        int l = c - 'a';
        if (!node->children[l]) {
          return false;
        } else {
          node = node->children[l].get();
        }
      }
    }

    return node->is_word;
  }

 public:
  WordDictionary() {}

  void addWord(string word) {
    if (!word.empty()) {
      Node* node = &root;
      for (int i = 0; i < word.size(); ++i) {
        int c = word[i] - 'a';
        if (node->children[c]) {
          node = node->children[c].get();
        } else {
          node->children[c] = make_unique<Node>();
          node = node->children[c].get();
        }
      }
      node->is_word = true;
    }
  }

  bool search(string word) {
    return search(word, 0, &root);
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
