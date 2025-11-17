//
// Created by Rene Windegger on 17/11/2025.
//

#include <bigint23/bigint.hpp>
#include <gtest/gtest.h>
#include <sstream>

namespace {
    TEST(bigint23, constexpr_from_integral_test) {
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> a(123456789);
        std::ostringstream oss;
        oss << std::dec << a;
        ASSERT_EQ(oss.str(), "123456789");
    }

    TEST(bigint23, constexpr_from_string_test) {
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> a("123456789");
        std::ostringstream oss;
        oss << std::dec << a;
        ASSERT_EQ(oss.str(), "123456789");
    }

    TEST(bigint23, constexpr_addition_test) {
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> a(21);
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> b(21);
        constexpr auto c = a + b;
        ASSERT_EQ(c, 42);
    }

    TEST(bigint23, constexpr_multiplication_test) {
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> a(21);
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> b(2);
        constexpr auto c = a * b;
        ASSERT_EQ(c, 42);
    }

    TEST(bigint23, constexpr_division_test) {
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> a(84);
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> b(2);
        constexpr auto c = a / b;
        ASSERT_EQ(c, 42);
    }

    TEST(bigint23, constexpr_modulo_test) {
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> a(85);
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> b(43);
        constexpr auto c = a % b;
        ASSERT_EQ(c, 42);
    }

    TEST(bigint23, constexpr_subtraction_test) {
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> a(84);
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> b(42);
        constexpr auto c = a - b;
        ASSERT_EQ(c, 42);
    }

    TEST(bigint23, constexpr_xor_test) {
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> a(0b1100);
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> b(0b1010);
        constexpr auto c = a ^ b;
        ASSERT_EQ(c, 0b0110);
    }

    TEST(bigint23, constexpr_and_test) {
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> a(0b1100);
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> b(0b1010);
        constexpr auto c = a & b;
        ASSERT_EQ(c, 0b1000);
    }

    TEST(bigint23, constexpr_or_test) {
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> a(0b1100);
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Signed> b(0b1010);
        constexpr auto c = a | b;
        ASSERT_EQ(c, 0b1110);
    }

    TEST(bigint23, constexpr_not_test) {
        constexpr bigint::bigint<bigint::BitWidth{8}, bigint::Signedness::Unsigned> a(static_cast<std::uint8_t>(0b10101010));
        constexpr auto c = ~a;
        ASSERT_EQ(c, static_cast<std::uint8_t>(0b01010101));
    }

    TEST(bigint23, constexpr_shift_left_test) {
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Unsigned> a(0b0001);
        constexpr auto c = a << 3;
        ASSERT_EQ(c, 0b1000);
    }

    TEST(bigint23, constexpr_shift_right_test) {
        constexpr bigint::bigint<bigint::BitWidth{128}, bigint::Signedness::Unsigned> a(0b1000);
        constexpr auto c = a >> 3;
        ASSERT_EQ(c, 0b0001);
    }
}
