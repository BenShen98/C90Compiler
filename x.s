.globl postInc
.ent postInc
postInc:
.frame $fp,56,$31
addiu $sp, $sp, -56
sw $31, 20($sp)
li $t0,0 #imm id _8_
# assign _8_ to _4_ in reg $t0
li $t1,0 #imm id _16_
# assign _16_ to _12_ in reg $t1
addi $t2,$t0,1 #add, swap org copy & org
# assign _20_ to _12_ in reg $t0
addu $t1,$t2,$t0 #dst id _24_
# assign _24_ to _28_ in reg $t1
move $2,$t1
b EXIT_postInc
EXIT_postInc:
lw $31, 20($sp)
addiu $sp, $sp, 56
j $31
.end postInc

