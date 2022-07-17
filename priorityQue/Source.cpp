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
		this->maxQue = 5; // Assiging Val
		// Initializing it With Zeros
		this->count = this->front = this->rear = 0;
		items = new ItemType[maxQue]; // Creating an Array
		for (int i = 0; i < maxQue; i++) // Initializing All Elements to 0
		{
			items[i] = 0;
		}

	}
	Queue(int Max) //Parameterized
	{
		this->maxQue = Max; // Assiging Val
		// Initializing it With Zeros
		this->count = this->front = this->rear = 0;
		items = new ItemType[maxQue]; // Creating an Array
		for (int i = 0; i < maxQue; i++) // Initializing All Elements to 0
		{
			items[i] = 0;
		}

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
	void DisplayQue()
	{
		if (isEmpty())
		{ //To Show that Que is Empty...
			for (int i = 0; i < maxQue; i++)
			{
				cout << setw(2) << setfill('0') << items[i] << "\t";
			}
			cout << "\t.....Que is Empty....";
		}
		else
		{
			for (int i = 0; i < maxQue; i++)
			{
				cout << setw(2) << setfill('0') << items[i] << "\t";
			}
		}
	}
	//-----------------------------------------------//
};
template<class ItemType> // Using Templates
class PQue // Defining Priority Queue Class
{
	//Private Data Members
private:
	Queue <ItemType>* pQ; // Array of Queues
	int PriLvl; // Data Member For Priority level
public:
	//Public Member Functions
	//--------- Constructors -----------//
	PQue() //Default
	{
		this->pQ = new Queue<ItemType>[10]; // Creating Array
	}
	PQue(int Lvls) //Parameterized
	{
		this->PriLvl = Lvls; // Assigning Levls
		this->pQ = new Queue<ItemType>[Lvls]; // Vreating Queues
	}
	//------------------------------------//

	//-------------------------------------//
	bool isFull_PQ(int priorityLvl)const
	{
		this->pQ[priorityLvl].isEmpty(); // Checking Queue per Priority
	}
	bool isEmpty_PQ(int priorityLvl)const
	{
		// Checking Queue per Priority
		this->pQ[priorityLvl].isEmpty();
	}
	//-----------------------------------//

	//-------------------------------------//
	void Insert_PQ(ItemType newItem, int priorityLvl)
	{
		// Inserting Items in Priotity Level of Queue
		this->pQ[priorityLvl].enQueue(newItem); 
	}
	void Remove_PQ(ItemType& oldItem, int priorityLvl)
	{
		//Removing item From particular priotiy Level
		this->pQ[priorityLvl].deQueue(oldItem);

	}
	//----------------------------------//

	void DisplayPQ()
	{
		for (int i = 0; i < PriLvl; i++)
		{
			//Printing
			this->pQ[i].DisplayQue();
			cout << endl;
		}
	}
	//-------------------------------//
};
int main()
{
	int n = 0;
	cout << "Enter Priority Lvls: "; cin >> n;
	PQue <int> P(n);
	int PriLvl = 0, choice = 0, value = 0;
	cout << "What operation do you want to perform?." << endl;
	do
	{
		cout << "\n0. To end program." << endl;
		cout << "1. To Enter Data in queue." << endl;
		cout << "2. To Remove Data From queue." << endl;
		cout << "3. To Display Priority Queue." << endl;
		cout << "4. To Clear Screen." << endl;
		cout << "\nChoice: "; cin >> choice; // Input
		switch (choice)
		{
		case 1:
			cout << "Enter an item to Enqueue from Right in the Queue: ";
			cin >> value;
			cout << "Enter Priority Level: "; cin >> PriLvl;
			P.Insert_PQ(value, PriLvl);
			cout << endl;
			break;
		case 2:
			cout << "Enter Priority Level to Dequeue from: "; cin >> PriLvl;
			P.Remove_PQ(value, PriLvl);
			cout << endl;
			break;
		case 3:
			cout << "\nDisplaying Priority Queue...\n" << endl;
			cout << "\nNOTE: All elements in Priority Queue are initialized to 0"
				<< endl;
			P.DisplayPQ();
			break;
		case 4:
			system("CLS");
			break;
		default:
			cout << "\nThank You For using the Program..." << endl;
			break;
		}
	} while (choice != 0);

	/*
		Experiment By Calling Different Funcs. ;)
	*/


	system("PAUSE>0");
	return 0;
}