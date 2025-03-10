/*
 * v1_local_subject_access_review.h
 *
 * LocalSubjectAccessReview checks whether or not a user or group can perform an action in a given namespace. Having a namespace scoped resource makes it much easier to grant namespace scoped policy that includes permissions checking.
 */

#ifndef _v1_local_subject_access_review_H_
#define _v1_local_subject_access_review_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_local_subject_access_review_t v1_local_subject_access_review_t;

#include "v1_object_meta.h"
#include "v1_subject_access_review_spec.h"
#include "v1_subject_access_review_status.h"



typedef struct v1_local_subject_access_review_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_subject_access_review_spec_t *spec; //model
    struct v1_subject_access_review_status_t *status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_local_subject_access_review_t;

__attribute__((deprecated)) v1_local_subject_access_review_t *v1_local_subject_access_review_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_subject_access_review_spec_t *spec,
    v1_subject_access_review_status_t *status
);

void v1_local_subject_access_review_free(v1_local_subject_access_review_t *v1_local_subject_access_review);

v1_local_subject_access_review_t *v1_local_subject_access_review_parseFromJSON(cJSON *v1_local_subject_access_reviewJSON);

cJSON *v1_local_subject_access_review_convertToJSON(v1_local_subject_access_review_t *v1_local_subject_access_review);

#endif /* _v1_local_subject_access_review_H_ */

