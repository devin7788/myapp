//
// Created by DEIN2023 on 25-6-24.
//

#ifndef TS_QUEUE_H
#define TS_QUEUE_H

#include <pthread.h>

typedef struct ts_queue_node {
    int data;
    struct ts_queue_node *next;
} ts_queue_node_t;

typedef struct {
    ts_queue_node_t *head;
    ts_queue_node_t *tail;
    pthread_mutex_t mutex;
} ts_queue_t;

void ts_queue_init(ts_queue_t *q);
void ts_queue_destroy(ts_queue_t *q);
void ts_queue_push(ts_queue_t *q, int data);
int ts_queue_pop(ts_queue_t *q, int *data);

#endif // TS_QUEUE_H
