/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return NULL;
        if (headA == headB)
            return headA;
       
        ListNode *currentA;
        ListNode *currentB;

        ListNode *endA = nullptr;
        ListNode *endB = nullptr;

        while (true) {
            while (currentA->next != endA && currentA->next != nullptr) {
                currentA = currentA->next;
            }
            while (currentB->next != endB && currentB->next != nullptr) {
                currentB = currentB->next;
            }
            if (currentA == currentB) {
                if (currentA == headA || currentB == headB) {
                    return currentA;
                }
                endA = currentA;
                endB = currentB;
                currentA = headA;
                currentB = headB;
                continue;
            }
            return currentA->next;
        }

        // if (currentA == currentB) {
            // return currentA;
        // }
    }
};