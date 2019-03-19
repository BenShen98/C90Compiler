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
mult $t2,$t3 #dst id _24_
mflo $t4#dst id _24_
# assign _24_ to _4_ in reg $t4
sw $t4,60($sp) #save dirty re _4_ before duplicate
# assign _4_ to _28_ in reg $t4
addu $t1,$t4,$t1 #+=4
lw $t0,60($sp) #load _4_ to$t0
addu $t2,$t1,$t0 #dst id _32_
# assign _32_ to _36_ in reg $t2
move $2,$t2
b EXIT_main
sw $t1,56($sp) #write back id 8
sw $t2,28($sp) #write back id 36
sw $t4,36($sp) #write back id 28
EXIT_main:
lw $31, 20($sp)
addiu $sp, $sp, 64
j $31
.end main

