----------------------------------------------------------------------
entity andorxor is
	port (
		in0		: in  std_logic;
		in1		: in  std_logic;
		in2		: in  std_logic;
		in3		: in  std_logic;
		out0		: out std_logic
	);
end andorxor;
----------------------------------------------------------------------

----------------------------------------------------------------------
architecture struct of andorxor is
	signal net_0		: std_logic;
	signal net_1		: std_logic;
	signal net_2		: std_logic;
	signal net_3		: std_logic;
	signal net_4		: std_logic;
	signal net_5		: std_logic;
	signal net_6		: std_logic;
begin
	net_0 <= in0;
	net_1 <= in1;
	net_2 <= in2;
	net_3 <= in3;
	U1 : AND2 port map(A1 => net_0, A2 => net_1, Z => net_4);
	U2 : OR2 port map(A1 => net_2, A2 => net_3, Z => net_5);
	U3 : XOR2 port map(A1 => net_4, A2 => net_5, Z => net_6);
	out0 <= net_6;
end struct;
