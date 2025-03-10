/*
 * apiextensions_v1_service_reference.h
 *
 * ServiceReference holds a reference to Service.legacy.k8s.io
 */

#ifndef _apiextensions_v1_service_reference_H_
#define _apiextensions_v1_service_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct apiextensions_v1_service_reference_t apiextensions_v1_service_reference_t;




typedef struct apiextensions_v1_service_reference_t {
    char *name; // string
    char *_namespace; // string
    char *path; // string
    int port; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} apiextensions_v1_service_reference_t;

__attribute__((deprecated)) apiextensions_v1_service_reference_t *apiextensions_v1_service_reference_create(
    char *name,
    char *_namespace,
    char *path,
    int port
);

void apiextensions_v1_service_reference_free(apiextensions_v1_service_reference_t *apiextensions_v1_service_reference);

apiextensions_v1_service_reference_t *apiextensions_v1_service_reference_parseFromJSON(cJSON *apiextensions_v1_service_referenceJSON);

cJSON *apiextensions_v1_service_reference_convertToJSON(apiextensions_v1_service_reference_t *apiextensions_v1_service_reference);

#endif /* _apiextensions_v1_service_reference_H_ */

