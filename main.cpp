#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class WordDictionary {
  struct Node {
    unordered_map<char, Node*> children;
    bool is_word = false;
  };

  Node root;

  bool search(const string& word, int pos, Node* node) {
    for (int i = pos; i < word.size(); ++i) {
      char c = word[i];
      if ('.' == c) {
        for (const auto&[letter, child]: node->children) {
          if (search(word, i + 1, child)) return true;
        }
        return false;
      } else {
        if (!node->children.count(c)) {
          return false;
        } else {
          node = node->children.at(c);
        }
      }
    }

    return node->is_word;
  }

 public:
  WordDictionary() = default;

  void addWord(string word) {
    if (!word.empty()) {
      Node* node = &root;
      for (int i = 0; i < word.size(); ++i) {
        char c = word[i];
        if (node->children.count(c)) {
          node = node->children.at(c);
        } else {
          Node* child = new Node;
          node->children[c] = child;
          node = child;
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
