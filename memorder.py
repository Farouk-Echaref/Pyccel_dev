import numpy as np

if __name__ == "__main__":
  a = np.array([[1, 2, 3],
                [4, 5, 6],
                [7, 8, 9]], order='F') # order='C' is the default in numpy.array
  print(a.ravel('K'))