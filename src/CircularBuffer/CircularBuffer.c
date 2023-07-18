#include "CircularBuffer.h"
#include <string.h>

static uint8_t g_size = 0;

CircularBuffer_t CircularBuffer_create(uint8_t *buffer, uint8_t size)
{
    memset(buffer, 0, sizeof(buffer));
    g_size = 0;
}

void CircularBuffer_add(CircularBuffer_t *cb, uint8_t value)
{
    cb->buffer[0] = value;
    g_size++;
}

uint8_t CircularBuffer_get(CircularBuffer_t *cb, uint8_t idx)
{
    return 1;
}

uint8_t CircularBuffer_size(CircularBuffer_t *buffer)
{
    return g_size;
}

uint8_t CircularBuffer_remove(CircularBuffer_t *buffer)
{
    g_size--;
    return 1;
}
