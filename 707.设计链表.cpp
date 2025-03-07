/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:

    struct LinkNode
    {
        int val;
        LinkNode *next;
        LinkNode(int val){
            this->val=val;
            this->next=nullptr;
        }
    };
    int size;
    LinkNode *dhead;
    
    MyLinkedList() {
        dhead=new LinkNode(0);
    }
    
    int get(int index) {
        if (index<0||index>size-1)
        {
            return -1;
        }
        LinkNode *p=dhead;
        int i=0;
        while (p->next)
        {
            if(i==index){
                break;
            }
            p=p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        LinkNode *p=dhead;
        LinkNode *q=dhead->next;
        LinkNode *tmp=new LinkNode(val);
        p->next=tmp;
        tmp->next=q;
        size++;
    }
    
    void addAtTail(int val) {
        LinkNode *p=dhead;
        LinkNode *tmp=new LinkNode(val);
        while (p->next)
        {
            p=p->next;
        }
        p->next=tmp;
        tmp->next=nullptr;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        LinkNode *p = dhead;
        LinkNode *tmp = new LinkNode(val);
        if (index<0||index>size-1)
        {
            return;
        }
        if(index==size){
            
        }
        
    }
    
    void deleteAtIndex(int index) {
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

