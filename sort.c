
void swap_8(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int *A , int n){
    printf("*****************BUBBLE_SORTING******************\n");

    for(int i = 0; i < n-1; i++){
        for (int ii = 0; ii < n-i-1 ; ii++){
            if(A[ii] > A[ii+1]) swap_8(&A[ii],&A[ii+1]);
        }
    }
}

void merge_8(int* A, int* B,int n, int* C){
  int i = 0, j = 0, k = 0;

  while(i < n/2 && j < (n-(n/2))){
    if (A[i] < B[j]) C[k++] = A[i++];
    else C[k++] = B[j++];
  }

  for ( ; i < n/2 ; i++){

    C[k++] = A[i];
  }
  for( ; j < (n-n/2) ; j++){
    C[k++] = B[j];
  }

}

void MergeSort(int *A , int n){

    if (n > 1){

    int left[n/2];
    int right[n-n/2];

    for(int i = 0; i < n/2; i++){
        left[i] = A[i];
    }

    for(int j = 0; j < (n-(n/2));j++){
        right[j] = A[n/2+j];
    }

    MergeSort(left,n/2);
    MergeSort(right,(n-(n/2)));
    merge_8(left,right,n,A);}
}

