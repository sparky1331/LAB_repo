#include <iostream>
#include <random>


// merges sorted arr1[n1] arr2[n2] in sorted arr[n1 + n2]
void merge(int n1, int n2, int* arr1, int* arr2, int* arr) {

    int tmp1 = 0, tmp2 = 0;
    
    for (int i = 0; i < n1 + n2; i++) {
    
        if ((tmp1 < n1) and (tmp2 < n2)) {
          
          if (arr1[tmp1] <= arr2[tmp2]) {  
           
            arr[i] = arr1[tmp1]; 
            tmp1++;
          
          }        
        
          else {

          arr[i] = arr2[tmp2];
          tmp2++;
        
          }
        
        }
    
        else {

          arr[i] = arr1[tmp1] * (tmp1 < n1) + arr2[tmp2] * (tmp2 < n2);
          tmp1 = tmp1 + (tmp1 < (n1 - 1));
          tmp2 = tmp2 + (tmp2 < (n2 - 1));

        }
    
    }

}

// swaps arr[i] and arr[j] in given array
void swap(int i, int j, int* arr) {

    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;

}

// k - largest number in generated array, n - number of elements in array, arr - generated array
void rand(int k, int n, int* arr) {  

  unsigned seed = 1001; 
  std::default_random_engine rng(seed);
  std::uniform_int_distribution <unsigned> dstr (0, k);
  
  for (int i = 0; i != n; i++)
  {
    long int tmp = 0;
    tmp = dstr(rng);
    arr[i] = tmp;
  }

}  

void heapify(int i, int n, int* arr) {

    int left = 2*i;
    int right = 2*i + 1;
    int largest = i;
    
    if ((left <= n) and (arr[left] > arr[largest]))

        largest = left;

    if ((right <= n) and (arr[right] > arr[largest]))

        largest = right;
    
    if (largest != i) {

        swap(i, largest, arr);
        heapify(largest, n, arr);

    }

}


void build_heap(int n, int* arr) {

    for (int i = n / 2; i > -1; --i) 

        heapify(i, n, arr);

}

void heapsort(int n, int* arr) {

    build_heap(n, arr);

    for (int i = n; i != -1; --i) {

        swap(i, 0, arr);
        --n;
        heapify(0, n, arr);

    }

}

void puzyrek(int n, int *arr) {

    for (int i = n - 1; i != 0; --i) {

        for (int j = 0; j < i; j++) {

            if (arr[j + 1] < arr[j])

                swap(j + 1, j, arr);

        }

    }
}

void vybor(int n, int* arr) {

    for (int i = 0; i < n - 1; i++) {

        int min_id = i;

        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[min_id])

                min_id = j;

        }

        if (min_id != i)

            swap(min_id, i, arr);

    }

}

void vstavka(int n, int* arr) {

    for (int i = 0; i < n - 1; i++) {

        int k = i;

        while ((arr[k + 1] < arr[k]) and (k >= 0)) {

            swap(k + 1, k, arr);
            --k;

        }


    }

}

// sorts the array from n_1'th to n_2'th (arr[n_1:n_2]) elements. If you want to sort whole array: n_1 = 0, n_2 = n, where n is the length of the array.
void qsort(int n_1, int n_2 , int * arr) {

    if (n_2 - n_1 > 2) {

        int tmp = (n_1 + n_2) / 2;
        // int tmp_val = arr[tmp];

        
        int zxc[n_2-n_1];
        for (int y = 0; y < n_2 - n_1 + 1; y++)
            zxc[y] = arr[n_1 + y];



        for (int i = n_1; i < n_2; i++) {

            if ((arr[i] < arr[tmp]) and (i > tmp)) {

                for (int j = i; j > tmp; --j)
                {
                    swap(j, j - 1, arr);

                    for (int y = 0; y < n_2 - n_1 + 1; y++)
                        zxc[y] = arr[n_1 + y];

                }
                // i++;
                tmp++;

            }

            if ((arr[i] > arr[tmp]) and (i < tmp)) {

                for (int j = i; j < tmp; j++)
                {
                 
                    swap(j, j + 1, arr);
                    
                    for (int y = 0; y < n_2 - n_1 + 1; y++)
                        zxc[y] = arr[n_1 + y];

                }
                --i;
                --tmp;
            
            }

        }

    qsort(n_1, tmp, arr);
    qsort(tmp, n_2, arr);
    
    }

    if (n_2 - n_1 == 2) {

        if (arr[n_1] > arr[n_1 + 1])

            swap(n_1, n_2 + 1, arr);

    }


}

void mergesort(int n, int * arr) {
    
    if (n > 2) {
        int * temp_arr = new int[n];
        mergesort(n/2, arr);
        mergesort(n - n/2, arr + n - n/2);
        merge(n/2, n - n/2, arr, arr + n - n/2, temp_arr);
        
        for (int i = 0; i < n; i++) 

            arr[i] = temp_arr[i];

        delete[] temp_arr;

    }
    
    else {

        if (arr[0] > arr[1])

            swap(0, 1, arr);

    } 

}


int main() {
 
    int n, k;
    std::cout << "enter number of items in arr, then largest number" << std::endl;
    std::cin >> n >> k;
    
    int* arr = new int[n];

    rand(k, n, arr);

    for (int i = 0; i < n; i++) {

        std::cout << arr[i] << " ";

    }
    
    std::cout << "" << std::endl;

    // choose sort alg:
    mergesort(n, arr);

    for (int i = 0; i < n; i++) {

        std::cout << arr[i] << " ";

    }
    
    std::cout << "" << std::endl;
}

