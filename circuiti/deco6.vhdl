library ieee;
use ieee.std_logic_1164.all;

----------------------------------------------------------------------
entity deco6 is
	port (
		input		: in  std_logic_vector(5 downto 0);
		output		: out std_logic_vector(0 to 63)
	);
end deco6;
----------------------------------------------------------------------

----------------------------------------------------------------------
architecture struct of deco6 is
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
	signal net_42		: std_logic;
	signal net_43		: std_logic;
	signal net_44		: std_logic;
	signal net_45		: std_logic;
	signal net_46		: std_logic;
	signal net_47		: std_logic;
	signal net_48		: std_logic;
	signal net_49		: std_logic;
	signal net_50		: std_logic;
	signal net_51		: std_logic;
	signal net_52		: std_logic;
	signal net_53		: std_logic;
	signal net_54		: std_logic;
	signal net_55		: std_logic;
	signal net_56		: std_logic;
	signal net_57		: std_logic;
	signal net_58		: std_logic;
	signal net_59		: std_logic;
	signal net_60		: std_logic;
	signal net_61		: std_logic;
	signal net_62		: std_logic;
	signal net_63		: std_logic;
	signal net_64		: std_logic;
	signal net_65		: std_logic;
	signal net_66		: std_logic;
	signal net_67		: std_logic;
	signal net_68		: std_logic;
	signal net_69		: std_logic;
	signal net_70		: std_logic;
	signal net_71		: std_logic;
	signal net_72		: std_logic;
	signal net_73		: std_logic;
	signal net_74		: std_logic;
	signal net_75		: std_logic;
	signal net_76		: std_logic;
	signal net_77		: std_logic;
	signal net_78		: std_logic;
	signal net_79		: std_logic;
	signal net_80		: std_logic;
	signal net_81		: std_logic;
	signal net_82		: std_logic;
	signal net_83		: std_logic;
	signal net_84		: std_logic;
	signal net_85		: std_logic;
	signal net_86		: std_logic;
	signal net_87		: std_logic;
	signal net_88		: std_logic;
	signal net_89		: std_logic;
	signal net_90		: std_logic;
	signal net_91		: std_logic;
	signal net_92		: std_logic;
	signal net_93		: std_logic;
	signal net_94		: std_logic;
	signal net_95		: std_logic;
	signal net_96		: std_logic;
	signal net_97		: std_logic;
	signal net_98		: std_logic;
	signal net_99		: std_logic;
	signal net_100		: std_logic;
	signal net_101		: std_logic;
	signal net_102		: std_logic;
	signal net_103		: std_logic;
	signal net_104		: std_logic;
	signal net_105		: std_logic;
	signal net_106		: std_logic;
	signal net_107		: std_logic;
	signal net_108		: std_logic;
	signal net_109		: std_logic;
	signal net_110		: std_logic;
	signal net_111		: std_logic;
	signal net_112		: std_logic;
	signal net_113		: std_logic;
	signal net_114		: std_logic;
	signal net_115		: std_logic;
	signal net_116		: std_logic;
	signal net_117		: std_logic;
	signal net_118		: std_logic;
	signal net_119		: std_logic;
	signal net_120		: std_logic;
	signal net_121		: std_logic;
	signal net_122		: std_logic;
	signal net_123		: std_logic;
	signal net_124		: std_logic;
	signal net_125		: std_logic;
	signal net_126		: std_logic;
	signal net_127		: std_logic;
	signal net_128		: std_logic;
	signal net_129		: std_logic;
	signal net_130		: std_logic;
	signal net_131		: std_logic;
	signal net_132		: std_logic;
	signal net_133		: std_logic;
	signal net_134		: std_logic;
	signal net_135		: std_logic;
	signal net_136		: std_logic;
	signal net_137		: std_logic;
	signal net_138		: std_logic;
	signal net_139		: std_logic;
	signal net_140		: std_logic;
	signal net_141		: std_logic;
	signal net_142		: std_logic;
	signal net_143		: std_logic;
	signal net_144		: std_logic;
	signal net_145		: std_logic;
	signal net_146		: std_logic;
	signal net_147		: std_logic;
	signal net_148		: std_logic;
	signal net_149		: std_logic;
	signal net_150		: std_logic;
	signal net_151		: std_logic;
	signal net_152		: std_logic;
	signal net_153		: std_logic;
	signal net_154		: std_logic;
	signal net_155		: std_logic;
	signal net_156		: std_logic;
	signal net_157		: std_logic;
	signal net_158		: std_logic;
	signal net_159		: std_logic;
	signal net_160		: std_logic;
	signal net_161		: std_logic;
	signal net_162		: std_logic;
	signal net_163		: std_logic;
	signal net_164		: std_logic;
	signal net_165		: std_logic;
	signal net_166		: std_logic;
	signal net_167		: std_logic;
