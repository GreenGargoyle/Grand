#include <Grand.h>

class Sandbox : public Grand::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Grand::Application* Grand::createApplication()
{
	return new Sandbox();
}
