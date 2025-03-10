/////////////////////////////////////////////////////////////////////////////
// Name:        mainform.cpp
// Purpose:     
// Author:      Sergey Talipov
// Modified by: 
// Created:     10.03.2025 21:50:16
// RCS-ID:      
// Copyright:   15681627-3C745D8E-630127F2
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "mainform.h"

////@begin XPM images
#include "tsnsoft.xpm"
////@end XPM images


/*
 * MainForm type definition
 */

IMPLEMENT_CLASS(MainForm, wxFrame)


/*
 * MainForm event table definition
 */

	BEGIN_EVENT_TABLE(MainForm, wxFrame)

	////@begin MainForm event table entries
	EVT_BUTTON(ID_BUTTON_SUM, MainForm::OnButtonSumClick)
	EVT_BUTTON(ID_BUTTON_RAND, MainForm::OnButtonRandClick)
	EVT_BUTTON(ID_BUTTON_EXIT, MainForm::OnButtonExitClick)
	////@end MainForm event table entries

	END_EVENT_TABLE()


	/*
	 * MainForm constructors
	 */

	MainForm::MainForm()
{
	Init();
}

MainForm::MainForm(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
	Init();
	Create(parent, id, caption, pos, size, style);

	// Программно нажмем на кнопку случайных чисел
	wxCommandEvent evt; // Создаем объект события
	OnButtonRandClick(evt); // Программно нажмем на кнопку случайных чисел
}


/*
 * MainForm creator
 */

bool MainForm::Create(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
	////@begin MainForm creation
	wxFrame::Create(parent, id, caption, pos, size, style);

	CreateControls();
	SetIcon(GetIconResource(wxT("tsnsoft.xpm")));
	if (GetSizer())
	{
		GetSizer()->SetSizeHints(this);
	}
	Centre();
	////@end MainForm creation
	return true;
}


/*
 * MainForm destructor
 */

MainForm::~MainForm()
{
	////@begin MainForm destruction
	////@end MainForm destruction
}


/*
 * Member initialisation
 */

void MainForm::Init()
{
	////@begin MainForm member initialisation
	m_grid1 = NULL;
	m_staticText_Sum = NULL;
	////@end MainForm member initialisation
}


/*
 * Control creation for MainForm
 */

void MainForm::CreateControls()
{
	////@begin MainForm content construction
	MainForm* itemFrame1 = this;

	wxGridBagSizer* itemGridBagSizer1 = new wxGridBagSizer(0, 0);
	itemGridBagSizer1->SetEmptyCellSize(wxSize(10, 19));
	itemFrame1->SetSizer(itemGridBagSizer1);

	wxButton* itemButton3 = new wxButton(itemFrame1, ID_BUTTON_SUM, wxT("Сумма"), wxDefaultPosition, wxDefaultSize, 0);
	itemGridBagSizer1->Add(itemButton3, wxGBPosition(6, 8), wxGBSpan(1, 3), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 4);

	wxButton* itemButton1 = new wxButton(itemFrame1, ID_BUTTON_RAND, wxT("Случайные"), wxDefaultPosition, wxDefaultSize, 0);
	itemGridBagSizer1->Add(itemButton1, wxGBPosition(6, 3), wxGBSpan(1, 3), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_grid1 = new wxGrid(itemFrame1, ID_GRID, wxDefaultPosition, wxSize(500, 250), wxSUNKEN_BORDER | wxHSCROLL | wxVSCROLL);
	m_grid1->SetForegroundColour(wxColour(255, 255, 0));
	m_grid1->SetBackgroundColour(wxColour(0, 255, 0));
	m_grid1->SetDefaultColSize(60);
	m_grid1->SetDefaultRowSize(25);
	m_grid1->SetColLabelSize(25);
	m_grid1->SetRowLabelSize(50);
	m_grid1->CreateGrid(8, 7, wxGrid::wxGridSelectCells);
	itemGridBagSizer1->Add(m_grid1, wxGBPosition(1, 1), wxGBSpan(3, 20), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_staticText_Sum = new wxStaticText(itemFrame1, ID_TEXT_SUM, wxT("Результат"), wxDefaultPosition, wxDefaultSize, 0);
	itemGridBagSizer1->Add(m_staticText_Sum, wxGBPosition(5, 7), wxGBSpan(1, 7), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 4);

	wxButton* itemButton2 = new wxButton(itemFrame1, ID_BUTTON_EXIT, wxT("Выход"), wxDefaultPosition, wxDefaultSize, 0);
	itemGridBagSizer1->Add(itemButton2, wxGBPosition(6, 17), wxGBSpan(1, 1), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	////@end MainForm content construction
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SUM
 */

void MainForm::OnButtonSumClick(wxCommandEvent& event)
{
	int rc = m_grid1->GetNumberRows(); // Определяем количество строк в таблице
	int cc = m_grid1->GetNumberCols(); // Определяем количество столбцов в таблице
	int sum = 0;
	wxString ss;

	// Перебираем все строки таблицы
	for (int i = 0; i < rc; i++) {
		// Перебираем все столбцы таблицы
		for (int j = 0; j < cc; j++) {
			ss = m_grid1->GetCellValue(i, j); // Считываем текстовое значение ячейки таблицы
			sum += wxAtoi(ss); // Накапливаем в переменной значение суммы, преобразовав в число значение ячейки
		}
	}
	m_staticText_Sum->SetLabel(L"Сумма = " + wxString::Format("%d", sum)); // Выдадим в компонент значение суммы
}


/*
 * Should we show tooltips?
 */

bool MainForm::ShowToolTips()
{
	return true;
}

/*
 * Get bitmap resources
 */

wxBitmap MainForm::GetBitmapResource(const wxString& name)
{
	// Bitmap retrieval
////@begin MainForm bitmap retrieval
	wxUnusedVar(name);
	return wxNullBitmap;
	////@end MainForm bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon MainForm::GetIconResource(const wxString& name)
{
	// Icon retrieval
////@begin MainForm icon retrieval
	wxUnusedVar(name);
	if (name == wxT("tsnsoft.xpm"))
	{
		wxIcon icon(tsnsoft_xpm);
		return icon;
	}
	return wxNullIcon;
	////@end MainForm icon retrieval
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_CLEAR
 */

void MainForm::OnButtonRandClick(wxCommandEvent& event)
{
	std::srand(time(0)); // Инициализация датчика случайных чисел
	int rc = m_grid1->GetNumberRows(); // Определяем количество строк в таблице
	int cc = m_grid1->GetNumberCols(); // Определяем количество столбцов в таблице
	// Перебираем все строки таблицы
	for (int i = 0; i < rc; i++) {
		// Перебираем все столбцы таблицы
		for (int j = 0; j < cc; j++) {
			int r = std::rand() % 41 - 20; // Генерируем случайное число
			m_grid1->SetCellValue(i, j, wxString::Format("%d", r)); // Занесем в ячейку таблицы нужное значение
		}
	}
	// Программно нажмем на кнопку расчета суммы
	OnButtonSumClick(event);
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_EXIT
 */

void MainForm::OnButtonExitClick(wxCommandEvent& event)
{
	////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_EXIT in MainForm.
		// Before editing this code, remove the block markers.
	Destroy();
	////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_EXIT in MainForm. 
}

