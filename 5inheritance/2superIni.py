#!/usr/bin/python3

# super() gives u access to methods in a superclass from 
#the subclass that inherits from it

class Rect(object):
    __slots__ = ('_length', '_width')
    def __init__(self, length, width) -> None:
        self._length = length
        self._width = width
    
    @property
    def area(self):
        print('called from: ', self)
        return self._width * self._length
    
    @property
    def perimiter(self):
        return 2*self._length + 2*self._width

class Square(Rect):
    __slots__ = ()
    def __init__(self, length) -> None:
        super().__init__(length, length)

#Cube doesn't need an __init__ cs Cube inherits from the square and 
#.__init__() doesn’t really do anything differently for Cube than 
#it already does for Square, you can skip defining it, 
#and the .__init__() of the superclass (Square) will be called automatically.
class Cube(Square):
    __slots__ = ('_face_area')
    
    @property
    def surface_area(self):
        self._face_area = super().area
        return self._face_area * 6

    @property
    def volume(self):
        self._face_area = super().area
        return self._face_area * self._length
        

sqr = Square(4)
print(sqr.area)

rect = Rect(2, 4)
print(rect.area)

cube = Cube(3)
print(cube.surface_area)
print(cube.volume)
