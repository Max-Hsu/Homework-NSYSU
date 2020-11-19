#include <iostream>

using namespace std;

class Vector2D{
	public:
		Vector2D();
		Vector2D(int x,int y);
		const int operator *(const Vector2D& vector2);
		void output();
	private:
		int x,y;
};