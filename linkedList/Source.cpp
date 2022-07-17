#include<iostream>	//Input Output Lib.
using namespace std; //Using a Standard
template<class ItemType>	//Template
//--+-+-+-+-+-+-+-+-+-+-+-+- Linked List Class -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-//
class Linked_List //Class Name
{
	//Private Struct and Data Member
private:
	struct Node // A Structure Of Node
	{
		ItemType info; // To Hold Info Of Any Data Type.
		struct Node* Next; // Next Element
	};
	typedef struct Node* NODEPTR;
	Node* Head; //An Object of Structure (Node)
public:
	//Public Member Functions//
	//---- Constructor -----//
	Linked_List() //Default Constructor
	{
		Head = NULL;
	}
	//------------------------//

	//------ Insert Functions ------//
	void insertAtFront(ItemType info)
	{
		NODEPTR N = new Node; // getting a New Node
		N->info = info; // Storing Info
		N->Next = Head; // Assigning head to next
		this->Head = N; // Assigning N to Head
	}
	//*********************************//
	void insertAtTail(ItemType info)
	{
		NODEPTR N = new Node; // Getting a New Node
		/*
			Storing Value in N and Assiging Next as Null
		*/
		N->info = info;
		N->Next = NULL;
		//Checking If We Have a Linked List or Not
		if (Head == NULL)
		{
			insertAtFront(info); // If Not Adding First Element
		}
		else // If We have a List
		{
			NODEPTR Temp = Head; //Creating a Temp
			while (Temp->Next != NULL) // Traversing 
			{
				Temp = Temp->Next; // going to Next
			}
			Temp->Next = N; // Assiging Next the N
		}
	}
	//------------------------------------------------------------//

	//------- Display Function -------//
	void DisplayList()
	{
		Node* Temp = Head; // Creating a Temporary
		while (Temp!= NULL) // Traversing
		{
			cout << Temp->info << "->"; // Printing Info
			Temp = Temp->Next; // Going to Next Element
		}
		cout << "NULL"; // Printing Null at Last
	}
	//----------------------------------
};
//-+-+-+-+-+-+-+-+-+-+-+-+- End Of Linked List Class -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-//

//-+-+-+-+-+-+-+-+-+-+-+-+- Start of Main Function -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-//
int main()
{
	/*
		Test Code
	*/

	Linked_List <int>L; // Creating an Obj.

	//*********************************//

	L.insertAtTail(8);
	L.insertAtTail(9);
	L.insertAtTail(0);
	L.insertAtFront(2);

	//**********************************//

	L.DisplayList(); // Calling Display


	system("PAUSE>0"); //Calling a Pause
}
//-+-+-+-+-+-+-+-+-+-+-+-+- End Of Main Function -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-//
