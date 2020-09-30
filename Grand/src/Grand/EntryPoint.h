#pragma once


#ifdef GRAND_PLATFORM_WINDOWS

extern Grand::Application* Grand::createApplication();

int main(int argc, char** argv)
{
	printf("Grand Engine\n");
	auto app = Grand::createApplication();
	app->run();
	delete app;
}
#endif