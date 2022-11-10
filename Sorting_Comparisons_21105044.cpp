/*

Difference between bubble sort and selection sort:-

In bubble sort, two adjacent elements are compared. If the adjacent elements are not at the correct position, swapping would be performed whereas in selection sort, the minimum element is selected from the array and swap with an element which is at the beginning of the unsorted sub array.
The time complexities in case of bubble sort in best case and worst case are O(n) and O(n^2) respectively whereas in case of selection sort the time complexity in both best and worst cases is O(n^2).

The total number of comparisons in case of bubble sort is (n - 1) + (n - 2)... (2) + (1) = n(n - 1)/2 or O(n^2). 

To find the smallest element from a group of N elements selection sort takes N-1 comparisons.
The average number of comparisons per pass in selection sort will always be one half of the number of items to be sorted. For eight items, we have 1/2(82 + 8) = 1/2(64 + 8) = 1/2(72) = 36 comparisons.
Selection sort performs (at most) n – 1 swaps between data elements, while the bubble sort swaps n * (n – 1) / 2 elements in the worst case (when the list is sorted in reverse order).

*/

#include <iostream>
using namespace std;

pair<int,int> bubbleSort(int *input, int size)
{
    int count_swaps = 0;//to maintain the count of the number of swaps 
    int count_comparisons = 0;
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1 - j; i++)
        {
            if (input[i] > input[i + 1])
            {
                int temp = input[i];
                input[i] = input[i + 1];
                input[i + 1] = temp;
                count_swaps++;
            }
            count_comparisons++;
        }
    }
    pair<int,int> ans;
    ans.first = count_swaps;
    ans.second = count_comparisons;
    return ans;
}


pair<int,int> SelectionSort(int *input,int size)
{
    int min_index;
    int count_swaps = 0;
    int count_comparisons = 0;
    for(int i=0;i<size;i++)
    {
        min_index = i;
        for(int j=i+1;j<size;j++)
        {
            if(input[j]<input[min_index])
            {
                min_index = j;
                count_swaps++;
            }
            count_comparisons++;
        }
        int temp = input[i];
        input[i] = input[min_index];
        input[min_index] = temp;
    }
    pair<int,int> ans;
    ans.first = count_swaps;
    ans.second = count_comparisons;
    return ans;
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    pair<int,int> bubble = bubbleSort(arr,n);
    pair<int,int> selection = SelectionSort(arr,n);

    cout << "comparison between selection and bubble sort " << endl;
    cout << endl;

    cout << "1.on the basis of comparisons: " << " ";
    if(bubble.second > selection.second)
    {
        cout << "more comparisons are required for bubble sort" << endl;
    }
    else if(bubble.second < selection.second)
    {
        cout << "more comparisons are required for selection sort" << endl;
    }
    else
    {
        cout << "both require equal number of comparisons" << endl;
    }
    cout << endl;

    //second comparison

    cout << "2. ON THE BASIS OF NUMBEOF SWAPS : " << " ";
    if(bubble.first > selection.first)
    {
        cout << "MORE SWAPS ARE REQUIRED FOR BUBBLE SORT." << endl;
    }
    else if(bubble.first < selection.first)
    {
        cout << "MORE SWAPS ARE REQUIRED FOR SELECTION SORT." << endl;
    }
    else
    {
        cout << "BOTH REQUIRE EQUAL NUMBER OF SWAPS." << endl;
    }
    cout << endl;

    cout << "3 . Both BubbleSort and SelectionSort are In-place algorithms, hence both of their Inplace Algorithms have been written above." << endl;

}

//submitted by Aryana Sharma 
//SID: 21105044
//Branch: ECE