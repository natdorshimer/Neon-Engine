#include "Neon.h"

int main()
{
	auto app = std::make_unique<Neon::Application>();

	app->Run();
}