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
// add two numbers
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
    node*newnode=new node(sum%10);
    current->next=newnode;
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
    node*newnode=new node(carry);
    current->next=newnode;
   }
   return dummynode->next;
}
// group odd and even index elements together 
node*oddeven(node*head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }
    int count=3;
    node*temp=head;
    node*head1=new node(temp->data);
    node*head2=new node(temp->next->data);
    temp=temp->next->next;
    node*temp1=head1;
    node*temp2=head2;
    while(temp!=NULL) {
        if(count%2==1) {
            node*newnode=new node(temp->data);
            temp1->next=newnode;
            temp1=temp1->next;
        }
        else {
            node*newnode=new node(temp->data);
            temp2->next=newnode;
            temp2=temp2->next;
        }
        count++;
         temp=temp->next;
    }
    temp1->next=head2;
    return head1;
}
// sort a ll of 0,1,2
node*sort(node*head) {
    node*temp=head;
    int count0=0;
    int count1=0;
    int count2=0;
    node*temp1=new node(0);
        node*temp2=new node(1);
        node*temp3=new node(2);
        node*head1;
        node*head2;
        node*head3;
    while(temp!=NULL) {
        if(temp->data==0) {
            if(count0!=0) {
            temp1->next=new node(0);
            temp1=temp1->next;
            }
            else {
                head1=temp1;
            }
            count0++;
        }
        if(temp->data==1) {
            if(count1!=0) {
            temp2->next=new node(1);
            temp2=temp2->next;
            }
            else {
                head2=temp2;
            }
            count1++;
        }
        if(temp->data==2) {
            if(count2!=0) {
            temp3->next=new node(2);
            temp3=temp3->next;
            }
            else {
                head3=temp3;
            }
            count2++;
        }
        temp=temp->next;
    }
    temp1->next=head2;
    temp2->next=head3;
    return head1;
}
// to remove the kth node from last
node*remove(node*head, int k, vector<int> &arr) {
    node*temp=head;
    int count=0;
    while(temp!=NULL) {
        if(count==arr.size()-k-1) {
            break;
        }
        temp=temp->next;
        count++;
    }
    node*prev=temp;
    node*temp1=prev->next;
    node*front=temp1->next;
    prev->next=front;
    free(temp1);
    return head;
}
// reverse a ll
node*reverse(node*head) {
    node*temp=head;
    node*prev=NULL;
    while(temp!=NULL) {
        node*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
// reverse using recursion
node*reverserecursion(node*head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }
    node*newhead=reverserecursion(head->next);
    node*front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
}
// check if a ll is palindrome or not
// bool palindrome(node*head) {
//     node*temp=head;
//     vector<int> vec1;
//     while(temp!=NULL) {
//         vec1.push_back(temp->data);
//         temp=temp->next;
//     }
//     //reverse(head);
//     node*temp1=head;
//     int count=0;
//     int i=vec1.size()-1;
//     while(temp1!=NULL) {
//         if(temp1->data!=vec1[i]) {
//             count++;
//         }
//         temp1=temp1->next;
//         i--;
//     }
//     if(count>0) {
//         cout << "NO" << endl;
//         return false;
//     }
//     else {
//         cout << "YES" << endl;
//         return true;
//     }
// }
bool palindrome(node*head) {
    if(head==NULL || head->next==NULL) {
        return true;
    }
    node*temp=head;
    node*slow=head;
    node*fast=head;
    int count=0;
    while(fast->next!=NULL) {
        if(fast->next!=NULL && fast->next->next==NULL) {
            count++;
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    node*mid=slow;
    node*newhead=reverserecursion(mid->next);
    node*first=head;
    node*second=newhead;
   // int count=0;
    while(second!=NULL) {
        if(first->data!=second->data) {
            return false;
        }
        first=first->next;
        second=second->next; 
    }
    reverse(newhead);
    return true;
}
// add 1 to a link list
node*add(node*head) {
    node*tempp=head;
    node*newhead=reverserecursion(head);
    node*temp=newhead;
    int carry=1;
    while(temp!=NULL) {
        int sum=0;
    sum=temp->data+carry;
    //temp->data=sum;
    int modulo=sum%10;
    carry=sum/10;
    temp->data=modulo;
    temp=temp->next;
    }
    newhead=reverserecursion(newhead);
    if(carry!=0) {
        node*newnode=new node(carry,head);
        return newnode;
    }
    return newhead;
}
// find the intersection of two linked list and return the first point where it started insecting
node*intersection(node*head1,node*head2) {
    node*temp1=head1;
    node*temp2=head2;
    map<node*,int> m;
    while(temp1!=NULL) {
        m[temp1]++;
        temp1=temp1->next;
    }
    while(temp2!=NULL) {
        auto it=m.find(temp2);
        if(it!=m.end()) {
            return temp2;
        }
        temp2=temp2->next;
    }
    return NULL;
}
node*intersection2(node*head1, node*head2) {
    if(head1==NULL || head2==NULL) {
        return NULL;
    }
    node*temp1=head1;
    node*temp2=head2;
    while(temp1!=temp2) {
            if(temp1==NULL) {
            temp1=head2;
        }
        else {
            temp1=temp1->next;
        }
        if(temp2==NULL) {
            temp2=head1;
        }
        else {
        temp2=temp2->next;
        }
    }
    return temp1;
}
// detect a loop in a link list
bool loop(node*head) {
    node*temp=head;
    unordered_map<node*,int> m;
    int count=0;
    while(temp!=NULL) {
        auto it=m.find(temp);
        if(it!=m.end()) {
            count++;
            break;
        }
        m[temp]++;
        temp=temp->next;
    }
    if(count>0) {
        cout << "YES" << endl;
        return true;
    }
    else {
        cout << "NO" << endl;
        return false;
    }
}
// find the length of the loop in a linked list
int counting(node*fast,node*slow) {
    int count=1;
    fast=fast->next;
    while(fast!=slow) {
        count++;
        fast=fast->next;
    }
    return count;
}
int length(node*head) {
    node*fast=head;
    node*slow=head;
    while(fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) {
            return counting(fast,slow);
        }
    }
    return 0;
}
// find the starting point of the loop if exists
node*start(node*head) {
    node*fast=head;
    node*slow=head;
    int count=0;
    while(fast!=NULL && fast->next!=NULL) {
        fast=fast->next;
        slow=slow->next;
        if(slow==fast) {
            count++;
            if(count==1) {
                slow=head;
            }
            else {
                return fast;
            }
        }
    }
    return NULL;
}
// removing duplicates in a sorted doubly linked list
node*deleteduplicate(node*head) {
    node*temp=head;
    while(temp!=NULL && temp->next!=NULL) {
    while(temp->data==temp->next->data && temp->next!=NULL) {
        node*front1=temp->next;
        //node*back1=temp->back;
        node*front2=front1->next;
        //node*back2=front2->back;
        temp->next=front2;
        if(front2!=NULL) {
            front2->back=temp;
        }
        //front2->back=temp;
        delete(front1);
    }
    temp=temp->next;
}
return head;
}
// reverse nodes in k groups
node*reverserecursionofk(node*head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }
    node*newhead=reverserecursion(head->next);
    node*front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
}
node*reverseofk(node*head, int k) {
    node*temp=head;
    node*prev=NULL;
    while(temp!=NULL) {
    int count=0;
    node*newhead;
    node*newprev;
    while(count<k-1 && temp!=NULL) {
        node*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    }
    return prev;
}
// reverse nodes in k groups
node*reversecount(node*head,int k) {
    node*temp=head;
    node*prev=NULL;
    int count=0;
    while(temp!=NULL && count<k-1) {
        node*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp->back=front;
        count++; 
    }
}
node*rversek(node*head) {
    node*temp=head;
    int count=0;
}
// node*reverse(node*head) {
//     node*temp=head;
//     node*prev=NULL;
//     while(temp!=NULL) {
//         node*front=temp->next;
//         temp->next=prev;
//         prev=temp;
//         temp=front;
//     }
//     return prev;
// }
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
    node*head=convertarrtoll(arr);
    // head=loop(head);
    //palindrome(head);
    //loop(head);
    int x=length(head);
    cout << x << endl;
    //printll(head);
  return 0;
}
