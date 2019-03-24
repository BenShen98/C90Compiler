.globl main
.ent main
main:
.frame $fp,64,$31
addiu $sp, $sp, -64
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,24 #imm id _1:32_
# assign _1:32_ to _1:36_ in reg $t0
move $2,$t0
b EXIT_main
# End scope
# End scope
EXIT_main:
lw $31, 20($sp)
addiu $sp, $sp, 64
j $31
.end main

