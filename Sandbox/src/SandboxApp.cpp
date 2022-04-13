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
		if (Lapis::Input::IsKeyPressed(LP_KEY_TAB))
			LP_INFO("Tab key is pressed!");
	}

	void OnEvent(Lapis::Event& event) override
	{
		
	}
};

class Sandbox : public Lapis::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Lapis::ImGuiLayer);
	}

	~Sandbox()
	{

	}
};

Lapis::Application* Lapis::CreateApplication() 
{
	return new Sandbox();
}