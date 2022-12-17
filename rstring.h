#pragma once
#ifndef RSTRING_H
#define RSTRING_H

#include <stdlib.h>
#include <string.h>

typedef struct String String;

struct String {
	size_t allocated;
	size_t length;
	char* data;
};

String* create_string(const char* str);

char* get_data(String* str);
size_t length(String* str);
void add_char(String* str, char c);

void delete_string(String* str);

#endif // !RSTRING_H
