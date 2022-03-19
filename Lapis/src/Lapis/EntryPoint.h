#pragma once

#ifdef LP_PLATFORM_WINDOWS

extern Lapis::Application* Lapis::CreateApplication();

int main(int argc, char** argv)
{
	Lapis::Log::Init();
	LP_CORE_WARN("Initialized Log!");
	int a = 5;
	LP_INFO("HIIII! Var={0}", a);

	auto app = Lapis::CreateApplication();
	app->Run();
	delete app;
}

#endif