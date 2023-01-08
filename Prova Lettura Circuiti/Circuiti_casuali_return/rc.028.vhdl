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
		out0     : out std_logic;
		out1     : out std_logic;
		out2     : out std_logic;
		out3     : out std_logic;
		out4     : out std_logic;
		out5     : out std_logic;
		out6     : out std_logic
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
begin
	net_37 <= in0;
	net_38 <= in1;
	net_39 <= in2;
	net_40 <= in3;
	net_41 <= in4;
	net_42 <= in5;
	net_43 <= in6;
	out0 <= net_1;
	out1 <= net_37;
	out2 <= net_2;
	out3 <= net_0;
	out4 <= net_4;
	out5 <= net_35;
	out6 <= net_3;
	U33 : NAND3 port map(A1 => net_43, A2 => net_39, A3 => net_41, Z => net_31);
	U34 : NAND4 port map(A1 => net_37, A2 => net_41, A3 => net_43, A4 => net_37, Z => net_32);
	U35 : NOT1 port map(A1 => net_38, Z => net_33);
	U36 : OR3 port map(A1 => net_39, A2 => net_40, A3 => net_43, Z => net_34);
	U37 : NAND3 port map(A1 => net_40, A2 => net_41, A3 => net_40, Z => net_35);
	U38 : NOT1 port map(A1 => net_37, Z => net_36);
	U27 : XNOR3 port map(A1 => net_38, A2 => net_33, A3 => net_38, Z => net_25);
	U28 : AND4 port map(A1 => net_39, A2 => net_40, A3 => net_40, A4 => net_42, Z => net_26);
	U29 : XOR2 port map(A1 => net_40, A2 => net_43, Z => net_27);
	U30 : OR2 port map(A1 => net_33, A2 => net_38, Z => net_28);
	U31 : OR3 port map(A1 => net_39, A2 => net_38, A3 => net_37, Z => net_29);
	U32 : NAND3 port map(A1 => net_43, A2 => net_40, A3 => net_34, Z => net_30);
	U22 : OR4 port map(A1 => net_30, A2 => net_32, A3 => net_43, A4 => net_43, Z => net_20);
	U23 : XNOR2 port map(A1 => net_34, A2 => net_37, Z => net_21);
	U24 : XNOR2 port map(A1 => net_28, A2 => net_36, Z => net_22);
	U25 : NAND2 port map(A1 => net_38, A2 => net_32, Z => net_23);
	U26 : NAND2 port map(A1 => net_31, A2 => net_33, Z => net_24);
	U18 : NAND4 port map(A1 => net_29, A2 => net_33, A3 => net_29, A4 => net_25, Z => net_16);
	U19 : NOR2 port map(A1 => net_24, A2 => net_43, Z => net_17);
	U20 : XNOR2 port map(A1 => net_37, A2 => net_33, Z => net_18);
	U21 : NAND2 port map(A1 => net_27, A2 => net_38, Z => net_19);
	U12 : OR2 port map(A1 => net_16, A2 => net_35, Z => net_10);
	U13 : AND4 port map(A1 => net_18, A2 => net_27, A3 => net_23, A4 => net_22, Z => net_11);
	U14 : AND3 port map(A1 => net_37, A2 => net_36, A3 => net_27, Z => net_12);
	U15 : NAND4 port map(A1 => net_19, A2 => net_23, A3 => net_41, A4 => net_17, Z => net_13);
	U16 : AND3 port map(A1 => net_38, A2 => net_18, A3 => net_36, Z => net_14);
	U17 : OR3 port map(A1 => net_20, A2 => net_23, A3 => net_37, Z => net_15);
	U5 : XOR3 port map(A1 => net_13, A2 => net_14, A3 => net_22, Z => net_4);
	U6 : NAND2 port map(A1 => net_12, A2 => net_25, Z => net_5);
	U7 : XOR2 port map(A1 => net_21, A2 => net_41, Z => net_6);
	U8 : NOR4 port map(A1 => net_10, A2 => net_15, A3 => net_41, A4 => net_13, Z => net_7);
	U9 : AND4 port map(A1 => net_17, A2 => net_26, A3 => net_36, A4 => net_16, Z => net_8);
	U10 : XOR3 port map(A1 => net_11, A2 => net_28, A3 => net_20, Z => net_9);
	U1 : NOT1 port map(A1 => net_42, Z => net_0);
	U2 : NOT1 port map(A1 => net_8, Z => net_1);
	U3 : NOT1 port map(A1 => net_5, Z => net_2);
	U4 : NAND3 port map(A1 => net_6, A2 => net_7, A3 => net_9, Z => net_3);
end struct;
