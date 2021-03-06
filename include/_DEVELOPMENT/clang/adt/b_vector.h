
// automatically generated by m4 from headers in proto subdir


#ifndef _ADT_B_VECTOR_H
#define _ADT_B_VECTOR_H

#include <stddef.h>

// DATA STRUCTURES

typedef struct b_vector_s
{

   void       *data;
   size_t      size;
   size_t      capacity;
   size_t      max_size;

} b_vector_t;

extern size_t b_vector_append(b_vector_t *v,int c);


extern void *b_vector_append_block(b_vector_t *v,size_t n);


extern size_t b_vector_append_n(b_vector_t *v,size_t n,int c);


extern int b_vector_at(b_vector_t *v,size_t idx);


extern int b_vector_back(b_vector_t *v);


extern size_t b_vector_capacity(b_vector_t *v);


extern void b_vector_clear(b_vector_t *v);


extern void *b_vector_data(b_vector_t *v);


extern void b_vector_destroy(b_vector_t *v);


extern int b_vector_empty(b_vector_t *v);


extern size_t b_vector_erase(b_vector_t *v,size_t idx);


extern size_t b_vector_erase_block(b_vector_t *v,size_t idx,size_t n);


extern size_t b_vector_erase_range(b_vector_t *v,size_t idx_first,size_t idx_last);


extern int b_vector_front(b_vector_t *v);


extern b_vector_t *b_vector_init(void *p,size_t capacity,size_t max_size);


extern size_t b_vector_insert(b_vector_t *v,size_t idx,int c);


extern void *b_vector_insert_block(b_vector_t *v,size_t idx,size_t n);


extern size_t b_vector_insert_n(b_vector_t *v,size_t idx,size_t n,int c);


extern size_t b_vector_max_size(b_vector_t *v);


extern int b_vector_pop_back(b_vector_t *v);


extern size_t b_vector_push_back(b_vector_t *v,int c);


extern size_t b_vector_read_block(void *dst,size_t n,b_vector_t *v,size_t idx);


extern int b_vector_reserve(b_vector_t *v,size_t n);


extern int b_vector_resize(b_vector_t *v,size_t n);


extern int b_vector_shrink_to_fit(b_vector_t *);


extern size_t b_vector_size(b_vector_t *v);


extern size_t b_vector_write_block(void *src,size_t n,b_vector_t *v,size_t idx);



#endif
