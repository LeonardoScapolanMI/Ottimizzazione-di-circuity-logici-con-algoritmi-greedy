----------------------------------------------------------------------
entity randomcircuit is
	port (
		in0      : in  std_logic;
		in1      : in  std_logic;
		in2      : in  std_logic;
		in3      : in  std_logic;
		in4      : in  std_logic;
		in5      : in  std_logic;
		in6      : in  std_logic;
		out0     : out std_logic
	);
end randomcircuit;
----------------------------------------------------------------------

----------------------------------------------------------------------
architecture struct of randomcircuit is
	signal net_0      : std_logic;
	signal net_1      : std_logic;
	signal net_2      : std_logic;
	signal net_3      : std_logic;
	signal net_4      : std_logic;
	signal net_5      : std_logic;
	signal net_6      : std_logic;
	signal net_7      : std_logic;
	signal net_8      : std_logic;
	signal net_9      : std_logic;
	signal net_10     : std_logic;
	signal net_11     : std_logic;
	signal net_12     : std_logic;
	signal net_13     : std_logic;
	signal net_14     : std_logic;
	signal net_15     : std_logic;
	signal net_16     : std_logic;
	signal net_17     : std_logic;
	signal net_18     : std_logic;
	signal net_19     : std_logic;
	signal net_20     : std_logic;
	signal net_21     : std_logic;
	signal net_22     : std_logic;
	signal net_23     : std_logic;
	signal net_24     : std_logic;
	signal net_25     : std_logic;
	signal net_26     : std_logic;
	signal net_27     : std_logic;
	signal net_28     : std_logic;
	signal net_29     : std_logic;
	signal net_30     : std_logic;
	signal net_31     : std_logic;
	signal net_32     : std_logic;
	signal net_33     : std_logic;
	signal net_34     : std_logic;
	signal net_35     : std_logic;
	signal net_36     : std_logic;
	signal net_37     : std_logic;
	signal net_38     : std_logic;
	signal net_39     : std_logic;
	signal net_40     : std_logic;
	signal net_41     : std_logic;
	signal net_42     : std_logic;
	signal net_43     : std_logic;
	signal net_44     : std_logic;
	signal net_45     : std_logic;
	signal net_46     : std_logic;
	signal net_47     : std_logic;
	signal net_48     : std_logic;
begin
	net_42 <= in0;
	net_43 <= in1;
	net_44 <= in2;
	net_45 <= in3;
	net_46 <= in4;
	net_47 <= in5;
	net_48 <= in6;
	out0 <= net_0;
	U52 : NOT1 port map(A1 => net_45, Z => net_34);
	U53 : XOR3 port map(A1 => net_47, A2 => net_48, A3 => net_45, Z => net_35);
	U54 : XOR3 port map(A1 => net_46, A2 => net_44, A3 => net_48, Z => net_36);
	U56 : XOR3 port map(A1 => net_42, A2 => net_43, A3 => net_45, Z => net_37);
	U57 : XOR2 port map(A1 => net_46, A2 => net_45, Z => net_38);
	U59 : NOR3 port map(A1 => net_42, A2 => net_48, A3 => net_42, Z => net_39);
	U60 : XNOR3 port map(A1 => net_48, A2 => net_45, A3 => net_48, Z => net_40);
	U61 : NAND3 port map(A1 => net_42, A2 => net_48, A3 => net_45, Z => net_41);
	U42 : OR3 port map(A1 => net_37, A2 => net_38, A3 => net_38, Z => net_25);
	U43 : NOR2 port map(A1 => net_40, A2 => net_48, Z => net_26);
	U44 : XOR2 port map(A1 => net_41, A2 => net_41, Z => net_27);
	U45 : NOT1 port map(A1 => net_35, Z => net_28);
	U46 : NOR4 port map(A1 => net_48, A2 => net_38, A3 => net_42, A4 => net_38, Z => net_29);
	U47 : XNOR2 port map(A1 => net_36, A2 => net_38, Z => net_30);
	U48 : NOR4 port map(A1 => net_45, A2 => net_37, A3 => net_43, A4 => net_46, Z => net_31);
	U49 : NOR3 port map(A1 => net_44, A2 => net_40, A3 => net_46, Z => net_32);
	U50 : AND2 port map(A1 => net_40, A2 => net_42, Z => net_33);
	U32 : NOT1 port map(A1 => net_25, Z => net_16);
	U33 : NOR2 port map(A1 => net_48, A2 => net_42, Z => net_17);
	U34 : NOT1 port map(A1 => net_29, Z => net_18);
	U35 : XNOR2 port map(A1 => net_31, A2 => net_44, Z => net_19);
	U36 : NOR4 port map(A1 => net_27, A2 => net_30, A3 => net_28, A4 => net_29, Z => net_20);
	U37 : AND4 port map(A1 => net_33, A2 => net_44, A3 => net_47, A4 => net_48, Z => net_21);
	U38 : XOR3 port map(A1 => net_44, A2 => net_47, A3 => net_31, Z => net_22);
	U39 : NOR4 port map(A1 => net_41, A2 => net_44, A3 => net_35, A4 => net_29, Z => net_23);
	U41 : XNOR3 port map(A1 => net_26, A2 => net_35, A3 => net_46, Z => net_24);
	U23 : OR2 port map(A1 => net_20, A2 => net_24, Z => net_9);
	U24 : NAND4 port map(A1 => net_23, A2 => net_31, A3 => net_31, A4 => net_40, Z => net_10);
	U25 : NAND2 port map(A1 => net_32, A2 => net_46, Z => net_11);
	U26 : XOR3 port map(A1 => net_28, A2 => net_34, A3 => net_39, Z => net_12);
	U27 : NOT1 port map(A1 => net_19, Z => net_13);
	U29 : NAND4 port map(A1 => net_16, A2 => net_29, A3 => net_20, A4 => net_23, Z => net_14);
	U30 : NOT1 port map(A1 => net_17, Z => net_15);
	U12 : AND4 port map(A1 => net_9, A2 => net_11, A3 => net_15, A4 => net_21, Z => net_4);
	U13 : NOT1 port map(A1 => net_12, Z => net_5);
	U14 : NOT1 port map(A1 => net_22, Z => net_6);
	U15 : AND2 port map(A1 => net_13, A2 => net_18, Z => net_7);
	U16 : OR2 port map(A1 => net_10, A2 => net_14, Z => net_8);
	U2 : NOR2 port map(A1 => net_6, A2 => net_8, Z => net_1);
	U3 : NOT1 port map(A1 => net_4, Z => net_2);
	U4 : XOR2 port map(A1 => net_5, A2 => net_7, Z => net_3);
	U1 : OR3 port map(A1 => net_1, A2 => net_2, A3 => net_3, Z => net_0);
end struct;
