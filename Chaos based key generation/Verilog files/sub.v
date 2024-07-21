module subb(in1,
           in2,
           out);
  input   [31:0] in1;  // ufix32
  input   [31:0] in2;  // ufix32
  output  [31:0] out;  // ufix32


  wire AS;  // ufix1
  wire [7:0] AE;  // ufix8
  wire [22:0] AM;  // ufix23
  wire BS;  // ufix1
  wire [7:0] BE;  // ufix8
  wire [22:0] BM;  // ufix23
  wire Relational_Operator1_relop1;
  wire Relational_Operator_relop1;
  wire bitconcat_aExponent_aMantissa_relop1;
  wire Logical_Operator_out1;  // ufix1
  wire Logical_Operator1_out1;  // ufix1
  wire [7:0] if_bitconcat_aExponent_aMantiss_out1;  // ufix8
  wire aExponent_cfType_Exponent_I_out1;  // ufix1
  wire Exponent_0_out1;  // ufix1
  wire [7:0] C_out1;  // ufix8
  wire [7:0] if_Exponent_0_out1;  // ufix8
  wire exp_norm_cfType_Exponent_In_out1;  // ufix1
  wire alphaExponent_0_cfType_Exp_out1;  // ufix1
  wire [2:0] alpha1_out1;  // ufix3
  wire [2:0] alpha0_out1;  // ufix3
  wire [2:0] if_Exponent_0_cfType_Exp_out1;  // ufix3
  wire [22:0] if_bitconcat_aExponent_aMantiss_1_out1;  // ufix23
  wire [25:0] Bit_Concat_out1;  // ufix26
  wire [1:0] alpha0_1_out1;  // ufix2
  wire [27:0] Bit_Concat1_out1;  // ufix28
  wire signed [27:0] Data_Type_Conversion_out1;  // sfix28
  wire Logical_Operator_out1_1;  // ufix1
  wire if_bitconcat_aExponent_aMantiss_2_out1;  // ufix1
  wire if_bitconcat_aExponent_aMantiss_5_out1;  // ufix1
  wire bitxor_out1;  // ufix1
  wire [7:0] if_bitconcat_aExponent_aMantiss_3_out1;  // ufix8
  wire exp_b_cfType_Exponent_Inf_o_out1;  // ufix1
  wire Exponent_0_out1_1;  // ufix1
  wire alphaExponent_0_cfType_Exp_out1_1;  // ufix1
  wire [2:0] alpha1_out1_1;  // ufix3
  wire [2:0] alpha0_out1_1;  // ufix3
  wire [2:0] if_Exponent_0_cfType_Exp_out1_1;  // ufix3
  wire [22:0] if_bitconcat_aExponent_aMantiss_4_out1;  // ufix23
  wire [25:0] Bit_Concat_out1_1;  // ufix26
  wire [1:0] alpha0_1_out1_1;  // ufix2
  wire [27:0] Bit_Concat1_out1_1;  // ufix28
  wire signed [27:0] Data_Type_Conversion_out1_1;  // sfix28
  wire signed [28:0] alphamant_b_ext_in0;  // sfix29
  wire signed [28:0] alphamant_b_ext_1;  // sfix29
  wire signed [27:0] alphamant_b_ext_out1;  // sfix28
  wire signed [27:0] if_opp_Sign_out1;  // sfix28
  wire [7:0] C_out1_1;  // ufix8
  wire [7:0] if_Exponent_0_out1_1;  // ufix8
  wire signed [31:0] storedInteger_exp_a_cor_sto_1;  // sfix32
  wire signed [31:0] storedInteger_exp_a_cor_sto_2;  // sfix32
  wire signed [31:0] storedInteger_exp_a_cor_sto_out1;  // int32
  wire [2:0] Bit_Slice2_out1;  // ufix3
  wire Compare_To_Zero_out1;  // ufix1
  wire [4:0] Constant_out1;  // ufix5
  wire [4:0] Bit_Slice_out1;  // ufix5
  wire [4:0] if_opp_Sign_1_out1;  // ufix5
  wire [7:0] dynamic_shift_1;  // uint8
  wire signed [27:0] bitsra_mant_b_ext_shift_lengt_out1;  // sfix28
  wire signed [31:0] mant_a_ext_mant_b_shifted_add_temp;  // sfix32
  wire signed [31:0] mant_a_ext_mant_b_shifted_1;  // sfix32
  wire signed [31:0] mant_a_ext_mant_b_shifted_2;  // sfix32
  wire [26:0] mant_a_ext_mant_b_shifted_out1;  // ufix27
  wire BitSlice_out1;  // ufix1
  wire Logical_Operator_out1_2;  // ufix1
  wire [25:0] BitSlice3_out1;  // ufix26
  wire Bit_Slice5_out1;  // ufix1
  wire Bit_Slice3_out1;  // ufix1
  wire Logical_Operator1_out1_1;  // ufix1
  wire [7:0] Bit_Slice2_out1_1;  // ufix8
  wire Bit_Slice16_out1;  // ufix1
  wire Bit_Slice15_out1;  // ufix1
  wire Logical_Operator5_out1;  // ufix1
  wire Bit_Slice14_out1;  // ufix1
  wire Bit_Slice13_out1;  // ufix1
  wire Logical_Operator7_out1;  // ufix1
  wire Logical_Operator6_out1;  // ufix1
  wire Bit_Slice12_out1;  // ufix1
  wire Bit_Slice11_out1;  // ufix1
  wire Logical_Operator4_out1;  // ufix1
  wire Bit_Slice10_out1;  // ufix1
  wire Bit_Slice9_out1;  // ufix1
  wire Logical_Operator14_out1;  // ufix1
  wire Logical_Operator13_out1;  // ufix1
  wire Logical_Operator12_out1;  // ufix1
  wire [7:0] Bit_Slice1_out1;  // ufix8
  wire Bit_Slice16_out1_1;  // ufix1
  wire Bit_Slice15_out1_1;  // ufix1
  wire Logical_Operator5_out1_1;  // ufix1
  wire Bit_Slice14_out1_1;  // ufix1
  wire Bit_Slice13_out1_1;  // ufix1
  wire Logical_Operator7_out1_1;  // ufix1
  wire Logical_Operator6_out1_1;  // ufix1
  wire Bit_Slice12_out1_1;  // ufix1
  wire Bit_Slice11_out1_1;  // ufix1
  wire Logical_Operator4_out1_1;  // ufix1
  wire Bit_Slice10_out1_1;  // ufix1
  wire Bit_Slice9_out1_1;  // ufix1
  wire Logical_Operator14_out1_1;  // ufix1
  wire Logical_Operator13_out1_1;  // ufix1
  wire [7:0] Bit_Slice4_out1;  // ufix8
  wire Bit_Slice8_out1;  // ufix1
  wire Bit_Slice7_out1;  // ufix1
  wire Logical_Operator1_out1_2;  // ufix1
  wire Bit_Slice6_out1;  // ufix1
  wire Bit_Slice5_out1_1;  // ufix1
  wire Logical_Operator3_out1;  // ufix1
  wire Bit_Slice3_out1_1;  // ufix1
  wire Bit_Slice2_out1_2;  // ufix1
  wire Bit_Slice1_out1_1;  // ufix1
  wire Bit_Slice_out1_1;  // ufix1
  wire [4:0] Constant_out1_1;  // ufix5
  wire [4:0] Constant1_out1;  // ufix5
  wire [4:0] Switch_out1;  // ufix5
  wire Logical_Operator_out1_3;  // ufix1
  wire [4:0] Constant2_out1;  // ufix5
  wire [4:0] Switch1_out1;  // ufix5
  wire [4:0] Constant3_out1;  // ufix5
  wire [4:0] Switch2_out1;  // ufix5
  wire [4:0] Constant4_out1;  // ufix5
  wire Logical_Operator2_out1;  // ufix1
  wire [4:0] Switch3_out1;  // ufix5
  wire [4:0] Switch4_out1;  // ufix5
  wire [4:0] Constant5_out1;  // ufix5
  wire [4:0] Switch5_out1;  // ufix5
  wire [4:0] Constant6_out1;  // ufix5
  wire [4:0] Switch6_out1;  // ufix5
  wire [4:0] Constant7_out1;  // ufix5
  wire [4:0] Switch7_out1;  // ufix5
  wire [4:0] Constant8_out1;  // ufix5
  wire [4:0] Switch8_out1;  // ufix5
  wire Logical_Operator12_out1_1;  // ufix1
  wire [4:0] Switch9_out1;  // ufix5
  wire [4:0] Switch10_out1;  // ufix5
  wire [4:0] Constant9_out1;  // ufix5
  wire [4:0] Switch11_out1;  // ufix5
  wire [4:0] Constant10_out1;  // ufix5
  wire [4:0] Switch12_out1;  // ufix5
  wire [4:0] Constant11_out1;  // ufix5
  wire [4:0] Switch14_out1;  // ufix5
  wire [4:0] Constant12_out1;  // ufix5
  wire [4:0] Switch15_out1;  // ufix5
  wire [4:0] Switch16_out1;  // ufix5
  wire [4:0] Constant13_out1;  // ufix5
  wire [4:0] Switch17_out1;  // ufix5
  wire [4:0] Constant14_out1;  // ufix5
  wire [4:0] Switch18_out1;  // ufix5
  wire [4:0] Constant15_out1;  // ufix5
  wire [4:0] Switch19_out1;  // ufix5
  wire [4:0] Constant16_out1;  // ufix5
  wire [4:0] Switch20_out1;  // ufix5
  wire [4:0] Switch21_out1;  // ufix5
  wire Logical_Operator_out1_4;  // ufix1
  wire [4:0] Switch13_out1;  // ufix5
  wire [4:0] Switch33_out1;  // ufix5
  wire [4:0] Constant9_out1_1;  // ufix5
  wire [4:0] Switch11_out1_1;  // ufix5
  wire [4:0] Constant10_out1_1;  // ufix5
  wire [4:0] Switch12_out1_1;  // ufix5
  wire [4:0] Constant11_out1_1;  // ufix5
  wire [4:0] Switch14_out1_1;  // ufix5
  wire [4:0] Constant12_out1_1;  // ufix5
  wire [4:0] Switch15_out1_1;  // ufix5
  wire [4:0] Switch16_out1_1;  // ufix5
  wire [4:0] Constant13_out1_1;  // ufix5
  wire [4:0] Switch17_out1_1;  // ufix5
  wire [4:0] Constant14_out1_1;  // ufix5
  wire [4:0] Switch18_out1_1;  // ufix5
  wire [4:0] Constant15_out1_1;  // ufix5
  wire [4:0] Switch19_out1_1;  // ufix5
  wire [4:0] Constant16_out1_1;  // ufix5
  wire [4:0] Switch20_out1_1;  // ufix5
  wire [4:0] Switch21_out1_1;  // ufix5
  wire [4:0] Switch13_out1_1;  // ufix5
  wire [4:0] Constant1_out1_1;  // ufix5
  wire [4:0] Switch3_out1_1;  // ufix5
  wire [4:0] Constant2_out1_1;  // ufix5
  wire [4:0] Switch2_out1_1;  // ufix5
  wire [4:0] Switch1_out1_1;  // ufix5
  wire [4:0] Switch34_out1;  // ufix5
  wire [4:0] Bit_Slice_out1_2;  // ufix5
  wire shift_length_exp_a_cor_relop1;
  wire [2:0] Bit_Slice1_out1_2;  // ufix3
  wire Compare_To_Zero_out1_1;  // ufix1
  wire Logical_Operator1_out1_3;  // ufix1
  wire [7:0] C1_out1;  // ufix8
  wire [4:0] exp_a_cor_1_sub_cast;  // ufix5
  wire [4:0] exp_a_cor_1_out1;  // ufix5
  wire [4:0] if_shift_length_exp_a_cor_1_out1;  // ufix5
  wire [7:0] dynamic_shift_3;  // uint8
  wire [26:0] bitsll_Sum_shift_length_out1;  // ufix27
  wire [26:0] bitsrl_Sum_1_out1;  // ufix27
  wire [26:0] if_bitget_Sum_Sum_WordLength_out1;  // ufix27
  wire [26:0] C5_out1;  // ufix27
  wire [26:0] if_exp_norm_cfType_Exponent_I_out1;  // ufix27
  wire [23:0] BitSlice6_out1;  // ufix24
  wire BitSlice5_out1;  // ufix1
  wire Bit_Slice13_out1_2;  // ufix1
  wire Bit_Slice12_out1_2;  // ufix1
  wire Bit_Slice10_out1_2;  // ufix1
  wire Bit_Slice11_out1_2;  // ufix1
  wire Bit_Slice14_out1_2;  // ufix1
  wire [2:0] Bit_Slice7_out1_1;  // ufix3
  wire Constant1_out1_2;  // ufix1
  wire [3:0] Bit_Concat_out1_2;  // ufix4
  wire Bit_Slice_out1_3;  // ufix1
  wire Bit_Slice1_out1_3;  // ufix1
  wire Logical_Operator_out1_5;  // ufix1
  wire Switch6_out1_1;  // ufix1
  wire Bit_Slice2_out1_3;  // ufix1
  wire Logical_Operator1_out1_4;  // ufix1
  wire Bit_Slice3_out1_2;  // ufix1
  wire Logical_Operator2_out1_1;  // ufix1
  wire Switch7_out1_1;  // ufix1
  wire Switch3_out1_2;  // ufix1
  wire [3:0] Bit_Slice8_out1_1;  // ufix4
  wire Bit_Slice_out1_4;  // ufix1
  wire Logical_Operator3_out1_1;  // ufix1
  wire Bit_Slice1_out1_4;  // ufix1
  wire Logical_Operator_out1_6;  // ufix1
  wire Switch6_out1_2;  // ufix1
  wire Bit_Slice2_out1_4;  // ufix1
  wire Logical_Operator1_out1_5;  // ufix1
  wire Bit_Slice3_out1_3;  // ufix1
  wire Logical_Operator2_out1_2;  // ufix1
  wire Switch7_out1_2;  // ufix1
  wire Switch3_out1_3;  // ufix1
  wire Switch6_out1_3;  // ufix1
  wire [3:0] Bit_Slice9_out1_2;  // ufix4
  wire Bit_Slice_out1_5;  // ufix1
  wire Logical_Operator3_out1_2;  // ufix1
  wire Bit_Slice1_out1_5;  // ufix1
  wire Logical_Operator_out1_7;  // ufix1
  wire Switch6_out1_4;  // ufix1
  wire Bit_Slice2_out1_5;  // ufix1
  wire Logical_Operator1_out1_6;  // ufix1
  wire Bit_Slice3_out1_4;  // ufix1
  wire Logical_Operator2_out1_3;  // ufix1
  wire Switch7_out1_3;  // ufix1
  wire Switch3_out1_4;  // ufix1
  wire [3:0] Bit_Slice3_out1_5;  // ufix4
  wire Bit_Slice_out1_6;  // ufix1
  wire Logical_Operator3_out1_3;  // ufix1
  wire Bit_Slice1_out1_6;  // ufix1
  wire Logical_Operator_out1_8;  // ufix1
  wire Switch6_out1_5;  // ufix1
  wire Bit_Slice2_out1_6;  // ufix1
  wire Logical_Operator1_out1_7;  // ufix1
  wire Bit_Slice3_out1_6;  // ufix1
  wire Logical_Operator2_out1_4;  // ufix1
  wire Switch7_out1_4;  // ufix1
  wire Switch3_out1_5;  // ufix1
  wire Switch7_out1_5;  // ufix1
  wire Switch3_out1_6;  // ufix1
  wire [3:0] Bit_Slice4_out1_1;  // ufix4
  wire Bit_Slice_out1_7;  // ufix1
  wire Logical_Operator3_out1_4;  // ufix1
  wire Bit_Slice1_out1_7;  // ufix1
  wire Logical_Operator_out1_9;  // ufix1
  wire Switch6_out1_6;  // ufix1
  wire Bit_Slice2_out1_7;  // ufix1
  wire Logical_Operator1_out1_8;  // ufix1
  wire Bit_Slice3_out1_7;  // ufix1
  wire Logical_Operator2_out1_5;  // ufix1
  wire Switch7_out1_6;  // ufix1
  wire Switch3_out1_7;  // ufix1
  wire [3:0] Bit_Slice5_out1_2;  // ufix4
  wire Bit_Slice_out1_8;  // ufix1
  wire Logical_Operator3_out1_5;  // ufix1
  wire Bit_Slice1_out1_8;  // ufix1
  wire Logical_Operator_out1_10;  // ufix1
  wire Switch6_out1_7;  // ufix1
  wire Bit_Slice2_out1_8;  // ufix1
  wire Logical_Operator1_out1_9;  // ufix1
  wire Bit_Slice3_out1_8;  // ufix1
  wire Logical_Operator2_out1_6;  // ufix1
  wire Switch7_out1_7;  // ufix1
  wire Switch3_out1_8;  // ufix1
  wire Switch6_out1_8;  // ufix1
  wire [3:0] Bit_Slice6_out1_1;  // ufix4
  wire Bit_Slice_out1_9;  // ufix1
  wire Logical_Operator3_out1_6;  // ufix1
  wire Bit_Slice1_out1_9;  // ufix1
  wire Logical_Operator_out1_11;  // ufix1
  wire Switch6_out1_9;  // ufix1
  wire Bit_Slice2_out1_9;  // ufix1
  wire Logical_Operator1_out1_10;  // ufix1
  wire Bit_Slice3_out1_9;  // ufix1
  wire Logical_Operator2_out1_7;  // ufix1
  wire Switch7_out1_8;  // ufix1
  wire Switch3_out1_9;  // ufix1
  wire Bit_Slice1_out1_10;  // ufix1
  wire Logical_Operator_out1_12;  // ufix1
  wire Logical_Operator1_out1_11;  // ufix1
  wire Switch7_out1_9;  // ufix1
  wire Switch3_out1_10;  // ufix1
  wire Switch2_out1_2;  // ufix1
  wire BitSlice1_out1;  // ufix1
  wire sticky_bitget_Sum_1_out1;  // ufix1
  wire BitSlice_out1_1;  // ufix1
  wire BitSlice1_out1_1;  // ufix1
  wire if_bitget_Sum_Sum_WordLength_2_out1;  // ufix1
  wire sticky_bitget_Sum_1_out1_1;  // ufix1
  wire alphabitget_Mant_tmp_2_0_out1;  // ufix1
  wire alphabitget_Mant_tmp_1_0_out1;  // ufix1
  wire alpha0_out1_2;  // ufix1
  wire [22:0] BitSlice4_out1;  // ufix23
  wire [23:0] Bit_Concat_out1_3;  // ufix24
  wire [23:0] cast_2_like_Mant_tmp_out1;  // ufix24
  wire [23:0] Mant_tmp_cast_2_like_Man_out1;  // ufix24
  wire [23:0] if_bitget_Mant_tmp_1_0_out1;  // ufix24
  wire BitSlice2_out1;  // ufix1
  wire BitSlice4_out1_1;  // ufix1
  wire [7:0] C4_out1;  // ufix8
  wire Sum_0_out1;  // ufix1
  wire [7:0] exp_a_cor_shift_length_1;  // ufix8
  wire [7:0] exp_a_cor_shift_length_out1;  // ufix8
  wire [7:0] C2_out1;  // ufix8
  wire [7:0] if_shift_length_exp_a_cor_out1;  // ufix8
  wire BitSlice2_out1_1;  // ufix1
  wire [7:0] C3_out1;  // ufix8
  wire [7:0] if_Sum_0_out1;  // ufix8
  wire [7:0] if_bitget_Sum_Sum_WordLength_1_out1;  // ufix8
  wire [7:0] C_out1_2;  // ufix8
  wire [7:0] exp_a_cor_1_out1_1;  // ufix8
  wire [7:0] if_bitget_Sum_Sum_WordLength_1_out1_1;  // ufix8
  wire [7:0] if_bitget_Sum_Sum_WordLength_out1_1;  // ufix8
  wire [7:0] cast_1_like_Exp_out1;  // ufix8
  wire [7:0] Exp_cast_1_like_Exp_out1;  // ufix8
  wire [7:0] if_bitget_Mant_tmp_Mant_tmp_Wor_out1;  // ufix8
  wire Exponent_0_out1_2;  // ufix1
  wire [22:0] BitSlice3_out1_1;  // ufix23
  wire Mantissa_0_out1;  // ufix1
  wire alphaExponent_0_Mantissa_out1;  // ufix1
  wire Constant_out1_2;  // ufix1
  wire Switch_out1_1;  // ufix1
  wire alphaaSign_1_bSign_1_out1;  // ufix1
  wire if_Exponent_0_Mantissa_out1;  // ufix1
  wire [7:0] if_aExponent_cfType_Exponent_out1;  // ufix8
  wire opp_signs_exp_b_cfType_out1;  // ufix1
  wire mant_a_0_out1;  // ufix1
  wire alphamant_a_0_opp_signs_out1;  // ufix1
  wire [22:0] BitSet_out1;  // ufix23
  wire [22:0] if_mant_a_0_opp_signs_out1;  // ufix23
  wire [22:0] if_aExponent_cfType_Exponent_1_out1;  // ufix23
  wire [31:0] out_pack;  // ufix32


  // Split 32 bit word into FP sign, exponent, mantissa
  assign AS = in1[31];
  assign AE = in1[30:23];
  assign AM = in1[22:0];



  // Split 32 bit word into FP sign, exponent, mantissa
  assign BS = in2[31];
  assign BE = in2[30:23];
  assign BM = in2[22:0];



  assign Relational_Operator1_relop1 = AE == BE;



  assign Relational_Operator_relop1 = AE > BE;



  assign bitconcat_aExponent_aMantissa_relop1 = AM >= BM;



  assign Logical_Operator_out1 = Relational_Operator1_relop1 & bitconcat_aExponent_aMantissa_relop1;



  assign Logical_Operator1_out1 = Relational_Operator_relop1 | Logical_Operator_out1;



  assign if_bitconcat_aExponent_aMantiss_out1 = (Logical_Operator1_out1 == 1'b0 ? BE :
              AE);



  assign aExponent_cfType_Exponent_I_out1 = if_bitconcat_aExponent_aMantiss_out1 == 8'b11111111;



  assign Exponent_0_out1 = if_bitconcat_aExponent_aMantiss_out1 == 8'b00000000;



  assign C_out1 = 8'b00000001;



  assign if_Exponent_0_out1 = (Exponent_0_out1 == 1'b0 ? if_bitconcat_aExponent_aMantiss_out1 :
              C_out1);



  assign exp_norm_cfType_Exponent_In_out1 = if_Exponent_0_out1 == 8'b11111110;



  assign alphaExponent_0_cfType_Exp_out1 = aExponent_cfType_Exponent_I_out1 | Exponent_0_out1;



  assign alpha1_out1 = 3'b001;



  assign alpha0_out1 = 3'b000;



  assign if_Exponent_0_cfType_Exp_out1 = (alphaExponent_0_cfType_Exp_out1 == 1'b0 ? alpha1_out1 :
              alpha0_out1);



  assign if_bitconcat_aExponent_aMantiss_1_out1 = (Logical_Operator1_out1 == 1'b0 ? BM :
              AM);



  assign Bit_Concat_out1 = {if_Exponent_0_cfType_Exp_out1, if_bitconcat_aExponent_aMantiss_1_out1};



  assign alpha0_1_out1 = 2'b00;



  assign Bit_Concat1_out1 = {Bit_Concat_out1, alpha0_1_out1};



  assign Data_Type_Conversion_out1 = Bit_Concat1_out1;



  assign Logical_Operator_out1_1 =  ~ BS;



  assign if_bitconcat_aExponent_aMantiss_2_out1 = (Logical_Operator1_out1 == 1'b0 ? Logical_Operator_out1_1 :
              AS);



  assign if_bitconcat_aExponent_aMantiss_5_out1 = (Logical_Operator1_out1 == 1'b0 ? AS :
              Logical_Operator_out1_1);



  assign bitxor_out1 = if_bitconcat_aExponent_aMantiss_2_out1 ^ if_bitconcat_aExponent_aMantiss_5_out1;



  assign if_bitconcat_aExponent_aMantiss_3_out1 = (Logical_Operator1_out1 == 1'b0 ? AE :
              BE);



  assign exp_b_cfType_Exponent_Inf_o_out1 = if_bitconcat_aExponent_aMantiss_3_out1 == 8'b11111111;



  assign Exponent_0_out1_1 = if_bitconcat_aExponent_aMantiss_3_out1 == 8'b00000000;



  assign alphaExponent_0_cfType_Exp_out1_1 = exp_b_cfType_Exponent_Inf_o_out1 | Exponent_0_out1_1;



  assign alpha1_out1_1 = 3'b001;



  assign alpha0_out1_1 = 3'b000;



  assign if_Exponent_0_cfType_Exp_out1_1 = (alphaExponent_0_cfType_Exp_out1_1 == 1'b0 ? alpha1_out1_1 :
              alpha0_out1_1);



  assign if_bitconcat_aExponent_aMantiss_4_out1 = (Logical_Operator1_out1 == 1'b0 ? AM :
              BM);



  assign Bit_Concat_out1_1 = {if_Exponent_0_cfType_Exp_out1_1, if_bitconcat_aExponent_aMantiss_4_out1};



  assign alpha0_1_out1_1 = 2'b00;



  assign Bit_Concat1_out1_1 = {Bit_Concat_out1_1, alpha0_1_out1_1};



  assign Data_Type_Conversion_out1_1 = Bit_Concat1_out1_1;



  assign alphamant_b_ext_1 = {Data_Type_Conversion_out1_1[27], Data_Type_Conversion_out1_1};
  assign alphamant_b_ext_in0 =  - (alphamant_b_ext_1);
  assign alphamant_b_ext_out1 = alphamant_b_ext_in0[27:0];



  assign if_opp_Sign_out1 = (bitxor_out1 == 1'b0 ? Data_Type_Conversion_out1_1 :
              alphamant_b_ext_out1);



  assign C_out1_1 = 8'b00000001;



  assign if_Exponent_0_out1_1 = (Exponent_0_out1_1 == 1'b0 ? if_bitconcat_aExponent_aMantiss_3_out1 :
              C_out1_1);



  assign storedInteger_exp_a_cor_sto_1 = {24'b0, if_Exponent_0_out1};
  assign storedInteger_exp_a_cor_sto_2 = {24'b0, if_Exponent_0_out1_1};
  assign storedInteger_exp_a_cor_sto_out1 = storedInteger_exp_a_cor_sto_1 - storedInteger_exp_a_cor_sto_2;



  assign Bit_Slice2_out1 = storedInteger_exp_a_cor_sto_out1[7:5];



  assign Compare_To_Zero_out1 = Bit_Slice2_out1 == 3'b000;



  assign Constant_out1 = 5'b11111;



  assign Bit_Slice_out1 = storedInteger_exp_a_cor_sto_out1[4:0];



  assign if_opp_Sign_1_out1 = (Compare_To_Zero_out1 == 1'b0 ? Constant_out1 :
              Bit_Slice_out1);



  assign dynamic_shift_1 = {3'b0, if_opp_Sign_1_out1};
  assign bitsra_mant_b_ext_shift_lengt_out1 = if_opp_Sign_out1 >>> dynamic_shift_1;



  assign mant_a_ext_mant_b_shifted_1 = {{4{Data_Type_Conversion_out1[27]}}, Data_Type_Conversion_out1};
  assign mant_a_ext_mant_b_shifted_2 = {{4{bitsra_mant_b_ext_shift_lengt_out1[27]}}, bitsra_mant_b_ext_shift_lengt_out1};
  assign mant_a_ext_mant_b_shifted_add_temp = mant_a_ext_mant_b_shifted_1 + mant_a_ext_mant_b_shifted_2;
  assign mant_a_ext_mant_b_shifted_out1 = mant_a_ext_mant_b_shifted_add_temp[26:0];



  assign BitSlice_out1 = mant_a_ext_mant_b_shifted_out1[26];



  assign Logical_Operator_out1_2 = exp_norm_cfType_Exponent_In_out1 & BitSlice_out1;



  assign BitSlice3_out1 = mant_a_ext_mant_b_shifted_out1[25:0];



  assign Bit_Slice5_out1 = BitSlice3_out1[25];



  assign Bit_Slice3_out1 = BitSlice3_out1[24];



  assign Logical_Operator1_out1_1 = Bit_Slice5_out1 | Bit_Slice3_out1;



  assign Bit_Slice2_out1_1 = BitSlice3_out1[23:16];



  assign Bit_Slice16_out1 = Bit_Slice2_out1_1[7];



  assign Bit_Slice15_out1 = Bit_Slice2_out1_1[6];



  assign Logical_Operator5_out1 = Bit_Slice16_out1 | Bit_Slice15_out1;



  assign Bit_Slice14_out1 = Bit_Slice2_out1_1[5];



  assign Bit_Slice13_out1 = Bit_Slice2_out1_1[4];



  assign Logical_Operator7_out1 = Bit_Slice14_out1 | Bit_Slice13_out1;



  assign Logical_Operator6_out1 = Logical_Operator5_out1 | Logical_Operator7_out1;



  assign Bit_Slice12_out1 = Bit_Slice2_out1_1[3];



  assign Bit_Slice11_out1 = Bit_Slice2_out1_1[2];



  assign Logical_Operator4_out1 = Bit_Slice12_out1 | Bit_Slice11_out1;



  assign Bit_Slice10_out1 = Bit_Slice2_out1_1[1];



  assign Bit_Slice9_out1 = Bit_Slice2_out1_1[0];



  assign Logical_Operator14_out1 = Bit_Slice10_out1 | Bit_Slice9_out1;



  assign Logical_Operator13_out1 = Logical_Operator4_out1 | Logical_Operator14_out1;



  assign Logical_Operator12_out1 = Logical_Operator6_out1 | Logical_Operator13_out1;



  assign Bit_Slice1_out1 = BitSlice3_out1[15:8];



  assign Bit_Slice16_out1_1 = Bit_Slice1_out1[7];



  assign Bit_Slice15_out1_1 = Bit_Slice1_out1[6];



  assign Logical_Operator5_out1_1 = Bit_Slice16_out1_1 | Bit_Slice15_out1_1;



  assign Bit_Slice14_out1_1 = Bit_Slice1_out1[5];



  assign Bit_Slice13_out1_1 = Bit_Slice1_out1[4];



  assign Logical_Operator7_out1_1 = Bit_Slice14_out1_1 | Bit_Slice13_out1_1;



  assign Logical_Operator6_out1_1 = Logical_Operator5_out1_1 | Logical_Operator7_out1_1;



  assign Bit_Slice12_out1_1 = Bit_Slice1_out1[3];



  assign Bit_Slice11_out1_1 = Bit_Slice1_out1[2];



  assign Logical_Operator4_out1_1 = Bit_Slice12_out1_1 | Bit_Slice11_out1_1;



  assign Bit_Slice10_out1_1 = Bit_Slice1_out1[1];



  assign Bit_Slice9_out1_1 = Bit_Slice1_out1[0];



  assign Logical_Operator14_out1_1 = Bit_Slice10_out1_1 | Bit_Slice9_out1_1;



  assign Logical_Operator13_out1_1 = Logical_Operator4_out1_1 | Logical_Operator14_out1_1;



  assign Bit_Slice4_out1 = BitSlice3_out1[7:0];



  assign Bit_Slice8_out1 = Bit_Slice4_out1[7];



  assign Bit_Slice7_out1 = Bit_Slice4_out1[6];



  assign Logical_Operator1_out1_2 = Bit_Slice8_out1 | Bit_Slice7_out1;



  assign Bit_Slice6_out1 = Bit_Slice4_out1[5];



  assign Bit_Slice5_out1_1 = Bit_Slice4_out1[4];



  assign Logical_Operator3_out1 = Bit_Slice6_out1 | Bit_Slice5_out1_1;



  assign Bit_Slice3_out1_1 = Bit_Slice4_out1[3];



  assign Bit_Slice2_out1_2 = Bit_Slice4_out1[2];



  assign Bit_Slice1_out1_1 = Bit_Slice4_out1[1];



  assign Bit_Slice_out1_1 = Bit_Slice4_out1[0];



  assign Constant_out1_1 = 5'b11010;



  assign Constant1_out1 = 5'b11001;



  assign Switch_out1 = (Bit_Slice_out1_1 == 1'b0 ? Constant_out1_1 :
              Constant1_out1);



  assign Logical_Operator_out1_3 = Bit_Slice3_out1_1 | Bit_Slice2_out1_2;



  assign Constant2_out1 = 5'b11000;



  assign Switch1_out1 = (Bit_Slice1_out1_1 == 1'b0 ? Switch_out1 :
              Constant2_out1);



  assign Constant3_out1 = 5'b10111;



  assign Switch2_out1 = (Bit_Slice2_out1_2 == 1'b0 ? Constant_out1_1 :
              Constant3_out1);



  assign Constant4_out1 = 5'b10110;



  assign Logical_Operator2_out1 = Logical_Operator1_out1_2 | Logical_Operator3_out1;



  assign Switch3_out1 = (Bit_Slice3_out1_1 == 1'b0 ? Switch2_out1 :
              Constant4_out1);



  assign Switch4_out1 = (Logical_Operator_out1_3 == 1'b0 ? Switch1_out1 :
              Switch3_out1);



  assign Constant5_out1 = 5'b10101;



  assign Switch5_out1 = (Bit_Slice5_out1_1 == 1'b0 ? Constant_out1_1 :
              Constant5_out1);



  assign Constant6_out1 = 5'b10100;



  assign Switch6_out1 = (Bit_Slice6_out1 == 1'b0 ? Switch5_out1 :
              Constant6_out1);



  assign Constant7_out1 = 5'b10011;



  assign Switch7_out1 = (Bit_Slice7_out1 == 1'b0 ? Constant_out1_1 :
              Constant7_out1);



  assign Constant8_out1 = 5'b10010;



  assign Switch8_out1 = (Bit_Slice8_out1 == 1'b0 ? Switch7_out1 :
              Constant8_out1);



  assign Logical_Operator12_out1_1 = Logical_Operator6_out1_1 | Logical_Operator13_out1_1;



  assign Switch9_out1 = (Logical_Operator1_out1_2 == 1'b0 ? Switch6_out1 :
              Switch8_out1);



  assign Switch10_out1 = (Logical_Operator2_out1 == 1'b0 ? Switch4_out1 :
              Switch9_out1);



  assign Constant9_out1 = 5'b10001;



  assign Switch11_out1 = (Bit_Slice9_out1_1 == 1'b0 ? Constant_out1_1 :
              Constant9_out1);



  assign Constant10_out1 = 5'b10000;



  assign Switch12_out1 = (Bit_Slice10_out1_1 == 1'b0 ? Switch11_out1 :
              Constant10_out1);



  assign Constant11_out1 = 5'b01111;



  assign Switch14_out1 = (Bit_Slice11_out1_1 == 1'b0 ? Constant_out1_1 :
              Constant11_out1);



  assign Constant12_out1 = 5'b01110;



  assign Switch15_out1 = (Bit_Slice12_out1_1 == 1'b0 ? Switch14_out1 :
              Constant12_out1);



  assign Switch16_out1 = (Logical_Operator4_out1_1 == 1'b0 ? Switch12_out1 :
              Switch15_out1);



  assign Constant13_out1 = 5'b01101;



  assign Switch17_out1 = (Bit_Slice13_out1_1 == 1'b0 ? Constant_out1_1 :
              Constant13_out1);



  assign Constant14_out1 = 5'b01100;



  assign Switch18_out1 = (Bit_Slice14_out1_1 == 1'b0 ? Switch17_out1 :
              Constant14_out1);



  assign Constant15_out1 = 5'b01011;



  assign Switch19_out1 = (Bit_Slice15_out1_1 == 1'b0 ? Constant_out1_1 :
              Constant15_out1);



  assign Constant16_out1 = 5'b01010;



  assign Switch20_out1 = (Bit_Slice16_out1_1 == 1'b0 ? Switch19_out1 :
              Constant16_out1);



  assign Switch21_out1 = (Logical_Operator5_out1_1 == 1'b0 ? Switch18_out1 :
              Switch20_out1);



  assign Logical_Operator_out1_4 = Logical_Operator1_out1_1 | Logical_Operator12_out1;



  assign Switch13_out1 = (Logical_Operator6_out1_1 == 1'b0 ? Switch16_out1 :
              Switch21_out1);



  assign Switch33_out1 = (Logical_Operator12_out1_1 == 1'b0 ? Switch10_out1 :
              Switch13_out1);



  assign Constant9_out1_1 = 5'b01001;



  assign Switch11_out1_1 = (Bit_Slice9_out1 == 1'b0 ? Constant_out1_1 :
              Constant9_out1_1);



  assign Constant10_out1_1 = 5'b01000;



  assign Switch12_out1_1 = (Bit_Slice10_out1 == 1'b0 ? Switch11_out1_1 :
              Constant10_out1_1);



  assign Constant11_out1_1 = 5'b00111;



  assign Switch14_out1_1 = (Bit_Slice11_out1 == 1'b0 ? Constant_out1_1 :
              Constant11_out1_1);



  assign Constant12_out1_1 = 5'b00110;



  assign Switch15_out1_1 = (Bit_Slice12_out1 == 1'b0 ? Switch14_out1_1 :
              Constant12_out1_1);



  assign Switch16_out1_1 = (Logical_Operator4_out1 == 1'b0 ? Switch12_out1_1 :
              Switch15_out1_1);



  assign Constant13_out1_1 = 5'b00101;



  assign Switch17_out1_1 = (Bit_Slice13_out1 == 1'b0 ? Constant_out1_1 :
              Constant13_out1_1);



  assign Constant14_out1_1 = 5'b00100;



  assign Switch18_out1_1 = (Bit_Slice14_out1 == 1'b0 ? Switch17_out1_1 :
              Constant14_out1_1);



  assign Constant15_out1_1 = 5'b00011;



  assign Switch19_out1_1 = (Bit_Slice15_out1 == 1'b0 ? Constant_out1_1 :
              Constant15_out1_1);



  assign Constant16_out1_1 = 5'b00010;



  assign Switch20_out1_1 = (Bit_Slice16_out1 == 1'b0 ? Switch19_out1_1 :
              Constant16_out1_1);



  assign Switch21_out1_1 = (Logical_Operator5_out1 == 1'b0 ? Switch18_out1_1 :
              Switch20_out1_1);



  assign Switch13_out1_1 = (Logical_Operator6_out1 == 1'b0 ? Switch16_out1_1 :
              Switch21_out1_1);



  assign Constant1_out1_1 = 5'b00001;



  assign Switch3_out1_1 = (Bit_Slice3_out1 == 1'b0 ? Constant_out1_1 :
              Constant1_out1_1);



  assign Constant2_out1_1 = 5'b00000;



  assign Switch2_out1_1 = (Bit_Slice5_out1 == 1'b0 ? Switch3_out1_1 :
              Constant2_out1_1);



  assign Switch1_out1_1 = (Logical_Operator1_out1_1 == 1'b0 ? Switch13_out1_1 :
              Switch2_out1_1);



  assign Switch34_out1 = (Logical_Operator_out1_4 == 1'b0 ? Switch33_out1 :
              Switch1_out1_1);



  assign Bit_Slice_out1_2 = if_Exponent_0_out1[4:0];



  assign shift_length_exp_a_cor_relop1 = Switch34_out1 >= Bit_Slice_out1_2;



  assign Bit_Slice1_out1_2 = if_Exponent_0_out1[7:5];



  assign Compare_To_Zero_out1_1 = Bit_Slice1_out1_2 == 3'b000;



  assign Logical_Operator1_out1_3 = shift_length_exp_a_cor_relop1 & Compare_To_Zero_out1_1;



  assign C1_out1 = 8'b00000001;



  assign exp_a_cor_1_sub_cast = C1_out1[4:0];
  assign exp_a_cor_1_out1 = Bit_Slice_out1_2 - exp_a_cor_1_sub_cast;



  assign if_shift_length_exp_a_cor_1_out1 = (Logical_Operator1_out1_3 == 1'b0 ? Switch34_out1 :
              exp_a_cor_1_out1);



  assign dynamic_shift_3 = {3'b0, if_shift_length_exp_a_cor_1_out1};
  assign bitsll_Sum_shift_length_out1 = mant_a_ext_mant_b_shifted_out1 <<< dynamic_shift_3;



  assign bitsrl_Sum_1_out1 = mant_a_ext_mant_b_shifted_out1 >> 8'd1;



  assign if_bitget_Sum_Sum_WordLength_out1 = (BitSlice_out1 == 1'b0 ? bitsll_Sum_shift_length_out1 :
              bitsrl_Sum_1_out1);



  assign C5_out1 = 27'b000000000000000000000000000;



  assign if_exp_norm_cfType_Exponent_I_out1 = (Logical_Operator_out1_2 == 1'b0 ? if_bitget_Sum_Sum_WordLength_out1 :
              C5_out1);



  assign BitSlice6_out1 = if_exp_norm_cfType_Exponent_I_out1[24:1];



  assign BitSlice5_out1 = if_exp_norm_cfType_Exponent_I_out1[0];



  assign Bit_Slice13_out1_2 = if_opp_Sign_1_out1[4];



  assign Bit_Slice12_out1_2 = if_opp_Sign_1_out1[3];



  assign Bit_Slice10_out1_2 = if_opp_Sign_1_out1[2];



  assign Bit_Slice11_out1_2 = if_opp_Sign_1_out1[1];



  assign Bit_Slice14_out1_2 = if_opp_Sign_1_out1[0];



  assign Bit_Slice7_out1_1 = if_opp_Sign_out1[2:0];



  assign Constant1_out1_2 = 1'b0;



  assign Bit_Concat_out1_2 = {Bit_Slice7_out1_1, Constant1_out1_2};



  assign Bit_Slice_out1_3 = Bit_Concat_out1_2[0];



  assign Bit_Slice1_out1_3 = Bit_Concat_out1_2[1];



  assign Logical_Operator_out1_5 = Bit_Slice1_out1_3 | Bit_Slice_out1_3;



  assign Switch6_out1_1 = (Bit_Slice14_out1_2 == 1'b0 ? Bit_Slice_out1_3 :
              Logical_Operator_out1_5);



  assign Bit_Slice2_out1_3 = Bit_Concat_out1_2[2];



  assign Logical_Operator1_out1_4 = Bit_Slice2_out1_3 | Logical_Operator_out1_5;



  assign Bit_Slice3_out1_2 = Bit_Concat_out1_2[3];



  assign Logical_Operator2_out1_1 = Bit_Slice3_out1_2 | Logical_Operator1_out1_4;



  assign Switch7_out1_1 = (Bit_Slice14_out1_2 == 1'b0 ? Logical_Operator1_out1_4 :
              Logical_Operator2_out1_1);



  assign Switch3_out1_2 = (Bit_Slice11_out1_2 == 1'b0 ? Switch6_out1_1 :
              Switch7_out1_1);



  assign Bit_Slice8_out1_1 = if_opp_Sign_out1[6:3];



  assign Bit_Slice_out1_4 = Bit_Slice8_out1_1[0];



  assign Logical_Operator3_out1_1 = Bit_Slice_out1_4 | Logical_Operator2_out1_1;



  assign Bit_Slice1_out1_4 = Bit_Slice8_out1_1[1];



  assign Logical_Operator_out1_6 = Bit_Slice1_out1_4 | Logical_Operator3_out1_1;



  assign Switch6_out1_2 = (Bit_Slice14_out1_2 == 1'b0 ? Logical_Operator3_out1_1 :
              Logical_Operator_out1_6);



  assign Bit_Slice2_out1_4 = Bit_Slice8_out1_1[2];



  assign Logical_Operator1_out1_5 = Bit_Slice2_out1_4 | Logical_Operator_out1_6;



  assign Bit_Slice3_out1_3 = Bit_Slice8_out1_1[3];



  assign Logical_Operator2_out1_2 = Bit_Slice3_out1_3 | Logical_Operator1_out1_5;



  assign Switch7_out1_2 = (Bit_Slice14_out1_2 == 1'b0 ? Logical_Operator1_out1_5 :
              Logical_Operator2_out1_2);



  assign Switch3_out1_3 = (Bit_Slice11_out1_2 == 1'b0 ? Switch6_out1_2 :
              Switch7_out1_2);



  assign Switch6_out1_3 = (Bit_Slice10_out1_2 == 1'b0 ? Switch3_out1_2 :
              Switch3_out1_3);



  assign Bit_Slice9_out1_2 = if_opp_Sign_out1[10:7];



  assign Bit_Slice_out1_5 = Bit_Slice9_out1_2[0];



  assign Logical_Operator3_out1_2 = Bit_Slice_out1_5 | Logical_Operator2_out1_2;



  assign Bit_Slice1_out1_5 = Bit_Slice9_out1_2[1];



  assign Logical_Operator_out1_7 = Bit_Slice1_out1_5 | Logical_Operator3_out1_2;



  assign Switch6_out1_4 = (Bit_Slice14_out1_2 == 1'b0 ? Logical_Operator3_out1_2 :
              Logical_Operator_out1_7);



  assign Bit_Slice2_out1_5 = Bit_Slice9_out1_2[2];



  assign Logical_Operator1_out1_6 = Bit_Slice2_out1_5 | Logical_Operator_out1_7;



  assign Bit_Slice3_out1_4 = Bit_Slice9_out1_2[3];



  assign Logical_Operator2_out1_3 = Bit_Slice3_out1_4 | Logical_Operator1_out1_6;



  assign Switch7_out1_3 = (Bit_Slice14_out1_2 == 1'b0 ? Logical_Operator1_out1_6 :
              Logical_Operator2_out1_3);



  assign Switch3_out1_4 = (Bit_Slice11_out1_2 == 1'b0 ? Switch6_out1_4 :
              Switch7_out1_3);



  assign Bit_Slice3_out1_5 = if_opp_Sign_out1[14:11];



  assign Bit_Slice_out1_6 = Bit_Slice3_out1_5[0];



  assign Logical_Operator3_out1_3 = Bit_Slice_out1_6 | Logical_Operator2_out1_3;



  assign Bit_Slice1_out1_6 = Bit_Slice3_out1_5[1];



  assign Logical_Operator_out1_8 = Bit_Slice1_out1_6 | Logical_Operator3_out1_3;



  assign Switch6_out1_5 = (Bit_Slice14_out1_2 == 1'b0 ? Logical_Operator3_out1_3 :
              Logical_Operator_out1_8);



  assign Bit_Slice2_out1_6 = Bit_Slice3_out1_5[2];



  assign Logical_Operator1_out1_7 = Bit_Slice2_out1_6 | Logical_Operator_out1_8;



  assign Bit_Slice3_out1_6 = Bit_Slice3_out1_5[3];



  assign Logical_Operator2_out1_4 = Bit_Slice3_out1_6 | Logical_Operator1_out1_7;



  assign Switch7_out1_4 = (Bit_Slice14_out1_2 == 1'b0 ? Logical_Operator1_out1_7 :
              Logical_Operator2_out1_4);



  assign Switch3_out1_5 = (Bit_Slice11_out1_2 == 1'b0 ? Switch6_out1_5 :
              Switch7_out1_4);



  assign Switch7_out1_5 = (Bit_Slice10_out1_2 == 1'b0 ? Switch3_out1_4 :
              Switch3_out1_5);



  assign Switch3_out1_6 = (Bit_Slice12_out1_2 == 1'b0 ? Switch6_out1_3 :
              Switch7_out1_5);



  assign Bit_Slice4_out1_1 = if_opp_Sign_out1[18:15];



  assign Bit_Slice_out1_7 = Bit_Slice4_out1_1[0];



  assign Logical_Operator3_out1_4 = Bit_Slice_out1_7 | Logical_Operator2_out1_4;



  assign Bit_Slice1_out1_7 = Bit_Slice4_out1_1[1];



  assign Logical_Operator_out1_9 = Bit_Slice1_out1_7 | Logical_Operator3_out1_4;



  assign Switch6_out1_6 = (Bit_Slice14_out1_2 == 1'b0 ? Logical_Operator3_out1_4 :
              Logical_Operator_out1_9);



  assign Bit_Slice2_out1_7 = Bit_Slice4_out1_1[2];



  assign Logical_Operator1_out1_8 = Bit_Slice2_out1_7 | Logical_Operator_out1_9;



  assign Bit_Slice3_out1_7 = Bit_Slice4_out1_1[3];



  assign Logical_Operator2_out1_5 = Bit_Slice3_out1_7 | Logical_Operator1_out1_8;



  assign Switch7_out1_6 = (Bit_Slice14_out1_2 == 1'b0 ? Logical_Operator1_out1_8 :
              Logical_Operator2_out1_5);



  assign Switch3_out1_7 = (Bit_Slice11_out1_2 == 1'b0 ? Switch6_out1_6 :
              Switch7_out1_6);



  assign Bit_Slice5_out1_2 = if_opp_Sign_out1[22:19];



  assign Bit_Slice_out1_8 = Bit_Slice5_out1_2[0];



  assign Logical_Operator3_out1_5 = Bit_Slice_out1_8 | Logical_Operator2_out1_5;



  assign Bit_Slice1_out1_8 = Bit_Slice5_out1_2[1];



  assign Logical_Operator_out1_10 = Bit_Slice1_out1_8 | Logical_Operator3_out1_5;



  assign Switch6_out1_7 = (Bit_Slice14_out1_2 == 1'b0 ? Logical_Operator3_out1_5 :
              Logical_Operator_out1_10);



  assign Bit_Slice2_out1_8 = Bit_Slice5_out1_2[2];



  assign Logical_Operator1_out1_9 = Bit_Slice2_out1_8 | Logical_Operator_out1_10;



  assign Bit_Slice3_out1_8 = Bit_Slice5_out1_2[3];



  assign Logical_Operator2_out1_6 = Bit_Slice3_out1_8 | Logical_Operator1_out1_9;



  assign Switch7_out1_7 = (Bit_Slice14_out1_2 == 1'b0 ? Logical_Operator1_out1_9 :
              Logical_Operator2_out1_6);



  assign Switch3_out1_8 = (Bit_Slice11_out1_2 == 1'b0 ? Switch6_out1_7 :
              Switch7_out1_7);



  assign Switch6_out1_8 = (Bit_Slice10_out1_2 == 1'b0 ? Switch3_out1_7 :
              Switch3_out1_8);



  assign Bit_Slice6_out1_1 = if_opp_Sign_out1[26:23];



  assign Bit_Slice_out1_9 = Bit_Slice6_out1_1[0];



  assign Logical_Operator3_out1_6 = Bit_Slice_out1_9 | Logical_Operator2_out1_6;



  assign Bit_Slice1_out1_9 = Bit_Slice6_out1_1[1];



  assign Logical_Operator_out1_11 = Bit_Slice1_out1_9 | Logical_Operator3_out1_6;



  assign Switch6_out1_9 = (Bit_Slice14_out1_2 == 1'b0 ? Logical_Operator3_out1_6 :
              Logical_Operator_out1_11);



  assign Bit_Slice2_out1_9 = Bit_Slice6_out1_1[2];



  assign Logical_Operator1_out1_10 = Bit_Slice2_out1_9 | Logical_Operator_out1_11;



  assign Bit_Slice3_out1_9 = Bit_Slice6_out1_1[3];



  assign Logical_Operator2_out1_7 = Bit_Slice3_out1_9 | Logical_Operator1_out1_10;



  assign Switch7_out1_8 = (Bit_Slice14_out1_2 == 1'b0 ? Logical_Operator1_out1_10 :
              Logical_Operator2_out1_7);



  assign Switch3_out1_9 = (Bit_Slice11_out1_2 == 1'b0 ? Switch6_out1_9 :
              Switch7_out1_8);



  assign Bit_Slice1_out1_10 = if_opp_Sign_out1[27];



  assign Logical_Operator_out1_12 =  ~ Bit_Slice1_out1_10;



  assign Logical_Operator1_out1_11 = Logical_Operator_out1_12 & Logical_Operator2_out1_7;



  assign Switch7_out1_9 = (Bit_Slice10_out1_2 == 1'b0 ? Switch3_out1_9 :
              Logical_Operator1_out1_11);



  assign Switch3_out1_10 = (Bit_Slice12_out1_2 == 1'b0 ? Switch6_out1_8 :
              Switch7_out1_9);



  assign Switch2_out1_2 = (Bit_Slice13_out1_2 == 1'b0 ? Switch3_out1_6 :
              Switch3_out1_10);



  assign BitSlice1_out1 = mant_a_ext_mant_b_shifted_out1[0];



  assign sticky_bitget_Sum_1_out1 = BitSlice1_out1 | Switch2_out1_2;



  assign BitSlice_out1_1 = BitSlice6_out1[0];



  assign BitSlice1_out1_1 = BitSlice6_out1[1];



  assign if_bitget_Sum_Sum_WordLength_2_out1 = (BitSlice_out1 == 1'b0 ? Switch2_out1_2 :
              sticky_bitget_Sum_1_out1);



  assign sticky_bitget_Sum_1_out1_1 = BitSlice5_out1 | if_bitget_Sum_Sum_WordLength_2_out1;



  assign alphabitget_Mant_tmp_2_0_out1 = BitSlice1_out1_1 | sticky_bitget_Sum_1_out1_1;



  assign alphabitget_Mant_tmp_1_0_out1 = BitSlice_out1_1 & alphabitget_Mant_tmp_2_0_out1;



  assign alpha0_out1_2 = 1'b0;



  assign BitSlice4_out1 = BitSlice6_out1[23:1];



  assign Bit_Concat_out1_3 = {alpha0_out1_2, BitSlice4_out1};



  assign cast_2_like_Mant_tmp_out1 = 24'b000000000000000000000001;



  assign Mant_tmp_cast_2_like_Man_out1 = Bit_Concat_out1_3 + cast_2_like_Mant_tmp_out1;



  assign if_bitget_Mant_tmp_1_0_out1 = (alphabitget_Mant_tmp_1_0_out1 == 1'b0 ? Bit_Concat_out1_3 :
              Mant_tmp_cast_2_like_Man_out1);



  assign BitSlice2_out1 = if_bitget_Mant_tmp_1_0_out1[23];



  assign BitSlice4_out1_1 = if_bitget_Sum_Sum_WordLength_out1[25];



  assign C4_out1 = 8'b00000000;



  assign Sum_0_out1 = mant_a_ext_mant_b_shifted_out1 == 27'b000000000000000000000000000;



  assign exp_a_cor_shift_length_1 = {3'b0, Switch34_out1};
  assign exp_a_cor_shift_length_out1 = if_Exponent_0_out1 - exp_a_cor_shift_length_1;



  assign C2_out1 = 8'b00000001;



  assign if_shift_length_exp_a_cor_out1 = (Logical_Operator1_out1_3 == 1'b0 ? exp_a_cor_shift_length_out1 :
              C2_out1);



  assign BitSlice2_out1_1 = mant_a_ext_mant_b_shifted_out1[25];



  assign C3_out1 = 8'b00000000;



  assign if_Sum_0_out1 = (Sum_0_out1 == 1'b0 ? if_shift_length_exp_a_cor_out1 :
              C3_out1);



  assign if_bitget_Sum_Sum_WordLength_1_out1 = (BitSlice2_out1_1 == 1'b0 ? if_Sum_0_out1 :
              if_Exponent_0_out1);



  assign C_out1_2 = 8'b00000001;



  assign exp_a_cor_1_out1_1 = C_out1_2 + if_Exponent_0_out1;



  assign if_bitget_Sum_Sum_WordLength_1_out1_1 = (BitSlice_out1 == 1'b0 ? if_bitget_Sum_Sum_WordLength_1_out1 :
              exp_a_cor_1_out1_1);



  assign if_bitget_Sum_Sum_WordLength_out1_1 = (BitSlice4_out1_1 == 1'b0 ? C4_out1 :
              if_bitget_Sum_Sum_WordLength_1_out1_1);



  assign cast_1_like_Exp_out1 = 8'b00000001;



  assign Exp_cast_1_like_Exp_out1 = if_bitget_Sum_Sum_WordLength_out1_1 + cast_1_like_Exp_out1;



  assign if_bitget_Mant_tmp_Mant_tmp_Wor_out1 = (BitSlice2_out1 == 1'b0 ? if_bitget_Sum_Sum_WordLength_out1_1 :
              Exp_cast_1_like_Exp_out1);



  assign Exponent_0_out1_2 = if_bitget_Mant_tmp_Mant_tmp_Wor_out1 == 8'b00000000;



  assign BitSlice3_out1_1 = if_bitget_Mant_tmp_1_0_out1[22:0];



  assign Mantissa_0_out1 = BitSlice3_out1_1 == 23'b00000000000000000000000;



  assign alphaExponent_0_Mantissa_out1 = Exponent_0_out1_2 & Mantissa_0_out1;



  assign Constant_out1_2 = 1'b0;



  assign Switch_out1_1 = (aExponent_cfType_Exponent_I_out1 == 1'b0 ? alphaExponent_0_Mantissa_out1 :
              Constant_out1_2);



  assign alphaaSign_1_bSign_1_out1 = if_bitconcat_aExponent_aMantiss_2_out1 & if_bitconcat_aExponent_aMantiss_5_out1;



  assign if_Exponent_0_Mantissa_out1 = (Switch_out1_1 == 1'b0 ? if_bitconcat_aExponent_aMantiss_2_out1 :
              alphaaSign_1_bSign_1_out1);



  assign if_aExponent_cfType_Exponent_out1 = (aExponent_cfType_Exponent_I_out1 == 1'b0 ? if_bitget_Mant_tmp_Mant_tmp_Wor_out1 :
              if_bitconcat_aExponent_aMantiss_out1);



  assign opp_signs_exp_b_cfType_out1 = bitxor_out1 & exp_b_cfType_Exponent_Inf_o_out1;



  assign mant_a_0_out1 = if_bitconcat_aExponent_aMantiss_1_out1 != 23'b00000000000000000000000;



  assign alphamant_a_0_opp_signs_out1 = opp_signs_exp_b_cfType_out1 | mant_a_0_out1;



  assign BitSet_out1 = if_bitconcat_aExponent_aMantiss_1_out1 | 23'b10000000000000000000000;



  assign if_mant_a_0_opp_signs_out1 = (alphamant_a_0_opp_signs_out1 == 1'b0 ? if_bitconcat_aExponent_aMantiss_1_out1 :
              BitSet_out1);



  assign if_aExponent_cfType_Exponent_1_out1 = (aExponent_cfType_Exponent_I_out1 == 1'b0 ? BitSlice3_out1_1 :
              if_mant_a_0_opp_signs_out1);



  // Combine FP sign, exponent, mantissa into 32 bit word
  assign out_pack = {if_Exponent_0_Mantissa_out1, if_aExponent_cfType_Exponent_out1, if_aExponent_cfType_Exponent_1_out1};



  assign out = out_pack;

endmodule  // nfp_sub_single
