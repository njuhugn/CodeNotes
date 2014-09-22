#include<cstdio>
#include<iostream>

using namespace std;

struct RandNode
{
	int data;
	RandNode* next;
	RandNode* rand;

	RandNode(int data): data(data),next(nullptr),rand(nullptr){}
	RandNode(int data, RandNode* next): data(data),next(next),rand(nullptr){}
	RandNode(int data, RandNode* next,RandNode* rand): data(data),next(next),rand(rand){}
};

extern RandNode* copyRandList(RandNode* old);

int main(){

	RandNode node4(4);
	RandNode node3(3,&node4);
	RandNode node2(2,&node3);
	RandNode node1(1,&node2);

	node1.rand = nullptr;
	node2.rand = &node4;
	node3.rand = &node1;
	node4.rand = &node2;

	cout<<"The old list:"<<endl;
	for(RandNode* p = &node1; p != nullptr; p = p->next)
	{
		if(p->next != nullptr && p->rand != nullptr)
			cout<<p->data<<" "<<p->next->data<<" "<<p->rand->data<<endl;
		else if(p->next == nullptr)
			cout<<p->data<<" "<<"NULL"<<" "<<p->rand->data<<endl;
		else if(p->rand == nullptr)
			cout<<p->data<<" "<<p->next->data<<" "<<"NULL"<<endl;
		else
			cout<<p->data<<" "<<"NULL"<<" "<<"NULL"<<endl;
	}
	cout<<endl;

	RandNode* copyHead = copyRandList(&node1);

	cout<<"The copy list:"<<endl;
	for(RandNode* p = copyHead; p != nullptr; p = p->next)
	{
		if(p->next != nullptr && p->rand != nullptr)
			cout<<p->data<<" "<<p->next->data<<" "<<p->rand->data<<endl;
		else if(p->next == nullptr)
			cout<<p->data<<" "<<"NULL"<<" "<<p->rand->data<<endl;
		else if(p->rand == nullptr)
			cout<<p->data<<" "<<p->next->data<<" "<<"NULL"<<endl;
		else
			cout<<p->data<<" "<<"NULL"<<" "<<"NULL"<<endl;
	}
	cout<<endl;

	return 0;
}

RandNode* copyRandList(RandNode* old)
{
	//1. generate the copy and merge the old and copy into the Big list
	for(RandNode* pOld = old; pOld != nullptr;)
	{
		RandNode* pNode = new RandNode(pOld->data);
		pNode->next = pOld->next;
		pOld->next = pNode; // copyNode[i] is between old[i] and old[i+1]

		pOld = pNode->next;
	}

	//2. copy the random pointers with the help of the Big list
	for(RandNode* pOld = old; pOld != nullptr;)
	{
		RandNode* pCopy = pOld->next;
		if(pOld->rand != nullptr)
			pCopy->rand = (pOld->rand)->next;
		
		pOld = pCopy->next;
	}

	//3. split the Big list into the old and the copy
	RandNode dummy(-1);
	for(RandNode *pOld=old, *pCopy=&dummy; pOld != nullptr;)
	{
		pCopy->next = pOld->next;
		pOld->next = pOld->next->next;

		pCopy = pCopy->next;
		pOld = pOld->next;
	}
	return dummy.next; // the head of the copy list

}