#include "invalid_util.h"

#include <catch2/catch_test_macros.hpp>

#include <atomic>
#include <signal.h>
#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>
#include <cstdlib>

extern "C" void IntInstruction();

#pragma GCC diagnostic ignored "-Wattributes" // Suppress warning in case control-flow checks aren't enabled
__attribute__((naked, nocf_check)) static void InvalidINT() {
  __asm volatile(R"(
    IntInstruction:
    hlt;
    ret;
    )");
}

unsigned long EXPECTED_RIP = reinterpret_cast<unsigned long>(&IntInstruction);
constexpr int EXPECTED_TRAPNO = 0xD;
constexpr int EXPECTED_ERR = 0;
constexpr int EXPECTED_SI_CODE = 128;
constexpr int EXPECTED_SIGNAL = SIGSEGV;

TEST_CASE("Signals: Invalid HLT") {
  capturing_handler_skip = 1;
  struct sigaction act {};
  act.sa_sigaction = CapturingHandler;
  act.sa_flags = SA_SIGINFO;
  sigaction(SIGSEGV, &act, nullptr);
  sigaction(SIGTRAP, &act, nullptr);
  sigaction(SIGILL, &act, nullptr);

  InvalidINT();

#ifndef REG_RIP
#define REG_RIP REG_EIP
#endif

  REQUIRE(from_handler.has_value());
  CHECK(from_handler->mctx.gregs[REG_RIP] == EXPECTED_RIP);
  CHECK(from_handler->mctx.gregs[REG_TRAPNO] == EXPECTED_TRAPNO);
  CHECK(from_handler->mctx.gregs[REG_ERR] == EXPECTED_ERR);
  CHECK(from_handler->si_code == EXPECTED_SI_CODE);
  CHECK(from_handler->signal == EXPECTED_SIGNAL);
}
