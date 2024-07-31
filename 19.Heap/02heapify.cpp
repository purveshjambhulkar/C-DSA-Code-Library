void heapify(int arr[], int n, int i) {

//this is for 1 based indexing
  int largest = i;
  int left = 2 * i;
  int right = 2 * i + 1;

  //this is for 0 based indexing
  // int largest = i;
  // int left = 2 * i + 1 ;
  // int right = 2 * i + 2;

  if (left < n && arr[largest] < arr[left]) {
    largest = left;
  }
  if (right < n && arr[largest] < arr[right]) {
    largest = right;
  }

  if (largest != i) {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}


int main() {
  

  int arr[6] = {-1, 54, 53, 55, 52, 50};
  int n = 5;

  //this is for 1 based indexing
  for (int i = n / 2; i > 0; i--) {
    heapify(arr, n, i);
  }

  //for 0 based indexing 
  // for(int i = n/2 - 1 ; i >=0 ; i-- ){
  //   heapify(arr, n ,i);
  //     }

  for (int i = 1; i < 6; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
