#!/usr/bin/python3

from distutils.core import setup, Extension

module = Extension("Example", sources = ["Example.c"])

setup(name="name",
    version="6.9",
    description="extending_py_to_c",
    ext_modules=[module])