// A C++ Program to find length of the Longest Common
// Increasing Subsequence (LCIS)
#include<bits/stdc++.h>
using namespace std;
 
// Returns the length and the LCIS of two
// arrays arr1[0..n-1] and arr2[0..m-1] and
// prints LCIS
int LCIS(int arr1[], int n, int arr2[], int m)
{
    // table[j] is going to store length of LCIS
    // ending with arr2[j]. We initialize it as 0,
    int table[m], parent[m];
    for (int j=0; j<m; j++)
        table[j] = 0;
 
    // Traverse all elements of arr1[]
    for (int i=0; i<n; i++)
    {
        // Initialize current length of LCIS
        int current = 0, last = -1;
 
        // For each element of arr1[], trvarse all
        // elements of arr2[].
        for (int j=0; j<m; j++)
        {
            // If both the array have same elements.
            // Note that we don't break the loop here.
            if (arr1[i] == arr2[j])
            {
                if (current + 1 > table[j])
                {
                    table[j] = current + 1;
                    parent[j] = last;
                }
            }
 
            /* Now seek for previous smaller common
               element for current element of arr1 */
            if (arr1[i] > arr2[j])
            {
                if (table[j] > current)
                {
                    current = table[j];
                    last = j;
                }
            }
        }
    }
 
    // The maximum value in table[] is out result
    int result = 0, index = -1;
    for (int i=0; i<m; i++)
    {
        if (table[i] > result)
        {
           result = table[i];
           index = i;
        }
    }
 
    // LCIS is going to store elements of LCIS
    int lcis[result];
    for (int i=0; index != -1; i++)
    {
        lcis[i] = arr2[index];
        index = parent[index];
    }
 
    cout << "The LCIS is : ";
    for (int i=result-1; i>=0; i--)
        printf ("%d ", lcis[i]);
 
    return result;
}
 
/* Driver program to test above function */
int main()
{
    int arr1[] = {3, 4, 9, 1};
    int arr2[] = {5, 3, 8, 9, 10, 2, 1};
 
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
 
    cout << "\nLength of LCIS is "
         << LCIS(arr1, n, arr2, m);
    return (0);
}
