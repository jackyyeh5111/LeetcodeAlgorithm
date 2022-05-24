auto comp = [](ListNode *list1, ListNode *list2) {
    return list1->val > list2->val;
};

std::priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp);