#include<iostream>
#include<ctime>
using namespace std;

/*
		******* ALGORITHM FOR BUBBLE SORT ******* 

		Algorithm bubbleSort (A, n)
		Input An array A of n elements
		Output Array A arranged in ascending order
			for i <- n-1 downto 1 do
				for j <- 1 to i do
					if A[j-1] > A[j] then
						Swap(A[j-1], A[j] )
*/

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

/*
	Algorithm selectionSort (A, n)
	Input An array A of n elements
	Output Array A arranged in ascending order
		for i <- 0 to n-1 do
			min <- i
			for j <- i+1 to n do
				if A[j] < A[min] then
					min <- j
		    Swap (A[i], A[min] )
*/


// ----------- SELECTION SORT ---------// 
template<class ItemType> // Using Templates
void SelectionSort(ItemType*& Arr, int N)
{
	int Min = 0; // Decalring Variables
	for (int i = 0; i < N - 1; i++) // First For-Loop
	{
		Min = i; // Taking The First Element
		for (int j = i + 1; j < N ; j++) //Nested For Loop
		{
			if (Arr[j]< Arr[Min]) // Checking For minimum Element
			{
				Min = j; // Assigning minimum Elmenent index to Min
			}
		}
		swap(Arr[i], Arr[Min]); // Swapping
	}
}
// -------------------- END ---------------------// 

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
	//BubbleSort(Arr, N);

								// Applying Selection Sort
	SelectionSort(Arr, N);

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