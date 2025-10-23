class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)return head;
        // Step 1: Find length of list
        int length = 1;
        ListNode* temp = head;
        while(temp->next){
            temp = temp->next;
            length++;
        }
        // Step 2: Connect last node to head (circular list)
        k = k % length;
        temp->next = head;
        // Step 3: Traverse to new head
        ListNode* newtail = head;
        for(int i = 0;i < length - k -1;i++){
            newtail = newtail->next;
        }
        // Step 4: Break circle
        ListNode* newhead = newtail->next;
        newtail->next = nullptr;
        return newhead;
    }
};
