/*

Difference between bubble sort and selection sort:-

In bubble sort, two adjacent elements are compared. If the adjacent elements are not at the correct position, swapping would be performed whereas in selection sort, the minimum element is selected from the array and swap with an element which is at the beginning of the unsorted sub array.
The time complexities in case of bubble sort in best case and worst case are O(n) and O(n^2) respectively whereas in case of selection sort the time complexity in both best and worst cases is O(n^2).

The total number of comparisons in case of bubble sort is (n - 1) + (n - 2)... (2) + (1) = n(n - 1)/2 or O(n^2). 

To find the smallest element from a group of N elements selection sort takes N-1 comparisons.
The average number of comparisons per pass in selection sort will always be one half of the number of items to be sorted. For eight items, we have 1/2(82 + 8) = 1/2(64 + 8) = 1/2(72) = 36 comparisons.
Selection sort performs (at most) n – 1 swaps between data elements, while the bubble sort swaps n * (n – 1) / 2 elements in the worst case (when the list is sorted in reverse order).

*/

<iostream>              
using namespace std;            
//Function Implementing Bubble Sort Algorithm
void bubble_sort(int arr[],int n){
    int i=0,j=1,t=n-1;
    int no_of_swap=0;
    int no_of_comp=0;
    while(t>0){
        while(j<=t){
            if(arr[i]>arr[j]){swap(arr[i],arr[j]);no_of_swap++;}
            i++,j++;
            no_of_comp++;
        }
        t--;
        i=0,j=1;
    }
    cout<<" . Number of SWAP:"<<no_of_swap<<endl;
    cout<<" . Number of COMPARISON:"<<no_of_comp<<endl;
    cout<<" . [INPLACE SORTING ALGORITHM USED]"<<endl;
}

//Function that returns index of minimum value in an array
int min_ind(int arr[],int si,int ei){
    //Initialising minimum value as first element of array
    int m=arr[si];             //m=minimum value in array
    int min_ind=si;           //min_ind=index holding minimum value
    for(int i=si;i<=ei;i++){
        int min_prev=m;
        m=min(m,arr[i]);
        if(m<min_prev){min_ind=i;}
    }
    return min_ind;
}

//Function Implementing Selection-Sort Algorithm
void selection_sort(int arr[],int n){
    //si=starting index
    //ei=ending index
    int si=0,ei=n-1;
    int no_of_swap=0;
    int no_of_comp=0;
    while(si<ei){
    int mi=min_ind(arr,si,ei);  //mi=index holding minimum value
    no_of_comp=no_of_comp+(ei-si+1);
    if(si!=mi){swap(arr[si],arr[mi]);
    no_of_swap++;}
    si++;
    }
    cout<<" . Number of SWAP:"<<no_of_swap<<endl;
    cout<<" . Number of COMPARISON:"<<no_of_comp<<endl;
    cout<<" . [INPLACE SORTING ALGORITHM USED]"<<endl;
}

//Function to print the array
void pfun(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    //n=number of elements in the array
    int n;
    //taking number of elements as input from the user
    cout<<"Enter number of elements in array:";cin>>n;
    //array of size n
    int arr1[n];int arr2[n];
    //taking array as input from the user
    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){int a;cin>>a;arr1[i]=a;arr2[i]=a;}
    //printing array before sorting
    cout<<"\nARRAY before sorting:";pfun(arr1,n);
    cout<<endl;
    //sorting array using bubble sort and printing it
    cout<<"BUBBLE SORT"<<endl;
    bubble_sort(arr1,n);
    cout<<" . ARRAY After Sorting Using Bubble Sorting:";pfun(arr1,n);
    cout<<endl;
    //sorting array using insertion sort and printing it
    cout<<"SELECTION SORT"<<endl;
    selection_sort(arr2,n);
    cout<<" . ARRAY After Sorting Using Selection Sorting:";pfun(arr2,n);
}
/*

BONUS QUESTION

TIME COMPLEXITY OF BUBBLE SORT
   In the worst-case scenario, the outer loop runs O(n) times.
   As a result, the worst-case time complexity of bubble sort is O(n x n) = O(n x n) (n2).
  

TIME COMPLEXITY OF SELECTION SORT
   The worst case is when the array is completely unsorted or sorted in descending order. So, we will traverse the entire 
   array for checking, and in each iteration, we will perform the searching operation. After searching, we will swap the 
   element at its correct position. As we know that the swapping only takes a constant amount of time i.e. O(1)O(1) so 
   the worst time complexity of selection sort also comes out to be O(N^2).

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