// SPDX-License-Identifier: MIT
#pragma once
#include <FEXCore/IR/IR.h>
#include <FEXCore/fextl/vector.h>

#include "LinuxSyscalls/Syscalls.h"

namespace FEXCore::Context {
struct VDSOSigReturn;
}

namespace FEX::VDSO {
using MapperFn = std::function<void*(void* addr, size_t length, int prot, int flags, int fd, off_t offset)>;
void* LoadVDSOThunks(bool Is64Bit, FEX::HLE::SyscallHandler* const Handler);

uint64_t GetVSyscallEntry(const void* VDSOBase);

const fextl::vector<FEXCore::IR::ThunkDefinition>& GetVDSOThunkDefinitions();
const FEXCore::Context::VDSOSigReturn& GetVDSOSymbols();
} // namespace FEX::VDSO
