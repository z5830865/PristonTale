#include "StdAfx.h"
#include "CursorWindow.h"

namespace CURSOR
{
	Window::Window() : CBaseWindow()
	{

	}
	Window::Window(EWindow eID) : CBaseWindow(eID)
	{
		SetWindowLevel(9);
	}
	Window::~Window()
	{

	}
	void Window::Init()
	{
		BuildWindow();
	}
	void Window::Shutdown()
	{
		m_pWindowMain->Clear();
	}
	void Window::BuildWindow()
	{
		m_pWindowMain = std::make_shared<UI::Window>(Rectangle2D(0, 0, GRAPHICENGINE->GetBackWidth(), GRAPHICENGINE->GetBackHeight()));

		m_pWindowMain->AddElement(Load(ECURSORICON_Default, "image\\Sinimage\\Cursor\\DefaultCursor.tga"));
		m_pWindowMain->AddElement(Load(ECURSORICON_Sell, "image\\Sinimage\\Cursor\\SellCursor.tga"));
		m_pWindowMain->AddElement(Load(ECURSORICON_Buy, "image\\Sinimage\\Cursor\\BuyCursor.tga"));
		m_pWindowMain->AddElement(Load(ECURSORICON_Repair, "image\\Sinimage\\Cursor\\RepairCursor.tga"));
		m_pWindowMain->AddElement(Load(ECURSORICON_Attack, "image\\Sinimage\\Cursor\\Attack_Cursor.tga"));
		m_pWindowMain->AddElement(Load(ECURSORICON_GetItem1, "image\\Sinimage\\Cursor\\GetItem_Cursor1.tga"));
		m_pWindowMain->AddElement(Load(ECURSORICON_GetItem2, "image\\Sinimage\\Cursor\\GetItem_Cursor2.tga"));
		m_pWindowMain->AddElement(Load(ECURSORICON_Talk, "image\\Sinimage\\Cursor\\Talk_Cursor.tga"));
	}
	UI::LPIMAGEBOX Window::Load(ECursorIcon eID, const char* pszFile)
	{
		auto pImageBox = std::make_shared<UI::ImageBox>(Rectangle2D(0, 0, 32, 32));
		pImageBox->SetImage(UI::ImageLoader::LoadImage_(pszFile));
		pImageBox->SetID(eID);
		return pImageBox;
	}
	void Window::Render()
	{
		if (m_bShow)
		{
			if (m_eID == ECURSORICON_RepairAll)
				ECURSORICON_Repair;

			auto pImageBox = m_pWindowMain->GetElement<UI::ImageBox>(m_eID);

			pImageBox ? pImageBox->Render(MOUSEHANDLER->GetPosition()->iX, MOUSEHANDLER->GetPosition()->iY, GRAPHICENGINE->GetBackWidth(), GRAPHICENGINE->GetBackHeight(), 0, 0) : 0;
		}
	}
}