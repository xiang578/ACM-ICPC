struct Point{
	int x;
	int y;
	Point(int a, int b) :x(a), y(b){ }
};


int cross(const Point &a, const Point &b, const Point &p)
{
	return (b.x - a.x)*(p.y - a.y) - (b.y - a.y)*(p.x - a.x);
}

bool toLeft(const Point &a, const Point &b, const Point &p)
{
	return cross(a, b, p) > 0;
}

bool inTriangle(const Point &p, const Point &a, const Point &b, const Point &c)
{
	bool res = toLeft(a, b, p);
	if (res != toLeft(b, c, p))
		return false;
	if (res != toLeft(c, a, p))
		return false;
	if (cross(a, b, c) == 0)	//ABC is in one line
		return false;
	return true;
}
