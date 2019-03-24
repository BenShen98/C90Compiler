.globl f6
.ent f6
f6:
.frame $fp,48,$31
addiu $sp, $sp, -48
sw $31, 20($sp)
sw $a0,48($sp) #store parameter 0:0
sw $a1,52($sp) #store parameter 0:-4
sw $a2,56($sp) #store parameter 0:-8
sw $a3,60($sp) #store parameter 0:-12
lw $t0,48($sp) #load _0:0_ to$t0
lw $t1,52($sp) #load _0:-4_ to$t1
addu $t2,$t0,$t1 #dst id _1:4_
lw $t3,56($sp) #load _0:-8_ to$t3
addu $t4,$t2,$t3 #dst id _1:8_
# assign _1:8_ to _1:12_ in reg $t4
move $2,$t4
b EXIT_f6
EXIT_f6:
lw $31, 20($sp)
addiu $sp, $sp, 48
j $31
.end f6

