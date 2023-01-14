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

Node* AddAnyPosition(Node* pNode, int pos, int value)
{
	Node* newNode = CreatANode(value);
	Node* temp = pNode;
	for (int i = 1; i < pos-1; i++)
	{
		if (temp->next != NULL)
			temp = temp->next;
		else
			break;
	}
	if (pos != 1)
	{
		newNode->next = temp->next;
		temp->next = newNode;
	}
	else
	{
		newNode->next = temp;
		pNode = newNode;
	}
	return pNode;
}

Node* RevertList(Node* head)
{
	Node* pre = NULL;
	Node* cur = head;
	Node* after = NULL;
	while (cur != NULL)
	{
		after = cur->next;
		cur->next = pre;
		pre = cur;
		cur = after;
	}
	head = pre;
	after = NULL;
	cur = NULL;
	return head;
}

Node* RevertCurList(Node* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	} 
	Node* Rest = RevertCurList(head->next);
	head -> next -> next = head;
	head->next = NULL;
	return Rest;
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
	//p0=AddAnyPosition(p0, 4, 4);
	PrintListNode(p0);
	//p0 = RevertList(p0);
	p0 = RevertCurList(p0);
	PrintListNode(p0);
	l = NULL;
	p0 = NULL;
	delete l;
	delete p0;
	return 0;
}