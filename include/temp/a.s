addiu $sp, $sp, -40
sw $31, 16($sp)
li $t0,123456 #immediate op1
li $t1,4564 #immediate op2
addu $t2,$t0,$t1 #
sw $t0,32($sp) #write back id 8
sw $t2,24($sp) #write back id 16
EXIT_para:
lw $31, 16($sp)
addiu $sp, $sp, 40
j $31
