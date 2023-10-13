#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

namespace search {
namespace median_search {
int median_of_medians(const std::vector<int>& A,  const int& idx) {
	int pivot = 0;
	std::vector<int> a(A.begin(), A.end());
	std::vector<int> m;
	int r = a.size();
	for(int i = 0; i < r; i += 5){
		std::sort(a.begin() + i, a.begin() + std::min(r, i + 5));
		int mid = (i + std::min(r, i + 5)) / 2;
		m.push_back(a[mid]);
	}
	int sz = int(m.size());
	if(sz <= 5){
		std::sort(m.begin(), m.end());
		pivot = m[(sz- 1) / 2];
	}
	else{
		pivot = median_of_medians(m, idx);
	}
	std::vector<int> low;
	std::vector<int> high;
	for(int i = 0; i < r; i++){
		if(a[i] < pivot){
			low.push_back(a[i]);
		}
		else if(a[i] > pivot){
			high.push_back(a[i]);
		}
	}
	int k = int(low.size());
	if(idx < k){
		return median_of_medians(low, idx);
	}
	else if(idx > k){
		return median_of_medians(high, idx-k-1);
	}
	else{
		return pivot;
	}
}
}
}

void test(){
	std::vector<int> A{25,21,98,100,76,22,43,60,89,87};
	int i = 3;
	assert(A[6] == search::median_search::median_of_medians(A, i));
	std::cout << "test case:1 passed\n";
	
	std::vector<int> B{1,2,3,4,5,6};
	int j = 4;
	assert(B[4] == search::median_search::median_of_medians(B, j));
	std::cout << "test case:2 passed\n";
	
	std::vector<int> C{1,2,3,4,5,1000,8,9,99};
	int k = 3;
	assert(C[3] == search::median_search::median_of_medians(C, k));
	std::cout << "test case:3 passed\n";
	std::cout << "--All tests passed--\n";
}

int main()
{
	test();
	int n = 0;
	std::cout << "Enter Size of Array: ";
	std::cin >> n;
	std::vector<int> a(n);
	std::cout << "Enter Array: ";
	for(int i = 0; i < n; i++){
		std::cin >> a[i];
	}
	std::cout << "Median: ";
	int x = search::median_search::median_of_medians(a,  (n - 1) / 2);
	if(n % 2 == 0){
		int y = search::median_search::median_of_medians(a, n / 2);
		std::cout << (float(x) + float(y))/2.0;
	}
	else{
		std::cout << x;
	}
	std::cout << "\nTo find i-th smallest element ";
       	std::cout << "\nEnter i: ";
	int idx = 0;
	std::cin >> idx;
	idx--;
	std::cout << idx + 1<< "-th smallest element: " << search::median_search::median_of_medians(a, idx) << '\n';
	return 0;
}
