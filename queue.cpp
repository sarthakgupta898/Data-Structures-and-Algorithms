#include <iostream>
using namespace std;

template <typename t>
class Queue{
	t *arr;
	int front;
	int rear;
	int curr_size;
	int max_size;

public:
	Queue(int ds=4){
		front=0;
		max_size=ds;
		rear=max_size-1;
		arr=new t[max_size];
		curr_size=0;
	}

	bool isFull(){
		return curr_size==max_size;
	}

	bool isEmpty(){
		return curr_size==0;
	}

	void push(t data){
		if(!isFull()){
			rear=(rear+1)%max_size;
			arr[rear]=data;
			curr_size++;
		}
	}

	void pop(){
		if(!isEmpty()){
			front=(front+1)%max_size;
			curr_size--;
		}
	}

	t getFront(){
		return arr[front];
	}
};

int main(){
   Queue<int> q(10);

   for(int i=1;i<=6;i++){
       q.push(i);
   }
   q.pop();
   q.push(8);

   while(!q.isEmpty()){
       cout<<q.getFront()<<" ";
       q.pop();
   }

    return 0;

}