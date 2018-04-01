#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
  int data;
  Node *next;
  Node(int d) {
    data = d;
    next = NULL;
  }
};
class Solution {
public:
  Node *removeDuplicates(Node *head) {
    Node *iter = head;
    while (iter != NULL) {
      Node *temp = head;
      Node *back = head;
      while (temp != iter) {
        if (temp->data == iter->data) {
          if (temp == head) {
            head = iter;
            delete temp;
          } else {
            back->next = temp->next;
            delete temp;
            temp = back->next;
          }
        } else {
          back = temp;
          temp = temp->next;
        }
      }
      iter = iter->next;
    }
    return head;
  }
  Node *insert(Node *head, int data) {
    Node *p = new Node(data);
    if (head == NULL) {
      head = p;

    } else if (head->next == NULL) {
      head->next = p;

    } else {
      Node *start = head;
      while (start->next != NULL) {
        start = start->next;
      }
      start->next = p;
    }
    return head;
  }
  void display(Node *head) {
    Node *start = head;
    while (start) {
      cout << start->data << " ";
      start = start->next;
    }
  }
};

int main() {
  Node *head = NULL;
  Solution mylist;
  int T, data;
  cin >> T;
  while (T-- > 0) {
    cin >> data;
    head = mylist.insert(head, data);
  }
  head = mylist.removeDuplicates(head);

  mylist.display(head);
}
