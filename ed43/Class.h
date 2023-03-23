#ifndef Class_h
#define Class_h
#include <iostream>

#include "set_eda.h"
#include<queue>
using namespace std;
template <class T, class Comparator = std::less<T>>
class user_set :public set < T, Comparator > {
	using TreeNode = typename set< T, Comparator > ::TreeNode;
	

	using Link = TreeNode*;




public:

	std::pair<bool, T> lower_bound(T const& e) const {
		Link it = this->raiz;
		bool encontrado = false;
		T elem = e;

		while (!encontrado && it != nullptr) {
			if (it->elem < e) {				
				it = it->dr;
			}
			else if (it->elem > e) {
				elem = it->elem;
				it = it->iz;
			}

			else {
				encontrado = true;
				elem = e;
			}
		}

		if (elem > e)
			encontrado = true;
			

		return { encontrado,elem };


	}

};


#endif