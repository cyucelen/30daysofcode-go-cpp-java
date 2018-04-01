#include <iostream>

using namespace std;

struct Node {
  char data;
  Node *link;
};

class LinkedList {
private:
  Node *first;

public:
  LinkedList() { first = NULL; }
  void addItem(char data) {
    Node *item = new Node();
    item->data = data;
    item->link = NULL;
    if (first == NULL) {
      first = item;
    } else {
      Node *iter = first;
      while (iter->link != NULL) {
        iter = iter->link;
      }
      iter->link = item;
    }
  }
  void deleteLast() {
    if (first == NULL)
      return;
    if (first->link == NULL) {
      delete first;
      first = NULL;
      return;
    }

    Node *iter = first;

    while (iter->link->link != NULL) {
      iter = iter->link;
    }
    delete iter->link;
    iter->link = NULL;
  }
  void deleteFirst() {
    if (first == NULL)
      return;

    if (first->link == NULL) {
      delete first;
      first = NULL;
      return;
    }

    Node *temp = first;
    first = first->link;
    delete temp;
  }
  char getFirstData() { return first->data; }
  char getLastData() {
    Node *iter = first;
    while (iter->link != NULL) {
      iter = iter->link;
    }
    return iter->data;
  }
  void print() {
    Node *iter = first;
    while (iter != NULL) {
      cout << iter->data;
      iter = iter->link;
    }
    cout << endl;
  }
};

class Stack {
private:
  LinkedList stackList;

public:
  Stack() {}
  void pushCharacter(char ch) { stackList.addItem(ch); }
  char popCharacter() {
    char data = stackList.getLastData();
    stackList.deleteLast();
    return data;
  }
};

class Queue {
private:
  LinkedList queueList;

public:
  Queue(){};
  void enqueueCharacter(char ch) { queueList.addItem(ch); }
  char dequeueCharacter() {
    char data = queueList.getFirstData();
    queueList.deleteFirst();
    return data;
  }
};
// Sorry for multiple inheritance but i have to..
class Solution : public Stack, public Queue {};

int main() {
  // read the string s.
  string s;
  getline(cin, s);

  // create the Solution class object p.
  Solution obj;

  // push/enqueue all the characters of string s to stack.
  for (int i = 0; i < s.length(); i++) {
    obj.pushCharacter(s[i]);
    obj.enqueueCharacter(s[i]);
  }

  bool isPalindrome = true;

  // pop the top character from stack.
  // dequeue the first character from queue.
  // compare both the characters.
  for (int i = 0; i < s.length() / 2; i++) {
    if (obj.popCharacter() != obj.dequeueCharacter()) {
      isPalindrome = false;

      // break;
    }
  }

  // finally print whether string s is palindrome or not.
  if (isPalindrome) {
    cout << "The word, " << s << ", is a palindrome.";
  } else {
    cout << "The word, " << s << ", is not a palindrome.";
  }

  return 0;
}