begin
	net_0 <= input(0);
	net_1 <= input(1);
	net_2 <= input(2);
	net_3 <= input(3);
	net_4 <= input(4);
	net_5 <= input(5);
	I1 : INV port map (A => input(0), Z => net_6);
	I2 : INV port map (A => input(1), Z => net_7);
	I3 : INV port map (A => input(2), Z => net_8);
	I4 : INV port map (A => input(3), Z => net_9);
	I5 : INV port map (A => input(4), Z => net_10);
	I6 : INV port map (A => input(5), Z => net_11);

	U1 : NAND2 port map (A1 => net_11, A2 => net_10, Z => net_12);
	U2 : NAND2 port map (A1 => net_9, A2 => net_8, Z => net_13);
	U3 : NAND2 port map (A1 => net_7, A2 => net_6, Z => net_14);
	U4 : NOR2 port map (A1 => net_12, A2 => net_13, Z => net_15);
	U5 : NAND2 port map (A1 => net_15, A2 => net_14, Z => net_16);
	I7 : INV port map (A => net_16, Z => net_17);
	output(0) <= net_17;

	U6 : NAND2 port map (A1 => net_7, A2 => net_0, Z => net_18);
	U7 : NAND2 port map (A1 => net_15, A2 => net_18, Z => net_19);
	I8 : INV port map (A => net_19, Z => net_20);
	output(1) <= net_20;

	U8 : NAND2 port map (A1 => net_1, A2 => net_6, Z => net_21);
	U9 : NAND2 port map (A1 => net_15, A2 => net_21, Z => net_22);
	I9 : INV port map (A => net_22, Z => net_23);
	output(2) <= net_23;

	U10 : NAND2 port map (A1 => net_1, A2 => net_0, Z => net_24);
	U11 : NAND2 port map (A1 => net_15, A2 => net_24, Z => net_25);
	I10 : INV port map (A => net_25, Z => net_26);
	output(3) <= net_26;

	U12 : NAND2 port map (A1 => net_9, A2 => net_2, Z => net_27);
	U13 : NOR2 port map (A1 => net_12, A2 => net_27, Z => net_28);
	U14 : NAND2 port map (A1 => net_28, A2 => net_14, Z => net_29);
	I11 : INV port map (A => net_29, Z => net_30);
	output(4) <= net_30;

	U15 : NAND2 port map (A1 => net_28, A2 => net_18, Z => net_31);
	I12 : INV port map (A => net_31, Z => net_32);
	output(5) <= net_32;

	U16 : NAND2 port map (A1 => net_28, A2 => net_21, Z => net_33);
	I13 : INV port map (A => net_33, Z => net_34);
	output(6) <= net_34;

	U17 : NAND2 port map (A1 => net_28, A2 => net_24, Z => net_35);
	I14 : INV port map (A => net_35, Z => net_36);
	output(7) <= net_36;

	U18 : NAND2 port map (A1 => net_3, A2 => net_8, Z => net_37);
	U19 : NOR2 port map (A1 => net_12, A2 => net_37, Z => net_38);
	U20 : NAND2 port map (A1 => net_38, A2 => net_14, Z => net_39);
	I15 : INV port map (A => net_39, Z => net_40);
	output(8) <= net_40;

	U21 : NAND2 port map (A1 => net_38, A2 => net_18, Z => net_41);
	I16 : INV port map (A => net_41, Z => net_42);
	output(9) <= net_42;

	U22 : NAND2 port map (A1 => net_38, A2 => net_21, Z => net_43);
	I17 : INV port map (A => net_43, Z => net_44);
	output(10) <= net_44;

	U23 : NAND2 port map (A1 => net_38, A2 => net_24, Z => net_45);
	I18 : INV port map (A => net_45, Z => net_46);
	output(11) <= net_46;

	U24 : NAND2 port map (A1 => net_3, A2 => net_2, Z => net_47);
	U25 : NOR2 port map (A1 => net_12, A2 => net_47, Z => net_48);
	U26 : NAND2 port map (A1 => net_48, A2 => net_14, Z => net_49);
	I19 : INV port map (A => net_49, Z => net_50);
	output(12) <= net_50;

	U27 : NAND2 port map (A1 => net_48, A2 => net_18, Z => net_51);
	I20 : INV port map (A => net_51, Z => net_52);
	output(13) <= net_52;

	U28 : NAND2 port map (A1 => net_48, A2 => net_21, Z => net_53);
	I21 : INV port map (A => net_53, Z => net_54);
	output(14) <= net_54;

	U29 : NAND2 port map (A1 => net_48, A2 => net_24, Z => net_55);
	I22 : INV port map (A => net_55, Z => net_56);
	output(15) <= net_56;

	U30 : NAND2 port map (A1 => net_11, A2 => net_4, Z => net_57);
	U31 : NOR2 port map (A1 => net_57, A2 => net_13, Z => net_58);
	U32 : NAND2 port map (A1 => net_58, A2 => net_14, Z => net_59);
	I23 : INV port map (A => net_59, Z => net_60);
	output(16) <= net_60;

	U33 : NAND2 port map (A1 => net_58, A2 => net_18, Z => net_61);
	I24 : INV port map (A => net_61, Z => net_62);
	output(17) <= net_62;

	U34 : NAND2 port map (A1 => net_58, A2 => net_21, Z => net_63);
	I25 : INV port map (A => net_63, Z => net_64);
	output(18) <= net_64;

	U35 : NAND2 port map (A1 => net_58, A2 => net_24, Z => net_65);
	I26 : INV port map (A => net_65, Z => net_66);
	output(19) <= net_66;

	U36 : NOR2 port map (A1 => net_57, A2 => net_27, Z => net_67);
	U37 : NAND2 port map (A1 => net_67, A2 => net_14, Z => net_68);
	I27 : INV port map (A => net_68, Z => net_69);
	output(20) <= net_69;

	U38 : NAND2 port map (A1 => net_67, A2 => net_18, Z => net_70);
	I28 : INV port map (A => net_70, Z => net_71);
	output(21) <= net_71;

	U39 : NAND2 port map (A1 => net_67, A2 => net_21, Z => net_72);
	I29 : INV port map (A => net_72, Z => net_73);
	output(22) <= net_73;

	U40 : NAND2 port map (A1 => net_67, A2 => net_24, Z => net_74);
	I30 : INV port map (A => net_74, Z => net_75);
	output(23) <= net_75;

	U41 : NOR2 port map (A1 => net_57, A2 => net_37, Z => net_76);
	U42 : NAND2 port map (A1 => net_76, A2 => net_14, Z => net_77);
	I31 : INV port map (A => net_77, Z => net_78);
	output(24) <= net_78;

	U43 : NAND2 port map (A1 => net_76, A2 => net_18, Z => net_79);
	I32 : INV port map (A => net_79, Z => net_80);
	output(25) <= net_80;

	U44 : NAND2 port map (A1 => net_76, A2 => net_21, Z => net_81);
	I33 : INV port map (A => net_81, Z => net_82);
	output(26) <= net_82;

	U45 : NAND2 port map (A1 => net_76, A2 => net_24, Z => net_83);
	I34 : INV port map (A => net_83, Z => net_84);
	output(27) <= net_84;

	U46 : NOR2 port map (A1 => net_57, A2 => net_47, Z => net_85);
	U47 : NAND2 port map (A1 => net_85, A2 => net_14, Z => net_86);
	I35 : INV port map (A => net_86, Z => net_87);
	output(28) <= net_87;

	U48 : NAND2 port map (A1 => net_85, A2 => net_18, Z => net_88);
	I36 : INV port map (A => net_88, Z => net_89);
	output(29) <= net_89;

	U49 : NAND2 port map (A1 => net_85, A2 => net_21, Z => net_90);
	I37 : INV port map (A => net_90, Z => net_91);
	output(30) <= net_91;

	U50 : NAND2 port map (A1 => net_85, A2 => net_24, Z => net_92);
	I38 : INV port map (A => net_92, Z => net_93);
	output(31) <= net_93;

	U51 : NAND2 port map (A1 => net_5, A2 => net_10, Z => net_94);
	U52 : NOR2 port map (A1 => net_94, A2 => net_13, Z => net_95);
	U53 : NAND2 port map (A1 => net_95, A2 => net_14, Z => net_96);
	I39 : INV port map (A => net_96, Z => net_97);
	output(32) <= net_97;

	U54 : NAND2 port map (A1 => net_95, A2 => net_18, Z => net_98);
	I40 : INV port map (A => net_98, Z => net_99);
	output(33) <= net_99;

	U55 : NAND2 port map (A1 => net_95, A2 => net_21, Z => net_100);
	I41 : INV port map (A => net_100, Z => net_101);
	output(34) <= net_101;

	U56 : NAND2 port map (A1 => net_95, A2 => net_24, Z => net_102);
	I42 : INV port map (A => net_102, Z => net_103);
	output(35) <= net_103;

	U57 : NOR2 port map (A1 => net_94, A2 => net_27, Z => net_104);
	U58 : NAND2 port map (A1 => net_104, A2 => net_14, Z => net_105);
	I43 : INV port map (A => net_105, Z => net_106);
	output(36) <= net_106;

	U59 : NAND2 port map (A1 => net_104, A2 => net_18, Z => net_107);
	I44 : INV port map (A => net_107, Z => net_108);
	output(37) <= net_108;

	U60 : NAND2 port map (A1 => net_104, A2 => net_21, Z => net_109);
	I45 : INV port map (A => net_109, Z => net_110);
	output(38) <= net_110;

	U61 : NAND2 port map (A1 => net_104, A2 => net_24, Z => net_111);
	I46 : INV port map (A => net_111, Z => net_112);
	output(39) <= net_112;

	U62 : NOR2 port map (A1 => net_94, A2 => net_37, Z => net_113);
	U63 : NAND2 port map (A1 => net_113, A2 => net_14, Z => net_114);
	I47 : INV port map (A => net_114, Z => net_115);
	output(40) <= net_115;

	U64 : NAND2 port map (A1 => net_113, A2 => net_18, Z => net_116);
	I48 : INV port map (A => net_116, Z => net_117);
	output(41) <= net_117;

	U65 : NAND2 port map (A1 => net_113, A2 => net_21, Z => net_118);
	I49 : INV port map (A => net_118, Z => net_119);
	output(42) <= net_119;

	U66 : NAND2 port map (A1 => net_113, A2 => net_24, Z => net_120);
	I50 : INV port map (A => net_120, Z => net_121);
	output(43) <= net_121;

	U67 : NOR2 port map (A1 => net_94, A2 => net_47, Z => net_122);
	U68 : NAND2 port map (A1 => net_122, A2 => net_14, Z => net_123);
	I51 : INV port map (A => net_123, Z => net_124);
	output(44) <= net_124;

	U69 : NAND2 port map (A1 => net_122, A2 => net_18, Z => net_125);
	I52 : INV port map (A => net_125, Z => net_126);
	output(45) <= net_126;

	U70 : NAND2 port map (A1 => net_122, A2 => net_21, Z => net_127);
	I53 : INV port map (A => net_127, Z => net_128);
	output(46) <= net_128;

	U71 : NAND2 port map (A1 => net_122, A2 => net_24, Z => net_129);
	I54 : INV port map (A => net_129, Z => net_130);
	output(47) <= net_130;

	U72 : NAND2 port map (A1 => net_5, A2 => net_4, Z => net_131);
	U73 : NOR2 port map (A1 => net_131, A2 => net_13, Z => net_132);
	U74 : NAND2 port map (A1 => net_132, A2 => net_14, Z => net_133);
	I55 : INV port map (A => net_133, Z => net_134);
	output(48) <= net_134;

	U75 : NAND2 port map (A1 => net_132, A2 => net_18, Z => net_135);
	I56 : INV port map (A => net_135, Z => net_136);
	output(49) <= net_136;

	U76 : NAND2 port map (A1 => net_132, A2 => net_21, Z => net_137);
	I57 : INV port map (A => net_137, Z => net_138);
	output(50) <= net_138;

	U77 : NAND2 port map (A1 => net_132, A2 => net_24, Z => net_139);
	I58 : INV port map (A => net_139, Z => net_140);
	output(51) <= net_140;

	U78 : NOR2 port map (A1 => net_131, A2 => net_27, Z => net_141);
	U79 : NAND2 port map (A1 => net_141, A2 => net_14, Z => net_142);
	I59 : INV port map (A => net_142, Z => net_143);
	output(52) <= net_143;

	U80 : NAND2 port map (A1 => net_141, A2 => net_18, Z => net_144);
	I60 : INV port map (A => net_144, Z => net_145);
	output(53) <= net_145;

	U81 : NAND2 port map (A1 => net_141, A2 => net_21, Z => net_146);
	I61 : INV port map (A => net_146, Z => net_147);
	output(54) <= net_147;

	U82 : NAND2 port map (A1 => net_141, A2 => net_24, Z => net_148);
	I62 : INV port map (A => net_148, Z => net_149);
	output(55) <= net_149;

	U83 : NOR2 port map (A1 => net_131, A2 => net_37, Z => net_150);
	U84 : NAND2 port map (A1 => net_150, A2 => net_14, Z => net_151);
	I63 : INV port map (A => net_151, Z => net_152);
	output(56) <= net_152;

	U85 : NAND2 port map (A1 => net_150, A2 => net_18, Z => net_153);
	I64 : INV port map (A => net_153, Z => net_154);
	output(57) <= net_154;

	U86 : NAND2 port map (A1 => net_150, A2 => net_21, Z => net_155);
	I65 : INV port map (A => net_155, Z => net_156);
	output(58) <= net_156;

	U87 : NAND2 port map (A1 => net_150, A2 => net_24, Z => net_157);
	I66 : INV port map (A => net_157, Z => net_158);
	output(59) <= net_158;

	U88 : NOR2 port map (A1 => net_131, A2 => net_47, Z => net_159);
	U89 : NAND2 port map (A1 => net_159, A2 => net_14, Z => net_160);
	I67 : INV port map (A => net_160, Z => net_161);
	output(60) <= net_161;

	U90 : NAND2 port map (A1 => net_159, A2 => net_18, Z => net_162);
	I68 : INV port map (A => net_162, Z => net_163);
	output(61) <= net_163;

	U91 : NAND2 port map (A1 => net_159, A2 => net_21, Z => net_164);
	I69 : INV port map (A => net_164, Z => net_165);
	output(62) <= net_165;

	U92 : NAND2 port map (A1 => net_159, A2 => net_24, Z => net_166);
	I70 : INV port map (A => net_166, Z => net_167);
	output(63) <= net_167;
end struct;
----------------------------------------------------------------------