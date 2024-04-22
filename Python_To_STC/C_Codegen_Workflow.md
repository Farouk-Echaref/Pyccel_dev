codegen workflow:

Goal: *recognise list to import external library(STC).

--> next

==> inside/outside 

codegen for c: 

	* execute_pyccel =>(IN) codegen_init(set correct printer)

	==>(IN) CCodePrinter_init

	==>(OUT) ==>(OUT) fname 
	
	==>(IN) fname, progname = codegen.export(fname)
		
		--> set extension(.c / .h)
		--> set files (f.c / f.h)
		--> print module header:
			--> ModuleHeader.__init__()
			--> Codeprinter.dotprint():
				--> Codeprinter._print()
					--> ccode._print_ModuleHeader()
						funcs : --> ccode.function_signature() // signature of List methods
						global_variables
						imports: --> print_Import() // implement list macros
		--> print module:
			--> .dotprint():
				--> ._print():
					--> _print_Module():
						--> body = self._print() //need to implement C printers for Lists and it's methods
						--> global_vars
						--> imports // header file to include import of STC

			
		

	==>(OUT) CompileObj_init(store compiling info)

	--> check if the printer requires an internal lib.


	 *Note: needs to define "codegen.get_printer_imports()" "lib_name: (stdlib_folder, stdlib)" in case of a list for it's equivalent in STC (vector).


	==>(IN) copy_internal_library(lib_folder, pyccel_dirpath) (e.g: copy math in __pyccel__)
	

Notes from the meeting:
* check copy_internal_library
* exemple to check copy_internal_library: test with import gcd from math
* goal: copy stc 
* goal2: declare header file zith include vec 
* in codegen check:
	print module
	print module header  ==> the order of the call of those printers
test in eppycel, return one element
* goal: modify copy_internal_library for external library
