#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;

        SinglyLinkedList() {
            this->head = nullptr;
        }

};

void print_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        cout << node->data << "\n";

        node = node->next;
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* temp = new SinglyLinkedListNode(data);
    if (head == NULL) {
        head = temp;
    }
    else {
        SinglyLinkedListNode* walker = head;
        while (walker->next != NULL) {
            walker = walker->next;
        }
        walker->next = temp;
    }
    return head;
}

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* temp = new SinglyLinkedListNode(data);
    if (llist == NULL) llist = temp;
    else {
        temp->next = llist;
        llist = temp;
    }
    return llist;
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* new_ptr = new SinglyLinkedListNode(data);
    if (position == 0) {
        new_ptr->next = head;
        head = new_ptr;
    }
    else {
        int count = 0;
        SinglyLinkedListNode* walker = head;
        SinglyLinkedListNode* pre_walker = new SinglyLinkedListNode(0);
        pre_walker->next = head;
        while (walker != NULL) {
            if (count == position) {
                new_ptr->next = walker;
                pre_walker->next = new_ptr;
                break;
            }
            walker = walker->next;
            pre_walker = pre_walker->next;
            count++;
        }
    } 
    return head;
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if (position == 0) {
        SinglyLinkedListNode* del_node = head;
        head = head->next;
        delete(del_node);
    }
    else {
        int count = 0;
        SinglyLinkedListNode* walker = head;
        SinglyLinkedListNode* pre_walker = new SinglyLinkedListNode(0);
        pre_walker->next = head;

        while (walker != NULL) {
            if (count == position) {
                SinglyLinkedListNode* del_node = walker;
                walker = walker->next;
                pre_walker->next = walker;
                delete(del_node);
                break;
            }
            walker = walker->next;
            pre_walker = pre_walker->next;
            count++;
        }
    }
    return head;
}

void reversePrint(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* walker = head;
    vector<int> res;
    while (walker != NULL) {
        res.push_back(walker->data);
        walker = walker->next;
    }
    vector<int>::iterator it;
    for (auto it = res.rbegin() ; it != res.rend() ; ++it) {
        cout << *it << "\n";
    }
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* prev = NULL;
    SinglyLinkedListNode* curr = head;
    SinglyLinkedListNode* next = head;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        head = prev;
    }
    return head;
}

bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (head1 == NULL && head2 == NULL) return true; 
    SinglyLinkedListNode* walker1 = head1;
    SinglyLinkedListNode* walker2 = head2;
    while (true) {
        if (walker1 == NULL && walker2 == NULL) break;
        else if (walker1 == NULL && walker2 != NULL) return false;
        else if (walker1 != NULL && walker2 == NULL) return false;
        else if (walker1->data != walker2->data) return false;
        walker1 = walker1->next;
        walker2 = walker2->next;
    }
    return true;
}

