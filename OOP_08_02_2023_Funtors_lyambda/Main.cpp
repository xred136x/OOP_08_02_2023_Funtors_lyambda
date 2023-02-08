#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include"Printer.h"

//functor - объект у которого перегружен оператор ()
using namespace Engine;

class Increment {
public:
	Increment(int x) : _x(x){}

	int operator()(int y) {// перегрузка оператора ()
		return _x + y;
	}
	int myFunc(int y) {
		const auto add = [this, y](int a) { // _х был в зоне видимости, this - по ссылке
			return _x + y + a;
		};
		return add(5);
	}

private:
	int _x;
};

class IVehicle {
public:
	virtual int getSpeed()const = 0;
	virtual void PrintType()const = 0;
};

class Car : public IVehicle {
public:
	Car(int speed): _speed(speed){}
	int getSpeed()const override {
		return _speed;
	}
	void PrintType()const override {
		std::cout << "Car\n";
	}
private:
	int _speed;

};

class Moto : public IVehicle {
public:
	Moto(int speed): _speed(speed){}
	int getSpeed()const override {
		return _speed;
	}
	void PrintType()const override {
		std::cout << "Moto\n";
	}
private:
	int _speed;
};

class ElectricBike : public IVehicle {
public:
	ElectricBike(int speed) : _speed(speed) {}
	int getSpeed()const override {
		return _speed;
	}
	void PrintType()const override {
		std::cout << "ElectricBike\n";
	}
private:
	int _speed;
};


int main() {

	std::shared_ptr<IVehicle> v = std::make_shared<Car>(50);
	std::cout << "Vehicle speed: " << v->getSpeed() << '\n';
	v->PrintType();
	std::cout << "==============================\n";
	Increment inc(50);

	int a = inc(5);
	std::cout << a << '\n';

	/*const auto myinc = [a](int num) {
		return num + 5 + a;
	};
	std::cout << myinc(6) << '\n';*/

	const auto myinc = [=, &a](int num) -> int { // захват с копированием , а захват (a) по ссылке
		return num + 5 + a;
	};
	std::cout << myinc(6) << '\n';

	//[&total, factor]
	// [factor, &total]
	//[&, factor]
	//[=, &total]

    std::cout << inc.myFunc(3) << '\n'; 

	std::cout << "==========================\n";

	std::vector<int> vec{ 1,-4,3,-2 };
	for (const auto el : vec) {
		std::cout << el << ' ';
	}
	std::cout << '\n';

	// сортировка
	std::sort(vec.begin(), vec.end());

	for (const auto el : vec) {
		std::cout << el << ' ';
	}
	std::cout << '\n';

	// сортировка по модулю
	std::sort(vec.begin(), vec.end(), [](int a, int b) {
		return std::abs(a) < std::abs(b);
	});
	for (const auto el : vec) {
		std::cout << el << ' ';
	}
	std::cout << '\n';

	Printer p;
	p.PrintDefault();



	return 0;
}