#include <Lapis.h>

class ExampleLayer : public Lapis::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		LP_INFO("ExampleLayer::Update");
	}

	void OnEvent(Lapis::Event& event) override
	{
		LP_TRACE("{0}", event);
	}
};

class Sandbox : public Lapis::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Lapis::Application* Lapis::CreateApplication() 
{
	return new Sandbox();
}