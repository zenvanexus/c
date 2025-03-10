/*
 * v1_ingress_load_balancer_status.h
 *
 * IngressLoadBalancerStatus represents the status of a load-balancer.
 */

#ifndef _v1_ingress_load_balancer_status_H_
#define _v1_ingress_load_balancer_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ingress_load_balancer_status_t v1_ingress_load_balancer_status_t;

#include "v1_ingress_load_balancer_ingress.h"



typedef struct v1_ingress_load_balancer_status_t {
    list_t *ingress; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_ingress_load_balancer_status_t;

__attribute__((deprecated)) v1_ingress_load_balancer_status_t *v1_ingress_load_balancer_status_create(
    list_t *ingress
);

void v1_ingress_load_balancer_status_free(v1_ingress_load_balancer_status_t *v1_ingress_load_balancer_status);

v1_ingress_load_balancer_status_t *v1_ingress_load_balancer_status_parseFromJSON(cJSON *v1_ingress_load_balancer_statusJSON);

cJSON *v1_ingress_load_balancer_status_convertToJSON(v1_ingress_load_balancer_status_t *v1_ingress_load_balancer_status);

#endif /* _v1_ingress_load_balancer_status_H_ */

