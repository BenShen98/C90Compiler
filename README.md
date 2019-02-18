# C90Compiler

## Coursework Requirement
Write a compiler that is able to translate the C90 to python and also compile to MIPS assembly.\
Please visit this [link](requirement/) for detail.

## Background and Design Choices
- This coursework is done in pairs, we have about 5 weeks to complete the project.\
- The coursework is only marked on correctness NOT on efficiency, and it is unlikely for this code to be a dependency of other projects.

As a result of these backgrounds, we made the following design choices
 1. Use general AST (have the type of AST as a field rather than through class polymorphism)
 2. Only implement the core C90 features at the start, add more features if have more time
 3. Ensure code generation is reailble before considering optimsation
 
## Features
 
