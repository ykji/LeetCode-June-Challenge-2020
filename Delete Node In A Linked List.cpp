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
    void deleteNode(ListNode* node) {
        // shifting the successive values of target node one place back
        // then deleting the last node
        while(node->next->next!=NULL){
            node->val=node->next->val;
            node=node->next;
        }node->val=node->next->val;
        delete (node->next);
        node->next=NULL;
    }
};
