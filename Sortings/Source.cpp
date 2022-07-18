#include<iostream>
#include<ctime>
using namespace std;

// ----------- BUBBLE SORT ---------// 
template<class ItemType>
void BubbleSort(ItemType* Arr, int N)
{
	for (int i = N; i > 0; i--) // First For-Loop
	{
		for (int j = 0; j < i; j++)//Nesting Second For-Loop
		{
			if (Arr[j - 1] > Arr[j]) // If value is Greater
			{
				//then Swap
				swap(Arr[j - 1], Arr[j]); // Calling Swap Function
			}
		}
	}
}
// --------------  END ------------//


//***************************************************//
int main()
{
	cout << "Enter Size of an Array: ";
	int N = 0; cin >> N; // Input

	int* Arr = new int[N];// Creating an Array
	
	/*
		Creating Random Numbers
	*/
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		Arr[i] = 1 + rand() % 10;
	}

	/*
		Printing Random (Non-Sorted) Numbers
	*/
	for (int i = 0; i < N; i++)
	{
		cout << Arr[i] << " ";
	}

	/*
		NOTE: Uncomment the Sort You Want to Perform.
	*/

								// Applying Bubble Sort
	BubbleSort(Arr, N);


	/*
		Printing Sorted Array
	*/
	cout << "\nSorted Array..." << endl;
	for (int i = 0; i < N; i++)
	{
		cout << Arr[i] << " ";
	}

	system("PAUSE>0");
	return 0;
}
//***************************************************//