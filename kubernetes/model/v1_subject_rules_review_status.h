/*
 * v1_subject_rules_review_status.h
 *
 * SubjectRulesReviewStatus contains the result of a rules check. This check can be incomplete depending on the set of authorizers the server is configured with and any errors experienced during evaluation. Because authorization rules are additive, if a rule appears in a list it&#39;s safe to assume the subject has that permission, even if that list is incomplete.
 */

#ifndef _v1_subject_rules_review_status_H_
#define _v1_subject_rules_review_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_subject_rules_review_status_t v1_subject_rules_review_status_t;

#include "v1_non_resource_rule.h"
#include "v1_resource_rule.h"



typedef struct v1_subject_rules_review_status_t {
    char *evaluation_error; // string
    int incomplete; //boolean
    list_t *non_resource_rules; //nonprimitive container
    list_t *resource_rules; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_subject_rules_review_status_t;

__attribute__((deprecated)) v1_subject_rules_review_status_t *v1_subject_rules_review_status_create(
    char *evaluation_error,
    int incomplete,
    list_t *non_resource_rules,
    list_t *resource_rules
);

void v1_subject_rules_review_status_free(v1_subject_rules_review_status_t *v1_subject_rules_review_status);

v1_subject_rules_review_status_t *v1_subject_rules_review_status_parseFromJSON(cJSON *v1_subject_rules_review_statusJSON);

cJSON *v1_subject_rules_review_status_convertToJSON(v1_subject_rules_review_status_t *v1_subject_rules_review_status);

#endif /* _v1_subject_rules_review_status_H_ */

