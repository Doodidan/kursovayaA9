
// ChildView.cpp : реализация класса CChildView
//

#include "stdafx.h"
#include "kursovayaA9.h"
#include "ChildView.h"
// #include "Circle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView() {
	m_nCatched = -1; // Initialization
}

CChildView::~CChildView() {
	// Clear the memory allocated for the circles
	for (int i=0; m_Objects[i] != NULL; i++) {
		delete m_Objects[i];
	}
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_NEWCIRCLE, OnNewCircle)
END_MESSAGE_MAP()



// обработчики сообщений CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // контекст устройства для рисования
	
	for (int i = 0; i< m_Objects.size(); i++) {
		m_Objects[i]->Draw(dc);
	}
	
	// Не вызывайте CWnd::OnPaint() для сообщений рисования
}

int CChildView::FindObject(CPoint point) {
	int nObj = -1; // if none object found, return -1
	for (int i = m_Objects.size() - 1; i >= 0; i--) {
		if (m_Objects[i]->IsInside(point.x, point.y)) {
			nObj = i;
			break;
		}
	}
	return nObj;
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_nCatched = FindObject(point);
	if (m_nCatched >= 0) {
		m_MousePos = point;
		SetCapture();
	}

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_nCatched = -1;
	ReleaseCapture();

	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_nCatched >= 0) {
		CRect rect;
		GetClientRect(&rect);
		point.x = min(rect.right, max(rect.left, point.x));
		point.y = min(rect.bottom, max(rect.top, point.y));
		CPoint Delta = point - m_MousePos;
		m_Objects[m_nCatched]->Move(Delta.x, Delta.y);
		m_MousePos = point;
		Invalidate();
	}

	CWnd::OnMouseMove(nFlags, point);
}

void CChildView::OnNewCircle () {
	CRect rect;
	GetClientRect(&rect);
	m_Objects.push_back(new CCircle(rand() % rect.Width(), rand() % rect.Height(), 10));
	Invalidate();
}
