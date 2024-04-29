## Codegen Workflow

**Goal:** Recognize list to import external library (STC).

--> **Next**

==> **Inside/Outside**

### Codegen for C:

- **execute_pyccel**:
  - **(IN) codegen_init** (set correct printer)
    - ==> **(IN) CCodePrinter_init**
    - ==> **(OUT) fname**
    - ==> **(OUT) fname**
    - ==> **(IN) fname, progname = codegen.export(fname)**
      - --> Set extension (.c / .h)
      - --> Set files (f.c / f.h)
      - --> Print module header:
        - --> `ModuleHeader.__init__()`
        - --> `Codeprinter.dotprint()`:
          - --> `Codeprinter._print()`
            - --> `ccode._print_ModuleHeader()`
              - Funcs: `ccode.function_signature()` (signature of List methods)
              - Global variables
              - Imports: `print_Import()` (implement list macros)
      - --> Print module:
        - --> `.dotprint()`:
          - --> `._print()`:
            - --> `_print_Module()`:
              - Body = `self._print()` (need to implement C printers for Lists and its methods)
              - Global vars
              - Imports (header file to include import of STC)

- **(OUT) CompileObj_init** (store compiling info)
  - --> Check if the printer requires an internal lib.

**Note:** 
- Needs to define `codegen.get_printer_imports()` `"lib_name: (stdlib_folder, stdlib)"` in case of a list for its equivalent in STC (vector).

- **(IN) copy_internal_library(lib_folder, pyccel_dirpath)** (e.g., copy math in `__pyccel__`)

**Notes:**
- Check `copy_internal_library`.
- Example to check `copy_internal_library`: test with import `gcd` from `math`.
- Goal: Copy STC.
- Goal 2: Declare header file with include vec.
- In codegen check: print module, print module header ==> the order of the call of those printers.
- Pyccel free functions should call STC `drop()` methods
- Test in eppycel, return one element.
- Goal: Modify `copy_internal_library` for external library.
