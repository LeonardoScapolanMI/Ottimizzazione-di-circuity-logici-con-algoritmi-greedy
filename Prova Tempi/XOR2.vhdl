----------------------------------------------------------------------
entity XOR2 is
	port (
		in0		: in  std_logic;
		in1		: in  std_logic;	
		out0		: out std_logic
	);
end XOR2;
----------------------------------------------------------------------

----------------------------------------------------------------------
architecture struct of XOR2 is
	signal net_0		: std_logic;
	signal net_1		: std_logic;
	signal net_2		: std_logic;
begin
	net_0 <= in0;
	net_1 <= in1;
	U1 : XOR2 port map(A1 => net_0, A2 => net_1, Z => net_2);
	out0 <= net_2;
end struct;
