#!/usr/bin/python3
import ast 

tree = ast.parse("print('Hello World!')")

# traverse in presequence order(root, left, right)

for node in ast.walk(tree):
    print(node)
    print(node.__dict__)
    print("children: " + str([x for x in ast.iter_child_nodes(node)]) + "\\n")
    print("\n")