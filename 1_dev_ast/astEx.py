#!/usr/bin/python3

#importing AST module
import ast 

#parse code and create an AST
tree = ast.parse("print('Hello World!')")

# traverse in presequence order(root, left, right)
#iterate over all the nodes of the AST using the ast.walk() method
for node in ast.walk(tree):
    #print the current node of the AST, the string representation of the node
    print(node)
    #print the dictionary representation of it's attributes,provides more detailed information about the node, including its type, attributes, and values.
    print(node.__dict__)
    #Print the children nodes of the current node using ast.iter_child_nodes. This line prints the child nodes as a list
    print("children: " + str([x for x in ast.iter_child_nodes(node)]) + "\\n")
    print("\n")