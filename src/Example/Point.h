
class Point
{
private:
	double x, y, z;
public:
	Point(double x = 0, double y = 0, double z = 0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	friend bool operator<(Point const& p1, Point const& p2);
};

bool operator<(Point const& p1, Point const& p2)
{
	return (p1.x * p1.x + p1.y * p1.y + p1.z * p1.z)
		< (p2.x * p2.x + p2.y * p2.y + p2.z * p2.z);
}