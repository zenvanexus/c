#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/object.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_priority_class.h"
#include "../model/v1_priority_class_list.h"
#include "../model/v1_status.h"


// create a PriorityClass
//
v1_priority_class_t*
SchedulingV1API_createPriorityClass(apiClient_t *apiClient, v1_priority_class_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of PriorityClass
//
v1_status_t*
SchedulingV1API_deleteCollectionPriorityClass(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete a PriorityClass
//
v1_status_t*
SchedulingV1API_deletePriorityClass(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
SchedulingV1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind PriorityClass
//
v1_priority_class_list_t*
SchedulingV1API_listPriorityClass(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified PriorityClass
//
v1_priority_class_t*
SchedulingV1API_patchPriorityClass(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified PriorityClass
//
v1_priority_class_t*
SchedulingV1API_readPriorityClass(apiClient_t *apiClient, char *name, char *pretty);


// replace the specified PriorityClass
//
v1_priority_class_t*
SchedulingV1API_replacePriorityClass(apiClient_t *apiClient, char *name, v1_priority_class_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


