#include<iostream> // Adding I/O Lib
using namespace std;
template<class ItemType> // using Templates
class Queue // Queue Class
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
		for (int i = 0; i < maxQue; i++)
		{
			items[i] = 0; // Initializing Elements to Zero
		}

	}
	Queue(int Max) //Parameterized
	{
		this->maxQue = Max; // Assiging Val
		// Initializing it With Zeros
		this->count = this->front = this->rear = 0;
		items = new ItemType[maxQue]; // Creating an Array
		for (int i = 0; i < maxQue; i++)
		{
			items[i] = 0;// Initializing Elements to Zero
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
	void Insert_Right(ItemType newItem)
	{
		if (isFull())
		{
			//if Queue is Full Print Error
			cerr << "\nOverflow..." << endl;
			exit(1); // Exiting
		}
		else
		{
			//Else Insert item to Queue From right
			items[rear] = newItem;
			if (count != maxQue - 1)
			{
				rear = (rear - 1) % maxQue;
			}
			++count;// Incrementing
		}
	}
	void Remove_Right(ItemType& item)
	{
		if (isEmpty())
		{
			//if Queue is Empty
			cerr << "\nUnderflow..." << endl;
			exit(1); // Exiting
		}
		else
		{
			//if not Empty
			item = items[rear]; // Retreiving info
			items[rear] = 0;
			rear = (rear + (maxQue - 1)) % maxQue; // Wrap Around
			--count; // Decrementing
			if (count == 0)// If It's Last element
			{
				rear = front = 0;
			}
		}
	}
	void Insert_Left(ItemType newItem)
	{
		if (isFull())
		{
			//if Queue is Full Print Error
			cerr << "\nOverflow..." << endl;
			exit(1); // Exiting
		}
		else
		{
			//Else insert info from Left
			front = (front + (maxQue - 1)) % maxQue;
			items[front] = newItem; // Adding info
			++count; // incrementing
		}
	}
	void Remove_Left(ItemType& item)
	{
		if (isEmpty())
		{
			//if Queue is Empty
			cerr << "\nUnderflow..." << endl;
			exit(1); // Exiting
		}
		else
		{
			//Else Remove element from Left
			item = items[front]; // Retrieving info from front
			items[front] = 0;
			front = (front + 1) % maxQue;
			--count; // Decrementing
			if (count == 0) // If Last Element
			{
				rear = front = 0;
			}
		}
	}
	//------------------------------------------------------------
	void Peek()
	{
		//Displaying Front & Rear
		cout << "\nFront: " << front << endl;
		cout << "Rear: " << rear << endl;
	}
	//-----------------------------------------------//
	void display()
	{
		if (isEmpty())
		{
			//if Queue is Empty
			cerr << "\nUnderflow..." << endl;
		}
		else
		{
			//Printin Items
			cout << endl << endl;
			cout << "Queue: ";
			for (int i = 0; i < maxQue; i++)
			{
				cout << items[i] << " "; // Output
			}
			cout << endl << endl;
		}

	}
	//----------------------------------------------//
};
int main()
{
	Queue<int> Q(5);
	int value = 0, ch = 0;
	do
	{
		cout << "--------------------------------------" << endl;
		cout << "Enter 0 to End the Program." << endl;
		cout << "Enter 1 to Insert Right." << endl;
		cout << "Enter 2 to Insert Left." << endl;
		cout << "Enter 3 to Remove Right." << endl;
		cout << "Enter 4 to Remove Left." << endl;
		cout << "Enter 5 to Display." << endl;
		cout << "Enter 6 to Peek." << endl;
		cout << "Enter 7 to Clear Screen." << endl;
		cout << "-------------------------------------" << endl;
		cout << "\nEnter Choice: "; cin >> ch;
		switch (ch)
		{
		case 0:
			break;
		case 1:
			cout << "\nEnter Value to Enter From the Right: "; cin >> value;
			Q.Insert_Right(value);
			cout << endl;
			break;
		case 2:
			cout << "\nEnter Value to Enter From the Left: "; cin >> value;
			Q.Insert_Left(value);
			cout << endl;
			break;
		case 3:
			cout << "\nEnter Value to Remove From the Right: "; cin >> value;
			Q.Remove_Right(value);
			cout << "\nValue Remove: " << value << endl;
			cout << endl;
			break;
		case 4:
			cout << "\nEnter Value to Remove From the Left: "; cin >> value;
			Q.Remove_Left(value);
			cout << "\nValue Remove: " << value << endl;
			cout << endl;
		case 5:
			cout << "\nDiplaying All Element in the Queue..." << endl;
			Q.display();
			break;
		case 6:
			Q.Peek();
			cout << endl;
			break;
		case 7:
			system("CLS");
			break;
		default:
			cout << "Invalid Option Selected..." << endl;
			break;
		}
	} while (ch != 0);

	system("pause>0");
	return 0;
}