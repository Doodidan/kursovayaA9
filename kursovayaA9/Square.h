#pragma once
#include "GrpObject.h"
class CSquare :
	public CGrpObject
{
public:
	CSquare(double x, double y, double a);
	~CSquare(void);

public:
	void Draw(CDC &dc);
	bool IsInside(double x, double y);

protected:
	double m_dA;
};

