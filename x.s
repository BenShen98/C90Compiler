addiu $sp, $sp, -64
sw $31, 20($sp)
li $t0,0 #immediate y
li $t1,5 #immediate 
li $t2,2 #immediate 
li $t3,3 #immediate 
addu $t4,$t2,$t3 #
li $t2,6 #immediate 
addiu $t2,$t2,1 #per increment id 4
addu $t0,$t1,$t2 #
move $2,$t0
b EXIT_main
sw $t0,28($sp) #write back id 36
sw $t1,56($sp) #write back id 8
sw $t4,40($sp) #write back id 24
EXIT_main:
lw $31, 20($sp)
addiu $sp, $sp, 64
j $31

