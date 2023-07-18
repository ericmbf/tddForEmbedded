#include <stdint.h>

typedef struct CircularBuffer
{
    uint8_t *buffer;
    uint8_t tail;
    uint8_t head;
    uint8_t size;
}CircularBuffer_t;

CircularBuffer_t CircularBuffer_create(uint8_t *buffer, uint8_t uc_size);
uint8_t CircularBuffer_get(CircularBuffer_t *cb, uint8_t idx);
void CircularBuffer_add(CircularBuffer_t *buffer, uint8_t value);
uint8_t CircularBuffer_size(CircularBuffer_t *buffer);
uint8_t CircularBuffer_remove(CircularBuffer_t *buffer);