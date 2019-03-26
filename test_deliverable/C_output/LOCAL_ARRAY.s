.globl f
.ent f
f:
.frame $fp,136,$31
addiu $sp, $sp, -136
sw $31, 20($sp)
# Enter scope
sw $a0,136($sp) #store parameter 0:0
sw $a1,140($sp) #store parameter 0:-4
# Enter scope
li $t0,0 #imm id _1:24_
sw $t0,112($sp) #write back id 1:24
lw $t0,112($sp) #load _1:24_ to$t0
nop
# assign _1:24_ to _1:20_ in reg $t0
li $t1,5 #imm id _1:28_
sw $t0,116($sp) #write back id 1:20
sw $t1,108($sp) #write back id 1:28
lw $t0,108($sp) #load _1:28_ to$t0
nop
# assign _1:28_ to _1:16_ in reg $t0
li $t1,2 #imm id _1:32_
sw $t0,120($sp) #write back id 1:16
sw $t1,104($sp) #write back id 1:32
lw $t0,104($sp) #load _1:32_ to$t0
nop
# assign _1:32_ to _1:12_ in reg $t0
li $t1,3 #imm id _1:36_
sw $t0,124($sp) #write back id 1:12
sw $t1,100($sp) #write back id 1:36
lw $t0,100($sp) #load _1:36_ to$t0
nop
# assign _1:36_ to _1:8_ in reg $t0
li $t1,0 #imm id _1:40_
sw $t0,128($sp) #write back id 1:8
sw $t1,96($sp) #write back id 1:40
lw $t0,96($sp) #load _1:40_ to$t0
nop
# assign _1:40_ to _1:4_ in reg $t0
li $t1,0 #imm id _1:44_
li $t2,0 #imm id _1:48_
lw $t3,84($sp) #load _1:52_ to$t3
nop
addiu $t3, $sp, 116 #addr of a
lw $t4,140($sp) #load _0:-4_ to$t4
nop
li $t5,4 #imm id _1:56_
mult $t4,$t5 #cal offset _1:60
mflo $t6#cal offset _1:60
addu $t7,$t3,$t6 #dst id _1:64_
sw $t0,132($sp) #write back id 1:4
sw $t1,92($sp) #write back id 1:44
sw $t2,88($sp) #write back id 1:48
sw $t3,84($sp) #write back id 1:52
sw $t5,80($sp) #write back id 1:56
sw $t7,72($sp) #write back id 1:64
lw $t0,72($sp) #load _1:64_ to$t0
nop
lw $t1,140($sp) #load _0:-4_ to$t1
nop
sw $t1,0($t0) #write back via indirection
lw $t2,68($sp) #load _1:68_ to$t2
nop
addiu $t2, $sp, 116 #addr of a
lw $t3,136($sp) #load _0:0_ to$t3
nop
li $t4,4 #imm id _1:72_
mult $t3,$t4 #cal offset _1:76
mflo $t5#cal offset _1:76
addu $t6,$t2,$t5 #dst id _1:80_
sw $t2,68($sp) #write back id 1:68
sw $t4,64($sp) #write back id 1:72
sw $t6,56($sp) #write back id 1:80
lw $t0,56($sp) #load _1:80_ to$t0
nop
lw $t0,0($t0) #de ref
nop
# assign _1:84_ to _1:44_ in reg $t0
lw $t1,48($sp) #load _1:88_ to$t1
nop
addiu $t1, $sp, 116 #addr of a
lw $t2,140($sp) #load _0:-4_ to$t2
nop
li $t3,4 #imm id _1:92_
mult $t2,$t3 #cal offset _1:96
mflo $t4#cal offset _1:96
addu $t5,$t1,$t4 #dst id _1:100_
sw $t0,92($sp) #write back id 1:44
sw $t1,48($sp) #write back id 1:88
sw $t3,44($sp) #write back id 1:92
sw $t5,36($sp) #write back id 1:100
lw $t0,36($sp) #load _1:100_ to$t0
nop
lw $t0,0($t0) #de ref
nop
# assign _1:104_ to _1:48_ in reg $t0
lw $t1,92($sp) #load _1:44_ to$t1
nop
addu $t2,$t1,$t0 #dst id _1:108_
sw $t0,88($sp) #write back id 1:48
sw $t2,28($sp) #write back id 1:108
lw $t0,28($sp) #load _1:108_ to$t0
nop
# assign _1:108_ to _1:112_ in reg $t0
move $2,$t0
b EXIT_f
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 136
j $31
.end f

