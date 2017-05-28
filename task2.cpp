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
	NodeQ<T> *top;
	NodeQ<T> *front, *back; //two pointers for front and back 
	// operations
	//constructor
	queue(){
		top = NULL;
		back = NULL;
		front = NULL;
	}
	//functions for queue
	void enQueue(T d); //function to insert values in the queue
	void deQueue(); //fucntion to delete values from the queue
	void display(); //function to display the queue
	T front1(); //function to display the value in front of the queue
	T back1(); //function to display the value at the back of the queue
	bool isEmptyq();//to check whether the queue is empty 
	//functions for stack
	void push(T d); // insert item into stack
	void pop(); // delete item from stack
	T stackTop(); // get content at top stack
	bool isEmptys(); // check whether stack is empty
	
};

template <typename T>
bool queue<T>::isEmptyq()
	{
		return back == NULL && front == NULL;
	}
template <typename T>
bool queue<T>::isEmptys()
	{
		return (top == NULL);//if top is NULL stack is empty else return false
	}
template <typename T>
void queue<T>::push(T d)
	{ // create newnode
		NodeQ<T> *nodeptr = new NodeQ<T>;
		if (nodeptr == NULL)
			cout << "Cannot allocate memory…" << endl;
		else // add to empty stack, or to front stack
		{
			nodeptr->data = d; //assign the data to the new node
			nodeptr->next = top; //point it to where the top is pointing 
			top = nodeptr; //make the top point to the newnode
		}// end if
	} //end push operation
template <typename T>
void queue<T> ::pop()
	{
		NodeQ<T> *temp = top; //making a temporary node and pointing it to top 
		top = top->next; //making the top point towards the next node 
		delete temp;//delete the temporary node
	}//pop ends
template <typename T>
T queue<T>::stackTop()
	{
		return top->data;  //return the data in the Top
	} // stacktop ends

template <typename T>
T queue<T>::front1()
	{
		return front->data; //returns the data in the front 
	}//front1 ends
template <typename T>
T queue<T>::back1()
	{
		return back->data; //return the data at the back
	}//back1 ends
template <typename T>
void queue<T>::enQueue(T d)
	{
		NodeQ<T> *nodeptr = new NodeQ<T>; //creating a new node 
		nodeptr->data = d; //putting the data in the new node
		nodeptr->next = NULL; //making it point to null
		if (front == NULL) //if the node is empty ie front is null
			front = back = nodeptr; //then point the front and back to the new node pointer
		else
		{
			back->next = nodeptr; //otherwise insert the new node at the back of the queue by pointing the back pointer to the new node
			back = nodeptr;//making the back point towards the new Node
		}
	}//end enQueue
template <typename T>
void queue<T>::deQueue()
	{
		NodeQ<T>* temp = front;//creating a temprory pointer to point towards the front 
		front = front->next; //make the front node point towards the next node
		delete temp;//and delete the temprory node 
		if (!front)//if front is equal to null then make the back NULL
			back = NULL;
	}//dequeu ends
template <typename T>
void queue<T>::display()
	{
		NodeQ<T> *temp = front; //making a new temporary Node to point towards the front node
		while (temp)
		{
			cout << temp->data<<endl; //print the data in the temp 
			temp = temp->next;  //traversing to the next node 
		}//while ends
	}//display ends
//main
int main()
{
	queue<char> qe;
	cout << "Enter the charachter one by one " << endl;
	cout << "press * when done entering" << endl;
	char a;   //defining a charachter to store the input
	while (cin>>a)
	{ //while we are taking input this loop should run
		if (a == '*') //if the * if entered that means the user is done entering number then break out of the loop
			break;
		qe.push(a); //push the input charachter in the stack
		qe.enQueue(a); //enqueue the value in queue
	}//while ends 
	while (!qe.isEmptys() && !qe.isEmptyq()) //while stack and queue are not empty 
	{
		char x = qe.front1(); //store the charachter in the front of the queue in x 
		qe.deQueue(); //deque the front element 
		char y = qe.stackTop(); //stor the top element to be poped in y 
		qe.pop(); //pop the element at the top
		if (x != y) //if both are not equal then end the program
		{
			cout << "This is not a Palindrome " << endl;
			exit(0);
		}//if ends
	}//while ends
	cout << "This is a palindrome" << endl; //if both stack and queue becomes empty then this is a palindrome
}//main ends
