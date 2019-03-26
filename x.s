.globl f
.ent f
f:
.frame $fp,96,$31
addiu $sp, $sp, -96
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,0 #imm id _1:24_
sw $t0,72($sp) #write back id 1:24
lw $t0,72($sp) #load _1:24_ to$t0
nop
# assign _1:24_ to _1:20_ in reg $t0
li $t1,5 #imm id _1:28_
sw $t0,76($sp) #write back id 1:20
sw $t1,68($sp) #write back id 1:28
lw $t0,68($sp) #load _1:28_ to$t0
nop
# assign _1:28_ to _1:16_ in reg $t0
li $t1,2 #imm id _1:32_
sw $t0,80($sp) #write back id 1:16
sw $t1,64($sp) #write back id 1:32
lw $t0,64($sp) #load _1:32_ to$t0
nop
# assign _1:32_ to _1:12_ in reg $t0
li $t1,3 #imm id _1:36_
sw $t0,84($sp) #write back id 1:12
sw $t1,60($sp) #write back id 1:36
lw $t0,60($sp) #load _1:36_ to$t0
nop
# assign _1:36_ to _1:8_ in reg $t0
li $t1,4 #imm id _1:40_
sw $t0,88($sp) #write back id 1:8
sw $t1,56($sp) #write back id 1:40
lw $t0,56($sp) #load _1:40_ to$t0
nop
# assign _1:40_ to _1:4_ in reg $t0
li $t1,0 #imm id _1:44_
lw $t2,48($sp) #load _1:48_ to$t2
nop
addiu $t2, $sp, 76 #addr of a
li $t3,1 #imm id _1:52_
li $t4,4 #imm id _1:56_
mult $t3,$t4 #cal offset _1:60
mflo $t5#cal offset _1:60
addu $t3,$t2,$t5 #dst id _1:64_
sw $t0,92($sp) #write back id 1:4
sw $t1,52($sp) #write back id 1:44
sw $t2,48($sp) #write back id 1:48
sw $t3,32($sp) #write back id 1:64
sw $t4,40($sp) #write back id 1:56
lw $t0,32($sp) #load _1:64_ to$t0
nop
lw $t0,0($t0) #de ref
nop
# assign _1:68_ to _1:44_ in reg $t0
sw $t0,52($sp) #write back id 1:44
lw $t0,52($sp) #load _1:44_ to$t0
nop
# assign _1:44_ to _1:72_ in reg $t0
move $2,$t0
b EXIT_f
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 96
j $31
.end f

