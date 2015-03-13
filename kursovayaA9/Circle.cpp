#include "StdAfx.h"
#include "Circle.h" 

CCircle::CCircle (double x, double y, double R) {
	m_dCenterX = x;
	m_dCenterY = y;
	m_dRadius = R;
}

CCircle::~CCircle (void) {

}

void CCircle::Draw (CDC &dc) {
	dc.Ellipse(m_dCenterX - m_dRadius, m_dCenterY - m_dRadius, m_dCenterX + m_dRadius, m_dCenterX + m_dRadius);
}

bool CCircle::IsInside (double x, double y) {
	return  (x - m_dCenterX)*(x - m_dCenterX) + (y - m_dCenterY)*(y - m_dCenterY) < m_dRadius*m_dRadius;
}

void CCircle::Move (double dx, double dy) {
	m_dCenterX += dx;
	m_dCenterY += dy;
}
