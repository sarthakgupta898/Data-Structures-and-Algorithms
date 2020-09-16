#include <iostream>
using namespace std;
class node{
public:
	int data;
	node* next;
	node(int d):data(d),next(NULL){

	}
};

void InsertAtHead(node *&head,int data){
	node* n=new node(data);
	n->next=head;
	head=n;
	return;
}

void InsertAtTail(node*&head,int data){
	node *tail=head;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	tail->next=new node(data);
	return;
}

void InsertAtMiddle(node*&head,int data,int position){
	int jump=0;
	node* temp=head;
	while(jump<position-1){
		temp=temp->next;
		jump += 1;
	}
	node* n=new node(data);
	n->next=temp->next;
	temp->next=n;
	return;
}

int length (node*head){
	int len=0;
	while(head->next!=0){
		head=head->next;
		len += 1;
	}
	return len;
}

void reverse(node*&head){
	node* C=head;
	node* P=NULL;
	node* N;
	while(C!=NULL){
		N=C->next;
		C->next=P;
		P=C;
		C=N;
	}
	head =P;
}

bool Search(node*&head,int key){
	while(head!=NULL){
		if(head->data==key){
			return true;
		}
		head=head->next;
	}
	return false;
}

void print(node* head){
	while(head!=NULL){
		cout<<head->data<<' ';
		head=head->next;
	}
}

void BuildList(node *&head){
	int data;
	cin>>data;
	while(data!=-1){
		InsertAtTail(head,data);
		cin>>data;
	}
}

istream& operator>>(istream &is,node*&head){
	BuildList(head);
	return is;
}

ostream& operator<<(ostream &os,node*&head){
	print(head);
	return os;
}


int main(){
	node *head=NULL;
	InsertAtHead(head,5);
	InsertAtTail(head,2);
	InsertAtTail(head,3);
	InsertAtTail(head,4);
	InsertAtMiddle(head,7,2);
	print(head);

	cin>>head;
	cout<<head;
	return 0;
}