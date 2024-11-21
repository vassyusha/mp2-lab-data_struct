#pragma once
#include <vector>

template<typename T, class Container = std::vector<T>>
class TStack {
private:
	Container stack;
public:
	std::size_t size() const { return this->stack.size(); }
	bool empty() const { return (this->stack.size() == 0); }

	T top() const {
		if (this->empty()) throw std::out_of_range("size should be greater than 0");
		return this->stack[this->stack.size() - 1];
	}

	void push(const T& el) {
		this->stack.push_back(el);
	}

	void pop() {
		if (this->empty()) throw std::out_of_range("size should be greater than 0");
		this->stack.pop_back();
	}
};