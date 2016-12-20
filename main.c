
#include <glib-object.h>

#include "dummy.h"

/**
 * Use GHashTable like Set<Dummy*>
 */
void
use_ghashtable_as_set()
{
	GlsDummy *dummy_1 = gls_dummy_new();
	GlsDummy *dummy_2 = gls_dummy_new();
	GlsDummy *dummy_3 = gls_dummy_new();
	GlsDummy *dummy_4 = gls_dummy_new();
	g_print("\n");

	GHashTable *map = g_hash_table_new_full(
		(GHashFunc)gls_dummy_hash,
		(GEqualFunc)gls_dummy_equal,
		NULL,/*do not unref key while value is unref on hash_tabe_unref*/
		(GDestroyNotify)g_object_unref);

	{
		g_print("g_hash_table_add(#1)\n");
		g_hash_table_add(map, dummy_1);

		g_print("g_hash_table_add(#2)\n");
		g_hash_table_add(map, dummy_2);

		g_print("g_hash_table_add(#3)\n");
		g_hash_table_add(map, dummy_3);

		g_print("g_hash_table_add(#4)\n");
		g_hash_table_add(map, dummy_4);
	}
	
	g_print("\n");
	//g_hash_table_unref(map);
	g_hash_table_ref(map);
	g_hash_table_destroy(map);
}


int
main (int argc, char *argv[])
{
	use_ghashtable_as_set();

	g_print("Hello World !\n");
	return 0;
}
