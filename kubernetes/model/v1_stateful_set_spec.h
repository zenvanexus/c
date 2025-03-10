/*
 * v1_stateful_set_spec.h
 *
 * A StatefulSetSpec is the specification of a StatefulSet.
 */

#ifndef _v1_stateful_set_spec_H_
#define _v1_stateful_set_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_stateful_set_spec_t v1_stateful_set_spec_t;

#include "v1_label_selector.h"
#include "v1_persistent_volume_claim.h"
#include "v1_pod_template_spec.h"
#include "v1_stateful_set_ordinals.h"
#include "v1_stateful_set_persistent_volume_claim_retention_policy.h"
#include "v1_stateful_set_update_strategy.h"



typedef struct v1_stateful_set_spec_t {
    int min_ready_seconds; //numeric
    struct v1_stateful_set_ordinals_t *ordinals; //model
    struct v1_stateful_set_persistent_volume_claim_retention_policy_t *persistent_volume_claim_retention_policy; //model
    char *pod_management_policy; // string
    int replicas; //numeric
    int revision_history_limit; //numeric
    struct v1_label_selector_t *selector; //model
    char *service_name; // string
    struct v1_pod_template_spec_t *_template; //model
    struct v1_stateful_set_update_strategy_t *update_strategy; //model
    list_t *volume_claim_templates; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_stateful_set_spec_t;

__attribute__((deprecated)) v1_stateful_set_spec_t *v1_stateful_set_spec_create(
    int min_ready_seconds,
    v1_stateful_set_ordinals_t *ordinals,
    v1_stateful_set_persistent_volume_claim_retention_policy_t *persistent_volume_claim_retention_policy,
    char *pod_management_policy,
    int replicas,
    int revision_history_limit,
    v1_label_selector_t *selector,
    char *service_name,
    v1_pod_template_spec_t *_template,
    v1_stateful_set_update_strategy_t *update_strategy,
    list_t *volume_claim_templates
);

void v1_stateful_set_spec_free(v1_stateful_set_spec_t *v1_stateful_set_spec);

v1_stateful_set_spec_t *v1_stateful_set_spec_parseFromJSON(cJSON *v1_stateful_set_specJSON);

cJSON *v1_stateful_set_spec_convertToJSON(v1_stateful_set_spec_t *v1_stateful_set_spec);

#endif /* _v1_stateful_set_spec_H_ */

