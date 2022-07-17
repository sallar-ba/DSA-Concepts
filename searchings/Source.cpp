#include<iostream>//Input Output Lib.
#include<vector>
#include<ctime> // For Random
#include<algorithm> 
using namespace std;

// NOTE THAT ALL ALGOS CONTAIN TABLE BUT CODE CONTAINS ARRAYS (VECTORS)

		    // ------ SEQUENTIAL SEARCHING ------ //
/*
	****THIS IS A SEARCHING WHEN THE LIST IS UNORDERED OR NOT-SORTED****

	- NORMAL SEQUENTIAL SEARCH...
	ALGORITHM:

	ALGORITHM SEQSEARCH(KEY, TABLE)
	INPUT THE KEY TO SEARCH IN THE TABLE
	OUTPUT LOCATION OF THE SEARCHED RECORD, -1 OTHERWISE
		
		FOR i <- 0 N-1 DO
			IF KEY = TABLE[i].K RETURN i
	RETURN -1
		
					"MAXIMUM COMPARISIONS = 2N"

---------------------------------------------------------------------------------

	- EFFICIENT SEQUENTIAL SEARCH...
	ALGORITHM:

	ALGORITHM SEQSEARCH&INSERT (KEY, TABLE)
	INPUT THE KEY TO SEARCH IN THE TABLE
	OUTPUT LOCATION OF THE SEARCHED RECORD, -1 OTHERWISE
		
		TABLE[N].K <- KEY
		i <- 0
		WHILE KEY != TABLE[i].K DO i++
		IF i = N
			TABLE[N++].R <- REC
		RETURN i

					"MAXIMUM COMPARISIONS = N + 1"
*/
template<class ItemType>
int seqSearch(ItemType Key, vector<ItemType> Arr)
{
	for (int i = 0; i < Arr.size(); i++)//LOOP
	{
		if (Key == Arr[i])//COMPARISION
		{
			return i;//RETURNING INDEX
		}
	}
	return -1;//RETURNING -1
}

			// ------ BINARY SEARCHING ------ //
/*
	****THIS IS A SEARCHING WHEN THE LIST IS ORDERED OR SORTED****

	ALGORITHM BINARYSEARCH(KEY, TABLE)
	INPUT THE KEY TO SEARCH FROM THE TABLE
	OUTPUT LOCATION OF THE SEARCHED RECORD, -1 OTHERWISE
		FIRST <- 0
		LAST <- N-1
		WHILE(FIRST<=LAST)
			MID <- (FIRST + LAST) / 2
			IF(KEY = TABLE[MID].K) RETURN MID
			IF(KEY < TABLE[MID].K)
				LAST <- MID - 1
			ELSE
				FIRST <- MID + 1
		RETURN -1

				"MAXIMUM COMPARISIONS = LOG2(N) + 1"

*/

template<class ItemType>
int BinarySearch(ItemType Key, vector<ItemType>Arr)
{
	//Sorting List Using STL
	sort(Arr.begin(), Arr.end());

	//Printing Sorted List
	cout << "\nSorted \n";
	for (auto x : Arr)
	{
		cout << x << " "; // Printing
	}

	int First = 0, Last = Arr.size(); // Declaring Var.
	while (First <= Last)
	{
		int Mid = (First + Last) / 2;
		if (Key == Arr[Mid])
		{
			return Mid; // Returning Mid If Val Found at Mid
		}
		if (Key < Arr[Mid])
		{
			Last = Mid - 1; // Decrementing Mid
		}
		else
		{
			First = Mid + 1; // Incrementing Mid
		}
	}
	return -1; //Returning -1
}


int main()
{
	//Initializing a Vector
	vector<int>Arr;

	//Generating Random Numbers
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Arr.push_back(1 + rand() % 10);
	}

	//Printing Random Numbers
	cout << "Random Numbers Generated..." << endl;
	for (int i = 0; i < Arr.size(); i++)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;

	//Sequential Search
	cout << "\nValue Found at Index: " << seqSearch(2, Arr) << endl;

	//Binary
	cout << "\n\nValue Found at Index: " << BinarySearch(2, Arr) << endl;

	system("PAUSE>0");
	return 0;
}