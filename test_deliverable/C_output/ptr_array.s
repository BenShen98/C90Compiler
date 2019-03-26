.globl f
.ent f
f:
.frame $fp,104,$31
addiu $sp, $sp, -104
sw $31, 20($sp)
# Enter scope
# Enter scope
lw $t0,76($sp) #load _1:28_ to$t0
nop
addiu $t0, $sp, 84 #addr of a
sw $t0,76($sp) #write back id 1:28
lw $t0,76($sp) #load _1:28_ to$t0
nop
# assign _1:28_ to _1:24_ in reg $t0
li $t1,1 #imm id _1:32_
sw $t0,80($sp) #save dirty re _1:24_ before negation
lw $t0,0($t0) #de ref
nop
li $t2,4 #imm id _1:40_
mult $t1,$t2 #cal offset _1:44
mflo $t3#cal offset _1:44
addu $t1,$t0,$t3 #dst id _1:48_
li $t0,6 #imm id _1:52_
sw $t0,52($sp) #write back id 1:52
sw $t1,56($sp) #write back id 1:48
sw $t2,64($sp) #write back id 1:40
lw $t0,56($sp) #load _1:48_ to$t0
nop
lw $t1,52($sp) #load _1:52_ to$t1
nop
sw $t1,0($t0) #write back via indirection
li $t2,1 #imm id _1:56_
lw $t3,80($sp) #load _1:24_ to$t3
nop
lw $t3,0($t3) #de ref
nop
li $t4,4 #imm id _1:64_
mult $t2,$t4 #cal offset _1:68
mflo $t5#cal offset _1:68
addu $t2,$t3,$t5 #dst id _1:72_
sw $t2,32($sp) #write back id 1:72
sw $t4,40($sp) #write back id 1:64
lw $t0,32($sp) #load _1:72_ to$t0
nop
lw $t0,0($t0) #de ref
nop
# assign _1:80_ to _1:76_ in reg $t0
move $2,$t0
b EXIT_f
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 104
j $31
.end f

