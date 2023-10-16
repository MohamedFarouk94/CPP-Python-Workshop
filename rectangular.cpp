#include <iostream>

using namespace std;

struct Rectangular{
	double x, y, z;

	Rectangular(double x, double y, double z) { this->x = x; this->y=y; this->z=z; }

	void info(){ cout << "x = " << this->x << ",\ny = " << this->y << ",\nz = " << this->z << endl; }

	double volume(){ return this->x * this->y * this->z; }
};

extern "C"{
	Rectangular* rect_new(double x, double y, double z) { return new Rectangular(x, y, z); }
	void rect_info(Rectangular* rect) { rect->info(); }
	double rect_volume(Rectangular* rect) { return rect->volume(); }
}

int main(){
	Rectangular* rect = new Rectangular(1, 2, 3);
	rect->info();
	cout << endl;
	cout << rect->volume() << endl;
	return 0;
}