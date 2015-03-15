
// ChildView.h : интерфейс класса CChildView
//


#pragma once
#include "GrpObject.h"
#include <vector>


// окно CChildView

class CChildView : public CWnd
{
// Создание
public:
	CChildView();

// Атрибуты
public:

protected:
	//CCircle m_Circles;
	//Now we need an array of circles
	std::vector<CGrpObject *> m_Objects;
	//bool m_bCatched;
	int m_nCatched;
	CPoint m_MousePos;

// Операции
public:
	//If the point is inside of a circle,
	//the function will return its number, otherwise -1
	int FindObject(CPoint point);

// Переопределение
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Реализация
public:
	virtual ~CChildView();

	// Созданные функции схемы сообщений
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNewCircle();
	afx_msg void OnNewSquare();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

