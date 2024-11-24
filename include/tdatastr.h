#pragma once
#include <deque>
#include <vector>

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

template<typename T>
class TQueue {
private:
	std::vector<T> cont;
	std::size_t sz = 0;
	std::size_t st = 0;
	std::size_t en = 0;

	void repack() {

		std::vector<T> temp(this->cont.size() * 2);
		int i = 0, j = this->st;
		while (j != this->en) {
			temp[i] = this->cont[j];
			j = (j + 1) % (this->cont.size());
			i++;
		}
		std::swap(this->cont, temp);
		this->st = 0;
		this->en = this->sz;
	}

public:

	TQueue() {
		this->cont = std::vector<T>(1);
		this->sz = 0;
		this->st = 0;
		this->en = 0;
	}

	T front() const {
		if (this->empty()) throw "size should be greater than 0";
		return this->cont[this->st % (this->cont.size())]; 
	}
	
	void push(const T& el) {

		if (this->sz == this->cont.size()) {
			this->repack();
		}

		this->cont[this->en] = el;
		this->en = (this->en + 1) % (this->cont.size());
		this->sz++;
	}

	void pop() {
		if (this->empty()) throw "size should be greater than 0";
		this->st = (this->st + 1) % (this->cont.size());
		this->sz--;
	}

	std::size_t size() const { return this->sz; }
	bool empty() const { return (this->sz == 0); }

};
