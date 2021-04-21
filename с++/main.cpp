#include<iostream>
#include<fstream>
#include<string>
#include"list.h"
using namespace std;
int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "Error: provide database filename\n";
		return 1;
	}
	Food ball("coffee", 20, "maded 13.04.2021");
	List list(ball);
	ifstream in(argv[1]);
	string a, b, c;
		if (in.is_open())
		{
			while (1)
			{
				if (getline(in, a) && getline(in, b) && getline(in, c)) {
					int price = stoi(b);
					list.addFood(a, price, c);
				}
				else {
					break;
				}
			}
			in.close();
		}
		else {
			return 1;
		}
	
	char number = 0;
	while (number != '6') {
		cout << "\n";
		cout << "Mame mor coffeeshop:\n";
		cout << "1) all foods \n";
		cout << "2) add food\n";
		cout << "3) look info about food \n";

		cout << "4) edit price \n";
		cout << "5) delete food \n";
		cout << "6) exit \n";
		cout << "\n";
		cout << "Print number from 1 to 6:\n";
		cin >> number;
		switch (number) {
		case '1':
			list.print();
			break;
		case '2':
		{
			string name, info;
			int price;
			cout << "Enter food: " << endl;
			cout << "Name: ";
			cin >> a;
			cout << "Price: ";
			cin >> price;
			cout << "Info: ";
			cin >> c;
			list.addFood(name, price, info);
		}
			break;
		case '3':
		{
			string name;
			cout << "enter name: " << '\n';
			cin >> name;
			cout<<list.findFoodByName(name)->GetPrice()<<'\n';
		}
			break;
		case '4':
		{
			int index;
			int price;
			cout << "enter index: " << '\n';
			cin >> index;
			cout << "enter info: " << '\n';
			cin >> price;
			list.editPrice(index, price);
		}
			break;
		case '5':
		{
			int index;
			cout << "enter index: " << '\n';
			cin >> index;
			list.del(index);
		}
			break;
		case '6':
		default:
			break;
		}
	}
	list.printFile(argv[1]);
	list.free();
	return 0;
}
