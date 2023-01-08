#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* CreatANode(int value)
{
	Node* temNode = new Node;
	temNode->data = value;
	temNode->next = NULL;
	return temNode;
}

Node* AddANode(Node* pNode, int value)
{
	Node* newNode = CreatANode(value);
	pNode->next = newNode;
	return newNode;
}

void PrintListNode(Node* pNode)
{
	Node* tem = pNode;
	while (tem->next != NULL)
	{
		cout << tem->data << " ";
		tem = tem->next;
	}
	cout << tem->data;
	delete tem;
}
int main()
{
	int n = 0, x = 0;
	std::cout << "Nhap vao so luong node: ";
	std::cin >> n;
	cout << "Nhap vao gia tri cho node dau tien: ";
	cin >> x;
	Node* p0 = CreatANode(x);
	Node* l = p0;
	for (int i = 1; i < n; i++)
	{
		cout << "Nhap gia tri cho node " << i + 1 << ": ";
		cin >> x;
		l = AddANode(l,x);
	}
	PrintListNode(p0);
	l = NULL;
	p0 = NULL;
	delete l;
	delete p0;
	return 0;
}