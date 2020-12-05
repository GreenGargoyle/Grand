#include <Grand.h>


class ExampleLayer : public Grand::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
		// Empty.
	}

	void onUpdate() override
	{
		GRAND_INFO("ExampleLayer::Update");
	}

	void onEvent(Grand::Event& event) override
	{
		GRAND_TRACE("{0}", event);
	}
};

class Sandbox : public Grand::Application
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Grand::Application* Grand::createApplication()
{
	return new Sandbox();
}
