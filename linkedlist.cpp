#include <iostream>

using namespace std;

struct node{
  int val;
  node *next;
};
// using struct and func only
// pointers are passed by val by default
// void insert(node *&head, int value){
//   node *temp = new node;
//   temp->val = value;
//   temp ->next = NULL;
//   if(head == NULL){
//     head = temp;
//   }
//   else{
//     temp -> next = head;
//     head = temp;
//   }
// }
// void display(node *head){
//   node *temp = head;
//   while(temp->next !=NULL){
//     cout<<temp->val;
//     temp = temp ->next;
//   }
// }
class linkedlist{
  
  public:
  node *head;
    linkedlist(int value){
      head = new node;
      head->val = value;
      head ->next = NULL;
    }
  void insert(int value);
  void display();
  node* reverse(node* head);
};

void linkedlist::insert(int value){
  node *temp = new node;
  temp->val = value;
  temp ->next = NULL;
  if(head == NULL){
    head = temp;
  }
  else{
    temp -> next = head;
    head = temp;
  }
}

void linkedlist::display(){
  node *temp = head;
  while(temp != NULL){
    cout<<temp->val;
    temp = temp ->next;
  }
}

node* linkedlist::reverse(node* head){
  if(head->next == NULL){
    return head;
  }
  node * temp = reverse(head->next);
  head->next->next = head;
  head->next = NULL;
  return temp;
}

int main(){
  linkedlist v(23);
  v.insert(24);
  v.insert(25);
  v.insert(26);
  v.display();
  cout<<endl;
  v.head = v.reverse(v.head);
 
  // node *head;
  // insert(head, 23);
  // insert(head, 24);
  // display(head);
  return 0;
}

// reverse a linkedlist
// 1. iterative
// 2. recursive
// 3. using stack 
// iterative approach
// node *prev,*next, *curr;
// curr = head;
// next = NULL;
// prev = NULL;
// while(curr!=NULL){
//   next = curr->link;
//   curr->next = prev;
//   prev = curr;
//   curr = next;
// }

// recursive approach
// node *reverse(node *head){
//   if(head->link == NULL){
//     return head;
//   }
//   node * temp = reverse(head->next);
//   head->link->link = head;
// head->link = NULL;
//   return temp;
// }


//Merging two sorted linkedlist
//Approach-1
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//       ListNode *it1=list1, *it2=list2, *temp=NULL, *head=NULL, *tail=NULL;
//       if(it1==NULL&&it2!=NULL){
//           return it2;
//       }
//       else if(it2==NULL&&it1!=NULL){
//           return it1;
//       }
//       else if(it1==NULL&&it2==NULL){
//           return it2;
//       }
//       else{
//             while(it1!=NULL&&it2!=NULL){
//             if(it1->val<=it2->val){
//               temp = new ListNode;
//               temp->val = it1->val;
//               temp->next = NULL;
//               it1 = it1->next;
//               if(head==NULL){
//                 tail = head = temp;
//               }
//               else{
//                   tail->next = temp;
//                   tail = temp;
//               }
//           }
//           else{
//               temp = new ListNode;
//               temp->val = it2->val;
//               temp->next = NULL;
//               it2 = it2->next;
//               if(head==NULL){
//                 tail = head = temp;
//               }
//               else{
//                   tail->next = temp;
//                   tail = temp;
//                 }
//             }
//         }
//         if(it1!=NULL){
//             while(it1!=NULL){
//             temp = new ListNode;
//             temp->val = it1->val;
//             temp->next = NULL;
//             tail->next = temp;
//             tail = temp;
//             it1 = it1->next;
//             }
//        }
//        else if(it2!=NULL){
//            while(it2!=NULL){
//             temp = new ListNode;
//             temp->val = it2->val;
//             temp->next = NULL;
//             tail->next = temp;
//             tail = temp;
//             it2 = it2->next;
//            }
//        }
//        return head;
//       }

//     }
// };