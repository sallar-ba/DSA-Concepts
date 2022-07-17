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
		Node* Next; // Next Element
	};
	Node Head; //An Object of Structure (Node)
public:
	//Public Member Functions//
	//---- Constructors -----//
	Linked_List(); //Default Constructor
	~Linked_List();
};
//-+-+-+-+-+-+-+-+-+-+-+-+- End Of Linked List Class -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-//

//-+-+-+-+-+-+-+-+-+-+-+-+- Start of Main Function -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-//
int main()
{

	system("PAUSE>0"); //Calling a Pause
}
//-+-+-+-+-+-+-+-+-+-+-+-+- End Of Main Function -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-//
