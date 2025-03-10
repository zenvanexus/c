/*
 * v1_custom_resource_subresource_scale.h
 *
 * CustomResourceSubresourceScale defines how to serve the scale subresource for CustomResources.
 */

#ifndef _v1_custom_resource_subresource_scale_H_
#define _v1_custom_resource_subresource_scale_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_custom_resource_subresource_scale_t v1_custom_resource_subresource_scale_t;




typedef struct v1_custom_resource_subresource_scale_t {
    char *label_selector_path; // string
    char *spec_replicas_path; // string
    char *status_replicas_path; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_custom_resource_subresource_scale_t;

__attribute__((deprecated)) v1_custom_resource_subresource_scale_t *v1_custom_resource_subresource_scale_create(
    char *label_selector_path,
    char *spec_replicas_path,
    char *status_replicas_path
);

void v1_custom_resource_subresource_scale_free(v1_custom_resource_subresource_scale_t *v1_custom_resource_subresource_scale);

v1_custom_resource_subresource_scale_t *v1_custom_resource_subresource_scale_parseFromJSON(cJSON *v1_custom_resource_subresource_scaleJSON);

cJSON *v1_custom_resource_subresource_scale_convertToJSON(v1_custom_resource_subresource_scale_t *v1_custom_resource_subresource_scale);

#endif /* _v1_custom_resource_subresource_scale_H_ */

