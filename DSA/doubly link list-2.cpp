#include <bits/stdc++.h>
#define int long long
using namespace std;
class node{
  public:
  int data;
  node*next;
  node*back;
  node(int data,node*next,node*back) {
    this->data=data;
    this->next=next;
    this->back=back;
  }
  node(int data) {
    this->data=data;
    next=nullptr;
    back=nullptr;
  }
};
node*convertarrtodll(vector<int> &arr){
    node*head=new node(arr[0]);
    //node*mover=head;
    node*mover=head;
    for(int i=1; i<arr.size(); i++) {
      node*temp=new node(arr[i],nullptr,mover);
      mover->next=temp;
      mover=temp;
      // prev=prev->next;
    }
    return head; 
  }
  node*deletehead(node*head) {
    if(head==NULL) {
      return head;
    }
    node*temp=head;
    head=head->next;
    head->back=nullptr;
    temp->next=nullptr;
    free(temp);
    return head;
  }
  node*deletetail(node*head) {
    if(head==NULL || head->next==NULL) {
      return head;
    }
    node*temp=head;
    //temp increase till tail
    // when temp=tail break;
    while(temp->next!=NULL) {
      temp=temp->next;
    }
    node*prev=temp->back;
    temp->back=nullptr;
    prev->next=nullptr;
    free(temp);
    return head;
  } 
  node*deletek(node*head, int k) {
    if(head==NULL) {
      return NULL;
      }
      int count=0;
      node*temp=head;
      while(temp!=NULL) {
        count++;
        if(count==k) {
          break;
        } 
        temp=temp->next;
      }
      node*prev=temp->back;
      node*front=temp->next;
      if(prev==NULL && front==NULL) {
        return NULL;
      }
      else if(prev==NULL) {
        return deletehead(head);
      }
      else if(front==NULL) {
        return deletetail(head);
      }
      prev->next=front;
      front->back=prev;
      temp->next=nullptr;
      temp->back=nullptr;
      free(temp);
       return head; 
  }
  // inserthead
  node*inserthead(node*head,int val) {
    node*temp=new node(val,head,nullptr);
    head->back=temp;
    return temp;
  }
  node*inserttail(node*head, int value) {
    if(head==NULL) {
      return new node(value,nullptr,nullptr);
    }
    if(head->next==NULL) {
      return inserthead(head,value);
    }
    node*temp=head;
    while(temp->next->next!=NULL) {
      temp=temp->next;
    }
    node*front=temp->next;
    node*back=front->back;
    temp->next=new node(value);
    front->back=temp->next;
    temp->next->next=front;
    temp->next->back=back;
    return head;
  }
 node*insertk(node*head,int value, int k) {
  node*temp=head;
  if(head==NULL) {
    if(k==1) {
      return new node(value);
    }
  }
  int count=0;
  while(temp!=NULL) {
    count++;
    if(count==k-1) {
      break;
    }
    temp=temp->next;
  }
  node*front=temp->next;
  // node*front=temp->next;
  // node*back=front->back;
  // temp->next=new node(value);
  // temp=temp->next;
  // temp->next=front;
  // temp->back=back;
  // front->back=temp;
  node*newnode=new node(value);
  temp->next=newnode;
  front->back=newnode;
  newnode->back=temp;
  newnode->next=front;
  return head;
 }
 node*reversedll( node*head) {
  if(head==NULL || head->next==NULL) {
    return head;
  }
  node*current=head;
  node*prev=NULL;
  while(current!=NULL) {
    prev=current->back;
    current->back=current->next; 
    current->next=prev;
    current=current->back;
  }
  return prev->back;
 }
 void printll(node*head) {
  while(head!=NULL) {
    cout << head->data << " ";
    head=head->next;
  }
  }
signed main() {
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
      int x;
      cin >> x;
      arr.push_back(x);
    }
    node*head=convertarrtodll(arr);
    //head=deletek(head,1);
    head=reversedll(head);
    printll(head);
  return 0;
}
