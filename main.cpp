/* Codigo creado por el grupo formado por:
   Héctor Palencia
   Arturo Alba
   Alvaro Iglesias
   Alberto González
   Francisco Afán*/

#include <iostream>
using namespace std; 
/* La función merge divide el arr[]. 
   El primer array es arr[l..m] 
   Y el segundo es arr[m+1..r]*/ 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* crea versiones temporales del array dividido */
    int L[n1], R[n2]; 
  
    /* Copia los datos originales del array en L[] y R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Va haciendo merge de los array temporales en el array original arr[l..r]*/
    i = 0; // Valor inicio del primer array temporal
    j = 0; // Valor inicio del Segundo array temporal
    k = l; // Valor de referencia para realizar el mergeI
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copia los elementos restantes de L[], si hay alguno */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copia los elementos restantes de R[], si hay alguno */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}   
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
  
/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
  
// Driver program 
int main() 
{ 
	int x;
	cout << "Introduzca el tama"<<char(164)<<"o del array: ";
	cin >> x;
    int arr[x];
    for (int i=0;i<x;i++){
    	cout << "Introduzca el valor en la posici"<<char(162)<<"n "<<(i+1)<<" del array: ";
    	cin >> arr[i];
	}
    int n = sizeof(arr)/sizeof(arr[0]); 
  
  	cout << "Given array is \n"; 
    printArray(arr, n);
    
    heapSort(arr, n); 
    cout << "\nSorted array by Heapsort is \n"; 
    printArray(arr, n); 
    
    mergeSort(arr, 0, n - 1); 
    cout << "\nSorted array by Mergesort is \n"; 
    printArray(arr, n); 
    return 0;
}
