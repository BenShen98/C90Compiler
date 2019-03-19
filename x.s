.globl main
.ent main
main:
.frame $fp,64,$31
addiu $sp, $sp, -64
sw $31, 20($sp)
li $t0,0 #imm id _4_
li $t1,0x5 #imm id _12_
# assign _12_ to _8_ in reg $t1
li $t2,2 #imm id _16_
li $t3,3 #imm id _20_
addu $t4,$t2,$t3 #dst id _24_
li $t2,6 #imm id _28_
# assign _28_ to _4_ in reg $t2
addi $t2,$t2,1 #per increment id 4
addu $t0,$t1,$t2 #dst id _32_
# assign _32_ to _36_ in reg $t0
move $2,$t0
b EXIT_main
sw $t0,28($sp) #write back id 36
sw $t1,56($sp) #write back id 8
sw $t4,40($sp) #write back id 24
EXIT_main:
lw $31, 20($sp)
addiu $sp, $sp, 64
j $31

.end main
