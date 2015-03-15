
// ChildView.h : ��������� ������ CChildView
//


#pragma once
#include "GrpObject.h"
#include <vector>


// ���� CChildView

class CChildView : public CWnd
{
// ��������
public:
	CChildView();

// ��������
public:

protected:
	//CCircle m_Circles;
	//Now we need an array of circles
	std::vector<CGrpObject *> m_Objects;
	//bool m_bCatched;
	int m_nCatched;
	CPoint m_MousePos;

// ��������
public:
	//If the point is inside of a circle,
	//the function will return its number, otherwise -1
	int FindObject(CPoint point);

// ���������������
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����������
public:
	virtual ~CChildView();

	// ��������� ������� ����� ���������
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

