#include <iostream>
#include <vector>
using namespace std;

class Stack{
private:
	vector <int> v;
public:
	void push(int data){
		v.push_back(data);
	}
	bool empty(){
		return v.size()==0;
	}
	void pop(){
		if(!empty()){
			v.pop_back();
		}
	}
	int top(){
		cout<<v[v.size()-1];
	}
};

int main(){
	Stack s;
	for(int i=0;i<5;i++){
		s.push(i);
	}
	

	while(!s.empty()){
		s.top();
		s.pop();
	}
}