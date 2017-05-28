#include <iostream>
#include <string>
using namespace std;
// Node structure
template <typename T>
struct NodeQ{
	T data; //data in the node 
	NodeQ *next; //pointer of data
};

//Queue implementation using linear singley linked list
template <typename T>
class queue{
public:
	NodeQ<T> *front, *back; //two pointers for front and back 
	// operations
	//constructor
	queue(){
		back = NULL;
		front = NULL;
	}

	void enQueue(T d); //function to insert values in the queue
	void deQueue(); //fucntion to delete values from the queue
	void display(); //function to display the queue
	void front1(); //function to display the value in front of the queue
	void back1(); //function to display the value at the back of the queue
};


template <typename T>
void queue<T>::front1(){
	cout << front->data << endl; //printing the data in the front Node of the queue
}//front1 ends
template <typename T>
void queue<T>::back1(){
	cout << back->data << endl; //printing the data in the back Node of the queue
}//back1 ends
template <typename T>
void queue<T>::enQueue(T d){
	NodeQ<T> *nodeptr = new NodeQ<T>; //creating a new node 
	nodeptr->data = d; //putting the data in the new node
	nodeptr->next = NULL; //making it point to null
	if (front == NULL) //if the node is empty ie front is null
		front = back = nodeptr; //then point the front and back to the new node pointer
	else{
		back->next = nodeptr; //otherwise insert the new node at the back of the queue by pointing the back pointer to the new node
		back = nodeptr;//making the back point towards the new Node
	}
}//end enQueue
template <typename T>
void queue<T>::deQueue(){
	NodeQ<T>* temp = front;//creating a temprory pointer to point towards the front 
	front = front->next; //make the front node point towards the next node
	delete temp;//and delete the temprory node 
	if (!front)//if front is equal to null then make the back NULL
		back = NULL;
}//dequeu ends
template <typename T>
void queue<T>::display(){
	NodeQ<T> *temp = front; //making a new temporary Node to point towards the front node
	while (temp){
		cout << temp->data<<"->" ; //print the data in the temp 
		temp = temp->next;  //traversing to the next node 
	}//while ends
	if (back == NULL && front == NULL) //if front and back are empty then print EMPTY else print NULL 
		cout << "Empty" << endl;
	else
		cout << "NULL" << endl;
}//display ends
//main
int main()
{
	queue<int> qe;
	qe.enQueue(100); //inserting 100,200,300,400,500 
	qe.display();//displaying after each insertion
	qe.enQueue(200);
	qe.display();
	qe.enQueue(300);
	qe.display();
	qe.enQueue(400);
	qe.display();
	qe.enQueue(500);
	qe.display();
	qe.deQueue();//deleting from queue 
	qe.display();//displaying after each deletion
	qe.deQueue();
	qe.display();
	qe.deQueue();
	qe.display();
	qe.deQueue();
	qe.display();
	qe.deQueue();
	qe.display();

}//main ends