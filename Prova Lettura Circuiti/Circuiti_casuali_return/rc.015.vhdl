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
begin
	net_34 <= in0;
	net_35 <= in1;
	net_36 <= in2;
	net_37 <= in3;
	net_38 <= in4;
	net_39 <= in5;
	net_40 <= in6;
	out0 <= net_0;
	U42 : AND4 port map(A1 => net_37, A2 => net_37, A3 => net_40, A4 => net_37, Z => net_25);
	U43 : AND4 port map(A1 => net_36, A2 => net_37, A3 => net_39, A4 => net_37, Z => net_26);
	U45 : XOR2 port map(A1 => net_39, A2 => net_37, Z => net_27);
	U46 : AND4 port map(A1 => net_39, A2 => net_36, A3 => net_38, A4 => net_37, Z => net_28);
	U47 : AND4 port map(A1 => net_36, A2 => net_37, A3 => net_38, A4 => net_40, Z => net_29);
	U48 : XOR3 port map(A1 => net_35, A2 => net_37, A3 => net_38, Z => net_30);
	U49 : XNOR2 port map(A1 => net_34, A2 => net_40, Z => net_31);
	U50 : NOT1 port map(A1 => net_39, Z => net_32);
	U51 : AND3 port map(A1 => net_38, A2 => net_38, A3 => net_35, Z => net_33);
	U32 : NAND3 port map(A1 => net_33, A2 => net_37, A3 => net_30, Z => net_16);
	U33 : OR3 port map(A1 => net_32, A2 => net_39, A3 => net_35, Z => net_17);
	U34 : XOR2 port map(A1 => net_31, A2 => net_38, Z => net_18);
	U35 : NOR2 port map(A1 => net_26, A2 => net_27, Z => net_19);
	U36 : NOR3 port map(A1 => net_38, A2 => net_31, A3 => net_27, Z => net_20);
	U37 : NOT1 port map(A1 => net_40, Z => net_21);
	U38 : XNOR3 port map(A1 => net_30, A2 => net_32, A3 => net_37, Z => net_22);
	U40 : NOR2 port map(A1 => net_38, A2 => net_39, Z => net_23);
	U41 : NAND2 port map(A1 => net_35, A2 => net_25, Z => net_24);
	U22 : AND3 port map(A1 => net_17, A2 => net_19, A3 => net_18, Z => net_7);
	U23 : XNOR2 port map(A1 => net_36, A2 => net_23, Z => net_8);
	U24 : AND2 port map(A1 => net_22, A2 => net_24, Z => net_9);
	U25 : OR3 port map(A1 => net_23, A2 => net_36, A3 => net_26, Z => net_10);
	U26 : NOT1 port map(A1 => net_16, Z => net_11);
	U27 : OR3 port map(A1 => net_34, A2 => net_40, A3 => net_34, Z => net_12);
	U28 : NOR4 port map(A1 => net_28, A2 => net_29, A3 => net_29, A4 => net_33, Z => net_13);
	U30 : NAND2 port map(A1 => net_25, A2 => net_31, Z => net_14);
	U31 : XOR3 port map(A1 => net_20, A2 => net_22, A3 => net_18, Z => net_15);
	U12 : AND2 port map(A1 => net_14, A2 => net_18, Z => net_3);
	U13 : NOR4 port map(A1 => net_9, A2 => net_13, A3 => net_15, A4 => net_21, Z => net_4);
	U14 : AND3 port map(A1 => net_7, A2 => net_11, A3 => net_19, Z => net_5);
	U17 : XNOR3 port map(A1 => net_8, A2 => net_10, A3 => net_12, Z => net_6);
	U2 : AND3 port map(A1 => net_3, A2 => net_5, A3 => net_6, Z => net_1);
	U3 : NOT1 port map(A1 => net_4, Z => net_2);
	U1 : NAND2 port map(A1 => net_1, A2 => net_2, Z => net_0);
end struct;
