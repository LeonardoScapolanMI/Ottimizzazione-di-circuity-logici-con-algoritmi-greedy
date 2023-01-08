----------------------------------------------------------------------
entity multiplier11 is
	port (
		a        : in  std_logic_vector(10 downto 0);
		b        : in  std_logic_vector(10 downto 0);
		res      : out std_logic_vector(21 downto 0)
	);
end multiplier11;
----------------------------------------------------------------------

----------------------------------------------------------------------
architecture struct of multiplier11 is
	signal p_0_0      :  std_logic;
	signal p_1_0      :  std_logic;
	signal p_2_0      :  std_logic;
	signal p_3_0      :  std_logic;
	signal p_4_0      :  std_logic;
	signal p_5_0      :  std_logic;
	signal p_6_0      :  std_logic;
	signal p_7_0      :  std_logic;
	signal p_8_0      :  std_logic;
	signal p_9_0      :  std_logic;
	signal p_10_0     :  std_logic;
	signal p_0_1      :  std_logic;
	signal p_1_1      :  std_logic;
	signal p_2_1      :  std_logic;
	signal p_3_1      :  std_logic;
	signal p_4_1      :  std_logic;
	signal p_5_1      :  std_logic;
	signal p_6_1      :  std_logic;
	signal p_7_1      :  std_logic;
	signal p_8_1      :  std_logic;
	signal p_9_1      :  std_logic;
	signal p_10_1     :  std_logic;
	signal p_0_2      :  std_logic;
	signal p_1_2      :  std_logic;
	signal p_2_2      :  std_logic;
	signal p_3_2      :  std_logic;
	signal p_4_2      :  std_logic;
	signal p_5_2      :  std_logic;
	signal p_6_2      :  std_logic;
	signal p_7_2      :  std_logic;
	signal p_8_2      :  std_logic;
	signal p_9_2      :  std_logic;
	signal p_10_2     :  std_logic;
	signal p_0_3      :  std_logic;
	signal p_1_3      :  std_logic;
	signal p_2_3      :  std_logic;
	signal p_3_3      :  std_logic;
	signal p_4_3      :  std_logic;
	signal p_5_3      :  std_logic;
	signal p_6_3      :  std_logic;
	signal p_7_3      :  std_logic;
	signal p_8_3      :  std_logic;
	signal p_9_3      :  std_logic;
	signal p_10_3     :  std_logic;
	signal p_0_4      :  std_logic;
	signal p_1_4      :  std_logic;
	signal p_2_4      :  std_logic;
	signal p_3_4      :  std_logic;
	signal p_4_4      :  std_logic;
	signal p_5_4      :  std_logic;
	signal p_6_4      :  std_logic;
	signal p_7_4      :  std_logic;
	signal p_8_4      :  std_logic;
	signal p_9_4      :  std_logic;
	signal p_10_4     :  std_logic;
	signal p_0_5      :  std_logic;
	signal p_1_5      :  std_logic;
	signal p_2_5      :  std_logic;
	signal p_3_5      :  std_logic;
	signal p_4_5      :  std_logic;
	signal p_5_5      :  std_logic;
	signal p_6_5      :  std_logic;
	signal p_7_5      :  std_logic;
	signal p_8_5      :  std_logic;
	signal p_9_5      :  std_logic;
	signal p_10_5     :  std_logic;
	signal p_0_6      :  std_logic;
	signal p_1_6      :  std_logic;
	signal p_2_6      :  std_logic;
	signal p_3_6      :  std_logic;
	signal p_4_6      :  std_logic;
	signal p_5_6      :  std_logic;
	signal p_6_6      :  std_logic;
	signal p_7_6      :  std_logic;
	signal p_8_6      :  std_logic;
	signal p_9_6      :  std_logic;
	signal p_10_6     :  std_logic;
	signal p_0_7      :  std_logic;
	signal p_1_7      :  std_logic;
	signal p_2_7      :  std_logic;
	signal p_3_7      :  std_logic;
	signal p_4_7      :  std_logic;
	signal p_5_7      :  std_logic;
	signal p_6_7      :  std_logic;
	signal p_7_7      :  std_logic;
	signal p_8_7      :  std_logic;
	signal p_9_7      :  std_logic;
	signal p_10_7     :  std_logic;
	signal p_0_8      :  std_logic;
	signal p_1_8      :  std_logic;
	signal p_2_8      :  std_logic;
	signal p_3_8      :  std_logic;
	signal p_4_8      :  std_logic;
	signal p_5_8      :  std_logic;
	signal p_6_8      :  std_logic;
	signal p_7_8      :  std_logic;
	signal p_8_8      :  std_logic;
	signal p_9_8      :  std_logic;
	signal p_10_8     :  std_logic;
	signal p_0_9      :  std_logic;
	signal p_1_9      :  std_logic;
	signal p_2_9      :  std_logic;
	signal p_3_9      :  std_logic;
	signal p_4_9      :  std_logic;
	signal p_5_9      :  std_logic;
	signal p_6_9      :  std_logic;
	signal p_7_9      :  std_logic;
	signal p_8_9      :  std_logic;
	signal p_9_9      :  std_logic;
	signal p_10_9     :  std_logic;
	signal p_0_10     :  std_logic;
	signal p_1_10     :  std_logic;
	signal p_2_10     :  std_logic;
	signal p_3_10     :  std_logic;
	signal p_4_10     :  std_logic;
	signal p_5_10     :  std_logic;
	signal p_6_10     :  std_logic;
	signal p_7_10     :  std_logic;
	signal p_8_10     :  std_logic;
	signal p_9_10     :  std_logic;
	signal p_10_10    :  std_logic_vector;
	signal adder_a    :  std_logic_vector;
	signal adder_b    :  std_logic_vector;
	signal adder_res  :  std_logic_vector;
	signal net_0      :  std_logic;
	signal net_1      :  std_logic;
	signal net_2      :  std_logic;
	signal net_3      :  std_logic;
	signal net_4      :  std_logic;
	signal net_5      :  std_logic;
	signal net_6      :  std_logic;
	signal net_7      :  std_logic;
	signal net_8      :  std_logic;
	signal net_9      :  std_logic;
	signal net_10     :  std_logic;
	signal net_11     :  std_logic;
	signal net_12     :  std_logic;
	signal net_13     :  std_logic;
	signal net_14     :  std_logic;
	signal net_15     :  std_logic;
	signal net_16     :  std_logic;
	signal net_17     :  std_logic;
	signal net_18     :  std_logic;
	signal net_19     :  std_logic;
	signal net_20     :  std_logic;
	signal net_21     :  std_logic;
	signal net_22     :  std_logic;
	signal net_23     :  std_logic;
	signal net_24     :  std_logic;
	signal net_25     :  std_logic;
	signal net_26     :  std_logic;
	signal net_27     :  std_logic;
	signal net_28     :  std_logic;
	signal net_29     :  std_logic;
	signal net_30     :  std_logic;
	signal net_31     :  std_logic;
	signal net_32     :  std_logic;
	signal net_33     :  std_logic;
	signal net_34     :  std_logic;
	signal net_35     :  std_logic;
	signal net_36     :  std_logic;
	signal net_37     :  std_logic;
	signal net_38     :  std_logic;
	signal net_39     :  std_logic;
	signal net_40     :  std_logic;
	signal net_41     :  std_logic;
	signal net_42     :  std_logic;
	signal net_43     :  std_logic;
	signal net_44     :  std_logic;
	signal net_45     :  std_logic;
	signal net_46     :  std_logic;
	signal net_47     :  std_logic;
	signal net_48     :  std_logic;
	signal net_49     :  std_logic;
	signal net_50     :  std_logic;
	signal net_51     :  std_logic;
	signal net_52     :  std_logic;
	signal net_53     :  std_logic;
	signal net_54     :  std_logic;
	signal net_55     :  std_logic;
	signal net_56     :  std_logic;
	signal net_57     :  std_logic;
	signal net_58     :  std_logic;
	signal net_59     :  std_logic;
	signal net_60     :  std_logic;
	signal net_61     :  std_logic;
	signal net_62     :  std_logic;
	signal net_63     :  std_logic;
	signal net_64     :  std_logic;
	signal net_65     :  std_logic;
	signal net_66     :  std_logic;
	signal net_67     :  std_logic;
	signal net_68     :  std_logic;
	signal net_69     :  std_logic;
	signal net_70     :  std_logic;
	signal net_71     :  std_logic;
	signal net_72     :  std_logic;
	signal net_73     :  std_logic;
	signal net_74     :  std_logic;
	signal net_75     :  std_logic;
	signal net_76     :  std_logic;
	signal net_77     :  std_logic;
	signal net_78     :  std_logic;
	signal net_79     :  std_logic;
	signal net_80     :  std_logic;
	signal net_81     :  std_logic;
	signal net_82     :  std_logic;
	signal net_83     :  std_logic;
	signal net_84     :  std_logic;
	signal net_85     :  std_logic;
	signal net_86     :  std_logic;
	signal net_87     :  std_logic;
	signal net_88     :  std_logic;
	signal net_89     :  std_logic;
	signal net_90     :  std_logic;
	signal net_91     :  std_logic;
	signal net_92     :  std_logic;
	signal net_93     :  std_logic;
	signal net_94     :  std_logic;
	signal net_95     :  std_logic;
	signal net_96     :  std_logic;
	signal net_97     :  std_logic;
	signal net_98     :  std_logic;
	signal net_99     :  std_logic;
	signal net_100    :  std_logic;
	signal net_101    :  std_logic;
	signal net_102    :  std_logic;
	signal net_103    :  std_logic;
	signal net_104    :  std_logic;
	signal net_105    :  std_logic;
	signal net_106    :  std_logic;
	signal net_107    :  std_logic;
	signal net_108    :  std_logic;
	signal net_109    :  std_logic;
	signal net_110    :  std_logic;
	signal net_111    :  std_logic;
	signal net_112    :  std_logic;
	signal net_113    :  std_logic;
	signal net_114    :  std_logic;
	signal net_115    :  std_logic;
	signal net_116    :  std_logic;
	signal net_117    :  std_logic;
	signal net_118    :  std_logic;
	signal net_119    :  std_logic;
	signal net_120    :  std_logic;
	signal net_121    :  std_logic;
	signal net_122    :  std_logic;
	signal net_123    :  std_logic;
	signal net_124    :  std_logic;
	signal net_125    :  std_logic;
	signal net_126    :  std_logic;
	signal net_127    :  std_logic;
	signal net_128    :  std_logic;
	signal net_129    :  std_logic;
	signal net_130    :  std_logic;
	signal net_131    :  std_logic;
	signal net_132    :  std_logic;
	signal net_133    :  std_logic;
	signal net_134    :  std_logic;
	signal net_135    :  std_logic;
	signal net_136    :  std_logic;
	signal net_137    :  std_logic;
	signal net_138    :  std_logic;
	signal net_139    :  std_logic;
	signal net_140    :  std_logic;
	signal net_141    :  std_logic;
	signal net_142    :  std_logic;
	signal net_143    :  std_logic;
	signal net_144    :  std_logic;
	signal net_145    :  std_logic;
	signal net_146    :  std_logic;
	signal net_147    :  std_logic;
	signal net_148    :  std_logic;
	signal net_149    :  std_logic;
	signal net_150    :  std_logic;
	signal net_151    :  std_logic;
	signal net_152    :  std_logic;
	signal net_153    :  std_logic;
	signal net_154    :  std_logic;
	signal net_155    :  std_logic;
	signal net_156    :  std_logic;
	signal net_157    :  std_logic;
	signal net_158    :  std_logic;
	signal net_159    :  std_logic;
	signal net_160    :  std_logic;
	signal net_161    :  std_logic;
	signal net_162    :  std_logic;
	signal net_163    :  std_logic;
	signal net_164    :  std_logic;
	signal net_165    :  std_logic;
	signal net_166    :  std_logic;
	signal net_167    :  std_logic;
	signal net_168    :  std_logic;
	signal net_169    :  std_logic;
	signal net_170    :  std_logic;
	signal net_171    :  std_logic;
	signal net_172    :  std_logic;
	signal net_173    :  std_logic;
	signal net_174    :  std_logic;
	signal net_175    :  std_logic;
	signal net_176    :  std_logic;
	signal net_177    :  std_logic;
	signal net_178    :  std_logic;
	signal net_179    :  std_logic;
	signal net_180    :  std_logic;
	signal net_181    :  std_logic;
	signal net_182    :  std_logic;
	signal net_183    :  std_logic;
	signal net_184    :  std_logic;
	signal net_185    :  std_logic;
	signal net_186    :  std_logic;
	signal net_187    :  std_logic;
	signal net_188    :  std_logic;
	signal net_189    :  std_logic;
	signal net_190    :  std_logic;
	signal net_191    :  std_logic;
	signal net_192    :  std_logic;
	signal net_193    :  std_logic;
	signal net_194    :  std_logic;
	signal net_195    :  std_logic;
	signal net_196    :  std_logic;
	signal net_197    :  std_logic;
	signal net_198    :  std_logic;
	signal net_199    :  std_logic;
	signal net_200    :  std_logic;
	signal net_201    :  std_logic;
	signal net_202    :  std_logic;
	signal net_203    :  std_logic;
	signal net_204    :  std_logic;
	signal net_205    :  std_logic;
	signal net_206    :  std_logic;
	signal net_207    :  std_logic;
	signal net_208    :  std_logic;
	signal net_209    :  std_logic;
	signal net_210    :  std_logic;
	signal net_211    :  std_logic;
	signal net_212    :  std_logic;
	signal net_213    :  std_logic;
	signal net_214    :  std_logic;
	signal net_215    :  std_logic;
	signal net_216    :  std_logic;
	signal net_217    :  std_logic;
	signal net_218    :  std_logic;
	signal net_219    :  std_logic;
	signal net_220    :  std_logic;
	signal net_221    :  std_logic;
	signal net_222    :  std_logic;
	signal net_223    :  std_logic;
	signal net_224    :  std_logic;
	signal net_225    :  std_logic;
	signal net_226    :  std_logic;
	signal net_227    :  std_logic;
	signal net_228    :  std_logic;
	signal net_229    :  std_logic;
	signal net_230    :  std_logic;
	signal net_231    :  std_logic;
	signal net_232    :  std_logic;
	signal net_233    :  std_logic;
	signal net_234    :  std_logic;
	signal net_235    :  std_logic;
	signal net_236    :  std_logic;
	signal net_237    :  std_logic;
	signal net_238    :  std_logic;
	signal net_239    :  std_logic;
	signal net_240    :  std_logic;
	signal net_241    :  std_logic;
	signal net_242    :  std_logic;
	signal net_243    :  std_logic;
	signal net_244    :  std_logic;
	signal net_245    :  std_logic;
	signal net_246    :  std_logic;
	signal net_247    :  std_logic;
	signal net_248    :  std_logic;
	signal net_249    :  std_logic;
