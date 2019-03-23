.globl main
.ent main
main:
.frame $fp,200,$31
addiu $sp, $sp, -200
sw $31, 20($sp)
EXIT_main:
lw $31, 20($sp)
addiu $sp, $sp, 200
j $31
.end main

