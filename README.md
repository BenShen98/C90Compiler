# C90Compiler  [![Build Status](https://travis-ci.com/BenShen98/C90Compiler.svg?token=MhRupwiszpRvsr3Bhyd3&branch=master)](https://travis-ci.com/BenShen98/C90Compiler)


## Coursework Requirement
Write a compiler that is able to translate the C90 to python and also compile to MIPS assembly.\
Please visit this [link](requirement/) for detail.

## Designs
The sections provide an overview of the design in logical order.
### Flow
Since the Coursework requires python and assembly output, it makes sense to use the workflow shown below.
![flow](https://user-images.githubusercontent.com/15164268/59982066-94ae5780-9604-11e9-9fd0-323a857f4edd.png)

As shown, the compiler will turn C90 source file to AST ([Abstract syntax tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree)). And then use the same AST to generate required outputs.

### AST structure
There is an abstract class called ast_abs serves as the interface for its derived child.\
Each token in [the Yacc file](https://github.com/BenShen98/C90Compiler/blob/master/src/C90.y) corresponds to a [child](https://github.com/BenShen98/C90Compiler/tree/master/include/ast) derived from the abstract class `ast_abs`.

### C90 to AST
This process is fairly standard.
1. The source file is opened, the content is loaded into a buffer
2. Chars are read and reduce to tokens streams by using DFA ([Deterministic finite automaton](https://en.wikipedia.org/wiki/Deterministic_finite_automaton))
3. ASTs are constructed by using shift and reduce parsing

### AST to Python
Since convert from C to Python is more like line by line conversion.\
There are not feedback mechanism in the `py(str pysrc)`, instead, the AST trees are traversed. Each child nodes append its content to the pysrc. 

### AST to Assembly
Unlike convert to Python, now the context becomes important.\
There are two types of interface `mp()` and `mp(Result& result)` for Statement and Expression respectively.

The `mp(Result& result)` are mostly used to let the parent know where to access the result produced by the child using `StakId`, but just like life, there are many exceptions, which has been listed on [this internal WIKI page](https://github.com/BenShen98/C90Compiler/wiki/AST2MIPS-interface).

### CPU abstraction
As mentioned in sub-section above, the `StackId` is used to identify the resources of variables.

This is because it's hard to provide an accurate estimate of stack space and decide a method efficient register allocation. As the result, I wrote [the Mp class](https://github.com/BenShen98/C90Compiler/blob/master/include/Mp.hpp) which provide an abstraction of the MIPS CPU which the binary is targeted for. Allow a self-reflection inside the compiler, allows the compiler to make the optimised decision on the go, rather than provide hard-coded rules which may not cover all possible input.

Due to the time constraint, the Mp class is not optimised when comes to stack space, although the provisioning had been implemented. This is because such optimisation needs sophisticated test cases to ensure the optimisation did not alter the functional behaviour of the outputted code.

