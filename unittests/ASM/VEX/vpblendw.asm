%ifdef CONFIG
{
  "HostFeatures": ["AVX"],
  "RegData": {
    "XMM2": ["0xAAAABBBBCCCCDDDD", "0xEEEEFFFF99998888", "0x7777666655554444", "0x222211110000AAAA"],
    "XMM3": ["0x1111222233334444", "0x5555666677778888", "0x9999AAAABBBBCCCC", "0xDDDDEEEEFFFF1111"],
    "XMM4": ["0xAAAABBBBCCCCDDDD", "0xEEEEFFFF99998888", "0x0000000000000000", "0x0000000000000000"],
    "XMM5": ["0x1111222233334444", "0x5555666677778888", "0x0000000000000000", "0x0000000000000000"],
    "XMM6": ["0x1111BBBB3333DDDD", "0x5555FFFF77778888", "0x99996666BBBB4444", "0xDDDD1111FFFFAAAA"],
    "XMM7": ["0xAAAA2222CCCC4444", "0xEEEE666699998888", "0x7777AAAA5555CCCC", "0x2222EEEE00001111"],
    "XMM8": ["0x1111BBBB3333DDDD", "0x5555FFFF77778888", "0x0000000000000000", "0x0000000000000000"],
    "XMM9": ["0xAAAA2222CCCC4444", "0xEEEE666699998888", "0x0000000000000000", "0x0000000000000000"]
  },
  "MemoryRegions": {
    "0x100000000": "4096"
  }
}
%endif

lea rdx, [rel .data]

vmovapd ymm0, [rdx]
vmovapd ymm1, [rdx + 32]

; Selecting all of one input vector
vpblendw ymm2, ymm0, ymm1, 0    ; All of ymm0
vpblendw ymm3, ymm0, ymm1, 0xFF ; All of ymm1

vpblendw xmm4, xmm0, xmm1, 0    ; All of xmm0
vpblendw xmm5, xmm0, xmm1, 0xFF ; All of xmm1

; Alternating source vectors
vpblendw ymm6, ymm0, ymm1, 0b10101010
vpblendw ymm7, ymm0, ymm1, 0b01010101

vpblendw xmm8, xmm0, xmm1, 0b10101010
vpblendw xmm9, xmm0, xmm1, 0b01010101

hlt

align 32
.data:
dq 0xAAAABBBBCCCCDDDD
dq 0xEEEEFFFF99998888
dq 0x7777666655554444
dq 0x222211110000AAAA

dq 0x1111222233334444
dq 0x5555666677778888
dq 0x9999AAAABBBBCCCC
dq 0xDDDDEEEEFFFF1111