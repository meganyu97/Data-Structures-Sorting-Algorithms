//Megan Yu
//ID: 2263079
//yu204@mail.chapman.edu
//CPSC 350-01
//Assignment 6

//This project takes in a file from command line and reads in an array of unsorted numbers then uses three sorting 
//algorithms to order the data into numerical order. Time stamps are implemented to keep track of the start and end 
//times of the algorithms. 

#include <iostream>
#include <fstream> 
#include <time.h>
using namespace std; 

void insertSort(double* a, int n);
void quicksort(double *myArray, int lower, int upper);
int split(double *myarray, int lower, int upper);
int shellSort(double[], int);
void printArray(double[], int);

int main(int argc, char const *argv[])
{
	ifstream file; 
	istream &fin = (argc >1) ? (file.open(argv[1]), file) : cin;

	if (!fin)
	{
		cerr << argv[0] << ": " << argv[1] << ": " << "Unable to open file " << argv[1] << endl;
		return 2; 
	}
  	time_t start;
  	time_t end; 
    int loop;
    double* d;
  	fin >> loop;
  	// cout << loop; 
  	d = new double[loop];
  
  
   cout << "Unsorted array: " << endl;
  	for(int i = 0; i < loop; i++)
    {
      fin >> d[i];
      cout << d[i] << endl;
    }
  
  	cout << endl;
  	cout << endl;
    cout << endl;
  	start = time(0);
  	cout << "Insert Sort Start time: "<< start << endl;
  	insertSort(d, loop);
  	end = time(0);
  	cout << "Insert Sort End time: "<< end << endl;
  	cout << "Insert Sort time difference: " << end - start << endl; 
  	cout << "Insert Sort - Sorted array: " << endl;
  	printArray(d, loop);
  	

  	start = time(0); 
  	cout << "Quick Sort Start time: "<< start << endl;
	quicksort(d,0, loop-1);
	end = time(0);
  	cout << "Quick Sort End time: "<< end << endl;
  	cout << "Quick Sort time difference: " << end - start << endl; 
  	cout << "Quick Sort - Sorted array: " << endl;
  	printArray(d, loop);

  	start = time(0); 
  	cout << "Shell Sort Start time: "<< start << endl;
  	shellSort(d, loop);
  	end = time(0);
  	cout << "Shell Sort End time: "<< end << endl;
  	cout << "Shell Sort time difference: " << end - start << endl;  
  	cout << "Shell Sort - Sorted array: "<<endl; 
  	printArray (d, loop);
  
  
	return 0;
}

void printArray(double d[], int size)
{
    //cout << "Sorted array: " << endl;
  	for(int i = 0; i < size; i++)
    {
      cout << d[i] << endl;
    }
  	cout << endl;
}
void insertSort(double *myArray, int n)
{
	for (int j = 1; j<n; ++j) //marker
	{
		double temp = myArray[j]; //store marked item
		int k=j; //where to start shifting
		while (k > 0 && myArray [k-1]>= temp) //while the thing to the left is larger, shift
		{
			myArray[k] = myArray[k-1];
			--k;
		}
		myArray[k] = temp; //put marked item in right spot
	}
}

void quicksort(double *myArray, int lower, int upper)
{
	int i;
	if (upper > lower)
	{
		i = split(myArray, lower, upper);
		quicksort(myArray, lower, i - 1);
		quicksort(myArray, i + 1, upper);
	}
}

int split(double *myarray, int lower, int upper)
{
	double i, t;
	int p, q;
	p = lower + 1;
	q = upper;

	i = myarray[lower];
	while (p <= q)
	{
		while (myarray[p] < i)
			p++;
		while (myarray[q] > i)
			q--;

		if (p <= q)
		{
			t = myarray[p];
			myarray[p] = myarray[q];
			myarray[q] = t;
			p++;
			q--;
		}
	}

	t = myarray[lower];
	myarray[lower] = myarray[q];
	myarray[q] = t;
	return q;

}

int shellSort(double arr[], int n)
{
	// Start with a big gap, then reduce the gap
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted 
		for (int i = gap; i < n; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			double temp = arr[i];

			// shift earlier gap-sorted elements up until the correct 
			// location for a[i] is found
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			//  put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
	return 0;
}
