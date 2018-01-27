# lab-3-sem-2-

#include<iostream>
using namespace std;

class Node {//element of the linked list
	public:
		int data;
		Node* next;
		Node* prev;

		Node() {//constuctor initializes an empty node
			data = 0;
			next = NULL;
		}
};

class LinkedList {
	private://head points to the start, tail to the end, and n is the number of elements in a linked list
		Node* head;
		Node* tail;
		int n;

	public:
		LinkedList() {
			head = NULL;
			tail = NULL;
			n = 0;
		}

		void insert(int x);
		void insertAt(int x, int i);
		void deletelast();
		void deleteAt(int i);
		void display();
		int countElements();
		void reversedisplay();
};

void LinkedList::insert(int x) {
	//temp points to the newly created node
	Node* temp = new Node;
	//the value input by the user, x is assigned to the node and since it's added to the end, it's next points to NULL
	temp->data = x;
	temp->next = NULL;
            //Checks if the list is empty or not and changes head or attaches the new node to the list accordingly
	if (head == NULL) {
		head = temp;
		temp->prev=NULL;
	} else {//attaches the new node after the last element through double link
		tail->next = temp;
		temp->prev=tail;
	}
	//changes the tail and increments the number of elements by one
		tail = temp;
		++n;
}

void LinkedList::insertAt(int i, int x) 
{    //checks if the number of elements in the list are enough to insert at position i
if (i > n) 
  {cout << "Linked List does not have that many elements \n";
	}
	//adds the element to the start,assigns the next of temp to the first element and changes the head to point at the new start
else if (i == 0) 
  {Node* temp = new Node;
		temp->data = x;
   //adds the element to the start of the list and makes the previous null, changes the value of head
		temp->next = head;
		temp->prev=NULL;
		head = temp;
		++n;
	} 
else if (i == n) 
  {//adds the node at the end of the list, identical to insert function
  	
  	insert(x);
	 
  }
  else 
  {
		Node* temp = new Node;
		temp->data = x;

		Node* locate = head;
                        //pointer variable locate transverses through the list to find position i-1
		for (int j=0; j<i-2; ++j) {
			locate = locate->next;
		}
                        //the new node points to the node which the (i-1)th node was pointing to, which in turn points to the new node 
	//temp is inserteed after locate with double link	
	  temp->next = locate->next;
		locate->next->prev=temp;
		locate->next = temp;
		temp->prev=locate;
		//increases the elements by one, as the node is successfully added
		++n;
	}
}

void LinkedList::deletelast()
{      Node* temp;
       temp=tail;
 //temp replaces tail and is attached back to the head
       tail=temp->prev;
       tail->next=NULL;
       delete temp;
       n--;
}

void LinkedList::deleteAt(int i) {
	if (i >= n) {
		cout << "Linked List does not have that many elements \n";
	} else if (i == 0) {
		//changes the head so that the first element is no longer in the list
		Node*temp;
		temp=head;
		//head shifts to next
		head = head->next;
		//the previous is null-ed
		head->prev=NULL;
		//deletes the temp
		delete temp;
		--n;
	} else if (i == n-1) {
		//the tail shifts to the element before the last and the last element is detached from the list
		deletelast();
	} else {    //locate pointer locates the (i-1)th element and makes it point to the (i+1)th element hence detaching the ith element from the list
		Node* locate = head;
		Node* temp;
		//locate transverses the list to find the element before the one to be deleted
		for (int j=0; j<i-2; ++j) {
			locate = locate->next;
		}
        temp=locate->next;
		//new node points to the second element after it
		locate->next = (locate->next)->next;
		//it points back to the element before it removing the last one 
		locate->next->prev=locate;
		delete temp;
		--n;
	}
}

void LinkedList::display() {
	if (head == NULL) {//no element in the list
		cout << "The list is empty." << endl;
	} else {
		Node* temp = new Node;
		temp = head;
		//temp pointer transverses through the list printing all elements
		while (temp != NULL) {//prints all data elements
			cout << temp->data<<" -> ";
			temp = temp->next;
		}cout<<endl;
		//delets temp pointer
		delete temp;
	}
}

void LinkedList::reversedisplay() {
	Node* temp = new Node;
		temp = tail;
		//temp pointer transverses through the list printing all elements from tail to head in reverse
		while (temp != NULL) {
			cout << temp->data <<" -> ";
			temp = temp->prev;}
			cout<<endl;
			delete temp;
}

int LinkedList::countElements()
{int j;
j=n;
	return j;}


int main() {
	LinkedList list1;
	int a=0;
	cout<<"Enter the number associated to the operation you want to do \n1.addnode\n2.add node at a certain position\n3.delete node\n4.Delete a particular element\n5.Display elements of the list\n6.Count elements in the list\n7.Displays the elements in reverse\n8.Exit\n";
	while(a!=8)
	{cin>>a;
	if(a==1)
	{cout<<"Enter the element to be inserted"<<endl;
	int x;
	cin>>x;
	list1.insert(x);
	}
	else if(a==2)
	{cout<<"Enter the element to be inserted and it's position\n"<<endl;
	int x;
	int i;
	cin>>x>>i;
	list1.insertAt(i,x);
		
	}
	else if(a==3)
	{list1.deletelast();}
	else if(a==4)
	{cout<<"Enter the position to be deleted\n";
	int i;
	cin>>i;
	list1.deleteAt(i);
	}
	else if(a==5)
	{list1.display();}
	else if(a==6)
	{int n;
	n=list1.countElements();
	cout<<"The number of elements are "<<n<<endl;
	}
	else if (a==7)
	{list1.reversedisplay();}
		
}

	
	return 0;
}
