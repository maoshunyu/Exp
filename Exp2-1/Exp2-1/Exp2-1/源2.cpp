#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
import <ranges>;
using namespace std::placeholders;
bool less(int a,int target){
	return a < target;
}
bool greater(int a, int target) {
	return a > target;
}
template <auto value> 
void foo() {
	return;
}

static std::tuple<double, char, std::string> get_student(int id) {
	if (id == 0) return std::make_tuple(3.8, 'A', "Lisa Simpson");
	if (id == 1) return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
	if (id == 2) return std::make_tuple(1.7, 'D', "Ralph Wiggum");
	throw std::invalid_argument("id");
}
template<typename T> concept Incrementable = requires(T x) { x++; ++x; };
template<Incrementable T>
void Foo(T t);
int main() {
	using pf = bool(*)(int, int);
	pf l = less;
	std::vector<std::function<bool(int, int)>> func{less,greater};
	std::vector<int> v{6,32,6,76,33,2,465,7,8,2,2435,798,2,345,3};
	auto first = v[0];
	
	for (auto& item : func) {
		auto a = std::find_if(v.begin(), v.end(), std::bind(item, _1, first));
		std::cout << *a<<std::endl;
	}
	std::tuple<int, char> third(20, 'b');
	std::cout << std::get<1>(third)<< std::get<0>(third);
	auto [x, y, z] = get_student(1);
	std::cout << x << y << z<<std::tuple_size<decltype(third)>::value;
	auto fourth=std::tuple_cat(third, std::make_tuple('B', std::string("-=+")));
\
}