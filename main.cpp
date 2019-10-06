/* Codigo creado por el grupo formado por:
   Héctor Palencia
   Arturo Alba
   Alvaro Iglesias
   Alberto González
   Francisco Afán*/

#include <iostream> //Libreria para el manejo de operaciones de E/S
using namespace std; //Namespace para evitar el uso de std:: cada vez que se quiera mostrar algo por pantalla
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
    while (i < n1 && j < n2) // Va comprobando elemento a elemento de los sub-array
    { 
        if (L[i] <= R[j])//Comprueba si el elemento izquierdo es menor que el derecho
        { 
            arr[k] = L[i];  //Añade el elemento menor al array final mergeado
            i++; //Aumenta el indice del sub-array izquierdo
        } 
        else //En caso de que el elemento derecho sea menor que el izquierdo
        { 
            arr[k] = R[j]; //Añade el elemento menor al array final mergeado
            j++; //Aumenta el indice del sub-array derecho
        } 
        k++; //Va aumentando el indice del array final mergeado
    } 
  	
    /* Copia los elementos restantes de L[], si hay alguno. */	
    while (i < n1) /*Si se ha hecho exhaust (recorrido al completo) del sub-array derecho se copian todos los elementos 
    		     del sub-array izquierdo al array final ya que estan previamente ordenados*/ 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copia los elementos restantes de R[], si hay alguno */
    while (j < n2) /*Al igual que en el caso anterior si se ha hecho exhaust del sub-array izquierdo se copian todos los elementos
    		     del sub-array derecho al array final ya que estan previamente ordenados*/
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l representa el indice izquierdo y r al indice derecho del 
   sub-array del array original (arr[]) que va a ser ordenado */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        /* En caso de tener un tamaño impar de array se calcula de modo que deja un elemento mas 
	    en el lado izquierdo */
        int m = l+(r-l)/2; //Calcula el punto medio del array para hacer las divisiones
  
        // Ordena primero y despues hace las divisiones del array hasta la unidad de ambos lados l y r 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); /*Por ultimo hace una llamada a merge para unir los dos sub-arrays ya ordenados
	    			y aplicar de nuevo el algoritmo para obtener el array final con todos los datos
				en orden ascendente*/
    } 
}   
/* La funcion heapify es la que se encarga de dar forma de un arbol a los datos con raiz en el nodo i
que es el indice del array y en n el tamaño del monticulo o heap */
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Inicializa un MaxHeap como raiz usando el nodo i
    int l = 2*i + 1; // left = 2*i + 1 inicializa el nodo izquierdo del subarbol
    int r = 2*i + 2; // right = 2*i + 2 inicializa el nodo derecho del subarbol
  
    // Si el hijo izquierdo es mayor que la raiz 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; //Hace un swap entre el hijo y la raiz o "MaxHeap"
  
    // Si el hijo derecho es mayor que la raiz 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; //Hace un swap entre el hijo y la raiz o "MaxHeap"
  
    // Si el mayor termino no es la raiz 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Se aplica la funcion de forma recursiva al subarbol resultante 
        heapify(arr, n, largest); 
    } 
} 
  
// Funcion principal para aplicar el algoritmo HeapSort
void heapSort(int arr[], int n) 
{ 
    // Construye el monticulo (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // Extrae elementos uno a uno del monticulo
    for (int i=n-1; i>=0; i--) 
    { 
        // Intercambia la raiz con el ultimo elemento
        swap(arr[0], arr[i]); 
  
        // Llama a la funcion para aplicar de nuevo el algortimo al subarbol reducido 
        heapify(arr, i, 0); 
    } 
} 
  
/* Funcion para imprimir el array de tamaño n */
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; //Va mostrando posicion a posicion el array junto a un espacio representado por " "
    cout << "\n"; 
} 
  
// Funcion principal del programa
int main() 
{ 
	int x; //x es el tamaño del array que se pide al usuario por consola
	cout << "Introduzca el tama"<<char(164)<<"o del array: ";
	cin >> x;
    int arr[x];//Declaramos un array del tamaño que el usuario nos haya dado
    for (int i=0;i<x;i++){ //Rellenamos mediante un for un array hasta llegar al tamaño dado por el usuario
    	cout << "Introduzca el valor en la posici"<<char(162)<<"n "<<(i+1)<<" del array: ";
    	cin >> arr[i];
	}
    int n = sizeof(arr)/sizeof(arr[0]); 
  
  	cout << "El array original dado es: \n"; 
    printArray(arr, n);
    
    heapSort(arr, n); 
    cout << "\nEl array ordenado por Heapsort es: \n"; 
    printArray(arr, n); 
    
    mergeSort(arr, 0, n - 1); 
    cout << "\nEl array ordenado por Mergesort es: \n"; 
    printArray(arr, n); 
    return 0;
}
