#include <iostream>
#include <random>



// swaps arr[i] and arr[j] in given array
void swap(int i, int j, int arr[]) {

    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;

}

// k - largest number in generated array, n - number of elements in array, arr - generated array
void rand(int k, int n, int arr[]) {  

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

void puzyrek(int n, int arr[]) {

    for (int i = n - 1; i != 0; --i) {

        for (int j = 0; j < i; j++) {

            if (arr[j + 1] < arr[j])

                swap(j + 1, j, arr);

        }

    }
}

void vybor(int n, int arr[]) {

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

int main() {
 
    int n, k;
    std::cout << "enter number of items in arr, then largest number" << std::endl;
    std::cin >> n >> k;
    
    int arr[n];

    rand(k, n, arr);

    for (int i = 0; i < n; i++) {

        std::cout << arr[i] << " ";

    }
    
    std::cout << "" << std::endl;

    // choose sort alg:
    vybor(n, arr);

    for (int i = 0; i < n; i++) {

        std::cout << arr[i] << " ";

    }
    
    std::cout << "" << std::endl;
}