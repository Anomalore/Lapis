#include <Lapis.h>

class Sandbox : public Lapis::Application
{
public:
	Sandbox() 
	{

	}

	~Sandbox()
	{

	}
};

Lapis::Application* Lapis::CreateApplication() 
{
	return new Sandbox();
}