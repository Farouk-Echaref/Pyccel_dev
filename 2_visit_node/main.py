#!/usr/bin/python3

import ast

#by inheriting from ast.NodeVisitor, the Visitor class can be used to traverse the AST Node
class Visitor(ast.NodeVisitor):
    #overides the visit() method of ast.NodeVisitor, takes the current ast Node and prints it
    # def visit(self, node: ast.AST):
    #     print(node)
    #     #using DFS, ensures that the traversal continues to visit the child nodes of the current node.
    #     self.generic_visit(node)
        
    def visit_Assign(self, node: ast.AST):
        print(node)
        #using DFS, ensures that the traversal continues to visit the child nodes of the current node.
        self.generic_visit(node)
    # def generic_visit(self, node):
    #     print(type(node).__name__)
    #     ast.NodeVisitor.generic_visit(self, node)

def main():
    with open('fech.py') as f:
        code = f.read()
    
    node = ast.parse(code)

    visitor = Visitor()
    visitor.visit_Assign(node)
    # print(node)
    # print(node._fields)
    # print(node.body)
    # print(node.body[0]._fields)
    # print(node.body[0].value)
    # print(node.body[0].targets)
    # print(node.body[1]._fields)

if __name__ == "__main__":
    main()