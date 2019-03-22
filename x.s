.globl addneg
.ent addneg
addneg:
.frame $fp,56,$31
addiu $sp, $sp, -56
sw $31, 20($sp)
li $t0,4294967295 #imm id _8_
# assign _8_ to _4_ in reg $t0
li $t1,1 #imm id _16_
sw $t1,40($sp) #save dirty re _16_ before negation
sltu $t1,$t1,1 #sltu_16_
and $t1,$t1,0x00ff #andi_16_
# assign _20_ to _12_ in reg $t1
addu $t2,$t0,$t1 #dst id _24_
# assign _24_ to _28_ in reg $t2
move $2,$t2
b EXIT_addneg
EXIT_addneg:
lw $31, 20($sp)
addiu $sp, $sp, 56
j $31
.end addneg

