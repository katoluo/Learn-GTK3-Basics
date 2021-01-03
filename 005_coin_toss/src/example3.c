/* ====================================================
#   Copyright (C) 2021  All rights reserved
#
#   Author        : kato
#   Email         : 1123629751@qq.com
#   File Name     : example3.c
#   Last Modified : 2021-01-03 22:01
#   Describe      : 
#
# ====================================================*/


#include <glib.h>

int main(void)
{
	gboolean result;
	
	result = g_random_boolean();
	if (result == TRUE) {
		g_print("Heads\n");
	}
	else {
		g_print("Tails\n");
	}
	return 0;
}
