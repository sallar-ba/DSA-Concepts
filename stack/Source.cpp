#include<iostream> //Including I/O Lib.
using namespace std; // Standard Namespace
template<class ItemType> // Using Templates
class Stack // Class Named Stack
{
//Private Data Members
private:
	//To Indicate the Top of Stack and Max Number
	//of Elements in Stack.
	int top, maxStack; 
	//Items to Store Data
	ItemType* items;
//Public Member Functions
public:
	//----- Constrcutors -----//
	Stack() //Default Constructor
	{
		this->maxStack = 500; // Assiging a Val
		this->top = -1; // Starting it With -1
		this->items = new ItemType[maxStack]; // Creating an Array
	}
	//Parameterized Constructor
	Stack(int Max)
	{
		// Assiging a Val
		this->maxStack = Max; 
		// Starting it With -1
		this->top = -1; 
		// Creating an Array
		this->items = new ItemType[maxStack]; 
	}
	//---------------------------//
	bool isEmpty() const
	{
		// returning True if top is -1
		return (top == -1); 
	}
	//--------------------------//
	bool isFull() const
	{
		// returning True if top = Max value
		return (top == maxStack - 1); 
	}
	//--------------------------//
	void Push(ItemType newItem)
	{
		//Checking if the Stack is Full or Not
		if (isFull())
		{
			//if Full Printing Error
			cerr << "Stack Overflow..." << endl;
			exit(1); // Exiting
		}
		else
		{
			//if Stack is Not Full
			top++; // Incrementing
			items[top] = newItem; // Adding Item to Stack
		}
	}
	//----------------------------//
	void Pop()
	{
		if (isEmpty())
		{
			//if empty Printing Error
			cerr << "Stack Underflow..." << endl;
			exit(1); // Exiting
		}
		else
		{
			// if Not Empty
			top--; // Removing Top
		}
	}
	//Overloaded Function to get value
	void Pop(ItemType& Item)
	{
		if (isEmpty())
		{
			//if empty Printing Error
			cerr << "Stack Underflow..." << endl;
			exit(1); // Exiting
		}
		else
		{
			//if not Empty Retrieving value 
			Item = items[top];
			top--;// Decrementing/Removing top
		}
	}
	//-----------------------------------------
};

//------------- Start Main ----------------//
int main()
{
	Stack<int> Stk; // Creating a Stack

	//For Loop to Add Elements into Stack
	for (int i = 0; i < 10; i++)
	{
		Stk.Push(i);// Pushing Elements
	}

	//Printing Elements
	int item = 0;
	for (int i = 0; i < 10; i++)
	{
		Stk.Pop(item);
		cout << item << " ";
	}

	/*
		Experiment By Calling Different Funtions ;)
	*/

	system("PAUSE>0"); // System Call For Pause
}
//------------------- End Main ---------------------//