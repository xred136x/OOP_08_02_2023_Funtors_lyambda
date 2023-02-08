#pragma once
#include<iostream>
#include<vector>

namespace Engine {
	class Printer
	{
	public:
		void PrintDefault();
		void Print(std::shared_ptr<IVehicle> v);
	private:
		std::vector<std::shared_ptr<IVehicle>> _vec;
	};
}
