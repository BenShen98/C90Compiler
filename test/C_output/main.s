addiu $sp, $sp, -32
sw $31, 20($sp)
li $t0,0 #imm id _4_
# assign _4_ to _8_ in reg $t0
move $2,$t0
b EXIT_main
sw $t0,24($sp) #write back id 8
EXIT_main:
lw $31, 20($sp)
addiu $sp, $sp, 32
j $31

