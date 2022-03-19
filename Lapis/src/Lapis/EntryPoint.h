#pragma once

#ifdef LP_PLATFORM_WINDOWS

extern Lapis::Application* Lapis::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Lapis::CreateApplication();
	app->Run();
	delete app;
}

#endif