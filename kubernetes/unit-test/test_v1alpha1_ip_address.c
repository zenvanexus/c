#ifndef v1alpha1_ip_address_TEST
#define v1alpha1_ip_address_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_ip_address_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_ip_address.h"
v1alpha1_ip_address_t* instantiate_v1alpha1_ip_address(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1alpha1_ip_address_spec.c"


v1alpha1_ip_address_t* instantiate_v1alpha1_ip_address(int include_optional) {
  v1alpha1_ip_address_t* v1alpha1_ip_address = NULL;
  if (include_optional) {
    v1alpha1_ip_address = v1alpha1_ip_address_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1alpha1_ip_address_spec(0)
    );
  } else {
    v1alpha1_ip_address = v1alpha1_ip_address_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return v1alpha1_ip_address;
}


#ifdef v1alpha1_ip_address_MAIN

void test_v1alpha1_ip_address(int include_optional) {
    v1alpha1_ip_address_t* v1alpha1_ip_address_1 = instantiate_v1alpha1_ip_address(include_optional);

	cJSON* jsonv1alpha1_ip_address_1 = v1alpha1_ip_address_convertToJSON(v1alpha1_ip_address_1);
	printf("v1alpha1_ip_address :\n%s\n", cJSON_Print(jsonv1alpha1_ip_address_1));
	v1alpha1_ip_address_t* v1alpha1_ip_address_2 = v1alpha1_ip_address_parseFromJSON(jsonv1alpha1_ip_address_1);
	cJSON* jsonv1alpha1_ip_address_2 = v1alpha1_ip_address_convertToJSON(v1alpha1_ip_address_2);
	printf("repeating v1alpha1_ip_address:\n%s\n", cJSON_Print(jsonv1alpha1_ip_address_2));
}

int main() {
  test_v1alpha1_ip_address(1);
  test_v1alpha1_ip_address(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_ip_address_MAIN
#endif // v1alpha1_ip_address_TEST
