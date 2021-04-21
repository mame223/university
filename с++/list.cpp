#include"list.h"


Food* List::find(int index) {
	Food* finded = NULL, * tmp = head;
	int i = 0;
	while (tmp != NULL) {
		if (i == index) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
		i++;
	}
	return finded;
}

void List::addFood(std::string name, int price, std::string info){

	Food* tmp = new Food(name, price, info);
	tmp->next = head;
	tmp->prev = NULL;
	head->prev = tmp;

	head = tmp;
}

void List::print() {
	Food* tmp = head;
	while (tmp != NULL) {
		std::cout << "Item " << tmp->GetName() << '\n';
		std::cout << "Price "<< tmp->GetPrice() << '\n';
		std::cout << "info: "<< tmp->GetInfo() << '\n';
		tmp = tmp->next;
	}
}

void  List::printFile(std::string fileName) {
	std::ofstream out(fileName);
	if (out.is_open())
	{
		Food* tmp = head;
		while (tmp != NULL) {
			out << tmp->GetName() << '\n' << tmp->GetPrice() << '\n' << tmp->GetInfo() << '\n';
			tmp = tmp->next;
		}
	}
	else {
		std::cout << "Can't open file " << fileName << '\n';
	}
	out.close();
}

void List::del(int index) {

	Food* finded = find(index);
	if (!finded)
		return;

	if (finded->prev) {
		finded->prev->next = finded->next;
	}
	if (finded->next) {
		finded->next->prev = finded->prev;
	}
	delete finded;

}

void List::free() {
	Food* tmp = head;
	while (tmp != NULL) {
		Food* p = tmp;
		tmp = tmp->next;
		delete p;
	}
}

void List::editPrice(int index, int value) {
	Food* finded = find(index);
	if (!finded) {
		std::cout << "can't find index: " << index << '\n';
		return;
	}
	finded->SetPrice(value);
	
}
Food* List::findFoodByName(std::string name) {
	Food* finded = NULL, * tmp = head;
	while (tmp != NULL) {
		if (tmp->GetName() == name) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
	}
	return finded;
}