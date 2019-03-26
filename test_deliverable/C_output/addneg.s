.globl addneg
.ent addneg
addneg:
.frame $fp,56,$31
addiu $sp, $sp, -56
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,3 #imm id _1:8_
sw $t0,48($sp) #write back id 1:8
lw $t0,48($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
li $t1,1 #imm id _1:16_
subu $t1,$0,$t1 #negating_1:16_
sw $t0,52($sp) #write back id 1:4
sw $t1,36($sp) #write back id 1:20
lw $t0,36($sp) #load _1:20_ to$t0
nop
# assign _1:20_ to _1:12_ in reg $t0
lw $t1,52($sp) #load _1:4_ to$t1
nop
addu $t2,$t1,$t0 #dst id _1:24_
sw $t0,44($sp) #write back id 1:12
sw $t2,32($sp) #write back id 1:24
lw $t0,32($sp) #load _1:24_ to$t0
nop
# assign _1:24_ to _1:28_ in reg $t0
move $2,$t0
b EXIT_addneg
# End scope
# End scope
EXIT_addneg:
lw $31, 20($sp)
addiu $sp, $sp, 56
j $31
.end addneg

