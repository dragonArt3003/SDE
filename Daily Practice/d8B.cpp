class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& A) {
        if (A.size() == 0)
            return nullptr;
        if (A.size() == 1)
            return A[0];
        pair<int, int> pr;
        std::priority_queue<pair<int, int>, vector<pair<int, int>>,
                            greater<pair<int, int>>>
            heap;
        for (int i = 0; i < A.size(); i++) {
            if(A[i]){
                pr.first = A[i]->val;
                pr.second = i;
                heap.push(pr);
            }
        }

        ListNode *head = nullptr, *p = nullptr;

        while (!heap.empty()) {
            pr = heap.top();
            heap.pop();

            ListNode *newNode = new ListNode(pr.first);
            if (head == nullptr) {
                p = head = newNode;
            } else
                p->next = newNode;
            p = newNode;

            A[pr.second] = A[pr.second]->next;
            if (A[pr.second] != nullptr) {
                pr.first = A[pr.second]->val;
                heap.push(pr);
            }
        }
        return head;
    }
};
