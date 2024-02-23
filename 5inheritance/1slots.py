#!/usr/bin/python3

class BaseClass(object):
    __slots__ = ('a', 'b', 'c')

#if subclass doesn't specify __slot__, 
#it will create __dict__ and __weakref__ in addition to slots from BaseClass
class DerivedClassWithoutSlots(BaseClass):
    pass

class DerivedClassWithSlots(BaseClass):
    __slots__ = ()

A = DerivedClassWithoutSlots()
B = DerivedClassWithSlots()

# Slots defined on parent class are automatically accessible to the child class
print(A.__slots__, A.__dict__)
print(B.__slots__)