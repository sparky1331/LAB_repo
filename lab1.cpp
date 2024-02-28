#include <iostream>
#include <chrono>
#include <random>
#include <fstream>

// func which generate random number in given range
int* rand(int k, int *arr, int num_of_its) {

  unsigned seed = 1001; 
  std::default_random_engine rng(seed);
  std::uniform_int_distribution <unsigned> dstr (0, k);
  for (int i = 0; i != num_of_its; i++)
  {
    int tmp = 0;
    tmp = dstr(rng);
    arr[i] = tmp;
  }
  
  return arr;

}

// program will track the time of executing this func

void alg1(int n, int* arr, int *arr_of_target_id, int num_of_its) // simple enumeration
{ 
  int target_value;
  
  for (int i = 0; i < num_of_its; i++)
  {
    // std::cout << i << std::endl;
    target_value = arr[arr_of_target_id[i]];
    // std::cout << i << std::endl;
    
    for (int j = 0; j < n; j++)
    {
    
      if (target_value == arr[j])
        break;
    
    }
  
  }

}

void alg2(int n, int* arr, int *arr_of_target_id, int num_of_its) // binary search 
{ 
  int target_value;
  
  for (int i = 0; i < num_of_its; i++)
  {
    // std::cout << i << std::endl;
    target_value = arr[arr_of_target_id[i]];
    // std::cout << i << std::endl;
    
    for (int j = 0; j < n; j++)
    {
    
      if (target_value == arr[j])
        break;
    
    }
  
  }

}

int main()
{
  std::ofstream out;
  out.open("lab1_lin.txt", std::ios::app);

  int val_of_search = 7000;
  int num_of_iters = 10000;
  int* arr_n = new int[val_of_search];
  int arr_of_rand_id[num_of_iters];

  for (unsigned cnt = 100; cnt != 0; --cnt)
  {
    for (int i = 0; i < val_of_search; i++)
      arr_n[i] = i;
  
    rand(val_of_search, arr_of_rand_id, num_of_iters);
  
  

    auto begin = std::chrono::steady_clock::now();

    alg1(val_of_search, arr_n, arr_of_rand_id, num_of_iters);
  
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast < std::chrono::milliseconds > (end - begin);  
  
    out << time_span.count() << std::endl;
  
    std::cout << time_span.count() << " " << val_of_search << std::endl;
    val_of_search = val_of_search + 6930;
  }
  
  out.close(); 
  return 0;
}

