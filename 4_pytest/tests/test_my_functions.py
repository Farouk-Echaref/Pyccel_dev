import pytest
import src.my_functions as my_functions

def test_add():
    res = my_functions.fadd(1, 2)
    assert res == 4