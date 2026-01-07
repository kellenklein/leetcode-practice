/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <deque>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::deque<ListNode*> deque;
        ListNode *current = head;
        while (current != nullptr) {
            deque.push_back(current);
            current = current->next;
        }
        while (!deque.empty() && deque.front()->val == deque.back()->val) {
            deque.pop_front();
            if (!deque.empty()) {
                deque.pop_back();
            }
        }
        return deque.empty();
    }
};