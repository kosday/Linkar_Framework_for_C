#include <malloc.h>
#include <stdio.h>

#include "LinkarStringsHelper.h"
#include "LinkarStrings.h"
#include "CredentialOptions.h"

#include "Types.h"

#include "FunctionsDirectJSON.h"

void main(void)
{	
	char* credentialOptions = LkCreateCredentialOptions("192.168.100.101", "QMEP1", 11301, "ADMIN", "admin", "", "Test C Library");	
	
	// Operation LkRead JSON example
	printf("\nOperation LkRead JSON example. LK.ORDERS Id 1\n");
	char* error;
	char* filename = "LK.ORDERS";
	char* recordIds = "1";
	char* dictionaries = "";
	char* readOptions = NULL;
	char* customVars = "";
	uint32_t receiveTimeout = 10;
	char* result = LkRead(&error, credentialOptions, filename, recordIds, dictionaries, readOptions, JSON_FORMAT_JSON, customVars, receiveTimeout);
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	printf("result (JSON): %s\n", result);
	LkFreeMemory(result);

	printf("\nOperation LkRead JSON_DICT example\n");
	result = LkRead(&error, credentialOptions, filename, recordIds, dictionaries, readOptions, JSON_FORMAT_JSON_DICT, customVars, receiveTimeout);
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	printf("result (JSON_DICT): %s\n", result);
	LkFreeMemory(result);

	printf("\nOperation LkRead JSON_SCH example\n");
	result = LkRead(&error, credentialOptions, filename, recordIds, dictionaries, readOptions, JSON_FORMAT_JSON_SCH, customVars, receiveTimeout);
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	printf("result (JSON_SCH): %s\n", result);
	LkFreeMemory(result);

	LkFreeMemory(credentialOptions);
}