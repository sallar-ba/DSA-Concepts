//Sallar Bin Aamir
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
		******* ALGORITHM FOR SELECTION SORT *******

	Algorithm selectionSort (A, n)
	Input An array A of n elements
	Output Array A arranged in ascending order
		for i <- 0 to n-2 do
			min <- i
			for j <- i+1 to n-1 do
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


/*
		******* ALGORITHM FOR INSERTION SORT *******

	Algorithm inserttionSort (A, n)
	Input An array A of n elements
	Output Array A arranged in ascending order
		for i <- 1 to n
			current <- A[i]
			j <- i - 1
			while A[j]>current && j >= 0
				A[j + 1] = A[j]
				j--
			A[j + 1] = current
*/

// ----------- INSERTION SORT ---------// 
template<class ItemType> // Using Templates
void InsertionSort(ItemType*& Arr, int N)
{
	for (int i = 1; i < N; i++)
	{
		int Current = Arr[i]; // Assiging the Next Element as Current
		int j = i - 1; //Prev Element
		while (Arr[j]>Current && j>= 0) //Checking 
		{
			Arr[j + 1] = Arr[j]; // Moving elements
			j--; // Decrementing J
		}
		Arr[j + 1] = Current; // Updating Array
	}
}
// -------------------- END ---------------------// 

/*
	******* ALGORITHM FOR MERGE SORT *******

	Algorithm MergeSort (A, L, R)
	Input An array A and L and R
	Output Array A arranged in ascending order
		if L<R
			Mid = (L+R)/2
			MergeSort(Arr, L, Mid)
			MergeSort(Arr, Mid+1, R)

			Merge(Arr, L, Mid, R)

*/


//----------- MERGE SORT ---------------//
template<class ItemType>
void Merge(ItemType*& Arr, int L, int Mid, int R)
{
	int N1 = Mid - L + 1;
	int N2 = R - Mid;

	// Temporary Arrays
	ItemType* A = new ItemType[N1];
	ItemType* B = new ItemType[N2];

	// Adding Elements into Array
	for (int i = 0; i < N1; i++)
	{
		A[i] = Arr[L + i];
	}
	for (int i = 0; i < N2; i++)
	{
		B[i] = Arr[Mid + 1 + i];
	}
	int i = 0, j = 0, k = L;
	while (i<N1 && j<N2)
	{
		if (A[i] < B[j])
		{
			Arr[k] = A[i];
			k++; i++;
		}
		else
		{
			Arr[k] = B[j];
			k++; j++;
		}
	}
	while (i<N1)
	{
		Arr[k] = A[i];
		k++; i++;
	}
	while (j<N2)
	{
		Arr[k] = B[j];
		k++; j++;
	}
}
template<class ItemType>
void MergeSort(ItemType*& Arr, int L, int R)
{
	if (L < R)
	{
		//Recursive
		int Mid = (L + R) / 2;
		MergeSort(Arr, L, Mid);
		MergeSort(Arr, Mid + 1, R);

		Merge(Arr, L, Mid, R);
	}
}
//--------------------- END -----------------//


//----------- QUICK SORT ---------------//

template<class ItemType>
int Partition(ItemType*& Arr, int L, int R)
{
	int Pivot = Arr[R];
	int i = L - 1;
	for (int j = L; j < R; j++)
	{
		if (Arr[j] < Pivot)
		{
			i++;
			swap(Arr[i], Arr[j]);
		}
	}
	int k = i + 1;
	swap(Arr[k], Arr[R]);
	return k;
}
template<class ItemType>
void quickSort(ItemType*& Arr, int L, int R)
{
	if (L<R)
	{
		int Pivot = Partition(Arr, L, R);

		quickSort(Arr, L, Pivot - 1);
		quickSort(Arr, Pivot + 1, R);
	}
}
//-------------------- END --------------------//

//----------- HEAP SORT ---------------//
template<class ItemType>
void Heapify(ItemType*& Arr, int N, int i)
{
	int Largest = i;
	int Left = (2 * i) + 1, Right = (2 * i) + 2;
	if (Left < N && Arr[Left] > Arr[Largest])
	{
		Largest = Left;
	}
	if (Right<N && Arr[Right] > Arr[Largest])
	{
		Largest = Right;
	}
	if (Largest != i)
	{
		swap(Arr[i], Arr[Largest]);
		Heapify(Arr, N, Largest);

	}

}
template<class ItemType>
void HeapSort(ItemType*& Arr, int N)
{
	for (int i = (N/2) - 1; i >= 0; i--)
	{
		Heapify(Arr, N, i);
	}
	for (int i = N - 1; i > 0; i--)
	{
		swap(Arr[0], Arr[i]);
		Heapify(Arr, i, 0);
	}

}
//-------------------- END --------------------//



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
	//SelectionSort(Arr, N);

								// Applying Insertion Sort
	//InsertionSort(Arr, N);

								// Applying Merge Sort
	//MergeSort(Arr, 0, N - 1);
	
								// Applying Quick Sort
	//quickSort(Arr, 0, N - 1);

								// Applying Heap Sort
	HeapSort(Arr, N);

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