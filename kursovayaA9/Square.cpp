#include "stdafx.h"
#include "Square.h"
#include <math.h>

CSquare::CSquare (double x, double y, double a) {
	m_dCenterX = x;
	m_dCenterY = y;
	m_dA = a;
}

CSquare::~CSquare (void) {}

void CSquare::Draw (CDC &dc) {
	dc.FillSolidRect( m_dCenterX-m_dA*0.5, m_dCenterY-m_dA*0.5, m_dA, m_dA, RGB(255,255,255));
	dc.Draw3dRect(m_dCenterX-m_dA*0.5, m_dCenterY-m_dA*0.5, m_dA, m_dA, 0, 0);
}

bool CSquare::IsInside (double x, double y) {
	return fabs(x - m_dCenterX) <= m_dA*0.5 && fabs(y - m_dCenterY) <= m_dA*0.5;
}
