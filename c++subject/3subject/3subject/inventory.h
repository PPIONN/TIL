#pragma once
#include<iostream>
#include<string>

using namespace std;
class Item
{
public:
	Item() {};
	Item(const string& name, int price) { 
		name_ = name;
		price_ = price;
	}; // 각 멤버 변수를 세팅

	const string& GetName() const { return name_; };
	int GetPrice() const { return price_; };
	void Clear()
	{
		name_ = "";
		price_ = 0;
	}

private:
	string name_;
	int price_;
};

template<typename T>
class Inventory {
public:
	Inventory(int capacity = 10) {
		if (capacity == 0) { // 예외처리. 입력되지 않는다면 기본적으로 10의 값을 가진다.
			setcapacity(10);
		}
		else {
			setcapacity(capacity); 
		}
		pitems_ = new T[getcapacity()]; // get을 활용해 capacity_의 값만큼 힙메모리 생성.

	}
	~Inventory() {
		delete[] pitems_;
		pitems_ = nullptr;
	};
	void setcapacity(int capacity) { // cpapcity_의 set 함수, 최소 1의 값을 가진다.
		if (capacity < 1) {
			capacity_ = 1;
		}
		else {
			capacity_ = capacity;
		}

	}
	int getcapacity() const { // capacity get함수
		return capacity_;
	}
	int getsize() const {
		return size_;
	}
	void AddItem(const T& item) {
		if (getsize() == getcapacity()) {
			cout << "인벤토리가 꽉 찼습니다!" << endl;
		}
		else {
			pitems_[getsize()] = item;
			++size_;
		}
	}
	void RemoveLastItem() {
		if (size_ > 0) --size_;
	}
	void PrintAllItems() const {
		for (int i = 0; i < getsize(); i++) {
			cout << "[이름: " << pitems_[i].GetName() << ", 가격: " << pitems_[i].GetPrice() << "G]" << endl;
		}
	}
	

private:
	T* pitems_;
	int capacity_ =0;
	int size_ = 0;
	bool check = true;


};
