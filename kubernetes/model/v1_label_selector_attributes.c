#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_label_selector_attributes.h"



static v1_label_selector_attributes_t *v1_label_selector_attributes_create_internal(
    char *raw_selector,
    list_t *requirements
    ) {
    v1_label_selector_attributes_t *v1_label_selector_attributes_local_var = malloc(sizeof(v1_label_selector_attributes_t));
    if (!v1_label_selector_attributes_local_var) {
        return NULL;
    }
    v1_label_selector_attributes_local_var->raw_selector = raw_selector;
    v1_label_selector_attributes_local_var->requirements = requirements;

    v1_label_selector_attributes_local_var->_library_owned = 1;
    return v1_label_selector_attributes_local_var;
}

__attribute__((deprecated)) v1_label_selector_attributes_t *v1_label_selector_attributes_create(
    char *raw_selector,
    list_t *requirements
    ) {
    return v1_label_selector_attributes_create_internal (
        raw_selector,
        requirements
        );
}

void v1_label_selector_attributes_free(v1_label_selector_attributes_t *v1_label_selector_attributes) {
    if(NULL == v1_label_selector_attributes){
        return ;
    }
    if(v1_label_selector_attributes->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_label_selector_attributes_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_label_selector_attributes->raw_selector) {
        free(v1_label_selector_attributes->raw_selector);
        v1_label_selector_attributes->raw_selector = NULL;
    }
    if (v1_label_selector_attributes->requirements) {
        list_ForEach(listEntry, v1_label_selector_attributes->requirements) {
            v1_label_selector_requirement_free(listEntry->data);
        }
        list_freeList(v1_label_selector_attributes->requirements);
        v1_label_selector_attributes->requirements = NULL;
    }
    free(v1_label_selector_attributes);
}

cJSON *v1_label_selector_attributes_convertToJSON(v1_label_selector_attributes_t *v1_label_selector_attributes) {
    cJSON *item = cJSON_CreateObject();

    // v1_label_selector_attributes->raw_selector
    if(v1_label_selector_attributes->raw_selector) {
    if(cJSON_AddStringToObject(item, "rawSelector", v1_label_selector_attributes->raw_selector) == NULL) {
    goto fail; //String
    }
    }


    // v1_label_selector_attributes->requirements
    if(v1_label_selector_attributes->requirements) {
    cJSON *requirements = cJSON_AddArrayToObject(item, "requirements");
    if(requirements == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *requirementsListEntry;
    if (v1_label_selector_attributes->requirements) {
    list_ForEach(requirementsListEntry, v1_label_selector_attributes->requirements) {
    cJSON *itemLocal = v1_label_selector_requirement_convertToJSON(requirementsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(requirements, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_label_selector_attributes_t *v1_label_selector_attributes_parseFromJSON(cJSON *v1_label_selector_attributesJSON){

    v1_label_selector_attributes_t *v1_label_selector_attributes_local_var = NULL;

    // define the local list for v1_label_selector_attributes->requirements
    list_t *requirementsList = NULL;

    // v1_label_selector_attributes->raw_selector
    cJSON *raw_selector = cJSON_GetObjectItemCaseSensitive(v1_label_selector_attributesJSON, "rawSelector");
    if (cJSON_IsNull(raw_selector)) {
        raw_selector = NULL;
    }
    if (raw_selector) { 
    if(!cJSON_IsString(raw_selector) && !cJSON_IsNull(raw_selector))
    {
    goto end; //String
    }
    }

    // v1_label_selector_attributes->requirements
    cJSON *requirements = cJSON_GetObjectItemCaseSensitive(v1_label_selector_attributesJSON, "requirements");
    if (cJSON_IsNull(requirements)) {
        requirements = NULL;
    }
    if (requirements) { 
    cJSON *requirements_local_nonprimitive = NULL;
    if(!cJSON_IsArray(requirements)){
        goto end; //nonprimitive container
    }

    requirementsList = list_createList();

    cJSON_ArrayForEach(requirements_local_nonprimitive,requirements )
    {
        if(!cJSON_IsObject(requirements_local_nonprimitive)){
            goto end;
        }
        v1_label_selector_requirement_t *requirementsItem = v1_label_selector_requirement_parseFromJSON(requirements_local_nonprimitive);

        list_addElement(requirementsList, requirementsItem);
    }
    }


    v1_label_selector_attributes_local_var = v1_label_selector_attributes_create_internal (
        raw_selector && !cJSON_IsNull(raw_selector) ? strdup(raw_selector->valuestring) : NULL,
        requirements ? requirementsList : NULL
        );

    return v1_label_selector_attributes_local_var;
end:
    if (requirementsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, requirementsList) {
            v1_label_selector_requirement_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(requirementsList);
        requirementsList = NULL;
    }
    return NULL;

}
