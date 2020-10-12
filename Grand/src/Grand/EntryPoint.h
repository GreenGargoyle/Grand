#pragma once


#ifdef GRAND_PLATFORM_WINDOWS

extern Grand::Application* Grand::createApplication();

int main(int argc, char** argv)
{
	Grand::Log::init();
	GRAND_CORE_WARN("Initialised Log!");
	GRAND_INFO("Hello!");

	auto app = Grand::createApplication();
	app->run();
	delete app;
}
#endif