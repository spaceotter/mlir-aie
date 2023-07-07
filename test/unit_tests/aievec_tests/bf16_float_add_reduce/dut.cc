void dut(bfloat16 *restrict v1, float *restrict v2) {
  int32_t v3 = 0;
  int32_t v4 = 4;
  int32_t v5 = 8;
  int32_t v6 = 16;
  int32_t v7 = 32;
  v16float v8 = broadcast_zero_float();
  size_t v9 = 0;
  size_t v10 = 1024;
  size_t v11 = 16;
  v16float v12;
  v16float v13 = v8;
  for (size_t v14 = v9; v14 < v10; v14 += v11)
    chess_prepare_for_pipelining chess_loop_range(64, 64) {
      v16bfloat16 v15 = *(v16bfloat16 *)(v1 + v14);
      v16accfloat v16 = ups_to_v16accfloat(v15);
      v16accfloat v17 = v16accfloat(v13);
      v16accfloat v18 = add(v16, v17);
      v16float v19 = v16float(v18);
      v13 = v19;
    }
  v12 = v13;
  v16float v20 = shift_bytes(v12, v12, v7);
  v16accfloat v21 = v16accfloat(v12);
  v16accfloat v22 = v16accfloat(v20);
  v16accfloat v23 = add(v21, v22);
  v16float v24 = v16float(v23);
  v16float v25 = shift_bytes(v24, v24, v6);
  v16accfloat v26 = v16accfloat(v24);
  v16accfloat v27 = v16accfloat(v25);
  v16accfloat v28 = add(v26, v27);
  v16float v29 = v16float(v28);
  v16float v30 = shift_bytes(v29, v29, v5);
  v16accfloat v31 = v16accfloat(v29);
  v16accfloat v32 = v16accfloat(v30);
  v16accfloat v33 = add(v31, v32);
  v16float v34 = v16float(v33);
  v16float v35 = shift_bytes(v34, v34, v4);
  v16accfloat v36 = v16accfloat(v34);
  v16accfloat v37 = v16accfloat(v35);
  v16accfloat v38 = add(v36, v37);
  v16float v39 = v16float(v38);
  float v40 = extract_elem(v39, v3);
  *(float *)v2 = v40;
  return;
}