begin
	res(0) <= p_0_0;
	res(1) <= net_0;
	res(2) <= net_80;
	res(3) <= net_138;
	res(4) <= net_182;
	res(5) <= net_217;
	adder_a <= net_248;
	adder_a <= net_246;
	adder_a <= net_244;
	adder_a <= net_242;
	adder_a <= net_240;
	adder_a <= net_238;
	adder_a <= net_236;
	adder_a <= net_234;
	adder_a <= net_232;
	adder_a <= net_230;
	adder_a <= net_228;
	adder_a <= net_226;
	adder_a <= net_224;
	adder_a <= net_222;
	adder_a <= net_220;
	adder_a <= net_218;
	adder_b <= net_249;
	adder_b <= net_247;
	adder_b <= net_245;
	adder_b <= net_243;
	adder_b <= net_241;
	adder_b <= net_239;
	adder_b <= net_237;
	adder_b <= net_235;
	adder_b <= net_233;
	adder_b <= net_231;
	adder_b <= net_229;
	adder_b <= net_227;
	adder_b <= net_225;
	adder_b <= net_223;
	adder_b <= net_221;
	adder_b <= net_219;
	res(21 downto 6) <= adder_res;
	gate_implicito : AND2 port map(in0 => a(0), in1 => b(0), out0 => p_0_0);
	gate_implicito : AND2 port map(in0 => a(1), in1 => b(0), out0 => p_1_0);
	gate_implicito : AND2 port map(in0 => a(2), in1 => b(0), out0 => p_2_0);
	gate_implicito : AND2 port map(in0 => a(3), in1 => b(0), out0 => p_3_0);
	gate_implicito : AND2 port map(in0 => a(4), in1 => b(0), out0 => p_4_0);
	gate_implicito : AND2 port map(in0 => a(5), in1 => b(0), out0 => p_5_0);
	gate_implicito : AND2 port map(in0 => a(6), in1 => b(0), out0 => p_6_0);
	gate_implicito : AND2 port map(in0 => a(7), in1 => b(0), out0 => p_7_0);
	gate_implicito : AND2 port map(in0 => a(8), in1 => b(0), out0 => p_8_0);
	gate_implicito : AND2 port map(in0 => a(9), in1 => b(0), out0 => p_9_0);
	gate_implicito : AND2 port map(in0 => a(10), in1 => b(0), out0 => p_10_0);
	gate_implicito : AND2 port map(in0 => a(0), in1 => b(1), out0 => p_0_1);
	gate_implicito : AND2 port map(in0 => a(1), in1 => b(1), out0 => p_1_1);
	gate_implicito : AND2 port map(in0 => a(2), in1 => b(1), out0 => p_2_1);
	gate_implicito : AND2 port map(in0 => a(3), in1 => b(1), out0 => p_3_1);
	gate_implicito : AND2 port map(in0 => a(4), in1 => b(1), out0 => p_4_1);
	gate_implicito : AND2 port map(in0 => a(5), in1 => b(1), out0 => p_5_1);
	gate_implicito : AND2 port map(in0 => a(6), in1 => b(1), out0 => p_6_1);
	gate_implicito : AND2 port map(in0 => a(7), in1 => b(1), out0 => p_7_1);
	gate_implicito : AND2 port map(in0 => a(8), in1 => b(1), out0 => p_8_1);
	gate_implicito : AND2 port map(in0 => a(9), in1 => b(1), out0 => p_9_1);
	gate_implicito : AND2 port map(in0 => a(10), in1 => b(1), out0 => p_10_1);
	gate_implicito : AND2 port map(in0 => a(0), in1 => b(2), out0 => p_0_2);
	gate_implicito : AND2 port map(in0 => a(1), in1 => b(2), out0 => p_1_2);
	gate_implicito : AND2 port map(in0 => a(2), in1 => b(2), out0 => p_2_2);
	gate_implicito : AND2 port map(in0 => a(3), in1 => b(2), out0 => p_3_2);
	gate_implicito : AND2 port map(in0 => a(4), in1 => b(2), out0 => p_4_2);
	gate_implicito : AND2 port map(in0 => a(5), in1 => b(2), out0 => p_5_2);
	gate_implicito : AND2 port map(in0 => a(6), in1 => b(2), out0 => p_6_2);
	gate_implicito : AND2 port map(in0 => a(7), in1 => b(2), out0 => p_7_2);
	gate_implicito : AND2 port map(in0 => a(8), in1 => b(2), out0 => p_8_2);
	gate_implicito : AND2 port map(in0 => a(9), in1 => b(2), out0 => p_9_2);
	gate_implicito : AND2 port map(in0 => a(10), in1 => b(2), out0 => p_10_2);
	gate_implicito : AND2 port map(in0 => a(0), in1 => b(3), out0 => p_0_3);
	gate_implicito : AND2 port map(in0 => a(1), in1 => b(3), out0 => p_1_3);
	gate_implicito : AND2 port map(in0 => a(2), in1 => b(3), out0 => p_2_3);
	gate_implicito : AND2 port map(in0 => a(3), in1 => b(3), out0 => p_3_3);
	gate_implicito : AND2 port map(in0 => a(4), in1 => b(3), out0 => p_4_3);
	gate_implicito : AND2 port map(in0 => a(5), in1 => b(3), out0 => p_5_3);
	gate_implicito : AND2 port map(in0 => a(6), in1 => b(3), out0 => p_6_3);
	gate_implicito : AND2 port map(in0 => a(7), in1 => b(3), out0 => p_7_3);
	gate_implicito : AND2 port map(in0 => a(8), in1 => b(3), out0 => p_8_3);
	gate_implicito : AND2 port map(in0 => a(9), in1 => b(3), out0 => p_9_3);
	gate_implicito : AND2 port map(in0 => a(10), in1 => b(3), out0 => p_10_3);
	gate_implicito : AND2 port map(in0 => a(0), in1 => b(4), out0 => p_0_4);
	gate_implicito : AND2 port map(in0 => a(1), in1 => b(4), out0 => p_1_4);
	gate_implicito : AND2 port map(in0 => a(2), in1 => b(4), out0 => p_2_4);
	gate_implicito : AND2 port map(in0 => a(3), in1 => b(4), out0 => p_3_4);
	gate_implicito : AND2 port map(in0 => a(4), in1 => b(4), out0 => p_4_4);
	gate_implicito : AND2 port map(in0 => a(5), in1 => b(4), out0 => p_5_4);
	gate_implicito : AND2 port map(in0 => a(6), in1 => b(4), out0 => p_6_4);
	gate_implicito : AND2 port map(in0 => a(7), in1 => b(4), out0 => p_7_4);
	gate_implicito : AND2 port map(in0 => a(8), in1 => b(4), out0 => p_8_4);
	gate_implicito : AND2 port map(in0 => a(9), in1 => b(4), out0 => p_9_4);
	gate_implicito : AND2 port map(in0 => a(10), in1 => b(4), out0 => p_10_4);
	gate_implicito : AND2 port map(in0 => a(0), in1 => b(5), out0 => p_0_5);
	gate_implicito : AND2 port map(in0 => a(1), in1 => b(5), out0 => p_1_5);
	gate_implicito : AND2 port map(in0 => a(2), in1 => b(5), out0 => p_2_5);
	gate_implicito : AND2 port map(in0 => a(3), in1 => b(5), out0 => p_3_5);
	gate_implicito : AND2 port map(in0 => a(4), in1 => b(5), out0 => p_4_5);
	gate_implicito : AND2 port map(in0 => a(5), in1 => b(5), out0 => p_5_5);
	gate_implicito : AND2 port map(in0 => a(6), in1 => b(5), out0 => p_6_5);
	gate_implicito : AND2 port map(in0 => a(7), in1 => b(5), out0 => p_7_5);
	gate_implicito : AND2 port map(in0 => a(8), in1 => b(5), out0 => p_8_5);
	gate_implicito : AND2 port map(in0 => a(9), in1 => b(5), out0 => p_9_5);
	gate_implicito : AND2 port map(in0 => a(10), in1 => b(5), out0 => p_10_5);
	gate_implicito : AND2 port map(in0 => a(0), in1 => b(6), out0 => p_0_6);
	gate_implicito : AND2 port map(in0 => a(1), in1 => b(6), out0 => p_1_6);
	gate_implicito : AND2 port map(in0 => a(2), in1 => b(6), out0 => p_2_6);
	gate_implicito : AND2 port map(in0 => a(3), in1 => b(6), out0 => p_3_6);
	gate_implicito : AND2 port map(in0 => a(4), in1 => b(6), out0 => p_4_6);
	gate_implicito : AND2 port map(in0 => a(5), in1 => b(6), out0 => p_5_6);
	gate_implicito : AND2 port map(in0 => a(6), in1 => b(6), out0 => p_6_6);
	gate_implicito : AND2 port map(in0 => a(7), in1 => b(6), out0 => p_7_6);
	gate_implicito : AND2 port map(in0 => a(8), in1 => b(6), out0 => p_8_6);
	gate_implicito : AND2 port map(in0 => a(9), in1 => b(6), out0 => p_9_6);
	gate_implicito : AND2 port map(in0 => a(10), in1 => b(6), out0 => p_10_6);
	gate_implicito : AND2 port map(in0 => a(0), in1 => b(7), out0 => p_0_7);
	gate_implicito : AND2 port map(in0 => a(1), in1 => b(7), out0 => p_1_7);
	gate_implicito : AND2 port map(in0 => a(2), in1 => b(7), out0 => p_2_7);
	gate_implicito : AND2 port map(in0 => a(3), in1 => b(7), out0 => p_3_7);
	gate_implicito : AND2 port map(in0 => a(4), in1 => b(7), out0 => p_4_7);
	gate_implicito : AND2 port map(in0 => a(5), in1 => b(7), out0 => p_5_7);
	gate_implicito : AND2 port map(in0 => a(6), in1 => b(7), out0 => p_6_7);
	gate_implicito : AND2 port map(in0 => a(7), in1 => b(7), out0 => p_7_7);
	gate_implicito : AND2 port map(in0 => a(8), in1 => b(7), out0 => p_8_7);
	gate_implicito : AND2 port map(in0 => a(9), in1 => b(7), out0 => p_9_7);
	gate_implicito : AND2 port map(in0 => a(10), in1 => b(7), out0 => p_10_7);
	gate_implicito : AND2 port map(in0 => a(0), in1 => b(8), out0 => p_0_8);
	gate_implicito : AND2 port map(in0 => a(1), in1 => b(8), out0 => p_1_8);
	gate_implicito : AND2 port map(in0 => a(2), in1 => b(8), out0 => p_2_8);
	gate_implicito : AND2 port map(in0 => a(3), in1 => b(8), out0 => p_3_8);
	gate_implicito : AND2 port map(in0 => a(4), in1 => b(8), out0 => p_4_8);
	gate_implicito : AND2 port map(in0 => a(5), in1 => b(8), out0 => p_5_8);
	gate_implicito : AND2 port map(in0 => a(6), in1 => b(8), out0 => p_6_8);
	gate_implicito : AND2 port map(in0 => a(7), in1 => b(8), out0 => p_7_8);
	gate_implicito : AND2 port map(in0 => a(8), in1 => b(8), out0 => p_8_8);
	gate_implicito : AND2 port map(in0 => a(9), in1 => b(8), out0 => p_9_8);
	gate_implicito : AND2 port map(in0 => a(10), in1 => b(8), out0 => p_10_8);
	gate_implicito : AND2 port map(in0 => a(0), in1 => b(9), out0 => p_0_9);
	gate_implicito : AND2 port map(in0 => a(1), in1 => b(9), out0 => p_1_9);
	gate_implicito : AND2 port map(in0 => a(2), in1 => b(9), out0 => p_2_9);
	gate_implicito : AND2 port map(in0 => a(3), in1 => b(9), out0 => p_3_9);
	gate_implicito : AND2 port map(in0 => a(4), in1 => b(9), out0 => p_4_9);
	gate_implicito : AND2 port map(in0 => a(5), in1 => b(9), out0 => p_5_9);
	gate_implicito : AND2 port map(in0 => a(6), in1 => b(9), out0 => p_6_9);
	gate_implicito : AND2 port map(in0 => a(7), in1 => b(9), out0 => p_7_9);
	gate_implicito : AND2 port map(in0 => a(8), in1 => b(9), out0 => p_8_9);
	gate_implicito : AND2 port map(in0 => a(9), in1 => b(9), out0 => p_9_9);
	gate_implicito : AND2 port map(in0 => a(10), in1 => b(9), out0 => p_10_9);
	gate_implicito : AND2 port map(in0 => a(0), in1 => b(10), out0 => p_0_10);
	gate_implicito : AND2 port map(in0 => a(1), in1 => b(10), out0 => p_1_10);
	gate_implicito : AND2 port map(in0 => a(2), in1 => b(10), out0 => p_2_10);
	gate_implicito : AND2 port map(in0 => a(3), in1 => b(10), out0 => p_3_10);
	gate_implicito : AND2 port map(in0 => a(4), in1 => b(10), out0 => p_4_10);
	gate_implicito : AND2 port map(in0 => a(5), in1 => b(10), out0 => p_5_10);
	gate_implicito : AND2 port map(in0 => a(6), in1 => b(10), out0 => p_6_10);
	gate_implicito : AND2 port map(in0 => a(7), in1 => b(10), out0 => p_7_10);
	gate_implicito : AND2 port map(in0 => a(8), in1 => b(10), out0 => p_8_10);
	gate_implicito : AND2 port map(in0 => a(9), in1 => b(10), out0 => p_9_10);
	gate_implicito : AND2 port map(in0 => a(10), in1 => b(10), out0 => p_10_10);
	ha_0 : HA port map(A => p_1_0, B => p_0_1, S => net_0, COUT => net_1);
	fa_0 : FA port map(A => p_2_0, B => p_1_1, CIN => p_0_2, S => net_2, COUT => net_3);
	fa_1 : FA port map(A => p_3_0, B => p_2_1, CIN => p_1_2, S => net_4, COUT => net_5);
	fa_2 : FA port map(A => p_4_0, B => p_3_1, CIN => p_2_2, S => net_6, COUT => net_7);
	ha_1 : HA port map(A => p_1_3, B => p_0_4, S => net_8, COUT => net_9);
	fa_3 : FA port map(A => p_5_0, B => p_4_1, CIN => p_3_2, S => net_10, COUT => net_11);
	fa_4 : FA port map(A => p_2_3, B => p_1_4, CIN => p_0_5, S => net_12, COUT => net_13);
	fa_5 : FA port map(A => p_6_0, B => p_5_1, CIN => p_4_2, S => net_14, COUT => net_15);
	fa_6 : FA port map(A => p_3_3, B => p_2_4, CIN => p_1_5, S => net_16, COUT => net_17);
	fa_7 : FA port map(A => p_7_0, B => p_6_1, CIN => p_5_2, S => net_18, COUT => net_19);
	fa_8 : FA port map(A => p_4_3, B => p_3_4, CIN => p_2_5, S => net_20, COUT => net_21);
	ha_2 : HA port map(A => p_1_6, B => p_0_7, S => net_22, COUT => net_23);
	fa_9 : FA port map(A => p_8_0, B => p_7_1, CIN => p_6_2, S => net_24, COUT => net_25);
	fa_10 : FA port map(A => p_5_3, B => p_4_4, CIN => p_3_5, S => net_26, COUT => net_27);
	fa_11 : FA port map(A => p_2_6, B => p_1_7, CIN => p_0_8, S => net_28, COUT => net_29);
	fa_12 : FA port map(A => p_9_0, B => p_8_1, CIN => p_7_2, S => net_30, COUT => net_31);
	fa_13 : FA port map(A => p_6_3, B => p_5_4, CIN => p_4_5, S => net_32, COUT => net_33);
	fa_14 : FA port map(A => p_3_6, B => p_2_7, CIN => p_1_8, S => net_34, COUT => net_35);
	fa_15 : FA port map(A => p_10_0, B => p_9_1, CIN => p_8_2, S => net_36, COUT => net_37);
	fa_16 : FA port map(A => p_7_3, B => p_6_4, CIN => p_5_5, S => net_38, COUT => net_39);
	fa_17 : FA port map(A => p_4_6, B => p_3_7, CIN => p_2_8, S => net_40, COUT => net_41);
	ha_3 : HA port map(A => p_1_9, B => p_0_10, S => net_42, COUT => net_43);
	fa_18 : FA port map(A => p_10_1, B => p_9_2, CIN => p_8_3, S => net_44, COUT => net_45);
	fa_19 : FA port map(A => p_7_4, B => p_6_5, CIN => p_5_6, S => net_46, COUT => net_47);
	fa_20 : FA port map(A => p_4_7, B => p_3_8, CIN => p_2_9, S => net_48, COUT => net_49);
	fa_21 : FA port map(A => p_10_2, B => p_9_3, CIN => p_8_4, S => net_50, COUT => net_51);
	fa_22 : FA port map(A => p_7_5, B => p_6_6, CIN => p_5_7, S => net_52, COUT => net_53);
	fa_23 : FA port map(A => p_4_8, B => p_3_9, CIN => p_2_10, S => net_54, COUT => net_55);
	fa_24 : FA port map(A => p_10_3, B => p_9_4, CIN => p_8_5, S => net_56, COUT => net_57);
	fa_25 : FA port map(A => p_7_6, B => p_6_7, CIN => p_5_8, S => net_58, COUT => net_59);
	ha_4 : HA port map(A => p_4_9, B => p_3_10, S => net_60, COUT => net_61);
	fa_26 : FA port map(A => p_10_4, B => p_9_5, CIN => p_8_6, S => net_62, COUT => net_63);
	fa_27 : FA port map(A => p_7_7, B => p_6_8, CIN => p_5_9, S => net_64, COUT => net_65);
	fa_28 : FA port map(A => p_10_5, B => p_9_6, CIN => p_8_7, S => net_66, COUT => net_67);
	fa_29 : FA port map(A => p_7_8, B => p_6_9, CIN => p_5_10, S => net_68, COUT => net_69);
	fa_30 : FA port map(A => p_10_6, B => p_9_7, CIN => p_8_8, S => net_70, COUT => net_71);
	ha_5 : HA port map(A => p_7_9, B => p_6_10, S => net_72, COUT => net_73);
	fa_31 : FA port map(A => p_10_7, B => p_9_8, CIN => p_8_9, S => net_74, COUT => net_75);
	fa_32 : FA port map(A => p_10_8, B => p_9_9, CIN => p_8_10, S => net_76, COUT => net_77);
	ha_6 : HA port map(A => p_10_9, B => p_9_10, S => net_78, COUT => net_79);
	ha_7 : HA port map(A => net_1, B => net_2, S => net_80, COUT => net_81);
	fa_33 : FA port map(A => net_3, B => net_4, CIN => p_0_3, S => net_82, COUT => net_83);
	fa_34 : FA port map(A => net_5, B => net_6, CIN => net_8, S => net_84, COUT => net_85);
	fa_35 : FA port map(A => net_7, B => net_9, CIN => net_10, S => net_86, COUT => net_87);
	fa_36 : FA port map(A => net_11, B => net_13, CIN => net_14, S => net_88, COUT => net_89);
	ha_8 : HA port map(A => net_16, B => p_0_6, S => net_90, COUT => net_91);
	fa_37 : FA port map(A => net_15, B => net_17, CIN => net_18, S => net_92, COUT => net_93);
	ha_9 : HA port map(A => net_20, B => net_22, S => net_94, COUT => net_95);
	fa_38 : FA port map(A => net_19, B => net_21, CIN => net_23, S => net_96, COUT => net_97);
	fa_39 : FA port map(A => net_24, B => net_26, CIN => net_28, S => net_98, COUT => net_99);
	fa_40 : FA port map(A => net_25, B => net_27, CIN => net_29, S => net_100, COUT => net_101);
	fa_41 : FA port map(A => net_30, B => net_32, CIN => net_34, S => net_102, COUT => net_103);
	fa_42 : FA port map(A => net_31, B => net_33, CIN => net_35, S => net_104, COUT => net_105);
	fa_43 : FA port map(A => net_36, B => net_38, CIN => net_40, S => net_106, COUT => net_107);
	fa_44 : FA port map(A => net_37, B => net_39, CIN => net_41, S => net_108, COUT => net_109);
	fa_45 : FA port map(A => net_43, B => net_44, CIN => net_46, S => net_110, COUT => net_111);
	ha_10 : HA port map(A => net_48, B => p_1_10, S => net_112, COUT => net_113);
	fa_46 : FA port map(A => net_45, B => net_47, CIN => net_49, S => net_114, COUT => net_115);
	fa_47 : FA port map(A => net_50, B => net_52, CIN => net_54, S => net_116, COUT => net_117);
	fa_48 : FA port map(A => net_51, B => net_53, CIN => net_55, S => net_118, COUT => net_119);
	fa_49 : FA port map(A => net_56, B => net_58, CIN => net_60, S => net_120, COUT => net_121);
	fa_50 : FA port map(A => net_57, B => net_59, CIN => net_61, S => net_122, COUT => net_123);
	fa_51 : FA port map(A => net_62, B => net_64, CIN => p_4_10, S => net_124, COUT => net_125);
	fa_52 : FA port map(A => net_63, B => net_65, CIN => net_66, S => net_126, COUT => net_127);
	fa_53 : FA port map(A => net_67, B => net_69, CIN => net_70, S => net_128, COUT => net_129);
	fa_54 : FA port map(A => net_71, B => net_73, CIN => net_74, S => net_130, COUT => net_131);
	ha_11 : HA port map(A => net_75, B => net_76, S => net_132, COUT => net_133);
	ha_12 : HA port map(A => net_77, B => net_78, S => net_134, COUT => net_135);
	ha_13 : HA port map(A => net_79, B => p_10_10, S => net_136, COUT => net_137);
	ha_14 : HA port map(A => net_81, B => net_82, S => net_138, COUT => net_139);
	ha_15 : HA port map(A => net_83, B => net_84, S => net_140, COUT => net_141);
	fa_55 : FA port map(A => net_85, B => net_86, CIN => net_12, S => net_142, COUT => net_143);
	fa_56 : FA port map(A => net_87, B => net_88, CIN => net_90, S => net_144, COUT => net_145);
	fa_57 : FA port map(A => net_89, B => net_91, CIN => net_92, S => net_146, COUT => net_147);
	fa_58 : FA port map(A => net_93, B => net_95, CIN => net_96, S => net_148, COUT => net_149);
	fa_59 : FA port map(A => net_97, B => net_99, CIN => net_100, S => net_150, COUT => net_151);
	ha_16 : HA port map(A => net_102, B => p_0_9, S => net_152, COUT => net_153);
	fa_60 : FA port map(A => net_101, B => net_103, CIN => net_104, S => net_154, COUT => net_155);
	ha_17 : HA port map(A => net_106, B => net_42, S => net_156, COUT => net_157);
	fa_61 : FA port map(A => net_105, B => net_107, CIN => net_108, S => net_158, COUT => net_159);
	ha_18 : HA port map(A => net_110, B => net_112, S => net_160, COUT => net_161);
	fa_62 : FA port map(A => net_109, B => net_111, CIN => net_113, S => net_162, COUT => net_163);
	ha_19 : HA port map(A => net_114, B => net_116, S => net_164, COUT => net_165);
	fa_63 : FA port map(A => net_115, B => net_117, CIN => net_118, S => net_166, COUT => net_167);
	fa_64 : FA port map(A => net_119, B => net_121, CIN => net_122, S => net_168, COUT => net_169);
	fa_65 : FA port map(A => net_123, B => net_125, CIN => net_126, S => net_170, COUT => net_171);
	fa_66 : FA port map(A => net_127, B => net_128, CIN => net_72, S => net_172, COUT => net_173);
	fa_67 : FA port map(A => net_129, B => net_130, CIN => p_7_10, S => net_174, COUT => net_175);
	ha_20 : HA port map(A => net_131, B => net_132, S => net_176, COUT => net_177);
	ha_21 : HA port map(A => net_133, B => net_134, S => net_178, COUT => net_179);
	ha_22 : HA port map(A => net_135, B => net_136, S => net_180, COUT => net_181);
	ha_23 : HA port map(A => net_139, B => net_140, S => net_182, COUT => net_183);
	ha_24 : HA port map(A => net_141, B => net_142, S => net_184, COUT => net_185);
	ha_25 : HA port map(A => net_143, B => net_144, S => net_186, COUT => net_187);
	fa_68 : FA port map(A => net_145, B => net_146, CIN => net_94, S => net_188, COUT => net_189);
	fa_69 : FA port map(A => net_147, B => net_148, CIN => net_98, S => net_190, COUT => net_191);
	fa_70 : FA port map(A => net_149, B => net_150, CIN => net_152, S => net_192, COUT => net_193);
	fa_71 : FA port map(A => net_151, B => net_153, CIN => net_154, S => net_194, COUT => net_195);
	fa_72 : FA port map(A => net_155, B => net_157, CIN => net_158, S => net_196, COUT => net_197);
	fa_73 : FA port map(A => net_159, B => net_161, CIN => net_162, S => net_198, COUT => net_199);
	fa_74 : FA port map(A => net_163, B => net_165, CIN => net_166, S => net_200, COUT => net_201);
	fa_75 : FA port map(A => net_167, B => net_168, CIN => net_124, S => net_202, COUT => net_203);
	fa_76 : FA port map(A => net_169, B => net_170, CIN => net_68, S => net_204, COUT => net_205);
	ha_26 : HA port map(A => net_171, B => net_172, S => net_206, COUT => net_207);
	ha_27 : HA port map(A => net_173, B => net_174, S => net_208, COUT => net_209);
	ha_28 : HA port map(A => net_175, B => net_176, S => net_210, COUT => net_211);
	ha_29 : HA port map(A => net_177, B => net_178, S => net_212, COUT => net_213);
	ha_30 : HA port map(A => net_179, B => net_180, S => net_214, COUT => net_215);
	gate_implicito : XOR2 port map(in0 => net_181, in1 => net_137, out0 => net_216);
	ha_32 : HA port map(A => net_183, B => net_184, S => net_217, COUT => net_218);
	ha_33 : HA port map(A => net_185, B => net_186, S => net_219, COUT => net_220);
	ha_34 : HA port map(A => net_187, B => net_188, S => net_221, COUT => net_222);
	ha_35 : HA port map(A => net_189, B => net_190, S => net_223, COUT => net_224);
	ha_36 : HA port map(A => net_191, B => net_192, S => net_225, COUT => net_226);
	fa_77 : FA port map(A => net_193, B => net_194, CIN => net_156, S => net_227, COUT => net_228);
	fa_78 : FA port map(A => net_195, B => net_196, CIN => net_160, S => net_229, COUT => net_230);
	fa_79 : FA port map(A => net_197, B => net_198, CIN => net_164, S => net_231, COUT => net_232);
	fa_80 : FA port map(A => net_199, B => net_200, CIN => net_120, S => net_233, COUT => net_234);
	ha_37 : HA port map(A => net_201, B => net_202, S => net_235, COUT => net_236);
	ha_38 : HA port map(A => net_203, B => net_204, S => net_237, COUT => net_238);
	ha_39 : HA port map(A => net_205, B => net_206, S => net_239, COUT => net_240);
	ha_40 : HA port map(A => net_207, B => net_208, S => net_241, COUT => net_242);
	ha_41 : HA port map(A => net_209, B => net_210, S => net_243, COUT => net_244);
	ha_42 : HA port map(A => net_211, B => net_212, S => net_245, COUT => net_246);
	ha_43 : HA port map(A => net_213, B => net_214, S => net_247, COUT => net_248);
	gate_implicito : XOR2 port map(in0 => net_215, in1 => net_216, out0 => net_249);
	MADD : adder16 port map(a => adder_a, b => adder_b, c_in => 'SEGNALE COSTANTE', sum => adder_res);
end struct;
----------------------------------------------------------------------
