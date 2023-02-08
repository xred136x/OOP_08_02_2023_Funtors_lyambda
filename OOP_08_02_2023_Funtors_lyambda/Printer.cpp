#include "Printer.h"

using namespace Engine;
void Engine::Printer::PrintDefault()
{
	std::cout << "Default Print Message\n";
}

void Engine::Printer::Print(std::shared_ptr<IVehicle> v) : _vec(v)
{

}

