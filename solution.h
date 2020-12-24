#ifndef SOLUTION_H
#define SOLUTION_H

#include <algorithm>
#include <initializer_list>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct List {
  List(const std::initializer_list<int>& numbers) {
    ListNode* last = head;
    for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
      ListNode* node = new ListNode(*iter);
      if (!head) {
        head = node;
      } else {
        last->next = node;
      }

      last = node;
    }
  }

  ListNode* head = nullptr;
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (head) {
      ListNode* pre_left = nullptr;
      ListNode* left = head;
      ListNode* right = head->next;
      while (right) {
        if ( isAdjacentNodes(left, right) ) {
          if (!pre_left) {
            head = right;
          }
          swapListNodes(pre_left, left, right);
          std::swap(left, right);
        }

        pre_left = left;
        left = left->next;
        right = right ->next;
      }
    }

    return head;
  }

private:
  bool isAdjacentNodes(ListNode* left, ListNode* right) {
    return left && right
        && (left->val + 1 == right->val
            || right-> val + 1 == left->val);
  }

  void swapListNodes(ListNode* pre_left, ListNode* left, ListNode* right) {
    if (pre_left) {
      pre_left->next = right;
    }
    left->next = right->next;
    right->next = left;
  }
};

#endif // SOLUTION_H
