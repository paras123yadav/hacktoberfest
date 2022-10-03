#include<iostream>
#define MAX 255
using namespace std;

void countSort(int array[], int length) {
    int output[MAX];
    int count[MAX];
    int max = array[0];

    // To find the largest item in array
    for (int i = 1; i < length; i++) { if (array[i] > max)
            max = array[i];
    }

    // Initialize the count for each element in array as 0
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Now, for each element we store the count
    for (int i = 0; i < length; i++) {
        count[array[i]]++;
    }

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}
	
	// Search the index of each element of the original array in count array, and
	// place the elements in other array
	for (int i = length - 1; i >= 0; i--) 
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Move the sorted items into original array
    for (int i = 0; i < length; i++) {
        array[i] = output[i];
    }
}

void display(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    int array[] = {2, 5, 2, 8, 1, 4, 1};
    int n = sizeof(array) / sizeof(array[0]);
  
    countSort(array, n);
  
    display(array, n);

    return 0;
}