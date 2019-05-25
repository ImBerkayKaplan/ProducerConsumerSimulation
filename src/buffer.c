#include "buffer.h"

/* The buffer */
buffer_item buffer[BUFFER_SIZE];

int insert_item(buffer_item item){

    /*Insert an item into buffer*/
    buffer[(arrayIndexInsert++)%BUFFER_SIZE] = item;
    return 0;
}

int remove_item(buffer_item *item){

    /*Remove an object from buffer and place it in item*/
    *item = buffer[(arrayIndexRemove++)%BUFFER_SIZE];
    return 0;

}
