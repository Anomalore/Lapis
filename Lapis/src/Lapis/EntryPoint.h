#pragma once

extern Lapis::Application* Lapis::CreateApplication();

int main(int argc, char** argv)
{
	Lapis::Log::Init();
	LP_CORE_WARN("Initialized Log!");

	auto app = Lapis::CreateApplication();
	app->Run();
	delete app;
}