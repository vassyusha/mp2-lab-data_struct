#pragma once
#include <deque>

template<typename T, class Container = std::deque<T>>
class TStack {
private:
	Container cont;
public:
	TStack(const Container& cont = Container()): cont(cont){}

	std::size_t size() const { return this->cont.size(); }
	bool empty() const { return (this->cont.size() == 0); }

	T top() const {
		if (this->empty()) throw "size should be greater than 0";
		return this->cont[this->cont.size() - 1];
	}

	void push(const T& el) {
		this->cont.push_back(el);
	}

	void pop() {
		if (this->empty()) throw "size should be greater than 0";
		this->cont.pop_back();
	}
};

