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

/* [Leetcode](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)*/

// T.C : O(n)
// S.C : o(1)

class Solution {
public:

    int findLength(ListNode* &head){// find the length of the linked list
        auto temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp -> next;
        }
        return len;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int n = findLength(head) , node = 1;
        ListNode* temp = head ; ListNode* left1 ; ListNode* right1;
        // left will store the kth value node from start
        //right will store the kth  value node from end
        while(temp != NULL){
            if(node == k){
                left1 = temp;
            }
            if(node == n - k + 1){
                right1 = temp;
            }
            node++;
            temp = temp -> next;
        }

        swap(left1 -> val , right1 -> val); // swap the values only
        return head;
    }
};