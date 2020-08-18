// CPP program to demonstrate multithreading 
// using three different callables. 
#include <iostream> 
#include <thread> 
#include <atomic>
#include <bits/stdc++.h> 
#include <chrono> 
using namespace std; 

std::atomic<unsigned long long> total {0};

// sum function 
void sum( long start, long end) 
{ 
	for (int i = start; i < end; i++) { 
		total+=i;
	} 
	cout << "sum thread ends" << endl; 
} 
int main() 
{ 

	auto start = chrono::high_resolution_clock::now(); 

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false); 

	cout << "main thread starts" << endl; 

	thread th1(sum, 1,33333333); 
	thread th2(sum, 33333334,66666666); 
	thread th3(sum, 66666667,1000000000);  


	// Wait for the threads to finish 
	th1.join(); 
	th2.join(); 
	th3.join(); 
	
   cout<< total <<endl;
   cout << "main thread ends" << endl; 
   auto end = chrono::high_resolution_clock::now(); 

	// Calculating total time taken by the program. 
	double time_taken = 
	chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 

	time_taken *= 1e-9; 

	cout << "Time taken by program is : " << fixed 
		<< time_taken << setprecision(9); 
	cout << " sec" << endl; 

	return 0; 
} 
