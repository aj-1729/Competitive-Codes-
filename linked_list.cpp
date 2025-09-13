#include<bits/stdc++.h>
#define int long long
#define MXI 1000000007LL
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

public:
	Node(int data1 , Node* next1 , Node* prev1)
	{
		data = data1;
		next = next1;
		prev = prev1;
	}
	Node(int data1 , Node* next1){
		data = data1;
		next = next1;
	}
	Node(int data1){
		data = data1;
		next = nullptr;
	}
};

Node* convertllarr(vector<int>& arr)
{
	int n = arr.size();
	Node* head = new Node(arr[0]);
	Node* curr = head;

	for(int i = 1 ; i < n ; i ++)
	{
		Node* temp = new Node(arr[i]);
		curr->next = temp;
		curr = temp;
	}

	return head;
}

Node* convertdllarr(vector<int>& arr)
{
	int n = arr.size();
	Node* head = new Node(arr[0]);
	Node* prev = head;

	for(int i = 1 ; i < n ; i ++)
	{
		Node* temp = new Node(arr[i] , nullptr , prev);
		prev->next = temp;
		prev = temp;
	}

	return head;
}


Node* insertnode(Node* head , int val)
{
	Node* lol = new Node(val , head);
	return lol;
}

Node* reversedll(Node* head)
{
	Node* temp = head;
	stack<int> s;

	while(temp != nullptr)
	{
		s.push(temp->data);
		temp = temp->next;
	}

	temp = head;

	while(temp != nullptr)
	{
		temp-> data = s.top();
		s.pop();
		temp = temp->next;
	}

	return head;
}

Node* reversedllop(Node* head)
{
	Node* curr = head;
	Node* temp = nullptr;

	while(curr != nullptr)
	{
		temp = curr->prev;

		curr->prev = curr->next;

		curr->next = temp;

		curr = curr->prev;
	}

	return temp-> prev;
}
int32_t main()
{
	vector<int> vec = {9 , 4 , 6 , 5 , 8};

	Node* x = convertdllarr(vec);

	x = reversedllop(x);

	Node* temp = x;

	while(temp)
	{
		cout << temp-> data << " " ;
		//if(temp -> data == 4) break;
		temp = temp->next;
	}

	//cout << temp->prev->data << " " << temp->next->data << endl;

}
