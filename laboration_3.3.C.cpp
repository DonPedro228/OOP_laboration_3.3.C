#include "Object.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main() {
	Vector3D vec1(1, 1, 1), vec2;
	cout << vec1 << endl;
	cout << vec2 << endl;
	cout << "Count: " << Vector3D::Count() << endl;
	cout << "Count: " << Object::Count() << endl;
	return 0;
}