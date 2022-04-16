#include <Lapis.h>

#include "imgui/imgui.h"

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

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
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
	}

	~Sandbox()
	{

	}
};

Lapis::Application* Lapis::CreateApplication() 
{
	return new Sandbox();
}