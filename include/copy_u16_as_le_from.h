#ifndef COPY_U16_AS_LE_FROM_H
#define COPY_U16_AS_LE_FROM_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

uint16_t copy_u16_as_le_from(const void *address, size_t byte_count, bool *ok);
#endif /* COPY_U16_AS_LE_FROM_H */
