.globl oneLif
.ent oneLif
oneLif:
.frame $fp,88,$31
addiu $sp, $sp, -88
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,5 #imm id _1:8_
sw $t0,80($sp) #write back id 1:8
lw $t0,80($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
li $t1,4 #imm id _1:20_
xor $t2,$t0,$t1 #dst id _1:24_
sltu $t2,$t2,0x1 #dst id _1:24_
sw $t0,84($sp) #write back id 1:4
sw $t2,64($sp) #write back id 1:24
lw $t0,64($sp) #load _1:24_ to$t0
nop
beq $t0,$0,elseStart_0_oneLif
li $t1,77 #imm id _1:28_
sw $t1,60($sp) #write back id 1:28
lw $t0,60($sp) #load _1:28_ to$t0
nop
# assign _1:28_ to _1:16_ in reg $t0
sw $t0,72($sp) #write back id 1:16
b elseEnd_1_oneLif
elseStart_0_oneLif:

li $t0,2 #imm id _1:32_
sw $t0,56($sp) #write back id 1:32
lw $t0,56($sp) #load _1:32_ to$t0
nop
# assign _1:32_ to _1:16_ in reg $t0
sw $t0,72($sp) #write back id 1:16
elseEnd_1_oneLif:

lw $t0,72($sp) #load _1:16_ to$t0
nop
# assign _1:16_ to _1:12_ in reg $t0
li $t1,5 #imm id _1:44_
lw $t2,84($sp) #load _1:4_ to$t2
nop
xor $t3,$t2,$t1 #dst id _1:48_
sltu $t3,$t3,0x1 #dst id _1:48_
sw $t0,76($sp) #write back id 1:12
sw $t3,40($sp) #write back id 1:48
lw $t0,40($sp) #load _1:48_ to$t0
nop
beq $t0,$0,elseStart_2_oneLif
li $t1,6 #imm id _1:52_
sw $t1,36($sp) #write back id 1:52
lw $t0,36($sp) #load _1:52_ to$t0
nop
# assign _1:52_ to _1:40_ in reg $t0
sw $t0,48($sp) #write back id 1:40
b elseEnd_3_oneLif
elseStart_2_oneLif:

li $t0,78 #imm id _1:56_
sw $t0,32($sp) #write back id 1:56
lw $t0,32($sp) #load _1:56_ to$t0
nop
# assign _1:56_ to _1:40_ in reg $t0
sw $t0,48($sp) #write back id 1:40
elseEnd_3_oneLif:

lw $t0,48($sp) #load _1:40_ to$t0
nop
# assign _1:40_ to _1:36_ in reg $t0
lw $t1,76($sp) #load _1:12_ to$t1
nop
subu $t2,$t0,$t1 #dst id _1:60_
sw $t0,52($sp) #write back id 1:36
sw $t2,28($sp) #write back id 1:60
lw $t0,28($sp) #load _1:60_ to$t0
nop
# assign _1:60_ to _1:64_ in reg $t0
move $2,$t0
b EXIT_oneLif
# End scope
# End scope
EXIT_oneLif:
lw $31, 20($sp)
addiu $sp, $sp, 88
j $31
.end oneLif

