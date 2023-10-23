#include <iostream>
#include <python3.8/Python.h>

/**
$ locate Python.h
$ g++ -I/usr/include/python3.8/ -o rect.o rectangular.cpp -l python3.8
**/

using namespace std;

struct Rectangular{
	PyObject* pydict, *pyrect;

	Rectangular(double x, double y, double z){
		PyObject* pyname = PyUnicode_FromString((char*)"rectangular");
		PyObject* pymodule = PyImport_Import(pyname);
		this->pydict = PyModule_GetDict(pymodule);

		PyObject* pynewrect = PyDict_GetItemString(this->pydict, (char*)"new_rect");
		PyObject* pynewrect_args = Py_BuildValue("(ddd)", x, y, z);
		this->pyrect = PyObject_CallObject(pynewrect, pynewrect_args);
	}

	void info(){
		PyObject* pyrectinfo = PyDict_GetItemString(this->pydict, (char*)"rect_info");
		PyObject* pyrectinfo_args = Py_BuildValue("(O)", this->pyrect);
		PyObject_CallObject(pyrectinfo, pyrectinfo_args);
	}

	double volume(){
		PyObject* pyrectvolume = PyDict_GetItemString(this->pydict, (char*)"rect_volume");
		PyObject* pyrectvolume_args = Py_BuildValue("(O)", this->pyrect);
		PyObject* pyrectvolume_res = PyObject_CallObject(pyrectvolume, pyrectvolume_args);
		return PyFloat_AsDouble(pyrectvolume_res);
	}

};

int main(){
	setenv("PYTHONPATH",".",1);
	Py_Initialize();

	Rectangular *rect = new Rectangular(1, 2, 3);
	rect->info();
	cout << rect->volume() << endl;

	Py_Finalize();
}