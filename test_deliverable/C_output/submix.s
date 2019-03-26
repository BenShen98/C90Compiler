.globl testsubmix
.ent testsubmix
testsubmix:
.frame $fp,48,$31
addiu $sp, $sp, -48
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,5 #imm id _1:8_
sw $t0,40($sp) #write back id 1:8
lw $t0,40($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
li $t1,3 #imm id _1:16_
sw $t0,44($sp) #write back id 1:4
sw $t1,32($sp) #write back id 1:16
lw $t0,32($sp) #load _1:16_ to$t0
nop
# assign _1:16_ to _1:12_ in reg $t0
lw $t1,44($sp) #load _1:4_ to$t1
nop
subu $t2,$t1,$t0 #dst id _1:20_
sw $t0,36($sp) #write back id 1:12
sw $t2,28($sp) #write back id 1:20
lw $t0,28($sp) #load _1:20_ to$t0
nop
# assign _1:20_ to _1:24_ in reg $t0
move $2,$t0
b EXIT_testsubmix
# End scope
# End scope
EXIT_testsubmix:
lw $31, 20($sp)
addiu $sp, $sp, 48
j $31
.end testsubmix

