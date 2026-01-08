#include <gtest/gtest.h>

#include "structural_tag.h"

using namespace xgrammar;

TEST(StructuralTagFingerprintTest, EquivalentRegexFingerprintMatches) {
  RegexFormat r1("a");
  RegexFormat r2("(a)");
  auto fp1 = _DebugComputeFormatFingerprint(r1);
  auto fp2 = _DebugComputeFormatFingerprint(r2);
  EXPECT_EQ(fp1, fp2);
}

TEST(StructuralTagFingerprintTest, DifferentExcludesDiffer) {
  RegexFormat r1("a", {"bb"});
  RegexFormat r2("a", {"cc"});
  auto fp1 = _DebugComputeFormatFingerprint(r1);
  auto fp2 = _DebugComputeFormatFingerprint(r2);
  EXPECT_NE(fp1, fp2);
}

