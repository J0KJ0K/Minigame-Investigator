	.include "MPlayDef.s"

	.equ	mus_title_grp, voicegroup059
	.equ	mus_title_pri, 0
	.equ	mus_title_rev, reverb_set+50
	.equ	mus_title_mvl, 90
	.equ	mus_title_key, 0
	.equ	mus_title_tbs, 1
	.equ	mus_title_exg, 1
	.equ	mus_title_cmp, 1

	.section .rodata
	.global	mus_title
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_title_1:
	.byte	KEYSH , mus_title_key+0
mus_title_1_B1:
@ 000   ----------------------------------------
@ 001   ----------------------------------------
	.byte	TEMPO , 120*mus_title_tbs/2
	.byte		VOICE , 0
	.byte		VOL   , 100*mus_title_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N92   , Cn2 , v080, gtp3
	.byte	W96
@ 002   ----------------------------------------
mus_title_1_002:
	.byte		N44   , Ds2 , v080, gtp3
	.byte	W48
	.byte		        Gn2 , v080, gtp3
	.byte	W48
	.byte	PEND
@ 003   ----------------------------------------
	.byte		N92   , Gs2 , v080, gtp3
	.byte	W96
@ 004   ----------------------------------------
mus_title_1_004:
	.byte		N68   , Gn2 , v080, gtp3
	.byte	W72
	.byte		N23   , Ds2 
	.byte	W24
	.byte	PEND
@ 005   ----------------------------------------
	.byte		N92   , Cn2 , v080, gtp3
	.byte	W96
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_title_1_002
@ 007   ----------------------------------------
	.byte		N92   , Gs2 , v080, gtp3
	.byte	W96
@ 008   ----------------------------------------
	.byte		N68   , Cn3 , v080, gtp3
	.byte	W72
	.byte		N23   , Gs2 
	.byte	W24
@ 009   ----------------------------------------
	.byte		N92   , Fn2 , v080, gtp3
	.byte	W96
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_title_1_004
@ 011   ----------------------------------------
	.byte		N92   , Cn2 , v080, gtp3
	.byte	W96
@ 012   ----------------------------------------
	.byte	W96
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W72
	.byte	W02
	.byte	GOTO
	 .word	mus_title_1_B1
mus_title_1_B2:
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

mus_title_2:
	.byte	KEYSH , mus_title_key+0
mus_title_2_B1:
@ 000   ----------------------------------------
	.byte		VOICE , 41
	.byte		VOL   , 100*mus_title_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N92   , Cn2 , v080, gtp3
	.byte		N92   , Cn3 , v080, gtp3
	.byte	W96
@ 001   ----------------------------------------
mus_title_2_001:
	.byte		N44   , Ds2 , v080, gtp3
	.byte		N44   , Ds3 , v080, gtp3
	.byte	W48
	.byte		        Gn2 , v080, gtp3
	.byte		N44   , Gn3 , v080, gtp3
	.byte	W48
	.byte	PEND
@ 002   ----------------------------------------
mus_title_2_002:
	.byte		N92   , Gs2 , v080, gtp3
	.byte		N92   , Gs3 , v080, gtp3
	.byte	W96
	.byte	PEND
@ 003   ----------------------------------------
mus_title_2_003:
	.byte		N68   , Gn2 , v080, gtp3
	.byte		N68   , Gn3 , v080, gtp3
	.byte	W72
	.byte		N23   , Ds2 
	.byte		N23   , Ds3 
	.byte	W24
	.byte	PEND
@ 004   ----------------------------------------
	.byte		N92   , Cn2 , v080, gtp3
	.byte		N92   , Cn3 , v080, gtp3
	.byte	W96
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_title_2_001
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_title_2_002
@ 007   ----------------------------------------
	.byte		N68   , Cn3 , v080, gtp3
	.byte		N68   , Cn4 , v080, gtp3
	.byte	W72
	.byte		N23   , Gs2 
	.byte		N23   , Gs3 
	.byte	W24
@ 008   ----------------------------------------
	.byte		N92   , Fn2 , v080, gtp3
	.byte		N92   , Fn3 , v080, gtp3
	.byte	W96
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_title_2_003
@ 010   ----------------------------------------
	.byte		TIE   , Cn2 , v080
	.byte		TIE   , Cn3 
	.byte	W96
@ 011   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		EOT   , Cn2 
	.byte		        Cn3 
	.byte	W01
@ 012   ----------------------------------------
	.byte	W96
@ 013   ----------------------------------------
	.byte	W72
	.byte	W02
	.byte	GOTO
	 .word	mus_title_2_B1
mus_title_2_B2:
	.byte	FINE

@**************** Track 3 (Midi-Chn.5) ****************@

mus_title_3:
	.byte	KEYSH , mus_title_key+0
mus_title_3_B1:
@ 000   ----------------------------------------
	.byte		VOICE , 127
	.byte		VOL   , 100*mus_title_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N44   , Bn0 , v080, gtp3
	.byte	W48
	.byte		N02   , Ds2 
	.byte	W36
	.byte		N23   , Bn0 
	.byte	W12
@ 001   ----------------------------------------
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N02   , Ds2 
	.byte	W48
@ 002   ----------------------------------------
mus_title_3_002:
	.byte		N44   , Bn0 , v080, gtp3
	.byte	W48
	.byte		N02   , Ds2 
	.byte	W36
	.byte		N23   , Bn0 
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
mus_title_3_003:
	.byte	W12
	.byte		N11   , Bn0 , v080
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N02   , Ds2 
	.byte	W48
	.byte	PEND
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_title_3_002
@ 005   ----------------------------------------
	.byte	W12
	.byte		N11   , Bn0 , v080
	.byte	W12
	.byte		N11   
	.byte	W24
	.byte		N02   , Ds2 
	.byte	W48
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_title_3_002
@ 007   ----------------------------------------
	.byte	W24
	.byte		N11   , Bn0 , v080
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N02   , Ds2 
	.byte	W48
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_title_3_002
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_title_3_003
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_title_3_002
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_title_3_003
@ 012   ----------------------------------------
	.byte		N44   , Bn0 , v080, gtp3
	.byte	W48
	.byte		N02   , Ds2 
	.byte	W36
	.byte		N23   , Bn0 
	.byte	W12
@ 013   ----------------------------------------
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N02   , Ds2 
	.byte	W24
	.byte	W02
	.byte	GOTO
	 .word	mus_title_3_B1
mus_title_3_B2:
	.byte	FINE

@******************************************************@
	.align	2

mus_title:
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_title_pri	@ Priority
	.byte	mus_title_rev	@ Reverb.

	.word	mus_title_grp

	.word	mus_title_1
	.word	mus_title_2
	.word	mus_title_3

	.end
