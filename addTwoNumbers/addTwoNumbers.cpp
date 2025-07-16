#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remember = 0;
        ListNode* res = nullptr;
        ListNode** cur = &res;
        
        while(l1 != nullptr || l2 != nullptr || remember == 1) {
            int a = (l1 != nullptr) ? l1->val : 0;
            int b = (l2 != nullptr) ? l2->val : 0;

            int sum = a + b + remember;
            remember = 0;
            if(sum >= 10){
                sum %= 10;
                remember = 1;
            }
            
            *cur = new ListNode(sum);
            cur = &(*cur)->next;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }

        return res;
    }
};

void printList(ListNode* head) {
    while(head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << "\n";
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }
}

int main() {
    ListNode* l1 = new ListNode(9);
    ListNode* l2 = new ListNode(1, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))))));
    Solution solution;
    printList(solution.addTwoNumbers(l1, l2));

    freeList(l1);
    freeList(l2);
    return 0;
}