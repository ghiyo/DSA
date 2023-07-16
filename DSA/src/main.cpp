#include <iostream>
#include <queue>

int main() {
	std::queue<int> q;
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);
	std::cout << q.empty() << std::endl;
	std::cout << q.size() << std::endl;
	std::cout << q.front() << std::endl;
	std::cout << q.back() << std::endl;
	q.emplace(9);
	std::cout << q.back() << std::endl;

	std::cin.get();
}