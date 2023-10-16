from ctypes import cdll, c_double
from os import system


system("g++ -c -fPIC rectangular.cpp -o rectangular.o")
system("g++ -shared -Wl,-soname,librect.so -o librect.so rectangular.o")


lib = cdll.LoadLibrary("./librect.so")
lib.rect_new.argtypes = [c_double, c_double, c_double]
lib.rect_volume.restype = c_double


class Rectangular(object):
	def __init__(self, x, y, z):
		self.obj = lib.rect_new(x, y, z)

	def info(self):
		lib.rect_info(self.obj)

	def volume(self):
		return lib.rect_volume(self.obj)
