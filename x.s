.globl array2
.ent array2
array2:
.frame $fp,344,$31
addiu $sp, $sp, -344
sw $31, 20($sp)
# Enter scope
sw $a0,344($sp) #store parameter 0:0
sw $a1,348($sp) #store parameter 0:-4
# Enter scope
li $t0,1 #imm id _1:204_
sw $t0,140($sp) #write back id 1:204
lw $t0,140($sp) #load _1:204_ to$t0
nop
# assign _1:204_ to _1:200_ in reg $t0
li $t1,2 #imm id _1:208_
sw $t0,144($sp) #write back id 1:200
sw $t1,136($sp) #write back id 1:208
lw $t0,136($sp) #load _1:208_ to$t0
nop
# assign _1:208_ to _1:196_ in reg $t0
li $t1,3 #imm id _1:212_
sw $t0,148($sp) #write back id 1:196
sw $t1,132($sp) #write back id 1:212
lw $t0,132($sp) #load _1:212_ to$t0
nop
# assign _1:212_ to _1:192_ in reg $t0
li $t1,4 #imm id _1:216_
sw $t0,152($sp) #write back id 1:192
sw $t1,128($sp) #write back id 1:216
lw $t0,128($sp) #load _1:216_ to$t0
nop
# assign _1:216_ to _1:188_ in reg $t0
li $t1,5 #imm id _1:220_
sw $t0,156($sp) #write back id 1:188
sw $t1,124($sp) #write back id 1:220
lw $t0,124($sp) #load _1:220_ to$t0
nop
# assign _1:220_ to _1:184_ in reg $t0
li $t1,6 #imm id _1:224_
sw $t0,160($sp) #write back id 1:184
sw $t1,120($sp) #write back id 1:224
lw $t0,120($sp) #load _1:224_ to$t0
nop
# assign _1:224_ to _1:180_ in reg $t0
li $t1,7 #imm id _1:228_
sw $t0,164($sp) #write back id 1:180
sw $t1,116($sp) #write back id 1:228
lw $t0,116($sp) #load _1:228_ to$t0
nop
# assign _1:228_ to _1:176_ in reg $t0
li $t1,8 #imm id _1:232_
sw $t0,168($sp) #write back id 1:176
sw $t1,112($sp) #write back id 1:232
lw $t0,112($sp) #load _1:232_ to$t0
nop
# assign _1:232_ to _1:172_ in reg $t0
li $t1,9 #imm id _1:236_
sw $t0,172($sp) #write back id 1:172
sw $t1,108($sp) #write back id 1:236
lw $t0,108($sp) #load _1:236_ to$t0
nop
# assign _1:236_ to _1:168_ in reg $t0
li $t1,10 #imm id _1:240_
sw $t0,176($sp) #write back id 1:168
sw $t1,104($sp) #write back id 1:240
lw $t0,104($sp) #load _1:240_ to$t0
nop
# assign _1:240_ to _1:164_ in reg $t0
li $t1,11 #imm id _1:244_
sw $t0,180($sp) #write back id 1:164
sw $t1,100($sp) #write back id 1:244
lw $t0,100($sp) #load _1:244_ to$t0
nop
# assign _1:244_ to _1:160_ in reg $t0
li $t1,12 #imm id _1:248_
sw $t0,184($sp) #write back id 1:160
sw $t1,96($sp) #write back id 1:248
lw $t0,96($sp) #load _1:248_ to$t0
nop
# assign _1:248_ to _1:156_ in reg $t0
li $t1,13 #imm id _1:252_
sw $t0,188($sp) #write back id 1:156
sw $t1,92($sp) #write back id 1:252
lw $t0,92($sp) #load _1:252_ to$t0
nop
# assign _1:252_ to _1:152_ in reg $t0
li $t1,14 #imm id _1:256_
sw $t0,192($sp) #write back id 1:152
sw $t1,88($sp) #write back id 1:256
lw $t0,88($sp) #load _1:256_ to$t0
nop
# assign _1:256_ to _1:148_ in reg $t0
li $t1,15 #imm id _1:260_
sw $t0,196($sp) #write back id 1:148
sw $t1,84($sp) #write back id 1:260
lw $t0,84($sp) #load _1:260_ to$t0
nop
# assign _1:260_ to _1:144_ in reg $t0
li $t1,16 #imm id _1:264_
sw $t0,200($sp) #write back id 1:144
sw $t1,80($sp) #write back id 1:264
lw $t0,80($sp) #load _1:264_ to$t0
nop
# assign _1:264_ to _1:140_ in reg $t0
lw $t1,76($sp) #load _1:268_ to$t1
nop
addiu $t1, $sp, 144 #addr of c
li $t2,39 #imm id _1:272_
li $t3,4 #imm id _1:276_
mult $t2,$t3 #cal offset _1:280
mflo $t4#cal offset _1:280
addu $t2,$t1,$t4 #dst id _1:284_
lw $t4,344($sp) #load _0:0_ to$t4
nop
lw $t5,348($sp) #load _0:-4_ to$t5
nop
mult $t4,$t5 #dst id _1:288_
mflo $t6#dst id _1:288_
sw $t0,204($sp) #write back id 1:140
sw $t1,76($sp) #write back id 1:268
sw $t2,60($sp) #write back id 1:284
sw $t3,68($sp) #write back id 1:276
sw $t6,56($sp) #write back id 1:288
lw $t0,60($sp) #load _1:284_ to$t0
nop
lw $t1,56($sp) #load _1:288_ to$t1
nop
sw $t1,0($t0) #write back via indirection
lw $t2,52($sp) #load _1:292_ to$t2
nop
addiu $t2, $sp, 144 #addr of c
li $t3,39 #imm id _1:296_
li $t4,4 #imm id _1:300_
mult $t3,$t4 #cal offset _1:304
mflo $t5#cal offset _1:304
addu $t3,$t2,$t5 #dst id _1:308_
sw $t2,52($sp) #write back id 1:292
sw $t3,36($sp) #write back id 1:308
sw $t4,44($sp) #write back id 1:300
lw $t0,36($sp) #load _1:308_ to$t0
nop
lw $t0,0($t0) #de ref
nop
# assign _1:316_ to _1:312_ in reg $t0
move $2,$t0
b EXIT_array2
# End scope
# End scope
EXIT_array2:
lw $31, 20($sp)
addiu $sp, $sp, 344
j $31
.end array2

