#include <bits/stdc++.h>
using namespace std;
//#define int long long
// class node { 
// class helps us to access inheritance ,encapsulation,abstraction etc
struct node {
    public:
    int data;
    node* next;
    node(int data, node* next) {
        this->data=data;
        this->next=next;
    }
    node(int data1) {
        data=data1;
        next=nullptr;
    }
};
node* convertarrtoll(vector<int> &arr) {
    node* head=new node(arr[0]);
    node* mover=head;
    for(int i=1; i<arr.size(); i++) {
        node* temp=new node(arr[i]); 
        mover->next=temp;
         mover=temp;
    }
    return head;
};
// to delete head
node*deletehead(node*head) {
    node*temp=head;
    head=head->next;
    free(temp); //  delete temp;
    return head;
}
// to remove tail
node*deletetail(node*head){
    if(head==NULL || head->next==NULL) {
        return NULL;
    }
    node*temp=head;
    while(temp->next->next!=NULL) {
        temp=temp->next;
    }
    free(temp->next); // or delete temp->next;
    temp->next=nullptr; 
    return head;
}
// to delete the kth element
node*deletek(node*head,int k) {
    if(head==NULL) {
        return head;
    }
    if(k==1) {
        node*temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int count=0;
    node*temp=head;
    node*prev=NULL;
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
void printll(node*head) {
    while(head!=nullptr) {
        cout << head->data << " ";
        head=head->next;
    }
}
int main() {
   int n;
   cin >> n;
   vector<int> arr;
   for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
   }
   node*head=convertarrtoll(arr);
   head=deletek(head,3);
   printll(head);
//    node x=node(2,nullptr);
//    node*y=&x;
//    // or we can write
//    node*y1=new node(arr[0],nullptr);
//    cout << y << " " << y1 << endl;
//    cout << y.data << endl;
// this was wrong because dot is used for classes and objects where as y is a pointer and for pointer we use ->
//   
    return 0;
};
