#include <iostream>
#include <chrono>
#include <random>
#include <fstream>

// func which generate an array of rand id's for given arr lenght

// void rand(int k, int arr[], int num_of_its) {

//   unsigned seed = 1001; 
//   std::default_random_engine rng(seed);
//   std::uniform_int_distribution <unsigned> dstr (0, k);
  
//   for (long int i = 0; i != num_of_its; i++)
//   {
//     long int tmp = 0;
//     tmp = dstr(rng);
//     arr[i] = tmp;
//   }
  

// }

// program will track the time of executing this func

// void alg1(int n, int arr[], int arr_of_target_id[], int num_of_its) // simple enumeration
// { 
//   // int target_value;
  
//   for (int i = 0; i < num_of_its; i++)
//   {
//     // std::cout << i << std::endl;
//     // target_value = arr[arr_of_target_id[i]];

// // below is algorithm code:
    
//     for (int j = 0; j < n; j++)
//     {
    
//       if (arr_of_target_id[i] == arr[j])
//         break;
    
//     }
  
//   }

// }

void alg2(int n, int arr[], int arr_of_target_id[], int num_of_its) // binary search 
{ 
  int target_id;
  
  for (int i = 0; i < num_of_its; i++)
  {
    // std::cout << i << std::endl;
    target_id = arr_of_target_id[i];

// below is algorithm code:

    int left = 0, right = n - 1;
    int mid;
    while (right >= left)
    {
      mid = left + (right - left)/2;
      if (mid == target_id)
        break;
      if (mid > target_id)
        right = mid - 1;
      else
        left = mid + 1;
    }
  
  }

}

// Code for average time:

// int main()
// {
//   std::ofstream out;
//   out.open("lab3_bin.txt", std::ios::app);

//   int val_of_search = 7000;
//   int num_of_iters = 100000;
//   int arr_n[500'000]{};

  
//   for (unsigned cnt = 100; cnt != 0; --cnt)
//   {
    
//     int arr_of_rand_id[num_of_iters];
    
//     for (int i = 0; i < val_of_search; i++)
//       arr_n[i] = i;
  
//     rand(val_of_search, arr_of_rand_id, num_of_iters);
  
//     auto begin = std::chrono::steady_clock::now();

//     alg2(val_of_search, arr_n, arr_of_rand_id, num_of_iters);
  
//     auto end = std::chrono::steady_clock::now();
//     auto time_span = std::chrono::duration_cast < std::chrono::microseconds > (end - begin);  
  
//     out << time_span.count() << std::endl;
  
//     std::cout << time_span.count() << " " << val_of_search << std::endl;
//     val_of_search = val_of_search + 4000;


//   }

//   out.close(); 
//   return 0;
// }




// code for bad cases:

int main()
{
  std::ofstream out;
  out.open("lab1_bin_bad.txt", std::ios::app);

  int val_of_search = 7000;
  int num_of_iters = 100000; // 100000 for binary, 10000 for enumeration
  int arr_n[500'000]{};
  int arr_of_rand_id[num_of_iters];

  
  for (unsigned cnt = 100; cnt != 0; --cnt)
  {
    
    for (int i = 0; i < num_of_iters; i++)
      arr_of_rand_id[i] = -1;
    
    for (int i = 0; i < val_of_search; i++)
      arr_n[i] = i;
  
    // rand(val_of_search, arr_of_rand_id, num_of_iters);


    auto begin = std::chrono::steady_clock::now();

    // choose required algorithm:

    alg2(val_of_search, arr_n, arr_of_rand_id, num_of_iters);
  
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast < std::chrono::microseconds > (end - begin);  //millisecs for enumeration micro for bin
  
    out << time_span.count() << std::endl;
  
    std::cout << time_span.count() << " " << val_of_search << std::endl;
    val_of_search = val_of_search + 4000;
  

  }

  out.close(); 
  return 0;
}

