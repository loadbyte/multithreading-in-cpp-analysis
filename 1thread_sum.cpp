#include <iostream> 
#include <thread> 
#include <atomic>
#include <bits/stdc++.h> 
#include <chrono> 
using namespace std; 
// sum function 
void sum(long start, long end) 
{ 
   unsigned long long cnt = 0;
	for (int i = start; i < end; i++) { 
		cnt+=i;
	} 
	cout<<cnt<<endl;
	cout << "sum thread ends" << endl; 
} 


int main() 
{ 
	auto start = chrono::high_resolution_clock::now(); 

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false); 

	cout << "main thread starts" << endl; 

	thread th1(sum, 1,1000000000); 

	// Wait for thread t1 to finish 
	th1.join(); 

	

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
