#include <bits/stdc++.h>
#define int long long
using namespace std;
class node{
  public:
  int data;
  node*next;
  node(int data) {
    this->data=data;
  }
  node(int data, node*next) {
    this->data=data;
    this->next=next;
  }
};
node*convertarrtoll(vector<int> &arr) {
  node*head=new node(arr[0]);
  node*mover=head;
  for(int i=1; i<arr.size(); i++) {
    node*temp=new node(arr[i]);
    mover->next=temp;
    mover=temp;
  }
  return head;
}
node*deletehead(node*head) {
  node*temp=head;
  head=head->next;
  free(temp);
  return head;
}
node*deletetail(node*head) {
  if(head==NULL || head->next==NULL) {
    return NULL;
  }
  node*temp=head;
  while(temp->next->next!=NULL) {
    temp=temp->next;
  }
  free(temp->next);
  temp->next=nullptr;
  return head;
}
node*deletek(node*head,int k) {
  if(head==NULL) {
    return NULL;
  }
  if(k==1)  {
    node*temp=head;
    head=head->next;
    free(temp);
    return head;
  }
  int count=0;
  node* prev=NULL;
  node*temp=head;
  while(temp!=NULL) {
    count++;
    if(count==k) {
      prev->next=prev->next->next;
      free(temp);
      break;
    }
    prev=temp;
    temp=temp->next;
  }
  return head;
}
node*deletevalue(node*head,int value) {
  node*temp=head;
  if(head==NULL) {
    return NULL;
  }
  if(head->data==value) {
    node*temp=head;
    head=head->next;
    free(temp);
    return head;
  }
  while(temp->next!=NULL)  {
    if(temp->next->data==value) {
      node*del=temp->next;
      temp->next=temp->next->next;
      free(del);
     //free(temp->next);
     break;
    }
    temp=temp->next;
  }
  // temp->next=temp->next->next;
  //free(temp);
  return head;
}
// insert elemnt at the head; 
node*inserthead(node*head,int val) {
  node*temp=new node(val,head);
  return temp;
}
// insert element at the last
node*inserttail(node*head,int val) {
  if(head==NULL) {
    return new node(val); 
  }
  node*temp=head;
  while(temp->next!=NULL) {
    temp=temp->next;
  }
  node*value=new node(val);
  temp->next=value;
  temp=temp->next;
  temp->next=nullptr;
  return head;
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
  return 0;
}
