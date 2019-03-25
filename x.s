.globl f
.ent f
f:
.frame $fp,88,$31
addiu $sp, $sp, -88
sw $31, 20($sp)
# Enter scope
# Enter scope
lw $t0,72($sp) #load _1:16_ to$t0
nop
addiu $t0, $sp, 76 #addr of a
li $t1,3 #imm id _1:20_
li $t2,4 #imm id _1:24_
mult $t1,$t2 #cal offset _1:28
mflo $t3#cal offset _1:28
addu $t1,$t0,$t3 #dst id _1:32_
li $t0,5 #imm id _1:36_
sw $t0,52($sp) #write back id 1:36
sw $t1,56($sp) #write back id 1:32
sw $t2,64($sp) #write back id 1:24
lw $t0,56($sp) #load _1:32_ to$t0
nop
lw $t1,52($sp) #load _1:36_ to$t1
nop
sw $t1,0($t0) #write back via indirection
lw $t2,48($sp) #load _1:40_ to$t2
nop
addiu $t2, $sp, 76 #addr of a
li $t3,0 #imm id _1:44_
li $t4,4 #imm id _1:48_
mult $t3,$t4 #cal offset _1:52
mflo $t5#cal offset _1:52
addu $t3,$t2,$t5 #dst id _1:56_
sw $t3,32($sp) #write back id 1:56
sw $t4,40($sp) #write back id 1:48
lw $t0,32($sp) #load _1:56_ to$t0
nop
# assign _1:56_ to _1:4_ in reg $t0
sw $t0,84($sp) #write back id 1:4
lw $t0,84($sp) #load _1:4_ to$t0
nop
# assign _1:4_ to _1:60_ in reg $t0
move $2,$t0
b EXIT_f
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 88
j $31
.end f

