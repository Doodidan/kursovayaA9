#pragma once
#include "GrpObject.h"

class CCircle : public CGrpObject{
public:
	CCircle(double x, double y, double R);
	~CCircle(void);

public:
	void Draw(CDC &dc);
	bool IsInside(double x, double y);
	// void Move(double dx, double dy);

protected:
	// double m_dCenterX;
	// double m_dCenterY;
	double m_dRadius;
};
