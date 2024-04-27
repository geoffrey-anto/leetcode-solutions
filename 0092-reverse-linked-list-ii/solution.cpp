class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) {
            return head;
        }

        ListNode* temp = new ListNode();
        
        temp->next = head;
        ListNode* prev = temp;

        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        ListNode* end = prev;
        for (int i = 0; i < right - left + 1; ++i) {
            end = end->next;
        }

        ListNode* start = prev->next;
        ListNode* curr = start->next;
        while (curr != end) {
            start->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = start->next;
        }

        start->next = end->next;
        end->next = prev->next;
        prev->next = end;

        if (left == 1) {
            head = temp->next;
        }

        delete temp;
        return head;
    }
};

