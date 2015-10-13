#include <iostream>
using namespace std;
template <class T>
class point
{
public:
	point( T x1=0, T y1=0 ); 	//������Ҫʹ������T�ĵط�����T����ʾ
	~point( ){ };
	//����/������������
	friend istream& operator>>( istream& istr, point<T>& t );
	friend ostream& operator<<( ostream& ostr, point<T>& t );
private:
	T x, y;
};

template <class T>
point<T>::point( T x1, T y1 )		//(1)
{
	x = x1;
	y = y1;
}

template <class T>
istream& operator>>( istream& istr, point<T>& t )	//�������������(2)
{
	istr >>t.x >>t.y;
	return istr;
}

template <class T>
ostream& operator<<( ostream& ostr, point<T>& t )	//������������(3)
{
	ostr <<t.x <<" " <<t.y <<endl;
	return ostr;
}

int main( )
{
	point<int> p1(2,3);
	point<double> p2(2.5,3.5);
	cout <<p1 <<p2;
	return 0;
}
