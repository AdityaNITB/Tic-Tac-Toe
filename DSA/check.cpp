#include <bits/stdc++.h>
#define int long long
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*back;
    node(int data, node*next, node*back) {
        this->data=data;
        this->next=next;
        this->back=back;
    };
    node(int data) {
        this->data=data;
        next=nullptr;
        back=nullptr;
    }
};
node*convertarrtodll(vector<int> &arr) {
    node*head=new node(arr[0]);
    node*mover=head;
    for(int i=1; i<arr.size(); i++) {
        node*temp=new node(arr[i],nullptr,mover);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
node*deletehead(node*head) {
    if(head==NULL) {
        return NULL;
    }
    node*temp=head;
    node*front=head->next;
    head=head->next;
    front->back=nullptr;
    temp->next=nullptr;
    free(temp);
    return head;
}
node*deletetail(node*head) {
    if(head==NULL) {
        return NULL;
    }
    if(head->next==NULL) {
        free(head);
        return NULL;
    }
    node*temp=head;
    while(temp->next->next!=NULL) {
        temp=temp->next;
    }
    node*front=temp->next;
    temp->next=nullptr;
    front->back=nullptr;
    free(front);
    return head;
}
node*deletek(node*head , int k) {
    int count=0;
    node*temp=head;
    while(temp->next!=NULL) {
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
    if(prev==NULL) {
        return deletehead(head);
    }
    if(front==NULL) {
        return deletetail(head);
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    free(temp);
    return head;
}
// node*deletehead(node*head) {
//     if(head==NULL) {
//       return head;
//     }
//     node*temp=head;
//     head=head->next;
//     head->back=nullptr;
//     temp->next=nullptr;
//     free(temp);
//     return head;
//   }
node*inserthead(node*head, int val) {
    node*temp=new node(val);
    temp->next=head;
    head->back=temp;
    return temp;
}
node*inserttail(node*head, int val) {
    if (head==NULL) {
        node*temp=new node(val,nullptr,nullptr);
        return temp;
    }
    node*temp=head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    node*front=new node(val,nullptr,temp);
    temp->next=front;
    return head;
}
node*insertk(node*head,int k, int val) {
    if(head==NULL) {
        return new node(val);
    }
    int count=1;
    node*temp=head;
    while(temp->next!=NULL) {
        if(count==k-1) {
            break;
        }
        temp=temp->next;
        count++;
    }
    node*front=temp->next;
    node*insert=new node(val,front,temp);
    temp->next=insert;
    front->back=insert;
    return head;
}
node*reversedll(node*head) {
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
node*sum(node*head1,node*head2) {
    node*dummynode=new node(-1);
    node*current=dummynode;
    node*temp1=head1;
    node*temp2=head2;
    int carry=0;
    while(temp1!=NULL || temp2!=NULL) {
        int sum=carry;
        if(temp1!=NULL) {
            sum+=temp1->data;
        }
        if(temp2!=NULL) {
            sum+=temp2->data;
        }
        node*put=new node(sum%10);
        current->next=put;
        current=current->next;
        carry=sum/10;
        if(temp1!=NULL) {
            temp1=temp1->next;
        }
        if(temp2!=NULL) {
            temp2=temp2->next;
        }
    }
    if(carry!=0) {
        node*temp=new node(carry);
        current->next=temp;
    }
}
void printdll(node*head) {
    while(head!=NULL) {
        cout << head->data << " ";
        head=head->next;
    }
}
// void printll(node*head) {
//   while(head!=NULL) {
//     cout << head->data << " ";
//     head=head->next;
//   }
//   }
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
    head=reversedll(head);
    printdll(head);
    return 0;
}