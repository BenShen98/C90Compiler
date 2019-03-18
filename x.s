addiu $sp, $sp, -48
sw $31, 20($sp)
li $t0,0 #immediate y
li $t1,5 #immediate 
li $t2,6 #immediate 
li $t0,0 #immediate 
move $2,$t0
b EXIT_main
sw $t0,28($sp) #write back id 20
sw $t1,408879031($sp) #write back id -408878983
sw $t2,44($sp) #write back id 4
EXIT_main:
lw $31, 20($sp)
addiu $sp, $sp, 48
j $31