bool has_cycle(SinglyLinkedListNode* head) {
    if (head == NULL) return 0;
    SinglyLinkedListNode* pre = head;
    SinglyLinkedListNode* curr = head->next;
        while (curr != NULL && curr->next != NULL) {
        if (curr == pre) return 1;
        curr = curr->next->next;
        pre = pre->next;
    }
    return 0;

    // SinglyLinkedListNode* walker = head;
    // while (walker != NULL && walker->next != NULL) {
    //     SinglyLinkedListNode* temp = walker->next->next;
    //     if (walker == temp) return 1;
    //     walker = walker->next;
    // }
    // return 0;
}

    SinglyLinkedListNode* addTwoNumbers(SinglyLinkedListNode* l1, SinglyLinkedListNode* l2) {
        SinglyLinkedListNode* new_list = new SinglyLinkedListNode(-1);
        
        int temp1 = 0;
        int temp2 = 0;
        int tempRes = 0;
        int remainder = 0;
        
        SinglyLinkedListNode* walker1 = l1;
        SinglyLinkedListNode* walker2 = l2;
        SinglyLinkedListNode* walkerNew = new_list;
        
        while (true) {
            if (walker1 == NULL && walker2 == NULL) {
                if (remainder == 0) break;
                else {
                    SinglyLinkedListNode* new_node = new SinglyLinkedListNode(remainder);
                    walkerNew->next = new_node;
                    break;
                }
            }
            else if (walker1 == NULL && walker2 != NULL) {
                if (remainder == 0) walkerNew->next = walker2;
                else {
                    int temp = (walker2->data + remainder) % 10;
                    remainder = (walker2->data + remainder) / 10;
                    walker2->data = temp;
                    walkerNew->next = walker2;
                }
            }
            else if (walker1 != NULL && walker2 == NULL) {
                if (remainder == 0) walkerNew->next = walker1;
                else {
                    int temp = (walker1->data + remainder) % 10;
                    remainder = (walker1->data + remainder) / 10;
                    walker1->data = temp;
                    walkerNew->next = walker1;
                }
            }
            else {
                temp1 = walker1->data;
                temp2 = walker2->data;
                tempRes = (temp1 + temp2 + remainder) % 10;
                remainder = (temp1 + temp2 + remainder) / 10;
                SinglyLinkedListNode* node = new SinglyLinkedListNode(tempRes);
                walkerNew->next = node;
            }
            if (walker1 != NULL) walker1 = walker1->next;
            if (walker2 != NULL) walker2 = walker2->next;
            walkerNew = walkerNew->next;
        }
        SinglyLinkedListNode* delNode = new_list;
        new_list = new_list->next;
        delete (delNode);
        return new_list;
    }

int main()
{
    // SinglyLinkedList* llist = new SinglyLinkedList();

    // cout << "Linked list 1 : \n";
    // int llist_count;
    // cin >> llist_count;

    // for (int i = 0; i < llist_count; i++) {
    //     int llist_item;
    //     cin >> llist_item;

    // 	SinglyLinkedListNode* llist_head = insertNodeAtTail(llist->head, llist_item);
    //   	llist->head = llist_head;
    // }

    // SinglyLinkedList* llist2 = new SinglyLinkedList();

    // cout << "Linked list 2 : \n";
    // int llist_count2;
    // cin >> llist_count2;

    // for (int i = 0; i < llist_count2; i++) {
    //     int llist_item2;
    //     cin >> llist_item2;

    // 	SinglyLinkedListNode* llist_head2 = insertNodeAtTail(llist2->head, llist_item2);
    //   	llist2->head = llist_head2;
    // }

    // int insert_data;
    // cin >> insert_data;
    // int insert_pos ;
    // cin >> insert_pos;
    // llist->head = insertNodeAtPosition(llist->head, insert_data, insert_pos);*/

    // int del_pos;
    // cin >> del_pos;
    // llist->head = deleteNode(llist->head, del_pos);*/

    // llist->head = reverse(llist->head);

    // print_singly_linked_list(llist->head);

    // reversePrint(llist->head);

    // cout << compare_lists(llist->head, llist2->head); 

    // free_singly_linked_list(llist->head);
    // free_singly_linked_list(llist2->head);

    SinglyLinkedListNode* head = new SinglyLinkedListNode(9);
    SinglyLinkedListNode* node2 = new SinglyLinkedListNode(8);
    // SinglyLinkedListNode* node3 = new SinglyLinkedListNode(3);
    // SinglyLinkedListNode* node4 = new SinglyLinkedListNode(4);
    // SinglyLinkedListNode* node5 = new SinglyLinkedListNode(5);

    SinglyLinkedListNode* head2 = new SinglyLinkedListNode(1);
    // SinglyLinkedListNode* node6 = new SinglyLinkedListNode(6);
    // SinglyLinkedListNode* node7 = new SinglyLinkedListNode(5);
    // SinglyLinkedListNode* node8 = new SinglyLinkedListNode(2);
    // SinglyLinkedListNode* node9 = new SinglyLinkedListNode(6);

    head->next = node2;
    node2->next = NULL;
    //node2->next = node3;
    // node3->next = node4;
    // node4->next = node5;
    // node5->next = NULL;

    // head2->next = node6;
    // node6->next = node7;
    // node7->next = node8;
    // node8->next = node9;
    // node9->next = NULL;

    SinglyLinkedListNode* new_list = new SinglyLinkedListNode(0);
    new_list = addTwoNumbers(head, head2);

    return 0;
}
