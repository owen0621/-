#include <iostream>
using namespace std;

typedef struct vecter{
	double x;
	double y;
	double z;
}V;

void enter(V*);
void vput(V*,V*,char);
V vadd(V*,V*);
double vdot(V*,V*);
V vcross(V*,V*);

int main()
{
	double d;
	V a,b,v;
	enter(&a);
	enter(&b);
	vput(&a,&b,'+');
	v=vadd(&a,&b);
	cout<<"("<<v.x<<","<<v.y<<","<<v.z<<")"<<endl;
	vput(&a,&b,'.');
	d=vdot(&a,&b);
	cout<<d<<endl;
	vput(&a,&b,'x');
	v=vcross(&a,&b);
	cout<<"("<<v.x<<","<<v.y<<","<<v.z<<")"<<endl;
	return 0;
}

void enter(V* input)
{
	cout<<"�п�J�V�q(x,y,z) : ";
	cin>>input->x>>input->y>>input->z;
}

void vput(V* a,V* b,char str)
{
	cout<<"("<<a->x<<","<<a->y<<","<<a->z<<") ";
	cout<<str;
	cout<<" ("<<b->x<<","<<b->y<<","<<b->z<<") = ";
}

V vadd(V* a,V* b)
{
	V v;
	v.x=(a->x)+(b->x);
	v.y=(a->y)+(b->y);
	v.z=(a->z)+(b->z);
	return v;
}

double vdot(V* a,V* b)
{
	double result;
	result=(a->x)*(b->x)+(a->y)*(b->y)+(a->z)*(b->z);
	return result;
}

V vcross(V* a,V* b)
{
	V v;
	v.x=a->y*b->z-b->y*a->z;
	v.y=a->z*b->x-b->z*a->x;
	v.z=a->x*b->y-b->x*a->y;
	return v;
}
 
