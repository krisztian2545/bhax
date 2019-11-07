#include <stddef.h>
#include <cxxabi.h>
#include <iostream>
#include <vector>

template<typename T>
struct CustomAlloc {

  using size_type = size_t;
	using value_type = T;
	using pointer = T*;
	using const_pointer = const T*;
	using reference = T&;
	using const_reference = const T&;
	using difference_type = ptrdiff_t;

	CustomAlloc() {}
	CustomAlloc(const CustomAlloc &) {}
	~CustomAlloc() {}

	pointer allocate(size_type n){
		int s;
		char* p = abi::__cxa_demangle( typeid(T).name(), 0, 0, &s );
		std::cout << "Allocating "
				  << n << " objects of "
				  << n * sizeof(T)
				  << " bytes. "
				  << typeid(T).name() << "=" << p
				  << std::endl;
		free(p);
		return reinterpret_cast<T*>( new char[ n * sizeof(T) ] );
	}

	void deallocate(pointer p, size_type n){
		delete[] reinterpret_cast<char *>(p);
		std::cout << "Deallocating "
				  << n << " objects of "
				  << n * sizeof(T)
				  << " bytes. "
				  << typeid(T).name() << "=" << p
				  << std::endl;
	}

};

int main(){
	std::vector<int, CustomAlloc<int>> v;

	int i = 0;
	for(i; i < 15; i++){
    v.push_back(i);
    std::cout << v[i] << std::endl;
  }

	return 0;
}
