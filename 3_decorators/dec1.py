def decor(f):
    def new_func():
        print("Add before func call")
        f()
        print("Add after func call")
    return new_func()

@decor
def init_func():
    print("Applied decor")

