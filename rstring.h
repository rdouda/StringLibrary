#pragma once
#ifndef RSTRING_H
#define RSTRING_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct String String;

struct String {
	size_t allocated;
	size_t length;
	char* data;
};

String* create_string(const char* str);

char* get_data(String* str);
char *add_char(String* str, char c);

size_t length(String* str);
bool has_space(String* str);

void delete(String* str, size_t start, size_t end);
void reallocate(String* str, size_t size);
void delete_string(String* str);

#endif // !RSTRING_H
