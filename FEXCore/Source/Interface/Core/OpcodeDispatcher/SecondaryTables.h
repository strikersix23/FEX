// SPDX-License-Identifier: MIT
#pragma once
#include "Interface/Core/OpcodeDispatcher.h"

namespace FEXCore::IR {
constexpr std::tuple<uint8_t, uint8_t, FEXCore::X86Tables::OpDispatchPtr> OpDispatch_TwoByteOpTable[] = {
  // Instructions
  {0x06, 1, &OpDispatchBuilder::PermissionRestrictedOp},
  {0x07, 1, &OpDispatchBuilder::PermissionRestrictedOp},
  {0x0B, 1, &OpDispatchBuilder::INTOp},
  {0x0E, 1, &OpDispatchBuilder::X87EMMS},

  {0x19, 7, &OpDispatchBuilder::NOPOp}, // NOP with ModRM

  {0x20, 4, &OpDispatchBuilder::PermissionRestrictedOp},

  {0x30, 1, &OpDispatchBuilder::PermissionRestrictedOp},
  {0x31, 1, &OpDispatchBuilder::RDTSCOp},
  {0x32, 2, &OpDispatchBuilder::PermissionRestrictedOp},
  {0x34, 3, &OpDispatchBuilder::UnimplementedOp},

  {0x3F, 1, &OpDispatchBuilder::ThunkOp},
  {0x40, 16, &OpDispatchBuilder::CMOVOp},
  {0x6E, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::MOVBetweenGPR_FPR, OpDispatchBuilder::VectorOpType::MMX>},
  {0x6F, 1, &OpDispatchBuilder::MOVQMMXOp},
  {0x7E, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::MOVBetweenGPR_FPR, OpDispatchBuilder::VectorOpType::MMX>},
  {0x7F, 1, &OpDispatchBuilder::MOVQMMXOp},
  {0x80, 16, &OpDispatchBuilder::CondJUMPOp},
  {0x90, 16, &OpDispatchBuilder::SETccOp},
  {0xA2, 1, &OpDispatchBuilder::CPUIDOp},
  {0xA3, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::BTOp, 0, BTAction::BTNone>}, // BT
  {0xA4, 1, &OpDispatchBuilder::SHLDImmediateOp},
  {0xA5, 1, &OpDispatchBuilder::SHLDOp},
  {0xAB, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::BTOp, 0, BTAction::BTSet>}, // BTS
  {0xAC, 1, &OpDispatchBuilder::SHRDImmediateOp},
  {0xAD, 1, &OpDispatchBuilder::SHRDOp},
  {0xAF, 1, &OpDispatchBuilder::IMUL1SrcOp},
  {0xB0, 2, &OpDispatchBuilder::CMPXCHGOp},                                            // CMPXCHG
  {0xB3, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::BTOp, 0, BTAction::BTClear>}, // BTR
  {0xB6, 2, &OpDispatchBuilder::MOVZXOp},
  {0xBB, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::BTOp, 0, BTAction::BTComplement>}, // BTC
  {0xBC, 1, &OpDispatchBuilder::BSFOp},                                                     // BSF
  {0xBD, 1, &OpDispatchBuilder::BSROp},                                                     // BSF
  {0xBE, 2, &OpDispatchBuilder::MOVSXOp},
  {0xC0, 2, &OpDispatchBuilder::XADDOp},
  {0xC3, 1, &OpDispatchBuilder::MOVGPRNTOp},
  {0xC4, 1, &OpDispatchBuilder::PINSROp<OpSize::i16Bit>},
  {0xC5, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PExtrOp, OpSize::i16Bit>},
  {0xC8, 8, &OpDispatchBuilder::BSWAPOp},

  // SSE
  {0x10, 2, &OpDispatchBuilder::MOVVectorUnalignedOp},
  {0x12, 2, &OpDispatchBuilder::MOVLPOp},
  {0x14, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKLOp, OpSize::i32Bit>},
  {0x15, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKHOp, OpSize::i32Bit>},
  {0x16, 2, &OpDispatchBuilder::MOVHPDOp},
  {0x28, 2, &OpDispatchBuilder::MOVVectorAlignedOp},
  {0x2A, 1, &OpDispatchBuilder::InsertMMX_To_XMM_Vector_CVT_Int_To_Float},
  {0x2B, 1, &OpDispatchBuilder::MOVVectorNTOp},
  {0x2C, 1, &OpDispatchBuilder::XMM_To_MMX_Vector_CVT_Float_To_Int<OpSize::i32Bit, false, false>},
  {0x2D, 1, &OpDispatchBuilder::XMM_To_MMX_Vector_CVT_Float_To_Int<OpSize::i32Bit, false, true>},
  {0x2E, 2, &OpDispatchBuilder::UCOMISxOp<OpSize::i32Bit>},
  {0x50, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::MOVMSKOp, OpSize::i32Bit>},
  {0x51, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorUnaryOp, IR::OP_VFSQRT, OpSize::i32Bit>},
  {0x52, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorUnaryOp, IR::OP_VFRSQRT, OpSize::i32Bit>},
  {0x53, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorUnaryOp, IR::OP_VFRECP, OpSize::i32Bit>},
  {0x54, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VAND, OpSize::i128Bit>},
  {0x55, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUROp, IR::OP_VANDN, OpSize::i64Bit>},
  {0x56, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VOR, OpSize::i128Bit>},
  {0x57, 1, &OpDispatchBuilder::VectorXOROp},
  {0x58, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VFADD, OpSize::i32Bit>},
  {0x59, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VFMUL, OpSize::i32Bit>},
  {0x5A, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::Vector_CVT_Float_To_Float, 8, 4, false>},
  {0x5B, 1, &OpDispatchBuilder::Vector_CVT_Int_To_Float<OpSize::i32Bit, false>},
  {0x5C, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VFSUB, OpSize::i32Bit>},
  {0x5D, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VFMIN, OpSize::i32Bit>},
  {0x5E, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VFDIV, OpSize::i32Bit>},
  {0x5F, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VFMAX, OpSize::i32Bit>},
  {0x60, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKLOp, OpSize::i8Bit>},
  {0x61, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKLOp, OpSize::i16Bit>},
  {0x62, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKLOp, OpSize::i32Bit>},
  {0x63, 1, &OpDispatchBuilder::PACKSSOp<OpSize::i16Bit>},
  {0x64, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VCMPGT, OpSize::i8Bit>},
  {0x65, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VCMPGT, OpSize::i16Bit>},
  {0x66, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VCMPGT, OpSize::i32Bit>},
  {0x67, 1, &OpDispatchBuilder::PACKUSOp<OpSize::i16Bit>},
  {0x68, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKHOp, OpSize::i8Bit>},
  {0x69, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKHOp, OpSize::i16Bit>},
  {0x6A, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKHOp, OpSize::i32Bit>},
  {0x6B, 1, &OpDispatchBuilder::PACKSSOp<OpSize::i32Bit>},
  {0x70, 1, &OpDispatchBuilder::PSHUFW8ByteOp},

  {0x74, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VCMPEQ, OpSize::i8Bit>},
  {0x75, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VCMPEQ, OpSize::i16Bit>},
  {0x76, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VCMPEQ, OpSize::i32Bit>},
  {0x77, 1, &OpDispatchBuilder::X87EMMS},

  {0xC2, 1, &OpDispatchBuilder::VFCMPOp<OpSize::i32Bit>},
  {0xC6, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::SHUFOp, OpSize::i32Bit>},

  {0xD1, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSRLDOp, OpSize::i16Bit>},
  {0xD2, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSRLDOp, OpSize::i32Bit>},
  {0xD3, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSRLDOp, OpSize::i64Bit>},
  {0xD4, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VADD, OpSize::i64Bit>},
  {0xD5, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VMUL, OpSize::i16Bit>},
  {0xD7, 1, &OpDispatchBuilder::MOVMSKOpOne}, // PMOVMSKB
  {0xD8, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VUQSUB, OpSize::i8Bit>},
  {0xD9, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VUQSUB, OpSize::i16Bit>},
  {0xDA, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VUMIN, OpSize::i8Bit>},
  {0xDB, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VAND, OpSize::i64Bit>},
  {0xDC, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VUQADD, OpSize::i8Bit>},
  {0xDD, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VUQADD, OpSize::i16Bit>},
  {0xDE, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VUMAX, OpSize::i8Bit>},
  {0xDF, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUROp, IR::OP_VANDN, OpSize::i64Bit>},
  {0xE0, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VURAVG, OpSize::i8Bit>},
  {0xE1, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSRAOp, OpSize::i16Bit>},
  {0xE2, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSRAOp, OpSize::i32Bit>},
  {0xE3, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VURAVG, OpSize::i16Bit>},
  {0xE4, 1, &OpDispatchBuilder::PMULHW<false>},
  {0xE5, 1, &OpDispatchBuilder::PMULHW<true>},
  {0xE7, 1, &OpDispatchBuilder::MOVVectorNTOp},
  {0xE8, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSQSUB, OpSize::i8Bit>},
  {0xE9, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSQSUB, OpSize::i16Bit>},
  {0xEA, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSMIN, OpSize::i16Bit>},
  {0xEB, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VOR, OpSize::i64Bit>},
  {0xEC, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSQADD, OpSize::i8Bit>},
  {0xED, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSQADD, OpSize::i16Bit>},
  {0xEE, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSMAX, OpSize::i16Bit>},
  {0xEF, 1, &OpDispatchBuilder::VectorXOROp},

  {0xF1, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSLL, OpSize::i16Bit>},
  {0xF2, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSLL, OpSize::i32Bit>},
  {0xF3, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSLL, OpSize::i64Bit>},
  {0xF4, 1, &OpDispatchBuilder::PMULLOp<OpSize::i32Bit, false>},
  {0xF5, 1, &OpDispatchBuilder::PMADDWD},
  {0xF6, 1, &OpDispatchBuilder::PSADBW},
  {0xF7, 1, &OpDispatchBuilder::MASKMOVOp},
  {0xF8, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSUB, OpSize::i8Bit>},
  {0xF9, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSUB, OpSize::i16Bit>},
  {0xFA, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSUB, OpSize::i32Bit>},
  {0xFB, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSUB, OpSize::i64Bit>},
  {0xFC, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VADD, OpSize::i8Bit>},
  {0xFD, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VADD, OpSize::i16Bit>},
  {0xFE, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VADD, OpSize::i32Bit>},

  // FEX reserved instructions
  {0x37, 1, &OpDispatchBuilder::CallbackReturnOp},
};

constexpr std::tuple<uint8_t, uint8_t, FEXCore::X86Tables::OpDispatchPtr> OpDispatch_SecondaryRepModTables[] = {
  {0x10, 2, &OpDispatchBuilder::MOVSSOp},
  {0x12, 1, &OpDispatchBuilder::VMOVSLDUPOp},
  {0x16, 1, &OpDispatchBuilder::VMOVSHDUPOp},
  {0x2A, 1, &OpDispatchBuilder::InsertCVTGPR_To_FPR<OpSize::i32Bit>},
  {0x2B, 1, &OpDispatchBuilder::MOVVectorNTOp},
  {0x2C, 1, &OpDispatchBuilder::CVTFPR_To_GPR<OpSize::i32Bit, false>},
  {0x2D, 1, &OpDispatchBuilder::CVTFPR_To_GPR<OpSize::i32Bit, true>},
  {0x51, 1, &OpDispatchBuilder::VectorScalarUnaryInsertALUOp<IR::OP_VFSQRTSCALARINSERT, OpSize::i32Bit>},
  {0x52, 1, &OpDispatchBuilder::VectorScalarUnaryInsertALUOp<IR::OP_VFRSQRTSCALARINSERT, OpSize::i32Bit>},
  {0x53, 1, &OpDispatchBuilder::VectorScalarUnaryInsertALUOp<IR::OP_VFRECPSCALARINSERT, OpSize::i32Bit>},
  {0x58, 1, &OpDispatchBuilder::VectorScalarInsertALUOp<IR::OP_VFADDSCALARINSERT, OpSize::i32Bit>},
  {0x59, 1, &OpDispatchBuilder::VectorScalarInsertALUOp<IR::OP_VFMULSCALARINSERT, OpSize::i32Bit>},
  {0x5A, 1, &OpDispatchBuilder::InsertScalar_CVT_Float_To_Float<OpSize::i64Bit, OpSize::i32Bit>},
  {0x5B, 1, &OpDispatchBuilder::Vector_CVT_Float_To_Int<OpSize::i32Bit, false, false>},
  {0x5C, 1, &OpDispatchBuilder::VectorScalarInsertALUOp<IR::OP_VFSUBSCALARINSERT, OpSize::i32Bit>},
  {0x5D, 1, &OpDispatchBuilder::VectorScalarInsertALUOp<IR::OP_VFMINSCALARINSERT, OpSize::i32Bit>},
  {0x5E, 1, &OpDispatchBuilder::VectorScalarInsertALUOp<IR::OP_VFDIVSCALARINSERT, OpSize::i32Bit>},
  {0x5F, 1, &OpDispatchBuilder::VectorScalarInsertALUOp<IR::OP_VFMAXSCALARINSERT, OpSize::i32Bit>},
  {0x6F, 1, &OpDispatchBuilder::MOVVectorUnalignedOp},
  {0x70, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSHUFWOp, false>},
  {0x7E, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::MOVQOp, OpDispatchBuilder::VectorOpType::SSE>},
  {0x7F, 1, &OpDispatchBuilder::MOVVectorUnalignedOp},
  {0xB8, 1, &OpDispatchBuilder::PopcountOp},
  {0xBC, 1, &OpDispatchBuilder::TZCNT},
  {0xBD, 1, &OpDispatchBuilder::LZCNT},
  {0xC2, 1, &OpDispatchBuilder::InsertScalarFCMPOp<OpSize::i32Bit>},
  {0xD6, 1, &OpDispatchBuilder::MOVQ2DQ<true>},
  {0xE6, 1, &OpDispatchBuilder::Vector_CVT_Int_To_Float<OpSize::i32Bit, true>},
};

constexpr std::tuple<uint8_t, uint8_t, FEXCore::X86Tables::OpDispatchPtr> OpDispatch_SecondaryRepNEModTables[] = {
  {0x10, 2, &OpDispatchBuilder::MOVSDOp},
  {0x12, 1, &OpDispatchBuilder::MOVDDUPOp},
  {0x2A, 1, &OpDispatchBuilder::InsertCVTGPR_To_FPR<OpSize::i64Bit>},
  {0x2B, 1, &OpDispatchBuilder::MOVVectorNTOp},
  {0x2C, 1, &OpDispatchBuilder::CVTFPR_To_GPR<OpSize::i64Bit, false>},
  {0x2D, 1, &OpDispatchBuilder::CVTFPR_To_GPR<OpSize::i64Bit, true>},
  {0x51, 1, &OpDispatchBuilder::VectorScalarUnaryInsertALUOp<IR::OP_VFSQRTSCALARINSERT, OpSize::i64Bit>},
  // x52 = Invalid
  {0x58, 1, &OpDispatchBuilder::VectorScalarInsertALUOp<IR::OP_VFADDSCALARINSERT, OpSize::i64Bit>},
  {0x59, 1, &OpDispatchBuilder::VectorScalarInsertALUOp<IR::OP_VFMULSCALARINSERT, OpSize::i64Bit>},
  {0x5A, 1, &OpDispatchBuilder::InsertScalar_CVT_Float_To_Float<OpSize::i32Bit, OpSize::i64Bit>},
  {0x5C, 1, &OpDispatchBuilder::VectorScalarInsertALUOp<IR::OP_VFSUBSCALARINSERT, OpSize::i64Bit>},
  {0x5D, 1, &OpDispatchBuilder::VectorScalarInsertALUOp<IR::OP_VFMINSCALARINSERT, OpSize::i64Bit>},
  {0x5E, 1, &OpDispatchBuilder::VectorScalarInsertALUOp<IR::OP_VFDIVSCALARINSERT, OpSize::i64Bit>},
  {0x5F, 1, &OpDispatchBuilder::VectorScalarInsertALUOp<IR::OP_VFMAXSCALARINSERT, OpSize::i64Bit>},
  {0x70, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSHUFWOp, true>},
  {0x7C, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VFADDP, OpSize::i32Bit>},
  {0x7D, 1, &OpDispatchBuilder::HSUBP<OpSize::i32Bit>},
  {0xD0, 1, &OpDispatchBuilder::ADDSUBPOp<OpSize::i32Bit>},
  {0xD6, 1, &OpDispatchBuilder::MOVQ2DQ<false>},
  {0xC2, 1, &OpDispatchBuilder::InsertScalarFCMPOp<OpSize::i64Bit>},
  {0xE6, 1, &OpDispatchBuilder::Vector_CVT_Float_To_Int<OpSize::i64Bit, true, true>},
  {0xF0, 1, &OpDispatchBuilder::MOVVectorUnalignedOp},
};

constexpr std::tuple<uint8_t, uint8_t, FEXCore::X86Tables::OpDispatchPtr> OpDispatch_SecondaryOpSizeModTables[] = {
  {0x10, 2, &OpDispatchBuilder::MOVVectorUnalignedOp},
  {0x12, 2, &OpDispatchBuilder::MOVLPOp},
  {0x14, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKLOp, OpSize::i64Bit>},
  {0x15, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKHOp, OpSize::i64Bit>},
  {0x16, 2, &OpDispatchBuilder::MOVHPDOp},
  {0x28, 2, &OpDispatchBuilder::MOVVectorAlignedOp},
  {0x2A, 1, &OpDispatchBuilder::MMX_To_XMM_Vector_CVT_Int_To_Float},
  {0x2B, 1, &OpDispatchBuilder::MOVVectorNTOp},
  {0x2C, 1, &OpDispatchBuilder::XMM_To_MMX_Vector_CVT_Float_To_Int<OpSize::i64Bit, true, false>},
  {0x2D, 1, &OpDispatchBuilder::XMM_To_MMX_Vector_CVT_Float_To_Int<OpSize::i64Bit, true, true>},
  {0x2E, 2, &OpDispatchBuilder::UCOMISxOp<OpSize::i64Bit>},

  {0x50, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::MOVMSKOp, OpSize::i64Bit>},
  {0x51, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorUnaryOp, IR::OP_VFSQRT, OpSize::i64Bit>},
  {0x54, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VAND, OpSize::i128Bit>},
  {0x55, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUROp, IR::OP_VANDN, OpSize::i64Bit>},
  {0x56, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VOR, OpSize::i128Bit>},
  {0x57, 1, &OpDispatchBuilder::VectorXOROp},
  {0x58, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VFADD, OpSize::i64Bit>},
  {0x59, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VFMUL, OpSize::i64Bit>},
  {0x5A, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::Vector_CVT_Float_To_Float, 4, 8, false>},
  {0x5B, 1, &OpDispatchBuilder::Vector_CVT_Float_To_Int<OpSize::i32Bit, false, true>},
  {0x5C, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VFSUB, OpSize::i64Bit>},
  {0x5D, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VFMIN, OpSize::i64Bit>},
  {0x5E, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VFDIV, OpSize::i64Bit>},
  {0x5F, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VFMAX, OpSize::i64Bit>},
  {0x60, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKLOp, OpSize::i8Bit>},
  {0x61, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKLOp, OpSize::i16Bit>},
  {0x62, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKLOp, OpSize::i32Bit>},
  {0x63, 1, &OpDispatchBuilder::PACKSSOp<OpSize::i16Bit>},
  {0x64, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VCMPGT, OpSize::i8Bit>},
  {0x65, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VCMPGT, OpSize::i16Bit>},
  {0x66, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VCMPGT, OpSize::i32Bit>},
  {0x67, 1, &OpDispatchBuilder::PACKUSOp<OpSize::i16Bit>},
  {0x68, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKHOp, OpSize::i8Bit>},
  {0x69, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKHOp, OpSize::i16Bit>},
  {0x6A, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKHOp, OpSize::i32Bit>},
  {0x6B, 1, &OpDispatchBuilder::PACKSSOp<OpSize::i32Bit>},
  {0x6C, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKLOp, OpSize::i64Bit>},
  {0x6D, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUNPCKHOp, OpSize::i64Bit>},
  {0x6E, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::MOVBetweenGPR_FPR, OpDispatchBuilder::VectorOpType::SSE>},
  {0x6F, 1, &OpDispatchBuilder::MOVVectorAlignedOp},
  {0x70, 1, &OpDispatchBuilder::PSHUFDOp},

  {0x74, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VCMPEQ, OpSize::i8Bit>},
  {0x75, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VCMPEQ, OpSize::i16Bit>},
  {0x76, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VCMPEQ, OpSize::i32Bit>},
  {0x78, 1, nullptr}, // GROUP 17
  {0x7C, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VFADDP, OpSize::i64Bit>},
  {0x7D, 1, &OpDispatchBuilder::HSUBP<OpSize::i64Bit>},
  {0x7E, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::MOVBetweenGPR_FPR, OpDispatchBuilder::VectorOpType::SSE>},
  {0x7F, 1, &OpDispatchBuilder::MOVVectorAlignedOp},
  {0xC2, 1, &OpDispatchBuilder::VFCMPOp<OpSize::i64Bit>},
  {0xC4, 1, &OpDispatchBuilder::PINSROp<OpSize::i16Bit>},
  {0xC5, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PExtrOp, OpSize::i16Bit>},
  {0xC6, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::SHUFOp, OpSize::i64Bit>},

  {0xD0, 1, &OpDispatchBuilder::ADDSUBPOp<OpSize::i64Bit>},
  {0xD1, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSRLDOp, OpSize::i16Bit>},
  {0xD2, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSRLDOp, OpSize::i32Bit>},
  {0xD3, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSRLDOp, OpSize::i64Bit>},
  {0xD4, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VADD, OpSize::i64Bit>},
  {0xD5, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VMUL, OpSize::i16Bit>},
  {0xD6, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::MOVQOp, OpDispatchBuilder::VectorOpType::SSE>},
  {0xD7, 1, &OpDispatchBuilder::MOVMSKOpOne}, // PMOVMSKB
  {0xD8, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VUQSUB, OpSize::i8Bit>},
  {0xD9, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VUQSUB, OpSize::i16Bit>},
  {0xDA, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VUMIN, OpSize::i8Bit>},
  {0xDB, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VAND, OpSize::i128Bit>},
  {0xDC, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VUQADD, OpSize::i8Bit>},
  {0xDD, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VUQADD, OpSize::i16Bit>},
  {0xDE, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VUMAX, OpSize::i8Bit>},
  {0xDF, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUROp, IR::OP_VANDN, OpSize::i64Bit>},
  {0xE0, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VURAVG, OpSize::i8Bit>},
  {0xE1, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSRAOp, OpSize::i16Bit>},
  {0xE2, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSRAOp, OpSize::i32Bit>},
  {0xE3, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VURAVG, OpSize::i16Bit>},
  {0xE4, 1, &OpDispatchBuilder::PMULHW<false>},
  {0xE5, 1, &OpDispatchBuilder::PMULHW<true>},
  {0xE6, 1, &OpDispatchBuilder::Vector_CVT_Float_To_Int<OpSize::i64Bit, true, false>},
  {0xE7, 1, &OpDispatchBuilder::MOVVectorNTOp},
  {0xE8, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSQSUB, OpSize::i8Bit>},
  {0xE9, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSQSUB, OpSize::i16Bit>},
  {0xEA, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSMIN, OpSize::i16Bit>},
  {0xEB, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VOR, OpSize::i128Bit>},
  {0xEC, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSQADD, OpSize::i8Bit>},
  {0xED, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSQADD, OpSize::i16Bit>},
  {0xEE, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSMAX, OpSize::i16Bit>},
  {0xEF, 1, &OpDispatchBuilder::VectorXOROp},

  {0xF1, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSLL, OpSize::i16Bit>},
  {0xF2, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSLL, OpSize::i32Bit>},
  {0xF3, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PSLL, OpSize::i64Bit>},
  {0xF4, 1, &OpDispatchBuilder::PMULLOp<OpSize::i32Bit, false>},
  {0xF5, 1, &OpDispatchBuilder::PMADDWD},
  {0xF6, 1, &OpDispatchBuilder::PSADBW},
  {0xF7, 1, &OpDispatchBuilder::MASKMOVOp},
  {0xF8, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSUB, OpSize::i8Bit>},
  {0xF9, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSUB, OpSize::i16Bit>},
  {0xFA, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSUB, OpSize::i32Bit>},
  {0xFB, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VSUB, OpSize::i64Bit>},
  {0xFC, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VADD, OpSize::i8Bit>},
  {0xFD, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VADD, OpSize::i16Bit>},
  {0xFE, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::VectorALUOp, IR::OP_VADD, OpSize::i32Bit>},
};

constexpr std::tuple<uint8_t, uint8_t, FEXCore::X86Tables::OpDispatchPtr> OpDispatch_TwoByteOpTable_64[] = {
  {0x05, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::SyscallOp, true>},
  {0xA0, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUSHSegmentOp, FEXCore::X86Tables::DecodeFlags::FLAG_FS_PREFIX>},
  {0xA1, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::POPSegmentOp, FEXCore::X86Tables::DecodeFlags::FLAG_FS_PREFIX>},
  {0xA8, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUSHSegmentOp, FEXCore::X86Tables::DecodeFlags::FLAG_GS_PREFIX>},
  {0xA9, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::POPSegmentOp, FEXCore::X86Tables::DecodeFlags::FLAG_GS_PREFIX>},
};

constexpr std::tuple<uint8_t, uint8_t, FEXCore::X86Tables::OpDispatchPtr> OpDispatch_TwoByteOpTable_32[] = {
  {0x05, 1, &OpDispatchBuilder::NOPOp},
  {0xA0, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUSHSegmentOp, FEXCore::X86Tables::DecodeFlags::FLAG_FS_PREFIX>},
  {0xA1, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::POPSegmentOp, FEXCore::X86Tables::DecodeFlags::FLAG_FS_PREFIX>},
  {0xA8, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::PUSHSegmentOp, FEXCore::X86Tables::DecodeFlags::FLAG_GS_PREFIX>},
  {0xA9, 1, &OpDispatchBuilder::Bind<&OpDispatchBuilder::POPSegmentOp, FEXCore::X86Tables::DecodeFlags::FLAG_GS_PREFIX>},
};
} // namespace FEXCore::IR
