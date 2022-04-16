#pragma once

#include "Lapis/Layer.h"

#include "Lapis/Events/ApplicationEvent.h"
#include "Lapis/Events/KeyEvent.h"
#include "Lapis/Events/MouseEvent.h"

namespace Lapis
{
	class LAPIS_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}