
#include <glib-object.h>

#include "dummy.h"

int
main (int argc, char *argv[])
{
	GlsDummy *dummy = gls_dummy_new();
	g_object_unref(G_OBJECT(dummy));

	g_print("Hello World !\n");
	return 0;
}
