
class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      int largest=i;
      int leftChild=2*i+1;
      int rightChild=2*i+2;
      if((leftChild<=n) && (arr[leftChild]>arr[largest])){
          largest=leftChild;
      }
      if((rightChild<=n) && (arr[rightChild]>arr[largest])){
          largest=rightChild;
      }
      if(largest!=i){
          swap(arr[i],arr[largest]);
          heapify(arr,n,largest);
      }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=n-1;i>=0;i--){
            heapify(arr,n-1,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        for(int i=n-1;i>0;i--){
            swap(arr[0],arr[i]);
            heapify(arr,i-1,0);
        }
    }
};




// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends