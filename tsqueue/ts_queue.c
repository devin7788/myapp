//
// Created by DEIN2023 on 25-6-24.
//
#include "ts_queue.h"
#include <stdlib.h>

void ts_queue_init(ts_queue_t *q) {
    q->head = q->tail = NULL;
    pthread_mutex_init(&q->mutex, NULL);
}

void ts_queue_destroy(ts_queue_t *q) {
    pthread_mutex_lock(&q->mutex);
    ts_queue_node_t *cur = q->head;
    while (cur) {
        ts_queue_node_t *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    q->head = q->tail = NULL;
    pthread_mutex_unlock(&q->mutex);
    pthread_mutex_destroy(&q->mutex);
}

void ts_queue_push(ts_queue_t *q, int data) {
    ts_queue_node_t *node = malloc(sizeof(ts_queue_node_t));
    if (!node) return;
    node->data = data;
    node->next = NULL;

    pthread_mutex_lock(&q->mutex);
    if (q->tail) {
        q->tail->next = node;
        q->tail = node;
    } else {
        q->head = q->tail = node;
    }
    pthread_mutex_unlock(&q->mutex);
}

int ts_queue_pop(ts_queue_t *q, int *data) {
    pthread_mutex_lock(&q->mutex);
    if (!q->head) {
        pthread_mutex_unlock(&q->mutex);
        return 0; // 队列空
    }
    ts_queue_node_t *node = q->head;
    *data = node->data;
    q->head = node->next;
    if (!q->head) q->tail = NULL;
    pthread_mutex_unlock(&q->mutex);

    free(node);
    return 1;
}
