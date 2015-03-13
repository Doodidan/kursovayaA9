// GrpObject.h : the interphase of CGrpObject
#pragma once
class CGrpObject {
public:
	CGrpObject(void) {}

	virtual void Draw(CDC &dc) = 0;
	virtual bool IsInside(double x, double y) = 0;

	virtual void Move(double dx, double dy) {
		m_dCenterX += dx;
		m_dCenterY += dy;
	}
	virtual ~CGrpObject(void){}

protected:
	double m_dCenterX;
	double m_dCenterY;
};
