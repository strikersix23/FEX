%ifdef CONFIG
{
  "HostFeatures": ["AVX"],
  "RegData": {
      "XMM1": ["0xFFFFFFFFFFFFFFFF", "0xFFFFFFFFFFFFFFFF", "0xFFFFFFFFFFFFFFFF", "0xFFFFFFFFFFFFFFFF"],
      "XMM2": ["0xFFFFFFFFFFFFFFFF", "0xFFFFFFFFFFFFFFFF", "0x0000000000000000", "0x0000000000000000"],
      "XMM3": ["0xCCCCCCCCCCCCCCCC", "0xCCCCCCCCCCCCCCCC", "0xCCCCCCCCCCCCCCCC", "0xDDDDDDDDDDDDDDDD"],
      "XMM4": ["0xCCCCCCCCCCCCCCCC", "0xDDDDDDDDDDDDDDDD", "0xEEEEEEEEEEEEEEEE", "0xFFFFFFFFFFFFFFFF"],
      "XMM5": ["0xCCCCCCCCCCCCCCCC", "0xDDDDDDDDDDDDDDDD", "0xFFFFFFFFFFFFFFFF", "0xFFFFFFFFFFFFFFFF"],
      "XMM6": ["0xCCCCCCCCCCCCCCCC", "0xDDDDDDDDDDDDDDDD", "0xEEEEEEEEEEEEEEEE", "0xFFFFFFFFFFFFFFFF"]
  }
}
%endif

lea rdx, [rel .data]

; Load inputs
vmovdqa ymm1, [rdx]
vmovdqa xmm2, [rdx]
vmovdqa ymm3, [rdx + 32]

; Test memory overwrite
mov rax, 0xCCCCCCCCCCCCCCCC
mov [rdx + 32], rax
mov rax, 0xDDDDDDDDDDDDDDDD
mov [rdx + 40], rax
mov rax, 0xEEEEEEEEEEEEEEEE
mov [rdx + 48], rax
mov rax, 0xFFFFFFFFFFFFFFFF
mov [rdx + 56], rax

vmovdqa ymm4, [rdx + 32]
vmovdqa [rdx], xmm4
vmovapd ymm5, [rdx]
vmovdqa [rdx], ymm4
vmovapd ymm6, [rdx]

hlt

align 32
.data:
db 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
db 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
db 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC
db 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD
