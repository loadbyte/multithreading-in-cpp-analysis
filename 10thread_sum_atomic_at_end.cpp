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
void sum(long start, long end) 
{ 
   unsigned long long cnt = 0;
	for (int i = start; i < end; i++) { 
		cnt+=i;
	} 
	total+=cnt;
	cout << "sum thread ends" << endl; 
} 
int main() 
{ 
	auto start = chrono::high_resolution_clock::now(); 

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false); 

	cout << "main thread starts" << endl; 

	thread th1(sum, 1,100000000); 
	thread th2(sum, 100000001,200000000); 
	thread th3(sum, 200000001,300000000); 
	thread th4(sum, 300000001,400000000); 
	thread th5(sum, 400000001,500000000); 
	thread th6(sum, 500000001,600000000); 
	thread th7(sum, 600000001,700000000); 
	thread th8(sum, 700000001,800000000); 
	thread th9(sum, 800000001,900000000); 
	thread th10(sum, 900000001,1000000000); 

	// Wait for the threads to finish 
	th1.join(); 
	th2.join(); 
	th3.join(); 
	th4.join(); 
	th5.join(); 
	th6.join(); 
	th7.join();
	th8.join();
	th9.join();
	th10.join();
	
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
