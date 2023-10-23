class Rectangular:
	def __init__(self, x, y, z):
		self.x, self.y, self.z = x, y, z

	def info(self):
		print(f'x={self.x},\ny={self.y},\nz={self.z}')

	def volume(self):
		return self.x * self.y * self.z


def new_rect(x, y, z):
	return Rectangular(x, y, z)


def rect_info(rect):
	rect.info()


def rect_volume(rect):
	return rect.volume()


if __name__ == '__main__':
	rect = Rectangular(1, 2, 3)
	rect.info()
	print(rect.volume())
