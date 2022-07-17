#include<iostream>	//Input Output Lib.
#include<string> // For Strings.
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
	//*******************************************//
	void insertAfter(ItemType oldVal, ItemType newVal)
	{
		NODEPTR newNode = new Node; // New Node
		newNode->info = newVal; // Stroting Info
		NODEPTR oldNode = SearchVal(oldVal); // Searching for Val
		newNode->Next = oldNode->Next; // Updating Links
		oldNode->Next = newNode;
	}
	//------------------------------------------------------------//

	//------- Other Imp. Functions -------//

	//************* Search Func. ****************//
	NODEPTR SearchVal(ItemType Val)
	{
		NODEPTR Temp = Head; // Assiging temp The Head
		while (Temp != NULL) // traversing
		{
			if (Temp->info == Val) // Comparing vals
			{
				return Temp; // returning Node on Find
			}
			Temp = Temp->Next; // Going to Next node
		}
		return NULL; // returning NULL if Not Found
	}
	//*******************************************//
	
	//*********** Node Counter ****************//
	int countNodes()
	{
		int Num = 0; // Initializing a Var.
		NODEPTR Temp = Head; // Assiging Temp the Head
		while (Temp!= NULL) // Traversing
		{
			Num++;// Incrementing 
			Temp = Temp->Next; // Going to next Node
		}
		return Num; // Returning Num
	}
	//*****************************************//

	//------ Delete Functions------//
	void DeleteHead(ItemType& info)
	{
		NODEPTR Temp = Head; // Assiging Head to Temp
		info = Temp->info; // Retrieving info
		Head = Temp->Next; // Assiging Head the Next Node
		delete Temp; // Delete the First
	}
	//**************************//
	void DeleteEndNode(ItemType& info)
	{
		NODEPTR Temp = Head; // Assiging Temp the Head
		NODEPTR P = new Node; // Getting another Node
		while (Temp->Next != NULL) // Traversing
		{
			P = Temp; // Assiging the P to Temp
			Temp= Temp->Next; // Going to Next
		}
		info = P->Next->info; // Retrieving Info
		P->Next = NULL; // Assiging the Last Null
		delete Temp; // Deleting Temp
	}
	//---------------------------------------

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
	//----------------------------------//
};
//-+-+-+-+-+-+-+-+-+-+-+-+- End Of Linked List Class -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-//

//-+-+-+-+-+-+-+-+-+-+-+-+- Start of Main Function -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-//
int main()
{
	/*
		Test Code
	*/

	Linked_List <int>List; // Creating an Obj. of integer Data Member

	//*********************************//

	List.insertAtTail(8);
	List.insertAtTail(9);
	List.insertAtTail(0);
	List.insertAtFront(2);
	List.insertAtFront(5);

	List.DisplayList();

	//**********************************//

	/*
			Experiment By Calling Functions ;)
	*/


	system("PAUSE>0"); //Calling a Pause
}
//-+-+-+-+-+-+-+-+-+-+-+-+- End Of Main Function -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-//
