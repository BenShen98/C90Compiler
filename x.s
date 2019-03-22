.globl main
.ent main
main:
.frame $fp,88,$31
addiu $sp, $sp, -88
sw $31, 20($sp)
EXIT_main:
lw $31, 20($sp)
addiu $sp, $sp, 88
j $31
.end main

