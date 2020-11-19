.text
.align 2
range_st:
    stmfd   sp! , {r1   , lr}
    cmp     r1  , #65
    blt     range_ed
    b       range_1
range_1:
    cmp     r1  , #90
    bgt     range_2
    add     r1  , r1    , #32
    adr     r0  , outchar
    bl      printf
    b       range_ed
range_2:
    cmp     r1  , #97
    blt     range_ed
    b       range_3
range_3:
    cmp     r1  , #122
    bgt     range_ed
    adr     r0  , outchar
    bl      printf
    b       range_ed
range_ed:
    ldmfd   sp! , {r1   , lr}
    bx      lr
getstr_st:
    stmfd   sp! , {r1   ,r5 ,r6 , lr}
    mov     r5  , r1            /* r5 is remember as pointer to the char array*/
    mov     r6  , #0            /* r6 is the index*/
    b       getstr
getstr:
    ldrb    r1  , [r5   , r6]   /* r1 is the character*/
    cmp     r1  , #0
    bl      range_st
    ldrb    r1  , [r5   , r6]
    cmp     r1  , #0
    addgt   r6  , r6    , #1
    bgt     getstr
    b       getstr_ed
getstr_ed:
    ldmfd   sp! , {r1   ,r5 ,r6 , lr}
    bx      lr
retrive_all_str_st:
    stmfd   sp! , {r1   ,r5 ,r6 , lr}
    mov     r8  , r0                    /* r8 argc count */
    mov     r7  , #1                    /* r7 argv[r7]*/
retrive_all_str:
    ldr     r1  , [r4   , r7 ,lsl #2]
    bl      getstr_st
    add     r7  , r7    , #1
    cmp     r7  , r8
    beq     retrive_all_str_ed
    b       retrive_all_str
retrive_all_str_ed:
    ldmfd   sp! , {r1   ,r5 ,r6 , lr}
    bx      lr
.global main /* 'main' is our entry point and must be global */
main:
    stmfd   sp! , {fp   , lr}
    add     fp  , sp    , #4
    mov     r4  , r1
    mov     r1  , r0
    /* argc r1 , argv r4*/
    bl      retrive_all_str_st
    adr     r0  , nextline
    bl      printf
    sub     sp  , fp    , #4
    ldmfd   sp! , {fp   , lr}
    bx lr
printchar:  .asciz  "%c\n"
outchar:    .asciz  "%c"
nextline:   .asciz  "\n"
