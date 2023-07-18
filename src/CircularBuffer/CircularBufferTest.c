#include "CircularBuffer.h"
#include "unity.h"
#include <stdint.h>

static uint8_t g_buffer[10] = {0xFF};
static CircularBuffer_t gs_cb;

void setUp() {
  gs_cb = CircularBuffer_create(&g_buffer[0], sizeof(g_buffer));
}
void tearDown() {}

void test_emptyOnCreate() {
  uint8_t buffer[10] = {0xFF};
  uint8_t expected[10] = {0x00};

  CircularBuffer_t cb = CircularBuffer_create(buffer, sizeof(buffer));

  TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, cb.buffer, sizeof(buffer));
}

void test_insertFirstElement() {

  CircularBuffer_add(&gs_cb, 0x01);
  TEST_ASSERT_EQUAL_UINT8(0x01, CircularBuffer_get(&gs_cb, 0));
  TEST_ASSERT_EQUAL_UINT8(0x01, CircularBuffer_size(g_buffer));
}

void test_removeFirstElement() {
  uint8_t buffer[10] = {0xFF};
  uint8_t expected[10] = {0x00};
  uint8_t elementRemoved = 0xFF;

  CircularBuffer_add(&gs_cb, 0x01);
  elementRemoved = CircularBuffer_remove(&gs_cb);
  TEST_ASSERT_EQUAL_UINT8(0x01, elementRemoved);
  TEST_ASSERT_EQUAL_UINT8(0x00, CircularBuffer_size(&gs_cb));
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_emptyOnCreate);
  RUN_TEST(test_insertFirstElement);
  RUN_TEST(test_removeFirstElement);
  return UNITY_END();
}