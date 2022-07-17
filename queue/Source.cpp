#include<iostream> //Adding I/O Lib.
#include<string>
#include<iomanip> // I/O Manipulation Lib.
using namespace std; 
template<class ItemType>
class Queue // Creating a que Class
{
	//Private Data Members
private:
	//For front and rear elements
	int front, rear;
	//For Count and max Numbers of Elements in Que
	int count, maxQue;
	ItemType* items; // For Storing Elements
public:
	//Public Member Functions
	//----------- Constructors --------//
	Queue() //Default
	{
		this->maxQue = 500; // Assiging Val
		// Initializing it With Zeros
		this->count = this->front = this->rear = 0;
		items = new ItemType[maxQue]; // Creating an Array
	} 
	Queue(int Max) //Parameterized
	{
		this->maxQue = Max; // Assiging Val
		// Initializing it With Zeros
		this->count = this->front = this->rear = 0;
		items = new ItemType[maxQue]; // Creating an Array
	}
	//-----------------------------------//
	bool isEmpty()const
	{
		//Returning True if Count = 0
		return (this->count == 0); 
	}
	bool isFull()const
	{
		//Returning True if Count = MaxQue
		return (this->count == maxQue);
	}
	//-----------------------------------//
	void enQueue(ItemType item)
	{
		if (isFull())
		{
			//if Que is Full Print Error
			cerr << "Overflow..." << endl;
			exit(1);// Exit
		}
		else
		{
			items[rear] = item; // Adding val
			//To Achieve Wrap-Around Functionality
			rear = (rear + 1) % maxQue;
			++count; // Incrementing
		}
	}
	void deQueue(ItemType& item)
	{
		if (isEmpty())
		{
			//if Que is Full Print Error
			cerr << "Underflow..." << endl;
			exit(1);// Exit
		}
		else
		{
			item = items[front]; // retrieving Val
			//To Achieve Wrap-Around Functionality
			front = (front + 1) % maxQue;
			--count; // Decrementing
		}
	}
	//-----------------------------------------------//
};
int main()
{
	Queue<int> Que; // Creating an Object
	int n = 0;
	//Inserting Numbers
	for (int i = 1; i <= 10; i++)
	{
		cout << "Inserting Number " << setw(2) << setfill('0') << i << endl;
		Que.enQueue(i);
	}
	//Removing Numbers
	cout << "\nRemoving Numbers....\n" << endl;
	for (int i = 0; i < 10; i++)
	{
		Que.deQueue(n);
		cout << setw(2) << setfill('0') << n << endl;
	}

	/*
		Experiment By Calling Different Funcs. ;)
	*/


	system("PAUSE>0");
}