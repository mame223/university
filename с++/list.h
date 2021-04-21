#pragma once
#include<string>
#include<iostream>
#include<fstream>

class Food {
private:
	std::string name;
	int price;
	std::string info;
public:
	Food* next;
	Food* prev;
	Food() {
		next = NULL;
		prev = NULL;
	}
	Food(std::string name, int price, std::string info) : name(name), price(price), info(info) {
		next = NULL;
		prev = NULL;
	}
	void SetName(std::string s) {
		this->name = s;
	}
	std::string GetName() {
		return this->name;
	}
	void SetPrice(int p) {
		this->price = p;
	}
	int GetPrice() {
		return this->price;
	}

	void SetInfo(std::string s) {
		this->info = s;
	}
	std::string GetInfo() {
		return this->info;
	}
	~Food() {
	
	}
};

class List {
public:
	Food* head;
	List(Food ml){
		Food* tmp = new Food(ml);
		head = tmp;
	}


	void editPrice(int index, int value);

	Food* findFoodByName(std::string name);

	Food* find(int index);

	void addFood(std::string name, int price, std::string info);

	void print();

	void printFile(std::string fileName);

	void del(int index);

	void free();


	~List() {
	}
};

