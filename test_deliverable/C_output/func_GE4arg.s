.globl f6
.ent f6
f6:
.frame $fp,48,$31
addiu $sp, $sp, -48
sw $31, 24($sp)
# Enter scope
sw $a0,48($sp) #store parameter 0:0
sw $a1,52($sp) #store parameter 0:-4
sw $a2,56($sp) #store parameter 0:-8
sw $a3,60($sp) #store parameter 0:-12
# Enter scope
lw $a0,52($sp) #load first 4 arg
nop
lw $a1,56($sp) #load first 4 arg
nop
lw $a2,60($sp) #load first 4 arg
nop
lw $a3,64($sp) #load first 4 arg
nop
jal ff
move $t0,$v0 #mv return to tReg _1:4_
sw $t0,44($sp) #write back id 1:4
lw $a0,48($sp) #load first 4 arg
nop
lw $a1,52($sp) #load first 4 arg
nop
lw $a2,56($sp) #load first 4 arg
nop
lw $a3,60($sp) #load first 4 arg
nop
lw $t0,64($sp) #load _0:-16_ to$t0
nop
sw $t0,16($sp) #load later args
lw $t0,68($sp) #load _0:-20_ to$t0
nop
sw $t0,20($sp) #load later args
jal ff2
move $t0,$v0 #mv return to tReg _1:8_
lw $t1,44($sp) #load _1:4_ to$t1
nop
addu $t2,$t1,$t0 #dst id _1:12_
sw $t2,36($sp) #write back id 1:12
lw $t0,36($sp) #load _1:12_ to$t0
nop
# assign _1:12_ to _1:16_ in reg $t0
move $2,$t0
b EXIT_f6
# End scope
# End scope
EXIT_f6:
lw $31, 24($sp)
addiu $sp, $sp, 48
j $31
.end f6

.globl ff
.ent ff
ff:
.frame $fp,40,$31
addiu $sp, $sp, -40
sw $31, 20($sp)
# Enter scope
sw $a0,40($sp) #store parameter 0:0
sw $a1,44($sp) #store parameter 0:-4
sw $a2,48($sp) #store parameter 0:-8
sw $a3,52($sp) #store parameter 0:-12
# Enter scope
lw $t0,40($sp) #load _0:0_ to$t0
nop
lw $t1,44($sp) #load _0:-4_ to$t1
nop
addu $t2,$t0,$t1 #dst id _1:4_
lw $t3,48($sp) #load _0:-8_ to$t3
nop
addu $t4,$t2,$t3 #dst id _1:8_
lw $t2,52($sp) #load _0:-12_ to$t2
nop
addu $t5,$t4,$t2 #dst id _1:12_
sw $t5,28($sp) #write back id 1:12
lw $t0,28($sp) #load _1:12_ to$t0
nop
# assign _1:12_ to _1:16_ in reg $t0
move $2,$t0
b EXIT_ff
# End scope
# End scope
EXIT_ff:
lw $31, 20($sp)
addiu $sp, $sp, 40
j $31
.end ff

.globl ff2
.ent ff2
ff2:
.frame $fp,48,$31
addiu $sp, $sp, -48
sw $31, 20($sp)
# Enter scope
sw $a0,48($sp) #store parameter 0:0
sw $a1,52($sp) #store parameter 0:-4
sw $a2,56($sp) #store parameter 0:-8
sw $a3,60($sp) #store parameter 0:-12
# Enter scope
lw $t0,48($sp) #load _0:0_ to$t0
nop
lw $t1,52($sp) #load _0:-4_ to$t1
nop
addu $t2,$t0,$t1 #dst id _1:4_
lw $t3,56($sp) #load _0:-8_ to$t3
nop
addu $t4,$t2,$t3 #dst id _1:8_
lw $t2,60($sp) #load _0:-12_ to$t2
nop
addu $t5,$t4,$t2 #dst id _1:12_
lw $t4,64($sp) #load _0:-16_ to$t4
nop
addu $t6,$t5,$t4 #dst id _1:16_
lw $t5,68($sp) #load _0:-20_ to$t5
nop
addu $t7,$t6,$t5 #dst id _1:20_
sw $t7,28($sp) #write back id 1:20
lw $t0,28($sp) #load _1:20_ to$t0
nop
# assign _1:20_ to _1:24_ in reg $t0
move $2,$t0
b EXIT_ff2
# End scope
# End scope
EXIT_ff2:
lw $31, 20($sp)
addiu $sp, $sp, 48
j $31
.end ff2

