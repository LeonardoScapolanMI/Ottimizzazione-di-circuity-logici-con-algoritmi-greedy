----------------------------------------------------------------------
entity randomcircuit is
	port (
		in0		: in  std_logic;
		in1		: in  std_logic;
		in2		: in  std_logic;
		in3		: in  std_logic;
		in4		: in  std_logic;
		in5		: in  std_logic;
		in6		: in  std_logic;
		out0		: out std_logic
	);
end randomcircuit;
----------------------------------------------------------------------

----------------------------------------------------------------------
architecture struct of randomcircuit is
	signal net_0		: std_logic;
	signal net_1		: std_logic;
	signal net_2		: std_logic;
	signal net_3		: std_logic;
	signal net_4		: std_logic;
	signal net_5		: std_logic;
	signal net_6		: std_logic;
	signal net_7		: std_logic;
	signal net_8		: std_logic;
	signal net_9		: std_logic;
	signal net_10		: std_logic;
	signal net_11		: std_logic;
	signal net_12		: std_logic;
	signal net_13		: std_logic;
	signal net_14		: std_logic;
	signal net_15		: std_logic;
	signal net_16		: std_logic;
	signal net_17		: std_logic;
	signal net_18		: std_logic;
	signal net_19		: std_logic;
	signal net_20		: std_logic;
	signal net_21		: std_logic;
	signal net_22		: std_logic;
	signal net_23		: std_logic;
	signal net_24		: std_logic;
	signal net_25		: std_logic;
	signal net_26		: std_logic;
	signal net_27		: std_logic;
	signal net_28		: std_logic;
	signal net_29		: std_logic;
	signal net_30		: std_logic;
	signal net_31		: std_logic;
	signal net_32		: std_logic;
	signal net_33		: std_logic;
	signal net_34		: std_logic;
	signal net_35		: std_logic;
	signal net_36		: std_logic;
	signal net_37		: std_logic;
	signal net_38		: std_logic;
	signal net_39		: std_logic;
	signal net_40		: std_logic;
	signal net_41		: std_logic;
begin
	net_35 <= in0;
	net_36 <= in1;
	net_37 <= in2;
	net_38 <= in3;
	net_39 <= in4;
	net_40 <= in5;
	net_41 <= in6;
	U33 : XOR2 port map(A1 => net_38, A2 => net_41, Z => net_27);
	U34 : NOR4 port map(A1 => net_37, A2 => net_35, A3 => net_36, A4 => net_38, Z => net_28);
	U35 : XOR3 port map(A1 => net_35, A2 => net_35, A3 => net_37, Z => net_29);
	U36 : OR3 port map(A1 => net_38, A2 => net_40, A3 => net_41, Z => net_30);
	U37 : OR4 port map(A1 => net_41, A2 => net_41, A3 => net_35, A4 => net_37, Z => net_31);
	U38 : XOR2 port map(A1 => net_36, A2 => net_35, Z => net_32);
	U39 : NOT1 port map(A1 => net_41, Z => net_33);
	U40 : XNOR3 port map(A1 => net_35, A2 => net_38, A3 => net_37, Z => net_34);
	U27 : NOT1 port map(A1 => net_28, Z => net_21);
	U28 : NOT1 port map(A1 => net_28, Z => net_22);
	U29 : NOR2 port map(A1 => net_29, A2 => net_37, Z => net_23);
	U30 : NOT1 port map(A1 => net_27, Z => net_24);
	U31 : XOR2 port map(A1 => net_34, A2 => net_29, Z => net_25);
	U32 : NAND3 port map(A1 => net_31, A2 => net_35, A3 => net_31, Z => net_26);
	U23 : NOR3 port map(A1 => net_41, A2 => net_26, A3 => net_38, Z => net_17);
	U24 : XNOR3 port map(A1 => net_30, A2 => net_39, A3 => net_28, Z => net_18);
	U25 : NOT1 port map(A1 => net_21, Z => net_19);
	U26 : NOR4 port map(A1 => net_36, A2 => net_24, A3 => net_29, A4 => net_31, Z => net_20);
	U16 : XNOR3 port map(A1 => net_39, A2 => net_40, A3 => net_21, Z => net_10);
	U17 : XOR3 port map(A1 => net_23, A2 => net_40, A3 => net_38, Z => net_11);
	U18 : NOT1 port map(A1 => net_20, Z => net_12);
	U19 : XNOR2 port map(A1 => net_18, A2 => net_19, Z => net_13);
	U20 : NOT1 port map(A1 => net_26, Z => net_14);
	U21 : NOT1 port map(A1 => net_24, Z => net_15);
	U22 : NAND4 port map(A1 => net_37, A2 => net_18, A3 => net_33, A4 => net_34, Z => net_16);
	U10 : NOR4 port map(A1 => net_10, A2 => net_11, A3 => net_22, A4 => net_32, Z => net_4);
	U11 : NOR2 port map(A1 => net_14, A2 => net_15, Z => net_5);
	U12 : OR2 port map(A1 => net_17, A2 => net_33, Z => net_6);
	U13 : OR2 port map(A1 => net_13, A2 => net_25, Z => net_7);
	U14 : XNOR3 port map(A1 => net_38, A2 => net_36, A3 => net_35, Z => net_8);
	U15 : NOT1 port map(A1 => net_16, Z => net_9);
	U2 : AND2 port map(A1 => net_6, A2 => net_9, Z => net_1);
	U3 : AND2 port map(A1 => net_4, A2 => net_8, Z => net_2);
	U4 : NAND4 port map(A1 => net_5, A2 => net_7, A3 => net_12, A4 => net_20, Z => net_3);
	U1 : OR3 port map(A1 => net_1, A2 => net_2, A3 => net_3, Z => net_0);
	out0 <= net_0;
end struct;
