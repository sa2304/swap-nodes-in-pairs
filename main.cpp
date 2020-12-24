#include <iostream>

#include "solution.h"

using namespace std;

int main()
{
    List numbers{1,2,3,4};
    Solution s;
    ListNode* head = s.swapPairs(numbers.head);
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
