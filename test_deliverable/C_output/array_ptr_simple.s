.globl f
.ent f
f:
.frame $fp,112,$31
addiu $sp, $sp, -112
sw $31, 20($sp)
# Enter scope
# Enter scope
lw $t0,92($sp) #load _1:20_ to$t0
nop
addiu $t0, $sp, 96 #addr of a
li $t1,0 #imm id _1:24_
li $t2,4 #imm id _1:28_
mult $t1,$t2 #cal offset _1:32
mflo $t3#cal offset _1:32
addu $t1,$t0,$t3 #dst id _1:36_
sw $t0,92($sp) #write back id 1:20
sw $t1,76($sp) #write back id 1:36
sw $t2,84($sp) #write back id 1:28
lw $t0,76($sp) #load _1:36_ to$t0
nop
# assign _1:36_ to _1:4_ in reg $t0
li $t1,2 #imm id _1:40_
lw $t2,68($sp) #load _1:44_ to$t2
nop
addiu $t2, $sp, 96 #addr of a
li $t3,4 #imm id _1:48_
mult $t1,$t3 #cal offset _1:52
mflo $t4#cal offset _1:52
addu $t1,$t4,$t2 #dst id _1:56_
li $t4,5 #imm id _1:60_
sw $t0,108($sp) #write back id 1:4
sw $t1,56($sp) #write back id 1:56
sw $t2,68($sp) #write back id 1:44
sw $t3,64($sp) #write back id 1:48
sw $t4,52($sp) #write back id 1:60
lw $t0,56($sp) #load _1:56_ to$t0
nop
lw $t1,52($sp) #load _1:60_ to$t1
nop
sw $t1,0($t0) #write back via indirection
li $t2,2 #imm id _1:64_
lw $t3,108($sp) #load _1:4_ to$t3
nop
li $t4,4 #imm id _1:68_
mult $t2,$t4 #cal offset _1:72
mflo $t5#cal offset _1:72
addu $t2,$t3,$t5 #dst id _1:76_
sw $t2,36($sp) #write back id 1:76
sw $t4,44($sp) #write back id 1:68
lw $t0,36($sp) #load _1:76_ to$t0
nop
lw $t0,0($t0) #de ref
nop
# assign _1:84_ to _1:80_ in reg $t0
move $2,$t0
b EXIT_f
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 112
j $31
.end f

