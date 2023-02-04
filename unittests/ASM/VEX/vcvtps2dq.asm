%ifdef CONFIG
{
  "HostFeatures": ["AVX"],
  "RegData": {
    "XMM0":  ["0x0000004600000053", "0x0000000D00000029", "0x0000000000000000", "0x0000000000000000"],
    "XMM1":  ["0x0000001600000005", "0x000000050000000A", "0x0000000000000000", "0x0000000000000000"],
    "XMM2":  ["0x000000430000001D", "0x0000005B00000013", "0x0000000000000000", "0x0000000000000000"],
    "XMM3":  ["0x0000003300000028", "0x0000001800000021", "0x0000000000000000", "0x0000000000000000"],
    "XMM4":  ["0x000000180000005B", "0x0000005B00000063", "0x0000000000000000", "0x0000000000000000"],
    "XMM5":  ["0x000000630000005B", "0x0000004A00000041", "0x0000000000000000", "0x0000000000000000"],
    "XMM6":  ["0x0000001900000023", "0x0000005A00000006", "0x0000000000000000", "0x0000000000000000"],
    "XMM7":  ["0x0000003400000021", "0x0000000A0000003A", "0x0000000000000000", "0x0000000000000000"],
    "XMM8":  ["0x0000005400000030", "0x000000420000005A", "0x0000005400000030", "0x000000420000005A"],
    "XMM9":  ["0x0000000700000060", "0x0000005F0000001A", "0x0000000700000060", "0x0000005F0000001A"],
    "XMM10": ["0x0000002500000058", "0x0000000A00000032", "0x0000002500000058", "0x0000000A00000032"],
    "XMM11": ["0x000000140000004E", "0x000000290000000A", "0x000000140000004E", "0x000000290000000A"],
    "XMM12": ["0x0000003A0000000F", "0x000000380000000A", "0x0000003A0000000F", "0x000000380000000A"],
    "XMM13": ["0x0000000500000035", "0x0000000300000049", "0x0000000500000035", "0x0000000300000049"],
    "XMM14": ["0x0000004700000039", "0x000000590000003E", "0x0000004700000039", "0x000000590000003E"],
    "XMM15": ["0x0000001800000030", "0x0000006100000022", "0x0000001800000030", "0x0000006100000022"]
  }
}
%endif

lea rdx, [rel .data]

vcvtps2dq xmm0,  [rdx + 32 * 0]
vcvtps2dq xmm1,  [rdx + 32 * 1]
vcvtps2dq xmm2,  [rdx + 32 * 2]
vcvtps2dq xmm3,  [rdx + 32 * 3]
vcvtps2dq xmm4,  [rdx + 32 * 4]
vcvtps2dq xmm5,  [rdx + 32 * 5]
vcvtps2dq xmm6,  [rdx + 32 * 6]
vcvtps2dq xmm7,  [rdx + 32 * 7]

vcvtps2dq ymm8,  [rdx + 32 * 8]
vcvtps2dq ymm9,  [rdx + 32 * 9]
vcvtps2dq ymm10, [rdx + 32 * 10]
vcvtps2dq ymm11, [rdx + 32 * 11]
vcvtps2dq ymm12, [rdx + 32 * 12]
vcvtps2dq ymm13, [rdx + 32 * 13]
vcvtps2dq ymm14, [rdx + 32 * 14]
vcvtps2dq ymm15, [rdx + 32 * 15]

hlt

align 32
.data:
dd 83.0999 , 69.50512, 41.02678, 13.05881
dd 83.0999 , 69.50512, 41.02678, 13.05881

dd 5.35242 , 21.9932 , 9.67383 , 5.32372
dd 5.35242 , 21.9932 , 9.67383 , 5.32372

dd 29.02872, 66.50151, 19.30764, 91.3633
dd 29.02872, 66.50151, 19.30764, 91.3633

dd 40.45086, 50.96153, 32.64489, 23.97574
dd 40.45086, 50.96153, 32.64489, 23.97574

dd 90.64316, 24.22547, 98.9394 , 91.21715
dd 90.64316, 24.22547, 98.9394 , 91.21715

dd 90.80143, 99.48407, 64.97245, 74.39838
dd 90.80143, 99.48407, 64.97245, 74.39838

dd 35.22761, 25.35321, 5.8732  , 90.19956
dd 35.22761, 25.35321, 5.8732  , 90.19956

dd 33.03133, 52.02952, 58.38554, 10.17531
dd 33.03133, 52.02952, 58.38554, 10.17531

dd 47.84703, 84.04831, 90.02965, 65.81329
dd 47.84703, 84.04831, 90.02965, 65.81329

dd 96.27991, 6.64479 , 25.58971, 95.00694
dd 96.27991, 6.64479 , 25.58971, 95.00694

dd 88.1929 , 37.16964, 49.52602, 10.27223
dd 88.1929 , 37.16964, 49.52602, 10.27223

dd 77.70605, 20.21439, 9.8056  , 41.29389
dd 77.70605, 20.21439, 9.8056  , 41.29389

dd 15.4071 , 57.54286, 9.61117 , 55.54302
dd 15.4071 , 57.54286, 9.61117 , 55.54302

dd 52.90745, 4.88086 , 72.52882, 3.0201
dd 52.90745, 4.88086 , 72.52882, 3.0201

dd 56.55091, 71.22749, 61.84736, 88.74295
dd 56.55091, 71.22749, 61.84736, 88.74295

dd 47.72641, 24.17404, 33.70564, 96.71303
dd 47.72641, 24.17404, 33.70564, 96.71303